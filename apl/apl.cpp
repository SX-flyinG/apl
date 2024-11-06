#include <iostream>
#include <string.h>

using namespace std;

int main()
{

	int amountOfBooks = 4;
	char** bookList = new char* [amountOfBooks];
	for (int i = 0; i < amountOfBooks; i++)
	{
		bookList[i] = new char[10];
		cout << "Write name of book " << i + 1 << ": ";
		cin.getline(bookList[i], 10);
	}
	cout << "Your list: " << endl;
	for (int i = 0; i < amountOfBooks; i++)
	{
		cout << bookList[i] << endl;
	}


	while (true) {
		cout << "1 - Add a book\n2 - Rename book\n3 - Delete book\n4 - Exit application\n5-Show all books\n: ";
		int result;
		cin >> result;
		cin.ignore();




		if (result == 1) {
			char** timeArr = new char* [amountOfBooks]; //временный массив
			for (int i = 0; i < amountOfBooks; i++)
			{
				timeArr[i] = new char[strlen(bookList[i]) + 1];			 //
				//
				//
				for (int j = 0; j < strlen(bookList[i]) + 1; j++)		 //
				{														 //перезаписывание
					timeArr[i][j] = (char)bookList[i][j];				 //
				}														 //
				delete[] bookList[i];									 //
				bookList[i] = nullptr;									 //

			}
			delete[] bookList;
			bookList = nullptr;

			amountOfBooks++;											   //
			bookList = new char* [amountOfBooks];						   //
			for (int i = 0; i < amountOfBooks - 1; i++)					   //
			{															   //
				bookList[i] = new char[strlen(timeArr[i]) + 1];			   //
				//
				//опять перезаписываем
				for (int j = 0; j < strlen(timeArr[i]) + 1; j++)		   //
				{														   //
					bookList[i][j] = (char)timeArr[i][j];				   //
				}														   //
				delete[] timeArr[i];									   //
				timeArr[i] = nullptr;									   //
			}
			delete[] timeArr;
			timeArr = nullptr;

			bookList[amountOfBooks - 1] = new char[10];
			cout << "Write your book: ";
			cin.getline(bookList[amountOfBooks - 1], 10);
			cout << endl;
			cout << "Your list: " << endl;
			for (int i = 0; i < amountOfBooks; i++)
			{
				cout << bookList[i] << endl;	//выводим массив
			}
			cout << endl;
		}


		else if (result == 2) {
			int numberBook;
			char* newName = new char[10];
			cout << "Write the number of book you want to rename: ";
			cin >> numberBook;
			cout << "Write your new name: ";
			cin >> newName;
			delete[] bookList[numberBook - 1];
			bookList[numberBook - 1] = nullptr;									//
			bookList[numberBook - 1] = new char[strlen(newName) + 1];			//перезаписываем новое имя
			bookList[numberBook - 1] = newName;									//
			cout << endl;
			cout << "Your list: " << endl;
			for (int i = 0; i < amountOfBooks; i++)
			{
				cout << bookList[i] << endl;
			}
			cout << endl;
		}


		else if (result == 3) {
			if (amountOfBooks - 1 < 0) {
				cout << "i cant";
				continue;
			}
			else {
				int numberBook;
				cout << "Write the number of book you want to delete: ";
				cin >> numberBook;
				amountOfBooks--;// уменьшаем количество книг
				int time = 0;
				char** timeArr = new char* [amountOfBooks];// временный массив 
				for (int i = 0; i < amountOfBooks + 1; i++)
				{
					if (i == numberBook - 1) {
						continue;
					}
					else {
						timeArr[time] = new char[strlen(bookList[time]) + 1];	   //
						for (int j = 0; j < strlen(bookList[i]) + 1; j++)		   //
						{														   //
							timeArr[time][j] = (char)bookList[i][j];			   //записывем в временный массив
						}														   //
						delete[] bookList[time];								   //
						bookList[time] = nullptr;								   //
						time++;													   //
					}
				}
				delete[] bookList;
				bookList = nullptr;

				bookList = new char* [amountOfBooks];
				for (int i = 0; i < amountOfBooks; i++)
				{
					bookList[i] = new char[strlen(timeArr[i]) + 1];				   //
					for (int j = 0; j < strlen(timeArr[i]) + 1; j++)			   //
					{															   //
						bookList[i][j] = (char)timeArr[i][j];					   //записываем обратно
					}															   //
					delete[] timeArr[i];										   //
					timeArr[i] = nullptr;										   //
				}
				delete[] timeArr;
				timeArr = nullptr;
				cout << endl;
				cout << "Your list: " << endl;
				for (int i = 0; i < amountOfBooks; i++)
				{
					cout << bookList[i] << endl;
				}
			}
			cout << endl;
		}


		else if (result == 4) {
			cout << "goodbye";
			break;
		}


		else if (result == 5) {
			cout << endl;
			cout << "Your list: " << endl;
			for (int i = 0; i < amountOfBooks; i++)
			{
				cout << bookList[i] << endl;
			}
			cout << endl;
		}
	}
}