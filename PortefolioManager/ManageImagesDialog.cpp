#include "ManageImagesDialog.h"

#include <QDebug>
#include <QFileDialog>
#include <QIcon>
#include <QListWidget>

#include "ProjectManager.h"
#include "Project.h"
#include "Image.h"
#include "NetworkReplyWrapper.h"

using namespace PortefolioManagerUtilities;

ManageImagesDialog::ManageImagesDialog(QWidget *parent)
	: QDialog(parent),
	projectManager(new ProjectManager(this)),
	isAdmin(false)
{
	ui.setupUi(this);
	setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);

	connect(ui.okPushButton, &QPushButton::clicked, this, &ManageImagesDialog::onAccept);
	connect(ui.cancelPushButton, &QPushButton::clicked, this, &ManageImagesDialog::onReject);
	connect(ui.addPushButton, &QPushButton::clicked, this, &ManageImagesDialog::onAddPush);
	connect(ui.deletePushButton, &QPushButton::clicked, this, &ManageImagesDialog::onDeletePush);

	getProjectReply = new NetworkReplyWrapper(this);
	connect(getProjectReply, &NetworkReplyWrapper::finishedProcessing,this, &ManageImagesDialog::onProjectRequestFinished);
}

void ManageImagesDialog::clearImages()
{
	qDebug() << "Clear images";
}

void ManageImagesDialog::AddImage(QPixmap imageMap) const
{
	ui.imagesListWidget->addItem(new QListWidgetItem(QIcon(imageMap), ""));
}

void ManageImagesDialog::getImages(const QString& projectId)
{
	ui.imagesListWidget->clear();
	getProjectReply->setNetworkReply(projectManager->getProject(projectId));
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
}

void ManageImagesDialog::onProjectRequestFinished(NetworkReplyWrapper* networkReplyWrapper)
{
	const QString& projectJson = getProjectReply->getBody();
	const Project& project = Project::fromJson(projectJson);
	const QList<Image>& imagesList = *project.getImages();

	imageRequestReplies.clear();
	unlockInput();
	for (Image img : imagesList) {
		NetworkReplyWrapper* reply = new NetworkReplyWrapper(this);
		reply->setNetworkReply(projectManager->getImage(img.getUrl()));
		connect(reply, &NetworkReplyWrapper::finishedProcessing, this, &ManageImagesDialog::onImageProjectRequestFinished, Qt::UniqueConnection);
		imageRequestReplies.append(QSharedPointer<NetworkReplyWrapper>(reply));
	}
}

void ManageImagesDialog::onImageProjectRequestFinished(NetworkReplyWrapper* networkReplyWrapper)
{
	QByteArray imageBytes = networkReplyWrapper->getBody();
	QPixmap pixMap;
	pixMap.loadFromData(imageBytes);
	AddImage(pixMap);
}
