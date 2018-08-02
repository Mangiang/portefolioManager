#pragma once

#include <QString>

class User
{
public:
	User();
	User(const User& user);
	static User fromJson(const QString&);

	QString getFirstname() const { return firstname; }
	void setFirstname(const QString& val) { firstname = val; }
	QString getLastname() const { return lastname; }
	void setLastname(const QString& val) { lastname = val; }
	QString getPhone() const { return phone; }
	void setPhone(const QString& val) { phone = val; }
	QString getToken() const { return token; }
	void setToken(const QString& val) { token = val; }
	bool getAdmin() const { return admin; }
	void setAdmin(bool val) { admin = val; }
private:
	QString firstname;
	QString lastname;
	QString phone;
	QString token;
	bool admin;
};