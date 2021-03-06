#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <QGraphicsEllipseItem>
#include "AbstractShape.h"

class Ellipse : public AbstractShape
{
    QGraphicsEllipseItem *itsEllipse;
public:
    enum {Type = UserType + 1};
    explicit Ellipse(const QPen &pen = QPen(), const QBrush &brush = QBrush(), AbstractShape *parent = 0);
    virtual ~Ellipse();
    int type() const;
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void draw(qreal x1, qreal y1, qreal x2, qreal y2);
};

#endif // ELLIPSE_H
