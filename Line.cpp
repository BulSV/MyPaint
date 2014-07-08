#include "Line.h"

#include <QDebug>

Line::Line(const QPen &pen, const QBrush &brush, AbstractShape *parent) :
    AbstractShape(pen, brush, parent)
  , itsLine(new QGraphicsLineItem())
{
}

Line::~Line()
{
    delete itsLine;
    itsLine = 0;
}

int Line::type() const
{
    return Type;
}

void Line::draw(qreal x1, qreal y1, qreal x2, qreal y2)
{
    itsLine->setPen(pen());
    itsLine->setLine(x1, y1, x2, y2);
}

QRectF Line::boundingRect() const
{
    return itsLine->boundingRect();
}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    itsLine->paint(painter, option, widget);
}
