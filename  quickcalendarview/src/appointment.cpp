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

#include "appointment.h"

/*!
   startDateTime - ������ ������, endDateTime - ���������.
*/
void Appointment::setDateTimes(const QDateTime &startDateTime, const QDateTime &endDateTime)
{
    if(startDateTime <= endDateTime) //���� ������ ������ ������ ������� ���������
    {
        myStartDateTime = startDateTime; //���������� ������ ������
        myEndDateTime = endDateTime; //���������� ������ ���������
    }
    else //�����
    {
        myEndDateTime = myStartDateTime = startDateTime; //���������� ������ ������ � ��������� �������
    }
}
/*!
   startTime - ����� ������, endTime - ����� ���������.
*/
void Appointment::setTimes(const QTime &startTime, const QTime &endTime)
{
    if(startTime <= endTime) //���� ����� ������ ������ ������� ���������
    {
        myStartDateTime.setTime(startTime); //���������� ����� ������
        myEndDateTime.setTime(endTime); //���������� ����� ���������
    }
    else //�����
    {
        myStartDateTime.setTime(startTime); //�� �� �����!!!
        myEndDateTime.setTime(endTime);
    }
}

/*!
    ������������� ���� � ����� ������ �������.
*/
void Appointment::setStartDateTime(const QDateTime &startDateTime)
{
    if(startDateTime <= myEndDateTime) //���� ������ ������ ������� ������ ������� �� ���������
    {
        myStartDateTime = startDateTime; //���������� ������ ������ �������
    }else //�����
    {
        myStartDateTime = myEndDateTime; //���������� ������ ������ ������� ������ ������� �� ���������
    }
}

/*!
    ������������� ���� � ����� ��������� �������.
*/
void Appointment::setEndDateTime(const QDateTime &endDateTime)
{
    if(endDateTime >= myStartDateTime) //���� ������ ������ ������� ������ ������� �� ���������
    {
        myEndDateTime = endDateTime; //���������� ������ ����� �������
    }else //�����
    {
        myEndDateTime = myStartDateTime; //���������� ������ ��������� ������ ������� ������ �������
    }
}

/*!
    ���� date ����� ���� ������ �������, ����� ������ ����� �������� ����, � ������� �������� �������.
    ���� date ������ ��� ���� ��������� �������, ������� ������ 0.
	����� -1.
*/
int Appointment::startQuater(const QDate &date) const
{
    QTime time = myStartDateTime.time(); //�������� ����� ������

    if(date == myStartDateTime.date()) //���� date ����� ���� ������
        return ((time.hour() * 60) + time.minute()) / 15; //������ ���������� ���������
    else if(date <= myEndDateTime.date()) //�����, ���� date ������ ���� ���������
        return 0; //������ 0
    else
        return -1; //����� ������ -1
}

/*!
    ���� date ����� ���� ������ �������, ����� ������ ����� �������� ����, � ������� �������� �������.
    ���� date ������ ��� ���� ��������� �������, ������� ������ 0.
	����� -1.
*/
int Appointment::endQuater(const QDate &date) const
{
    QTime time = myEndDateTime.time(); ////�������� ����� ���������

    if(date == myEndDateTime.date()) //���� date ����� ���� ���������
        return ((time.hour() * 60) + time.minute()) / 15; //������ ���������� ���������
    else if(myEndDateTime.date() > date) //�����, ���� date ������ ���� ���������
        return (24 * 60) / 15; //������ ���������� ��������� ���� � ������
    else
        return -1; //����� -1.
}

bool Appointment::before(Appointment *app1, Appointment *app2)
{
    return app1->startDateTime() < app2->startDateTime(); //���������� ����� ������ ������
}

/*!
    ���������� ������� �� �����.
*/
bool Appointment::operator==(const Appointment &other) const {
    if(this == &other) //���������� ������
        return true;
    else if(other.myKey == myKey) //����� ���������� �����
        return true;
    else
        return false;
}

/*!
    ���������� ������� �� �����.
*/
bool Appointment::operator!=(const Appointment &other) const {
    return !(*this == other); //�������� ���������
}

/*!
  ���������� ������� �� ������� �� ������.
*/
bool Appointment::operator<(const Appointment &other) const {
    if(this == &other) //���������� ���������
        return false;
    else if(other.myStartDateTime > myStartDateTime) //���������� ����� ������ ������
        return true;
    else
        return false;
}

