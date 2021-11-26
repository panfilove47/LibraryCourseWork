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
	/// —водка дл€ MyFormLibrarian
	/// </summary>
	public ref class MyFormLibrarian : public System::Windows::Forms::Form
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
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBoxUsername;
	private: System::Windows::Forms::Label^ error_label;

		   MySqlDataReader^ sqlRd;
	public:
		MyFormLibrarian(void)
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
		~MyFormLibrarian()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonBack;
	protected:
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBoxId;

	private: System::Windows::Forms::Button^ buttonGiveOut;

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
			this->buttonBack = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxId = (gcnew System::Windows::Forms::TextBox());
			this->buttonGiveOut = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBoxUsername = (gcnew System::Windows::Forms::TextBox());
			this->error_label = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonBack
			// 
			this->buttonBack->Font = (gcnew System::Drawing::Font(L"Arial", 9));
			this->buttonBack->Location = System::Drawing::Point(12, 368);
			this->buttonBack->Name = L"buttonBack";
			this->buttonBack->Size = System::Drawing::Size(75, 23);
			this->buttonBack->TabIndex = 0;
			this->buttonBack->Text = L"Back";
			this->buttonBack->UseVisualStyleBackColor = true;
			this->buttonBack->Click += gcnew System::EventHandler(this, &MyFormLibrarian::buttonBack_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::Control;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(187, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(575, 347);
			this->dataGridView1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 9));
			this->label1->Location = System::Drawing::Point(9, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(150, 15);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Enter id to give out a book:";
			// 
			// textBoxId
			// 
			this->textBoxId->Location = System::Drawing::Point(12, 57);
			this->textBoxId->Name = L"textBoxId";
			this->textBoxId->Size = System::Drawing::Size(100, 20);
			this->textBoxId->TabIndex = 3;
			// 
			// buttonGiveOut
			// 
			this->buttonGiveOut->Font = (gcnew System::Drawing::Font(L"Arial", 9));
			this->buttonGiveOut->Location = System::Drawing::Point(12, 159);
			this->buttonGiveOut->Name = L"buttonGiveOut";
			this->buttonGiveOut->Size = System::Drawing::Size(75, 23);
			this->buttonGiveOut->TabIndex = 4;
			this->buttonGiveOut->Text = L"Give out";
			this->buttonGiveOut->UseVisualStyleBackColor = true;
			this->buttonGiveOut->Click += gcnew System::EventHandler(this, &MyFormLibrarian::buttonGiveOut_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 9));
			this->label2->Location = System::Drawing::Point(9, 97);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(172, 15);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Enter name to give out a book:";
			// 
			// textBoxUsername
			// 
			this->textBoxUsername->Location = System::Drawing::Point(12, 125);
			this->textBoxUsername->Name = L"textBoxUsername";
			this->textBoxUsername->Size = System::Drawing::Size(100, 20);
			this->textBoxUsername->TabIndex = 6;
			// 
			// error_label
			// 
			this->error_label->AutoSize = true;
			this->error_label->ForeColor = System::Drawing::Color::Red;
			this->error_label->Location = System::Drawing::Point(12, 216);
			this->error_label->MinimumSize = System::Drawing::Size(150, 30);
			this->error_label->Name = L"error_label";
			this->error_label->Size = System::Drawing::Size(150, 30);
			this->error_label->TabIndex = 7;
			this->error_label->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// MyFormLibrarian
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(779, 403);
			this->Controls->Add(this->error_label);
			this->Controls->Add(this->textBoxUsername);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->buttonGiveOut);
			this->Controls->Add(this->textBoxId);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->buttonBack);
			this->MaximumSize = System::Drawing::Size(795, 442);
			this->MinimumSize = System::Drawing::Size(795, 442);
			this->Name = L"MyFormLibrarian";
			this->Text = L"Librarian";
			this->Load += gcnew System::EventHandler(this, &MyFormLibrarian::MyFormLibrarian_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyFormLibrarian_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonGiveOut_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonBack_Click(System::Object^ sender, System::EventArgs^ e);
};
}
