#pragma once

#include <QDialog>
#include "ui_ProjectManageImages.h"
#include "Image.h"

namespace PortefolioManagerUtilities {
	class ProjectManager;
	class NetworkReplyWrapper;
};

class ManageImagesDialog : public QDialog
{
	Q_OBJECT

public:
	ManageImagesDialog(QWidget *parent = Q_NULLPTR, PortefolioManagerUtilities::ProjectManager* projectManager = Q_NULLPTR);
	void clearImages();
	void AddImage(QPixmap imageMap);
	void getImages(const QString& projectId);
	void setToken(const QString& token);
	void setIsAdmin(bool isAdmin);

	void lockInput();
	void unlockInput();
private:
	Ui::ManageImagesDialog ui;
	PortefolioManagerUtilities::ProjectManager* projectManager; // This class is not the parent of this ProjectManager !
	bool isAdmin;
	QString token;

	PortefolioManagerUtilities::NetworkReplyWrapper* getProjectReply;
	QList<QSharedPointer<PortefolioManagerUtilities::NetworkReplyWrapper>> imageRequestReplies;
private slots:
	void onAccept(bool checked = false);
	void onReject(bool checked = false);
	void onDeletePush(bool checked = false);
	void onAddPush(bool checked = false);
	void onProjectRequestFinished(PortefolioManagerUtilities::NetworkReplyWrapper* networkReplyWrapper);
	void onImageProjectRequestFinished(PortefolioManagerUtilities::NetworkReplyWrapper* networkReplyWrapper);
};
