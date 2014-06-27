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
    //    Canvas *canvas = new Canvas();
    //    QScrollArea *scroll = new QScrollArea();
    //    ui->tabWidget->addTab(scroll, "New");
    //    scroll->addScrollBarWidget(canvas, Qt::AlignLeft);
    //    scroll->adjustSize();
    //    ui->tabWidget->addTab(canvas, "New");

    //    QGraphicsView *view = new QGraphicsView();
    //    QGraphicsScene *scene = new QGraphicsScene();
    //    scene->setSceneRect(0, 0, 1000, 1000);
    //    view->setScene(scene);
    //    ui->tabWidget->addTab(view, "New");
    //    scene->addEllipse(0, 0, 100, 30);
    //    scene->addLine(0, 0, 360, 360);
    //    scene->addRect(0, 0, 120, 40);

//    canvas = new Canvas();

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
    //    QGraphicsScene *scene = new QGraphicsScene();
    //    scene->setSceneRect(0, 0, 1000, 1000);
    //    view->setScene(scene);
    //    QInputDialog::getText(this, tr("Enter Name"),
    //                            tr("User name:"), QLineEdit::Normal,
    //                            "");

//    QGraphicsView *view = new QGraphicsView();
    Canvas *canvas = new Canvas();
//    view->setScene(canvas);

    bool nameOK;
    QString imageName = QInputDialog::getText(this, tr("Enter Name"),
                                              tr("Image name:"), QLineEdit::Normal,
                                              "", &nameOK);

    QPoint imageSizePx;
    imageSizePx.setX(QInputDialog::getInt(this, tr("Enter Width"), tr("Image Width Size, px")));
    imageSizePx.setY(QInputDialog::getInt(this, tr("Enter Height"), tr("Image Height Size, px")));


    if(nameOK && !imageName.isEmpty())
    {
        ui->tabWidget->addTab(canvas, imageName);
    }
    else
    {
        ui->tabWidget->addTab(canvas, tr("untitled"));
    }
    if(imageSizePx.x() && imageSizePx.y())
    {
        canvas->setSceneRect(0, 0, imageSizePx.x(), imageSizePx.y());

//        canvas->QGraphicsScene::addLine(0, 0, imageSizePx.x(), 0);
//        canvas->QGraphicsScene::addLine(imageSizePx.x(), 0, imageSizePx.x(), imageSizePx.y());
//        canvas->QGraphicsScene::addLine(imageSizePx.x(), imageSizePx.y(), 0, imageSizePx.y());
//        canvas->QGraphicsScene::addLine(0, imageSizePx.y(), 0, 0);
    }
    else
    {
        canvas->setSceneRect(0, 0, 250, 250);

//        canvas->QGraphicsScene::addLine(0, 0, 250, 0);
//        canvas->QGraphicsScene::addLine(250, 0, 250, 250);
//        canvas->QGraphicsScene::addLine(250, 250, 0, 250);
//        canvas->QGraphicsScene::addLine(0, 250, 0, 0);
    }
    canvas->setBackgroundBrush(QBrush(QColor(255, 255, 255)));


//    QPoint imageSizePx = QInputDialog::get



    //    scene->addEllipse(0, 0, 100, 30);
    //    scene->addLine(0, 0, 360, 360);
    //    scene->addRect(0, 0, 120, 40);
}


void MainWindow::on_bDrawLine_clicked()
{
    ((Canvas*)ui->tabWidget->currentWidget())->addShape(new DrawLine());
}
