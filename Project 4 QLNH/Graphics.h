#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

// H�m thay ??i k�ch c? c?a khung cmd v?i tham s? truy?n v�o l� chi?u cao, chi?u r?ng.
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// H�m t� m�u.
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

// H�m d?ch chuy?n con tr? ??n t?a ?? x, y.
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1,y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

// H�m x�a m�n h�nh.
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

// H�m l?y Key t? b�n ph�m
/* GetAsyncKeyState(VK_ESCAPE) => b?t s? ki?n ph�m Esc */

// H�m t? vi?t
void ToMau(char* a, int color) // x, y l� t?a ?? con tr? c?n nh?y ??n ?? vi?t, a l� chu?i c?n truy?n v�o, color l� m�u truy?n v�o.
{
	textcolor(color);
	cout << a;
	textcolor(7);
}