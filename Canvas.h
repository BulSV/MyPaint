#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>

class Canvas : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = 0);
    ~Canvas();
    int startX() const;
    int startY() const;
    int endX() const;
    int endY() const;
signals:
    void painting(int startX, int startY, int endX, int endY);
private:
    QPainter *p;
    int itsStartX;
    int itsStartY;
    int itsEndX;
    int itsEndY;
protected:
    virtual void mousePressEvent(QMouseEvent* pe);
    virtual void mouseMoveEvent(QMouseEvent* pe);
    virtual void mouseReleaseEvent(QMouseEvent* pe);
    virtual void paintEvent(QPaintEvent* pe);

};

#endif // CANVAS_H
