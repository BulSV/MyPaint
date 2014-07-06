#ifndef SIMPLETEXT_H
#define SIMPLETEXT_H

#include <QGraphicsTextItem>
#include <QFont>
#include "AbstractShape.h"

class SimpleText : public AbstractShape
{
    QGraphicsSimpleTextItem *itsTextItem;
public:
    explicit SimpleText(AbstractShape *parent = 0);
    explicit SimpleText(QString text, const QFont &font = QFont(), const QBrush &brush = QBrush(QColor(Qt::black)), AbstractShape *parent = 0);
    virtual ~SimpleText();
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void draw(qreal x1, qreal y1, qreal x2, qreal y2);
    void setFont(const QFont &font);
    QFont font() const;
    void setText(const QString &text);
    QString text() const;
    virtual void setBrush(const QBrush &brush);
};

#endif // SIMPLETEXT_H
