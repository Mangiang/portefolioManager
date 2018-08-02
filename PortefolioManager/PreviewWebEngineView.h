#pragma once

#include <QWebEngineView>
#include "ui_PreviewWebEngineView.h"

class PreviewWebEngineView : public QWebEngineView
{
	Q_OBJECT

public:
	PreviewWebEngineView(QWidget *parent = Q_NULLPTR);

	void init();
	bool setHtmlTagContent(const QString& selector, const QString& newContent) const;
	bool getHtmlTagContent(const QString& selector, const QWebEngineCallback<const QVariant&> callback) const;
	QString getPath() const;
private:
	Ui::PreviewWebEngineView ui;
	const QUrl baseUrl;
	const int readyCheckTimeout;
	bool ready;
	
	/*!	A timer needed to delay the execution of the javascript description check.
	 *	\sa http://doc.qt.io/qt-5/qtimer.html
	 */
	QSharedPointer<QTimer> readyTimer;

private slots:
	void onReadyTimerTimeout();
	void onUrlChanged(const QUrl&);

signals:
	void isReady() const;
	void isNotReady() const;
};
