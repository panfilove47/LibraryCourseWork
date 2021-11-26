#include <thread>
#include <chrono>
#include "MyFormAdmin.h"
#include "MyFormRegistry.h"
#include <Windows.h>
#include "Class_books.h"
Books book;
using namespace Library; // Название проекта
int WINAPI WinMain3(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	return 0;
}

System::Void Library::MyFormAdmin::back_btn_Click(System::Object^ sender, System::EventArgs^ e)
{
	Owner->Show();
	this->Close();
}

System::Void Library::MyFormAdmin::deleteBookBtn_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (textBoxToDelete->Text == "")
	{
		error_label->Text = "Enter id to delete";
	}
	else
	{
		int id = System::Convert::ToInt16(textBoxToDelete->Text);
		if (book.isBookOwn(id))
		{
			error_label->Text = "Book not yet returned";
		}
		else
		{
			if (!book.isBookExists(id))
			{
				error_label->Text = "The book does not exist";
			}
			else
			{
				book.delete_book(id);
				error_label->Text = "";
				this_thread::sleep_for(chrono::seconds(2));
				MyFormAdmin_Load(nullptr, nullptr);
			}
		}
	}
}

System::Void Library::MyFormAdmin::addBookBtn_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ bookName0 = textBoxBookName->Text;
	string bookName;
	String^ bookAuthor0 = textBoxBookAuthor->Text;
	string bookAuthor;
	MarshalString(bookName0, bookName);
	MarshalString(bookAuthor0, bookAuthor);
	if (textBoxBookName->Text == "" || textBoxBookAuthor->Text == "")
	{
		error_label->Text = "Enter book's name or author";
	}
	else
	{
		book.set_book(bookName, bookAuthor);
		error_label->Text = "";
		this_thread::sleep_for(chrono::seconds(2));
		MyFormAdmin_Load(nullptr, nullptr);
	}
}

System::Void Library::MyFormAdmin::MyFormAdmin_Load(System::Object^ sender, System::EventArgs^ e)
{
	sqlConn->ConnectionString = "datasource = localhost; port=3306; username=root;password = Vbifcfif; database = testdb";
	sqlConn->Open();
	sqlCmd->Connection = sqlConn;
	sqlCmd->CommandText = "SELECT bookId ,bookName, bookAuthor, bookStatus  FROM books;";
	sqlRd = sqlCmd->ExecuteReader();
	sqlDt->Load(sqlRd);
	sqlRd->Close();
	sqlConn->Close();
	dataGridView1->DataSource = sqlDt;
}
