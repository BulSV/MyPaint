#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QGraphicsRectItem>
#include "AbstractShape.h"

class Rectangle : public AbstractShape
{
    QGraphicsRectItem *itsRect;
public:
    enum {Type = UserType + 1};
    explicit Rectangle(const QPen &pen = QPen(), const QBrush &brush = QBrush(), AbstractShape *parent = 0);
    virtual ~Rectangle();
    int type() const;
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void draw(qreal x1, qreal y1, qreal x2, qreal y2);
};

#endif // RECTANGLE_H
