#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

// Hàm thay ??i kích c? c?a khung cmd v?i tham s? truy?n vào là chi?u cao, chi?u r?ng.
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// Hàm tô màu.
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

// Hàm d?ch chuy?n con tr? ??n t?a ?? x, y.
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1,y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

// Hàm xóa màn hình.
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

// Hàm l?y Key t? bàn phím
/* GetAsyncKeyState(VK_ESCAPE) => b?t s? ki?n phím Esc */

// Hàm t? vi?t
void ToMau(char* a, int color) // x, y là t?a ?? con tr? c?n nh?y ??n ?? vi?t, a là chu?i c?n truy?n vào, color là màu truy?n vào.
{
	textcolor(color);
	cout << a;
	textcolor(7);
}