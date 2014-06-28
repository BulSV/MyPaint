#ifndef DRAWSHAPE_H
#define DRAWSHAPE_H

//#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QObject>
#include <QPen>
#include <QBrush>
//#include <QGraphicsObject>

class DrawShape : /*public QGraphicsObject*/public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit DrawShape(const QPen &pen = QPen(), const QBrush &brush = QBrush(), QGraphicsItem *parent = 0);
    virtual ~DrawShape();
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
