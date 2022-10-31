#pragma once
#include "Graphics.h"
#include <iostream>
#include <string>
#include <fstream>
#include "DSLK.h"
using namespace std;

void DrawRectangle(int x, int y, string text)
{

	//Ve khung
	textcolor(5);
	int _x = x, _y = y;
	gotoxy(_x, _y);
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 30; j++)
		{
			if (i == 1)
			{
				_x += 1;
				gotoxy(_x, _y);
				if (j == 1)        cout << char(218);
				else if (j == 30)  cout << char(191);
				else			   cout << char(196);
			}
			else if (i == 2)
			{
				_x += 1;
				gotoxy(_x, _y);
				if (j == 1 || j == 30) cout << char(179);
				else				   cout << " ";
			}
			else
			{
				_x += 1;

				gotoxy(_x, _y);
				if (j == 1)        cout << char(192);
				else if (j == 30)  cout << char(217);
				else			   cout << char(196);
			}
		}
		_x = x;
		_y += 1;
		gotoxy(_x, _y);
	}
	textcolor(7);
	//Dien chu 
	_x = x + 1;
	_y = y + 1;
	int slkt = 30 - text.size();
	for (int i = 0; i < slkt / 2; i++)
	{
		_x += 1;
		gotoxy(_x, _y);

	}
	for (int i = 0; i < text.size(); i++)
	{
		textcolor(8);
		cout << text[i];
		_x += 1;
		textcolor(7);
		gotoxy(_x, _y);
	}


}
void DrawRectangleWithWidth(int x, int y, string text, int width)
{

	//Ve khung
	textcolor(5);
	int _x = x, _y = y;
	gotoxy(_x, _y);
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= width; j++)
		{
			if (i == 1)
			{
				_x += 1;
				gotoxy(_x, _y);
				if (j == 1)        cout << char(218);
				else if (j == width)  cout << char(191);
				else			   cout << char(196);
			}
			else if (i == 2)
			{
				_x += 1;
				gotoxy(_x, _y);
				if (j == 1 || j == width) cout << char(179);
				else				   cout << " ";
			}
			else
			{
				_x += 1;

				gotoxy(_x, _y);
				if (j == 1)        cout << char(192);
				else if (j == width)  cout << char(217);
				else			   cout << char(196);
			}
		}
		_x = x;
		_y += 1;
		gotoxy(_x, _y);
	}
	textcolor(7);
	//Dien chu 
	_x = x + 1;
	_y = y + 1;
	int slkt = width - text.size();
	for (int i = 0; i < slkt / 2; i++)
	{
		_x += 1;
		gotoxy(_x, _y);

	}
	for (int i = 0; i < text.size(); i++)
	{
		textcolor(8);
		cout << text[i];
		_x += 1;
		textcolor(7);
		gotoxy(_x, _y);
	}


}
void DrawLogo()
{
	ifstream read("Logo.txt");
	string str;
	int indexcolor = 0;
	while (!read.eof())
	{
		getline(read, str);
		textcolor(indexcolor);
		cout << "\t\t\t\t\t" << str << endl;
		indexcolor++;
		if (indexcolor == 7) indexcolor = 1;
	}
	textcolor(7);
}
void DrawNameofPro()
{
	ifstream read("TenDoAn.txt");
	string str;
	//int indexcolor = 0;
	while (!read.eof())
	{
		getline(read, str);
		cout << "\t\t\t\t\t\t\t" << str << endl;

	}
}
void DrawNameProAndLogo()
{
	DrawLogo();
	DrawNameofPro();
}
void DrawInfor()
{
	ifstream read("Thongtin.txt");
	string str;
	int indexcolor = 0;
	while (!read.eof())
	{
		getline(read, str);
		textcolor(indexcolor);
		cout << "\t\t\t" << str << endl;
		if (indexcolor == 15) indexcolor = 1;
		indexcolor++;
	}
	int _x = 57;
	int _y = 28;
	/*_y += 1;
	_x = x - 1;*/
	gotoxy(_x, _y);
	DrawRectangleWithWidth(_x, _y, " BACK ", 10);

	//Draw Button ESC
	_x += 83;
	gotoxy(_x, _y);
	DrawRectangleWithWidth(_x, _y, "ESC", 10);
}
void Menu(string menu1, string menu2, string menu3, string menu4, string menu5, string menu6)
{

	DrawRectangle(85, 20, menu1);
	DrawRectangle(85, 23, menu2);
	DrawRectangle(85, 26, menu3);
	DrawRectangle(85, 29, menu4);
	DrawRectangle(85, 32, menu5);
	DrawRectangle(85, 35, menu6);
}
void WriteTextAndColor(int x, int y, string text, int indexcolor)
{
	int _x = x, _y = y;
	_x = x + 1;
	_y = y + 1;
	int slkt = 30 - (int)text.size();
	/*for (int i = 0; i < slkt / 2; i++)
	{
		_x += 1;
		gotoxy(_x, _y);
		textcolor(indexcolor);
		textcolor(7);

	}*/
	if (slkt % 2 == 1)
	{
		for (int i = 0; i < slkt / 2; i++)
		{
			text.insert(0, " ");
			text.insert(text.size(), " ");
		}
	}
	else
	{
		for (int i = 0; i < (slkt - 1) / 2; i++)
		{
			text.insert(0, " ");
			text.insert(text.size(), " ");
		}
		text.insert(0, " ");
	}
	text.erase(text.size() - 1);
	for (int i = 0; i < text.size(); i++)
	{
		//if (i == 0) _x++;
		_x += 1;
		gotoxy(_x, _y);
		textcolor(indexcolor);
		cout << text[i];
		textcolor(7);


	}

}
void WriteTextAndColorAndWidth(int x, int y, string text, int indexcolor, int width)
{
	int _x = x, _y = y;
	_x = x + 1;
	_y = y + 1;
	int slkt = width - (int)text.size();
	/*for (int i = 0; i < slkt / 2; i++)
	{
		_x += 1;
		gotoxy(_x, _y);
		textcolor(indexcolor);
		textcolor(7);

	}*/
	if (slkt % 2 == 1)
	{
		for (int i = 0; i < slkt / 2; i++)
		{
			text.insert(0, " ");
			text.insert(text.size(), " ");
		}
	}
	else
	{
		for (int i = 0; i < (slkt - 1) / 2; i++)
		{
			text.insert(0, " ");
			text.insert(text.size(), " ");
		}
		text.insert(0, " ");
	}
	text.erase(text.size() - 1);
	for (int i = 0; i < text.size(); i++)
	{
		//if (i == 0) _x++;
		_x += 1;
		gotoxy(_x, _y);
		textcolor(indexcolor);
		cout << text[i];
		textcolor(7);


	}
}
void DrawLogoTTH()
{
	ifstream read("LogoTTHH.txt");
	string str;
	while (!read.eof()) //Kiem tra xem file khac rong
	{
		getline(read, str);
		textcolor(6); //doi mau
		cout << "\t\t\t" << str << endl; //tab
	}
	textcolor(7);
}
void DrawInforGoods(int& x, int& y, LinkedList l)
{
	int _x = x, _y = y;
	gotoxy(_x, _y);
	for (int i = 1; i <= 93; i++)
	{
		if (i == 1) cout << char(201);
		else if (i == 93)  cout << char(187);
		else if (i == 12 || i == 27 || i == 42 || i == 52 || i == 64 || i == 80) cout << char(209);
		else cout << char(205);
	}
	_y += 1;
	gotoxy(_x, _y);
	textcolor(9);
	cout << char(186) << " Ma Hang  " << char(179) << "   Ten Hang   " << char(179) << " Noi San xuat " << char(179) << " Mau sac " << char(179) << "  Gia Ban  " << char(179) << " Ngay Nhap Kho " << char(179) << "  So luong  " << char(186) << endl;
	textcolor(7);
	_y += 1;
	gotoxy(_x, _y);
	while (l.lhead != NULL)
	{
		for (int i = 1; i <= 93; i++)
		{
			if (i == 1)cout << char(199);
			else if (i == 12 || i == 27 || i == 42 || i == 52 || i == 64 || i == 80) cout << char(197);
			else if (i == 93) cout << char(182);
			else cout << char(196);
		}
#pragma region Thong tin hang
		_y += 1;
		gotoxy(_x, _y);
		cout << char(186);
		_x += 3;
		gotoxy(_x, _y);
		cout << l.lhead->mahang;
		_x += 8;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 2;
		gotoxy(_x, _y);
		cout << l.lhead->tenhang;
		_x += 13;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 2;
		gotoxy(_x, _y);
		cout << l.lhead->noisx;
		_x += 13;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 2;
		gotoxy(_x, _y);
		cout << l.lhead->mausac;
		_x += 8;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 2;
		cout << l.lhead->giaban << " VND";
		_x += 10;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 3;
		gotoxy(_x, _y);
		cout << l.lhead->ngaynhapkho;
		_x += 13;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 5;
		gotoxy(_x, _y);
		cout << l.lhead->soluong;
		_x += 8;
		gotoxy(_x, _y);
		cout << char(186);
#pragma endregion



		l.lhead = l.lhead->next;
		_x = x;
		_y += 1;
		gotoxy(_x, _y);
	}
	gotoxy(_x, _y);
	for (int i = 1; i <= 93; i++)
	{
		if (i == 1)cout << char(200);
		else if (i == 12 || i == 27 || i == 42 || i == 52 || i == 64 || i == 80) cout << char(207);
		else if (i == 93) cout << char(188);
		else cout << char(205);
	}
	x = _x;
	y = _y;
}
void DrawInforGoodsAndButton(int& x, int& y, LinkedList l)
{
	//Thanh thong tin
	int _x = x, _y = y;
	gotoxy(_x, _y);
	for (int i = 1; i <= 93; i++)
	{
		if (i == 1) cout << char(201);
		else if (i == 93)  cout << char(187);
		else if (i == 12 || i == 27 || i == 42 || i == 52 || i == 64 || i == 80) cout << char(209);
		else cout << char(205);
	}
	_y += 1;
	gotoxy(_x, _y);
	textcolor(9);
	cout << char(186) << " Ma Hang  " << char(179) << "   Ten Hang   " << char(179) << " Noi San xuat " << char(179) << " Mau sac " << char(179) << "  Gia Ban  " << char(179) << " Ngay Nhap Kho " << char(179) << "  So luong  " << char(186) << endl;
	textcolor(7);
	_y += 1;
	gotoxy(_x, _y);
	while (l.lhead != NULL)
	{
		for (int i = 1; i <= 93; i++)
		{
			if (i == 1)cout << char(199);
			else if (i == 12 || i == 27 || i == 42 || i == 52 || i == 64 || i == 80) cout << char(197);
			else if (i == 93) cout << char(182);
			else cout << char(196);
		}
#pragma region Thong tin hang
		_y += 1;
		gotoxy(_x, _y);
		cout << char(186);
		_x += 3;
		gotoxy(_x, _y);
		cout << l.lhead->mahang;
		_x += 8;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 2;
		gotoxy(_x, _y);
		cout << l.lhead->tenhang;
		_x += 13;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 2;
		gotoxy(_x, _y);
		cout << l.lhead->noisx;
		_x += 13;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 2;
		gotoxy(_x, _y);
		cout << l.lhead->mausac;
		_x += 8;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 2;
		cout << l.lhead->giaban << " VND";
		_x += 10;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 3;
		gotoxy(_x, _y);
		cout << l.lhead->ngaynhapkho;
		_x += 13;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 5;
		gotoxy(_x, _y);
		cout << l.lhead->soluong;
		_x += 8;
		gotoxy(_x, _y);
		cout << char(186);
#pragma endregion



		l.lhead = l.lhead->next;
		_x = x;
		_y += 1;
		gotoxy(_x, _y);
	}
	gotoxy(_x, _y);
	for (int i = 1; i <= 93; i++)
	{
		if (i == 1)cout << char(200);
		else if (i == 12 || i == 27 || i == 42 || i == 52 || i == 64 || i == 80) cout << char(207);
		else if (i == 93) cout << char(188);
		else cout << char(205);
	}

	//Button ESC AND Back

	//Draw Button Back
	_y += 1;
	_x = x - 1;
	gotoxy(_x, _y);
	DrawRectangleWithWidth(_x, _y, " BACK ", 10);

	//Draw Button ESC
	_x += 83;
	gotoxy(_x, _y);
	DrawRectangleWithWidth(_x, _y, "ESC", 10);

	//Set Location recent x ,y
	x = _x;
	y = _y;
}
void DrawLogoTKTT()
{
	ifstream read("LogoTKTT.txt");
	string str;
	while (!read.eof())
	{
		getline(read, str);
		textcolor(9);
		cout << "\t\t\t" << str << endl;
	}
	textcolor(7);
}
void DrawTextBox(int x, int y, string text, int indexcolor, int width)
{
	textcolor(6);
	int _x = x, _y = y;
	gotoxy(_x, _y);
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= width; j++)
		{
			if (i == 1)
			{
				_x += 1;
				gotoxy(_x, _y);
				if (j == 1)        cout << char(218);
				else if (j == width)  cout << char(191);
				else			   cout << char(196);
			}
			else if (i == 2)
			{
				_x += 1;
				gotoxy(_x, _y);
				if (j == 1 || j == width) cout << char(179);
				else				   cout << " ";
			}
			else
			{
				_x += 1;

				gotoxy(_x, _y);
				if (j == 1)        cout << char(192);
				else if (j == width)  cout << char(217);
				else			   cout << char(196);
			}
		}
		_x = x;
		_y += 1;
		gotoxy(_x, _y);
	}
	textcolor(7);
	//Dien chu 
	_x = x + 2;
	_y = y + 1;

	gotoxy(_x, _y);
	textcolor(indexcolor);
	cout << text;
	textcolor(7);
	/*int slkt = width - text.size();
	for (int i = 0; i < slkt / 2; i++)
	{
		_x += 1;
		gotoxy(_x, _y);

	}
	for (int i = 0; i < text.size(); i++)
	{
		textcolor(8);
		cout << text[i];
		_x += 1;
		textcolor(7);
		gotoxy(_x, _y);
	}*/
}
void DrawLogoDHOL()
{
	ifstream read("LogoDTOL.txt");
	string str;
	while (!read.eof())
	{
		getline(read, str);
		textcolor(13);
		cout << "\t\t\t\t" << str << endl;
	}
	textcolor(7);
}
void DrawBuyGoods(int& x, int& y, LinkedList l)
{
	int _x = x, _y = y;
	gotoxy(_x, _y);
	for (int i = 1; i <= 105; i++)
	{
		if (i == 1) cout << char(201);
		else if (i == 105)  cout << char(187);
		else if (i == 12 || i == 27 || i == 42 || i == 52 || i == 64 || i == 80 || i == 93) cout << char(209);
		else cout << char(205);
	}
	_y += 1;
	gotoxy(_x, _y);
	textcolor(9);
	cout << char(186) << " Ma Hang  " << char(179) << "   Ten Hang   " << char(179) << " Noi San xuat " << char(179) << " Mau sac " << char(179) << "  Gia Ban  " << char(179) << " Ngay Nhap Kho " << char(179) << "  So luong  " << char(179) << "           " << char(186) << endl;
	textcolor(7);
	_y += 1;
	gotoxy(_x, _y);
	while (l.lhead != NULL)
	{
		for (int i = 1; i <= 105; i++)
		{
			if (i == 1)cout << char(199);
			else if (i == 12 || i == 27 || i == 42 || i == 52 || i == 64 || i == 80 || i == 93) cout << char(197);
			else if (i == 105) cout << char(182);
			else cout << char(196);
		}
#pragma region Thong tin hang
		_y += 1;
		gotoxy(_x, _y);
		cout << char(186);
		_x += 3;
		gotoxy(_x, _y);
		cout << l.lhead->mahang;
		_x += 8;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 2;
		gotoxy(_x, _y);
		cout << l.lhead->tenhang;
		_x += 13;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 2;
		gotoxy(_x, _y);
		cout << l.lhead->noisx;
		_x += 13;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 2;
		gotoxy(_x, _y);
		cout << l.lhead->mausac;
		_x += 8;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 2;
		cout << l.lhead->giaban << " VND";
		_x += 10;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 3;
		gotoxy(_x, _y);
		cout << l.lhead->ngaynhapkho;
		_x += 13;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 5;
		gotoxy(_x, _y);
		cout << l.lhead->soluong;
		_x += 8;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 5;
		gotoxy(_x, _y);
		textcolor(3);
		cout << "MUA";
		textcolor(7);
		_x += 7;
		gotoxy(_x, _y);
		cout << char(186);
#pragma endregion



		l.lhead = l.lhead->next;
		_x = x;
		_y += 1;
		gotoxy(_x, _y);
	}
	gotoxy(_x, _y);
	for (int i = 1; i <= 105; i++)
	{
		if (i == 1)cout << char(200);
		else if (i == 12 || i == 27 || i == 42 || i == 52 || i == 64 || i == 80 || i == 93) cout << char(207);
		else if (i == 105) cout << char(188);
		else cout << char(205);
	}

	//Set Location
	x = _x;
	y = _y;


	//Draw Button
	_y += 2;
	_x = x - 1;
	DrawRectangleWithWidth(_x, _y, "BACK", 13);
	_x += 43;
	DrawRectangleWithWidth(_x, _y, "Xem Danh Sach Mua", 21);
	_x += 49;
	DrawRectangleWithWidth(_x, _y, "ESC", 13);


}
void DrawLogoDSMH()
{
	ifstream read("LogoDSMH.txt");
	string str;
	while (!read.eof())
	{
		getline(read, str);
		textcolor(13);
		cout << "\t\t\t" << str << endl;
	}
	textcolor(7);
}
void DrawListGoodsBuy(int& x, int& y, LinkedList l)
{
	int _x = x, _y = y;
	gotoxy(_x, _y);
	for (int i = 1; i <= 105; i++)
	{
		if (i == 1) cout << char(201);
		else if (i == 105)  cout << char(187);
		else if (i == 12 || i == 27 || i == 42 || i == 52 || i == 64 || i == 80 || i == 93) cout << char(209);
		else cout << char(205);
	}
	_y += 1;
	gotoxy(_x, _y);
	textcolor(9);
	cout << char(186) << " Ma Hang  " << char(179) << "   Ten Hang   " << char(179) << " Noi San xuat " << char(179) << " Mau sac " << char(179) << "  Gia Ban  " << char(179) << " Ngay Nhap Kho " << char(179) << "  So luong  " << char(179) << "           " << char(186) << endl;
	textcolor(7);
	_y += 1;
	gotoxy(_x, _y);
	while (l.lhead != NULL)
	{
		for (int i = 1; i <= 105; i++)
		{
			if (i == 1)cout << char(199);
			else if (i == 12 || i == 27 || i == 42 || i == 52 || i == 64 || i == 80 || i == 93) cout << char(197);
			else if (i == 105) cout << char(182);
			else cout << char(196);
		}
#pragma region Thong tin hang
		_y += 1;
		gotoxy(_x, _y);
		cout << char(186);
		_x += 3;
		gotoxy(_x, _y);
		cout << l.lhead->mahang;
		_x += 8;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 2;
		gotoxy(_x, _y);
		cout << l.lhead->tenhang;
		_x += 13;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 2;
		gotoxy(_x, _y);
		cout << l.lhead->noisx;
		_x += 13;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 2;
		gotoxy(_x, _y);
		cout << l.lhead->mausac;
		_x += 8;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 2;
		cout << l.lhead->giaban << " VND";
		_x += 10;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 3;
		gotoxy(_x, _y);
		cout << l.lhead->ngaynhapkho;
		_x += 13;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 5;
		gotoxy(_x, _y);
		cout << l.lhead->soluong;
		_x += 8;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 5;
		gotoxy(_x, _y);
		textcolor(12);
		cout << "XOA";
		textcolor(7);
		_x += 7;
		gotoxy(_x, _y);
		cout << char(186);
#pragma endregion



		l.lhead = l.lhead->next;
		_x = x;
		_y += 1;
		gotoxy(_x, _y);
	}
	gotoxy(_x, _y);
	for (int i = 1; i <= 105; i++)
	{
		if (i == 1)cout << char(200);
		else if (i == 12 || i == 27 || i == 42 || i == 52 || i == 64 || i == 80 || i == 93) cout << char(207);
		else if (i == 105) cout << char(188);
		else cout << char(205);
	}

	//Set Location
	x = _x;
	y = _y;


	//Draw Button
	_y += 2;
	_x = x - 1;
	DrawRectangleWithWidth(_x, _y, "BACK", 13);
	_x += 43;
	DrawRectangleWithWidth(_x, _y, "Xu Ly Hoa Don", 21);
	_x += 49;
	DrawRectangleWithWidth(_x, _y, "ESC", 13);


}
void DrawLogoAm()
{
	ifstream read("LogoQLH.txt");
	string str;
	while (!read.eof())
	{
		getline(read, str);
		textcolor(5);
		cout << "\t\t\t\t\t\t\t" << str << endl;
	}
	textcolor(7);
}
void DrawAdmin(int x, int y)
{
	//int _x = x,_y = y;
	////User and Password

	//string str;
	//cout << "Please enter your account" << endl;
	//cout << "\t\t\t\t User";
	//cin >> str;
	/*DrawTextBox(_x, _y, "User : ", 11, 27);
	_y += 4;
	DrawTextBox(_x, _y, "Password : ", 11, 27);
	_y += 4;
	gotoxy(_x +1, _y);
	textcolor(12);
	cout << "Vui long nhap tai khoan !!!";
	textcolor(7);*/
}
void DrawLogoQL()
{
	ifstream read("LogoQuanLi.txt");
	string str;
	while (!read.eof())
	{
		getline(read, str);
		textcolor(2);
		cout << "\t\t\t\t\t\t\t" << str << endl;
	}
	textcolor(7);
}
void DrawMenuAdmin()
{
	DrawLogoQL();
	DrawRectangleWithWidth(85, 15, "Quan Li Don Hang", 30);
	DrawRectangleWithWidth(85, 18, "Quan Li Hang Hoa", 30);
	DrawRectangleWithWidth(85, 21, "Quay Lai Menu", 30);
}
void DrawQLDonHang(int &x ,int &y ,LinkedList l)
{
	int _x = x, _y = y;
	gotoxy(_x, _y);
	for (int i = 1; i <= 105; i++)
	{
		if (i == 1) cout << char(201);
		else if (i == 105)  cout << char(187);
		else if (i == 12 || i == 27 || i == 42 || i == 52 || i == 64 || i == 80 || i == 93) cout << char(209);
		else cout << char(205);
	}
	_y += 1;
	gotoxy(_x, _y);
	textcolor(9);
	cout << char(186) << " Ma Hang  " << char(179) << "   Ten Hang   " << char(179) << " Noi San xuat " << char(179) << " Mau sac " << char(179) << "  Gia Ban  " << char(179) << " Ngay Nhap Kho " << char(179) << "  So luong  " << char(179) << "           " << char(186) << endl;
	textcolor(7);
	_y += 1;
	gotoxy(_x, _y);
	while (l.lhead != NULL)
	{
		for (int i = 1; i <= 105; i++)
		{
			if (i == 1)cout << char(199);
			else if (i == 12 || i == 27 || i == 42 || i == 52 || i == 64 || i == 80 || i == 93) cout << char(197);
			else if (i == 105) cout << char(182);
			else cout << char(196);
		}
#pragma region Thong tin hang
		_y += 1;
		gotoxy(_x, _y);
		cout << char(186);
		_x += 3;
		gotoxy(_x, _y);
		cout << l.lhead->mahang;
		_x += 8;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 2;
		gotoxy(_x, _y);
		cout << l.lhead->tenhang;
		_x += 13;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 2;
		gotoxy(_x, _y);
		cout << l.lhead->noisx;
		_x += 13;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 2;
		gotoxy(_x, _y);
		cout << l.lhead->mausac;
		_x += 8;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 2;
		cout << l.lhead->giaban << " VND";
		_x += 10;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 3;
		gotoxy(_x, _y);
		cout << l.lhead->ngaynhapkho;
		_x += 13;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 5;
		gotoxy(_x, _y);
		cout << l.lhead->soluong;
		_x += 8;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 5;
		gotoxy(_x, _y);
		textcolor(12);
		cout << "XOA";
		textcolor(7);
		_x += 7;
		gotoxy(_x, _y);
		cout << char(186);
#pragma endregion



		l.lhead = l.lhead->next;
		_x = x;
		_y += 1;
		gotoxy(_x, _y);
	}
	gotoxy(_x, _y);
	for (int i = 1; i <= 105; i++)
	{
		if (i == 1)cout << char(200);
		else if (i == 12 || i == 27 || i == 42 || i == 52 || i == 64 || i == 80 || i == 93) cout << char(207);
		else if (i == 105) cout << char(188);
		else cout << char(205);
	}

	//Set Location
	x = _x;
	y = _y;


	//Draw Button
	_y += 2;
	_x = x - 1;
	DrawRectangleWithWidth(_x, _y, "BACK", 13);
	_x += 43;
	DrawRectangleWithWidth(_x, _y, "Xu Ly Hoa Don", 21);
	_x += 49;
	DrawRectangleWithWidth(_x, _y, "ESC", 13);
}
void DrawQLTableDonHang(int &x,int &y,LinkedList l)
{
	int _x = x, _y = y;
	gotoxy(_x, _y);
	for (int i = 1; i <= 105; i++)
	{
		if (i == 1) cout << char(201);
		else if (i == 105)  cout << char(187);
		else if (i == 12 || i == 27 || i == 42 || i == 52 || i == 64 || i == 80 || i == 93) cout << char(209);
		else cout << char(205);
	}
	_y += 1;
	gotoxy(_x, _y);
	textcolor(9);
	cout << char(186) << " Ma Hang  " << char(179) << "   Ten Hang   " << char(179) << " Noi San xuat " << char(179) << " Mau sac " << char(179) << "  Gia Ban  " << char(179) << " Ngay Nhap Kho " << char(179) << "  So luong  " << char(179) << "           " << char(186) << endl;
	textcolor(7);
	_y += 1;
	gotoxy(_x, _y);
	while (l.lhead != NULL)
	{
		for (int i = 1; i <= 105; i++)
		{
			if (i == 1)cout << char(199);
			else if (i == 12 || i == 27 || i == 42 || i == 52 || i == 64 || i == 80 || i == 93) cout << char(197);
			else if (i == 105) cout << char(182);
			else cout << char(196);
		}
#pragma region Thong tin hang
		_y += 1;
		gotoxy(_x, _y);
		cout << char(186);
		_x += 3;
		gotoxy(_x, _y);
		cout << l.lhead->mahang;
		_x += 8;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 2;
		gotoxy(_x, _y);
		cout << l.lhead->tenhang;
		_x += 13;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 2;
		gotoxy(_x, _y);
		cout << l.lhead->noisx;
		_x += 13;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 2;
		gotoxy(_x, _y);
		cout << l.lhead->mausac;
		_x += 8;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 2;
		cout << l.lhead->giaban << " VND";
		_x += 10;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 3;
		gotoxy(_x, _y);
		cout << l.lhead->ngaynhapkho;
		_x += 13;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 5;
		gotoxy(_x, _y);
		cout << l.lhead->soluong;
		_x += 8;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 12;
		gotoxy(_x, _y);
		cout << char(186);
#pragma endregion



		l.lhead = l.lhead->next;
		_x = x;
		_y += 1;
		gotoxy(_x, _y);
	}
	gotoxy(_x, _y);
	for (int i = 1; i <= 105; i++)
	{
		if (i == 1)cout << char(200);
		else if (i == 12 || i == 27 || i == 42 || i == 52 || i == 64 || i == 80 || i == 93) cout << char(207);
		else if (i == 105) cout << char(188);
		else cout << char(205);
	}

	//Set Location
	x = _x;
	y = _y;


	//Draw Button
	_y += 2;
	_x = x - 1;
	DrawRectangleWithWidth(_x, _y, "BACK", 13);
	_x += 43;
	DrawRectangleWithWidth(_x, _y, "Xu Ly Hoa Don", 21);
	_x += 49;
	DrawRectangleWithWidth(_x, _y, "ESC", 13);
}
void DrawQLHangHoa()
{
	cout << "\t\t\t\t\t\t\t\t <===============================MENU===============================>" << endl;
	cout << "\t\t\t\t\t\t\t\t 1.Them San Pham      2.Xoa San Pham     3.Quay Lai Menu      4.Thoat" << endl;
	cout << "\t\t\t\t\t\t\t\t Vui long nhap lua chon : ";
}
void DrawOneInventor(int x, int y, Good* tmp)
{
	
	system("cls");
	DrawLogoQL();
	int _x = x, _y = y;
	gotoxy(_x, _y);
	for (int i = 1; i <= 105; i++)
	{
		if (i == 1) cout << char(201);
		else if (i == 105)  cout << char(187);
		else if (i == 12 || i == 27 || i == 42 || i == 52 || i == 64 || i == 80 || i == 93) cout << char(209);
		else cout << char(205);
	}
	_y += 1;
	gotoxy(_x, _y);
	textcolor(9);
	cout << char(186) << " Ma Hang  " << char(179) << "   Ten Hang   " << char(179) << " Noi San xuat " << char(179) << " Mau sac " << char(179) << "  Gia Ban  " << char(179) << " Ngay Nhap Kho " << char(179) << "  So luong  " << char(179) << "           " << char(186) << endl;
	textcolor(7);
	_y += 1;
	gotoxy(_x, _y);
	
		for (int i = 1; i <= 105; i++)
		{
			if (i == 1)cout << char(199);
			else if (i == 12 || i == 27 || i == 42 || i == 52 || i == 64 || i == 80 || i == 93) cout << char(197);
			else if (i == 105) cout << char(182);
			else cout << char(196);
		}
#pragma region Thong tin hang
		_y += 1;
		gotoxy(_x, _y);
		cout << char(186);
		_x += 3;
		gotoxy(_x, _y);
		cout << tmp->mahang;
		_x += 8;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 2;
		gotoxy(_x, _y);
		cout << tmp->tenhang;
		_x += 13;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 2;
		gotoxy(_x, _y);
		cout << tmp->noisx;
		_x += 13;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 2;
		gotoxy(_x, _y);
		cout << tmp->mausac;
		_x += 8;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 2;
		cout << tmp->giaban << " VND";
		_x += 10;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 3;
		gotoxy(_x, _y);
		cout << tmp->ngaynhapkho;
		_x += 13;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 5;
		gotoxy(_x, _y);
		cout << tmp->soluong;
		_x += 8;
		gotoxy(_x, _y);
		cout << char(179);
		_x += 12;
		gotoxy(_x, _y);
		cout << char(186);
#pragma endregion

		_x = x;
		_y += 1;
		gotoxy(_x, _y);

	gotoxy(_x, _y);
	for (int i = 1; i <= 105; i++)
	{
		if (i == 1)cout << char(200);
		else if (i == 12 || i == 27 || i == 42 || i == 52 || i == 64 || i == 80 || i == 93) cout << char(207);
		else if (i == 105) cout << char(188);
		else cout << char(205);
	}
}