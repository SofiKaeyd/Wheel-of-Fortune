/*
**************************************************************
Модуль Rating_Table.h
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
#include "fun.h"
#include "UserClasses.h"

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
	/// Сводка для Rating_Table
	/// </summary>
	public ref class Rating_Table : public System::Windows::Forms::Form
	{
	public:
		int checkLang;
	public:
		Rating_Table(void)
		{
			InitializeComponent();
			checkLang = 0;
		}
	protected:
		~Rating_Table()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ textBoxDelNickname;
	private: System::Windows::Forms::Button^ button_del_nickname;
	private: System::Windows::Forms::ComboBox^ comboBoxMainTypeSort;
	private: System::Windows::Forms::ComboBox^ comboBoxForMainSort;
	private: System::Windows::Forms::Button^ CleanRTableForSearch;
	private: System::Windows::Forms::Button^ CleanRTableMain;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ SortRTableMain;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::TextBox^ textBoxForSearch;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ SearchRTable;
	private: System::Windows::Forms::Button^ OpenRTable;
	private: System::Windows::Forms::Button^ SaveRTable;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBoxDelID;
	private: System::Windows::Forms::Button^ button_del_id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle21 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle22 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle23 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle24 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle25 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle26 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle27 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle28 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle29 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle30 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Rating_Table::typeid));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBoxDelID = (gcnew System::Windows::Forms::TextBox());
			this->button_del_id = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBoxDelNickname = (gcnew System::Windows::Forms::TextBox());
			this->button_del_nickname = (gcnew System::Windows::Forms::Button());
			this->comboBoxMainTypeSort = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxForMainSort = (gcnew System::Windows::Forms::ComboBox());
			this->CleanRTableForSearch = (gcnew System::Windows::Forms::Button());
			this->CleanRTableMain = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->SortRTableMain = (gcnew System::Windows::Forms::Button());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->textBoxForSearch = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SearchRTable = (gcnew System::Windows::Forms::Button());
			this->OpenRTable = (gcnew System::Windows::Forms::Button());
			this->SaveRTable = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->textBoxDelID);
			this->groupBox1->Controls->Add(this->button_del_id);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->textBoxDelNickname);
			this->groupBox1->Controls->Add(this->button_del_nickname);
			this->groupBox1->Controls->Add(this->comboBoxMainTypeSort);
			this->groupBox1->Controls->Add(this->comboBoxForMainSort);
			this->groupBox1->Controls->Add(this->CleanRTableForSearch);
			this->groupBox1->Controls->Add(this->CleanRTableMain);
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->SortRTableMain);
			this->groupBox1->Controls->Add(this->dataGridView2);
			this->groupBox1->Controls->Add(this->textBoxForSearch);
			this->groupBox1->Controls->Add(this->dataGridView1);
			this->groupBox1->Controls->Add(this->SearchRTable);
			this->groupBox1->Controls->Add(this->OpenRTable);
			this->groupBox1->Controls->Add(this->SaveRTable);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(12, 7);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(1239, 587);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Rating table";
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label6->Location = System::Drawing::Point(499, 336);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(130, 30);
			this->label6->TabIndex = 39;
			this->label6->Text = L"ID";
			// 
			// textBoxDelID
			// 
			this->textBoxDelID->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBoxDelID->Location = System::Drawing::Point(635, 336);
			this->textBoxDelID->Name = L"textBoxDelID";
			this->textBoxDelID->Size = System::Drawing::Size(105, 30);
			this->textBoxDelID->TabIndex = 38;
			// 
			// button_del_id
			// 
			this->button_del_id->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_del_id->Location = System::Drawing::Point(499, 303);
			this->button_del_id->Name = L"button_del_id";
			this->button_del_id->Size = System::Drawing::Size(130, 30);
			this->button_del_id->TabIndex = 37;
			this->button_del_id->Text = L"Delete";
			this->button_del_id->UseVisualStyleBackColor = true;
			this->button_del_id->Click += gcnew System::EventHandler(this, &Rating_Table::button_del_id_Click);
			// 
			// label9
			// 
			this->label9->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label9->Location = System::Drawing::Point(499, 272);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(130, 28);
			this->label9->TabIndex = 36;
			this->label9->Text = L"Nickname";
			// 
			// textBoxDelNickname
			// 
			this->textBoxDelNickname->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBoxDelNickname->Location = System::Drawing::Point(635, 272);
			this->textBoxDelNickname->Name = L"textBoxDelNickname";
			this->textBoxDelNickname->Size = System::Drawing::Size(105, 30);
			this->textBoxDelNickname->TabIndex = 31;
			// 
			// button_del_nickname
			// 
			this->button_del_nickname->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_del_nickname->Location = System::Drawing::Point(499, 239);
			this->button_del_nickname->Name = L"button_del_nickname";
			this->button_del_nickname->Size = System::Drawing::Size(130, 30);
			this->button_del_nickname->TabIndex = 29;
			this->button_del_nickname->Text = L"Delete";
			this->button_del_nickname->UseVisualStyleBackColor = true;
			this->button_del_nickname->Click += gcnew System::EventHandler(this, &Rating_Table::button_del_nickname_Click);
			// 
			// comboBoxMainTypeSort
			// 
			this->comboBoxMainTypeSort->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->comboBoxMainTypeSort->FormattingEnabled = true;
			this->comboBoxMainTypeSort->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Decreasing", L"Increasing" });
			this->comboBoxMainTypeSort->Location = System::Drawing::Point(427, 28);
			this->comboBoxMainTypeSort->Name = L"comboBoxMainTypeSort";
			this->comboBoxMainTypeSort->Size = System::Drawing::Size(124, 30);
			this->comboBoxMainTypeSort->TabIndex = 16;
			// 
			// comboBoxForMainSort
			// 
			this->comboBoxForMainSort->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->comboBoxForMainSort->FormattingEnabled = true;
			this->comboBoxForMainSort->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"ID", L"Nickname", L"Score", L"Correct answers",
					L"Mark"
			});
			this->comboBoxForMainSort->Location = System::Drawing::Point(299, 28);
			this->comboBoxForMainSort->Name = L"comboBoxForMainSort";
			this->comboBoxForMainSort->Size = System::Drawing::Size(122, 30);
			this->comboBoxForMainSort->TabIndex = 14;
			// 
			// CleanRTableForSearch
			// 
			this->CleanRTableForSearch->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CleanRTableForSearch->Location = System::Drawing::Point(746, 28);
			this->CleanRTableForSearch->Name = L"CleanRTableForSearch";
			this->CleanRTableForSearch->Size = System::Drawing::Size(487, 30);
			this->CleanRTableForSearch->TabIndex = 13;
			this->CleanRTableForSearch->Text = L"Clear";
			this->CleanRTableForSearch->UseVisualStyleBackColor = true;
			this->CleanRTableForSearch->Click += gcnew System::EventHandler(this, &Rating_Table::CleanRTableForSearch_Click);
			// 
			// CleanRTableMain
			// 
			this->CleanRTableMain->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CleanRTableMain->Location = System::Drawing::Point(6, 28);
			this->CleanRTableMain->Name = L"CleanRTableMain";
			this->CleanRTableMain->Size = System::Drawing::Size(123, 30);
			this->CleanRTableMain->TabIndex = 12;
			this->CleanRTableMain->Text = L"Clear";
			this->CleanRTableMain->UseVisualStyleBackColor = true;
			this->CleanRTableMain->Click += gcnew System::EventHandler(this, &Rating_Table::CleanRTableMain_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"ID", L"Nickname", L"Score", L"Correct answers",
					L"Mark"
			});
			this->comboBox1->Location = System::Drawing::Point(499, 147);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(241, 30);
			this->comboBox1->TabIndex = 11;
			// 
			// SortRTableMain
			// 
			this->SortRTableMain->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->SortRTableMain->Location = System::Drawing::Point(135, 28);
			this->SortRTableMain->Name = L"SortRTableMain";
			this->SortRTableMain->Size = System::Drawing::Size(158, 30);
			this->SortRTableMain->TabIndex = 7;
			this->SortRTableMain->Text = L"Sort";
			this->SortRTableMain->UseVisualStyleBackColor = true;
			this->SortRTableMain->Click += gcnew System::EventHandler(this, &Rating_Table::SortRTableMain_Click);
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->dataGridView2->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, this->dataGridViewTextBoxColumn4, this->dataGridViewTextBoxColumn5
			});
			this->dataGridView2->Location = System::Drawing::Point(746, 64);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->ReadOnly = true;
			this->dataGridView2->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->dataGridView2->Size = System::Drawing::Size(487, 90);
			this->dataGridView2->TabIndex = 6;
			// 
			// dataGridViewTextBoxColumn1
			// 
			dataGridViewCellStyle21->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			dataGridViewCellStyle21->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle21->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			dataGridViewCellStyle21->SelectionForeColor = System::Drawing::Color::Black;
			this->dataGridViewTextBoxColumn1->DefaultCellStyle = dataGridViewCellStyle21;
			this->dataGridViewTextBoxColumn1->HeaderText = L"ID";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->ReadOnly = true;
			this->dataGridViewTextBoxColumn1->Width = 60;
			// 
			// dataGridViewTextBoxColumn2
			// 
			dataGridViewCellStyle22->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			dataGridViewCellStyle22->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle22->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			dataGridViewCellStyle22->SelectionForeColor = System::Drawing::Color::Black;
			this->dataGridViewTextBoxColumn2->DefaultCellStyle = dataGridViewCellStyle22;
			this->dataGridViewTextBoxColumn2->HeaderText = L"Nickname";
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->ReadOnly = true;
			this->dataGridViewTextBoxColumn2->Width = 115;
			// 
			// dataGridViewTextBoxColumn3
			// 
			dataGridViewCellStyle23->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			dataGridViewCellStyle23->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle23->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			dataGridViewCellStyle23->SelectionForeColor = System::Drawing::Color::Black;
			this->dataGridViewTextBoxColumn3->DefaultCellStyle = dataGridViewCellStyle23;
			this->dataGridViewTextBoxColumn3->HeaderText = L"Score";
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->ReadOnly = true;
			this->dataGridViewTextBoxColumn3->Width = 70;
			// 
			// dataGridViewTextBoxColumn4
			// 
			dataGridViewCellStyle24->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			dataGridViewCellStyle24->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle24->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			dataGridViewCellStyle24->SelectionForeColor = System::Drawing::Color::Black;
			this->dataGridViewTextBoxColumn4->DefaultCellStyle = dataGridViewCellStyle24;
			this->dataGridViewTextBoxColumn4->HeaderText = L"Correct Answers";
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			this->dataGridViewTextBoxColumn4->ReadOnly = true;
			this->dataGridViewTextBoxColumn4->Width = 110;
			// 
			// dataGridViewTextBoxColumn5
			// 
			dataGridViewCellStyle25->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			dataGridViewCellStyle25->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle25->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			dataGridViewCellStyle25->SelectionForeColor = System::Drawing::Color::Black;
			this->dataGridViewTextBoxColumn5->DefaultCellStyle = dataGridViewCellStyle25;
			this->dataGridViewTextBoxColumn5->HeaderText = L"Mark";
			this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
			this->dataGridViewTextBoxColumn5->ReadOnly = true;
			this->dataGridViewTextBoxColumn5->Width = 90;
			// 
			// textBoxForSearch
			// 
			this->textBoxForSearch->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBoxForSearch->Location = System::Drawing::Point(635, 183);
			this->textBoxForSearch->Name = L"textBoxForSearch";
			this->textBoxForSearch->Size = System::Drawing::Size(105, 30);
			this->textBoxForSearch->TabIndex = 5;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column5
			});
			this->dataGridView1->Location = System::Drawing::Point(6, 64);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->dataGridView1->Size = System::Drawing::Size(487, 92);
			this->dataGridView1->TabIndex = 4;
			// 
			// Column1
			// 
			dataGridViewCellStyle26->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			dataGridViewCellStyle26->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle26->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			dataGridViewCellStyle26->SelectionForeColor = System::Drawing::Color::Black;
			this->Column1->DefaultCellStyle = dataGridViewCellStyle26;
			this->Column1->HeaderText = L"ID";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Width = 60;
			// 
			// Column2
			// 
			dataGridViewCellStyle27->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			dataGridViewCellStyle27->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle27->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			dataGridViewCellStyle27->SelectionForeColor = System::Drawing::Color::Black;
			this->Column2->DefaultCellStyle = dataGridViewCellStyle27;
			this->Column2->HeaderText = L"Nickname";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Width = 115;
			// 
			// Column3
			// 
			dataGridViewCellStyle28->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			dataGridViewCellStyle28->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle28->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			dataGridViewCellStyle28->SelectionForeColor = System::Drawing::Color::Black;
			this->Column3->DefaultCellStyle = dataGridViewCellStyle28;
			this->Column3->HeaderText = L"Score";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			this->Column3->Width = 70;
			// 
			// Column4
			// 
			dataGridViewCellStyle29->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			dataGridViewCellStyle29->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle29->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			dataGridViewCellStyle29->SelectionForeColor = System::Drawing::Color::Black;
			this->Column4->DefaultCellStyle = dataGridViewCellStyle29;
			this->Column4->HeaderText = L"Correct Answers";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			this->Column4->Width = 110;
			// 
			// Column5
			// 
			dataGridViewCellStyle30->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			dataGridViewCellStyle30->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle30->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			dataGridViewCellStyle30->SelectionForeColor = System::Drawing::Color::Black;
			this->Column5->DefaultCellStyle = dataGridViewCellStyle30;
			this->Column5->HeaderText = L"Mark";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			this->Column5->Width = 90;
			// 
			// SearchRTable
			// 
			this->SearchRTable->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->SearchRTable->Location = System::Drawing::Point(499, 183);
			this->SearchRTable->Name = L"SearchRTable";
			this->SearchRTable->Size = System::Drawing::Size(130, 30);
			this->SearchRTable->TabIndex = 2;
			this->SearchRTable->Text = L"Search";
			this->SearchRTable->UseVisualStyleBackColor = true;
			this->SearchRTable->Click += gcnew System::EventHandler(this, &Rating_Table::SearchRTable_Click);
			// 
			// OpenRTable
			// 
			this->OpenRTable->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OpenRTable->Location = System::Drawing::Point(499, 64);
			this->OpenRTable->Name = L"OpenRTable";
			this->OpenRTable->Size = System::Drawing::Size(130, 30);
			this->OpenRTable->TabIndex = 1;
			this->OpenRTable->Text = L"Open";
			this->OpenRTable->UseVisualStyleBackColor = true;
			this->OpenRTable->Click += gcnew System::EventHandler(this, &Rating_Table::OpenRTable_Click);
			// 
			// SaveRTable
			// 
			this->SaveRTable->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->SaveRTable->Location = System::Drawing::Point(499, 100);
			this->SaveRTable->Name = L"SaveRTable";
			this->SaveRTable->Size = System::Drawing::Size(130, 30);
			this->SaveRTable->TabIndex = 0;
			this->SaveRTable->Text = L"Save";
			this->SaveRTable->UseVisualStyleBackColor = true;
			this->SaveRTable->Click += gcnew System::EventHandler(this, &Rating_Table::SaveRTable_Click);
			// 
			// Rating_Table
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->ClientSize = System::Drawing::Size(1260, 606);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Rating_Table";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Rating Table";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Rating_Table::Rating_Table_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Rating_Table::Rating_Table_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		// Вывод списка в основную таблицу
	private: void Scan_ListRT(LISTratingTable* LRT) {
		dataGridView1->Rows->Clear();
		if (LRT == nullptr) 
		{
			if (checkLang == 1)
			{
				MessageBox::Show("Список рейтинга пуст!", "Информация",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else
			{
				MessageBox::Show("The rating list is empty!", "Information",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			return;
		}

		int i = 0;
		LISTratingTable* current = LRT;

		while (current != nullptr) 
		{
			dataGridView1->Rows->Add();
			dataGridView1->Rows[i]->Cells[0]->Value = current->element.id.ToString();
			if (!current->element.nickname.empty()) 
			{
				dataGridView1->Rows[i]->Cells[1]->Value = marshal_as<String^>(current->element.nickname);
			}
			else 
			{
				dataGridView1->Rows[i]->Cells[1]->Value = "N/A";
			}
			dataGridView1->Rows[i]->Cells[2]->Value = current->element.score.ToString();
			dataGridView1->Rows[i]->Cells[3]->Value = current->element.correctAnswers.ToString();
			dataGridView1->Rows[i]->Cells[4]->Value = current->element.mark.ToString();
			current = current->next;
			i++;
		}
		dataGridView1->Refresh();
		int totalHeight = dataGridView1->ColumnHeadersHeight;
		for (int j = 0; j < dataGridView1->Rows->Count; j++)
		{
			totalHeight += dataGridView1->Rows[j]->Height;
		}
		if (dataGridView1->Rows->Count > 0)
		{
			totalHeight += dataGridView1->Rows[0]->Height;
		}
		if (totalHeight > 517) {
			totalHeight = 517;
		}
		dataGridView1->Height = totalHeight;
	}
		   // Открытие и вывод списка в таблицу
		   private: void LoadRT() {
			   if (LRT != NULL)
				   while (LRT != NULL)
					   LRT = DelFirst_List_RT(LRT);
			   std::ifstream f("PlayerResults.txt");
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

			   ratingTable v;
			   if (f >> v.id >> std::ws >> std::quoted(v.nickname)
				   >> v.score >> v.correctAnswers >> v.mark)
			   {
				   LRT = Init_List_RT(v);
				   LISTratingTable* q = LRT;

				   while (f >> v.id >> std::ws >> std::quoted(v.nickname)
					   >> v.score >> v.correctAnswers >> v.mark)
				   {
					   LISTratingTable* n = new LISTratingTable;
					   n->element = v;
					   n->next = nullptr;
					   q->next = n;
					   q = n;
				   }
			   }
			   else
			   {
				   if (checkLang == 1)
				   {
					   MessageBox::Show("Файл пуст или содержит некорректные данные", "Сообщение",
						   MessageBoxButtons::OK, MessageBoxIcon::Information);
				   }
				   else
				   {
					   MessageBox::Show("The file is empty or contains incorrect data", "Message",
						   MessageBoxButtons::OK, MessageBoxIcon::Information);
				   }
			   }

			   f.close();
			   Scan_ListRT(LRT);
		   }
	private: System::Void Rating_Table_Load(System::Object^ sender, System::EventArgs^ e) {
		LoadRT();
	}
	private: System::Void OpenRTable_Click(System::Object^ sender, System::EventArgs^ e) {
		LoadRT();
	}	
private: System::Void Rating_Table_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	SavestRatingList(LRT, checkLang);
}
private: System::Void SaveRTable_Click(System::Object^ sender, System::EventArgs^ e) {
	SavestRatingList(LRT, checkLang);
}
private: System::Void SearchRTable_Click(System::Object^ sender, System::EventArgs^ e) {
	try 
	{
		if (comboBox1->SelectedIndex < 0) 
		{
			if (checkLang == 1)
			{

				MessageBox::Show("Выберите поле для поиска!", "Поиск",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else
			{
				MessageBox::Show("Select the search field!", "Search",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		SL = NULL;
		LISTratingTable* FL = NULL;
		LISTratingTable* F = NULL;

		if (comboBox1->SelectedIndex == 0) 
		{
			if (textBoxForSearch->Text == "") 
			{
				if (checkLang == 1)
				{
					MessageBox::Show("Введите «ID» для поиска!", "Повторите ввод",
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
				else
				{
					MessageBox::Show("Enter \"ID\" to search!", "Repeat the input",
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
			}
			else 
			{
				dataGridView2->Rows->Clear();
				ratingTable v;
				LISTratingTable* q = LRT;
				int i = 0;
				int searchNUM = Convert::ToInt32(textBoxForSearch->Text);
				bool find = false;
				if (q != NULL) {
					v.id = searchNUM; //поиск по id
					LISTratingTable* F = Find_id_List(q, v);
					while (F != NULL) 
					{
						dataGridView2->Rows->Add();
						dataGridView2->Rows[i]->Cells[0]->Value = F->element.id.ToString();
						dataGridView2->Rows[i]->Cells[1]->Value = marshal_as<String^>(F->element.nickname);
						dataGridView2->Rows[i]->Cells[2]->Value = F->element.score.ToString();
						dataGridView2->Rows[i]->Cells[3]->Value = F->element.correctAnswers.ToString();
						dataGridView2->Rows[i]->Cells[4]->Value = F->element.mark.ToString();
						i++;
						find = true;
						F = F->next;
						F = Find_id_List(F, v);
					}
					int totalHeight = dataGridView2->ColumnHeadersHeight;
					for (int j = 0; j < dataGridView2->Rows->Count; j++)
					{
						totalHeight += dataGridView2->Rows[j]->Height;
					}
					if (dataGridView2->Rows->Count > 0)
					{
						totalHeight += dataGridView2->Rows[0]->Height;
					}
					if (totalHeight > 517) {
						totalHeight = 517;
					}
					dataGridView2->Height = totalHeight;
				}
				if (find == false) 
				{
					if (checkLang == 1)
					{
						MessageBox::Show("Ничего не найдено!", "Поиск",
							MessageBoxButtons::OK, MessageBoxIcon::Information);
					}
					else
					{
						MessageBox::Show("Nothing was found!", "Search",
							MessageBoxButtons::OK, MessageBoxIcon::Information);
					}
					return;
				}
			}
		}

		if (comboBox1->SelectedIndex == 1) 
		{
			if (textBoxForSearch->Text == "") 
			{
				if (checkLang == 1)
				{
					MessageBox::Show("Введите «Ник» для поиска!", "Повторите ввод",
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
				else
				{
					MessageBox::Show("Enter \"Nickname\" to search!", "Repeat the input",
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
			}
			else 
			{
				dataGridView2->Rows->Clear();
				ratingTable v;
				LISTratingTable* q = LRT;
				int i = 0;
				marshal_context^ context = gcnew marshal_context();
				std::string search = context->marshal_as< std::string >(textBoxForSearch->Text->ToString());
				bool find = false;
				if (q != NULL) {
					v.nickname = search; //поиск по nickname
					LISTratingTable* F = Find_nickname_List(q, v);
					while (F != NULL) 
					{
						dataGridView2->Rows->Add();
						dataGridView2->Rows[i]->Cells[0]->Value = F->element.id.ToString();
						dataGridView2->Rows[i]->Cells[1]->Value = marshal_as<String^>(F->element.nickname);
						dataGridView2->Rows[i]->Cells[2]->Value = F->element.score.ToString();
						dataGridView2->Rows[i]->Cells[3]->Value = F->element.correctAnswers.ToString();
						dataGridView2->Rows[i]->Cells[4]->Value = F->element.mark.ToString();
						i++;
						find = true;
						F = F->next;
						F = Find_nickname_List(F, v);
					}
					int totalHeight = dataGridView2->ColumnHeadersHeight;
					for (int j = 0; j < dataGridView2->Rows->Count; j++)
					{
						totalHeight += dataGridView2->Rows[j]->Height;
					}
					if (dataGridView2->Rows->Count > 0)
					{
						totalHeight += dataGridView2->Rows[0]->Height;
					}
					if (totalHeight > 517) {
						totalHeight = 517;
					}
					dataGridView2->Height = totalHeight;
				}
				if (find == false) 
				{
					if (checkLang == 1)
					{
						MessageBox::Show("Ничего не найдено!", "Поиск",
							MessageBoxButtons::OK, MessageBoxIcon::Information);
					}
					else
					{
						MessageBox::Show("Nothing was found!", "Search",
							MessageBoxButtons::OK, MessageBoxIcon::Information);
					}
					return;
				}
			}
		}

		if (comboBox1->SelectedIndex == 2) 
		{
			if (textBoxForSearch->Text == "") 
			{
				if (checkLang == 1)
				{
					MessageBox::Show("Введите «Очки» для поиска!", "Повторите ввод",
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
				else
				{
					MessageBox::Show("Enter \"Score\" to search!", "Repeat the input",
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
			}
			else 
			{
				dataGridView2->Rows->Clear();
				ratingTable v;
				LISTratingTable* q = LRT;
				int i = 0;
				int searchNUM = Convert::ToInt32(textBoxForSearch->Text);
				bool find = false;
				if (q != NULL) {
					v.score = searchNUM; //поиск по score
					LISTratingTable* F = Find_score_List(q, v);
					while (F != NULL) 
					{
						dataGridView2->Rows->Add();
						dataGridView2->Rows[i]->Cells[0]->Value = F->element.id.ToString();
						dataGridView2->Rows[i]->Cells[1]->Value = marshal_as<String^>(F->element.nickname);
						dataGridView2->Rows[i]->Cells[2]->Value = F->element.score.ToString();
						dataGridView2->Rows[i]->Cells[3]->Value = F->element.correctAnswers.ToString();
						dataGridView2->Rows[i]->Cells[4]->Value = F->element.mark.ToString();
						i++;
						find = true;
						F = F->next;
						F = Find_score_List(F, v);
					}
					int totalHeight = dataGridView2->ColumnHeadersHeight;
					for (int j = 0; j < dataGridView2->Rows->Count; j++)
					{
						totalHeight += dataGridView2->Rows[j]->Height;
					}
					if (dataGridView2->Rows->Count > 0)
					{
						totalHeight += dataGridView2->Rows[0]->Height;
					}
					if (totalHeight > 517) {
						totalHeight = 517;
					}
					dataGridView2->Height = totalHeight;
				}
				if (find == false) 
				{
					if (checkLang == 1)
					{
						MessageBox::Show("Ничего не найдено!", "Поиск",
							MessageBoxButtons::OK, MessageBoxIcon::Information);
					}
					else
					{
						MessageBox::Show("Nothing was found!", "Search",
							MessageBoxButtons::OK, MessageBoxIcon::Information);
					}
					return;
				}
			}
		}

		if (comboBox1->SelectedIndex == 3) 
		{
			if (textBoxForSearch->Text == "") 
			{
				if (checkLang == 1)
				{
					MessageBox::Show("Введите «Верные ответы» для поиска!", "Повторите ввод",
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
				else
				{
					MessageBox::Show("Enter \"Correct answers\" to search!", "Repeat the input",
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
			}
			else 
			{
				dataGridView2->Rows->Clear();
				ratingTable v;
				LISTratingTable* q = LRT;
				int i = 0;
				int searchNUM = Convert::ToInt32(textBoxForSearch->Text);
				bool find = false;
				if (q != NULL) {
					v.correctAnswers = searchNUM; //поиск по correctAnswers
					LISTratingTable* F = Find_correctAnswers_List(q, v);
					while (F != NULL) 
					{
						dataGridView2->Rows->Add();
						dataGridView2->Rows[i]->Cells[0]->Value = F->element.id.ToString();
						dataGridView2->Rows[i]->Cells[1]->Value = marshal_as<String^>(F->element.nickname);
						dataGridView2->Rows[i]->Cells[2]->Value = F->element.score.ToString();
						dataGridView2->Rows[i]->Cells[3]->Value = F->element.correctAnswers.ToString();
						dataGridView2->Rows[i]->Cells[4]->Value = F->element.mark.ToString();
						i++;
						find = true;
						F = F->next;
						F = Find_correctAnswers_List(F, v);
					}
					int totalHeight = dataGridView2->ColumnHeadersHeight;
					for (int j = 0; j < dataGridView2->Rows->Count; j++)
					{
						totalHeight += dataGridView2->Rows[j]->Height;
					}
					if (dataGridView2->Rows->Count > 0)
					{
						totalHeight += dataGridView2->Rows[0]->Height;
					}
					if (totalHeight > 517) {
						totalHeight = 517;
					}
					dataGridView2->Height = totalHeight;
				}
				if (find == false) 
				{
					if (checkLang == 1)
					{
						MessageBox::Show("Ничего не найдено!", "Поиск",
							MessageBoxButtons::OK, MessageBoxIcon::Information);
					}
					else
					{
						MessageBox::Show("Nothing was found!", "Search",
							MessageBoxButtons::OK, MessageBoxIcon::Information);
					}
					return;
				}
			}
		}

		if (comboBox1->SelectedIndex == 4) 
		{
			if (textBoxForSearch->Text == "") 
			{
				if (checkLang == 1)
				{
					MessageBox::Show("Введите «Оценка» для поиска!", "Повторите ввод",
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
				else
				{
					MessageBox::Show("Enter \"Mark\" to search!", "Repeat the input",
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
			}
			else 
			{
				dataGridView2->Rows->Clear();
				ratingTable v;
				LISTratingTable* q = LRT;
				int i = 0;
				int searchNUM = Convert::ToInt32(textBoxForSearch->Text);
				bool find = false;
				if (q != NULL) {
					v.mark = searchNUM; //поиск по mark
					LISTratingTable* F = Find_mark_List(q, v);
					while (F != NULL) 
					{
						dataGridView2->Rows->Add();
						dataGridView2->Rows[i]->Cells[0]->Value = F->element.id.ToString();
						dataGridView2->Rows[i]->Cells[1]->Value = marshal_as<String^>(F->element.nickname);
						dataGridView2->Rows[i]->Cells[2]->Value = F->element.score.ToString();
						dataGridView2->Rows[i]->Cells[3]->Value = F->element.correctAnswers.ToString();
						dataGridView2->Rows[i]->Cells[4]->Value = F->element.mark.ToString();
						i++;
						find = true;
						F = F->next;
						F = Find_mark_List(F, v);
					}
					int totalHeight = dataGridView2->ColumnHeadersHeight;
					for (int j = 0; j < dataGridView2->Rows->Count; j++)
					{
						totalHeight += dataGridView2->Rows[j]->Height;
					}
					if (dataGridView2->Rows->Count > 0)
					{
						totalHeight += dataGridView2->Rows[0]->Height;
					}
					dataGridView2->Height = totalHeight;
				}
				if (find == false) 
				{
					if (checkLang == 1)
					{
						MessageBox::Show("Ничего не найдено!", "Поиск",
							MessageBoxButtons::OK, MessageBoxIcon::Information);
					}
					else
					{
						MessageBox::Show("Nothing was found!", "Search",
							MessageBoxButtons::OK, MessageBoxIcon::Information);
					}
					return;
				}
			}
		}
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
}
private: System::Void button_del_id_Click(System::Object^ sender, System::EventArgs^ e) {
	try
	{
		ratingTable v;
		marshal_context^ context = gcnew marshal_context();
		if (textBoxDelID->Text == "")
		{
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
			return;
		}

		int search = Int32::Parse(textBoxDelID->Text);
		v.id = search;
		LISTratingTable* address;
		address = Find_id_List(LRT, v);
		while (address != nullptr)
		{
			LISTratingTable* nextAddress = Find_id_List(address->next, v); // Ищем следующий

			if (address == LRT) {
				LRT = DelFirst_List_RT(LRT);
			}
			else {
				LRT = Del_List_RT(LRT, address); // Всегда обновляем LRT
			}

			address = nextAddress; // Переход к следующему
		}
		Scan_ListRT(LRT);

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
}
private: System::Void button_del_nickname_Click(System::Object^ sender, System::EventArgs^ e) {
	try 
	{
		ratingTable v;
		marshal_context^ context = gcnew marshal_context();
		if (textBoxDelNickname->Text == "") 
		{
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
			std::string search = context->marshal_as< std::string >(textBoxDelNickname->Text->ToString());
			v.nickname = search;
			LISTratingTable* address;
			address = Find_nickname_List(LRT, v);
			while (address != NULL) 
			{
				if (address == LRT) 
				{
					LRT = DelFirst_List_RT(LRT);
					address = NULL;
				}
				else 
				{
					Del_List_RT(LRT, address);
					address = Find_nickname_List(LRT, xRT);
				}
			}
			Scan_ListRT(LRT);
		}
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
}
private: System::Void CleanRTableMain_Click(System::Object^ sender, System::EventArgs^ e) {
	dataGridView1->Rows->Clear();
}
private: System::Void SortRTableMain_Click(System::Object^ sender, System::EventArgs^ e) {
	try 
	{
		if (comboBoxMainTypeSort->SelectedIndex < 0) 
		{
			if (checkLang == 1)
			{
				MessageBox::Show("Выберите тип сортировки!", "Сортировка",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else
			{
				MessageBox::Show("Choose the sort type!", "Sort",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		if (comboBoxForMainSort->SelectedIndex < 0) 
		{
			if (checkLang == 1)
			{
				MessageBox::Show("Выберите поле для сортировки!", "Сортировка",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else
			{
				MessageBox::Show("Select the field to sort!", "Sort",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		int fieldSort = comboBoxForMainSort->SelectedIndex;

		if (comboBoxMainTypeSort->SelectedIndex == 0) 
		{ //убывание
			switch (fieldSort) {
			case 0: Sort_id_1(LRT); break;
			case 1: Sort_nickname_1(LRT); break;
			case 2: Sort_score_1(LRT); break;
			case 3:	Sort_correctAnswers_1(LRT); break;
			case 4: Sort_mark_1(LRT); break;
			}
		}

		if (comboBoxMainTypeSort->SelectedIndex == 1) 
		{ //возрастание
			switch (fieldSort) {
			case 0: Sort_id_2(LRT); break;
			case 1: Sort_nickname_2(LRT); break;
			case 2: Sort_score_2(LRT); break;
			case 3:	Sort_correctAnswers_2(LRT); break;
			case 4: Sort_mark_2(LRT); break;
			}
		}

		Scan_ListRT(LRT);
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
}
private: System::Void CleanRTableForSearch_Click(System::Object^ sender, System::EventArgs^ e) {
	dataGridView2->Rows->Clear();
}
	   public: void OnChangeLangEngRating_Table(Object^ sender, EventArgs^ e) {
		   checkLang = 0;

		   this->Text = L"Rating Table";
		   groupBox1->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(0)));
		   groupBox1->Text = L"Rating table";
		   button_del_id->Text = L"Delete";
		   label9->Text = L"Nickname";
		   button_del_nickname->Text = L"Delete";
		   comboBoxMainTypeSort->Items->Clear();
		   comboBoxMainTypeSort->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Decreasing", L"Increasing" });
		   comboBoxForMainSort->Items->Clear();
		   comboBoxForMainSort->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
			   L"ID", L"Nickname", L"Score", L"Correct answers",
				   L"Mark"
		   });
		   CleanRTableForSearch->Text = L"Clear";
		   CleanRTableMain->Text = L"Clear";
		   comboBox1->Items->Clear();
		   comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
			   L"ID", L"Nickname", L"Score", L"Correct answers",
				   L"Mark"
		   });
		   SortRTableMain->Text = L"Sort";
		   SearchRTable->Text = L"Search";
		   OpenRTable->Text = L"Open";
		   SaveRTable->Text = L"Save";
		   Column2->HeaderText = L"Nickname";
		   Column3->HeaderText = L"Score";
		   Column4->HeaderText = L"Correct Answers";
		   Column5->HeaderText = L"Mark";
		   dataGridViewTextBoxColumn2->HeaderText = L"Nickname";
		   dataGridViewTextBoxColumn3->HeaderText = L"Score";
		   dataGridViewTextBoxColumn4->HeaderText = L"Correct Answers";
		   dataGridViewTextBoxColumn5->HeaderText = L"Mark";
	   }
	public: void OnChangeLangRusRating_Table(Object^ sender, EventArgs^ e) {
		checkLang = 1;

		this->Text = L"Таблица Рейтинга";
		groupBox1->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		groupBox1->Text = L"Таблица рейтинга";
		button_del_id->Text = L"Удалить";
		label9->Text = L"Ник";
		button_del_nickname->Text = L"Удалить";
		comboBoxMainTypeSort->Items->Clear();
		comboBoxMainTypeSort->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Убывание", L"Возрастание" });
		comboBoxForMainSort->Items->Clear();
		comboBoxForMainSort->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
			L"ID", L"Ник", L"Очки", L"Верные ответы",
				L"Оценка"
		});
		CleanRTableForSearch->Text = L"Очистить";
		CleanRTableMain->Text = L"Очистить";
		comboBox1->Items->Clear();
		comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
			L"ID", L"Ник", L"Очки", L"Верные ответы",
				L"Оценка"
		});
		SortRTableMain->Text = L"Сортировать";
		SearchRTable->Text = L"Поиск";
		OpenRTable->Text = L"Открыть";
		SaveRTable->Text = L"Сохранить";
		Column2->HeaderText = L"Ник";
		Column3->HeaderText = L"Очки";
		Column4->HeaderText = L"Верные ответы";
		Column5->HeaderText = L"Оценка";
		dataGridViewTextBoxColumn2->HeaderText = L"Ник";
		dataGridViewTextBoxColumn3->HeaderText = L"Очки";
		dataGridViewTextBoxColumn4->HeaderText = L"Верные ответы";
		dataGridViewTextBoxColumn5->HeaderText = L"Оценка";
	}
};
}
