#ifndef DRAWRECTANGLE_H
#define DRAWRECTANGLE_H

#include <QGraphicsRectItem>
#include "DrawShape.h"

class DrawRectangle : public DrawShape
{
    QGraphicsRectItem *itsRect;
public:
    enum {Type = UserType + 1};
    explicit DrawRectangle(const QPen &pen = QPen(), const QBrush &brush = QBrush(), DrawShape *parent = 0);
    virtual ~DrawRectangle();
    int type() const;
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void draw(qreal x1, qreal y1, qreal x2, qreal y2);
};

#endif // DRAWRECTANGLE_H
