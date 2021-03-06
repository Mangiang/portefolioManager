#include "Project.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

Project::Project():
	images(new QList<Image>()),
	dateFormat("MM/dd/yyyy")
{ }

void Project::getValuesFromProject(const Project& otherProject)
{
	setId(otherProject.getId());
	setTitle(otherProject.getTitle());
	setBeginDate(otherProject.getBeginDate());
	setEndDate(otherProject.getEndDate());
	setSmallDescription(otherProject.getSmallDescription());
	setDescription(otherProject.getDescription());
	setStatus(otherProject.getStatus());
	setImages(otherProject.getImages());
}

Project Project::fromJson(const QString& data)
{
	Project project;

	QJsonObject obj;
	QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8());
	if (!doc.isNull())
	{
		if (doc.isObject())
		{
			obj = doc.object();
		}
		else
		{
			qDebug() << "Document is not an object";
			return project;
		}
	}
	else
	{
		qDebug() << "Invalid JSON...";
		qDebug() << "Received : " << data;
		return project;
	}

	const QVariantMap& objectMap = obj.toVariantMap();

	project.setId(objectMap["id"].toString());
	project.setTitle(objectMap["title"].toString());
	project.setBeginDate(objectMap["beginDate"].toString());
	project.setEndDate(objectMap["endDate"].toString());
	project.setSmallDescription(objectMap["smallDescription"].toString());
	project.setDescription(objectMap["description"].toString());
	project.setStatus(objectMap["status"].toInt());
	
	
	const QVariantList& imageList = objectMap["images"].toList();
	project.images->clear();
	for (QVariant var : imageList) {
		const QVariantMap& imageMap = var.toMap();
		project.images->append(Image(imageMap["id"].toString(), imageMap["url"].toString()));
	}

	return project;
}

QString Project::toJson() const
{
	QLocale locale = QLocale(QLocale::English);
	const QString& beginDateString = getBeginDate().toString(getDateFormat());
	const QString& endDateString = getEndDate().toString(getDateFormat());
	return QString("{title:'%1',beginDate:'%2',endDate:'%3', smallDescription:'%4', description:'%5', status: '%6'}")
		.arg(getTitle()).arg(beginDateString).arg(endDateString).arg(getSmallDescription()).arg(getDescription()).arg(status);
}

void Project::setBeginDate(const QString& newDate)
{
	setBeginDate(QDate::fromString(newDate, getDateFormat()));
}

void Project::setEndDate(const QString& newDate)
{
	setEndDate(QDate::fromString(newDate, getDateFormat()));
}

QHash<QString, QString> Project::toHash() const
{
	QHash<QString, QString> projectHash;
	projectHash.insert("title", getTitle());
	projectHash.insert("beginDate", getBeginDate().toString(getDateFormat()));
	projectHash.insert("endDate", getEndDate().toString(getDateFormat()));
	projectHash.insert("smallDescription", getSmallDescription());
	projectHash.insert("description", getDescription());
	projectHash.insert("status", QString::number(getStatus()));

	return projectHash;
}

QHash<QString, QString> Project::toHashSettings() const
{
	QHash<QString, QString> projectHash;
	projectHash.insert("title", getTitle());
	projectHash.insert("beginDate", getBeginDate().toString(getDateFormat()));
	projectHash.insert("endDate", getEndDate().toString(getDateFormat()));
	projectHash.insert("smallDescription", getSmallDescription());
	projectHash.insert("status", QString::number(getStatus()));

	return projectHash;
}