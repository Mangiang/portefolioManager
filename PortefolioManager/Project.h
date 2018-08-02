#pragma once

#include <QString>
#include <QDate>

class Project
{
public:
	Project();
	void getValuesFromProject(const Project&);
	static Project fromJson(const QString&);
	QString toJson() const;

	QString getId() const { return Id; }
	void setId(const QString& val) { Id = val; }
	QString getDateFormat() const { return dateFormat; }
	QString getTitle() const { return title; }
	void setTitle(const QString& val) { title = val; }
	QDate getBeginDate() const { return beginDate; }
	void setBeginDate(const QDate& val) { beginDate = val; }
	void setBeginDate(const QString&);
	QDate getEndDate() const { return endDate; }
	void setEndDate(const QDate& val) { endDate = val; }
	void setEndDate(const QString&);
	QString getSmallDescription() const { return smallDescription; }
	void setSmallDescription(const QString& val) { smallDescription = val; }
	QString getDescription() const { return description; }
	void setDescription(const QString& val) { description = val; }

	QHash<QString, QString> toHash() const;
	QHash<QString, QString> toHashSettings() const;
private:
	QString Id;
	QString dateFormat;
	QString title;
	QDate beginDate;
	QDate endDate;
	QString smallDescription;
	QString description;
};

