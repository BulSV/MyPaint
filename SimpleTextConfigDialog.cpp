#include "SimpleTextConfigDialog.h"

void SimpleTextConfigDialog::createWidget()
{
    QGridLayout *grid = new QGridLayout();
    grid->addWidget(lText, 0, 0);
    grid->addWidget(bColor, 0, 2);
    grid->addWidget(bFont, 1, 2);
    grid->addWidget(leText, 1, 0, 1, 2);
    grid->addWidget(bOk, 2, 0);
    grid->addWidget(bCancel, 2, 1);
    setLayout(grid);
    setModal(true);
}

void SimpleTextConfigDialog::setFont(const QFont &font)
{
    itsFont = font;
}

void SimpleTextConfigDialog::setColor(const QColor &color)
{
    itsColor = color;
}

void SimpleTextConfigDialog::selectFont()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont(), this, tr("Select Font"));
    if(ok)
    {
        setFont(font);
    }
}

void SimpleTextConfigDialog::selectColor()
{
    setColor( QColorDialog::getColor(QColor()));
}

void SimpleTextConfigDialog::accepted()
{
    if(!leText->text().isEmpty())
    {        
        setText(leText->text());
        close();
    }
}

void SimpleTextConfigDialog::connections()
{
    connect(bFont, SIGNAL(clicked()), this, SLOT(selectFont()));
    connect(bColor, SIGNAL(clicked()), this, SLOT(selectColor()));
    connect(bOk, SIGNAL(clicked()), this, SLOT(accepted()));
    connect(bCancel, SIGNAL(clicked()), this, SLOT(close()));
}

void SimpleTextConfigDialog::setText(const QString &text)
{
    itsText = text;
}

SimpleTextConfigDialog::SimpleTextConfigDialog(QWidget *parent) :
    QDialog(parent)//QWidget(parent)
  , lText(new QLabel(tr("Text"), this))
  , leText(new QLineEdit(this))
  , bColor(new QPushButton(tr("Color"), this))
  , bFont(new QPushButton(tr("Font"), this))
  , bOk(new QPushButton(tr("OK"), this))
  , bCancel(new QPushButton(tr("Cancel"), this))
  , itsText(QString())
  , itsFont(QFont())
{
    createWidget();

    show();

    connections();
}

QColor SimpleTextConfigDialog::color() const
{
    return itsColor;
}

QFont SimpleTextConfigDialog::font() const
{
    return itsFont;
}

QString SimpleTextConfigDialog::text() const
{
    return itsText;
}
