#pragma once

#include "ui_PortefolioManager.h"

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

	/*!	A timer needed to delay the execution of the javascript description check. 
     *	\sa http://doc.qt.io/qt-5/qtimer.html	 
	 */
	QTimer *updateTimer;

private slots:
	/*!	Triggered when the action actionToggle_Preview has been triggered.
	 *	\param checked Not used. Checks if the trigger is active. 
	 */
	void onTogglePreview(bool checked = false) const;

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

	/*!	Triggered when the timer signal timeout has been triggered. */
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
