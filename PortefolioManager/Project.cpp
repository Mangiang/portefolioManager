#include "Project.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

Project::Project():
	dateFormat("MM/dd/yyyy")
{
}

void Project::getValuesFromProject(const Project& otherProject)
{
	setTitle(otherProject.title);
	setBeginDate(otherProject.beginDate);
	setBeginDate(otherProject.endDate);
	setSmallDescription(otherProject.smallDescription);
	setDescription(otherProject.description);
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
			qDebug() << "Document is not an object" << endl;
			return project;
		}
	}
	else
	{
		qDebug() << "Invalid JSON..." << endl;
		return project;
	}

	const QVariantMap& objectMap = obj.toVariantMap();

	project.setTitle(objectMap["title"].toString());
	project.setBeginDate(objectMap["beginDate"].toString());
	project.setEndDate(objectMap["endDate"].toString());
	project.setSmallDescription(objectMap["smallDescription"].toString());
	project.setDescription(objectMap["description"].toString());

	return project;
}

QString Project::toJson() const
{
	QLocale locale = QLocale(QLocale::English);
	const QString& beginDateString = beginDate.toString(dateFormat);
	const QString& endDateString = endDate.toString(dateFormat);
	return QString("{title:'%1',beginDate:'%2',endDate:'%3', smallDescription:'%4', description:'%5'}")
		.arg(title).arg(beginDateString).arg(endDateString).arg(smallDescription).arg(description);
}

#pragma region Setters/Getters
void Project::setTitle(const QString& newName)
{
	title = newName;
}

void Project::setBeginDate(const QString& newDate)
{
	beginDate = QDate::fromString(newDate, dateFormat);
}

void Project::setBeginDate(const QDate& newDate)
{
	beginDate = newDate;
}

void Project::setEndDate(const QString& newDate)
{
	endDate = QDate::fromString(newDate, dateFormat);
}

void Project::setEndDate(const QDate& newDate)
{
	endDate = newDate;
}

void Project::setSmallDescription(const QString& newDescription)
{
	smallDescription = newDescription;
}

void Project::setDescription(const QString& newDescription)
{
	description = newDescription;
}

QString Project::getTitle() const
{
	return title;
}

QDate Project::getBeginDate() const
{
	return beginDate;
}

QDate Project::getEndDate() const
{
	return endDate;
}

QString Project::getSmallDescription() const
{
	return smallDescription;
}

QString Project::getDescription() const
{
	return description;
}

#pragma endregion