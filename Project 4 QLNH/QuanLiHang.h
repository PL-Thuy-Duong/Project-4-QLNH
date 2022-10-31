#pragma once
#include <iostream>
#include "DSLK.h"
#include "Graphics.h" 
#include "Draw.h"
#include <conio.h>
using namespace std;

bool CheckAdmin(string user, string password)
{
	ifstream read("Thongtintk.txt");
	bool check = false;
	string tk, mk;
	while (!read.eof())
	{

		read >> tk;
		read >> mk;
		if (tk == "-1") break;
		if (tk == user && mk == password)
		{
			check = true;
			break;
		}
	}
	return check;
}
bool LoadAmin()
{

	string user, password;
	system("cls");
	DrawLogoAm();
	cout << "\t\t\t\t\t\t\t\t\t\t\t" << "User : ";
	char s;
	while (true)
	{
		s = _getch();
		if (s == 8)
		{
			if (user.size() > 0)
			{
				user.erase(user.end() - 1);
				gotoxy(96, 15);
				cout << user + " ";
				gotoxy(96, 15);
				cout << user;
			}
		}
		else if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(VK_RIGHT))
		{
			
		}
		else if (s != 13)
		{
			gotoxy(96, 15);
			user += s;
			cout << user;
		}
		else if (s == 13)
		{
			break;
		}
	}
	cout << endl;

	cout << "\t\t\t\t\t\t\t\t\t\t\t" << "Password : ";
	string answer = "";
	char x = _getch();;
	while (true)
	{

		if (x == 8) //Backspace
		{
			if (answer.size() > 0)
			{
				string s = "";
				for (int i = 0; i < answer.size() - 1; i++)
				{
					s += "*";
				}
				gotoxy(100, 16);
				cout << s + " ";
				gotoxy(100, 16);
				cout << s;
				answer.erase(answer.end() - 1);
			}
		}
		else if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(VK_RIGHT))
		{

		}
		else if (x != 13) //!Enter
		{
			answer = answer + x;
			gotoxy(100, 16);
			string p = "";
			for (int i = 0; i < answer.size(); i++)
			{
				p += "*";
			}
			cout << p;
		}

		if (x == 13) //Enter
		{
			break;
		}
		x = _getch();
	}
	return CheckAdmin(user, answer);

}
int LoadMenuAdmin()
{

	system("cls");



	int selectedMenu = 1;
	DrawMenuAdmin();
	int _x = 86, _y = 16;
	_y -= 2;
	gotoxy(_x, _y);
	while (true)
	{
		if (GetAsyncKeyState(VK_UP))
		{
			if (_y == 22)
			{
				WriteTextAndColorAndWidth(_x - 1, _y - 1, "Quay Lai Menu ", 8, 30);
				_y -= 3;
				gotoxy(_x, _y);
				WriteTextAndColorAndWidth(_x - 1, _y - 1, "Quan Li Hang Hoa ", 132, 30);
				gotoxy(_x + 1, _y);
				Sleep(250);
				selectedMenu = 2;
			}
			else if (_y > 16)
			{
				WriteTextAndColorAndWidth(_x - 1, _y - 1, "Quan Li Hang Hoa ", 8, 30);
				_y -= 3;
				gotoxy(_x, _y);
				WriteTextAndColorAndWidth(_x - 1, _y - 1, "Quan Li Don Hang ", 132, 30);
				gotoxy(_x + 1, _y);
				Sleep(250);
				selectedMenu = 1;
			}

		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			if (_y == 14)
			{
				_y += 2;
				WriteTextAndColorAndWidth(_x - 1, _y - 1, "Quan Li Don Hang ", 132, 30);
				gotoxy(_x + 2, _y);
				Sleep(250);
			}
			else if (_y == 16)
			{
				WriteTextAndColorAndWidth(_x - 1, _y - 1, "Quan Li Don Hang ", 8, 30);
				_y += 3;
				gotoxy(_x, _y);
				WriteTextAndColorAndWidth(_x - 1, _y - 1, "Quan Li Hang Hoa ", 132, 30);
				gotoxy(_x + 1, _y);
				Sleep(250);
				selectedMenu = 2;
			}
			else if (_y == 19)
			{
				WriteTextAndColorAndWidth(_x - 1, _y - 1, "Quan Li Hang Hoa ", 8, 30);
				_y += 3;
				gotoxy(_x, _y);
				WriteTextAndColorAndWidth(_x - 1, _y - 1, "Quay Lai Menu ", 132, 30);
				gotoxy(_x + 1, _y);
				Sleep(250);
				selectedMenu = 3;
			}

		}
		if (GetAsyncKeyState(13) && _y>=16)
		{
			break;
		}
		
	}
	return selectedMenu;
}
