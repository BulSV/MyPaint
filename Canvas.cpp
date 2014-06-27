#include "Canvas.h"

#include <QDebug>

Canvas::Canvas(QGraphicsView *parent) :
    QGraphicsView(parent)
  , itsStartX(0)
  , itsStartY(0)
  , itsEndX(0)
  , itsEndY(0)
  , itsCurrentPainter(0)
  , itsIsLeftButtonPressed(false)
  , itsScene(new QGraphicsScene())
{
    this->setScene(itsScene);
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

void Canvas::addShape(DrawShape *shape)
{
    itsScene->addItem(shape);
}

void Canvas::setSceneRect(qreal x, qreal y, qreal w, qreal h)
{
    itsScene->setSceneRect(x, y, w, h);
    itsScene->addLine(0, 0, w, 0);
    itsScene->addLine(w, 0, w, h);
    itsScene->addLine(w, h, 0, h);
    itsScene->addLine(0, h, 0, 0);
    itsCurrentPainter = 4;
}

void Canvas::mousePressEvent(QMouseEvent *pe)
{
    if(pe->buttons() & Qt::LeftButton)
    {
        qDebug() << "void MainWindow::mousePressEvent(QMouseEvent *pe)";
        QPointF point = mapToScene(pe->pos());
        itsStartX = point.x();
        itsStartY = point.y();
        itsIsLeftButtonPressed = true;
    }
}

void Canvas::mouseMoveEvent(QMouseEvent *pe)
{
    if(pe->buttons() & Qt::LeftButton)
    {
        QPointF point = mapToScene(pe->pos());
        itsEndX = point.x();
        itsEndY = point.y();

        if(itsScene->items().size() > itsCurrentPainter)
        {
            QGraphicsItem *gi = itsScene->items().first();
            itsScene->items().removeFirst();
            delete gi;
            gi = 0;
        }

//        itsScene->addLine(startX(), startY(), endX(), endY());
        ((DrawShape*)itsScene->items().at(itsCurrentPainter - 1))->draw(startX(), startY(), endX(), endY());
        qDebug() << "Number of Items" << itsScene->items().size();

        emit painting(startX(), startY(), endX(), endY());
    }
}

void Canvas::mouseReleaseEvent(QMouseEvent *pe)
{
    if(itsIsLeftButtonPressed)
    {
        qDebug() << "void MainWindow::mouseReleaseEvent(QMouseEvent *pe)";
        itsEndX = pe->x();
        itsEndY = pe->y();
        ++itsCurrentPainter;
        itsIsLeftButtonPressed = false;
    }
}
