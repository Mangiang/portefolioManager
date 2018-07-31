#include "ProjectSettingsDialog.h"

ProjectSettingsDialog::ProjectSettingsDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

ProjectSettingsDialog::~ProjectSettingsDialog()
{
}

void ProjectSettingsDialog::setProject(Project* project)
{
	currentProject = QSharedPointer<Project>(project);
}