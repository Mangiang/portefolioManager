/********************************************************************************
** Form generated from reading UI file 'ProjectSettingsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECTSETTINGSDIALOG_H
#define UI_PROJECTSETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ProjectSettingsDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *projectLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *okPushButton;
    QPushButton *cancelPushButton;
    QFormLayout *formLayout;
    QLabel *projectTitleLabel;
    QLineEdit *projectTitleLineEdit;
    QLabel *statusLabel;
    QComboBox *statusComboBox;
    QLabel *beginDateLabel;
    QDateEdit *beginDateEdit;
    QLabel *endDateLabel;
    QDateEdit *endDateEdit;
    QLabel *smallDescriptionLabel;
    QLineEdit *smallDescriptionLineEdit;

    void setupUi(QDialog *ProjectSettingsDialog)
    {
        if (ProjectSettingsDialog->objectName().isEmpty())
            ProjectSettingsDialog->setObjectName(QStringLiteral("ProjectSettingsDialog"));
        ProjectSettingsDialog->resize(478, 379);
        ProjectSettingsDialog->setMinimumSize(QSize(478, 379));
        QIcon icon;
        icon.addFile(QStringLiteral("Resources/images/repairing-service.svg"), QSize(), QIcon::Normal, QIcon::Off);
        ProjectSettingsDialog->setWindowIcon(icon);
        gridLayout = new QGridLayout(ProjectSettingsDialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        projectLabel = new QLabel(ProjectSettingsDialog);
        projectLabel->setObjectName(QStringLiteral("projectLabel"));
        projectLabel->setMaximumSize(QSize(16777215, 20));
        projectLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(projectLabel, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        okPushButton = new QPushButton(ProjectSettingsDialog);
        okPushButton->setObjectName(QStringLiteral("okPushButton"));

        horizontalLayout->addWidget(okPushButton);

        cancelPushButton = new QPushButton(ProjectSettingsDialog);
        cancelPushButton->setObjectName(QStringLiteral("cancelPushButton"));

        horizontalLayout->addWidget(cancelPushButton);


        gridLayout->addLayout(horizontalLayout, 4, 1, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        projectTitleLabel = new QLabel(ProjectSettingsDialog);
        projectTitleLabel->setObjectName(QStringLiteral("projectTitleLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, projectTitleLabel);

        projectTitleLineEdit = new QLineEdit(ProjectSettingsDialog);
        projectTitleLineEdit->setObjectName(QStringLiteral("projectTitleLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, projectTitleLineEdit);

        statusLabel = new QLabel(ProjectSettingsDialog);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, statusLabel);

        statusComboBox = new QComboBox(ProjectSettingsDialog);
        statusComboBox->addItem(QString());
        statusComboBox->addItem(QString());
        statusComboBox->addItem(QString());
        statusComboBox->addItem(QString());
        statusComboBox->setObjectName(QStringLiteral("statusComboBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, statusComboBox);

        beginDateLabel = new QLabel(ProjectSettingsDialog);
        beginDateLabel->setObjectName(QStringLiteral("beginDateLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, beginDateLabel);

        beginDateEdit = new QDateEdit(ProjectSettingsDialog);
        beginDateEdit->setObjectName(QStringLiteral("beginDateEdit"));
        beginDateEdit->setCalendarPopup(true);
        beginDateEdit->setTimeSpec(Qt::UTC);

        formLayout->setWidget(2, QFormLayout::FieldRole, beginDateEdit);

        endDateLabel = new QLabel(ProjectSettingsDialog);
        endDateLabel->setObjectName(QStringLiteral("endDateLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, endDateLabel);

        endDateEdit = new QDateEdit(ProjectSettingsDialog);
        endDateEdit->setObjectName(QStringLiteral("endDateEdit"));
        endDateEdit->setCalendarPopup(true);

        formLayout->setWidget(3, QFormLayout::FieldRole, endDateEdit);

        smallDescriptionLabel = new QLabel(ProjectSettingsDialog);
        smallDescriptionLabel->setObjectName(QStringLiteral("smallDescriptionLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, smallDescriptionLabel);

        smallDescriptionLineEdit = new QLineEdit(ProjectSettingsDialog);
        smallDescriptionLineEdit->setObjectName(QStringLiteral("smallDescriptionLineEdit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, smallDescriptionLineEdit);


        gridLayout->addLayout(formLayout, 1, 1, 1, 1);


        retranslateUi(ProjectSettingsDialog);

        QMetaObject::connectSlotsByName(ProjectSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *ProjectSettingsDialog)
    {
        ProjectSettingsDialog->setWindowTitle(QApplication::translate("ProjectSettingsDialog", "ProjectSettingsDialog", nullptr));
        projectLabel->setText(QApplication::translate("ProjectSettingsDialog", "PROJECT", nullptr));
        okPushButton->setText(QApplication::translate("ProjectSettingsDialog", "OK", nullptr));
        cancelPushButton->setText(QApplication::translate("ProjectSettingsDialog", "CANCEL", nullptr));
        projectTitleLabel->setText(QApplication::translate("ProjectSettingsDialog", "Project name :", nullptr));
        statusLabel->setText(QApplication::translate("ProjectSettingsDialog", "Status :", nullptr));
        statusComboBox->setItemText(0, QApplication::translate("ProjectSettingsDialog", "Completed", nullptr));
        statusComboBox->setItemText(1, QApplication::translate("ProjectSettingsDialog", "Ongoing", nullptr));
        statusComboBox->setItemText(2, QApplication::translate("ProjectSettingsDialog", "Aborted", nullptr));
        statusComboBox->setItemText(3, QApplication::translate("ProjectSettingsDialog", "On Hold", nullptr));

        beginDateLabel->setText(QApplication::translate("ProjectSettingsDialog", "Begin Date :", nullptr));
        endDateLabel->setText(QApplication::translate("ProjectSettingsDialog", "End Date :", nullptr));
        smallDescriptionLabel->setText(QApplication::translate("ProjectSettingsDialog", "Small Description :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProjectSettingsDialog: public Ui_ProjectSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECTSETTINGSDIALOG_H
