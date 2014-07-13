#ifndef RUBBER_H
#define RUBBER_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include "AbstractShape.h"
#include "Rectangle.h"

class Rubber :public AbstractShape
{        
    AbstractShape *itsBrushShape;
    QGraphicsScene *itsScene;
public:
    Rubber(QGraphicsScene *parentScene,
           const QPen &pen = QPen(),
           const QBrush &brush = QBrush(),
           AbstractShape *brushShape = new Rectangle(),
           AbstractShape *parent = 0);
    virtual ~Rubber();
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void draw(qreal x1, qreal y1, qreal x2, qreal y2);
    void setBrushShape(AbstractShape *brushShape);
};

#endif // RUBBER_H
