#include "PortefolioManager.h"

#include <QTimer>
#include <QtWidgets/QMainWindow>

#include "PortefolioManagerUtilities.h"

PortefolioManager::PortefolioManager(QWidget *parent)
	: QMainWindow(parent),
	updateTimer(new QTimer(this))
{
	ui.setupUi(this);
	

	// MenuBar actions
	connect(ui.actionRefresh, SIGNAL(triggered(bool)), SLOT(onRefreshPreview(bool)));
	connect(ui.actionToggle_Preview, SIGNAL(triggered(bool)), SLOT(onTogglePreview(bool)));

	// ToolBar actions
	connect(ui.actionBold, SIGNAL(triggered(bool)), SLOT(onBoldTriggered(bool)));
	connect(ui.actionItalic, SIGNAL(triggered(bool)), SLOT(onItalicTriggered(bool)));
	connect(ui.actionUnderline, SIGNAL(triggered(bool)), SLOT(onUnderlineTriggered(bool)));

	// Other actions
	connect(ui.webEngineView, SIGNAL(loadFinished(bool)), SLOT(onPageLoadFinished(bool)));
	connect(ui.webEngineView, SIGNAL(urlChanged(const QUrl&)), SLOT(onUrlChanged(const QUrl&)));
	connect(ui.webEngineView, SIGNAL(urlChanged(const QUrl&)), SLOT(onUrlChanged(const QUrl&)));
	connect(updateTimer, SIGNAL(timeout()), this, SLOT(onUpdateTimeout()));


	ui.webEngineView->setUrl(QUrl("https://arthur-joly.fr"));
}

void PortefolioManager::onTogglePreview(bool checked /*= false*/) const
{
	ui.previewDockWidget->setVisible(!ui.previewDockWidget->isVisible());
	ui.previewDockWidget->setFloating(true);
}

void PortefolioManager::onRefreshPreview(bool checked /*= false*/) const
{
	//ui.webEngineView->setHtml(ui.contentPlainTextEdit->toPlainText());
	ui.webEngineView->page()->runJavaScript(
		QString("var desc = document.getElementById('projectDescription'); "
			"if (desc) "
			"	desc.innerHTML = '%1'; ").arg(ui.contentPlainTextEdit->toPlainText()));

}

void PortefolioManager::onPageLoadFinished(bool status) const
{
	if (status)
	{
		// Add a timer because PageLoadFinished is not always perfectly finished
		updateTimer->start(500);
	}
}

void PortefolioManager::onUrlChanged(const QUrl& newUrl) const
{
	ui.webEngineView->setUrl(newUrl);
}

void PortefolioManager::onUpdateTimeout() const
{
		ui.webEngineView->page()->toHtml([](const QString& result) {qDebug() << result; });
		ui.webEngineView->page()->runJavaScript(
			"var desc = document.getElementById('projectDescription');"
			"(desc ? desc.innerHTML :'')",
			[this](const QVariant &v) { 
			qDebug() << v.toString(); 
			ui.contentPlainTextEdit->clear(); 
			ui.contentPlainTextEdit->appendPlainText(v.toString()); 
		});
		updateTimer->stop();
}

void PortefolioManager::onBoldTriggered(bool checked /*= false*/) const
{
	QTextCursor cursor = ui.contentPlainTextEdit->textCursor();
	PortefolioManagerUtilities::wrapText(cursor, "b");
}

void PortefolioManager::onItalicTriggered(bool checked /*= false*/) const
{
	QTextCursor cursor = ui.contentPlainTextEdit->textCursor();
	PortefolioManagerUtilities::wrapText(cursor, "i");
}

void PortefolioManager::onUnderlineTriggered(bool checked /*= false*/) const
{
	QTextCursor cursor = ui.contentPlainTextEdit->textCursor();
	PortefolioManagerUtilities::wrapText(cursor, "u");
}