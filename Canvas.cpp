#include "Canvas.h"

#include <QDebug>

Canvas::Canvas(QGraphicsView *parent) :
    QGraphicsView(parent)
  , itsPainter(new QList<QPainter*>)
  , itsStartX(0)
  , itsStartY(0)
  , itsEndX(0)
  , itsEndY(0)
  , itsCurrentPainter(0)
  , itsIsLeftButtonPressed(false)
  , itsScene(new QGraphicsScene())
{
    this->setScene(itsScene);
//    this->setSceneRect(0, 0, 250, 250);
}

//Canvas::Canvas(QGraphicsScene *scene, QGraphicsView *parent) :
//    QGraphicsView(scene, parent)
////  , itsPainter(new QList<QPainter*>)
//  , itsStartX(0)
//  , itsStartY(0)
//  , itsEndX(0)
//  , itsEndY(0)
////  , itsCurrentPainter(0)
//  , itsScene(scene)
//{

//}

Canvas::~Canvas()
{
}

int Canvas::startX() const
{
    return itsStartX;
}

int Canvas::startY() const
{
    return itsStartY;
}

int Canvas::endX() const
{
    return itsEndX;
}

int Canvas::endY() const
{
    return itsEndY;
}

QGraphicsLineItem *Canvas::addLineCanvas()
{
//    return QGraphicsScene::addLine(startX(), startY(), endX(), endY(), QPen(QBrush(QColor(Qt::red)), 10.0));
//    return this->addEllipse(0.0, 0.0, 100.0, 50.0);
    //    return addLine(0, 0, 250, 250, QPen(QBrush(QColor(Qt::red)), 10));
}

void Canvas::setSceneRect(qreal x, qreal y, qreal w, qreal h)
{
    itsScene->setSceneRect(x, y, w, h);
    itsScene->addLine(0, 0, w, 0);
    itsScene->addLine(w, 0, w, h);
    itsScene->addLine(w, h, 0, h);
    itsScene->addLine(0, h, 0, 0);
    itsCurrentPainter = 4;
}

//void Canvas::setPainter(QPainter *painter)
//{
//    itsPainter = painter;
//}

void Canvas::mousePressEvent(QMouseEvent *pe)
{
    if(pe->buttons() & Qt::LeftButton)
    {
        qDebug() << "void MainWindow::mousePressEvent(QMouseEvent *pe)";
        QPointF point = mapToScene(pe->pos());
        itsStartX = point.x();
        itsStartY = point.y();
        itsIsLeftButtonPressed = true;

//        itsScene->addLine(startX(), startY(), endX(), endY());
//        itsScene->clear();

//        itsPainter->append(new QPainter());
//        ++itsCurrentPainter;
    }
}

void Canvas::mouseMoveEvent(QMouseEvent *pe)
{
    if(pe->buttons() & Qt::LeftButton)
    {
        QPointF point = mapToScene(pe->pos());
        itsEndX = point.x();
        itsEndY = point.y();

//        itsScene->clear();
//        itsScene->addLine(startX(), startY(), endX(), endY());
        if(itsScene->items().size() > itsCurrentPainter)
        {
            QGraphicsItem *gi = itsScene->items().first();
            itsScene->items().removeFirst();
            delete gi;
            gi = 0;
        }

        itsScene->addLine(startX(), startY(), endX(), endY());
        qDebug() << "Number of Items" << itsScene->items().size();

//        updateSceneRect(QRect(0,0,250,250));

        emit painting(startX(), startY(), endX(), endY());
    }
}

void Canvas::mouseReleaseEvent(QMouseEvent *pe)
{
    if(itsIsLeftButtonPressed)
    {
        qDebug() << "void MainWindow::mouseReleaseEvent(QMouseEvent *pe)";
        itsEndX = pe->x();
        itsEndY = pe->y();
        ++itsCurrentPainter;
        itsIsLeftButtonPressed = false;
//        itsScene->clear();

//        itsScene->addLine(startX(), startY(), endX(), endY());
//        update();
    }
}

//void Canvas::paintEvent(QPaintEvent *pe)
//{
////    if(itsCurrentPainter)
////    {
////        itsPainter->at(itsCurrentPainter - 1)->save();
////        itsPainter->at(itsCurrentPainter - 1)->begin(this);
////        itsPainter->at(itsCurrentPainter - 1)->setPen(QPen(Qt::black, 3));
////        itsPainter->at(itsCurrentPainter - 1)->drawLine(QPointF(itsStartX, itsStartY), QPointF(itsEndX, itsEndY));
////        itsPainter->at(itsCurrentPainter - 1)->end();
////        itsPainter->at(itsCurrentPainter - 1)->restore();
////    }
//}
