#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QLabel>
#include <QFrame>
#include <QPainter>
#include <QScrollArea>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "Canvas.h"
#include "DrawLine.h"
#include "DrawRectangle.h"
#include "DrawEllipse.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLabel *lStartX;
    QLabel *lStartY;
    QLabel *lEndX;
    QLabel *lEndY;
    QFrame *frmXYLineSeparator;
//    Canvas *canvas;
private slots:
    void setStartXY_EndXY(int startX, int startY, int endX, int endY);
    void newImage();
    void on_bDrawLine_clicked();
};

#endif // MAINWINDOW_H
