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
  , itsIsShapeDrawn(true)
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

void Canvas::addShape(AbstractShape *shape)
{
    // Delete undrawn shape
    if(!itsIsShapeDrawn)
    {
        AbstractShape *undrawnShape = currentShape();
        itsScene->removeItem(undrawnShape);
        delete undrawnShape;
        undrawnShape = 0;
    }

    itsScene->addItem(shape);
    itsIsShapeDrawn = false;
    itsIsShapeSet = true;
}

void Canvas::setSceneRect(qreal x, qreal y, qreal w, qreal h)
{
    itsScene->setSceneRect(x, y, w, h);

    qreal width = 0.5;
    QPen pen(QBrush(Qt::black), width);
    pen.setCapStyle(Qt::SquareCap);
    pen.setJoinStyle(Qt::MiterJoin);

    qreal widthShadow = 7;
    QPen penShadow(QBrush(Qt::lightGray), widthShadow);
    penShadow.setCapStyle(Qt::SquareCap);
    penShadow.setJoinStyle(Qt::RoundJoin);

    QGraphicsItemGroup *group = new QGraphicsItemGroup();

    QGraphicsLineItem *rightLine =
            new QGraphicsLineItem(x+ w + (widthShadow - width)/2,
                                  y + widthShadow,
                                  x + w + (widthShadow - width)/2,
                                  y + h + widthShadow/2);
    rightLine->setPen(penShadow);

    QGraphicsLineItem *bottomLine =
            new QGraphicsLineItem(x + widthShadow,
                                  y + h + (widthShadow - width)/2,
                                  x + w + widthShadow/2,
                                  y + h + (widthShadow - width)/2);
    bottomLine->setPen(penShadow);

    QGraphicsRectItem *rect = new QGraphicsRectItem(x, y, w , h);
    rect->setPen(pen);

    group->addToGroup(rightLine);
    group->addToGroup(bottomLine);
    group->addToGroup(rect);

    itsScene->addItem(group);
}

AbstractShape *Canvas::currentShape()
{
    return (AbstractShape*)itsScene->items().first();
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

void Canvas::clear()
{
    itsScene->clear();
}

QRectF Canvas::drawRect() const
{
    QPoint p1 = mapFromScene(QPointF(itsScene->sceneRect().topLeft().x(), itsScene->sceneRect().topLeft().y()));
    QPoint p2 = mapFromScene(QPointF(itsScene->sceneRect().bottomRight().x(), itsScene->sceneRect().bottomRight().y()));

    QRectF rect(p1, p2);

    return rect;
}

void Canvas::mousePressEvent(QMouseEvent *pe)
{
    if(pe->buttons() & Qt::LeftButton)
    {
        QPointF point = mapToScene(pe->pos());
        itsStartX = point.x();
        itsStartY = point.y();
        if(point.x() > sceneRect().topLeft().x()
                && point.y() > sceneRect().topLeft().y()
                && point.x() < sceneRect().bottomRight().x()
                && point.y() < sceneRect().bottomRight().y())
        {
            itsIsLeftButtonPressed = true;
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
                itsScene->currentShape()->setPen(itsPen);
                itsScene->currentShape()->draw(startX(), startY(), endX(), endY());
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
        itsIsShapeDrawn = true;
        itsIsLeftButtonPressed = false;
        itsIsShapeSet = false;
    }
}
