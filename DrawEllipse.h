#ifndef DRAWELLIPSE_H
#define DRAWELLIPSE_H

#include "DrawShape.h"

class DrawEllipse : public DrawShape
{
    Q_OBJECT
public:
    explicit DrawEllipse(DrawShape *parent = 0);
    virtual ~DrawEllipse();
    virtual QGraphicsItem *draw(qreal x1, qreal y1, qreal x2, qreal y2, const QPen & pen = QPen());
};

#endif // DRAWELLIPSE_H
