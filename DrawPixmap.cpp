#include "DrawPixmap.h"

DrawPixmap::DrawPixmap(DrawShape *parent) :
    DrawShape()
  , itsPixmap(new QGraphicsPixmapItem(parent))
{
}

DrawPixmap::DrawPixmap(const QPixmap &pixmap, DrawShape *parent) :
    DrawShape()
  , itsPixmap(new QGraphicsPixmapItem(pixmap, parent))
{
}

DrawPixmap::~DrawPixmap()
{
    delete itsPixmap;
    itsPixmap = 0;
}

int DrawPixmap::type() const
{
    return Type;
}

QRectF DrawPixmap::boundingRect() const
{
    return itsPixmap->boundingRect();
}

void DrawPixmap::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    itsPixmap->paint(painter, option, widget);
}

void DrawPixmap::draw(qreal x1, qreal y1, qreal x2, qreal y2)
{
    itsPixmap->setOffset(x1, y1);
}
