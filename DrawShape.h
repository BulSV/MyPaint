#ifndef DRAWSHAPE_H
#define DRAWSHAPE_H

#include <QGraphicsItem>
#include <QPen>
#include <QBrush>

class DrawShape : public QGraphicsItem
{
public:
    enum {Type = UserType + 1};
    explicit DrawShape(const QPen &pen = QPen(), const QBrush &brush = QBrush(), QGraphicsItem *parent = 0);
    virtual ~DrawShape();
    int type() const;
    void setPen(const QPen &pen);
    void setBrush(const QBrush &brush);
    QPen pen() const;
    QBrush brush() const;
    virtual void draw(qreal x1, qreal y1, qreal x2, qreal y2) = 0;    
private:
    QPen itsPen;
    QBrush itsBrush;
};

#endif // DRAWSHAPE_H
