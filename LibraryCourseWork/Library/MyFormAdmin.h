#pragma once
#include <string>
using namespace std;
namespace Library {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// —водка дл€ MyFormAdmin
	/// </summary>
	public ref class MyFormAdmin : public System::Windows::Forms::Form
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
	public:
		MyFormAdmin(void)
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
		~MyFormAdmin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ back_btn;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ error_label;

	private: System::Windows::Forms::Button^ deleteBookBtn;
	private: System::Windows::Forms::Button^ addBookBtn;
	private: System::Windows::Forms::TextBox^ textBoxToDelete;
	private: System::Windows::Forms::TextBox^ textBoxBookName;
	private: System::Windows::Forms::TextBox^ textBoxBookAuthor;




	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:

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
			this->back_btn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->error_label = (gcnew System::Windows::Forms::Label());
			this->deleteBookBtn = (gcnew System::Windows::Forms::Button());
			this->addBookBtn = (gcnew System::Windows::Forms::Button());
			this->textBoxToDelete = (gcnew System::Windows::Forms::TextBox());
			this->textBoxBookName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxBookAuthor = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// back_btn
			// 
			this->back_btn->Font = (gcnew System::Drawing::Font(L"Arial", 9));
			this->back_btn->Location = System::Drawing::Point(12, 497);
			this->back_btn->Name = L"back_btn";
			this->back_btn->Size = System::Drawing::Size(75, 23);
			this->back_btn->TabIndex = 0;
			this->back_btn->Text = L"Back";
			this->back_btn->UseVisualStyleBackColor = true;
			this->back_btn->Click += gcnew System::EventHandler(this, &MyFormAdmin::back_btn_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 9));
			this->label1->Location = System::Drawing::Point(47, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(76, 30);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Delete book:\r\n(enter id)";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 9));
			this->label2->Location = System::Drawing::Point(47, 145);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(61, 15);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Add book:";
			// 
			// error_label
			// 
			this->error_label->AutoSize = true;
			this->error_label->ForeColor = System::Drawing::Color::Red;
			this->error_label->Location = System::Drawing::Point(12, 423);
			this->error_label->MinimumSize = System::Drawing::Size(180, 30);
			this->error_label->Name = L"error_label";
			this->error_label->Size = System::Drawing::Size(180, 30);
			this->error_label->TabIndex = 3;
			this->error_label->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// deleteBookBtn
			// 
			this->deleteBookBtn->Font = (gcnew System::Drawing::Font(L"Arial", 9));
			this->deleteBookBtn->Location = System::Drawing::Point(40, 105);
			this->deleteBookBtn->Name = L"deleteBookBtn";
			this->deleteBookBtn->Size = System::Drawing::Size(75, 23);
			this->deleteBookBtn->TabIndex = 4;
			this->deleteBookBtn->Text = L"Delete book";
			this->deleteBookBtn->UseVisualStyleBackColor = true;
			this->deleteBookBtn->Click += gcnew System::EventHandler(this, &MyFormAdmin::deleteBookBtn_Click);
			// 
			// addBookBtn
			// 
			this->addBookBtn->Font = (gcnew System::Drawing::Font(L"Arial", 9));
			this->addBookBtn->Location = System::Drawing::Point(47, 326);
			this->addBookBtn->Name = L"addBookBtn";
			this->addBookBtn->Size = System::Drawing::Size(75, 23);
			this->addBookBtn->TabIndex = 5;
			this->addBookBtn->Text = L"Add book";
			this->addBookBtn->UseVisualStyleBackColor = true;
			this->addBookBtn->Click += gcnew System::EventHandler(this, &MyFormAdmin::addBookBtn_Click);
			// 
			// textBoxToDelete
			// 
			this->textBoxToDelete->Location = System::Drawing::Point(47, 64);
			this->textBoxToDelete->Name = L"textBoxToDelete";
			this->textBoxToDelete->Size = System::Drawing::Size(100, 20);
			this->textBoxToDelete->TabIndex = 6;
			// 
			// textBoxBookName
			// 
			this->textBoxBookName->Location = System::Drawing::Point(43, 208);
			this->textBoxBookName->Name = L"textBoxBookName";
			this->textBoxBookName->Size = System::Drawing::Size(100, 20);
			this->textBoxBookName->TabIndex = 7;
			// 
			// textBoxBookAuthor
			// 
			this->textBoxBookAuthor->Location = System::Drawing::Point(43, 282);
			this->textBoxBookAuthor->Name = L"textBoxBookAuthor";
			this->textBoxBookAuthor->Size = System::Drawing::Size(100, 20);
			this->textBoxBookAuthor->TabIndex = 8;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial", 9));
			this->label4->Location = System::Drawing::Point(44, 178);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(110, 15);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Enter book\'s name";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial", 9));
			this->label5->Location = System::Drawing::Point(44, 255);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(113, 15);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Enter book\'s author";
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ControlLightLight;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
			this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(198, 29);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(563, 459);
			this->dataGridView1->TabIndex = 11;
			// 
			// MyFormAdmin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(788, 532);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBoxBookAuthor);
			this->Controls->Add(this->textBoxBookName);
			this->Controls->Add(this->textBoxToDelete);
			this->Controls->Add(this->addBookBtn);
			this->Controls->Add(this->deleteBookBtn);
			this->Controls->Add(this->error_label);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->back_btn);
			this->MaximumSize = System::Drawing::Size(804, 571);
			this->MinimumSize = System::Drawing::Size(804, 571);
			this->Name = L"MyFormAdmin";
			this->Text = L"Admin";
			this->Load += gcnew System::EventHandler(this, &MyFormAdmin::MyFormAdmin_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void back_btn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void deleteBookBtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void addBookBtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MyFormAdmin_Load(System::Object^ sender, System::EventArgs^ e);
};
}
