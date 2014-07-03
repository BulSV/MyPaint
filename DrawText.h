#ifndef DRAWTEXT_H
#define DRAWTEXT_H

#include <QGraphicsTextItem>
#include "DrawShape.h"

class DrawText : public DrawShape
{
    QGraphicsSimpleTextItem *itsText;
public:
    explicit DrawText(DrawShape *parent = 0);
    explicit DrawText(QString &text, DrawShape *parent = 0);
    virtual ~DrawText();
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void draw(qreal x1, qreal y1, qreal x2, qreal y2);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *pe);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *pe);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *pe);
};

#endif // DRAWTEXT_H
