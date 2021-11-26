#include "MyFormLibrarian.h"

using namespace Library; // Название проекта
int WINAPI WinMain5(HINSTANCE, HINSTANCE, LPSTR, int) 
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	return 0;
}
Books bok;
System::Void Library::MyFormLibrarian::MyFormLibrarian_Load(System::Object^ sender, System::EventArgs^ e)
{
	sqlConn->ConnectionString = "datasource = localhost; port=3306; username=root;password = Vbifcfif; database = testdb";
	sqlConn->Open();
	sqlCmd->Connection = sqlConn;
	sqlCmd->CommandText = "SELECT * FROM books;";
	sqlRd = sqlCmd->ExecuteReader();
	sqlDt->Load(sqlRd);
	sqlRd->Close();
	sqlConn->Close();
	dataGridView1->DataSource = sqlDt;
}

System::Void Library::MyFormLibrarian::buttonGiveOut_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ username0 = textBoxUsername->Text;
	string username;
	MarshalString(username0, username);
	if (textBoxId->Text == "" || textBoxUsername->Text == "")
	{
		error_label->Text = "Enter name and id";
	}
	else
	{
		int id = System::Convert::ToInt16(textBoxId->Text);
		if (!bok.isBookExists(id))
		{
			error_label->Text = "The book does not exist";
		}
		else
		{
			if (bok.isBookOwn(id))
			{
				error_label->Text = "Book not yet returned";
			}
			else
			{
				bok.set_book_owner(username, id);
				error_label->Text = "";
				this_thread::sleep_for(chrono::seconds(2));
				MyFormLibrarian_Load(nullptr, nullptr);
			}
		}
	}
}

System::Void Library::MyFormLibrarian::buttonBack_Click(System::Object^ sender, System::EventArgs^ e)
{
	Owner->Show();
	this->Close();
}
