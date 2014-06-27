#ifndef DRAWRECTANGLE_H
#define DRAWRECTANGLE_H

#include "DrawShape.h"

class DrawRectangle : public DrawShape
{
    Q_OBJECT
public:
    explicit DrawRectangle(DrawShape *parent = 0);
    virtual ~DrawRectangle();
    virtual QGraphicsItem *draw(qreal x1, qreal y1, qreal x2, qreal y2, const QPen & pen = QPen());
};

#endif // DRAWRECTANGLE_H
