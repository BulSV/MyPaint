#include "DrawText.h"

DrawText::DrawText(DrawShape *parent):
    DrawShape()
  , itsText(new QGraphicsSimpleTextItem(parent))
{
}

DrawText::DrawText(QString &text, DrawShape *parent) :
    DrawShape()
  , itsText(new QGraphicsSimpleTextItem(text, parent))
{
}

DrawText::~DrawText()
{
}

QRectF DrawText::boundingRect() const
{
    return itsText->boundingRect();
}

void DrawText::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    itsText->paint(painter, option, widget);
}

void DrawText::draw(qreal x1, qreal y1, qreal x2, qreal y2)
{
    itsText->setPen(pen());
    itsText->setFlags(QGraphicsItem::ItemIsFocusable
                      | QGraphicsItem::ItemIsMovable
                      | QGraphicsItem::ItemIsSelectable);
    itsText->setFocus();
    itsText->setRotation(45);
    itsText->setTransformOriginPoint(x2, y2);
}

void DrawText::mousePressEvent(QGraphicsSceneMouseEvent *pe)
{

}

void DrawText::mouseMoveEvent(QGraphicsSceneMouseEvent *pe)
{

}

void DrawText::mouseReleaseEvent(QGraphicsSceneMouseEvent *pe)
{

}
