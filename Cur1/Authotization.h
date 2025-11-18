/*
**************************************************************
Модуль Authotization.h
гр. П22
Разработчик: Баглаева С. А.
Модифицирован: 10 июня 2025
--------------------------------------------------------------
Модуль окна входа
**************************************************************
*/

#pragma once
#include "MyForm.h"
#include <msclr\marshal_cppstd.h>
#include <fstream>
#include "fun.h"

namespace Cur1 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace msclr::interop;
	
	/// <summary>
	/// Сводка для Authotization
	/// </summary>
	public ref class Authotization : public System::Windows::Forms::Form
	{
	public:
		event EventHandler^ ChangeLangEng;
		event EventHandler^ ChangeLangRus;
		event EventHandler^ AdminPremissions;
		event EventHandler^ PlayerPremissions;
	private:
		int checkLang;
	protected:
		void OnPlayerPremissions(EventArgs^ e) {
			PlayerPremissions(this, e);
		}
		void OnAdminPremissions(EventArgs^ e) {
			AdminPremissions(this, e);
		}
		void OnChangeLangEng(EventArgs^ e) {
			ChangeLangEng(this, e);
		}
		void OnChangeLangRus(EventArgs^ e) {
			ChangeLangRus(this, e);
		}
	public:
		Authotization(void)
		{
			InitializeComponent();
			checkLang = 0; // 0 - английский, 1 - русский
		}
	protected:
		~Authotization()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_log_in;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button_logup;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::ComboBox^ comboBox_language;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Authotization::typeid));
			this->button_log_in = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->comboBox_language = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button_logup = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button_log_in
			// 
			this->button_log_in->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_log_in->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_log_in->Location = System::Drawing::Point(85, 211);
			this->button_log_in->Name = L"button_log_in";
			this->button_log_in->Size = System::Drawing::Size(138, 36);
			this->button_log_in->TabIndex = 3;
			this->button_log_in->Text = L"Log In";
			this->button_log_in->UseVisualStyleBackColor = true;
			this->button_log_in->Click += gcnew System::EventHandler(this, &Authotization::button_log_in_Click);
			// 
			// panel1
			// 
			this->panel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->comboBox_language);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->textBox3);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->button_logup);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->button_log_in);
			this->panel1->Font = (gcnew System::Drawing::Font(L"Geometr212 BkCn BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(310, 440);
			this->panel1->TabIndex = 4;
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Geometr212 BkCn BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(36, 376);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(143, 20);
			this->label6->TabIndex = 19;
			this->label6->Text = L"Change language";
			// 
			// comboBox_language
			// 
			this->comboBox_language->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->comboBox_language->Font = (gcnew System::Drawing::Font(L"Geometr212 BkCn BT", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->comboBox_language->FormattingEnabled = true;
			this->comboBox_language->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Eng", L"Rus" });
			this->comboBox_language->Location = System::Drawing::Point(40, 399);
			this->comboBox_language->Name = L"comboBox_language";
			this->comboBox_language->Size = System::Drawing::Size(221, 31);
			this->comboBox_language->TabIndex = 18;
			this->comboBox_language->SelectedIndexChanged += gcnew System::EventHandler(this, &Authotization::comboBox_language_SelectedIndexChanged);
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(267, 329);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(30, 30);
			this->button1->TabIndex = 15;
			this->button1->Text = L">";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Visible = false;
			this->button1->Click += gcnew System::EventHandler(this, &Authotization::button1_Click);
			// 
			// textBox3
			// 
			this->textBox3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Geometr212 BkCn BT", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(40, 329);
			this->textBox3->Name = L"textBox3";
			this->textBox3->PasswordChar = '*';
			this->textBox3->Size = System::Drawing::Size(221, 29);
			this->textBox3->TabIndex = 14;
			this->textBox3->Visible = false;
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Geometr212 BkCn BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(36, 305);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(204, 20);
			this->label5->TabIndex = 13;
			this->label5->Text = L"Common admin password";
			this->label5->Visible = false;
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label4->Font = (gcnew System::Drawing::Font(L"Geometr212 BkCn BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label4->Location = System::Drawing::Point(59, 271);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(238, 20);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Need an admin account\?";
			this->label4->Click += gcnew System::EventHandler(this, &Authotization::label4_Click);
			this->label4->MouseLeave += gcnew System::EventHandler(this, &Authotization::label4_MouseLeave);
			this->label4->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Authotization::label4_MouseMove);
			// 
			// button_logup
			// 
			this->button_logup->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_logup->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_logup->Location = System::Drawing::Point(85, 159);
			this->button_logup->Name = L"button_logup";
			this->button_logup->Size = System::Drawing::Size(138, 36);
			this->button_logup->TabIndex = 11;
			this->button_logup->Text = L"Log Up";
			this->button_logup->UseVisualStyleBackColor = true;
			this->button_logup->Visible = false;
			this->button_logup->Click += gcnew System::EventHandler(this, &Authotization::button_logup_Click);
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label3->Font = (gcnew System::Drawing::Font(L"Geometr212 BkCn BT", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label3->Location = System::Drawing::Point(78, 250);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(229, 21);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Need an account\?";
			this->label3->Click += gcnew System::EventHandler(this, &Authotization::label3_Click);
			this->label3->MouseLeave += gcnew System::EventHandler(this, &Authotization::label3_MouseLeave);
			this->label3->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Authotization::label3_MouseMove);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(267, 110);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(30, 30);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Authotization::pictureBox1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox2->Location = System::Drawing::Point(40, 110);
			this->textBox2->Name = L"textBox2";
			this->textBox2->PasswordChar = '*';
			this->textBox2->Size = System::Drawing::Size(221, 31);
			this->textBox2->TabIndex = 7;
			// 
			// textBox1
			// 
			this->textBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox1->Location = System::Drawing::Point(40, 36);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(221, 31);
			this->textBox1->TabIndex = 6;
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(36, 84);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(100, 23);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Password";
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(36, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(101, 23);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Nickname";
			// 
			// Authotization
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->ClientSize = System::Drawing::Size(334, 464);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Authotization";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Authotization";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		bool eyeState = false;
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!eyeState) 
		{
			textBox2->PasswordChar = '\0';
			pictureBox1->Image = gcnew Bitmap(".\\NoCrossEye.png");
		}
		else 
		{
			textBox2->PasswordChar = '*';
			pictureBox1->Image = gcnew Bitmap(".\\CrossEye.png");
		}
		eyeState = !eyeState;
	}	
		  
private: System::Void button_log_in_Click(System::Object^ sender, System::EventArgs^ e) {
	System::String^ loginStr = textBox1->Text;
	System::String^ passStr = textBox2->Text;
	if (CheckAuthorization("Player.txt", textBox1->Text, textBox2->Text)) 
	{	
		if (checkLang == 1) 
		{
			MessageBox::Show("Авторизация успешна!", "Успешно",
				MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else 
		{
			MessageBox::Show("Authorization is successful!", "Success",
				MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		int existingId = GetPlayerIdByNickname(textBox1->Text, checkLang);
		Player^ currentPlayer = gcnew Player(existingId, loginStr, passStr);
		SavePlayerResults("PlayerResults.txt", currentPlayer);
		if (currentPlayer != nullptr) 
		{
			MyForm^ openForm = gcnew MyForm(currentPlayer);
			openForm->logoutSuccess += gcnew EventHandler(this, &Authotization::OnlogoutSuccess);
			if (checkLang == 1) {
				ChangeLangRus += gcnew EventHandler(openForm, &MyForm::ChangeLanguageToRusMyForm);
				OnChangeLangRus(EventArgs::Empty);
			}
			else {
				ChangeLangEng += gcnew EventHandler(openForm, &MyForm::ChangeLanguageToEngMyForm);
				OnChangeLangEng(EventArgs::Empty);
			}
			PlayerPremissions += gcnew EventHandler(openForm, &MyForm::OnPlayerPremissions);
			openForm->Show();
			OnPlayerPremissions(EventArgs::Empty);
			this->Hide();
		}
	}
	else if (CheckAuthorization("Admin.txt", textBox1->Text, textBox2->Text)) 
	{
		if (checkLang == 1)
		{
			MessageBox::Show("Авторизация администратора успешна!", "Успешно",
				MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else
		{
			MessageBox::Show("Admin authorization is successful!", "Success",
				MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		Admin^ currentAdmin = gcnew Admin(loginStr, passStr);
		MyForm^ openForm = gcnew MyForm();
		openForm->logoutSuccess += gcnew EventHandler(this, &Authotization::OnlogoutSuccess);
		if (checkLang == 1) {
			ChangeLangRus += gcnew EventHandler(openForm, &MyForm::ChangeLanguageToRusMyForm);
			OnChangeLangRus(EventArgs::Empty);
		}
		else {
			ChangeLangEng += gcnew EventHandler(openForm, &MyForm::ChangeLanguageToEngMyForm);
			OnChangeLangEng(EventArgs::Empty);
		}
		AdminPremissions += gcnew EventHandler(openForm, &MyForm::OnAdminPremissions);
		openForm->Show();
		OnAdminPremissions(EventArgs::Empty);
		this->Hide();
	}
	else 
	{
		if (checkLang == 1)
		{
			MessageBox::Show("Неверные данные!", "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else
		{
			MessageBox::Show("Invalid data!", "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

}
	private: void OnlogoutSuccess(Object^ sender, EventArgs^ e) {
		this->Show();
	}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	button_logup->Visible = true;
}
private: System::Void button_logup_Click(System::Object^ sender, System::EventArgs^ e) {
	System::String^ loginStr = textBox1->Text;
	System::String^ passStr = textBox2->Text;
	marshal_context^ context = gcnew marshal_context();

	if (textBox3->Text == marshal_as<String^>(Constants::COMMON_ADMIN_PASSW))
	{
		SaveToBinaryFile("Admin.txt", "Player.txt", loginStr, passStr, checkLang);
	}
	else 
	{
		SaveToBinaryFile("Player.txt", "Admin.txt", loginStr, passStr, checkLang);
		if (CheckAuthorization("Player.txt", loginStr, passStr)) {
			Player^ currentPlayer = gcnew Player(loginStr, passStr);
			SavePlayerResults("PlayerResults.txt", currentPlayer);
		}
	}
}
private: System::Void label3_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
		static_cast<System::Int32>(static_cast<System::Byte>(0)));
}
private: System::Void label3_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
		static_cast<System::Int32>(static_cast<System::Byte>(192)));
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	label5->Visible = true;
	textBox3->Visible = true;
	button1->Visible = true;
}
private: System::Void label4_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
		static_cast<System::Int32>(static_cast<System::Byte>(0)));
}
private: System::Void label4_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
		static_cast<System::Int32>(static_cast<System::Byte>(192)));
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textBox3->Text == marshal_as<String^>(Constants::COMMON_ADMIN_PASSW)) 
	{
		if (checkLang == 1)
		{
			MessageBox::Show("Пароль верный!", "Успешно",
				MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else
		{
			MessageBox::Show("Password is correct!", "Success",
				MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		button_logup->Visible = true;
	}
	else 
	{
		if (checkLang == 1)
		{
			MessageBox::Show("Неверный пароль!", "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else
		{
			MessageBox::Show("invalid password!", "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}
private: System::Void comboBox_language_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	int field = comboBox_language->SelectedIndex;
	switch (field) 
	{
	case 0: ChangeLanguageToEngAuthotization();
		break;
	case 1: ChangeLanguageToRusAuthotization();
		break;
	}
}
	   // Смена языка на английский
	   public: void ChangeLanguageToEngAuthotization() {
		   checkLang = 0;

		   panel1->Font = (gcnew System::Drawing::Font(L"Geometr212 BkCn BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(0)));
		   button_log_in->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(0)));
		   button_log_in->Text = L"Log In";
		   button1->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(0)));
		   textBox3->Font = (gcnew System::Drawing::Font(L"Geometr212 BkCn BT", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(0)));
		   label5->Font = (gcnew System::Drawing::Font(L"Geometr212 BkCn BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(0)));
		   label5->Text = L"Common admin password";
		   label4->Font = (gcnew System::Drawing::Font(L"Geometr212 BkCn BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(0)));
		   label4->Text = L"Need an admin account\?";
		   button_logup->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(0)));
		   button_logup->Text = L"Log Up";
		   label3->Location = System::Drawing::Point(78, 250);
		   label3->Font = (gcnew System::Drawing::Font(L"Geometr212 BkCn BT", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(0)));
		   label3->Text = L"Need an account\?";
		   label2->Text = L"Password";
		   label1->Text = L"Nickname";
		   label6->Font = (gcnew System::Drawing::Font(L"Geometr212 BkCn BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(0)));
		   label6->Text = L"Change language";
		   this->Text = L"Authotization";
	   }

			 // Смена языка на русский
	   public: void ChangeLanguageToRusAuthotization() {
		   checkLang = 1;

		   panel1->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(0)));
		   button_log_in->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(0)));
		   button_log_in->Text = L"Войти";
		   button1->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(0)));
		   textBox3->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(0)));
		   label5->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(0)));
		   label5->Text = L"Общий пароль администраторов";
		   label4->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(0)));
		   label4->Text = L"Нужен аккаунт админа\?";
		   button_logup->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(0)));
		   button_logup->Text = L"Создать";
		   label3->Location = System::Drawing::Point(59, 250);
		   label3->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(0)));
		   label3->Text = L"Нужен новый аккаунт\?";
		   label2->Text = L"Пароль";
		   label1->Text = L"Ник";
		   label6->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(0)));
		   label6->Text = L"Сменить язык";
		   this->Text = L"Авторизация";
	   }
};
}
