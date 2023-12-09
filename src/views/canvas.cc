#include "canvas.h"

<<<<<<< HEAD:src/views/canvas.cc
void Canvas::paintEvent(QPaintEvent *event) {
  QPainter painter = QPainter(this);
  setFixedSize(500, 500);
  std::vector<int> maze = {
    0, 2, 3, 1,
    0, 1, 0, 1,
    3, 2, 3, 1
  };
  cols_ = 4;
  rows_ = 3;
  cell_width_ = std::round(498.0f / cols_ - 2.0f);
  cell_height_ = std::round(498.0f / rows_ - 2.0f);
=======
void CaveCanvas::paintEvent(QPaintEvent *event) {
  cave_ = s21::ControllerSingleton::GetInstance().GetCave();  
  if (cave_->GetCols() > 0 && cave_->GetRows() > 0) {
    QPainter painter = QPainter(this);
    setFixedSize(500, 500);
>>>>>>> added cave upload, parse and render;:src/views/cave_canvas.cc

    int cols = cave_->GetCols();
    int rows = cave_->GetRows();

    cell_width_ = std::round(500.0f / cols);
    cell_height_ = std::round(500.0f / rows);

    size_t index = 0;
    for (size_t i = 0; i < rows; i++) {
      for (size_t j = 0; j < cols; j++) {
        unsigned cell = cave_->GetMatrix()[index];
        DrawCell(&painter, i, j, cell);
        index++;
      }
    }
    painter.fillRect(0, 0, 500, 2, Qt::black);
    painter.fillRect(0, 0, 2, 500, Qt::black);
    painter.end();
  }
}

<<<<<<< HEAD:src/views/canvas.cc
void Canvas::DrawCell(QPainter *p, size_t i, size_t j, int wall) {
  if (wall == 0) {  // TODO: 0 - нет границ 
    DrawCellBody(p, i, j);
  }
  if (wall == 1) {  // TODO: 1 - граница справа
    DrawCellBody(p, i, j);
    DrawRightWall(p, i, j);
  }
  if (wall == 2) {  // TODO: 2 - граница снизу
    DrawCellBody(p, i, j);
    DrawBottomWall(p, i, j);
  }
  if (wall == 3) {  // TODO: 3 - границы и снизу и справа
    DrawCellBody(p, i, j);
    DrawRightWall(p, i, j);
    DrawBottomWall(p, i, j);
  }
}

void Canvas::DrawCellBody(QPainter *p, size_t i, size_t j) {
=======
void CaveCanvas::DrawCell(QPainter *p, size_t i, size_t j, unsigned cell) {
  if (cell == 0) {
    DrawCellBody(p, i, j, Qt::GlobalColor::white);
  } else {
    DrawCellBody(p, i, j, Qt::GlobalColor::black);
  }
}

void CaveCanvas::DrawCellBody(QPainter *p, size_t i, size_t j, Qt::GlobalColor color) {
>>>>>>> added cave upload, parse and render;:src/views/cave_canvas.cc
  p->fillRect(
    (cell_width_ * j),
    (cell_height_ * i),
    cell_width_,
    cell_height_, 
<<<<<<< HEAD:src/views/canvas.cc
    Qt::GlobalColor::white
  );
}

void Canvas::DrawRightWall(QPainter *p, size_t i, size_t j) {
  p->fillRect(
    (cell_width_ * j) + (j*2) + cell_width_,
    (cell_height_ * i) + (i*2),
    2,
    cell_height_,
    Qt::GlobalColor::darkBlue
  );
}

void Canvas::DrawBottomWall(QPainter *p, size_t i, size_t j) {
  p->fillRect(
    (cell_width_ * j) + (j*2),
    (cell_height_ * i) + (i*2) + cell_height_,
    cell_width_,
    2,
    Qt::GlobalColor::darkBlue
=======
    color
>>>>>>> added cave upload, parse and render;:src/views/cave_canvas.cc
  );
}

