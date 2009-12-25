/*******************************************************************************

    Copyright (C) 2008 Jukka-Pekka Mдkelд.
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

/**
* @class Appointment
* @brief Базовый класс для хранения информации о встречах
*/ 

/**
Пример использования:
@code
    Appointment *app = new Appointment();
    app->setDateTimes(QDateTime(QDate(2008,12,23),QTime(19,0,0)),
                     QDateTime(QDate(2008,12,23),QTime(23,0,0)));

    app->setSubject("Holiday party!");
    app->setPlace("Secret place"); 
    app->setDescription("Secret holiday party at secret place. Everybody is welcome!");

    Calendar *cal = new Calendar(0);
    cal->insertAppointment(app); 
@endcode
Создаем объект класса Appointment. Методом setDateTimes()задаем время начала и окончания встречи.
Предмет встречи позволяет установить метод setSubject(), место встречи - метод setPlace(), а метод
setDescription() задает ее описание.
Создаем объект класса Calendar. Добавляем созданную встречу к календарю вызовом insertAppointment().
*/
class Appointment 
{
public:
	///Пустой конструктор, инициализация полей myKey и ptrCalendar 0
    Appointment() : myKey(0), ptrCalendar(0) {}
    ~Appointment() {} ///<Пустой деструктор

    int key() const {return myKey;} ///<Метод чтения поля ключ
    void setKey(int key) {myKey = key;} ///<Метод записи поля ключ

    int calendarKey() const {return myCalendarKey;} ///<Метод чтения поля myCalendarKey
    void setCalendarKey(int calendarKey) {myCalendarKey = calendarKey;} ///<Метод записи поля myCalendarKey

    Calendar* calendar() const {return ptrCalendar;} ///<Метод чтения указателя на календарь
    void setCalendar(Calendar *calendar) {ptrCalendar = calendar;} ///<Метод записи указателя на календарь

    QString subject() const {return mySubject;} ///<Метод чтения поля mySubject
    void setSubject(const QString &subject) {mySubject = subject;} ///<Метод записи поля mySubject

    QString place() const {return myPlace;} ///<Метод чтения места встречи
	void setPlace(const QString &place) {myPlace = place;} ///<Метод записи места встречи

    QString description() const {return myDescription;} ///<Метод чтения описания
    void setDescription(const QString &description) {myDescription = description;} ///<Метод установки описания

    QTime startTime() const { return myStartDateTime.time(); } ///<Метод чтения времени начала встречи
    QDate startDate() const { return myStartDateTime.date(); } ///<Метод чтения даты начала встречи
    QDateTime startDateTime() const {return myStartDateTime;} ///<Метод чтения даты и времени начала встречи
    void setStartDateTime(const QDateTime &startDateTime); ///<Метод записи даты и времени начала встречи

    QTime endTime() const { return myEndDateTime.time(); } ///<Метод чтения времени окончания встречи
    QDate endDate() const { return myEndDateTime.date(); } ///<Метод чтения даты окончания встречи
    QDateTime endDateTime() const {return myEndDateTime; } ///<Метод чтения даты и времени окончания встречи
    void setEndDateTime(const QDateTime &endDateTime); ///<Метод записи даты и времени окончания встречи

	///Метод установки даты и времени начала и окончания встречи.
    void setDateTimes(const QDateTime &startDateTime, const QDateTime &endDateTime);
	///Метод установки времени начала и окончания встречи
    void setTimes(const QTime &startTime, const QTime &endTime); 

	///Метод вернет номер четверти часа, в которой начнентся встреча
    int startQuater(const QDate &date) const;
	///Метод вернет номер четверти часа, в которой закончится встреча
    int endQuater(const QDate &date) const;

	///Метод вернет true, если встреча app1 начнется раньше app2
    static bool before(Appointment *app1, Appointment *app2);

    bool operator==(const Appointment &other) const; ///<Оператор ==
    bool operator!=(const Appointment &other) const; ///<Оператор !=
    bool operator<(const Appointment &other) const; ///<Оператор <

private:
    int myKey; ///<Ключ.
    int myCalendarKey; ///<Еще один ключ. Нигде не используется.

    Calendar *ptrCalendar; ///<Указатель на календарь, которому принадлежит встреча

    QString mySubject; ///<Тема встречи или человек, с которым назначена встреча.
    QString myPlace; ///<Место встречи
    QString myDescription;///<Описание встречи

    QDateTime myStartDateTime; ///<Дата и время начала встречи
    QDateTime myEndDateTime;   ///<Дата и время окончания встречи
};

Q_DECLARE_METATYPE(Appointment) ///<Объявление мета-класса

#endif
