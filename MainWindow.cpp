#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    lStartX = new QLabel(this);
    lStartY = new QLabel(this);
    lEndX = new QLabel(this);
    lEndY = new QLabel(this);

    frmXYLineSeparator = new QFrame(this);

    frmXYLineSeparator->setFrameShape(QFrame::VLine);

    ui->statusBar->addWidget(lStartX);
    ui->statusBar->addWidget(lStartY);
    ui->statusBar->addWidget(frmXYLineSeparator);
    ui->statusBar->addWidget(lEndX);
    ui->statusBar->addWidget(lEndY);

    ui->tabWidget->removeTab(0);
    ui->tabWidget->removeTab(0);

    connect(ui->actionAbout_Qt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    connect((Canvas*)ui->tabWidget->currentWidget(), SIGNAL(painting(int,int,int,int)), this, SLOT(setStartXY_EndXY(int,int,int,int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setStartXY_EndXY(int startX, int startY, int endX, int endY)
{
    lStartX->setText(tr("X = ") + QString::number(startX));
    lStartY->setText(tr("Y = ") + QString::number(startY));
    lEndX->setText(tr("X = ") + QString::number(endX));
    lEndY->setText(tr("Y = ") + QString::number(endY));
}

void MainWindow::newImage()
{
    Canvas *canvas = new Canvas();

    bool nameOK;
    QString imageName = QInputDialog::getText(this, tr("Enter Name"),
                                              tr("Image name:"), QLineEdit::Normal,
                                              "", &nameOK);

    if(nameOK)
    {
        if(!imageName.isEmpty())
        {
            ui->tabWidget->addTab(canvas, imageName);
        }
        else
        {
            ui->tabWidget->addTab(canvas, tr("untitled"));
        }
    }
    else
    {
        return;
    }

    QPoint imageSizePx;
    imageSizePx.setX(QInputDialog::getInt(this, tr("Enter Width"), tr("Image Width Size, px")));
    imageSizePx.setY(QInputDialog::getInt(this, tr("Enter Height"), tr("Image Height Size, px")));

    if(imageSizePx.x() && imageSizePx.y())
    {
        canvas->setSceneRect(0, 0, imageSizePx.x(), imageSizePx.y());
    }
    else
    {
        canvas->setSceneRect(0, 0, 250, 250);
    }
    canvas->setBackgroundBrush(QBrush(QColor(255, 255, 255)));
}


void MainWindow::on_bDrawLine_clicked()
{
    if(ui->tabWidget->currentWidget())
    {
        ((Canvas*)ui->tabWidget->currentWidget())->addShape(new DrawLine());
    }
}

void MainWindow::on_bDrawRectangle_clicked()
{
    if(ui->tabWidget->currentWidget())
    {
        ((Canvas*)ui->tabWidget->currentWidget())->addShape(new DrawRectangle());
    }
}

void MainWindow::on_bDrawEllipse_clicked()
{
    if(ui->tabWidget->currentWidget())
    {
        ((Canvas*)ui->tabWidget->currentWidget())->addShape(new DrawEllipse());
    }
}

void MainWindow::on_bDrawText_clicked()
{
    if(ui->tabWidget->currentWidget())
    {
        bool nameOK;
        QString text = QInputDialog::getText(this, tr("Enter Text"),
                                             tr("Text:"), QLineEdit::Normal,
                                             "", &nameOK);
        if(nameOK)
        {
            ((Canvas*)ui->tabWidget->currentWidget())->addShape(new DrawText(text));
        }
    }
}

void MainWindow::on_bPenColor_clicked()
{
    if(ui->tabWidget->currentWidget())
    {
        QColor color(QColorDialog::getColor(((Canvas*)ui->tabWidget->currentWidget())->color()));

        ((Canvas*)ui->tabWidget->currentWidget())->setColor(color);
    }
}

void MainWindow::on_bPenWidth_clicked()
{
    if(ui->tabWidget->currentWidget())
    {
        int width(QInputDialog::getInt(this, tr("Enter Pen Width"), tr("Pen Width, px")));
        ((Canvas*)ui->tabWidget->currentWidget())->setWidth(width);
    }
}

void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.bmp *.jpg *.png");
    QPixmap pixmap(fileName);
    if(!fileName.isEmpty())
    {
        if(!ui->tabWidget->currentWidget())
        {
            Canvas *canvas = new Canvas();
            QStringList list = fileName.split("/");
            ui->tabWidget->addTab(canvas, list.at(list.size() - 1));
        }
        ((Canvas*)ui->tabWidget->currentWidget())->clear();
        ((Canvas*)ui->tabWidget->currentWidget())->addShape(new DrawPixmap(pixmap));
    }
}

void MainWindow::save()
{
    QRect rect = ((Canvas*)ui->tabWidget->currentWidget())->viewport()->rect();
    QPixmap pixmap(rect.width(), rect.height());
    QPainter painter(&pixmap);
    ((Canvas*)ui->tabWidget->currentWidget())->render(&painter, rect, rect, Qt::IgnoreAspectRatio);
    painter.end();

    QString fileName = QFileDialog::getSaveFileName(0, "Save Dialog", "", "*.bmp *.jpg *.png");
    QStringList list = fileName.split(".");
    const char *format = list.at(list.size() - 1).toStdString().c_str();

    QString saveName;
    for(int i = 0; i < list.size() - 1; ++i)
    {
        saveName += list.at(i);
    }

    pixmap.save(fileName, format);
}
