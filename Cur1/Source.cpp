/*
**************************************************************
Модуль Source.сpp
гр. П22
Разработчик: Баглаева С. А.
Модифицирован: 10 июня 2025
--------------------------------------------------------------
Модуль окна входа
**************************************************************
*/

#include "MyForm.h"
#include "Quetions.h"
#include "Rating_Table.h"
#include "Authotization.h"
#include "QuetionForm.h"
#include "Guide.h"
#include <Windows.h>

using namespace Cur1;

[STAThread]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew Authotization);
    return 0;
}
