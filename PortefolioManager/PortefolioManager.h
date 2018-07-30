#pragma once

#include "ui_PortefolioManager.h"

class PortefolioManager : public QMainWindow
{
	Q_OBJECT

public:
	PortefolioManager(QWidget *parent = Q_NULLPTR);
	QString html;

private:
	Ui::PortefolioManagerClass ui;
	QTimer *updateTimer;

private slots:
	void onTogglePreview(bool checked = false) const;
	void onRefreshPreview(bool checked = false) const;
	void onPageLoadFinished(bool status) const;
	void onUrlChanged(const QUrl& newUrl) const;
	void onUpdateTimeout() const;


	void onBoldTriggered(bool checked = false) const;
	void onItalicTriggered(bool checked = false) const;
	void onUnderlineTriggered(bool checked = false) const;
};
