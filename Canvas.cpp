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
  , itsIsShapeSet(false)
  , itsScene(new Scene())
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
    itsIsShapeSet = true;
}

void Canvas::setSceneRect(qreal x, qreal y, qreal w, qreal h)
{
    itsScene->setSceneRect(x, y, w, h);

    qreal width = 0.5;
    QPen pen(QBrush(Qt::gray), width);
    pen.setCapStyle(Qt::SquareCap);
    pen.setJoinStyle(Qt::MiterJoin);

    qreal widthShadow = 5;
    QPen penShadow(QBrush(Qt::gray), widthShadow);
    penShadow.setCapStyle(Qt::SquareCap);
    penShadow.setJoinStyle(Qt::RoundJoin);

    itsScene->addRect(0, 0, w , h, pen);
    itsScene->addLine(w + widthShadow/2, widthShadow, w + widthShadow/2, h + widthShadow/2, penShadow);
    itsScene->addLine(widthShadow, h + widthShadow/2, w + widthShadow/2, h + widthShadow/2, penShadow);

    itsCurrentPainter = 3;
}

void Canvas::mousePressEvent(QMouseEvent *pe)
{
    if(pe->buttons() & Qt::LeftButton)
    {
        qDebug() << "void MainWindow::mousePressEvent(QMouseEvent *pe)";
        qDebug() << sceneRect();
        qDebug() << sceneRect().topLeft();
        qDebug() << sceneRect().bottomRight();

        QPointF point = mapToScene(pe->pos());
        qDebug() << point;
        if(point.x() > sceneRect().topLeft().x()
                && point.y() > sceneRect().topLeft().y()
                && point.x() < sceneRect().bottomRight().x()
                && point.y() < sceneRect().bottomRight().y())
        {
            itsStartX = point.x();
            itsStartY = point.y();
            itsIsLeftButtonPressed = true;
        }
        else
        {
            itsStartX = point.x();
            itsStartY = point.y();
        }
    }
}

void Canvas::mouseMoveEvent(QMouseEvent *pe)
{
    if(pe->buttons() & Qt::LeftButton)
    {
        QPointF point = mapToScene(pe->pos());
        if(point.x() > sceneRect().topLeft().x()
                && point.y() > sceneRect().topLeft().y()
                && point.x() < sceneRect().bottomRight().x()
                && point.y() < sceneRect().bottomRight().y())
        {
            itsEndX = point.x();
            itsEndY = point.y();

            if(startX() < sceneRect().topLeft().x()
                    || startY() < sceneRect().topLeft().y()
                    || startX() > sceneRect().bottomRight().x()
                    || startY() > sceneRect().bottomRight().y())
            {
                itsStartX = endX();
                itsStartY = endY();
            }

            if(itsIsShapeSet)
            {
                ((Scene*)itsScene)->draw((DrawShape*)itsScene->items().first(), startX(), startY(), endX(), endY());

                itsScene->update();
            }

            emit painting(startX(), startY(), endX(), endY());
        }
    }
}

void Canvas::mouseReleaseEvent(QMouseEvent *pe)
{
    if(itsIsLeftButtonPressed)
    {
        qDebug() << "void MainWindow::mouseReleaseEvent(QMouseEvent *pe)";
        ++itsCurrentPainter;
        itsIsLeftButtonPressed = false;
        itsIsShapeSet = false;
    }
}
