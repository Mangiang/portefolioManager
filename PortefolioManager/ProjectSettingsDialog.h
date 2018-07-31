#pragma once

#include <QDialog>
#include <QSharedPointer>
#include "ui_ProjectSettingsDialog.h"

class Project;

class ProjectSettingsDialog : public QDialog
{
	Q_OBJECT

public:
	ProjectSettingsDialog(QWidget *parent = Q_NULLPTR);
	~ProjectSettingsDialog();
	void setProject(Project* project);

private:
	Ui::ProjectSettingsDialog ui;
	QSharedPointer<Project> currentProject;
};
