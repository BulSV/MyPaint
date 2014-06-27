#ifndef DRAWLINE_H
#define DRAWLINE_H

#include "DrawShape.h"

class DrawLine : public DrawShape
{
    Q_OBJECT
public:
    explicit DrawLine(DrawShape *parent = 0);
    virtual ~DrawLine();
    virtual QGraphicsItem *draw(qreal x1, qreal y1, qreal x2, qreal y2, const QPen & pen = QPen());
};

#endif // DRAWLINE_H
