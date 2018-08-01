#pragma once

#include "ui_PortefolioManager.h"

class LoginDialog;
class ProjectSettingsDialog;

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

private:
	/*!	The UI. */
	Ui::PortefolioManagerClass ui;

	/*! The login Dialog*/
	LoginDialog* loginDialog;

	/*! The project settings Dialog*/
	ProjectSettingsDialog* projectSettingsDialog;

	/*! The project network manager */
	PortefolioManagerUtilities::ProjectManager* projectManager;

	/*! Is the user logged in ?*/
	bool loggedIn;
	

private slots:
	/*!	Triggered when the loginDialog accepted signal has been triggered.  */
	void onLoginDialogAccepted();

	/*!	Triggered when the loginDialog rejected signal has been triggered.  */
	void onLoginDialogRejected();

	/*!	Triggered when the action actionTogglePreview has been triggered.
	 *	\param checked Not used. Checks if the trigger is active.
	 */
	void onTogglePreview(bool checked = false) const;

	/*!	Triggered when the action actionToggleLog has been triggered.
	 *	\param checked Not used. Checks if the trigger is active.
	 */
	void onToggleLog(bool checked = false) const;
	
	/*!	Triggered when the action actionRefresh has been triggered.
	 *	\param checked Not used. Checks if the trigger is active.
	 */
	void onRefreshPreview(bool checked = false) const;

	/*!	Triggered when the previewWebEngine isReady signal has been triggered.
	 *	Used to replace the HTML editor by the content of the web page projectDescription tag.
	 */
	void onPageReady() const;
	
	/*!	Triggered when the previewWebEngine isNotReady signal has been triggered.
	 *	Used to replace the HTML editor by the content of the web page projectDescription tag.
	 */
	void onPageNotReady() const;

	/*!	Triggered when the action bold has been triggered.
	 *	\param checked Not used. Checks if the trigger is active.
	 */
	void onBoldTriggered(bool checked = false) const;

	/*!	Triggered when the action italic has been triggered.
	 *	\param checked Not used. Checks if the trigger is active.
	 */
	void onItalicTriggered(bool checked = false) const;

	/*!	Triggered when the action underline has been triggered.
	 *	\param checked Not used. Checks if the trigger is active.
	 */
	void onUnderlineTriggered(bool checked = false) const;
	
	/*!	Triggered when the action actionNewProject has been triggered.
	 *	\param checked Not used. Checks if the trigger is active.
	 */
	void onNewProjectTriggered(bool checked = false) const;
	
	/*!	Triggered when the action actionProjectSettings has been triggered.
	 *	\param checked Not used. Checks if the trigger is active.
	 */
	void onProjectSettingsTriggered(bool checked = false) const;
};
