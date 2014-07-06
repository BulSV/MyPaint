#include "AbstractShape.h"

AbstractShape::AbstractShape(const QPen &pen, const QBrush &brush, QGraphicsItem *parent) :
    QGraphicsItem(parent)
  , itsPen(pen)
  , itsBrush(brush)
{
}


AbstractShape::~AbstractShape()
{
}

int AbstractShape::type() const
{
    return Type;
}

void AbstractShape::setPen(const QPen &pen)
{
    itsPen = pen;
}

void AbstractShape::setBrush(const QBrush &brush)
{
    itsBrush = brush;
}

QPen AbstractShape::pen() const
{
    return itsPen;
}

QBrush AbstractShape::brush() const
{
    return itsBrush;
}
