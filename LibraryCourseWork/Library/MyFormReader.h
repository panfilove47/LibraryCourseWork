#pragma once
#include<string>
#include "MyFormRegistry.h"
#include"Class_books.h"
#include <Windows.h>
#include <thread>
#include <chrono>
namespace Library {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;
	using namespace std;

	/// <summary>
	/// —водка дл€ MyFormReader
	/// </summary>
	public ref class MyFormReader : public System::Windows::Forms::Form
	{
		void MarshalString(String^ s, string& os)
		{
			using namespace Runtime::InteropServices;
			const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlRd;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBoxUsername;
	private: System::Windows::Forms::Button^ buttonBack;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBoxToReturn;
	private: System::Windows::Forms::Button^ buttonToReturn;

	public:
		MyFormReader(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyFormReader()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBoxId;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ error_label;


	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxId = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->error_label = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBoxUsername = (gcnew System::Windows::Forms::TextBox());
			this->buttonBack = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBoxToReturn = (gcnew System::Windows::Forms::TextBox());
			this->buttonToReturn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::Control;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(174, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(456, 379);
			this->dataGridView1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 9));
			this->label1->Location = System::Drawing::Point(12, 39);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(124, 15);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Enter  id to take book:";
			// 
			// textBoxId
			// 
			this->textBoxId->Location = System::Drawing::Point(15, 65);
			this->textBoxId->Name = L"textBoxId";
			this->textBoxId->Size = System::Drawing::Size(100, 20);
			this->textBoxId->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial", 9));
			this->button1->Location = System::Drawing::Point(15, 164);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Take book";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyFormReader::button1_Click);
			// 
			// error_label
			// 
			this->error_label->AutoSize = true;
			this->error_label->ForeColor = System::Drawing::Color::Red;
			this->error_label->Location = System::Drawing::Point(9, 328);
			this->error_label->MinimumSize = System::Drawing::Size(180, 30);
			this->error_label->Name = L"error_label";
			this->error_label->Size = System::Drawing::Size(180, 30);
			this->error_label->TabIndex = 4;
			this->error_label->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial", 9));
			this->label3->Location = System::Drawing::Point(12, 100);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(97, 15);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Enter your name";
			// 
			// textBoxUsername
			// 
			this->textBoxUsername->Location = System::Drawing::Point(15, 130);
			this->textBoxUsername->Name = L"textBoxUsername";
			this->textBoxUsername->Size = System::Drawing::Size(100, 20);
			this->textBoxUsername->TabIndex = 6;
			// 
			// buttonBack
			// 
			this->buttonBack->Font = (gcnew System::Drawing::Font(L"Arial", 9));
			this->buttonBack->Location = System::Drawing::Point(15, 368);
			this->buttonBack->Name = L"buttonBack";
			this->buttonBack->Size = System::Drawing::Size(75, 23);
			this->buttonBack->TabIndex = 7;
			this->buttonBack->Text = L"Back";
			this->buttonBack->UseVisualStyleBackColor = true;
			this->buttonBack->Click += gcnew System::EventHandler(this, &MyFormReader::buttonBack_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 9));
			this->label2->Location = System::Drawing::Point(3, 209);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(133, 15);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Enter  id to return book:";
			// 
			// textBoxToReturn
			// 
			this->textBoxToReturn->Location = System::Drawing::Point(15, 260);
			this->textBoxToReturn->Name = L"textBoxToReturn";
			this->textBoxToReturn->Size = System::Drawing::Size(100, 20);
			this->textBoxToReturn->TabIndex = 9;
			// 
			// buttonToReturn
			// 
			this->buttonToReturn->Font = (gcnew System::Drawing::Font(L"Arial", 9));
			this->buttonToReturn->Location = System::Drawing::Point(15, 302);
			this->buttonToReturn->Name = L"buttonToReturn";
			this->buttonToReturn->Size = System::Drawing::Size(75, 23);
			this->buttonToReturn->TabIndex = 10;
			this->buttonToReturn->Text = L"Return book";
			this->buttonToReturn->UseVisualStyleBackColor = true;
			this->buttonToReturn->Click += gcnew System::EventHandler(this, &MyFormReader::buttonToReturn_Click);
			// 
			// MyFormReader
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(677, 407);
			this->Controls->Add(this->buttonToReturn);
			this->Controls->Add(this->textBoxToReturn);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->buttonBack);
			this->Controls->Add(this->textBoxUsername);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->error_label);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBoxId);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->MaximumSize = System::Drawing::Size(693, 446);
			this->MinimumSize = System::Drawing::Size(693, 446);
			this->Name = L"MyFormReader";
			this->Text = L"Reader";
			this->Load += gcnew System::EventHandler(this, &MyFormReader::MyFormReader_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MyFormReader_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonBack_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonToReturn_Click(System::Object^ sender, System::EventArgs^ e);
};
}
