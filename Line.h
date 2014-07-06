#ifndef LINE_H
#define LINE_H

#include <QGraphicsLineItem>
#include "AbstractShape.h"

class Line : public AbstractShape
{
    QGraphicsLineItem *itsLine;
public:
    enum {Type = UserType + 1};
    explicit Line(const QPen &pen = QPen(), const QBrush &brush = QBrush(), AbstractShape *parent = 0);
    virtual ~Line();
    int type() const;
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void draw(qreal x1, qreal y1, qreal x2, qreal y2);    
};

#endif // LINE_H
