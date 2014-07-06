#include "Pixmap.h"

Pixmap::Pixmap(AbstractShape *parent) :
    AbstractShape()
  , itsPixmap(new QGraphicsPixmapItem(parent))
{
}

Pixmap::Pixmap(const QPixmap &pixmap, AbstractShape *parent) :
    AbstractShape()
  , itsPixmap(new QGraphicsPixmapItem(pixmap, parent))
{
}

Pixmap::~Pixmap()
{
    delete itsPixmap;
    itsPixmap = 0;
}

int Pixmap::type() const
{
    return Type;
}

QRectF Pixmap::boundingRect() const
{
    return itsPixmap->boundingRect();
}

void Pixmap::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    itsPixmap->paint(painter, option, widget);
}

void Pixmap::draw(qreal x1, qreal y1, qreal x2, qreal y2)
{
    itsPixmap->setOffset(x1, y1);
}
