#include <QCalendarWidget>
#include <QDate>
#include <QDebug>
#include <qglobal.h>
#include <QLocale>
#include <QMessageBox>

#include "ProjectSettingsDialog.h"
#include "Project.h"
#include "ProjectManager.h"
#include "NetworkManager.h"
#include "NetworkReplyWrapper.h"

using namespace PortefolioManagerUtilities;

ProjectSettingsDialog::ProjectSettingsDialog(QWidget *parent, ProjectManager* projectManager)
	: QDialog(parent),
	projectManager(projectManager),
	isNewProject(true)
{
	ui.setupUi(this);
	setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
	ui.beginDateEdit->setDisplayFormat("MM/dd/yyyy");
	ui.endDateEdit->setDisplayFormat("MM/dd/yyyy");
	ui.beginDateEdit->calendarWidget()->setLocale(QLocale(QLocale::English));
	ui.endDateEdit->calendarWidget()->setLocale(QLocale(QLocale::English));

	connect(ui.okPushButton, &QPushButton::clicked, this, &ProjectSettingsDialog::onOkTriggered);
	connect(ui.cancelPushButton, &QPushButton::clicked, this, &ProjectSettingsDialog::onCancelTriggered);

	getProjectReply = new NetworkReplyWrapper(this);
	connect(getProjectReply, &NetworkReplyWrapper::finishedProcessing, this, &ProjectSettingsDialog::onGetProjectFinished);

	updateProjectReply = new NetworkReplyWrapper(this);
	connect(updateProjectReply, &NetworkReplyWrapper::finishedProcessing, this, &ProjectSettingsDialog::onUpdateProjectFinished);

	init();
}

void ProjectSettingsDialog::init() {
	isNewProject = true;
	currentProject = QSharedPointer<Project>(new Project());

	ui.projectTitleLineEdit->clear();
	ui.beginDateEdit->clear();
	ui.beginDateEdit->setDate(QDate::currentDate());
	ui.statusComboBox->setCurrentIndex(0);
	ui.endDateEdit->hide();
	ui.endDateEdit->clear();
	ui.endDateEdit->setDate(QDate::currentDate());
	ui.smallDescriptionLineEdit->clear();
	unlockUnput();
}

void ProjectSettingsDialog::setProjectId(const QString& projectId)
{
	lockInput();
	qDebug() << "Request Project";
	isNewProject = false;
	getProjectReply->setNetworkReply(projectManager->getProject(projectId));
}

QSharedPointer<Project> ProjectSettingsDialog::getProject() const
{
	return currentProject;
}

void ProjectSettingsDialog::onOkTriggered(bool)
{
	lockInput();
	currentProject->setTitle(ui.projectTitleLineEdit->text());
	currentProject->setBeginDate(ui.beginDateEdit->date());

	if (ui.statusComboBox->currentIndex() != ui.statusComboBox->findText("Ongoing"))
		currentProject->setEndDate(ui.endDateEdit->date());
	else
		currentProject->setEndDate("");

	currentProject->setStatus(ui.statusComboBox->currentIndex());
	currentProject->setSmallDescription(ui.smallDescriptionLineEdit->text());

	if (!isAdmin)
	{
		qInfo() << "Permission denied. Please contact an administrator.";
		if (!isAdmin)
			QMessageBox::warning(this, tr("Permission warning"), tr("This user is not an administrator. "
				"This operation will not finish but with an administrator account, your changes would have been sent to the server."));

		reject();
	}

	if (isNewProject)
	{
		qDebug() << "New project";
		projectManager->createProject(token, currentProject->getId(), currentProject->toHashSettings());
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

void ProjectSettingsDialog::onStatusComboBoxIndexChanged(int index)
{
	if (index != ui.statusComboBox->findText("Ongoing"))
	{
		ui.endDateEdit->show();
		ui.endDateLabel->show();
	}
	else
	{
		ui.endDateEdit->hide();
		ui.endDateLabel->hide();
	}
}

void ProjectSettingsDialog::onGetProjectFinished(NetworkReplyWrapper* networkReplyWrapper)
{
	const QString& projectJson = getProjectReply->getBody();
	currentProject->getValuesFromProject(Project::fromJson(projectJson));
	setUIFromProject(currentProject);
}

void ProjectSettingsDialog::onUpdateProjectFinished(PortefolioManagerUtilities::NetworkReplyWrapper* networkReplyWrapper)
{
	emit projectPosted();
}

void ProjectSettingsDialog::setUIFromProject(QSharedPointer<Project> project)
{
	ui.projectTitleLineEdit->setText(project->getTitle());
	ui.beginDateEdit->setDate(project->getBeginDate());

	ui.statusComboBox->setCurrentIndex(project->getStatus());

	if (ui.statusComboBox->currentIndex() != ui.statusComboBox->findText("Ongoing"))
	{
		ui.endDateEdit->setDate(project->getEndDate());
		ui.endDateEdit->show();
		ui.endDateLabel->show();
	}
	else
	{
		ui.endDateEdit->hide();
		ui.endDateLabel->hide();
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
	ui.statusComboBox->setEnabled(false);
	ui.smallDescriptionLineEdit->setReadOnly(true);
	ui.okPushButton->setEnabled(false);
	ui.cancelPushButton->setEnabled(true);
}

void ProjectSettingsDialog::unlockUnput()
{
	ui.projectTitleLineEdit->setReadOnly(false);
	ui.beginDateEdit->setReadOnly(false);
	ui.endDateEdit->setReadOnly(false);
	ui.statusComboBox->setEnabled(true);
	ui.smallDescriptionLineEdit->setReadOnly(false);
	ui.okPushButton->setEnabled(true);
	ui.cancelPushButton->setEnabled(true);
}
