/*
**************************************************************
Модуль MyForm.h
гр. П22
Разработчик: Баглаева С. А.
Модифицирован: 10 июня 2025
--------------------------------------------------------------
Модуль окна входа
**************************************************************
*/

#pragma once
#include "Quetions.h"
#include "Rating_Table.h"
#include "QuetionForm.h"
#include "Guide.h"
#include "fun.h"
#include "UserClasses.h"
#include <time.h>
#include <cmath>

namespace Cur1 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		Quetions^ questionsForm;
		Player^ currentPlayer;
		static int checkLang;
	public:
		event EventHandler^ logoutSuccess;
		event EventHandler^ ChangeLangEng;
		event EventHandler^ ChangeLangRus;
		event EventHandler^ ViewTables;
	protected:
		void OnChangeLangEng(EventArgs^ e) {
			ChangeLangEng(this, e);
		}
		void OnChangeLangRus(EventArgs^ e) {
			ChangeLangRus(this, e);
		}
		void OnViewTables(EventArgs^ e) {
			ViewTables(this, e);
		}
	public:
		MyForm(void)
		{
			InitializeComponent();
			// Создание объекта "колесо Фортуны" для администратора
			wheelFortune = gcnew LuckyCirlce();
			luckyCircle = gcnew LuckyCirlce();
			pictureBox1->Image = luckyCircle->pictureWheel; // Начальное изображение

			checkLang = 0;
		}
	public:
		MyForm(Player^ player) 
		{
			InitializeComponent();
			currentPlayer = player;

			// Создание объекта "колесо Фортуны" для игрока
			wheelFortune = gcnew LuckyCirlce();
			luckyCircle = gcnew LuckyCirlce();
			wheelIsMoved = false;
			angleStep = 0.0f;
			pictureBox1->Image = luckyCircle->pictureWheel; // Начальное изображение

			questionsForm = gcnew Quetions();

			playTimes = 10;

			checkLang = 0;
		}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		// Переменные формы
		bool wheelIsMoved;
		float angleStep;
		int playTimes;
	private: System::Windows::Forms::Button^ buttonUpdateRT;
	private: System::Windows::Forms::Button^ btnOpenGuide;
	private: System::Windows::Forms::DataGridView^ dgvCP;
	private: System::Windows::Forms::Label^ label_playNumTim;
	private: System::Windows::Forms::Label^ label_playTimes;
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
	private: System::Windows::Forms::ComboBox^ comboBox_language;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ Open_Table;
	private: System::Windows::Forms::ComboBox^ comboBox_Sw_Col;

	public:
		// Класс "LuckyCirlce" описывает фото-ресурс колеса и его состояние
		ref class LuckyCirlce
		{
		public:
			Bitmap^ pictureWheel;
			Bitmap^ tempPictureWheel;
			float angle;                     // Текущий угол поворота
			array<int>^ statusValues;      // Значения состояний
			int position;                      // Индекс текущего значения

			LuckyCirlce()
			{
				// Загрузка изображения
				String^ nameCurrentWheel = ReadWheelImageFromFile("WheelImage.txt");
				String^ currentWheel = ".\\lucky_wheel_" + nameCurrentWheel + ".png";
				ChangeImage(currentWheel);
				statusValues = gcnew array<int>(10) { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
				angle = 0.0f;
				position = 0;
			}

			// Метод для изменения изображений
			void ChangeImage(String^ imagePath) {
				// Удаление старых изображений
				if (pictureWheel != nullptr) delete pictureWheel;
				if (tempPictureWheel != nullptr) delete tempPictureWheel;

				// Загрузка новых изображений
				pictureWheel = gcnew Bitmap(imagePath);
				tempPictureWheel = gcnew Bitmap(imagePath);

				// Сброс состояния
				angle = 0.0f;
				position = 0;
			}
		};

	private:
		LuckyCirlce^ wheelFortune;
		LuckyCirlce^ luckyCircle;
	private: System::Windows::Forms::Button^ button_logout;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::DataGridView^ dgvRT;		   

	public:
		// Статический метод для поворота изображения с указанным углом
		static Bitmap^ RotateImage(Image^ image, float angle) {			
			PointF offset((float)image->Width / 2, (float)image->Height / 2); // Вычисление смещения – центра изображения.
			return RotateImage(image, offset, angle);
		}

		// Перегруженная версия RotateImage: принимает смещение
		static Bitmap^ RotateImage(Image^ image, PointF offset, float angle) {
			if (image == nullptr)
			{
				throw gcnew ArgumentNullException("image"); // Предотвращает ошибку NullReferenceException, если изображение null
			}
			// Новое изображения с размерами исходного
			Bitmap^ rotatedBmp = gcnew Bitmap(image->Width, image->Height);
			Graphics^ g = Graphics::FromImage(rotatedBmp);
			// Выполнение преобразования: смещение, поворот, обратное смещение
			g->TranslateTransform(offset.X, offset.Y);
			g->RotateTransform(angle);
			g->TranslateTransform(-offset.X, -offset.Y);
			g->DrawImage(image, PointF(0, 0));
			delete g;
			return rotatedBmp;
		}	

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ btnPlay;
private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::Timer^ wheelTimer;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle7 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle8 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle9 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle10 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnPlay = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->wheelTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->Open_Table = (gcnew System::Windows::Forms::Button());
			this->comboBox_Sw_Col = (gcnew System::Windows::Forms::ComboBox());
			this->button_logout = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->comboBox_language = (gcnew System::Windows::Forms::ComboBox());
			this->label_playNumTim = (gcnew System::Windows::Forms::Label());
			this->label_playTimes = (gcnew System::Windows::Forms::Label());
			this->buttonUpdateRT = (gcnew System::Windows::Forms::Button());
			this->dgvCP = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnOpenGuide = (gcnew System::Windows::Forms::Button());
			this->dgvRT = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCP))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRT))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(1058, 0);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(266, 40);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Add Questions";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(478, 160);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(365, 358);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// btnPlay
			// 
			this->btnPlay->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnPlay->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnPlay->Location = System::Drawing::Point(546, 524);
			this->btnPlay->Name = L"btnPlay";
			this->btnPlay->Size = System::Drawing::Size(225, 46);
			this->btnPlay->TabIndex = 2;
			this->btnPlay->Text = L"Play";
			this->btnPlay->UseVisualStyleBackColor = true;
			this->btnPlay->Click += gcnew System::EventHandler(this, &MyForm::btnPlay_Click);
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 50.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(616, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(74, 81);
			this->label1->TabIndex = 3;
			this->label1->Text = L"1";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// wheelTimer
			// 
			this->wheelTimer->Interval = 50;
			this->wheelTimer->Tick += gcnew System::EventHandler(this, &MyForm::wheelTimer_Tick);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(478, 105);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(365, 92);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 4;
			this->pictureBox2->TabStop = false;
			// 
			// Open_Table
			// 
			this->Open_Table->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Open_Table->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Open_Table->Location = System::Drawing::Point(1058, 44);
			this->Open_Table->Name = L"Open_Table";
			this->Open_Table->Size = System::Drawing::Size(266, 40);
			this->Open_Table->TabIndex = 5;
			this->Open_Table->Text = L"Rating Table";
			this->Open_Table->UseVisualStyleBackColor = true;
			this->Open_Table->Click += gcnew System::EventHandler(this, &MyForm::Open_Table_Click);
			// 
			// comboBox_Sw_Col
			// 
			this->comboBox_Sw_Col->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->comboBox_Sw_Col->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox_Sw_Col->FormattingEnabled = true;
			this->comboBox_Sw_Col->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Multicolored", L"Dark", L"Black-white",
					L"Purple", L"Green", L"Blue", L"Red"
			});
			this->comboBox_Sw_Col->Location = System::Drawing::Point(3, 35);
			this->comboBox_Sw_Col->Name = L"comboBox_Sw_Col";
			this->comboBox_Sw_Col->Size = System::Drawing::Size(214, 40);
			this->comboBox_Sw_Col->TabIndex = 7;
			this->comboBox_Sw_Col->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox_Sw_Col_SelectedIndexChanged);
			// 
			// button_logout
			// 
			this->button_logout->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_logout->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_logout->Location = System::Drawing::Point(3, 608);
			this->button_logout->Name = L"button_logout";
			this->button_logout->Size = System::Drawing::Size(237, 47);
			this->button_logout->TabIndex = 9;
			this->button_logout->Text = L"Log Out";
			this->button_logout->UseVisualStyleBackColor = true;
			this->button_logout->Click += gcnew System::EventHandler(this, &MyForm::button_logout_Click);
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(-1, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(209, 32);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Switch the color";
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->Controls->Add(this->button_logout);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Controls->Add(this->comboBox_language);
			this->panel1->Controls->Add(this->btnPlay);
			this->panel1->Controls->Add(this->label_playNumTim);
			this->panel1->Controls->Add(this->label_playTimes);
			this->panel1->Controls->Add(this->buttonUpdateRT);
			this->panel1->Controls->Add(this->dgvCP);
			this->panel1->Controls->Add(this->btnOpenGuide);
			this->panel1->Controls->Add(this->Open_Table);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->dgvRT);
			this->panel1->Controls->Add(this->comboBox_Sw_Col);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->pictureBox2);
			this->panel1->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->panel1->Location = System::Drawing::Point(12, 9);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1327, 658);
			this->panel1->TabIndex = 11;
			// 
			// comboBox_language
			// 
			this->comboBox_language->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->comboBox_language->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox_language->FormattingEnabled = true;
			this->comboBox_language->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Eng", L"Rus" });
			this->comboBox_language->Location = System::Drawing::Point(1229, 615);
			this->comboBox_language->Name = L"comboBox_language";
			this->comboBox_language->Size = System::Drawing::Size(95, 40);
			this->comboBox_language->TabIndex = 17;
			this->comboBox_language->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox_language_SelectedIndexChanged);
			// 
			// label_playNumTim
			// 
			this->label_playNumTim->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label_playNumTim->Font = (gcnew System::Drawing::Font(L"Geometr212 BkCn BT", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_playNumTim->Location = System::Drawing::Point(754, 573);
			this->label_playNumTim->Name = L"label_playNumTim";
			this->label_playNumTim->Size = System::Drawing::Size(45, 39);
			this->label_playNumTim->TabIndex = 16;
			this->label_playNumTim->Text = L"10";
			// 
			// label_playTimes
			// 
			this->label_playTimes->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label_playTimes->AutoSize = true;
			this->label_playTimes->Font = (gcnew System::Drawing::Font(L"Geometr212 BkCn BT", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_playTimes->Location = System::Drawing::Point(518, 573);
			this->label_playTimes->Name = L"label_playTimes";
			this->label_playTimes->Size = System::Drawing::Size(207, 30);
			this->label_playTimes->TabIndex = 15;
			this->label_playTimes->Text = L"Attempts to play:";
			// 
			// buttonUpdateRT
			// 
			this->buttonUpdateRT->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonUpdateRT->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonUpdateRT->Location = System::Drawing::Point(920, 53);
			this->buttonUpdateRT->Name = L"buttonUpdateRT";
			this->buttonUpdateRT->Size = System::Drawing::Size(105, 31);
			this->buttonUpdateRT->TabIndex = 12;
			this->buttonUpdateRT->Text = L"Update";
			this->buttonUpdateRT->UseVisualStyleBackColor = true;
			this->buttonUpdateRT->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// dgvCP
			// 
			this->dgvCP->AllowUserToAddRows = false;
			this->dgvCP->AllowUserToDeleteRows = false;
			this->dgvCP->AllowUserToOrderColumns = true;
			this->dgvCP->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->dgvCP->BackgroundColor = System::Drawing::Color::White;
			this->dgvCP->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvCP->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, this->dataGridViewTextBoxColumn4, this->dataGridViewTextBoxColumn5
			});
			this->dgvCP->Enabled = false;
			this->dgvCP->GridColor = System::Drawing::Color::DarkGray;
			this->dgvCP->Location = System::Drawing::Point(3, 90);
			this->dgvCP->Name = L"dgvCP";
			this->dgvCP->Size = System::Drawing::Size(404, 46);
			this->dgvCP->TabIndex = 13;
			// 
			// dataGridViewTextBoxColumn1
			// 
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::Color::Black;
			this->dataGridViewTextBoxColumn1->DefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridViewTextBoxColumn1->HeaderText = L"ID";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->Width = 40;
			// 
			// dataGridViewTextBoxColumn2
			// 
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::Color::Black;
			this->dataGridViewTextBoxColumn2->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridViewTextBoxColumn2->HeaderText = L"Nickname";
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			// 
			// dataGridViewTextBoxColumn3
			// 
			dataGridViewCellStyle3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::Color::Black;
			this->dataGridViewTextBoxColumn3->DefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridViewTextBoxColumn3->HeaderText = L"Score";
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->Width = 65;
			// 
			// dataGridViewTextBoxColumn4
			// 
			dataGridViewCellStyle4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::Color::Black;
			this->dataGridViewTextBoxColumn4->DefaultCellStyle = dataGridViewCellStyle4;
			this->dataGridViewTextBoxColumn4->HeaderText = L"Correct Answers";
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			this->dataGridViewTextBoxColumn4->Width = 80;
			// 
			// dataGridViewTextBoxColumn5
			// 
			dataGridViewCellStyle5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			dataGridViewCellStyle5->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle5->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			dataGridViewCellStyle5->SelectionForeColor = System::Drawing::Color::Black;
			this->dataGridViewTextBoxColumn5->DefaultCellStyle = dataGridViewCellStyle5;
			this->dataGridViewTextBoxColumn5->HeaderText = L"Mark";
			this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
			this->dataGridViewTextBoxColumn5->Width = 75;
			// 
			// btnOpenGuide
			// 
			this->btnOpenGuide->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnOpenGuide->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnOpenGuide->Location = System::Drawing::Point(3, 549);
			this->btnOpenGuide->Name = L"btnOpenGuide";
			this->btnOpenGuide->Size = System::Drawing::Size(237, 42);
			this->btnOpenGuide->TabIndex = 12;
			this->btnOpenGuide->Text = L"Guide";
			this->btnOpenGuide->UseVisualStyleBackColor = true;
			this->btnOpenGuide->Click += gcnew System::EventHandler(this, &MyForm::btnOpenGuide_Click);
			// 
			// dgvRT
			// 
			this->dgvRT->AllowUserToAddRows = false;
			this->dgvRT->AllowUserToDeleteRows = false;
			this->dgvRT->AllowUserToOrderColumns = true;
			this->dgvRT->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->dgvRT->BackgroundColor = System::Drawing::Color::White;
			this->dgvRT->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvRT->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Column1, this->Column2,
					this->Column3, this->Column4, this->Column5
			});
			this->dgvRT->Enabled = false;
			this->dgvRT->GridColor = System::Drawing::Color::DarkGray;
			this->dgvRT->Location = System::Drawing::Point(920, 90);
			this->dgvRT->Name = L"dgvRT";
			this->dgvRT->Size = System::Drawing::Size(404, 46);
			this->dgvRT->TabIndex = 12;
			// 
			// Column1
			// 
			dataGridViewCellStyle6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			dataGridViewCellStyle6->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle6->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			dataGridViewCellStyle6->SelectionForeColor = System::Drawing::Color::Black;
			this->Column1->DefaultCellStyle = dataGridViewCellStyle6;
			this->Column1->HeaderText = L"ID";
			this->Column1->Name = L"Column1";
			this->Column1->Width = 40;
			// 
			// Column2
			// 
			dataGridViewCellStyle7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			dataGridViewCellStyle7->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle7->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			dataGridViewCellStyle7->SelectionForeColor = System::Drawing::Color::Black;
			this->Column2->DefaultCellStyle = dataGridViewCellStyle7;
			this->Column2->HeaderText = L"Nickname";
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			dataGridViewCellStyle8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			dataGridViewCellStyle8->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle8->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			dataGridViewCellStyle8->SelectionForeColor = System::Drawing::Color::Black;
			this->Column3->DefaultCellStyle = dataGridViewCellStyle8;
			this->Column3->HeaderText = L"Score";
			this->Column3->Name = L"Column3";
			this->Column3->Width = 65;
			// 
			// Column4
			// 
			dataGridViewCellStyle9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			dataGridViewCellStyle9->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle9->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			dataGridViewCellStyle9->SelectionForeColor = System::Drawing::Color::Black;
			this->Column4->DefaultCellStyle = dataGridViewCellStyle9;
			this->Column4->HeaderText = L"Correct Answers";
			this->Column4->Name = L"Column4";
			this->Column4->Width = 80;
			// 
			// Column5
			// 
			dataGridViewCellStyle10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			dataGridViewCellStyle10->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle10->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			dataGridViewCellStyle10->SelectionForeColor = System::Drawing::Color::Black;
			this->Column5->DefaultCellStyle = dataGridViewCellStyle10;
			this->Column5->HeaderText = L"Mark";
			this->Column5->Name = L"Column5";
			this->Column5->Width = 75;
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Inherit;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->ClientSize = System::Drawing::Size(1351, 679);
			this->Controls->Add(this->panel1);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"The wheel of Fortune";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm::MyForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCP))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRT))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	public: void OnPlayerPremissions(Object^ sender, EventArgs^ e) {
		button1->Visible = false;
		buttonUpdateRT->Visible = false;
		Open_Table->Visible = false;
		btnOpenGuide->Visible = true;
		button_logout->Visible = true;
		pictureBox2->Visible = true;
		pictureBox1->Visible = true;
		btnPlay->Visible = true;
		label1->Visible = true;
		label2->Visible = true;
		comboBox_Sw_Col->Visible = true;
		dgvRT->Visible = true;
		dgvCP->Visible = true;
		label_playTimes->Visible = true;
		label_playNumTim->Visible = true;
	}

	public: void OnAdminPremissions(Object^ sender, EventArgs^ e) {
		button1->Visible = true;
		buttonUpdateRT->Visible = true;
		Open_Table->Visible = true;
		btnOpenGuide->Visible = true;
		button_logout->Visible = true;
		pictureBox2->Visible = true;
		pictureBox1->Visible = true;
		btnPlay->Visible = false;
		label1->Visible = true;
		label2->Visible = true;
		comboBox_Sw_Col->Visible = true;
		dgvRT->Visible = true;
		dgvCP->Visible = false;
		label_playTimes->Visible = false;
		label_playNumTim->Visible = false;
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Quetions^ formQ = gcnew Quetions;

		if (checkLang == 1) {
			ChangeLangRus += gcnew EventHandler(formQ, &Quetions::OnChangeLangRusQuetions);
			OnChangeLangRus(EventArgs::Empty);
		}
		else {
			ChangeLangEng += gcnew EventHandler(formQ, &Quetions::OnChangeLangEngQuetions);
			OnChangeLangEng(EventArgs::Empty);
		}

		formQ->Show();
	}
	
private: System::Void btnPlay_Click(System::Object^ sender, System::EventArgs^ e) {
	if (playTimes > 0 && !wheelIsMoved) 
	{
		wheelIsMoved = true;
		Random^ rand = gcnew Random();
		angleStep = (float)rand->Next(10, 30);
		wheelTimer->Start();
		playTimes--;
	}
	label_playNumTim->Text = playTimes.ToString();
}
private:
	// Метод для поворота изображения в PictureBox с обновлением изображения
	void RotateImage(PictureBox^ pb, Image^ img, float angle) {
		if (img == nullptr || pb->Image == nullptr)
		{
			return;
		}
		Image^ oldImage = pb->Image;
		pb->Image = RotateImage(img, angle);
		if (oldImage != nullptr)
		{
			delete oldImage;
		}
	}

	// Обработчик события Tick таймера - выполняется каждые 50 мс.
	System::Void wheelTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
		String^ num = "";
		String^ ques = "";
		String^ answ = "";
		if (wheelIsMoved && angleStep > 0.0f)
		{
			wheelFortune->angle += angleStep; // Увеличение угла на фиксированный шаг
			/* Использование модуля из <cmath> с плавающей точкой: функция fmod.Является заменой% для 0.0 чисел.
			Нормализует значение угла поворота: ограничивает его диапазоном от 0 до 360 градусов.
			Если angle = 372.5, то fmod(372.5, 360) даст 12.5*/
			wheelFortune->angle = fmod(wheelFortune->angle, 360); /* fmod(x, y) = x - (y * (x / y)), 
															где(x / y) округляется всегда в меньшую сторону.
															fmod(20.0, 7) = 6, где 20 - (7 * (20 / 7)) = 
															= 20 - (7 * 2) = 20 - 14 = 6*/
			if (pictureBox1->Image != nullptr) {
				RotateImage(pictureBox1, wheelFortune->pictureWheel, wheelFortune->angle);
			}
			if (angleStep > 0.1f) { // Уменьшение шага до остановки
				angleStep -= 0.1f;
			}
			else 
			{
				angleStep = 0;
			}			
		}
		else
		{
			try 
			{
				wheelIsMoved = false;
				wheelTimer->Stop();
				num = wheelFortune->statusValues[wheelFortune->position].ToString();
				int qNum = Convert::ToInt32(num);
				QuetionsStrct v = questionsForm->GetQuestionByNumber(qNum); // Вопрос по номеру из Quetions.txt
				ques = marshal_as<String^>(v.question);
				answ = marshal_as<String^>(v.answer);
				QuetionForm^ Qtform = gcnew QuetionForm(num, ques, answ, currentPlayer);
				Qtform->updateRT += gcnew EventHandler(this, &MyForm::ViewRT);
				Qtform->updateCP += gcnew EventHandler(this, &MyForm::ViewCP);
				if (checkLang == 1) {
					ChangeLangRus += gcnew EventHandler(Qtform, &QuetionForm::OnChangeLangRusQuetionForm);
					OnChangeLangRus(EventArgs::Empty);
				}
				else {
					ChangeLangEng += gcnew EventHandler(Qtform, &QuetionForm::OnChangeLangEngQuetionForm);
					OnChangeLangEng(EventArgs::Empty);
				}
				Qtform->Show();
			}
			catch (Exception^ ex) 
			{
				MessageBox::Show("Ошибка: " + ex->Message,
					"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		// Определение текущего состояния через округление угла, делённого на 36
		wheelFortune->position = Convert::ToInt32(Math::Floor(wheelFortune->angle / 36)) % 10;

		// Обновление текста в label с использованием массива значений			
		try
		{
			label1->Text = wheelFortune->statusValues[wheelFortune->position].ToString();
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
	private: void ViewRT(Object^ sender, EventArgs^ e) {
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
		Sort_score_1(LRT);
		Scan_List(LRT);
	}
	private: void ViewCP(Object^ sender, EventArgs^ e) {
		if (currentPlayer != nullptr) {
			if (LRT != NULL)
				while (LRT != NULL)
					LRT = DelFirst_List_RT(LRT);
			ratingTable v = GetPlayerByNickname(currentPlayer->nickname, checkLang);
			LRT = Init_List_RT(v);
			LISTratingTable* q = LRT;
			Scan_List_CP(LRT);
		}		
	}

private: System::Void Open_Table_Click(System::Object^ sender, System::EventArgs^ e) {
	Rating_Table^ formRT = gcnew Rating_Table;

	if (checkLang == 1) {
		ChangeLangRus += gcnew EventHandler(formRT, &Rating_Table::OnChangeLangRusRating_Table);
		OnChangeLangRus(EventArgs::Empty);
	}
	else {
		ChangeLangEng += gcnew EventHandler(formRT, &Rating_Table::OnChangeLangEngRating_Table);
		OnChangeLangEng(EventArgs::Empty);
	}

	formRT->Show();
}
	   // Обновление изображения в классе LuckyCirlce и pictureBox1
	   void PctBox1_ChangeImg(String^ namepct) {
		   String^ newImage = ".\\lucky_wheel_" + namepct + ".png";
		   if (!System::IO::File::Exists(newImage))
		   {
			   if (checkLang == 1)
			   {
				   MessageBox::Show("Файл изображения не найден!",
					   "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			   }
			   else
			   {
				   MessageBox::Show("The image file was not found!", "Error",
					   MessageBoxButtons::OK, MessageBoxIcon::Error);
			   }
			   return;
		   }
		   luckyCircle->ChangeImage(newImage);
		   wheelFortune->ChangeImage(newImage);
		   pictureBox1->Image = luckyCircle->pictureWheel;
		   SaveWheelImageToFile("WheelImage.txt", namepct);
	   }

private: System::Void comboBox_Sw_Col_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (!wheelIsMoved)
	{
		try
		{
			int field = comboBox_Sw_Col->SelectedIndex;
			switch (field)
			{
			case 0: PctBox1_ChangeImg("multicolored"); break;
			case 1:	PctBox1_ChangeImg("dark"); break;
			case 2: PctBox1_ChangeImg("black-white"); break;
			case 3:	PctBox1_ChangeImg("purple"); break;
			case 4: PctBox1_ChangeImg("green"); break;
			case 5:	PctBox1_ChangeImg("blue"); break;
			case 6: PctBox1_ChangeImg("red"); break;
			}
		}
		catch (Exception^ ex)
		{
			if (checkLang == 1)
			{
				MessageBox::Show("Ошибка загрузки изображения: " + ex->Message,
					"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else
			{
				MessageBox::Show("Image upload error: " + ex->Message,
					"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}
}
private: System::Void button_logout_Click(System::Object^ sender, System::EventArgs^ e) {
	logoutSuccess(this, EventArgs::Empty); // Генерация события для Authotization.h
	//ElementsUnvisible();
	if (checkLang == 1)
	{
		MessageBox::Show("Выход из аккаунта", "Успешно",
			MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	else
	{
		MessageBox::Show("Log out of account", "Success",
			MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	this->Close();
}
	// Вывод списка в основную таблицу
	private: void Scan_List(LISTratingTable* LRT) {
		dgvRT->Rows->Clear();
		LISTratingTable* q;
		int i = 0;
		q = LRT;
		if (LRT == NULL) return;
		while (q != NULL && i < 10) 
		{
			dgvRT->Rows->Add();
			dgvRT->Rows[i]->Cells[0]->Value = q->element.id.ToString();
			dgvRT->Rows[i]->Cells[1]->Value = marshal_as<String^>(q->element.nickname);
			dgvRT->Rows[i]->Cells[2]->Value = q->element.score.ToString();
			dgvRT->Rows[i]->Cells[3]->Value = q->element.correctAnswers.ToString();
			dgvRT->Rows[i]->Cells[4]->Value = q->element.mark.ToString();
			q = q->next;
			i++;
		}
		int totalHeight = dgvRT->ColumnHeadersHeight;
		for (int j = 0; j < dgvRT->Rows->Count; j++)
		{
			totalHeight += dgvRT->Rows[j]->Height;
		}
		if (dgvRT->Rows->Count > 0)
		{
			totalHeight += dgvRT->Rows[0]->Height;
		}
		dgvRT->Height = totalHeight;
	}

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
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
	Sort_score_1(LRT);
	Scan_List(LRT);
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	//this->UpdateElements();
	ViewTables += gcnew EventHandler(this, &MyForm::ViewRT);
	ViewTables += gcnew EventHandler(this, &MyForm::ViewCP);
	OnViewTables(EventArgs::Empty);
}
private: System::Void MyForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	logoutSuccess(this, EventArgs::Empty); // Генерация события для Authotization.h
}
private: System::Void btnOpenGuide_Click(System::Object^ sender, System::EventArgs^ e) {
	Guide^ guideForm = gcnew Guide;

	if (checkLang == 1) {
		ChangeLangRus += gcnew EventHandler(guideForm, &Guide::OnChangeLangRusGuide);
		OnChangeLangRus(EventArgs::Empty);
	}
	else {
		ChangeLangEng += gcnew EventHandler(guideForm, &Guide::OnChangeLangEngGuide);
		OnChangeLangEng(EventArgs::Empty);
	}

	guideForm->Show();
}
	   // Вывод списка в личную таблицу
	private: void Scan_List_CP(LISTratingTable* LRT) {
		dgvCP->Rows->Clear();
		LISTratingTable* q;
		int i = 0;
		q = LRT;
		if (LRT == NULL) return;
		while (q != NULL && i < 1) 
		{
			dgvCP->Rows->Add();
			dgvCP->Rows[i]->Cells[0]->Value = q->element.id.ToString();
			dgvCP->Rows[i]->Cells[1]->Value = marshal_as<String^>(q->element.nickname);
			dgvCP->Rows[i]->Cells[2]->Value = q->element.score.ToString();
			dgvCP->Rows[i]->Cells[3]->Value = q->element.correctAnswers.ToString();
			dgvCP->Rows[i]->Cells[4]->Value = q->element.mark.ToString();
			q = q->next;
			i++;
		}
		int totalHeight = dgvCP->ColumnHeadersHeight;
		for (int j = 0; j < dgvCP->Rows->Count; j++)
		{
			totalHeight += dgvCP->Rows[j]->Height;
		}
		if (dgvCP->Rows->Count > 0)
		{
			totalHeight += dgvCP->Rows[0]->Height;
		}
		dgvCP->Height = totalHeight;
	}
private: System::Void buttonUpdateCP_Click(System::Object^ sender, System::EventArgs^ e) {
	if (LRT != NULL)
		while (LRT != NULL)
			LRT = DelFirst_List_RT(LRT);
	ratingTable v = GetPlayerByNickname(currentPlayer->nickname, checkLang);
	LRT = Init_List_RT(v);
	LISTratingTable* q = LRT;
	Scan_List_CP(LRT);
}
private: System::Void comboBox_language_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	int field = comboBox_language->SelectedIndex;
	switch (field) 
	{
	case 0: 
		ChangeLangEng += gcnew EventHandler(this, &MyForm::ChangeLanguageToEngMyForm); 
		OnChangeLangEng(EventArgs::Empty);
		break;
	case 1: 
		ChangeLangRus += gcnew EventHandler(this, &MyForm::ChangeLanguageToRusMyForm); 
		OnChangeLangRus(EventArgs::Empty);
		break;
	}
}
	   // Смена языка на английский
	   public: void ChangeLanguageToEngMyForm(System::Object^ sender, System::EventArgs^ e) {
		   checkLang = 0;

		   this->Text = L"The wheel of Fortune";
		   panel1->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(0)));
		   button1->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(0)));
		   button1->Text = L"Add Questions";
		   btnPlay->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(0)));
		   btnPlay->Text = L"Play";
		   Open_Table->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(0)));
		   Open_Table->Text = L"Rating Table";
		   comboBox_Sw_Col->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(0)));
		   comboBox_Sw_Col->Items->Clear();
		   comboBox_Sw_Col->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
			   L"Multicolored", L"Dark", L"Black-white",
				   L"Purple", L"Green", L"Blue", L"Red"
		   });
		   button_logout->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(0)));
		   button_logout->Text = L"Log Out";
		   label2->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(0)));
		   label2->Text = L"Switch the color";
		   label_playTimes->Font = (gcnew System::Drawing::Font(L"Geometr212 BkCn BT", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(0)));
		   label_playTimes->Text = L"Attempts to play:";
		   label_playNumTim->Font = (gcnew System::Drawing::Font(L"Geometr212 BkCn BT", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(0)));
		   buttonUpdateRT->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(0)));
		   buttonUpdateRT->Text = L"Update";
		   dataGridViewTextBoxColumn2->HeaderText = L"Nickname";
		   dataGridViewTextBoxColumn3->HeaderText = L"Score";
		   dataGridViewTextBoxColumn4->HeaderText = L"Correct Answers";
		   dataGridViewTextBoxColumn5->HeaderText = L"Mark";
		   btnOpenGuide->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(0)));
		   btnOpenGuide->Text = L"Guide";
		   Column2->HeaderText = L"Nickname";
		   Column3->HeaderText = L"Score";
		   Column4->HeaderText = L"Correct Answers";
		   Column5->HeaderText = L"Mark";
	   }

	   // Смена языка на русский
	   public: void ChangeLanguageToRusMyForm(System::Object^ sender, System::EventArgs^ e) {
		   checkLang = 1;

		   this->Text = L"Колесо Фортуны";
		   panel1->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(0)));
		   button1->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(204)));
		   button1->Text = L"Вопросы";
		   btnPlay->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(0)));
		   btnPlay->Text = L"Запустить";
		   Open_Table->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(204)));
		   Open_Table->Text = L"Таблица Рейтинга";
		   comboBox_Sw_Col->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(0)));
		   comboBox_Sw_Col->Items->Clear();
		   comboBox_Sw_Col->Items->AddRange(gcnew cli::array<System::Object^>(7) {
			   L"Разноцветный", L"Тёмный", L"Чёрно-белый",
				   L"Фиолетовый", L"Зелёный", L"Синий", L"Красный"
		   });
		   button_logout->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(0)));
		   button_logout->Text = L"Выйти";
		   label2->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(0)));
		   label2->Text = L"Сменить цвет";
		   label_playTimes->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(0)));
		   label_playTimes->Text = L"Осталось попыток:";
		   label_playNumTim->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(0)));
		   buttonUpdateRT->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(204)));
		   buttonUpdateRT->Text = L"Обновить";
		   dataGridViewTextBoxColumn2->HeaderText = L"Ник";
		   dataGridViewTextBoxColumn3->HeaderText = L"Очки";
		   dataGridViewTextBoxColumn4->HeaderText = L"Верные ответы";
		   dataGridViewTextBoxColumn5->HeaderText = L"Оценка";
		   btnOpenGuide->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(204)));
		   btnOpenGuide->Text = L"Руководство";
		   Column2->HeaderText = L"Ник";
		   Column3->HeaderText = L"Очки";
		   Column4->HeaderText = L"Верные ответы";
		   Column5->HeaderText = L"Оценка";
	   }
};
}
