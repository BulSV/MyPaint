#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QList>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsLineItem>

class Canvas : public QGraphicsView
{
    Q_OBJECT
public:
    explicit Canvas(QGraphicsView *parent = 0);
//    explicit Canvas(QGraphicsScene *scene, QGraphicsView *parent = 0);
    ~Canvas();
    int startX() const;
    int startY() const;
    int endX() const;
    int endY() const;
//    void setPainter(QPainter *painter);
    QGraphicsLineItem *addLineCanvas();
    void setSceneRect(qreal x, qreal y, qreal w, qreal h);
signals:
    void painting(int startX, int startY, int endX, int endY);
private:
    QList <QPainter*> *itsPainter;
    int itsStartX;
    int itsStartY;
    int itsEndX;
    int itsEndY;
    int itsCurrentPainter;
    QGraphicsScene *itsScene;
protected:
    void mousePressEvent(QMouseEvent *pe);
    void mouseMoveEvent(QMouseEvent *pe);
//    void mouseReleaseEvent(QMouseEvent *pe);
//    void paintEvent(QPaintEvent* pe);

};

#endif // CANVAS_H
