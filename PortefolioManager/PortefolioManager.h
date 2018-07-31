#pragma once

#include <QSharedPointer>

#include "ui_PortefolioManager.h"
#include "LoginDialog.h"
#include "ProjectSettingsDialog.h"

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
	QSharedPointer<LoginDialog> loginDialog;

	/*! The project settings Dialog*/
	QSharedPointer<ProjectSettingsDialog> projectSettingsDialog;

	/*! Is the user logged in ?*/
	bool loggedIn;

	/*!	A timer needed to delay the execution of the javascript description check.
	 *	\sa http://doc.qt.io/qt-5/qtimer.html
	 */
	QSharedPointer<QTimer> updateTimer;
	

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

	/*!	Triggered when the loadFinished page signal has been triggered.
	 *	\param status Has the page finished to load ?
	 */
	void onPageLoadFinished(bool status) const;

	/*!	Triggered when the urlChanged page signal has been triggered.
	 *	\param newUrl The new QUrl.
	 *	\sa http://doc.qt.io/qt-5/qurl.html
	 */
	void onUrlChanged(const QUrl& newUrl) const;

	/*!	Triggered when the timer signal timeout has been triggered.
	 *	Used to replace the HTML editor by the content of the web page projectDescription tag.
	 */
	void onUpdateTimeout() const;

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

	/*!	Triggered when creating a new project and the projectSettingsDialog accepted signal has been triggered.  */
	void onNewProjectSettingsDialogAccepted();
	
	/*!	Triggered when the action actionProjectSettings has been triggered.
	 *	\param checked Not used. Checks if the trigger is active.
	 */
	void onProjectSettingsTriggered(bool checked = false) const;

	/*!	Triggered when in project settings and the projectSettingsDialog accepted signal has been triggered.  */
	void onProjectSettingsDialogAccepted();
};
