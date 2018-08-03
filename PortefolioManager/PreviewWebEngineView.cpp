#include "PreviewWebEngineView.h"

#include <QTimer>
#include <iostream>

PreviewWebEngineView::PreviewWebEngineView(QWidget *parent)
	: QWebEngineView(parent),
	baseUrl(QUrl("https://arthur-joly.fr")),
	readyTimer(new QTimer(this)),
	readyCheckTimeout(100),
	ready(false)
{
	ui.setupUi(this);
	connect(this, &QWebEngineView::urlChanged,this, &PreviewWebEngineView::onUrlChanged);
	connect(readyTimer.data(), &QTimer::timeout, this, &PreviewWebEngineView::onReadyTimerTimeout);
}

void PreviewWebEngineView::init()
{
	setUrl(baseUrl);
}

bool PreviewWebEngineView::setHtmlTagContent(const QString& selector, const QString& newContent) const
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

bool PreviewWebEngineView::getHtmlTagContent(const QString& selector, const QWebEngineCallback<const QVariant&> callback) const
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

QString PreviewWebEngineView::getPath() const
{
	return url().path();
}

void PreviewWebEngineView::onReadyTimerTimeout()
{
	page()->runJavaScript(
		"var desc = document.querySelector('#projectDescription');(desc ? 'OK' : '')",
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
		emit isNotReady();
		readyTimer->start(readyCheckTimeout);
	}
	else {
		ready = true;
		emit isNotReady();
	}
}
