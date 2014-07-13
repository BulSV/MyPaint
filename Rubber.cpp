#include "Rubber.h"

#include <QDebug>

Rubber::Rubber(QGraphicsScene *parentScene,
               const QPen &pen,
               const QBrush &brush,
               AbstractShape *brushShape,
               AbstractShape *parent) :
    AbstractShape(pen, brush, parent)
  , itsBrushShape(brushShape)
  , itsScene(parentScene)
{
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
    itsScene->addItem(new Rubber(itsScene));
}

void Rubber::setBrushShape(AbstractShape *brushShape)
{
    itsBrushShape = brushShape;
}
