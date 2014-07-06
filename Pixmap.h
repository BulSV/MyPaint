#ifndef PIXMAP_H
#define PIXMAP_H

#include <QGraphicsPixmapItem>
#include "AbstractShape.h"

class Pixmap : public AbstractShape
{
    QGraphicsPixmapItem *itsPixmap;
public:    
    enum {Type = UserType + 1};
    explicit Pixmap(AbstractShape *parent = 0);
    explicit Pixmap(const QPixmap &pixmap, AbstractShape *parent = 0);
    virtual ~Pixmap();
    int type() const;
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void draw(qreal x1, qreal y1, qreal x2, qreal y2);
};

#endif // PIXMAP_H
