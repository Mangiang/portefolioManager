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
#include "LoggerPlainTextEdit.h"
#include "PreviewWebEngineView.h"

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
    QAction *actionNewProject;
    QAction *actionProjectSettings;
    QAction *actionSendContent;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPlainTextEdit *contentPlainTextEdit;
    QMenuBar *menuBar;
    QMenu *menuPreview;
    QMenu *menuWindows;
    QMenu *menuProject;
    QToolBar *mainToolBar;
    QDockWidget *previewDockWidget;
    QWidget *previewDockSubWidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    PreviewWebEngineView *webEngineView;
    QStatusBar *statusBar;
    QDockWidget *logDockWidget;
    QWidget *logDockSubWidget;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_5;
    LoggerPlainTextEdit *logPlainTextEdit;

    void setupUi(QMainWindow *PortefolioManagerClass)
    {
        if (PortefolioManagerClass->objectName().isEmpty())
            PortefolioManagerClass->setObjectName(QStringLiteral("PortefolioManagerClass"));
        PortefolioManagerClass->resize(1339, 1024);
        QIcon icon;
        icon.addFile(QStringLiteral(":/PortefolioManager/Resources/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        PortefolioManagerClass->setWindowIcon(icon);
        PortefolioManagerClass->setIconSize(QSize(16, 16));
        PortefolioManagerClass->setDockOptions(QMainWindow::AllowNestedDocks|QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks|QMainWindow::GroupedDragging);
        actionRefresh = new QAction(PortefolioManagerClass);
        actionRefresh->setObjectName(QStringLiteral("actionRefresh"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/PortefolioManager/Resources/images/circular-arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRefresh->setIcon(icon1);
        actionBold = new QAction(PortefolioManagerClass);
        actionBold->setObjectName(QStringLiteral("actionBold"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/PortefolioManager/Resources/images/bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBold->setIcon(icon2);
        actionItalic = new QAction(PortefolioManagerClass);
        actionItalic->setObjectName(QStringLiteral("actionItalic"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/PortefolioManager/Resources/images/italic.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionItalic->setIcon(icon3);
        actionUnderline = new QAction(PortefolioManagerClass);
        actionUnderline->setObjectName(QStringLiteral("actionUnderline"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/PortefolioManager/Resources/images/underline.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUnderline->setIcon(icon4);
        actionTogglePreview = new QAction(PortefolioManagerClass);
        actionTogglePreview->setObjectName(QStringLiteral("actionTogglePreview"));
        actionToggleLog = new QAction(PortefolioManagerClass);
        actionToggleLog->setObjectName(QStringLiteral("actionToggleLog"));
        actionNewProject = new QAction(PortefolioManagerClass);
        actionNewProject->setObjectName(QStringLiteral("actionNewProject"));
        actionProjectSettings = new QAction(PortefolioManagerClass);
        actionProjectSettings->setObjectName(QStringLiteral("actionProjectSettings"));
        actionSendContent = new QAction(PortefolioManagerClass);
        actionSendContent->setObjectName(QStringLiteral("actionSendContent"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/PortefolioManager/Resources/images/send.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSendContent->setIcon(icon5);
        centralWidget = new QWidget(PortefolioManagerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        contentPlainTextEdit = new QPlainTextEdit(centralWidget);
        contentPlainTextEdit->setObjectName(QStringLiteral("contentPlainTextEdit"));
        contentPlainTextEdit->setLineWrapMode(QPlainTextEdit::NoWrap);
        contentPlainTextEdit->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::TextEditable|Qt::TextEditorInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout->addWidget(contentPlainTextEdit, 0, 0, 1, 1);

        PortefolioManagerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PortefolioManagerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1339, 18));
        menuPreview = new QMenu(menuBar);
        menuPreview->setObjectName(QStringLiteral("menuPreview"));
        menuWindows = new QMenu(menuBar);
        menuWindows->setObjectName(QStringLiteral("menuWindows"));
        menuProject = new QMenu(menuBar);
        menuProject->setObjectName(QStringLiteral("menuProject"));
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
        webEngineView = new PreviewWebEngineView(previewDockSubWidget);
        webEngineView->setObjectName(QStringLiteral("webEngineView"));
        webEngineView->setProperty("url", QVariant(QUrl(QStringLiteral("about:blank"))));

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
        logPlainTextEdit = new LoggerPlainTextEdit(logDockSubWidget);
        logPlainTextEdit->setObjectName(QStringLiteral("logPlainTextEdit"));
        logPlainTextEdit->setReadOnly(true);

        gridLayout_5->addWidget(logPlainTextEdit, 0, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 2, 0, 1, 1);

        logDockWidget->setWidget(logDockSubWidget);
        PortefolioManagerClass->addDockWidget(static_cast<Qt::DockWidgetArea>(8), logDockWidget);

        menuBar->addAction(menuWindows->menuAction());
        menuBar->addAction(menuPreview->menuAction());
        menuBar->addAction(menuProject->menuAction());
        menuPreview->addAction(actionRefresh);
        menuPreview->addAction(actionSendContent);
        menuWindows->addAction(actionTogglePreview);
        menuWindows->addAction(actionToggleLog);
        menuProject->addAction(actionNewProject);
        menuProject->addAction(actionProjectSettings);
        mainToolBar->addAction(actionBold);
        mainToolBar->addAction(actionItalic);
        mainToolBar->addAction(actionUnderline);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionRefresh);
        mainToolBar->addAction(actionSendContent);

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
        actionNewProject->setText(QApplication::translate("PortefolioManagerClass", "New Project", nullptr));
        actionProjectSettings->setText(QApplication::translate("PortefolioManagerClass", "Project settings", nullptr));
        actionSendContent->setText(QApplication::translate("PortefolioManagerClass", "SendContent", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSendContent->setShortcut(QApplication::translate("PortefolioManagerClass", "F8", nullptr));
#endif // QT_NO_SHORTCUT
        menuPreview->setTitle(QApplication::translate("PortefolioManagerClass", "Preview", nullptr));
        menuWindows->setTitle(QApplication::translate("PortefolioManagerClass", "Windows", nullptr));
        menuProject->setTitle(QApplication::translate("PortefolioManagerClass", "Project", nullptr));
        previewDockWidget->setWindowTitle(QApplication::translate("PortefolioManagerClass", "Preview", nullptr));
        logDockWidget->setWindowTitle(QApplication::translate("PortefolioManagerClass", "Log", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PortefolioManagerClass: public Ui_PortefolioManagerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PORTEFOLIOMANAGER_H
