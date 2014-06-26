#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QList>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsLineItem>

class Canvas : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Canvas(QGraphicsScene *parent = 0);
    explicit Canvas(qreal x, qreal y, qreal width, qreal height, QGraphicsScene *parent = 0);
    ~Canvas();
    int startX() const;
    int startY() const;
    int endX() const;
    int endY() const;
//    void setPainter(QPainter *painter);
    QGraphicsLineItem *addLineCanvas();
signals:
    void painting(int startX, int startY, int endX, int endY);
private:
//    QList <QPainter*> *itsPainter;
    int itsStartX;
    int itsStartY;
    int itsEndX;
    int itsEndY;
//    int itsCurrentPainter;
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *pe);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *pe);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *pe);
//    virtual void paintEvent(QPaintEvent* pe);

};

#endif // CANVAS_H
