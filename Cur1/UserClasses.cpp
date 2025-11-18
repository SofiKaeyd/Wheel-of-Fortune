/*
**************************************************************
Модуль UserClasses.сpp
гр. П22
Разработчик: Баглаева С. А.
Модифицирован: 10 июня 2025
--------------------------------------------------------------
Модуль окна входа
**************************************************************
*/

#include "UserClasses.h"
#include "fun.h"

User::User(String^ nickname, String^ password) {
    NextId = ReadMaxIdFromFile("PlayerResults.txt");
    id = ++NextId;
    this->nickname = nickname;
    this->password = password;
}

User::User(int id, String^ nickname, String^ password) {
    this->id = id;
    this->nickname = nickname;
    this->password = password;
}

Player::Player(String^ nickname, String^ password)
    : User(nickname, password)
{
    score = 0;
    correctAnswers = 0;
    mark = 0;
}

Player::Player(int id, String^ nickname, String^ password)
    : User(id, nickname, password)
{
    score = 0;
    correctAnswers = 0;
    mark = 0;
}

Admin::Admin(String^ nickname, String^ password)
    : User(nickname, password)
{    
}
