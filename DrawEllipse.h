#ifndef DRAWELLIPSE_H
#define DRAWELLIPSE_H

#include <QGraphicsEllipseItem>
#include "DrawShape.h"

class DrawEllipse : public DrawShape
{
    Q_OBJECT
    QGraphicsEllipseItem *itsEllipse;
public:
    explicit DrawEllipse(const QPen &pen = QPen(), const QBrush &brush = QBrush(), DrawShape *parent = 0);
    virtual ~DrawEllipse();
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void draw(qreal x1, qreal y1, qreal x2, qreal y2);
};

#endif // DRAWELLIPSE_H
