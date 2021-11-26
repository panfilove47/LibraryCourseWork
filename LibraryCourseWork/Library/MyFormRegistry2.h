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

	/// <summary>
	/// —водка дл€ MyFormRegistry2
	/// </summary>
	public ref class MyFormRegistry2 : public System::Windows::Forms::Form
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
		MyFormRegistry2(void)
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
		~MyFormRegistry2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Button^ registry_button;
	private: System::Windows::Forms::TextBox^ confirmed_password_textbox;
	private: System::Windows::Forms::TextBox^ create_password_textbox;
	private: System::Windows::Forms::TextBox^ user_textbox;
	private: System::Windows::Forms::Label^ confirmed_password_label;
	private: System::Windows::Forms::Label^ create_password_label;
	private: System::Windows::Forms::Label^ name_of_user_label;
	private: System::Windows::Forms::Button^ back_button;

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
			this->registry_button = (gcnew System::Windows::Forms::Button());
			this->confirmed_password_textbox = (gcnew System::Windows::Forms::TextBox());
			this->create_password_textbox = (gcnew System::Windows::Forms::TextBox());
			this->user_textbox = (gcnew System::Windows::Forms::TextBox());
			this->confirmed_password_label = (gcnew System::Windows::Forms::Label());
			this->create_password_label = (gcnew System::Windows::Forms::Label());
			this->name_of_user_label = (gcnew System::Windows::Forms::Label());
			this->back_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::Red;
			this->label1->Location = System::Drawing::Point(33, 363);
			this->label1->MaximumSize = System::Drawing::Size(100, 30);
			this->label1->MinimumSize = System::Drawing::Size(300, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(300, 30);
			this->label1->TabIndex = 17;
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// registry_button
			// 
			this->registry_button->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->registry_button->Location = System::Drawing::Point(132, 319);
			this->registry_button->Name = L"registry_button";
			this->registry_button->Size = System::Drawing::Size(103, 23);
			this->registry_button->TabIndex = 16;
			this->registry_button->Text = L"Register now";
			this->registry_button->UseVisualStyleBackColor = true;
			this->registry_button->Click += gcnew System::EventHandler(this, &MyFormRegistry2::registry_button_Click);
			// 
			// confirmed_password_textbox
			// 
			this->confirmed_password_textbox->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->confirmed_password_textbox->Location = System::Drawing::Point(109, 252);
			this->confirmed_password_textbox->Multiline = true;
			this->confirmed_password_textbox->Name = L"confirmed_password_textbox";
			this->confirmed_password_textbox->Size = System::Drawing::Size(149, 20);
			this->confirmed_password_textbox->TabIndex = 15;
			// 
			// create_password_textbox
			// 
			this->create_password_textbox->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->create_password_textbox->Location = System::Drawing::Point(109, 143);
			this->create_password_textbox->Multiline = true;
			this->create_password_textbox->Name = L"create_password_textbox";
			this->create_password_textbox->Size = System::Drawing::Size(149, 20);
			this->create_password_textbox->TabIndex = 14;
			// 
			// user_textbox
			// 
			this->user_textbox->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->user_textbox->Location = System::Drawing::Point(109, 34);
			this->user_textbox->Multiline = true;
			this->user_textbox->Name = L"user_textbox";
			this->user_textbox->Size = System::Drawing::Size(149, 20);
			this->user_textbox->TabIndex = 13;
			// 
			// confirmed_password_label
			// 
			this->confirmed_password_label->AutoSize = true;
			this->confirmed_password_label->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->confirmed_password_label->Location = System::Drawing::Point(123, 234);
			this->confirmed_password_label->Name = L"confirmed_password_label";
			this->confirmed_password_label->Size = System::Drawing::Size(121, 16);
			this->confirmed_password_label->TabIndex = 12;
			this->confirmed_password_label->Text = L"Repeat password:";
			// 
			// create_password_label
			// 
			this->create_password_label->AutoSize = true;
			this->create_password_label->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->create_password_label->Location = System::Drawing::Point(129, 125);
			this->create_password_label->Name = L"create_password_label";
			this->create_password_label->Size = System::Drawing::Size(109, 16);
			this->create_password_label->TabIndex = 11;
			this->create_password_label->Text = L"Enter password:";
			// 
			// name_of_user_label
			// 
			this->name_of_user_label->AutoSize = true;
			this->name_of_user_label->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->name_of_user_label->Location = System::Drawing::Point(143, 13);
			this->name_of_user_label->Name = L"name_of_user_label";
			this->name_of_user_label->Size = System::Drawing::Size(81, 16);
			this->name_of_user_label->TabIndex = 10;
			this->name_of_user_label->Text = L"Enter login:";
			// 
			// back_button
			// 
			this->back_button->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->back_button->Location = System::Drawing::Point(3, 433);
			this->back_button->Name = L"back_button";
			this->back_button->Size = System::Drawing::Size(75, 23);
			this->back_button->TabIndex = 9;
			this->back_button->Text = L"Back";
			this->back_button->UseVisualStyleBackColor = true;
			this->back_button->Click += gcnew System::EventHandler(this, &MyFormRegistry2::back_button_Click);
			// 
			// MyFormRegistry2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(363, 481);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->registry_button);
			this->Controls->Add(this->confirmed_password_textbox);
			this->Controls->Add(this->create_password_textbox);
			this->Controls->Add(this->user_textbox);
			this->Controls->Add(this->confirmed_password_label);
			this->Controls->Add(this->create_password_label);
			this->Controls->Add(this->name_of_user_label);
			this->Controls->Add(this->back_button);
			this->MaximumSize = System::Drawing::Size(379, 520);
			this->MinimumSize = System::Drawing::Size(379, 520);
			this->Name = L"MyFormRegistry2";
			this->Text = L"Registry";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void registry_button_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void back_button_Click(System::Object^ sender, System::EventArgs^ e);
};
}
