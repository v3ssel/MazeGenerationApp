#ifndef CPP4_3DVIEWER_V2_0_2_SRC_VIEWS_CAVE_CANVAS_H
#define CPP4_3DVIEWER_V2_0_2_SRC_VIEWS_CAVE_CANVAS_H

#include <QWidget>
#include <QPainter>

class CaveCanvas : public QWidget {
 public:
  CaveCanvas(QWidget *parent = nullptr) : QWidget(parent) {}
  
 protected:
  void paintEvent(QPaintEvent *event) override;

 private:
  std::vector<int> maze_;
  int cols_;
  int rows_;
  int cell_width_ = 0;
  int cell_height_ = 0;

  void DrawCell(QPainter *p, size_t i, size_t j, int wall);
  void DrawCellBody(QPainter *p, size_t i, size_t j);
  void DrawRightWall(QPainter *p, size_t i, size_t j);
  void DrawBottomWall(QPainter *p, size_t i, size_t j);
};

#endif // CPP4_3DVIEWER_V2_0_2_SRC_VIEWS_CAVE_CANVAS_H