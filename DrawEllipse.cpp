#include "DrawEllipse.h"

DrawEllipse::DrawEllipse(const QPen &pen, const QBrush &brush, DrawShape *parent) :
    DrawShape(pen, brush, parent)
  , itsEllipse(new QGraphicsEllipseItem())
{
}

DrawEllipse::~DrawEllipse()
{
}

QRectF DrawEllipse::boundingRect() const
{
    return itsEllipse->boundingRect();
}

void DrawEllipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    itsEllipse->paint(painter, option, widget);
}

void DrawEllipse::draw(qreal x1, qreal y1, qreal x2, qreal y2)
{
    itsEllipse->setRect(x1, y1, x2 - x1, y2 - y1);
}
