#ifndef RUBBER_H
#define RUBBER_H

#include <QGraphicsRectItem>
#include "AbstractShape.h"

class Rubber : public AbstractShape
{
    QGraphicsRectItem *itsRect;
public:
    Rubber(const QPen &pen = QPen(), const QBrush &brush = QBrush(), AbstractShape *parent = 0);
    virtual ~Rubber();
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void draw(qreal x1, qreal y1, qreal x2, qreal y2);
};

#endif // RUBBER_H
