#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Books
{
public:
	Books()
	{
		conn = mysql_init(0);
		conn = mysql_real_connect(conn, "localhost", "root", "Vbifcfif", "testdb", 3306, NULL, 0);
		string query = "SELECT * FROM books";
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			res = mysql_store_result(conn);
			while (row = mysql_fetch_row(res))
			{
				id++;
			}
		}
	}
	void set_book(string book_name, string book_author, string book_status = "inTheLibrary")
	{
		stringstream ss;
		ss << "INSERT INTO books(bookName, bookAuthor, bookStatus) VALUES ('" << book_name << "', '" << book_author << "', '" << book_status << "' )";
		string query = ss.str();
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
		id++;
	}
	void delete_book(int book_id)
	{
		stringstream ss;
		ss << "DELETE FROM books WHERE bookId = '" << book_id << "'";
		string query = ss.str();
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
	}
	void set_book_owner(string user_name, int bookId)
	{
		stringstream ss;
		ss << "UPDATE `books` SET `bookOwner` = '" << user_name << "', `bookStatus` = 'notInTheLibrary' WHERE (`bookId` = '" << bookId << "')";
		string query = ss.str();
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
	}
	void take_book(string user_name, int bookId)
	{
		stringstream ss;
		ss << "UPDATE `books` SET `bookOwner` = '" << user_name << "' WHERE (`bookId` = '" << bookId << "')";
		string query = ss.str();
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
	}
	void unset_book_owner(int bookId)
	{
		stringstream ss;
		ss << "UPDATE `books` SET `bookOwner` = '', `bookStatus` = 'inTheLibrary' WHERE (`bookId` = '" << bookId << "')";
		string query = ss.str();
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
	}
	bool isBookExists(int book_id)
	{
		stringstream ss;
		ss << "SELECT EXISTS(SELECT * FROM books WHERE bookId = '" << book_id << "')";
		string query = ss.str();
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
		res = mysql_store_result(conn);
		row = mysql_fetch_row(res);
		char result = *row[0];
		stringstream s;
		s << result;
		string tostr_result = s.str();
		int endresult = stoi(tostr_result);
		return endresult;
	}
	bool isBookOwn(int book_id)
	{
		stringstream ss;
		ss << "SELECT EXISTS(SELECT * FROM books WHERE bookId = '" << book_id << "' and bookStatus = 'notInTheLibrary')";
		string query = ss.str();
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
		res = mysql_store_result(conn);
		row = mysql_fetch_row(res);
		char result = *row[0];
		stringstream s;
		s << result;
		string tostr_result = s.str();
		int endresult = stoi(tostr_result);
		return endresult;
	}
private:
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	int qstate = 0;
	int id;
};