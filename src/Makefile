PROJECTDIR = $(CURDIR)
BUILDDIR = $(PROJECTDIR)/build
EXE = Maze.exe
TEST_EXE = MazeTests.exe
DISTDIR = ../distributive
GCOVAPPLE =

ifeq ($(shell uname), Darwin)
	EXE = Maze
	TEST_EXE = MazeTests
	GCOVAPPLE = --ignore-errors inconsistent,mismatch
endif

ifeq ($(shell uname), Linux)
	EXE = Maze
	TEST_EXE = MazeTests
endif


all: install tests gcov_report clean dist check dvi


install: $(BUILDDIR)-release
	read -p "Enter path to install: " path; \
	if [ -z "$$path" ]; then \
        path="./"; \
    fi; \
	if [ ! -d $$path ]; then mkdir -p $$path; fi; \
	if ! [ "$$path" != "$${path#/}" ]; then \
		path="$(PROJECTDIR)/$$path"; \
	fi; \
	cd $(BUILDDIR)-release && \
	cmake .. -DINSTALL=ON -DCMAKE_INSTALL_PREFIX=$$path -G "Unix Makefiles" && \
	cmake --build . --config=Release
	

uninstall: clean
	rm -rf ./bin ./Maze.exe ./$(TEST_EXE) ./Maze.app


tests: $(BUILDDIR)-testing
	cd $(BUILDDIR)-testing && \
	cmake .. -DTESTING=ON -G "Unix Makefiles" && \
	cmake --build . --config=RelWithDebInfo


gcov_report: $(BUILDDIR)-coverage
	cd $(BUILDDIR)-coverage && \
	cmake .. -DTESTING=ON -DCOVERAGE=ON -G "Unix Makefiles" && \
	cmake --build . --config=RelWithDebInfo
	./$(TEST_EXE)
	lcov -t "$(TEST_EXE)" -o test.info --no-external -c -b . -d $(BUILDDIR)-coverage $(GCOVAPPLE)
	genhtml -o report test.info $(GCOVAPPLE)


dist:
	rm -rf $(DISTDIR)
	mkdir -p $(DISTDIR)
	cp -r $(PROJECTDIR) $(DISTDIR)
	cd .. && tar -czvf distributive.tgz distributive
	rm -rf $(DISTDIR)


check:
	clang-format --verbose -i */*.cc */*.h */*/*.cc */*/*.h


$(BUILDDIR)-%:
	mkdir -p $@


clean:
	@rm -rf $(BUILDDIR)-*
	@rm -rf report *.info
	@rm -rf *.tgz ../*.tgz
	@rm -rf MazeTests

