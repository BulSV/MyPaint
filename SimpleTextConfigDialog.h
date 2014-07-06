#ifndef SIMPLETEXTCONFIGDIALOG_H
#define SIMPLETEXTCONFIGDIALOG_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QFontDialog>
#include <QColorDialog>
#include <QGridLayout>

class SimpleTextConfigDialog : public QWidget
{
    Q_OBJECT
    QLabel *lText;
    QLineEdit *leText;    
    QPushButton *bColor;
    QPushButton *bFont;
    QPushButton *bOk;
    QPushButton *bCancel;

    QString itsText;
    QFont itsFont;
    QColor itsColor;

    void createWidget();
    void connections();
    void setText(const QString &text);
    void setFont(const QFont &font);
    void setColor(const QColor &color);
private slots:
    void selectFont();
    void selectColor();
    void accepted();
public:
    explicit SimpleTextConfigDialog(QWidget *parent = 0);
    QColor color() const;
    QFont font() const;
    QString text() const;
signals:

public slots:

};

#endif // SIMPLETEXTCONFIGDIALOG_H
