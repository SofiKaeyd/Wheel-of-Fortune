/*
**************************************************************
Модуль UserClasses.h
гр. П22
Разработчик: Баглаева С. А.
Модифицирован: 10 июня 2025
--------------------------------------------------------------
Модуль окна входа
**************************************************************
*/

#pragma once
#ifndef USERCLASSES_H
#define USERCLASSES_H

#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class User {
public:
    static int NextId;
    int id;
    String^ nickname;
    String^ password;

    User(String^ nickname, String^ password); // Конструктор для нового пользователя
    User(int id, String^ nickname, String^ password); // Конструктор для существующего пользователя
};

public ref class Player : public User {
public:
    int score;
    int correctAnswers;
    int mark;
    Player(String^ nickname, String^ password);
    Player(int id, String^ nickname, String^ password);
};

public ref class Admin : public User {
public:
    Admin(String^ nickname, String^ password);
};

#endif USERCLASSES_H