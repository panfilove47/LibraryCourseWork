#include "MyFormRegistry2.h"
#include "MyFormRegistry.h"
#include <Windows.h>
User user;
using namespace Library; // Название проекта
int WINAPI WinMain2(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	return 0;
}

System::Void Library::MyFormRegistry2::registry_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ username0 = user_textbox->Text;
	string username;
	String^ password0 = create_password_textbox->Text;
	string password;
	MarshalString(username0, username);
	MarshalString(password0, password);

	if (create_password_textbox->Text != confirmed_password_textbox->Text)
	{
		label1->Text = "Incorrect condirmed password";
	}
	else
	{
		if (user_textbox->TextLength == 0 || create_password_textbox->TextLength == 0)
		{
			label1->Text = "Enter username or password";
		}
		else
		{
			if (user.isUser_exists(username))
			{
				label1->Text = "User is already exists";
			}
			else
			{
				user.set_data(username, password);
				Owner->Show();
				this->Close();
			}
		}
	}
}

System::Void Library::MyFormRegistry2::back_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	Owner->Show();
	this->Close();
}
