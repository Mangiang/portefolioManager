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
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_ProjectSettingsDialog
{
public:

    void setupUi(QDialog *ProjectSettingsDialog)
    {
        if (ProjectSettingsDialog->objectName().isEmpty())
            ProjectSettingsDialog->setObjectName(QStringLiteral("ProjectSettingsDialog"));
        ProjectSettingsDialog->resize(400, 300);

        retranslateUi(ProjectSettingsDialog);

        QMetaObject::connectSlotsByName(ProjectSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *ProjectSettingsDialog)
    {
        ProjectSettingsDialog->setWindowTitle(QApplication::translate("ProjectSettingsDialog", "ProjectSettingsDialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProjectSettingsDialog: public Ui_ProjectSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECTSETTINGSDIALOG_H
