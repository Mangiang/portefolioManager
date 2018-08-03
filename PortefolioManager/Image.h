#pragma once

#include <QString>

class Image
{
public:
	Image(QString id, QString url) { this->setId(id); this->setUrl(url); };
	
	QString getId() const { return id; }
	void setId(QString val) { id = val; }
	QString getUrl() const { return url; }
	void setUrl(QString val) { url = val; }
private:
	QString id;
	QString url;
};

