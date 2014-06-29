#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QList>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include "DrawShape.h"
#include "Scene.h"

class Canvas : public QGraphicsView
{
    Q_OBJECT
public:
    explicit Canvas(QGraphicsView *parent = 0);
    ~Canvas();
    int startX() const;
    int startY() const;
    int endX() const;
    int endY() const;
    void addShape(DrawShape *shape);
    void setSceneRect(qreal x, qreal y, qreal w, qreal h);
signals:
    void painting(int startX, int startY, int endX, int endY);
private:    
    int itsStartX;
    int itsStartY;
    int itsEndX;
    int itsEndY;
    int itsCurrentPainter;
    bool itsIsLeftButtonPressed;
    bool itsIsShapeSet;
    Scene *itsScene;
protected:
    void mousePressEvent(QMouseEvent *pe);
    void mouseMoveEvent(QMouseEvent *pe);
    void mouseReleaseEvent(QMouseEvent *pe);
};

#endif // CANVAS_H
