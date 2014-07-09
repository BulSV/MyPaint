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
#include <QColorDialog>
#include <QFileDialog>
#include "Canvas.h"
#include "Line.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "SimpleTextDialog.h"
#include "Pixmap.h"
#include "CanvasObserver.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public CanvasObserver
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    virtual void drawSameShapeType();

private:
    Ui::MainWindow *ui;
    QLabel *lStartX;
    QLabel *lStartY;
    QLabel *lEndX;
    QLabel *lEndY;
    QFrame *frmXYLineSeparator;
    QString currentDirOpen;
    QString currentDirSave;
    enum ShapeTypes
    {
        LineType, RectangleType, EllipseType, SimpleTextType
    };

    ShapeTypes lastDrawnShapeType;

    AbstractShape *lastDrawnShape();
private slots:
    void setStartXY_EndXY(int startX, int startY, int endX, int endY);
    void newImage();
    void on_bDrawLine_clicked();
    void on_bDrawRectangle_clicked();
    void on_bDrawEllipse_clicked();
    void on_bDrawText_clicked();
    void on_bPenColor_clicked();
    void on_bPenWidth_clicked();
    void open();
    void save();
    void closeTab(int tabIndex);
};

#endif // MAINWINDOW_H
