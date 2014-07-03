#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include "DrawShape.h"

class Scene : public QGraphicsScene
{
//    Q_OBJECT
public:
    explicit Scene(QObject *parent = 0);
    virtual ~Scene();
    void draw(DrawShape *shape, qreal x1, qreal y1, qreal x2,qreal y2);
    DrawShape *currentShape();
};

#endif // SCENE_H
