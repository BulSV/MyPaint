#include "Canvas.h"

#include <QDebug>

Canvas::Canvas(QGraphicsView *parent) :
    QGraphicsView(parent)
//  , itsPainter(new QList<QPainter*>)
  , itsStartX(0)
  , itsStartY(0)
  , itsEndX(0)
  , itsEndY(0)
//  , itsCurrentPainter(0)
  , itsScene(new QGraphicsScene())
{        
    this->setScene(itsScene);
    this->setSceneRect(0, 0, 250, 250);
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

//void Canvas::setPainter(QPainter *painter)
//{
//    itsPainter = painter;
//}

void Canvas::mousePressEvent(QMouseEvent *pe)
{
    qDebug() << "void MainWindow::mousePressEvent(QMouseEvent *pe)";
    if(pe->buttons() & Qt::LeftButton)
    {
        itsStartX = pe->x();
        itsStartY = pe->y();

        itsScene->addLine(startX(), startY(), endX(), endY());

//        itsPainter->append(new QPainter());
//        ++itsCurrentPainter;
    }
}

void Canvas::mouseMoveEvent(QMouseEvent *pe)
{
    if(pe->buttons() & Qt::LeftButton)
    {
        itsEndX = pe->x();
        itsEndY = pe->y();

        itsScene->addLine(startX(), startY(), endX(), endY());

        update();

        emit painting(startX(), startY(), endX(), endY());
    }
}

void Canvas::mouseReleaseEvent(QMouseEvent *pe)
{
    qDebug() << "void MainWindow::mouseReleaseEvent(QMouseEvent *pe)";
    if(pe->buttons() & Qt::LeftButton)
    {
        itsEndX = pe->x();
        itsEndY = pe->y();

        itsScene->addLine(startX(), startY(), endX(), endY());
    }
}

//void Canvas::paintEvent(QPaintEvent *)
//{
//    if(itsCurrentPainter)
//    {
//        itsPainter->at(itsCurrentPainter - 1)->begin(this);
//        itsPainter->at(itsCurrentPainter - 1)->setPen(QPen(Qt::black, 3));
//        itsPainter->at(itsCurrentPainter - 1)->drawLine(QPointF(itsStartX, itsStartY), QPointF(itsEndX, itsEndY));
//        itsPainter->at(itsCurrentPainter - 1)->end();
//    }
//}
