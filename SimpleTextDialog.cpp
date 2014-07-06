#include "SimpleTextDialog.h"
#include "Scene.h"

#include <QDebug>

SimpleTextDialog::SimpleTextDialog(SimpleText *parent) :
    SimpleText(parent)
{
    setFlags(QGraphicsItem::ItemIsMovable);
    simpleTextConfigDialog = new SimpleTextConfigDialog();
    simpleTextConfigDialog->show();    
}

SimpleTextDialog::~SimpleTextDialog()
{
    delete simpleTextConfigDialog;
    simpleTextConfigDialog = 0;
}

void SimpleTextDialog::draw(qreal x1, qreal y1, qreal x2, qreal y2)
{
    ((Scene*)scene())->currentShape()->setPos(x2, y2);
    setText(simpleTextConfigDialog->text());
    setBrush(QBrush(simpleTextConfigDialog->color()));
    setFont(simpleTextConfigDialog->font());

    qDebug() << "text:"<< text();
    qDebug() << "color:" << brush();
    qDebug() << "font:" << font();

    if(!isVisible())
    {
        setVisible(true);
    }
}
