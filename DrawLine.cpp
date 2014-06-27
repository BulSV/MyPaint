#include "DrawLine.h"

DrawLine::DrawLine(const QPen &pen, const QBrush &brush, DrawShape *parent) :
    DrawShape(pen, brush, parent)
{
}

DrawLine::~DrawLine()
{
}

void DrawLine::draw(qreal x1, qreal y1, qreal x2, qreal y2)
{
    itsLine->setLine(x1, y1, x2, y2);
}

QRectF DrawLine::boundingRect() const
{
    return itsLine->boundingRect();
}

void DrawLine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    itsLine->paint(painter, option, widget);
}
