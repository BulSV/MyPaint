#ifndef DRAWRECTANGLE_H
#define DRAWRECTANGLE_H

#include <QGraphicsRectItem>
#include "DrawShape.h"

class DrawRectangle : public DrawShape
{
    Q_OBJECT
    QGraphicsRectItem *itsRect;
public:
    explicit DrawRectangle(const QPen &pen = QPen(), const QBrush &brush = QBrush(), DrawShape *parent = 0);
    virtual ~DrawRectangle();
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void draw(qreal x1, qreal y1, qreal x2, qreal y2);
};

#endif // DRAWRECTANGLE_H
