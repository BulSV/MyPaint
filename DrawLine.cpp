#include "DrawLine.h"

DrawLine::DrawLine(DrawShape *parent) :
    DrawShape(parent)
{
}

DrawLine::~DrawLine()
{
}

QGraphicsItem *DrawLine::draw(qreal x1, qreal y1, qreal x2, qreal y2, const QPen &pen)
{
    return addLine(x1, y1, x2, y2, pen);
}
