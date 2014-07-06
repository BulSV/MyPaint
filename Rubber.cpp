#include "Rubber.h"

Rubber::Rubber(const QPen &pen, const QBrush &brush, AbstractShape *parent) :
    AbstractShape(pen, brush, parent)
  , itsRect(new QGraphicsRectItem())
{
}

Rubber::~Rubber()
{
    delete itsRect;
    itsRect = 0;
}

QRectF Rubber::boundingRect() const
{
    return itsRect->boundingRect();
}

void Rubber::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    itsRect->paint(painter, option, widget);
}

void Rubber::draw(qreal x1, qreal y1, qreal x2, qreal y2)
{
    itsRect->setRect(-x2/2, -y2/2, x2/2, y2/2);
    itsRect->setBrush(QBrush(QColor(Qt::white)));
}
