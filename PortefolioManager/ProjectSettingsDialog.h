#pragma once

#include <QDialog>
#include <QSharedPointer>
#include "ui_ProjectSettingsDialog.h"

class Project;

namespace PortefolioManagerUtilities {
	class ProjectManager;
	class NetworkReplyWrapper;
};

class ProjectSettingsDialog : public QDialog
{
	Q_OBJECT

public:
	ProjectSettingsDialog(QWidget *parent = Q_NULLPTR, PortefolioManagerUtilities::ProjectManager* projectManager = Q_NULLPTR);
	void init();
	void setProjectId(const QString& projectId);
	QSharedPointer<Project> getProject() const;

	bool getIsAdmin() const { return isAdmin; }
	void setIsAdmin(bool val) { isAdmin = val; }
	QString getToken() const { return token; }
	void setToken(const QString& val) { token = val; }

signals:
	void projectPosted();

private:
	Ui::ProjectSettingsDialog ui;
	QSharedPointer<Project> currentProject;
	bool isNewProject;
	bool isAdmin;
	QString token;
	PortefolioManagerUtilities::NetworkReplyWrapper* getProjectReply;
	PortefolioManagerUtilities::NetworkReplyWrapper* updateProjectReply;

	PortefolioManagerUtilities::ProjectManager* projectManager; // Ths class is not the parent of the ProjectManager ! 
	void setUIFromProject(QSharedPointer<Project> project);
	void lockInput();
	void unlockUnput();

private slots:
	void onOkTriggered(bool checked = false);
	void onCancelTriggered(bool checked = false);
	void onStatusComboBoxIndexChanged(int index);
	void onGetProjectFinished(PortefolioManagerUtilities::NetworkReplyWrapper* networkReplyWrapper);
	void onUpdateProjectFinished(PortefolioManagerUtilities::NetworkReplyWrapper* networkReplyWrapper);
};