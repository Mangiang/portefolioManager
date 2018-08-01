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

	void setTitle(const QString&);
	void setBeginDate(const QString&);
	void setBeginDate(const QDate&);
	void setEndDate(const QString&);
	void setEndDate(const QDate&);
	void setSmallDescription(const QString&);
	void setDescription(const QString&);
	QString getTitle() const;
	QDate getBeginDate() const;
	QDate getEndDate() const;
	QString getSmallDescription() const;
	QString getDescription() const;
private:
	QString dateFormat;
	QString title;
	QDate beginDate;
	QDate endDate;
	QString smallDescription;
	QString description;
};

