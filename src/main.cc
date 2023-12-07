#include <QApplication>

#include "controllers/controller_singleton.h"
#include "models/model.h"
#include "models/maze.h"
#include "models/maze_parser.h"
#include "views/mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);


  MainWindow *window = new MainWindow();

  s21::Maze maze = s21::Maze(0, 0);
  s21::MazeParser maze_parser = s21::MazeParser(&maze);
  s21::Model model = s21::Model(&maze, &maze_parser);
  s21::ControllerSingleton &controller = s21::ControllerSingleton::GetInstance();
  controller.SetModel(&model);

  // window->setWindowTitle(QString("Maze"));
  window->show();

  return a.exec();
}
