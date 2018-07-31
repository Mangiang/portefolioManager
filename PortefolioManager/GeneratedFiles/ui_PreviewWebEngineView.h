/********************************************************************************
** Form generated from reading UI file 'PreviewWebEngineView.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREVIEWWEBENGINEVIEW_H
#define UI_PREVIEWWEBENGINEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <qwebengineview.h>

QT_BEGIN_NAMESPACE

class Ui_PreviewWebEngineView
{
public:

    void setupUi(QWebEngineView *PreviewWebEngineView)
    {
        if (PreviewWebEngineView->objectName().isEmpty())
            PreviewWebEngineView->setObjectName(QStringLiteral("PreviewWebEngineView"));
        PreviewWebEngineView->resize(400, 300);

        retranslateUi(PreviewWebEngineView);

        QMetaObject::connectSlotsByName(PreviewWebEngineView);
    } // setupUi

    void retranslateUi(QWebEngineView *PreviewWebEngineView)
    {
        PreviewWebEngineView->setWindowTitle(QApplication::translate("PreviewWebEngineView", "PreviewWebEngineView", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PreviewWebEngineView: public Ui_PreviewWebEngineView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREVIEWWEBENGINEVIEW_H
