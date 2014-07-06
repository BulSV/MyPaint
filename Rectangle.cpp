#include "Rectangle.h"

Rectangle::Rectangle(const QPen &pen, const QBrush &brush, AbstractShape *parent) :
    AbstractShape(pen, brush, parent)
  , itsRect(new QGraphicsRectItem())
{
}

Rectangle::~Rectangle()
{
    delete itsRect;
    itsRect = 0;
}

int Rectangle::type() const
{
    return Type;
}

QRectF Rectangle::boundingRect() const
{
    return itsRect->boundingRect();
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    itsRect->paint(painter, option, widget);
}

void Rectangle::draw(qreal x1, qreal y1, qreal x2, qreal y2)
{
    itsRect->setPen(pen());
    itsRect->setBrush(brush());
    itsRect->setRect(x1, y1, x2 - x1, y2 - y1);
}
