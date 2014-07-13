#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>
#include <QInputDialog>
#include <QSignalMapper>

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

    currentDirOpen = "";
    currentDirSave = "";

    lastDrawnShapeType = NoShapeType;

    buttonsCheckStates.append(ui->bDrawLine);
    buttonsCheckStates.append(ui->bDrawRectangle);
    buttonsCheckStates.append(ui->bDrawEllipse);
    buttonsCheckStates.append(ui->bDrawText);
    buttonsCheckStates.append(ui->bRubber);

    ui->statusBar->addWidget(lStartX);
    ui->statusBar->addWidget(lStartY);
    ui->statusBar->addWidget(frmXYLineSeparator);
    ui->statusBar->addWidget(lEndX);
    ui->statusBar->addWidget(lEndY);

    ui->tabWidget->removeTab(0);
    ui->tabWidget->removeTab(0);

    connect(ui->actionAbout_Qt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete lStartX;
    delete lStartY;
    delete lEndX;
    delete lEndY;
    delete frmXYLineSeparator;
}

void MainWindow::drawSameShapeType()
{
    AbstractShape *lastDrawnShape = this->lastDrawnShape();
    if(lastDrawnShape)
    {
        ((Canvas*)ui->tabWidget->currentWidget())->addShape(lastDrawnShape);
    }
    lastDrawnShape = 0;
}

AbstractShape *MainWindow::lastDrawnShape()
{
    switch(lastDrawnShapeType)
    {
    case LineType: return new Line();
        break;
    case RectangleType: return new Rectangle();
        break;
    case EllipseType: return new Ellipse();
        break;
    case SimpleTextType: return new SimpleTextDialog();
        break;
    case RubberType: return new Rubber(((Canvas*)ui->tabWidget->currentWidget())->scene());
        break;
    default: return 0;
        break;
    }
}

void MainWindow::checkSwitcher(QPushButton *checkButton)
{
    for(int i = 0; i < buttonsCheckStates.size(); ++i)
    {
        if(buttonsCheckStates.indexOf(checkButton) != i
                && buttonsCheckStates.at(i)->isChecked())
        {
            buttonsCheckStates.at(i)->setChecked(false);
        }
    }
}

void MainWindow::setStartXY_EndXY(int startX, int startY, int endX, int endY)
{
    // current coordinates
    lStartX->setText(tr("X = ") + QString::number(endX));
    lStartY->setText(tr("Y = ") + QString::number(endY));
    // offset coordinates
    lEndX->setText(tr("dX = ") + QString::number(endX - startX));
    lEndY->setText(tr("dY = ") + QString::number(endY - startY));
}

void MainWindow::newImage()
{
    Canvas *canvas = new Canvas();
    canvas->registerObserver(this);

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

    connect((Canvas*)ui->tabWidget->currentWidget(), SIGNAL(painting(int,int,int,int)), this, SLOT(setStartXY_EndXY(int,int,int,int)));
}


void MainWindow::on_bDrawLine_pressed()
{
    checkSwitcher(ui->bDrawLine);

    if(ui->tabWidget->currentWidget())
    {
        lastDrawnShapeType = LineType;
        ((Canvas*)ui->tabWidget->currentWidget())->addShape(lastDrawnShape());
    }
}

void MainWindow::on_bDrawRectangle_pressed()
{
    checkSwitcher(ui->bDrawRectangle);

    if(ui->tabWidget->currentWidget())
    {
        lastDrawnShapeType = RectangleType;
        ((Canvas*)ui->tabWidget->currentWidget())->addShape(lastDrawnShape());
    }
}

void MainWindow::on_bDrawEllipse_pressed()
{
    checkSwitcher(ui->bDrawEllipse);

    if(ui->tabWidget->currentWidget())
    {
        lastDrawnShapeType = EllipseType;
        ((Canvas*)ui->tabWidget->currentWidget())->addShape(lastDrawnShape());
    }
}

void MainWindow::on_bDrawText_pressed()
{
    // because SimpleTextConfigDialog interrupts pressing
    ui->bDrawText->setChecked(true);

    checkSwitcher(ui->bDrawText);

    if(ui->tabWidget->currentWidget())
    {
        lastDrawnShapeType = SimpleTextType;
        ((Canvas*)ui->tabWidget->currentWidget())->addShape(lastDrawnShape());
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
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Dialog"), currentDirOpen, tr("Images (*.bmp *.jpg *.png)"));
    QPixmap pixmap(fileName);
    if(!fileName.isEmpty())
    {
        QStringList list = fileName.split("/");
        for(int i = 0; i < list.size() - 1; ++i)
        {
            currentDirOpen += list.at(i) + "/";
        }
        if(!ui->tabWidget->currentWidget())
        {
            Canvas *canvas = new Canvas();
            canvas->registerObserver(this);
            ui->tabWidget->addTab(canvas, list.at(list.size() - 1));
        }
        else
        {
            ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), list.at(list.size() - 1));
        }
        ((Canvas*)ui->tabWidget->currentWidget())->clear();
        ((Canvas*)ui->tabWidget->currentWidget())->setSceneRect(0, 0, pixmap.size().width(), pixmap.size().height());
        ((Canvas*)ui->tabWidget->currentWidget())->addBackgroundShape(new Pixmap(pixmap));
    }
}

void MainWindow::save()
{
    QRect currentRect = ((Canvas*)ui->tabWidget->currentWidget())->viewport()->rect();
    ((Canvas*)ui->tabWidget->currentWidget())->adjustSize();

    QRect rect = ((Canvas*)ui->tabWidget->currentWidget())->drawRect().toRect();

    QPixmap pixmap(rect.width(), rect.height());

    QPainter painter(&pixmap);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    ((Canvas*)ui->tabWidget->currentWidget())->render(&painter, rect, rect);
    painter.end();

    ((Canvas*)ui->tabWidget->currentWidget())->resize(currentRect.width(), currentRect.height());

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Dialog"), currentDirSave, tr("Images (*.bmp *.jpg *.png)"));
    if(!fileName.isEmpty())
    {
        QStringList list = fileName.split("/");
        for(int i = 0; i < list.size() - 1; ++i)
        {
            currentDirSave += list.at(i) + "/";
        }

        QStringList listFormat = fileName.split(".");
        const char *format = listFormat.at(listFormat.size() - 1).toStdString().c_str();

        QString saveName;
        for(int i = 0; i < listFormat.size() - 1; ++i)
        {
            saveName += listFormat.at(i);
        }

        pixmap.save(fileName, format);
        ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), list.at(list.size() - 1));
    }
}

void MainWindow::closeTab(int tabIndex)
{
    ui->tabWidget->removeTab(tabIndex);
}

void MainWindow::closeTab()
{
    closeTab(ui->tabWidget->currentIndex());
}

void MainWindow::on_bRubber_pressed()
{
    checkSwitcher(ui->bRubber);

    if(ui->tabWidget->currentWidget())
    {
        lastDrawnShapeType = RubberType;
        ((Canvas*)ui->tabWidget->currentWidget())->addShape(lastDrawnShape());
    }
}
