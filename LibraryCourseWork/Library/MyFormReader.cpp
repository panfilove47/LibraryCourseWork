#include "MyFormReader.h"
using namespace Library; // Название проекта
int WINAPI WinMain4(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	return 0;
}
Books boo;
System::Void Library::MyFormReader::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ username0 = textBoxUsername->Text;
	string username;
	MarshalString(username0, username);
	if (textBoxId->Text == "" || textBoxUsername->Text == "")
	{
		error_label->Text = "Enter your name and id";
	}
	else
	{
		int id = System::Convert::ToInt16(textBoxId->Text);
		if (!boo.isBookExists(id))
		{
			error_label->Text = "The book does not exist";
		}
		else
		{
			if (boo.isBookOwn(id))
			{
				error_label->Text = "Book not yet returned";
			}
			else
			{
				boo.set_book_owner(username, id);
				error_label->Text = "";
				this_thread::sleep_for(chrono::seconds(2));
				MyFormReader_Load(nullptr, nullptr);
			}
		}
	}
}

System::Void Library::MyFormReader::MyFormReader_Load(System::Object^ sender, System::EventArgs^ e)
{
	sqlConn->ConnectionString = "datasource = localhost; port=3306; username=root;password = Vbifcfif; database = testdb";
	sqlConn->Open();
	sqlCmd->Connection = sqlConn;
	sqlCmd->CommandText = "SELECT bookId ,bookName, bookAuthor, bookStatus FROM books;";
	sqlRd = sqlCmd->ExecuteReader();
	sqlDt->Load(sqlRd);
	sqlRd->Close();
	sqlConn->Close();
	dataGridView1->DataSource = sqlDt;
}

System::Void Library::MyFormReader::buttonBack_Click(System::Object^ sender, System::EventArgs^ e)
{
	Owner->Show();
	this->Close();
}

System::Void Library::MyFormReader::buttonToReturn_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (textBoxToReturn->Text == "")
	{
		error_label->Text = "Enter id";
	}
	else
	{
		int id = System::Convert::ToInt16(textBoxToReturn->Text);
		if (!boo.isBookExists(id))
		{
			error_label->Text = "The book does not exist";
		}
		else
		{
			if (!boo.isBookOwn(id))
			{
				error_label->Text = "The book already returned";
			}
			else
			{
				boo.unset_book_owner(id);
				this_thread::sleep_for(chrono::seconds(2));
				MyFormReader_Load(nullptr, nullptr);
			}
		}
	}
}


