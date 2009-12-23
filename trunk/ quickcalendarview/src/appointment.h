/*******************************************************************************

    Copyright (C) 2008 Jukka-Pekka M�kel�.
    Contact: jpm@mehteenit.net

    This file is part of QuickCalendar.

    Foobar is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Foobar is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with QuickCalendar.  If not, see <http://www.gnu.org/licenses/>.

*******************************************************************************/

#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <QDate>
#include <QDateTime>
#include <QMetaType>
#include <QString>
#include <QTime>

class Calendar;

///������� ����� ��� �������� ���������� � ��������
class Appointment 
{
public:
	///������ �����������, ������������� ����� myKey � ptrCalendar 0
    Appointment() : myKey(0), ptrCalendar(0) {}
    ~Appointment() {} ///<������ ����������

    int key() const {return myKey;} ///<����� ������ ���� ����
    void setKey(int key) {myKey = key;} ///<����� ������ ���� ����

    int calendarKey() const {return myCalendarKey;} ///<����� ������ ���� myCalendarKey
    void setCalendarKey(int calendarKey) {myCalendarKey = calendarKey;} ///<����� ������ ���� myCalendarKey

    Calendar* calendar() const {return ptrCalendar;} ///<����� ������ ��������� �� ���������
    void setCalendar(Calendar *calendar) {ptrCalendar = calendar;} ///<����� ������ ��������� �� ���������

    QString subject() const {return mySubject;} ///<����� ������ ���� mySubject
    void setSubject(const QString &subject) {mySubject = subject;} ///<����� ������ ���� mySubject

    QString place() const {return myPlace;} ///<����� ������ ����� �������
	void setPlace(const QString &place) {myPlace = place;} ///<����� ������ ����� �������

    QString description() const {return myDescription;} ///<����� ������ ��������
    void setDescription(const QString &description) {myDescription = description;} ///<����� ��������� ��������

    QTime startTime() const { return myStartDateTime.time(); } ///<����� ������ ������� ������ �������
    QDate startDate() const { return myStartDateTime.date(); } ///<����� ������ ���� ������ �������
    QDateTime startDateTime() const {return myStartDateTime;} ///<����� ������ ���� � ������� ������ �������
    void setStartDateTime(const QDateTime &startDateTime); ///<����� ������ ���� � ������� ������ �������

    QTime endTime() const { return myEndDateTime.time(); } ///<����� ������ ������� ��������� �������
    QDate endDate() const { return myEndDateTime.date(); } ///<����� ������ ���� ��������� �������
    QDateTime endDateTime() const {return myEndDateTime; } ///<����� ������ ���� � ������� ��������� �������
    void setEndDateTime(const QDateTime &endDateTime); ///<����� ������ ���� � ������� ��������� �������

	///����� ��������� ���� � ������� ������ � ��������� �������.
    void setDateTimes(const QDateTime &startDateTime, const QDateTime &endDateTime);
	///����� ��������� ������� ������ � ��������� �������
    void setTimes(const QTime &startTime, const QTime &endTime); 

	///����� ������ ����� �������� ����, � ������� ��������� �������
    int startQuater(const QDate &date) const;
	///����� ������ ����� �������� ����, � ������� ���������� �������
    int endQuater(const QDate &date) const;

	///����� ������ true, ���� ������� app1 �������� ������ app2
    static bool before(Appointment *app1, Appointment *app2);

    bool operator==(const Appointment &other) const; ///<�������� ==
    bool operator!=(const Appointment &other) const; ///<�������� !=
    bool operator<(const Appointment &other) const; ///<�������� <

private:
    int myKey; ///<����. ����� 0, ���� ������� �� ����������� ���������. ����� �������� ���������� �����.
    int myCalendarKey; ///<��� ���� ����. ����� �� ������������.

    Calendar *ptrCalendar; ///<��������� �� ���������, �������� ����������� �������

    QString mySubject; ///<���� ������� ��� �������, � ������� ��������� �������.
    QString myPlace; ///<����� �������
    QString myDescription;///<�������� �������

    QDateTime myStartDateTime; ///<���� � ����� ������ �������
    QDateTime myEndDateTime;   ///<���� � ����� ��������� �������
};

Q_DECLARE_METATYPE(Appointment) ///<���������� ����-������

#endif
