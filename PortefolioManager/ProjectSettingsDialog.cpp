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
	
	connect(projectManager, SIGNAL(requestFinished()), SLOT(onGetProjectFinished()));

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
}

bool ProjectSettingsDialog::setProjectId(const QString& projectId)
{
	qDebug() << "Request Project";
	return projectManager->getProject(projectId);
}

QSharedPointer<Project> ProjectSettingsDialog::getProject() const
{
	return currentProject;
}

void ProjectSettingsDialog::onOkTriggered(bool)
{
	currentProject->setTitle(ui.projectTitleLineEdit->text());
	currentProject->setBeginDate(ui.beginDateEdit->date());

	if (ui.workInProgressCheckBox->checkState() == Qt::Unchecked)
		currentProject->setEndDate(ui.endDateEdit->date());
	else
		currentProject->setEndDate("");

	currentProject->setSmallDescription(ui.smallDescriptionLineEdit->text());

	if (isNewProject)
	{
		qDebug() << "New project";
		qDebug() << currentProject->toJson();
	}
	else
	{
		qDebug() << "Project modified";
		qDebug() << currentProject->toJson();
	}
	accept();
}

void ProjectSettingsDialog::onCancelTriggered(bool)
{
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
	Project project = Project::fromJson(projectManager->getLastReplyBody());
	setUIFromProject(project);
}

void ProjectSettingsDialog::setUIFromProject(const Project& project)
{
	ui.projectTitleLineEdit->setText(project.getTitle());
	ui.beginDateEdit->setDate(project.getBeginDate());
	
	if (project.getEndDate().isNull())
		ui.workInProgressCheckBox->setCheckState(Qt::Checked);
	else
	{
		ui.workInProgressCheckBox->setCheckState(Qt::Unchecked);
		ui.endDateEdit->setDate(project.getEndDate());
	}

	ui.smallDescriptionLineEdit->setText(project.getSmallDescription());
	ui.smallDescriptionLineEdit->setCursorPosition(0);
}