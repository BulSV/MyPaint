#ifndef DRAWSHAPE_H
#define DRAWSHAPE_H

#include <QGraphicsScene>
#include <QGraphicsItem>

class DrawShape : public QGraphicsScene
{
    Q_OBJECT
public:
//    explicit DrawShape(QObject *parent = 0);
    virtual ~DrawShape();
    virtual QGraphicsItem *draw(qreal x1, qreal y1, qreal x2, qreal y2, const QPen & pen = QPen()) = 0;
};

#endif // DRAWSHAPE_H
