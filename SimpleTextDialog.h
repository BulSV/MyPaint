#ifndef SIMPLETEXTDIALOG_H
#define SIMPLETEXTDIALOG_H

#include "SimpleText.h"
#include "SimpleTextConfigDialog.h"

class SimpleTextDialog : public SimpleText
{    
    SimpleTextConfigDialog *simpleTextConfigDialog;
public:
    explicit SimpleTextDialog(SimpleText *parent = 0);
    virtual ~SimpleTextDialog();
    virtual void draw(qreal x1, qreal y1, qreal x2, qreal y2);
signals:

public slots:

};

#endif // SIMPLETEXTDIALOG_H
