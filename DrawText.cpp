#include "DrawText.h"

#include <QDebug>
#include <QFont>
#include <QGraphicsScene>
#include "Scene.h"

DrawText::DrawText(DrawShape *parent):
    DrawShape(QPen(), QBrush(), parent)
  , itsText(new QGraphicsSimpleTextItem())
  , itsFont(QFont())
{
    setVisible(false);
    setBrush(QBrush(QColor(Qt::black)));
}

DrawText::DrawText(QString &text, const QFont &font, const QBrush &brush, DrawShape *parent) :
    DrawShape(QPen(), brush, parent)
  , itsText(new QGraphicsSimpleTextItem(text))
  , itsFont(font)
{
    setVisible(false);
    setBrush(brush);
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
    ((Scene*)scene())->currentShape()->setPos(x2, y2);
    itsText->setBrush(brush());
    itsText->setFlags(QGraphicsItem::ItemIsMovable);
    itsText->setFont(font());

    if(!isVisible())
    {
        setVisible(true);
    }
}

void DrawText::setFont(const QFont &font)
{
    itsFont = font;
}

QFont DrawText::font() const
{
    return itsFont;
}
