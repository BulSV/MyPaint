#include "Rubber.h"

#include <QDebug>

void Rubber::shapeChocer(BrushShapes brushShape)
{
    switch(brushShape)
    {
    case RectangleShape: itsBrushShape = new Rectangle();
        break;
    case EllipseShape: itsBrushShape = new Ellipse();
        break;
    default: itsBrushShape = new Rectangle();
        break;
    }
    itsBrushShapeType = brushShape;
}

Rubber::Rubber(QGraphicsScene *parentScene,
               BrushShapes brushShape,
               const QPen &pen,
               const QBrush &brush,
               AbstractShape *parent) :
    AbstractShape(pen, brush, parent)
//  , itsBrushShape(brushShape)
  , itsScene(parentScene)
{
    shapeChocer(brushShape);
    itsBrushShape->setPen(QPen(Qt::NoPen));
    itsBrushShape->setBrush(QBrush(QColor(Qt::white)));
}

Rubber::~Rubber()
{
    delete itsBrushShape;
    itsBrushShape = 0;
}

QRectF Rubber::boundingRect() const
{
    return itsBrushShape->boundingRect();
}

void Rubber::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    itsBrushShape->paint(painter, option, widget);
}

void Rubber::draw(qreal x1, qreal y1, qreal x2, qreal y2)
{
    itsBrushShape->draw(x2 - pen().width()/2, y2 - pen().width()/2,
                        x2 + pen().width()/2, y2 + pen().width()/2);
    itsScene->addItem(new Rubber(itsScene, itsBrushShapeType));
}

void Rubber::setBrushShape(BrushShapes brushShape)
{
    delete itsBrushShape;
    shapeChocer(brushShape);
}
