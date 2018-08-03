#include "ManageImagesDialog.h"

#include <QDebug>
#include <QFileDialog>
#include <QIcon>
#include <QListWidget>

#include "ProjectManager.h"
#include "Project.h"
#include "Image.h"

ManageImagesDialog::ManageImagesDialog(QWidget *parent)
	: QDialog(parent),
	projectManager(new PortefolioManagerUtilities::ProjectManager(this)),
	isAdmin(false)
{
	ui.setupUi(this);
	setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);

	connect(ui.okPushButton, SIGNAL(clicked(bool)), SLOT(onAccept(bool)));
	connect(ui.cancelPushButton, SIGNAL(clicked(bool)), SLOT(onReject(bool)));
	connect(ui.addPushButton, SIGNAL(clicked(bool)), SLOT(onAddPush(bool)));
	connect(ui.deletePushButton, SIGNAL(clicked(bool)), SLOT(onDeletePush(bool)));

}

void ManageImagesDialog::clearImages()
{

}

void ManageImagesDialog::AddImage(QPixmap imageMap) const
{
	ui.imagesListWidget->addItem(new QListWidgetItem(QIcon(imageMap), ""));
}

void ManageImagesDialog::getImages(const QString& projectId)
{
	ui.imagesListWidget->clear();
	connect(projectManager, SIGNAL(requestFinished()), SLOT(onProjectRequestFinished()));
	projectManager->getProject(projectId);
}

void ManageImagesDialog::setToken(const QString& token)
{
	this->token = token;
}

void ManageImagesDialog::setIsAdmin(bool isAdmin)
{
	this->isAdmin = isAdmin;
}

void ManageImagesDialog::lockInput()
{
	ui.okPushButton->setEnabled(false);
	ui.cancelPushButton->setEnabled(false);
	ui.imagesListWidget->setEnabled(false);
}

void ManageImagesDialog::unlockInput()
{
	ui.okPushButton->setEnabled(true);
	ui.cancelPushButton->setEnabled(true);
	ui.imagesListWidget->setEnabled(true);
}

void ManageImagesDialog::onAccept(bool)
{
	lockInput();
	accept();
}

void ManageImagesDialog::onReject(bool)
{
	lockInput();
	reject();
}

void ManageImagesDialog::onDeletePush(bool checked /*= false*/)
{

}

void ManageImagesDialog::onAddPush(bool checked /*= false*/)
{
	auto fileName = QFileDialog::getOpenFileName(this, tr("Choose an Image"), ".", tr("Image Files (*.png *.jpg *.bmp)"));
	qDebug() << fileName;
}

void ManageImagesDialog::onProjectRequestFinished() 
{
	disconnect(projectManager, SIGNAL(requestFinished()), this, SLOT(onProjectRequestFinished()));
	const QString& projectJson = projectManager->getLastReplyBody();
	const Project& project = Project::fromJson(projectJson);
	const QList<Image>& imagesList = *project.getImages();

	connect(projectManager, SIGNAL(requestFinished()), SLOT(onImageProjectRequestFinished()), Qt::UniqueConnection);
	unlockInput();
	for (Image img : imagesList) {
		projectManager->getImage(img.getUrl());
	}
}

void ManageImagesDialog::onImageProjectRequestFinished()
{
	QByteArray imageBytes = projectManager->getLastReplyBody();
	QPixmap pixMap;
	pixMap.loadFromData(imageBytes);
	AddImage(pixMap);
}
