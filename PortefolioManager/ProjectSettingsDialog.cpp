#include <QCalendarWidget>
#include <QDate>
#include <QDebug>
#include <QLocale>
#include <QMessageBox>

#include "ProjectSettingsDialog.h"
#include "Project.h"
#include "ProjectManager.h"
#include "NetworkManager.h"

ProjectSettingsDialog::ProjectSettingsDialog(QWidget *parent)
	: QDialog(parent),
	isNewProject(true)
{
	ui.setupUi(this);
	setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
	ui.beginDateEdit->setDisplayFormat("MM/dd/yyyy");
	ui.endDateEdit->setDisplayFormat("MM/dd/yyyy");
	ui.beginDateEdit->calendarWidget()->setLocale(QLocale(QLocale::English));
	ui.endDateEdit->calendarWidget()->setLocale(QLocale(QLocale::English));
	
	connect(ui.statusComboBox, SIGNAL(currentIndexChanged(int)), SLOT(onStatusComboBoxIndexChanged(int)));
	connect(ui.okPushButton, SIGNAL(clicked(bool)), SLOT(onOkTriggered(bool)));
	connect(ui.cancelPushButton, SIGNAL(clicked(bool)), SLOT(onCancelTriggered(bool)));

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

bool ProjectSettingsDialog::setProjectId(const QString& projectId)
{
	lockInput();
	qDebug() << "Request Project";
	isNewProject = false;
	return projectManager->getProject(projectId);
}

QSharedPointer<Project> ProjectSettingsDialog::getProject() const
{
	return currentProject;
}

void ProjectSettingsDialog::setProjectManager(PortefolioManagerUtilities::ProjectManager* val)
{
	projectManager = val;
	connect(projectManager, SIGNAL(requestFinished()), SLOT(onGetProjectFinished()), Qt::UniqueConnection);
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
			QMessageBox::warning( this, tr("Permission warning"), tr("This user is not an administrator. "
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

void ProjectSettingsDialog::onGetProjectFinished()
{
	if (projectManager->getLastReplyOperation() == PortefolioManagerUtilities::ReplyOperation::PUT)
	{
		emit projectPosted();
	}
	else if (projectManager->getLastReplyOperation() == PortefolioManagerUtilities::ReplyOperation::GET)
	{
		const QString& projectJson = projectManager->getLastReplyBody();
		currentProject->getValuesFromProject(Project::fromJson(projectJson));
		setUIFromProject(currentProject);
	}
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
