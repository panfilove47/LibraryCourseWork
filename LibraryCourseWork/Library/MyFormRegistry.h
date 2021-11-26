#pragma once
#include <string>
#include "Class_user.h"
using namespace std;
namespace Library {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyFormRegistry
	/// </summary>
	public ref class MyFormRegistry : public System::Windows::Forms::Form
	{
	protected:
		void MarshalString(String^ s, string& os)
		{
			using namespace Runtime::InteropServices;
			const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}
	public:
		MyFormRegistry(void)
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
		virtual ~MyFormRegistry()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ login_box;
	private: System::Windows::Forms::TextBox^ password_box;
	private: System::Windows::Forms::Button^ login_button;
	private: System::Windows::Forms::Button^ reg_button;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->login_box = (gcnew System::Windows::Forms::TextBox());
			this->password_box = (gcnew System::Windows::Forms::TextBox());
			this->login_button = (gcnew System::Windows::Forms::Button());
			this->reg_button = (gcnew System::Windows::Forms::Button());
			this->error_label = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(257, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 22);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Login:";
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(237, 125);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(110, 22);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Password:";
			// 
			// login_box
			// 
			this->login_box->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->login_box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->login_box->Location = System::Drawing::Point(204, 47);
			this->login_box->MaximumSize = System::Drawing::Size(180, 30);
			this->login_box->Multiline = true;
			this->login_box->Name = L"login_box";
			this->login_box->Size = System::Drawing::Size(180, 30);
			this->login_box->TabIndex = 5;
			// 
			// password_box
			// 
			this->password_box->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->password_box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->password_box->Location = System::Drawing::Point(204, 150);
			this->password_box->MaximumSize = System::Drawing::Size(180, 30);
			this->password_box->Multiline = true;
			this->password_box->Name = L"password_box";
			this->password_box->PasswordChar = '*';
			this->password_box->Size = System::Drawing::Size(180, 30);
			this->password_box->TabIndex = 6;
			// 
			// login_button
			// 
			this->login_button->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->login_button->ForeColor = System::Drawing::SystemColors::ControlText;
			this->login_button->Location = System::Drawing::Point(234, 202);
			this->login_button->Name = L"login_button";
			this->login_button->Size = System::Drawing::Size(117, 26);
			this->login_button->TabIndex = 1;
			this->login_button->Text = L"Sign in";
			this->login_button->UseVisualStyleBackColor = true;
			this->login_button->Click += gcnew System::EventHandler(this, &MyFormRegistry::login_button_Click);
			// 
			// reg_button
			// 
			this->reg_button->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->reg_button->Location = System::Drawing::Point(234, 244);
			this->reg_button->Name = L"reg_button";
			this->reg_button->Size = System::Drawing::Size(117, 26);
			this->reg_button->TabIndex = 2;
			this->reg_button->Text = L"Registration";
			this->reg_button->UseVisualStyleBackColor = true;
			this->reg_button->Click += gcnew System::EventHandler(this, &MyFormRegistry::reg_button_Click);
			// 
			// error_label
			// 
			this->error_label->AutoSize = true;
			this->error_label->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->error_label->ForeColor = System::Drawing::Color::Red;
			this->error_label->Location = System::Drawing::Point(142, 289);
			this->error_label->MaximumSize = System::Drawing::Size(300, 50);
			this->error_label->MinimumSize = System::Drawing::Size(300, 50);
			this->error_label->Name = L"error_label";
			this->error_label->Size = System::Drawing::Size(300, 50);
			this->error_label->TabIndex = 7;
			this->error_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MyFormRegistry
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 361);
			this->Controls->Add(this->error_label);
			this->Controls->Add(this->reg_button);
			this->Controls->Add(this->login_button);
			this->Controls->Add(this->password_box);
			this->Controls->Add(this->login_box);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->MaximumSize = System::Drawing::Size(600, 400);
			this->MinimumSize = System::Drawing::Size(600, 400);
			this->Name = L"MyFormRegistry";
			this->Text = L"Login";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void login_button_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void reg_button_Click(System::Object^ sender, System::EventArgs^ e);
};
}
