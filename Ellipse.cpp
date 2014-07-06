#include "Ellipse.h"

Ellipse::Ellipse(const QPen &pen, const QBrush &brush, AbstractShape *parent) :
    AbstractShape(pen, brush, parent)
  , itsEllipse(new QGraphicsEllipseItem())
{
}

Ellipse::~Ellipse()
{
    delete itsEllipse;
    itsEllipse = 0;
}

int Ellipse::type() const
{
    return Type;
}

QRectF Ellipse::boundingRect() const
{
    return itsEllipse->boundingRect();
}

void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    itsEllipse->paint(painter, option, widget);
}

void Ellipse::draw(qreal x1, qreal y1, qreal x2, qreal y2)
{
    itsEllipse->setPen(pen());
    itsEllipse->setBrush(brush());
    itsEllipse->setRect(x1, y1, x2 - x1, y2 - y1);
}
