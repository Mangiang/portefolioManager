#include "PreviewWebEngineView.h"

#include <QTimer>

PreviewWebEngineView::PreviewWebEngineView(QWidget *parent)
	: QWebEngineView(parent),
	baseUrl(QUrl("https://arthur-joly.fr")),
	readyTimer(new QTimer(this)),
	readyCheckTimeout(100),
	ready(false)
{
	ui.setupUi(this);
	connect(this, SIGNAL(urlChanged(const QUrl&)), SLOT(onUrlChanged(const QUrl&)));
	connect(readyTimer.data(), SIGNAL(timeout()), this, SLOT(onReadyTimerTimeout()));
}

PreviewWebEngineView::~PreviewWebEngineView()
{
}

void PreviewWebEngineView::init()
{
	setUrl(baseUrl);
}

bool PreviewWebEngineView::setContent(const QString& selector, const QString& newContent) const
{
	if (!ready) {
		qCritical() << "Page not ready yet.";
		return false;
	}

	page()->runJavaScript(
		QString("var desc = document.querySelector('%1'); "
			"if (desc) "
			"	desc.innerHTML = '%2'; ").arg(selector).arg(newContent));
	return true;
}

bool PreviewWebEngineView::getContent(const QString& selector, const QWebEngineCallback<const QVariant&> callback) const
{
	if (!ready) {
		qCritical() << "Page not ready yet.";
		return false;
	}

	page()->runJavaScript(
		QString("var desc = document.querySelector('%1');(desc ? desc.innerHTML :'')").arg(selector),
		callback);
	return true;
}

void PreviewWebEngineView::onReadyTimerTimeout()
{
	page()->runJavaScript(
		"var desc = document.querySelector('#projectDescription'); (desc ? desc.innerHTML : '')",
		[this](const QVariant &v) {
		if (!v.toString().isEmpty())
		{
			ready = true;
			emit isReady();
		}
		else
			readyTimer->start(readyCheckTimeout);
	});
	readyTimer->stop();
}

void PreviewWebEngineView::onUrlChanged(const QUrl& newUrl)
{
	if (newUrl.path().contains("project"))
	{
		ready = false;
		readyTimer->start(readyCheckTimeout);
	}
	else
		ready = true;
}
