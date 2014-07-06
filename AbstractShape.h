#ifndef ABSTRACTSHAPE_H
#define ABSTRACTSHAPE_H

#include <QGraphicsItem>
#include <QPen>
#include <QBrush>

class AbstractShape : public QGraphicsItem
{
public:
    enum {Type = UserType + 1};
    explicit AbstractShape(const QPen &pen = QPen(), const QBrush &brush = QBrush(), QGraphicsItem *parent = 0);
    virtual ~AbstractShape();
    int type() const;
    virtual void setPen(const QPen &pen);
    virtual void setBrush(const QBrush &brush);
    QPen pen() const;
    QBrush brush() const;
    virtual void draw(qreal x1, qreal y1, qreal x2, qreal y2) = 0;    
private:
    QPen itsPen;
    QBrush itsBrush;
};

#endif // ABSTRACTSHAPE_H
