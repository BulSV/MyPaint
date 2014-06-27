#include "DrawEllipse.h"

DrawEllipse::DrawEllipse(DrawShape *parent) :
    DrawShape(parent)
{
}

DrawEllipse::~DrawEllipse()
{
}

QGraphicsItem *DrawEllipse::draw(qreal x1, qreal y1, qreal x2, qreal y2, const QPen &pen)
{
    return addEllipse(x1, y1, x2, y2, pen);
}
