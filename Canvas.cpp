#include "Canvas.h"

#include <QDebug>

Canvas::Canvas(QGraphicsScene *parent) :
    QGraphicsScene(parent)
//  , itsPainter(new QList<QPainter*>)
  , itsStartX(0)
  , itsStartY(0)
  , itsEndX(0)
  , itsEndY(0)
//  , itsCurrentPainter(0)
{        
}

Canvas::Canvas(qreal x, qreal y, qreal width, qreal height, QGraphicsScene *parent) :
    QGraphicsScene(x, y, width, height, parent)
//  , itsPainter(new QList<QPainter*>)
  , itsStartX(0)
  , itsStartY(0)
  , itsEndX(0)
  , itsEndY(0)
//  , itsCurrentPainter(0)
{

}

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
    return addLine(0, 0, 250, 250, QPen(QBrush(QColor(Qt::red)), 10));
}

//void Canvas::setPainter(QPainter *painter)
//{
//    itsPainter = painter;
//}

void Canvas::mousePressEvent(QGraphicsSceneMouseEvent *pe)
{
    qDebug() << "void MainWindow::mousePressEvent(QMouseEvent *pe)";
    if(pe->buttons() & Qt::LeftButton)
    {
        itsStartX = pe->scenePos().toPoint().x();
        itsStartY = pe->scenePos().toPoint().y();

//        itsPainter->append(new QPainter());
//        ++itsCurrentPainter;
    }
}

void Canvas::mouseMoveEvent(QGraphicsSceneMouseEvent *pe)
{
    if(pe->buttons() & Qt::LeftButton)
    {
        itsEndX = pe->scenePos().toPoint().x();
        itsEndY = pe->scenePos().toPoint().y();

        update();

        emit painting(startX(), startY(), endX(), endY());
    }
}

void Canvas::mouseReleaseEvent(QGraphicsSceneMouseEvent *pe)
{
    qDebug() << "void MainWindow::mouseReleaseEvent(QMouseEvent *pe)";
    if(pe->buttons() & Qt::LeftButton)
    {
        itsEndX = pe->scenePos().toPoint().x();
        itsEndY = pe->scenePos().toPoint().y();
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
