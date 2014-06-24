#include "Canvas.h"

#include <QDebug>

Canvas::Canvas(QWidget *parent) :
    QWidget(parent)
  , p(new QPainter)
  , itsStartX(0)
  , itsStartY(0)
  , itsEndX(0)
  , itsEndY(0)
{    
}

Canvas::~Canvas()
{
}

int Canvas::startX() const
{
    return itsStartX;
}

int Canvas::startY() const
{
    return itsStartY;
}

int Canvas::endX() const
{
    return itsEndX;
}

int Canvas::endY() const
{
    return itsEndY;
}

void Canvas::mousePressEvent(QMouseEvent *pe)
{
    qDebug() << "void MainWindow::mousePressEvent(QMouseEvent *pe)";
    if(pe->buttons() & Qt::LeftButton)
    {
        itsStartX = pe->x();
        itsStartY = pe->y();
    }
}

void Canvas::mouseMoveEvent(QMouseEvent *pe)
{
    if(pe->buttons() & Qt::LeftButton)
    {
        itsEndX = pe->x();
        itsEndY = pe->y();

        update();

        emit painting(startX(), startY(), endX(), endY());
    }
}

void Canvas::mouseReleaseEvent(QMouseEvent *pe)
{
    qDebug() << "void MainWindow::mouseReleaseEvent(QMouseEvent *pe)";
    if(pe->buttons() & Qt::LeftButton)
    {
        itsEndX = pe->x();
        itsEndY = pe->y();
    }
}

void Canvas::paintEvent(QPaintEvent *)
{
    p->begin(this);
    p->setPen(QPen(Qt::black, 3));
    p->drawLine(QPointF(itsStartX, itsStartY), QPointF(itsEndX, itsEndY));
    p->end();
}
