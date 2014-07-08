#include "SimpleText.h"

#include <QDebug>
#include <QFont>
#include <QGraphicsScene>
#include "Scene.h"

SimpleText::SimpleText(AbstractShape *parent):
    AbstractShape(QPen(), QBrush(), parent)
  , itsTextItem(new QGraphicsSimpleTextItem())
{
    setVisible(false);
    setBrush(QBrush(QColor(Qt::black)));
    setFont(QFont());
}

SimpleText::SimpleText(QString text, const QFont &font, const QBrush &brush, AbstractShape *parent) :
    AbstractShape(QPen(), brush, parent)
  , itsTextItem(new QGraphicsSimpleTextItem(text))
{
    setVisible(false);
    setBrush(brush);
    setFont(font);
}

SimpleText::~SimpleText()
{
    delete itsTextItem;
    itsTextItem = 0;
}

QRectF SimpleText::boundingRect() const
{
    return itsTextItem->boundingRect();
}

void SimpleText::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    itsTextItem->paint(painter, option, widget);
}

void SimpleText::draw(qreal x1, qreal y1, qreal x2, qreal y2)
{
    ((Scene*)scene())->currentShape()->setPos(x2, y2);
    itsTextItem->setBrush(brush());
    itsTextItem->setFlags(QGraphicsItem::ItemIsMovable);
    itsTextItem->setFont(font());

    if(!isVisible())
    {
        setVisible(true);
    }
}

void SimpleText::setFont(const QFont &font)
{
    itsTextItem->setFont(font);
}

QFont SimpleText::font() const
{
    return itsTextItem->font();
}

void SimpleText::setText(const QString &text)
{
    itsTextItem->setText(text);
}

QString SimpleText::text() const
{
    return itsTextItem->text();
}

void SimpleText::setBrush(const QBrush &brush)
{
    itsTextItem->setBrush(brush);
}
