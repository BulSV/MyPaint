#ifndef DRAWPIXMAP_H
#define DRAWPIXMAP_H

#include <QGraphicsPixmapItem>
#include "DrawShape.h"

class DrawPixmap : public DrawShape
{
    QGraphicsPixmapItem *itsPixmap;
public:    
    enum {Type = UserType + 1};
    explicit DrawPixmap(DrawShape *parent = 0);
    explicit DrawPixmap(const QPixmap &pixmap, DrawShape *parent = 0);
    virtual ~DrawPixmap();
    int type() const;
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void draw(qreal x1, qreal y1, qreal x2, qreal y2);
};

#endif // DRAWPIXMAP_H
