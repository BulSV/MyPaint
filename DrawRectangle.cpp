#include "DrawRectangle.h"

DrawRectangle::DrawRectangle(DrawShape *parent) :
    DrawShape(parent)
{
}

DrawRectangle::~DrawRectangle()
{
}

QGraphicsItem *DrawRectangle::draw(qreal x1, qreal y1, qreal x2, qreal y2, const QPen &pen)
{
    return addRect(x1, y1, x2, y2, pen);
}
