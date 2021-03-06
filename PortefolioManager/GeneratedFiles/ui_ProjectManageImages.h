/********************************************************************************
** Form generated from reading UI file 'ProjectManageImages.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECTMANAGEIMAGES_H
#define UI_PROJECTMANAGEIMAGES_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_ManageImagesDialog
{
public:
    QGridLayout *gridLayout_2;
    QLabel *imageManagementLabel;
    QGridLayout *gridLayout;
    QPushButton *cancelPushButton;
    QSpacerItem *verticalSpacer;
    QPushButton *addPushButton;
    QPushButton *deletePushButton;
    QListWidget *imagesListWidget;
    QPushButton *okPushButton;
    QPushButton *insertPushButton;

    void setupUi(QDialog *ManageImagesDialog)
    {
        if (ManageImagesDialog->objectName().isEmpty())
            ManageImagesDialog->setObjectName(QStringLiteral("ManageImagesDialog"));
        ManageImagesDialog->resize(990, 688);
        QIcon icon;
        icon.addFile(QStringLiteral("Resources/images/image.svg"), QSize(), QIcon::Normal, QIcon::Off);
        ManageImagesDialog->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(ManageImagesDialog);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        imageManagementLabel = new QLabel(ManageImagesDialog);
        imageManagementLabel->setObjectName(QStringLiteral("imageManagementLabel"));
        imageManagementLabel->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(imageManagementLabel, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        cancelPushButton = new QPushButton(ManageImagesDialog);
        cancelPushButton->setObjectName(QStringLiteral("cancelPushButton"));

        gridLayout->addWidget(cancelPushButton, 5, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 3);

        addPushButton = new QPushButton(ManageImagesDialog);
        addPushButton->setObjectName(QStringLiteral("addPushButton"));

        gridLayout->addWidget(addPushButton, 1, 0, 1, 2);

        deletePushButton = new QPushButton(ManageImagesDialog);
        deletePushButton->setObjectName(QStringLiteral("deletePushButton"));

        gridLayout->addWidget(deletePushButton, 1, 2, 1, 2);

        imagesListWidget = new QListWidget(ManageImagesDialog);
        imagesListWidget->setObjectName(QStringLiteral("imagesListWidget"));
        imagesListWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        imagesListWidget->setDragDropMode(QAbstractItemView::DragDrop);
        imagesListWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        imagesListWidget->setIconSize(QSize(200, 200));
        imagesListWidget->setMovement(QListView::Snap);
        imagesListWidget->setViewMode(QListView::IconMode);

        gridLayout->addWidget(imagesListWidget, 0, 0, 1, 4);

        okPushButton = new QPushButton(ManageImagesDialog);
        okPushButton->setObjectName(QStringLiteral("okPushButton"));

        gridLayout->addWidget(okPushButton, 5, 0, 1, 1);

        insertPushButton = new QPushButton(ManageImagesDialog);
        insertPushButton->setObjectName(QStringLiteral("insertPushButton"));

        gridLayout->addWidget(insertPushButton, 5, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);


        retranslateUi(ManageImagesDialog);

        QMetaObject::connectSlotsByName(ManageImagesDialog);
    } // setupUi

    void retranslateUi(QDialog *ManageImagesDialog)
    {
        ManageImagesDialog->setWindowTitle(QApplication::translate("ManageImagesDialog", "Dialog", nullptr));
        imageManagementLabel->setText(QApplication::translate("ManageImagesDialog", "ImageManagement", nullptr));
        cancelPushButton->setText(QApplication::translate("ManageImagesDialog", "Cancel", nullptr));
        addPushButton->setText(QApplication::translate("ManageImagesDialog", "Add image to server", nullptr));
        deletePushButton->setText(QApplication::translate("ManageImagesDialog", "Delete selected images", nullptr));
        okPushButton->setText(QApplication::translate("ManageImagesDialog", "OK", nullptr));
        insertPushButton->setText(QApplication::translate("ManageImagesDialog", "Insert in content", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManageImagesDialog: public Ui_ManageImagesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECTMANAGEIMAGES_H
