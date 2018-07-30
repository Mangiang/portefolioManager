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
    QAction *actionToggle_Preview;
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

    void setupUi(QMainWindow *PortefolioManagerClass)
    {
        if (PortefolioManagerClass->objectName().isEmpty())
            PortefolioManagerClass->setObjectName(QStringLiteral("PortefolioManagerClass"));
        PortefolioManagerClass->resize(973, 477);
        QIcon icon;
        icon.addFile(QStringLiteral(":/PortefolioManager/Resources/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        PortefolioManagerClass->setWindowIcon(icon);
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
        actionToggle_Preview = new QAction(PortefolioManagerClass);
        actionToggle_Preview->setObjectName(QStringLiteral("actionToggle_Preview"));
        centralWidget = new QWidget(PortefolioManagerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        contentPlainTextEdit = new QPlainTextEdit(centralWidget);
        contentPlainTextEdit->setObjectName(QStringLiteral("contentPlainTextEdit"));

        gridLayout->addWidget(contentPlainTextEdit, 0, 0, 1, 1);

        PortefolioManagerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PortefolioManagerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 973, 18));
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

        menuBar->addAction(menuWindows->menuAction());
        menuBar->addAction(menuPreview->menuAction());
        menuPreview->addAction(actionRefresh);
        menuWindows->addAction(actionToggle_Preview);
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
        actionToggle_Preview->setText(QApplication::translate("PortefolioManagerClass", "Toggle Preview", nullptr));
#ifndef QT_NO_TOOLTIP
        actionToggle_Preview->setToolTip(QApplication::translate("PortefolioManagerClass", "Toggle Preview", nullptr));
#endif // QT_NO_TOOLTIP
        menuPreview->setTitle(QApplication::translate("PortefolioManagerClass", "Preview", nullptr));
        menuWindows->setTitle(QApplication::translate("PortefolioManagerClass", "Windows", nullptr));
        previewDockWidget->setWindowTitle(QApplication::translate("PortefolioManagerClass", "Preview", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PortefolioManagerClass: public Ui_PortefolioManagerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PORTEFOLIOMANAGER_H
