#include "DrawText.h"

#include <QDebug>
#include <QFont>

qreal DrawText::getItsX() const
{
    return itsX;
}

void DrawText::setItsX(const qreal &value)
{
    itsX = value;
}

qreal DrawText::getItsY() const
{
    return itsY;
}

void DrawText::setItsY(const qreal &value)
{
    itsY = value;
}

DrawText::DrawText(DrawShape *parent):
    DrawShape()
  , itsText(new QGraphicsSimpleTextItem(parent))
  , itsX(0)
  , itsY(0)
{
    setVisible(false);
}

DrawText::DrawText(QString &text, DrawShape *parent) :
    DrawShape()
  , itsText(new QGraphicsSimpleTextItem(text, parent))
  , itsX(0)
  , itsY(0)
{
    setVisible(false);
}

DrawText::~DrawText()
{
    delete itsText;
    itsText = 0;
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
    itsText->setFlags(/*QGraphicsItem::ItemIsFocusable
                      | */QGraphicsItem::ItemIsMovable
                      /*| QGraphicsItem::ItemIsSelectable*/);

    itsText->setPos(x2 - getItsX(), y2 - getItsY());
//    itsText->setFont(QFont("Arial", 50, 3, true));
//    itsText->setBrush(QBrush(QColor(Qt::red)));

    setItsX(x2);
    setItsY(y2);

    if(!isVisible())
    {
        setVisible(true);
    }
}
