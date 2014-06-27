#include "DrawRectangle.h"

DrawRectangle::DrawRectangle(const QPen &pen, const QBrush &brush, DrawShape *parent) :
    DrawShape(pen, brush, parent)
{
}

DrawRectangle::~DrawRectangle()
{
}

QRectF DrawRectangle::boundingRect() const
{
    return itsRect->boundingRect();
}

void DrawRectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    itsRect->paint(painter, option, widget);
}

void DrawRectangle::draw(qreal x1, qreal y1, qreal x2, qreal y2)
{
    itsRect->setRect(x1, y1, x2, y2);
}
