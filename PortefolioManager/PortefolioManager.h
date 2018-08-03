#pragma once

#include "ui_PortefolioManager.h"
#include <QSharedPointer>

class LoginDialog;
class ProjectSettingsDialog;
class User;
class ManageImagesDialog;

namespace PortefolioManagerUtilities {
	class ProjectManager;
}

/*!	\class PortefolioManager
 * 	\brief The QMainWindow holding the tool together.
 * 	\sa http://doc.qt.io/qt-5/qmainwindow.html
 */
class PortefolioManager : public QMainWindow
{
	Q_OBJECT

public:
	/*!	The Constructor. */
	PortefolioManager(QWidget *parent = Q_NULLPTR);

	/*!	The inner HTML of the projectDescription. */
	QString descriptionHtml;

	/*! Called when closing the window */
	void closeEvent(QCloseEvent *event);
private:
	/*!	The UI. */
	Ui::PortefolioManagerClass ui;

	/*! The login Dialog*/
	LoginDialog* loginDialog;

	/*! The project settings Dialog*/
	ProjectSettingsDialog* projectSettingsDialog;

	/*! The project network manager 
	 */
	PortefolioManagerUtilities::ProjectManager* projectManager;
	
	/*! The manage image Dialog */
	ManageImagesDialog* manageImagesDialog;

	/*! Is the user logged in ?*/
	bool loggedIn;
	
	/*! The user informations ?*/
	QSharedPointer<User> user;

	/*! Get the id based on the WebEngineView url*/
	QString getCurrentProjectID() const;
private slots:
	/*!	Triggered when the loginDialog accepted signal has been triggered.  
	 *	Used to save the new user informations.
	 */
	void onLoginDialogAccepted();

	/*!	Triggered when the action actionTogglePreview has been triggered.
	 *	Display the preview dockable window.
	 *	\param checked Not used. Checks if the trigger is active.
	 */
	void onTogglePreview(bool checked = false) const;

	/*!	Triggered when the action actionToggleLog has been triggered.
	 *	Display the logger dockable window.
	 *	\param checked Not used. Checks if the trigger is active.
	 */
	void onToggleLog(bool checked = false) const;
	
	/*!	Triggered when the action actionRefresh has been triggered.
	 *	Apply the textEdit value in the project content preview.
	 *	\param checked Not used. Checks if the trigger is active.
	 */
	void onRefreshPreview(bool checked = false) const;

	/*!	Triggered when the previewWebEngine isReady signal has been triggered.
	 *	Unlocks inputs when not on a project page.
	 *	Used to replace the HTML editor by the content of the web page projectDescription tag.
	 */
	void onPageReady() const;
	
	/*!	Triggered when the previewWebEngine isNotReady signal has been triggered.
	 *	Locks inputs when not on a project page.
	 *	Used to replace the HTML editor by the content of the web page projectDescription tag.
	 */
	void onPageNotReady() const;

	/*!	Triggered when the action bold has been triggered.
	 *	Surround the selected text with bold <b></b> tags.
	 *	\param checked Not used. Checks if the trigger is active.
	 */
	void onBoldTriggered(bool checked = false) const;

	/*!	Triggered when the action italic has been triggered.
	 *	Surround the selected text with italic <i></i> tags.
	 *	\param checked Not used. Checks if the trigger is active.
	 */
	void onItalicTriggered(bool checked = false) const;

	/*!	Triggered when the action underline has been triggered.
	 *	Surround the selected text with underline <u></u> tags.
	 *	\param checked Not used. Checks if the trigger is active.
	 */
	void onUnderlineTriggered(bool checked = false) const;
	
	/*!	Triggered when the action sendContent has been triggered.
	 *	Send the content of the PlainTextEdit to the server
	 *	\param checked Not used. Checks if the trigger is active.
	 */
	void onSendContentTriggered(bool checked = false) const;
	
	/*!	Triggered when the action AddImages has been triggered.
	 *	Open the manageImages window
	 *	\param checked Not used. Checks if the trigger is active.
	 */
	void onManageImages(bool checked = false) const;
	
	/*!	Triggered when the action actionNewProject has been triggered.
	 *	Display the ProjectSettingsDialog.
	 *	\param checked Not used. Checks if the trigger is active.
	 */
	void onNewProjectTriggered(bool checked = false) const;
	
	/*!	Triggered when the action actionProjectSettings has been triggered.
	 *	Displays the ProjectSettingsDialog with the current project informations.
	 *	\param checked Not used. Checks if the trigger is active.
	 */
	void onProjectSettingsTriggered(bool checked = false) const;
	
	/*!	Triggered when the projectSettings accepted signal has been triggered.  
	 *	Reloads the preview in case displayed informations have changed.
	 */
	void onProjectSettingsAccepted();

	/*!	Triggered when the projectManager requestFinish signal has been triggered.  
	 *	Reloads the preview in case displayed informations have changed.
	 */
	void onUpdateFinished();
};
