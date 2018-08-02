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
	ProjectSettingsDialog(QWidget *parent = Q_NULLPTR);
	void init();
	bool setProjectId(const QString& projectId);
	QSharedPointer<Project> getProject() const;

	bool getIsAdmin() const { return isAdmin; }
	void setIsAdmin(bool val) { isAdmin = val; }
	QString getToken() const { return token; }
	void setToken(const QString& val) { token = val; }
	void setProjectManager(PortefolioManagerUtilities::ProjectManager* val);
signals:
	void projectPosted();
private:
	Ui::ProjectSettingsDialog ui;
	QSharedPointer<Project> currentProject;
	bool isNewProject;
	bool isAdmin;
	QString token;
	
	PortefolioManagerUtilities::ProjectManager* projectManager;
	void setUIFromProject(QSharedPointer<Project> project);
	void lockInput();
	void unlockUnput();
private slots:
	void onOkTriggered(bool checked = false);
	void onCancelTriggered(bool checked = false);
	void onEndDateCheckStateChanged(int state);
	void onGetProjectFinished();
};