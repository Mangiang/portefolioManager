/********************************************************************************
** Form generated from reading UI file 'PortefolioManager.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PORTEFOLIOMANAGER_H
#define UI_PORTEFOLIOMANAGER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PortefolioManagerClass
{
public:
    QAction *actionRefresh;
    QAction *actionBold;
    QAction *actionItalic;
    QAction *actionUnderline;
    QAction *actionTogglePreview;
    QAction *actionToggleLog;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPlainTextEdit *contentPlainTextEdit;
    QMenuBar *menuBar;
    QMenu *menuPreview;
    QMenu *menuWindows;
    QToolBar *mainToolBar;
    QDockWidget *previewDockWidget;
    QWidget *previewDockSubWidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QWebEngineView *webEngineView;
    QStatusBar *statusBar;
    QDockWidget *logDockWidget;
    QWidget *logDockSubWidget;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_5;
    QPlainTextEdit *logPlainTextEdit;

    void setupUi(QMainWindow *PortefolioManagerClass)
    {
        if (PortefolioManagerClass->objectName().isEmpty())
            PortefolioManagerClass->setObjectName(QStringLiteral("PortefolioManagerClass"));
        PortefolioManagerClass->resize(1280, 1024);
        QIcon icon;
        icon.addFile(QStringLiteral(":/PortefolioManager/Resources/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        PortefolioManagerClass->setWindowIcon(icon);
        PortefolioManagerClass->setIconSize(QSize(16, 16));
        PortefolioManagerClass->setDockOptions(QMainWindow::AllowNestedDocks|QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks|QMainWindow::GroupedDragging);
        actionRefresh = new QAction(PortefolioManagerClass);
        actionRefresh->setObjectName(QStringLiteral("actionRefresh"));
        actionBold = new QAction(PortefolioManagerClass);
        actionBold->setObjectName(QStringLiteral("actionBold"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/PortefolioManager/Resources/images/bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBold->setIcon(icon1);
        actionItalic = new QAction(PortefolioManagerClass);
        actionItalic->setObjectName(QStringLiteral("actionItalic"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/PortefolioManager/Resources/images/italic.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionItalic->setIcon(icon2);
        actionUnderline = new QAction(PortefolioManagerClass);
        actionUnderline->setObjectName(QStringLiteral("actionUnderline"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/PortefolioManager/Resources/images/underline.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUnderline->setIcon(icon3);
        actionTogglePreview = new QAction(PortefolioManagerClass);
        actionTogglePreview->setObjectName(QStringLiteral("actionTogglePreview"));
        actionToggleLog = new QAction(PortefolioManagerClass);
        actionToggleLog->setObjectName(QStringLiteral("actionToggleLog"));
        centralWidget = new QWidget(PortefolioManagerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        contentPlainTextEdit = new QPlainTextEdit(centralWidget);
        contentPlainTextEdit->setObjectName(QStringLiteral("contentPlainTextEdit"));
        contentPlainTextEdit->setLineWrapMode(QPlainTextEdit::NoWrap);
        contentPlainTextEdit->setReadOnly(true);

        gridLayout->addWidget(contentPlainTextEdit, 0, 0, 1, 1);

        PortefolioManagerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PortefolioManagerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 18));
        menuPreview = new QMenu(menuBar);
        menuPreview->setObjectName(QStringLiteral("menuPreview"));
        menuWindows = new QMenu(menuBar);
        menuWindows->setObjectName(QStringLiteral("menuWindows"));
        PortefolioManagerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PortefolioManagerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setIconSize(QSize(16, 16));
        PortefolioManagerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        previewDockWidget = new QDockWidget(PortefolioManagerClass);
        previewDockWidget->setObjectName(QStringLiteral("previewDockWidget"));
        previewDockSubWidget = new QWidget();
        previewDockSubWidget->setObjectName(QStringLiteral("previewDockSubWidget"));
        gridLayout_3 = new QGridLayout(previewDockSubWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        webEngineView = new QWebEngineView(previewDockSubWidget);
        webEngineView->setObjectName(QStringLiteral("webEngineView"));
        webEngineView->setUrl(QUrl(QStringLiteral("about:blank")));

        gridLayout_2->addWidget(webEngineView, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        previewDockWidget->setWidget(previewDockSubWidget);
        PortefolioManagerClass->addDockWidget(static_cast<Qt::DockWidgetArea>(2), previewDockWidget);
        statusBar = new QStatusBar(PortefolioManagerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PortefolioManagerClass->setStatusBar(statusBar);
        logDockWidget = new QDockWidget(PortefolioManagerClass);
        logDockWidget->setObjectName(QStringLiteral("logDockWidget"));
        logDockSubWidget = new QWidget();
        logDockSubWidget->setObjectName(QStringLiteral("logDockSubWidget"));
        gridLayout_6 = new QGridLayout(logDockSubWidget);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        logPlainTextEdit = new QPlainTextEdit(logDockSubWidget);
        logPlainTextEdit->setObjectName(QStringLiteral("logPlainTextEdit"));
        logPlainTextEdit->setLineWrapMode(QPlainTextEdit::NoWrap);
        logPlainTextEdit->setReadOnly(true);

        gridLayout_5->addWidget(logPlainTextEdit, 0, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 2, 0, 1, 1);

        logDockWidget->setWidget(logDockSubWidget);
        PortefolioManagerClass->addDockWidget(static_cast<Qt::DockWidgetArea>(8), logDockWidget);

        menuBar->addAction(menuWindows->menuAction());
        menuBar->addAction(menuPreview->menuAction());
        menuPreview->addAction(actionRefresh);
        menuWindows->addAction(actionTogglePreview);
        menuWindows->addAction(actionToggleLog);
        mainToolBar->addAction(actionBold);
        mainToolBar->addAction(actionItalic);
        mainToolBar->addAction(actionUnderline);

        retranslateUi(PortefolioManagerClass);

        QMetaObject::connectSlotsByName(PortefolioManagerClass);
    } // setupUi

    void retranslateUi(QMainWindow *PortefolioManagerClass)
    {
        PortefolioManagerClass->setWindowTitle(QApplication::translate("PortefolioManagerClass", "PortefolioManager", nullptr));
        actionRefresh->setText(QApplication::translate("PortefolioManagerClass", "Refresh", nullptr));
#ifndef QT_NO_SHORTCUT
        actionRefresh->setShortcut(QApplication::translate("PortefolioManagerClass", "F5", nullptr));
#endif // QT_NO_SHORTCUT
        actionBold->setText(QApplication::translate("PortefolioManagerClass", "Bold", nullptr));
#ifndef QT_NO_SHORTCUT
        actionBold->setShortcut(QApplication::translate("PortefolioManagerClass", "Ctrl+B", nullptr));
#endif // QT_NO_SHORTCUT
        actionItalic->setText(QApplication::translate("PortefolioManagerClass", "Italic", nullptr));
#ifndef QT_NO_SHORTCUT
        actionItalic->setShortcut(QApplication::translate("PortefolioManagerClass", "Ctrl+I", nullptr));
#endif // QT_NO_SHORTCUT
        actionUnderline->setText(QApplication::translate("PortefolioManagerClass", "Underline", nullptr));
#ifndef QT_NO_SHORTCUT
        actionUnderline->setShortcut(QApplication::translate("PortefolioManagerClass", "Ctrl+U", nullptr));
#endif // QT_NO_SHORTCUT
        actionTogglePreview->setText(QApplication::translate("PortefolioManagerClass", "Toggle Preview", nullptr));
#ifndef QT_NO_TOOLTIP
        actionTogglePreview->setToolTip(QApplication::translate("PortefolioManagerClass", "Toggle Preview", nullptr));
#endif // QT_NO_TOOLTIP
        actionToggleLog->setText(QApplication::translate("PortefolioManagerClass", "Toggle Log", nullptr));
        menuPreview->setTitle(QApplication::translate("PortefolioManagerClass", "Preview", nullptr));
        menuWindows->setTitle(QApplication::translate("PortefolioManagerClass", "Windows", nullptr));
        previewDockWidget->setWindowTitle(QApplication::translate("PortefolioManagerClass", "Preview", nullptr));
        logDockWidget->setWindowTitle(QApplication::translate("PortefolioManagerClass", "Log", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PortefolioManagerClass: public Ui_PortefolioManagerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PORTEFOLIOMANAGER_H
