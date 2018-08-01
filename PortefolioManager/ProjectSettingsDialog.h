#pragma once

#include <QDialog>
#include <QSharedPointer>
#include "ui_ProjectSettingsDialog.h"

class Project;

namespace PortefolioManagerUtilities {
	class ProjectManager;
}

class ProjectSettingsDialog : public QDialog
{
	Q_OBJECT

public:
	ProjectSettingsDialog(QWidget *parent = Q_NULLPTR, PortefolioManagerUtilities::ProjectManager* projectManager = nullptr);
	void init();
	bool setProjectId(const QString& projectId);
	QSharedPointer<Project> getProject() const;

private:
	Ui::ProjectSettingsDialog ui;
	QSharedPointer<Project> currentProject;
	bool isNewProject;
	PortefolioManagerUtilities::ProjectManager* projectManager;
	
	void setUIFromProject(const Project& project);
private slots:
	void onOkTriggered(bool checked = false);
	void onCancelTriggered(bool checked = false);
	void onEndDateCheckStateChanged(int state);
	void onGetProjectFinished();
};