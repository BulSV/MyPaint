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
#include "AbstractShape.h"
#include "Scene.h"
#include "CanvasObserver.h"

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
    void addShape(AbstractShape *shape);
    void addBackgroundShape(AbstractShape *backgroundShape);
    void setSceneRect(qreal x, qreal y, qreal w, qreal h);
    AbstractShape *currentShape();
    void setColor(QColor color);
    QColor color() const;
    void setWidth(int width);
    int width() const;
    void clear();
    QRectF drawRect() const;
    void registerObserver(CanvasObserver *canvasObserver);
    void removeObserver(CanvasObserver *canvasObserver);
signals:
    void painting(int startX, int startY, int endX, int endY);
private:
    int itsStartX;
    int itsStartY;
    int itsEndX;
    int itsEndY;
    bool itsIsLeftButtonPressed;
    bool itsIsShapeSet;
    bool itsIsShapeDrawn;
    Scene *itsScene;
    QPen itsPen;

    QList<CanvasObserver*> itsCanvasObservers;

    void notifyObservers();
protected:
    void mousePressEvent(QMouseEvent *pe);
    void mouseMoveEvent(QMouseEvent *pe);
    void mouseReleaseEvent(QMouseEvent *pe);
};

#endif // CANVAS_H
