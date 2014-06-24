/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionAbout_Qt;
    QAction *actionShowDrawingTools;
    QAction *actionHideDrawingTools;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuView;
    QStatusBar *statusBar;
    QDockWidget *drawingTools;
    QWidget *dockWidgetContents_2;
    QVBoxLayout *verticalLayout;
    QPushButton *bDrawLine;
    QPushButton *bDrawRectangle;
    QPushButton *bDrawEllipse;
    QFrame *line;
    QPushButton *bDrawColor;
    QPushButton *bDrawWidth;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(531, 319);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName(QStringLiteral("actionAbout_Qt"));
        actionShowDrawingTools = new QAction(MainWindow);
        actionShowDrawingTools->setObjectName(QStringLiteral("actionShowDrawingTools"));
        actionHideDrawingTools = new QAction(MainWindow);
        actionHideDrawingTools->setObjectName(QStringLiteral("actionHideDrawingTools"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setCursor(QCursor(Qt::CrossCursor));
        tabWidget->setMouseTracking(false);
        tabWidget->setStyleSheet(QStringLiteral("QWidget { background-color: white; }"));
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(true);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        verticalLayout_2->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 531, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        drawingTools = new QDockWidget(MainWindow);
        drawingTools->setObjectName(QStringLiteral("drawingTools"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        verticalLayout = new QVBoxLayout(dockWidgetContents_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        bDrawLine = new QPushButton(dockWidgetContents_2);
        bDrawLine->setObjectName(QStringLiteral("bDrawLine"));

        verticalLayout->addWidget(bDrawLine);

        bDrawRectangle = new QPushButton(dockWidgetContents_2);
        bDrawRectangle->setObjectName(QStringLiteral("bDrawRectangle"));

        verticalLayout->addWidget(bDrawRectangle);

        bDrawEllipse = new QPushButton(dockWidgetContents_2);
        bDrawEllipse->setObjectName(QStringLiteral("bDrawEllipse"));

        verticalLayout->addWidget(bDrawEllipse);

        line = new QFrame(dockWidgetContents_2);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        bDrawColor = new QPushButton(dockWidgetContents_2);
        bDrawColor->setObjectName(QStringLiteral("bDrawColor"));

        verticalLayout->addWidget(bDrawColor);

        bDrawWidth = new QPushButton(dockWidgetContents_2);
        bDrawWidth->setObjectName(QStringLiteral("bDrawWidth"));

        verticalLayout->addWidget(bDrawWidth);

        verticalSpacer = new QSpacerItem(20, 52, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        drawingTools->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), drawingTools);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionAbout_Qt);
        menuView->addAction(actionShowDrawingTools);
        menuView->addAction(actionHideDrawingTools);

        retranslateUi(MainWindow);
        QObject::connect(actionShowDrawingTools, SIGNAL(triggered()), drawingTools, SLOT(show()));
        QObject::connect(actionHideDrawingTools, SIGNAL(triggered()), drawingTools, SLOT(hide()));
        QObject::connect(drawingTools, SIGNAL(visibilityChanged(bool)), actionShowDrawingTools, SLOT(setDisabled(bool)));
        QObject::connect(drawingTools, SIGNAL(visibilityChanged(bool)), actionHideDrawingTools, SLOT(setEnabled(bool)));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MyPaint", 0));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0));
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        actionAbout_Qt->setText(QApplication::translate("MainWindow", "About Qt", 0));
        actionShowDrawingTools->setText(QApplication::translate("MainWindow", "Show Drawing Tools", 0));
        actionHideDrawingTools->setText(QApplication::translate("MainWindow", "Hide Drawing Tools", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "New", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0));
#ifndef QT_NO_TOOLTIP
        drawingTools->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Drawing Tools</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        bDrawLine->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Draw Line</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        bDrawLine->setText(QApplication::translate("MainWindow", "Line", 0));
#ifndef QT_NO_TOOLTIP
        bDrawRectangle->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Draw Rectangle</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        bDrawRectangle->setText(QApplication::translate("MainWindow", "Rectangle", 0));
#ifndef QT_NO_TOOLTIP
        bDrawEllipse->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Draw Ellipse</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        bDrawEllipse->setText(QApplication::translate("MainWindow", "Ellipse", 0));
#ifndef QT_NO_TOOLTIP
        bDrawColor->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Set Pen Color</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        bDrawColor->setText(QApplication::translate("MainWindow", "Color", 0));
#ifndef QT_NO_TOOLTIP
        bDrawWidth->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Set Pen Width</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        bDrawWidth->setText(QApplication::translate("MainWindow", "Width", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
