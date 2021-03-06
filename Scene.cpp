#include "Scene.h"

Scene::Scene(QObject *parent) :
    QGraphicsScene(parent)
{
}

Scene::~Scene()
{
}

void Scene::draw(AbstractShape *shape, qreal x1, qreal y1, qreal x2, qreal y2)
{
    shape->draw(x1, y1, x2, y2);
}

AbstractShape *Scene::currentShape()
{
    return (AbstractShape*)items().first();
}
