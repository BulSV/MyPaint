#include "Canvas.h"

#include <QDebug>

Canvas::Canvas(QGraphicsView *parent) :
    QGraphicsView(parent)
  , itsStartX(0)
  , itsStartY(0)
  , itsEndX(0)
  , itsEndY(0)
  , itsIsLeftButtonPressed(false)
  , itsIsShapeSet(false)
  , itsScene(new Scene())
  , itsPen(QPen())
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

    itsScene->addRect(x, y, w , h, pen);
    itsScene->addLine(x+ w + (widthShadow - width)/2, y + widthShadow, x + w + (widthShadow - width)/2, y + h + widthShadow/2, penShadow);
    itsScene->addLine(x + widthShadow, y + h + (widthShadow - width)/2, x + w + widthShadow/2, y + h + (widthShadow - width)/2, penShadow);
}

DrawShape *Canvas::currentShape()
{
    return (DrawShape*)itsScene->items().first();
}

void Canvas::setColor(QColor color)
{
    itsPen.setColor(color);
}

QColor Canvas::color() const
{
    return itsPen.color();
}

void Canvas::setWidth(int width)
{
    itsPen.setWidth(width);
}

int Canvas::width() const
{
    return itsPen.width();
}

void Canvas::mousePressEvent(QMouseEvent *pe)
{
    if(pe->buttons() & Qt::LeftButton)
    {        
        QPointF point = mapToScene(pe->pos());        
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
                ((DrawShape*)itsScene->items().first())->setPen(itsPen);
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
        itsIsLeftButtonPressed = false;
        itsIsShapeSet = false;
    }
}
