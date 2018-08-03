#include "ManageImagesDialog.h"

#include <QDebug>
#include <QFileDialog>
#include <QIcon>
#include <QListWidget>
#include <QMessageBox>

#include "ProjectManager.h"
#include "Project.h"
#include "Image.h"
#include "NetworkReplyWrapper.h"

using namespace PortefolioManagerUtilities;

ManageImagesDialog::ManageImagesDialog(QWidget *parent, ProjectManager* projectManager)
	: QDialog(parent),
	projectManager(projectManager),
	isAdmin(false)
{

	ui.setupUi(this);
	setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);

	connect(ui.okPushButton, &QPushButton::clicked, this, &ManageImagesDialog::onAccept);
	connect(ui.cancelPushButton, &QPushButton::clicked, this, &ManageImagesDialog::onReject);
	connect(ui.addPushButton, &QPushButton::clicked, this, &ManageImagesDialog::onAddPush);
	connect(ui.deletePushButton, &QPushButton::clicked, this, &ManageImagesDialog::onDeletePush);

	getProjectReply = new NetworkReplyWrapper(this);
	connect(getProjectReply, &NetworkReplyWrapper::finishedProcessing, this, &ManageImagesDialog::onProjectRequestFinished);
}

void ManageImagesDialog::clearImages()
{
	qDebug() << "Clear images";
}

void ManageImagesDialog::AddImage(const QPixmap& imageMap, const QString& path)
{
	unlockInput();
	QListWidgetItem* item = new QListWidgetItem(QIcon(imageMap), "");
	item->setData(Qt::UserRole, path);
	ui.imagesListWidget->addItem(item);
}

void ManageImagesDialog::getImages(const QString& projectId)
{
	ui.imagesListWidget->clear();
	this->projectId = projectId;
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
	imageUploadRequestReplies.clear();

	if (!isAdmin)
	{
		qInfo() << "Permission denied. Please contact an administrator.";
		if (!isAdmin)
			QMessageBox::warning(this, tr("Permission warning"), tr("This user is not an administrator. "
				"This operation will not finish but with an administrator account, your changes would have been sent to the server."));

		reject();
		return;
	}

	const int itemCount = ui.imagesListWidget->count();
	for (int i = 0; i < itemCount; ++i)
	{
		QListWidgetItem* const item = ui.imagesListWidget->item(i);
		const QString& imagePath = item->data(Qt::UserRole).toString();
		if (!imagePath.isEmpty())
		{
			NetworkReplyWrapper* reply = new NetworkReplyWrapper(this);
			reply->setNetworkReply(projectManager->uploadImage(imagePath, projectId, token));
			connect(reply, &NetworkReplyWrapper::finishedProcessing, this, &ManageImagesDialog::onImageUploadRequestFinished, Qt::UniqueConnection);
			imageUploadRequestReplies.append(QSharedPointer<NetworkReplyWrapper>(reply));
		}
	}

	for (QSharedPointer<QListWidgetItem> removeItem : removeItemList)
	{
		const QString& id = removeItem->data(Qt::UserRole).toString();
		if (!id.isEmpty())
		{
			NetworkReplyWrapper* reply = new NetworkReplyWrapper(this);
			reply->setNetworkReply(projectManager->deleteImage(id, projectId, token));
			connect(reply, &NetworkReplyWrapper::finishedProcessing, this, &ManageImagesDialog::onImageDeleteRequestFinished, Qt::UniqueConnection);
			imageUploadRequestReplies.append(QSharedPointer<NetworkReplyWrapper>(reply));
		}
	}
	removeItemList.clear();
	accept();
}

void ManageImagesDialog::onReject(bool)
{
	lockInput();
	reject();
}

void ManageImagesDialog::onDeletePush(bool checked /*= false*/)
{
	const QList<QListWidgetItem*>& selectedItems = ui.imagesListWidget->selectedItems();
	for (QListWidgetItem* listWidgetItem : selectedItems)
	{
		removeItemList.append(QSharedPointer<QListWidgetItem>(ui.imagesListWidget->takeItem(ui.imagesListWidget->row(listWidgetItem))));
	}
}

void ManageImagesDialog::onAddPush(bool checked /*= false*/)
{
	lockInput();
	const QString& fileName = QFileDialog::getOpenFileName(this, tr("Choose an Image"), ".", tr("Image Files (*.png *.jpg *.bmp)"));
	const QPixmap& img(fileName);
	AddImage(img, fileName);
}

void ManageImagesDialog::onProjectRequestFinished(NetworkReplyWrapper* networkReplyWrapper)
{
	lockInput();
	const QString& projectJson = getProjectReply->getBody();
	const Project& project = Project::fromJson(projectJson);
	const QList<Image>& imagesList = *project.getImages();

	imageRequestReplies.clear();
	for (Image img : imagesList) {
		NetworkReplyWrapper* reply = new NetworkReplyWrapper(this);
		reply->setNetworkReply(projectManager->getImage(img.getUrl()));
		reply->addData("id", img.getId());
		connect(reply, &NetworkReplyWrapper::finishedProcessing, this, &ManageImagesDialog::onImageProjectRequestFinished, Qt::UniqueConnection);
		imageRequestReplies.append(QSharedPointer<NetworkReplyWrapper>(reply));
	}
}

void ManageImagesDialog::onImageProjectRequestFinished(NetworkReplyWrapper* networkReplyWrapper)
{
	QByteArray imageBytes = networkReplyWrapper->getBody();
	QPixmap pixMap;
	pixMap.loadFromData(imageBytes);
	AddImage(pixMap, networkReplyWrapper->getData("id"));
}

void ManageImagesDialog::onImageUploadRequestFinished(PortefolioManagerUtilities::NetworkReplyWrapper* networkReplyWrapper)
{
	qDebug() << "Status : " << networkReplyWrapper->getStatusCode();
	qDebug() << networkReplyWrapper->getMessage();
	qDebug() << networkReplyWrapper->getBody();
}

void ManageImagesDialog::onImageDeleteRequestFinished(PortefolioManagerUtilities::NetworkReplyWrapper* networkReplyWrapper)
{
	qDebug() << "Status : " << networkReplyWrapper->getStatusCode();
	qDebug() << networkReplyWrapper->getMessage();
	qDebug() << networkReplyWrapper->getBody();
}