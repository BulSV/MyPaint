#ifndef DRAWLINE_H
#define DRAWLINE_H

#include <QGraphicsLineItem>
#include "DrawShape.h"

class DrawLine : public DrawShape
{
    QGraphicsLineItem *itsLine;
public:
    enum {Type = UserType + 1};
    explicit DrawLine(const QPen &pen = QPen(), const QBrush &brush = QBrush(), DrawShape *parent = 0);    
    virtual ~DrawLine();
    int type() const;
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void draw(qreal x1, qreal y1, qreal x2, qreal y2);    
};

#endif // DRAWLINE_H
