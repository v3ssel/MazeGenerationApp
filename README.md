# Maze
`Maze` is an application for visualizing mazes and caves presented in text format, as well as finding the path in the maze.

## Installation
To install to the `src` directory, navigate to the `src` folder and invoke the `make install` command.
```bash
cd src
make install
```
An executable file will appear in the selected folder.

To run the tests in the `src` folder, call the `make tests` command.
```bash
make tests
```

To uninstall a program in the `src` folder, call the `make uninstall` or `make clean` command.
```bash
make uninstall
```

The `Qt` library package, `googletest` library and `cmake` utility must be installed on the computer for correct build.


After running the tests, you can delete temporary files, including the build folder, with the `make clean` command
```bash
make clean
```

## User Interface
![Maze_interface.png](src/assets/screenshots/Maze_interface.png)

![Cave_interface.png](src/assets/screenshots/Cave_interface.png)

The application consists of one window with two tabs. In the left part of the tabs there is a widget for viewing the maze and cave, in the right part there are buttons for loading files, generating new structures and the rules by which they are created.

## Project structure
The project is implemented using `MVC` design pattern and `Singleton` in the controller.

All the source files of the project are located in the `src` folder. Its contents are:

* `assets` - test objects and screenshots of this README;
* `controllers` - implementation of the controller linking the model and GUI;
* `models` - implementation of parsing `.txt` files with caves and mazes, solving mazes;
* `tests` - tests for our functions;
* `views` - GUI files;
* `CMakeLists.txt` - file for generating an additional Makefile that builds the whole application;
* `Makefile` - the main makefile of the whole project, it allows to run targets `all, install, uninstall, clean, dvi, dist, tests`.

# Created by [stevenso](https://github.com/v3ssel), [darrpama](https://github.com/darrpama) and [myregree](https://github.com/atakhan) in educational purpose.
