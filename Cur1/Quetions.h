/*
**************************************************************
Модуль Quetions.h
гр. П22
Разработчик: Баглаева С. А.
Модифицирован: 10 июня 2025
--------------------------------------------------------------
Модуль окна входа
**************************************************************
*/

#pragma once
#include <string>
#include <msclr/marshal_cppstd.h>
#include <fstream>
#include <iomanip>
#include "fun.h"

namespace Cur1 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Сводка для Quetions
	/// </summary>
	public ref class Quetions : public System::Windows::Forms::Form
	{
	public:
		int checkLang;
	public:
		Quetions(void)
		{
			InitializeComponent();
			checkLang = 0;
		}
	protected:
		~Quetions()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBoxQuetion;
	private: System::Windows::Forms::Button^ add_quetion;
	private: System::Windows::Forms::Button^ ButtonDelQue;
	private: System::Windows::Forms::Button^ buttonClean;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ button_saveQ;
	private: System::Windows::Forms::Button^ button_openQ;
	private: System::Windows::Forms::TextBox^ textBoxNum;
	private: System::Windows::Forms::TextBox^ textBoxDelQue;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBoxAnswer;
	private: System::Windows::Forms::Button^ ButtonDelAllQue;
	private: System::Windows::Forms::Button^ button_add_time;
	private: System::Windows::Forms::TextBox^ textBox_time;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::Label^ label4;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Quetions::typeid));
			this->textBoxQuetion = (gcnew System::Windows::Forms::TextBox());
			this->add_quetion = (gcnew System::Windows::Forms::Button());
			this->ButtonDelQue = (gcnew System::Windows::Forms::Button());
			this->buttonClean = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textBox_time = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button_add_time = (gcnew System::Windows::Forms::Button());
			this->ButtonDelAllQue = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxAnswer = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDelQue = (gcnew System::Windows::Forms::TextBox());
			this->textBoxNum = (gcnew System::Windows::Forms::TextBox());
			this->button_saveQ = (gcnew System::Windows::Forms::Button());
			this->button_openQ = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBoxQuetion
			// 
			this->textBoxQuetion->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBoxQuetion->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBoxQuetion->Location = System::Drawing::Point(202, 21);
			this->textBoxQuetion->Name = L"textBoxQuetion";
			this->textBoxQuetion->Size = System::Drawing::Size(330, 30);
			this->textBoxQuetion->TabIndex = 0;
			// 
			// add_quetion
			// 
			this->add_quetion->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->add_quetion->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->add_quetion->Location = System::Drawing::Point(0, 21);
			this->add_quetion->Name = L"add_quetion";
			this->add_quetion->Size = System::Drawing::Size(152, 31);
			this->add_quetion->TabIndex = 2;
			this->add_quetion->Text = L"Add question";
			this->add_quetion->UseVisualStyleBackColor = true;
			this->add_quetion->Click += gcnew System::EventHandler(this, &Quetions::add_quetion_Click);
			// 
			// ButtonDelQue
			// 
			this->ButtonDelQue->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ButtonDelQue->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ButtonDelQue->Location = System::Drawing::Point(604, 195);
			this->ButtonDelQue->Name = L"ButtonDelQue";
			this->ButtonDelQue->Size = System::Drawing::Size(163, 32);
			this->ButtonDelQue->TabIndex = 24;
			this->ButtonDelQue->Text = L"Delete by №:";
			this->ButtonDelQue->UseVisualStyleBackColor = true;
			this->ButtonDelQue->Click += gcnew System::EventHandler(this, &Quetions::ButtonDelQue_Click);
			// 
			// buttonClean
			// 
			this->buttonClean->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonClean->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonClean->Location = System::Drawing::Point(604, 79);
			this->buttonClean->Name = L"buttonClean";
			this->buttonClean->Size = System::Drawing::Size(163, 32);
			this->buttonClean->TabIndex = 25;
			this->buttonClean->Text = L"Clear";
			this->buttonClean->UseVisualStyleBackColor = true;
			this->buttonClean->Click += gcnew System::EventHandler(this, &Quetions::buttonClean_Click);
			// 
			// panel1
			// 
			this->panel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->panel1->Controls->Add(this->textBox_time);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->button_add_time);
			this->panel1->Controls->Add(this->ButtonDelQue);
			this->panel1->Controls->Add(this->ButtonDelAllQue);
			this->panel1->Controls->Add(this->dataGridView1);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->textBoxAnswer);
			this->panel1->Controls->Add(this->textBoxDelQue);
			this->panel1->Controls->Add(this->textBoxNum);
			this->panel1->Controls->Add(this->button_saveQ);
			this->panel1->Controls->Add(this->button_openQ);
			this->panel1->Controls->Add(this->textBoxQuetion);
			this->panel1->Controls->Add(this->buttonClean);
			this->panel1->Controls->Add(this->add_quetion);
			this->panel1->Font = (gcnew System::Drawing::Font(L"Geometr212 BkCn BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(770, 398);
			this->panel1->TabIndex = 26;
			// 
			// textBox_time
			// 
			this->textBox_time->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox_time->Location = System::Drawing::Point(602, 328);
			this->textBox_time->Name = L"textBox_time";
			this->textBox_time->Size = System::Drawing::Size(130, 31);
			this->textBox_time->TabIndex = 37;
			this->textBox_time->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Quetions::textBox_time_KeyPress);
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label4->Font = (gcnew System::Drawing::Font(L"Geometr212 BkCn BT", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(730, 335);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(40, 21);
			this->label4->TabIndex = 38;
			this->label4->Text = L"Sec";
			// 
			// button_add_time
			// 
			this->button_add_time->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_add_time->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_add_time->Location = System::Drawing::Point(602, 290);
			this->button_add_time->Name = L"button_add_time";
			this->button_add_time->Size = System::Drawing::Size(163, 32);
			this->button_add_time->TabIndex = 36;
			this->button_add_time->Text = L"Time to answer:";
			this->button_add_time->UseVisualStyleBackColor = true;
			this->button_add_time->Click += gcnew System::EventHandler(this, &Quetions::button_add_time_Click);
			// 
			// ButtonDelAllQue
			// 
			this->ButtonDelAllQue->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ButtonDelAllQue->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ButtonDelAllQue->Location = System::Drawing::Point(604, 134);
			this->ButtonDelAllQue->Name = L"ButtonDelAllQue";
			this->ButtonDelAllQue->Size = System::Drawing::Size(163, 55);
			this->ButtonDelAllQue->TabIndex = 35;
			this->ButtonDelAllQue->Text = L"Delete all question";
			this->ButtonDelAllQue->UseVisualStyleBackColor = true;
			this->ButtonDelAllQue->Click += gcnew System::EventHandler(this, &Quetions::ButtonDelAllQue_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column1,
					this->Column2, this->Column3
			});
			this->dataGridView1->Location = System::Drawing::Point(3, 57);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(595, 33);
			this->dataGridView1->TabIndex = 26;
			this->dataGridView1->RowPostPaint += gcnew System::Windows::Forms::DataGridViewRowPostPaintEventHandler(this, &Quetions::dataGridView1_RowPostPaint);
			// 
			// Column1
			// 
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::Color::Black;
			this->Column1->DefaultCellStyle = dataGridViewCellStyle1;
			this->Column1->HeaderText = L"№";
			this->Column1->Name = L"Column1";
			this->Column1->Width = 40;
			// 
			// Column2
			// 
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Geometr212 BkCn BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::Color::Black;
			this->Column2->DefaultCellStyle = dataGridViewCellStyle2;
			this->Column2->HeaderText = L"Question";
			this->Column2->Name = L"Column2";
			this->Column2->Width = 432;
			// 
			// Column3
			// 
			dataGridViewCellStyle3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::Color::Black;
			this->Column3->DefaultCellStyle = dataGridViewCellStyle3;
			this->Column3->HeaderText = L"Answer";
			this->Column3->Name = L"Column3";
			this->Column3->Width = 80;
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Geometr212 BkCn BT", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(220, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(293, 19);
			this->label3->TabIndex = 34;
			this->label3->Text = L"Is that true that clouds are made of gas\?";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->Font = (gcnew System::Drawing::Font(L"Geometr212 BkCn BT", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(549, -3);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(40, 23);
			this->label2->TabIndex = 33;
			this->label2->Text = L"+/-";
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Geometr212 BkCn BT", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(168, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(17, 19);
			this->label1->TabIndex = 32;
			this->label1->Text = L"1";
			// 
			// textBoxAnswer
			// 
			this->textBoxAnswer->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBoxAnswer->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBoxAnswer->Location = System::Drawing::Point(538, 21);
			this->textBoxAnswer->Name = L"textBoxAnswer";
			this->textBoxAnswer->Size = System::Drawing::Size(60, 30);
			this->textBoxAnswer->TabIndex = 31;
			// 
			// textBoxDelQue
			// 
			this->textBoxDelQue->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBoxDelQue->Location = System::Drawing::Point(604, 233);
			this->textBoxDelQue->Name = L"textBoxDelQue";
			this->textBoxDelQue->Size = System::Drawing::Size(163, 31);
			this->textBoxDelQue->TabIndex = 30;
			// 
			// textBoxNum
			// 
			this->textBoxNum->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBoxNum->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBoxNum->Location = System::Drawing::Point(158, 21);
			this->textBoxNum->Name = L"textBoxNum";
			this->textBoxNum->Size = System::Drawing::Size(38, 30);
			this->textBoxNum->TabIndex = 29;
			// 
			// button_saveQ
			// 
			this->button_saveQ->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_saveQ->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_saveQ->Location = System::Drawing::Point(604, 41);
			this->button_saveQ->Name = L"button_saveQ";
			this->button_saveQ->Size = System::Drawing::Size(163, 32);
			this->button_saveQ->TabIndex = 28;
			this->button_saveQ->Text = L"Save";
			this->button_saveQ->UseVisualStyleBackColor = true;
			this->button_saveQ->Click += gcnew System::EventHandler(this, &Quetions::button_saveQ_Click);
			// 
			// button_openQ
			// 
			this->button_openQ->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_openQ->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_openQ->Location = System::Drawing::Point(604, 3);
			this->button_openQ->Name = L"button_openQ";
			this->button_openQ->Size = System::Drawing::Size(163, 32);
			this->button_openQ->TabIndex = 27;
			this->button_openQ->Text = L"Open";
			this->button_openQ->UseVisualStyleBackColor = true;
			this->button_openQ->Click += gcnew System::EventHandler(this, &Quetions::button_openQ_Click);
			// 
			// Quetions
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->ClientSize = System::Drawing::Size(794, 422);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Quetions";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Bank of Questions";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Quetions::Quetions_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Quetions::Quetions_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	//Вывод списка в основную таблицу
	private: void Scan_List(LISTQuetions* LQ) {
		dataGridView1->Rows->Clear();
		LISTQuetions* q;
		int i = 0;
		q = LQ;
		if (LQ == NULL) return;
		while (q != NULL) 
		{
			dataGridView1->Rows->Add();
			dataGridView1->Rows[i]->Cells[0]->Value = marshal_as<String^>(q->element.num);
			dataGridView1->Rows[i]->Cells[1]->Value = marshal_as<String^>(q->element.question);
			dataGridView1->Rows[i]->Cells[2]->Value = marshal_as<String^>(q->element.answer);
			q = q->next;
			i++;
		}
		int totalHeight = dataGridView1->ColumnHeadersHeight;
		for (int j = 0; j < dataGridView1->Rows->Count; j++)
		{
			totalHeight += dataGridView1->Rows[j]->Height;
		}
		if (dataGridView1->Rows->Count > 0)
		{
			totalHeight += dataGridView1->Rows[0]->Height;
		}
		dataGridView1->Height = totalHeight;
	}

	private: System::Void add_quetion_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string f("Quetions.txt");
		if (IsRecordLimitReached(f, 10))
		{
			if (checkLang == 1)
			{
				MessageBox::Show("Максимальное количество записей — 10!", "Ограничение",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
			else
			{
				MessageBox::Show("The maximum number of entries is 10!", "Limitation",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
			return;
		}
		if (textBoxQuetion->Text == "" || textBoxAnswer->Text == "" || textBoxNum->Text == "")
		{
			if (checkLang == 1)
			{
				MessageBox::Show("Не заполнены поля!", "Повторите ввод",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else
			{
				MessageBox::Show("Fields are not filled in!", "Repeat the input",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			return;
		}

		QuetionsStrct v;
		int n = 0;
		LISTQuetions* q;
		q = LQ; //вставка после головы
		marshal_context^ context = gcnew marshal_context();
		v.num = context->marshal_as< std::string >(textBoxNum->Text->ToString());
		v.question = context->marshal_as< std::string >(textBoxQuetion->Text->ToString());
		if (textBoxAnswer->Text != "+" && textBoxAnswer->Text != "-")
		{
			if (checkLang == 1)
			{
				MessageBox::Show("Можно ввести только «+» или «-»", "Повторите ввод",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
			else
			{
				MessageBox::Show("You can only enter \"+\" or \"-\"", "Repeat the input",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
			return;
		}
		else
		{
			v.answer = context->marshal_as< std::string >(textBoxAnswer->Text->ToString());
		}
		LQ = InsEnd_List_Q(v, LQ);
		Scan_List(LQ);
		SavestQuetionsStrct(LQ, checkLang);
		textBoxNum->Text = "";
		textBoxQuetion->Text = "";
		textBoxAnswer->Text = "";

	}
	private: System::Void ButtonDelQue_Click(System::Object^ sender, System::EventArgs^ e) {
		QuetionsStrct v;
		if (textBoxDelQue->Text == "") {
			if (checkLang == 1)
			{
				MessageBox::Show("Не заполнено поле!", "Повторите ввод",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else
			{
				MessageBox::Show("The field is not filled in!", "Repeat the input",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		else 
		{
			marshal_context^ context = gcnew marshal_context();
			std::string search = context->marshal_as< std::string >(textBoxDelQue->Text->ToString());
			v.num = search;
			LISTQuetions* address;
			address = Find_num_List_Q(LQ, v);
			while (address != NULL) 
			{
				if (address == LQ) 
				{
					LQ = DelFirst_List_Q(LQ);
					address = NULL;
				}
				else 
				{
					Del_List_Q(LQ, address);
					address = Find_num_List_Q(LQ, xQ);
				}
			}
			Scan_List(LQ);
		}
	}

	private: void LoadQT() {
		if (LQ != NULL)
			while (LQ != NULL)
				LQ = DelFirst_List_Q(LQ);
		std::ifstream f("Quetions.txt");
		if (!f.is_open())
		{
			if (checkLang == 1)
			{
				MessageBox::Show("Не удалось открыть файл", "Ошибка",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else
			{
				MessageBox::Show("Couldn't open a file", "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			return;
		}
		QuetionsStrct v;
		if (f >> v.num >> std::ws >> std::quoted(v.question) //std::ws пропускает все пробельные символы
			>> std::ws >> std::quoted(v.answer)) { /*std::quoted помещает строку в кавычки,
												благодаря чему пробелы и кавычки внутри строки не считываются программой*/
			LQ = Init_List_Q(v);
			LISTQuetions* q = LQ;

			while (f >> v.num >> std::ws >> std::quoted(v.question)
				>> std::ws >> std::quoted(v.answer)) {
				LISTQuetions* n = new LISTQuetions;
				n->element = v;
				n->next = nullptr;
				q->next = n;
				q = n;
			}
		}
		f.close();
		Scan_List(LQ);
	}

	private: System::Void Quetions_Load(System::Object^ sender, System::EventArgs^ e) {
		LoadQT();
	}
	private: System::Void button_openQ_Click(System::Object^ sender, System::EventArgs^ e) {
		LoadQT();
	}
	private: System::Void Quetions_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		SavestQuetionsStrct(LQ, checkLang);
	}
	private: System::Void button_saveQ_Click(System::Object^ sender, System::EventArgs^ e) {
		SavestQuetionsStrct(LQ, checkLang);
	}
	private: System::Void buttonClean_Click(System::Object^ sender, System::EventArgs^ e) {
		dataGridView1->Rows->Clear();
	}
	private: System::Void dataGridView1_RowPostPaint(System::Object^ sender, System::Windows::Forms::DataGridViewRowPostPaintEventArgs^ e) {
		System::String^ rowNumber = (e->RowIndex + 1).ToString();
		e->Graphics->DrawString(rowNumber, dataGridView1->Font, System::Drawing::Brushes::Black,
			e->RowBounds.Location.X + 10, e->RowBounds.Location.Y + 4);
	}
	public: QuetionsStrct GetQuestionByNumber(int index) {
		QuetionsStrct v;
		v.num = "";
		v.question = "";
		v.answer = "";

		try
		{
			std::ifstream f("Quetions.txt");
			if (!f.is_open())
			{
				if (checkLang == 1)
				{
					MessageBox::Show("Не удалось открыть файл", "Ошибка",
						MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				else
				{
					MessageBox::Show("Couldn't open a file", "Error",
						MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				return v;
			}

			int curIndex = 0;
			std::string numLine;
			std::string questionLine;
			std::string answerLine;

			while (std::getline(f, numLine))
			{
				if (!std::getline(f, questionLine))
					break;
				if (!std::getline(f, answerLine))
					break;
				curIndex++;
				if (curIndex == index)
				{
					v.num = curIndex;
					v.question = questionLine;
					v.answer = answerLine;
					f.close();
					return v;
				}
			}
			f.close();
		}
		catch (Exception^ ex)
		{
			if (checkLang == 1)
			{
				MessageBox::Show("Ошибка: " + ex->Message,
					"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else
			{
				MessageBox::Show("Error: " + ex->Message,
					"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		return v; // Если запись не найдена, возвращаем v со значениями по умолчанию
	}
	private: System::Void ButtonDelAllQue_Click(System::Object^ sender, System::EventArgs^ e) {
		dataGridView1->Rows->Clear();
		ClearQuestionsFile("Quetions.txt");
	}
	private: System::Void textBox_time_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (((e->KeyChar < 48 || e->KeyChar > 57) && (e->KeyChar != 8) && (e->KeyChar != 44) && (e->KeyChar != 46)) ||
			(((e->KeyChar == ',') || (e->KeyChar == '.')) && ((textBox_time->Text->IndexOf(",") != -1) || (textBox_time->Text->IndexOf(".") != -1)))) {
			e->Handled = true;
			return;
		}
	}
	private: System::Void button_add_time_Click(System::Object^ sender, System::EventArgs^ e) {
		SaveTimeQustionToFile("TimerForQuestions.txt", System::Convert::ToDouble(textBox_time->Text), checkLang);
	}

	public: void OnChangeLangEngQuetions(Object^ sender, EventArgs^ e) {
		checkLang = 0;

		this->Text = L"Bank of Questions";
		textBoxQuetion->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		add_quetion->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		add_quetion->Text = L"Add question";
		ButtonDelQue->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		ButtonDelQue->Text = L"Delete by №:";
		buttonClean->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		buttonClean->Text = L"Clear";
		panel1->Font = (gcnew System::Drawing::Font(L"Geometr212 BkCn BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		button_add_time->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		button_add_time->Text = L"Time to answer:";
		ButtonDelAllQue->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		ButtonDelAllQue->Text = L"Delete all question";
		Column2->HeaderText = L"Question";
		Column3->HeaderText = L"Answer";
		label3->Font = (gcnew System::Drawing::Font(L"Geometr212 BkCn BT", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		label3->Text = L"Is that true that clouds are made of gas\?";
		label2->Font = (gcnew System::Drawing::Font(L"Geometr212 BkCn BT", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		label1->Font = (gcnew System::Drawing::Font(L"Geometr212 BkCn BT", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		textBoxAnswer->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		textBoxNum->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		button_saveQ->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		button_saveQ->Text = L"Save";
		button_openQ->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		button_openQ->Text = L"Open";
		label4->Font = (gcnew System::Drawing::Font(L"Geometr212 BkCn BT", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		label4->Text = L"Sec";

	}

	public: void OnChangeLangRusQuetions(Object^ sender, EventArgs^ e) {
		checkLang = 1;
		this->Text = L"Банк Вопросов";
		textBoxQuetion->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		add_quetion->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		add_quetion->Text = L"Добавить";
		ButtonDelQue->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 13.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		ButtonDelQue->Text = L"Удалить по №:";
		buttonClean->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		buttonClean->Text = L"Очистить";
		panel1->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		button_add_time->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		button_add_time->Text = L"Время для ответа:";
		ButtonDelAllQue->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		ButtonDelAllQue->Text = L"Удалить все вопросы";
		Column2->HeaderText = L"Вопрос";
		Column3->HeaderText = L"Ответ";
		label3->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		label3->Text = L"Правда, что облака состоят из газа\?";
		label2->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		label1->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		textBoxAnswer->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		textBoxNum->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		button_saveQ->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		button_saveQ->Text = L"Сохранить";
		button_openQ->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		button_openQ->Text = L"Открыть";
		label4->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		label4->Text = L"Сек";
	}
};
}
