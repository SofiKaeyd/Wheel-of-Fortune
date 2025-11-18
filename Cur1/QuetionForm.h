/*
**************************************************************
Модуль QuetionForm.h
гр. П22
Разработчик: Баглаева С. А.
Модифицирован: 10 июня 2025
--------------------------------------------------------------
Модуль окна входа
**************************************************************
*/

#pragma once
#include "Quetions.h"
#include "UserClasses.h"
#include "fun.h"

namespace Cur1 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для QuetionForm
	/// </summary>
	public ref class QuetionForm : public System::Windows::Forms::Form
	{
	private:
		String^ ShowQuestion;
		String^ ShowNum;
		String^ ShowAnswer;
		Player^ currentPlayer;
		int secTim;
	public:
		event EventHandler^ updateRT;
		event EventHandler^ updateCP;
		int checkLang;
	private: System::Windows::Forms::TextBox^ txbSec;
	private: System::Windows::Forms::Timer^ timer1;
	public:
		QuetionForm(void)
		{
			InitializeComponent();
			checkLang = 0;
		}
	public:
		QuetionForm(String^ num, String^ ques, String^ answ, Player^ player)
		{
			InitializeComponent();
			ShowNum = num;
			ShowQuestion = ques;
			ShowAnswer = answ;
			currentPlayer = player;
			secTim = ReadTimeQustionToFile("TimerForQuestions.txt", checkLang);
		}
	protected:
		~QuetionForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::RadioButton^ rbtnWrong;
	private: System::Windows::Forms::RadioButton^ rbtnRight;
	private: System::Windows::Forms::Label^ labelNumber;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(QuetionForm::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->txbSec = (gcnew System::Windows::Forms::TextBox());
			this->labelNumber = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->rbtnWrong = (gcnew System::Windows::Forms::RadioButton());
			this->rbtnRight = (gcnew System::Windows::Forms::RadioButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->panel1->Controls->Add(this->txbSec);
			this->panel1->Controls->Add(this->labelNumber);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->rbtnWrong);
			this->panel1->Controls->Add(this->rbtnRight);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Font = (gcnew System::Drawing::Font(L"Geometr212 BkCn BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(583, 243);
			this->panel1->TabIndex = 5;
			// 
			// txbSec
			// 
			this->txbSec->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->txbSec->Enabled = false;
			this->txbSec->Location = System::Drawing::Point(524, 199);
			this->txbSec->Name = L"txbSec";
			this->txbSec->Size = System::Drawing::Size(48, 31);
			this->txbSec->TabIndex = 5;
			// 
			// labelNumber
			// 
			this->labelNumber->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelNumber->AutoSize = true;
			this->labelNumber->Location = System::Drawing::Point(3, 20);
			this->labelNumber->Name = L"labelNumber";
			this->labelNumber->Size = System::Drawing::Size(25, 23);
			this->labelNumber->TabIndex = 4;
			this->labelNumber->Text = L"0.";
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->Location = System::Drawing::Point(182, 199);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(185, 33);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Answer";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &QuetionForm::button1_Click);
			// 
			// rbtnWrong
			// 
			this->rbtnWrong->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->rbtnWrong->AutoSize = true;
			this->rbtnWrong->Location = System::Drawing::Point(401, 167);
			this->rbtnWrong->Name = L"rbtnWrong";
			this->rbtnWrong->Size = System::Drawing::Size(87, 27);
			this->rbtnWrong->TabIndex = 2;
			this->rbtnWrong->TabStop = true;
			this->rbtnWrong->Text = L"Wrong";
			this->rbtnWrong->UseVisualStyleBackColor = true;
			// 
			// rbtnRight
			// 
			this->rbtnRight->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->rbtnRight->AutoSize = true;
			this->rbtnRight->Location = System::Drawing::Point(73, 167);
			this->rbtnRight->Name = L"rbtnRight";
			this->rbtnRight->Size = System::Drawing::Size(75, 27);
			this->rbtnRight->TabIndex = 1;
			this->rbtnRight->TabStop = true;
			this->rbtnRight->Text = L"Right";
			this->rbtnRight->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->Location = System::Drawing::Point(34, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(543, 116);
			this->label1->TabIndex = 0;
			this->label1->Text = L" —";
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &QuetionForm::timer1_Tick);
			// 
			// QuetionForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->ClientSize = System::Drawing::Size(607, 267);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"QuetionForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Quetion!";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &QuetionForm::QuetionForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &QuetionForm::QuetionForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		
private: System::Void QuetionForm_Load(System::Object^ sender, System::EventArgs^ e) {
	labelNumber->Text = ShowNum;
	label1->Text = ShowQuestion;
	txbSec->Text = secTim.ToString();
	timer1->Start();
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ userAnswer = "";
	if (rbtnRight->Checked) 
	{
		userAnswer = "\"+\"";
	}
	if (rbtnWrong->Checked) 
	{
		userAnswer = "\"-\"";
	}	
	QuetionsStrct v;
	v.num = Convert::ToInt32(ShowNum);
	marshal_context^ context = gcnew marshal_context();
	v.question = context->marshal_as< std::string >(ShowQuestion->ToString());
	v.answer = context->marshal_as< std::string >(ShowAnswer->ToString());
	if (currentPlayer != nullptr) 
	{
		if (userAnswer == (marshal_as<String^>(v.answer))) 
		{
			currentPlayer->score += 150;
			currentPlayer->correctAnswers += 1;
			currentPlayer->mark = (currentPlayer->score + 149) / 150;
			SavePlayerResults("PlayerResults.txt", currentPlayer);
			if (checkLang == 1)
			{
				MessageBox::Show("Правильно!", "Результат",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else
			{
				MessageBox::Show("Correctly!", "Result",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
		}
		else 
		{
			if (currentPlayer->score >= 10) 
			{
				currentPlayer->score -= 10;
				currentPlayer->mark = (currentPlayer->score + 149) / 150;
				SavePlayerResults("PlayerResults.txt", currentPlayer);
			}
			if (checkLang == 1)
			{
				MessageBox::Show("Неправильно!", "Результат",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else
			{
				MessageBox::Show("Incorrectly!", "Result",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}
	this->Close();
}
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	secTim -= 1;
	this->txbSec->Text = secTim.ToString();
	if (secTim <= 0) 
	{
		timer1->Stop();
		if (currentPlayer->score >= 10) 
		{
			currentPlayer->score -= 10;
			currentPlayer->mark = (currentPlayer->score + 149) / 150;
			SavePlayerResults("PlayerResults.txt", currentPlayer);
		}
		if (checkLang == 1)
		{
			MessageBox::Show("Время кончилось!", "Результат",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else
		{
			MessageBox::Show("Time's up!", "Result",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		this->Close();
	}
}
private: System::Void QuetionForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	updateRT(this, EventArgs::Empty);
	updateCP(this, EventArgs::Empty);
}
	public: void OnChangeLangEngQuetionForm(Object^ sender, EventArgs^ e) {
		checkLang = 0;

		this->Text = L"Quetion!";
		panel1->Font = (gcnew System::Drawing::Font(L"Geometr212 BkCn BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		button1->Text = L"Answer";
		rbtnWrong->Text = L"Wrong";
		rbtnRight->Text = L"Right";
	}
	public: void OnChangeLangRusQuetionForm(Object^ sender, EventArgs^ e) {
		checkLang = 1;

		this->Text = L"Вопрос!";
		panel1->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		button1->Text = L"Ответить";
		rbtnWrong->Text = L"Неверно";
		rbtnRight->Text = L"Верно";
	}
};
}
