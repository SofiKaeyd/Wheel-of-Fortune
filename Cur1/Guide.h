/*
**************************************************************
Модуль Guide.h
гр. П22
Разработчик: Баглаева С. А.
Модифицирован: 10 июня 2025
--------------------------------------------------------------
Модуль окна входа
**************************************************************
*/

#pragma once
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
	/// Сводка для Guide
	/// </summary>
	public ref class Guide : public System::Windows::Forms::Form
	{
	public:
		int checkLang;
	public:
		Guide(void)
		{
			InitializeComponent();
			checkLang = 0;
		}
	protected:
		~Guide()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ buttonChangeGuide;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBoxComAdminPass;
	private: System::Windows::Forms::Button^ btnArrowNext;
	private: System::Windows::Forms::Button^ buttonOpenGuid;
	private: System::Windows::Forms::Button^ buttonSaveGuide;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Guide::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->buttonSaveGuide = (gcnew System::Windows::Forms::Button());
			this->buttonOpenGuid = (gcnew System::Windows::Forms::Button());
			this->btnArrowNext = (gcnew System::Windows::Forms::Button());
			this->textBoxComAdminPass = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->buttonChangeGuide = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->panel1->Controls->Add(this->dataGridView1);
			this->panel1->Controls->Add(this->buttonSaveGuide);
			this->panel1->Controls->Add(this->buttonOpenGuid);
			this->panel1->Controls->Add(this->btnArrowNext);
			this->panel1->Controls->Add(this->textBoxComAdminPass);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->buttonChangeGuide);
			this->panel1->Font = (gcnew System::Drawing::Font(L"Geometr212 BkCn BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(799, 791);
			this->panel1->TabIndex = 5;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Geometr212 BkCn BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->GridColor = System::Drawing::SystemColors::ButtonFace;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->dataGridView1->Size = System::Drawing::Size(629, 791);
			this->dataGridView1->StandardTab = true;
			this->dataGridView1->TabIndex = 19;
			// 
			// buttonSaveGuide
			// 
			this->buttonSaveGuide->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonSaveGuide->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonSaveGuide->Location = System::Drawing::Point(637, 48);
			this->buttonSaveGuide->Name = L"buttonSaveGuide";
			this->buttonSaveGuide->Size = System::Drawing::Size(162, 39);
			this->buttonSaveGuide->TabIndex = 18;
			this->buttonSaveGuide->Text = L"Save guide";
			this->buttonSaveGuide->UseVisualStyleBackColor = true;
			this->buttonSaveGuide->Visible = false;
			this->buttonSaveGuide->Click += gcnew System::EventHandler(this, &Guide::buttonSaveGuide_Click);
			// 
			// buttonOpenGuid
			// 
			this->buttonOpenGuid->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonOpenGuid->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonOpenGuid->Location = System::Drawing::Point(637, 3);
			this->buttonOpenGuid->Name = L"buttonOpenGuid";
			this->buttonOpenGuid->Size = System::Drawing::Size(162, 39);
			this->buttonOpenGuid->TabIndex = 17;
			this->buttonOpenGuid->Text = L"Open guide";
			this->buttonOpenGuid->UseVisualStyleBackColor = true;
			this->buttonOpenGuid->Click += gcnew System::EventHandler(this, &Guide::buttonOpenGuid_Click);
			// 
			// btnArrowNext
			// 
			this->btnArrowNext->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnArrowNext->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnArrowNext->Location = System::Drawing::Point(773, 166);
			this->btnArrowNext->Name = L"btnArrowNext";
			this->btnArrowNext->Size = System::Drawing::Size(26, 27);
			this->btnArrowNext->TabIndex = 16;
			this->btnArrowNext->Text = L">";
			this->btnArrowNext->UseVisualStyleBackColor = true;
			this->btnArrowNext->Click += gcnew System::EventHandler(this, &Guide::btnArrowNext_Click);
			// 
			// textBoxComAdminPass
			// 
			this->textBoxComAdminPass->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBoxComAdminPass->Location = System::Drawing::Point(637, 166);
			this->textBoxComAdminPass->Name = L"textBoxComAdminPass";
			this->textBoxComAdminPass->PasswordChar = '*';
			this->textBoxComAdminPass->Size = System::Drawing::Size(130, 27);
			this->textBoxComAdminPass->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->Font = (gcnew System::Drawing::Font(L"Geometr212 BkCn BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(639, 107);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(157, 56);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Enter the password to change a guide";
			// 
			// buttonChangeGuide
			// 
			this->buttonChangeGuide->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonChangeGuide->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonChangeGuide->Location = System::Drawing::Point(635, 199);
			this->buttonChangeGuide->Name = L"buttonChangeGuide";
			this->buttonChangeGuide->Size = System::Drawing::Size(164, 39);
			this->buttonChangeGuide->TabIndex = 1;
			this->buttonChangeGuide->Text = L"Change guide";
			this->buttonChangeGuide->UseVisualStyleBackColor = true;
			this->buttonChangeGuide->Visible = false;
			this->buttonChangeGuide->Click += gcnew System::EventHandler(this, &Guide::buttonChangeGuide_Click);
			// 
			// Guide
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->ClientSize = System::Drawing::Size(823, 815);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Guide";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Guide";
			this->Load += gcnew System::EventHandler(this, &Guide::Guide_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void btnArrowNext_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textBoxComAdminPass->Text == marshal_as<String^>(Constants::COMMON_ADMIN_PASSW)) 
	{
		buttonChangeGuide->Visible = true;
		buttonSaveGuide->Visible = true;
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
				MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
}
private: System::Void buttonChangeGuide_Click(System::Object^ sender, System::EventArgs^ e) {
	OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
	if (checkLang == 1)
	{
		openFileDialog->Filter = "Текстовые файлы (*.txt)|*.txt|Все файлы (*.*)|*.*";
		openFileDialog->Title = "Выберите файл для загрузки";
	}
	else
	{
		openFileDialog->Filter = "Text file (*.txt)|*.txt|All files (*.*)|*.*";
		openFileDialog->Title = "Select the file to download";
	}	

	if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) 
	{
		System::String^ filePath = openFileDialog->FileName;

		array<System::String^>^ lines = System::IO::File::ReadAllLines(filePath);

		dataGridView1->Columns->Clear();
		dataGridView1->Rows->Clear();
		if (checkLang == 1)
		{
			dataGridView1->Columns->Add("colText", "Новое руководство");
		}
		else
		{
			dataGridView1->Columns->Add("colText", "New guide");
		}		
		dataGridView1->Columns["colText"]->Width = 592;

		dataGridView1->DefaultCellStyle->WrapMode = DataGridViewTriState::True;
		dataGridView1->AutoSizeRowsMode = DataGridViewAutoSizeRowsMode::AllCells;

		for (int i = 0; i < lines->Length; i++) 
		{
			dataGridView1->Rows->Add(lines[i]);
		}
	}
}
	   private: void LoadGT() {
		   std::ifstream ifs("Guide.txt");
		   if (!ifs.is_open())
		   {
			   if (checkLang == 1)
			   {
				   MessageBox::Show("Не удалось открыть файл", "Ошибка",
					   MessageBoxButtons::OK, MessageBoxIcon::Error);
			   }
			   else
			   {
				   MessageBox::Show("Couldn't open the file", "Error",
					   MessageBoxButtons::OK, MessageBoxIcon::Error);
			   }
			   return;
		   }

		   dataGridView1->Rows->Clear();
		   dataGridView1->Columns->Clear();
		   if (checkLang == 1)
		   {
			   dataGridView1->Columns->Add("col0", "Руководство");
		   }
		   else
		   {
			   dataGridView1->Columns->Add("col0", "Guide");
		   }
		   dataGridView1->Columns["col0"]->Width = 592;
		   std::string line;

		   while (std::getline(ifs, line))
		   {
			   System::String^ managedLine = gcnew System::String(line.c_str());
			   dataGridView1->Rows->Add(managedLine);
		   }
		   ifs.close();
	   }
private: System::Void Guide_Load(System::Object^ sender, System::EventArgs^ e) {
	LoadGT();
}
private: System::Void buttonOpenGuid_Click(System::Object^ sender, System::EventArgs^ e) {
	LoadGT();
}
private: System::Void buttonSaveGuide_Click(System::Object^ sender, System::EventArgs^ e) {
	std::ofstream ofs("Guide.txt", std::ios::out);
	if (!ofs.is_open()) 
	{
		if (checkLang == 1)
		{
			MessageBox::Show("Не удалось открыть файл", "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else
		{
			MessageBox::Show("Couldn't open the file", "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		return;
	}

	for (int i = 0; i < dataGridView1->Rows->Count; i++) 
	{
		DataGridViewRow^ row = dataGridView1->Rows[i];
		if (row->IsNewRow) continue;
		if (row->Cells[0]->Value != nullptr) {
			std::string cellStr = msclr::interop::marshal_as<std::string>(
				row->Cells[0]->Value->ToString());
			ofs << cellStr << std::endl;
		}
	}

	ofs.close();
}
	public: void OnChangeLangEngGuide(Object^ sender, EventArgs^ e) {
		checkLang = 0;

		this->Text = L"Guide";
		panel1->Font = (gcnew System::Drawing::Font(L"Geometr212 BkCn BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		buttonSaveGuide->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		buttonSaveGuide->Text = L"Save guide";
		buttonOpenGuid->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		buttonOpenGuid->Text = L"Open guide";
		label1->Font = (gcnew System::Drawing::Font(L"Geometr212 BkCn BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		label1->Text = L"Enter the password to change a guide";
		buttonChangeGuide->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		buttonChangeGuide->Text = L"Change guide";
	}
	public: void OnChangeLangRusGuide(Object^ sender, EventArgs^ e) {
		checkLang = 1;

		this->Text = L"Руководство";
		panel1->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		buttonSaveGuide->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		buttonSaveGuide->Text = L"Сохранить";
		buttonOpenGuid->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		buttonOpenGuid->Text = L"Открыть";
		label1->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		label1->Text = L"Введите пароль, чтобы изменить руководство";
		buttonChangeGuide->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		buttonChangeGuide->Text = L"Изменить";
	}
};
}
