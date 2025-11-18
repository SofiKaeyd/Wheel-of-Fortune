/*
**************************************************************
Модуль fun.h
гр. П22
Разработчик: Баглаева С. А.
Модифицирован: 10 июня 2025
--------------------------------------------------------------
Модуль окна входа
**************************************************************
*/

#pragma once
#ifndef FUN_H
#define FUN_H

#include <string>
#include <ctime>
#include <stdlib.h>
#include <fstream>
#include <msclr\marshal_cppstd.h>
#include <iomanip>
#include "UserClasses.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace msclr::interop;
using namespace System::Data::OleDb;

namespace Constants 
{
    static const std::string COMMON_ADMIN_PASSW = "22072020"; // Константа общего пароля администраторов
}

struct ratingTable 
{
    int id;
    std::string nickname;
    int score;
    int correctAnswers;
    int mark;
};
struct LISTratingTable 
{
    ratingTable element;
    LISTratingTable* next;
};
struct UserData 
{
    std::string nickname;
    std::string password;
};
struct QuetionsStrct 
{
    std::string num;
    std::string question;
    std::string answer;
};
struct LISTQuetions 
{
    QuetionsStrct element;
    LISTQuetions* next;
};

static ratingTable xRT;
static LISTratingTable* LRT;
static LISTratingTable* SL;
static QuetionsStrct xQ;
static LISTQuetions* LQ;
static int n;

String^ ReadWheelImageFromFile(std::string FilePath);
void SaveWheelImageToFile(std::string FilePath, String^ whellImage);
ratingTable GetPlayerByNickname(System::String^ searchNickname, int check);
int GetPlayerIdByNickname(System::String^ searchNickname, int check);
int ReadMaxIdFromFile(std::string filePath);
int ReadTimeQustionToFile(std::string FilePath, int check);
void SaveTimeQustionToFile(std::string FilePath, float timeQuestion, int check);

void SavePlayerResults(String^ filePath, Player^ player);

bool IsnicknameUnique(const std::string& filePath, const std::string& nickname);
void SaveToBinaryFile(std::string filePath, std::string filePathfor2Check, System::String^ text1, System::String^ text2, int check);
bool CheckAuthorization(std::string filePath, System::String^ text1, System::String^ text2);
bool IsRecordLimitReached(std::string filename, int maxRecords);
void ClearQuestionsFile(std::string filename);

LISTratingTable* Init_List_RT(ratingTable xRT);
LISTratingTable* InsFirst_List_RT(ratingTable xRT, LISTratingTable* LRT);
LISTratingTable* InsEnd_List_RT(ratingTable xRT, LISTratingTable* LRT);
LISTratingTable* DelFirst_List_RT(LISTratingTable* LRT);
LISTratingTable* Del_List_RT(LISTratingTable* LRT, LISTratingTable* p);

LISTratingTable* Find_id_List(LISTratingTable* LRT, ratingTable xRT);
LISTratingTable* Find_nickname_List(LISTratingTable* LRT, ratingTable xRT);
LISTratingTable* Find_score_List(LISTratingTable* LRT, ratingTable xRT);
LISTratingTable* Find_correctAnswers_List(LISTratingTable* LRT, ratingTable xRT);
LISTratingTable* Find_mark_List(LISTratingTable* LRT, ratingTable xRT);
void SavestRatingList(LISTratingTable* LRT, int check);
void Sort_id_1(LISTratingTable*& LRT);
void Sort_id_2(LISTratingTable*& LRT);
void Sort_nickname_1(LISTratingTable* LRT);
void Sort_nickname_2(LISTratingTable* LRT);
void Sort_score_1(LISTratingTable* LRT);
void Sort_score_2(LISTratingTable* LRT);
void Sort_correctAnswers_1(LISTratingTable*& LRT);
void Sort_correctAnswers_2(LISTratingTable*& LRT);
void Sort_mark_1(LISTratingTable*& LRT);
void Sort_mark_2(LISTratingTable*& LRT);

LISTQuetions* Init_List_Q(QuetionsStrct xQ);
LISTQuetions* InsFirst_List_Q(QuetionsStrct xQ, LISTQuetions* LQ);
LISTQuetions* InsEnd_List_Q(QuetionsStrct xQ, LISTQuetions* LQ);
LISTQuetions* DelFirst_List_Q(LISTQuetions* LQ);
LISTQuetions* Del_List_Q(LISTQuetions* LQ, LISTQuetions* p);
LISTQuetions* Find_num_List_Q(LISTQuetions* LQ, QuetionsStrct xQ);
void SavestQuetionsStrct(LISTQuetions* LQ, int check);

#endif FUN_H