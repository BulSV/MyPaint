#include "DrawShape.h"

DrawShape::DrawShape(const QPen &pen, const QBrush &brush, QGraphicsItem *parent) :
    QObject()
  , QGraphicsItem(parent)
  , itsPen(pen)
  , itsBrush(brush)
{
}


DrawShape::~DrawShape()
{
}

void DrawShape::setPen(const QPen &pen)
{
    itsPen = pen;
}

void DrawShape::setBrush(const QBrush &brush)
{
    itsBrush = brush;
}

QPen DrawShape::pen() const
{
    return itsPen;
}

QBrush DrawShape::brush() const
{
    return itsBrush;
}
