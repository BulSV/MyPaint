#ifndef RUBBER_H
#define RUBBER_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include "AbstractShape.h"
#include "Rectangle.h"
#include "Ellipse.h"

class Rubber :public AbstractShape
{            
public:
    enum BrushShapes
    {
        RectangleShape, EllipseShape
    };

    Rubber(QGraphicsScene *parentScene,
           BrushShapes brushShape = RectangleShape,
           const QPen &pen = QPen(),
           const QBrush &brush = QBrush(),
           AbstractShape *parent = 0);
    virtual ~Rubber();
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void draw(qreal x1, qreal y1, qreal x2, qreal y2);
    void setBrushShape(BrushShapes brushShape);
private:
    AbstractShape *itsBrushShape;
    QGraphicsScene *itsScene;
    BrushShapes itsBrushShapeType;

    void shapeChocer(BrushShapes brushShape);
};

#endif // RUBBER_H
