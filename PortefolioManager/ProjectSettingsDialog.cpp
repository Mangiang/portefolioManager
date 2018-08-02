#include <QCalendarWidget>
#include <QDate>
#include <QDebug>
#include <QLocale>

#include "ProjectSettingsDialog.h"
#include "Project.h"
#include "ProjectManager.h"

ProjectSettingsDialog::ProjectSettingsDialog(QWidget *parent, PortefolioManagerUtilities::ProjectManager* projectManager)
	: QDialog(parent),
	isNewProject(true),
	projectManager(projectManager)
{
	ui.setupUi(this);
	setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
	ui.beginDateEdit->setDisplayFormat("MM/dd/yyyy");
	ui.endDateEdit->setDisplayFormat("MM/dd/yyyy");
	ui.beginDateEdit->calendarWidget()->setLocale(QLocale(QLocale::English));
	ui.endDateEdit->calendarWidget()->setLocale(QLocale(QLocale::English));
	
	connect(ui.workInProgressCheckBox, SIGNAL(stateChanged(int)), SLOT(onEndDateCheckStateChanged(int)));
	connect(ui.okPushButton, SIGNAL(clicked(bool)), SLOT(onOkTriggered(bool)));
	connect(ui.cancelPushButton, SIGNAL(clicked(bool)), SLOT(onCancelTriggered(bool)));
	

	currentProject = QSharedPointer<Project>(new Project());

	init();
}

void ProjectSettingsDialog::init() {
	isNewProject = true;
	
	ui.projectTitleLineEdit->clear();
	ui.beginDateEdit->clear();
	ui.workInProgressCheckBox->setChecked(true);
	ui.endDateEdit->hide();
	ui.endDateEdit->clear();
	ui.smallDescriptionLineEdit->clear();
	unlockUnput();
}

bool ProjectSettingsDialog::setProjectId(const QString& projectId)
{
	lockInput();
	connect(projectManager, SIGNAL(requestFinished()), SLOT(onGetProjectFinished()));
	qDebug() << "Request Project";
	isNewProject = false;
	return projectManager->getProject(projectId);
}

QSharedPointer<Project> ProjectSettingsDialog::getProject() const
{
	return currentProject;
}

void ProjectSettingsDialog::onOkTriggered(bool)
{
	lockInput();
	disconnect(projectManager, SIGNAL(requestFinished()), this, 0);
	currentProject->setTitle(ui.projectTitleLineEdit->text());
	currentProject->setBeginDate(ui.beginDateEdit->date());

	if (ui.workInProgressCheckBox->checkState() == Qt::Unchecked)
		currentProject->setEndDate(ui.endDateEdit->date());
	else
		currentProject->setEndDate("");

	currentProject->setSmallDescription(ui.smallDescriptionLineEdit->text());

	if (!isAdmin)
	{
		qInfo() << "Operation denied. Please contact an administrator.";
		accept();
		return;
	}

	if (isNewProject)
	{
		qDebug() << "New project";
		qDebug() << currentProject->toJson();
	}
	else
	{
		qDebug() << "Modify project";
		projectManager->updateProject(token, currentProject->getId(), currentProject->toHashSettings());
	}
	accept();
}

void ProjectSettingsDialog::onCancelTriggered(bool)
{
	lockInput();
	reject();
}

void ProjectSettingsDialog::onEndDateCheckStateChanged(int state)
{
	if (state == Qt::Unchecked)
	{
		ui.endDateEdit->show();
	}
	else
	{
		ui.endDateEdit->hide();
	}
}

void ProjectSettingsDialog::onGetProjectFinished()
{
	const QString& projectJson = projectManager->getLastReplyBody();
	currentProject->getValuesFromProject(Project::fromJson(projectJson));
	setUIFromProject(currentProject);
}

void ProjectSettingsDialog::setUIFromProject(QSharedPointer<Project> project)
{
	ui.projectTitleLineEdit->setText(project->getTitle());
	ui.beginDateEdit->setDate(project->getBeginDate());
	
	if (project->getEndDate().isNull())
		ui.workInProgressCheckBox->setCheckState(Qt::Checked);
	else
	{
		ui.workInProgressCheckBox->setCheckState(Qt::Unchecked);
		ui.endDateEdit->setDate(project->getEndDate());
	}

	ui.smallDescriptionLineEdit->setText(project->getSmallDescription());
	ui.smallDescriptionLineEdit->setCursorPosition(0);
	unlockUnput();
}

void ProjectSettingsDialog::lockInput()
{
	ui.projectTitleLineEdit->setReadOnly(true);
	ui.beginDateEdit->setReadOnly(true);
	ui.endDateEdit->setReadOnly(true);
	ui.workInProgressCheckBox->setEnabled(false);
	ui.smallDescriptionLineEdit->setReadOnly(true);
	ui.okPushButton->setEnabled(false);
	ui.cancelPushButton->setEnabled(true);
}

void ProjectSettingsDialog::unlockUnput()
{
	ui.projectTitleLineEdit->setReadOnly(false);
	ui.beginDateEdit->setReadOnly(false);
	ui.endDateEdit->setReadOnly(false);
	ui.workInProgressCheckBox->setEnabled(true);
	ui.smallDescriptionLineEdit->setReadOnly(false);
	ui.okPushButton->setEnabled(true);
	ui.cancelPushButton->setEnabled(true);
}
