#pragma once

#include <QDialog>
#include "ui_ProjectManageImages.h"
#include "Image.h"

namespace PortefolioManagerUtilities {
	class ProjectManager;
};

class ManageImagesDialog : public QDialog
{
	Q_OBJECT

public:
	ManageImagesDialog(QWidget *parent = Q_NULLPTR);
	void clearImages();
	void AddImage(QPixmap imageMap) const;
	void getImages(const QString& projectId);
	void setToken(const QString& token);
	void setIsAdmin(bool isAdmin);

	void lockInput();
	void unlockInput();
private:
	Ui::ManageImagesDialog ui;
	PortefolioManagerUtilities::ProjectManager* projectManager; // This class is nor the owner nor the parent of this pointer
	bool isAdmin;
	QString token;
private slots:
	void onAccept(bool checked = false);
	void onReject(bool checked = false);
	void onDeletePush(bool checked = false);
	void onAddPush(bool checked = false);
	void onProjectRequestFinished();
	void onImageProjectRequestFinished();
};
