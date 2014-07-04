#ifndef DRAWTEXT_H
#define DRAWTEXT_H

#include <QGraphicsTextItem>
#include <QFont>
#include "DrawShape.h"

class DrawText : public DrawShape
{
    QGraphicsSimpleTextItem *itsText;
    QFont itsFont;
public:
    explicit DrawText(DrawShape *parent = 0);
    explicit DrawText(QString &text, const QPen &pen = QPen(), const QBrush &brush = QBrush(), DrawShape *parent = 0);
    virtual ~DrawText();
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void draw(qreal x1, qreal y1, qreal x2, qreal y2);
    void setFont(const QFont &font);
    QFont font() const;
};

#endif // DRAWTEXT_H
