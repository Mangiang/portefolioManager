#pragma once

#include "ui_PortefolioManager.h"
#include "LoginDialog.h"

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

	/*! The logTextEdit*/
	static QPlainTextEdit* logTextEdit;

	/*! Does the log window autoscroll ?*/
	static bool logAutoScroll;

	/*! The method used to override the message handler*/
	static void customMessageHandler(QtMsgType, const QMessageLogContext&, const QString&);

private:
	/*!	The UI. */
	Ui::PortefolioManagerClass ui;

	/*! The login Dialog*/
	LoginDialog* loginDialog;

	/*! Is the user logged in ?*/
	bool loggedIn;

	/*!	A timer needed to delay the execution of the javascript description check.
	 *	\sa http://doc.qt.io/qt-5/qtimer.html
	 */
	QTimer *updateTimer;
	

private slots:
	/*!	Triggered when the showLogin action has been triggered.  */
	void onLoginDialogShow(bool checked = false);
	
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
};
