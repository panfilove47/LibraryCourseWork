#include "MyFormRegistry.h"
#include "MyFormRegistry2.h"
#include "MyFormAdmin.h"
#include "MyFormLibrarian.h"
#include"MyFormReader.h"
#include <Windows.h>
using namespace Library; // Название проекта
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyFormRegistry);
	return 0;
}
User us;
System::Void Library::MyFormRegistry::login_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ login0 = login_box->Text;
	string login;
	String^ password0 = password_box->Text;
	string password;
	MarshalString(login0, login);
	MarshalString(password0, password);
	if (login_box->Text == "" || password_box->Text == "")
	{
		error_label->Text = "Enter your username or password";
	}
	else
	{
		if (!us.isAccount_exists(login, password))
		{
			error_label->Text = "This user does not exist, please register";
			reg_button->Focus();
		}
		else
		{
			if (us.isAdmin(login))
			{
				MyFormAdmin^ formAdm = gcnew MyFormAdmin;
				formAdm->Owner = this;
				formAdm->Show();
				this->Hide();
				error_label->Text = "";
			}
			else
			{
				if (us.isReader(login))
				{
					MyFormReader^ formRead = gcnew MyFormReader;
					formRead->Owner = this;
					formRead->Show();
					this->Hide();
					error_label->Text = "";
				}
				else
				{
					MyFormLibrarian^ formLibr = gcnew MyFormLibrarian;
					formLibr->Owner = this;
					formLibr->Show();
					this->Hide();
					error_label->Text = "";
				}
			}
		}
	}
}

System::Void Library::MyFormRegistry::reg_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	MyFormRegistry2^ formReg = gcnew MyFormRegistry2;
	formReg->Owner = this;
	formReg->Show();
	this->Hide();
	error_label->Text = "";
}
