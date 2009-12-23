﻿/*******************************************************************************

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

#ifndef CALENDAR_H
#define CALENDAR_H

#include <QColor>
#include <QList>
#include <QMetaType>
#include <QString>

#include "appointment.h"
/*!
    \class Calendar
    \brief Класс для хранения данных календарей.
*/

class Calendar
{
public:
    Calendar(int key) : mySelected(false), myColor(255,0,0), myCounter(0) { myKey = key; }
    ~Calendar() { qDeleteAll(myAppointments); }

    int key() const {return myKey;}		///<Метод чтения ключа
    void setKey(int key) {myKey = key;}	///<Метод записи ключа

    QString name() const {return myName;}				///<Метод чтения имени
    void setName(const QString &name) {myName = name;}	///<Метод записи имени

    QString description() const {return myDescription;}	///<Метод чтения описания
    void setDescription(const QString &description) {myDescription = description;}	///<Метод установки описания

    bool isSelected() const { return mySelected; }				///<Возращает  статус выбора текущего календаря
    void setSelected(bool selected) { mySelected = selected; }	///<Установить статус выбора текущего календаря

    QColor color() const { return myColor; }					///<Получить цвет календаря
    void setColor(const QColor &color) { myColor = color; }		///<Задать цвет для календаря

	/**
	* Получить список встреч на выбранное число
	* @param date Дата встречи в формате QDate.
	* @return Список встреч QList <Appointment *>
	*/
    QList <Appointment *> getAppointments(const QDate &date);
    bool insertAppointment(Appointment *appointment);			///<Добавить встречу
    bool updateAppointment(const Appointment &appointment);		///<Обновить данные о встрече
    bool removeAppointment(Appointment *appointment);			///<Удалить встречу

    bool operator==(const Calendar &other) const;				///<Булевый оператор сравнения с другим календарем
    bool operator!=(const Calendar &other) const;				///<Белевый оператор неравенства с другим календарем
private:
    int myKey;	///<Ключ индификатор календаря

    bool mySelected; ///<Статус выбора

    QColor myColor;	 ///<Цвет календаря

    QString myName; ///<Имя календаря
    QString myDescription; ///<Описание о календаре

    QList <Appointment *> myAppointments; ///<Список встреч

    int myCounter;	///<??
};

//Q_DECLARE_METATYPE(Calendar)

#endif
