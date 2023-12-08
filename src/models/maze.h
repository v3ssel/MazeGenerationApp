#ifndef A1_MAZE_1_0_SRC_MAZE_H
#define A1_MAZE_1_0_SRC_MAZE_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#include "../type.h"

namespace s21 {

class Maze {
 public:
  Maze(int rows, int cols) : rows_(rows), cols_(cols), matrix_{} {}

  int GetRows();
  int GetCols();
  void SetRows(int);
  void SetCols(int);
  void Push(Border);
  std::vector<Border>& GetMatrix();

  void Clear();
  bool IsIdeal();

 private:
  int rows_;
  int cols_;
  std::vector<Border> matrix_;
};

}  // namespace s21

#endif  // A1_MAZE_1_0_SRC_MAZE_H
