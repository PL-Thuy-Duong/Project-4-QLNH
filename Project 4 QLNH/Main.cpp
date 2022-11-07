#include <iostream>
#include <string>
#include "Graphics.h"
#include "Draw.h"
#include "QuanLiHang.h"
#include "conio.h"
using namespace std;


Good* good;
int index = 1000;

LinkedList l;
LinkedList ListHangMua;
LinkedList ListXuLy;

int LoadMenuMain();
int LoadInforGoods();
int LoadInfor();
int LoadSearchInfor();
int LoadBuyGoods();
int LoadListGoodsBuy();
int LoadMenuAdmin();
bool LoadAmin();
bool CheckAdmin(string user, string password);
int LoadMenuXulyDonHang();
int LoadMenuXuLyHangHoa();
void XuLyDonHang();
bool Xuly();



int main()
{
	resizeConsole(3050, 2050);

	LoadData(l, "DataDSLK.txt");
	Start:
	system("cls");
	int SelectedMenu = LoadMenuMain();

	if (SelectedMenu == 6) //Thong Tin Hang
	{
		int Selected = LoadInforGoods();
		//BACK
		if (Selected == 1)
		{
			//Use goto
			system("cls");
			goto Start;
		}
		//ESC
		else if (Selected == 2)
		{
			exit(0);
		}
	}
	else if (SelectedMenu == 5) //Tim Kiem Hang
	{
		SearchInfor:
		int selectedMenu = LoadSearchInfor();
		if (selectedMenu == 1)
		{
			//Use goto
			system("cls");
			goto Start;
		}
		//ESC
		else if (selectedMenu == 2)
		{
			exit(0);
		}
		else if (selectedMenu == 100)
		{
			
			DrawOneInventor(47, 18, good);
			cout << endl;
			system("pause");
			goto SearchInfor;
		}
	}
	else if (SelectedMenu == 4) //Dat Hang Online
	{
	Dathang:
		int select = LoadBuyGoods();
		if (select == 1) //BACK
		{

			system("cls");
			goto Start;
		}
		else if (select == 2) //Xem danh sach mua
		{
		Dsmua:
			int slc = LoadListGoodsBuy();
			if (slc == 1) //BACK
			{
				system("cls");
				goto Dathang;
			}
			else if (slc == 2) //Xu Ly Don Hang
			{
				XuLyDonHang();
				goto Dathang;
			}
			else if (slc == 3) //ESC
			{
				exit(0);
			}
			else if (slc == 0) //Reload
			{
				system("cls");
				goto Dsmua;
			}
		}
		else if (select == 3) //ESC
		{
			exit(0);
		}
		else if (select == 0) //Reload danh sach hang 
		{
			system("cls");
			goto Dathang;
		}
	}
	else if (SelectedMenu == 3) //Quan Li Hang
	{
		bool f = Xuly();
		if (f)
		{
			Lai:
			int x = LoadMenuAdmin();
			if (x == 1)
			{
				Nay:
				int slc = LoadMenuXulyDonHang();
				if (slc == 1) //back
				{
					goto Lai;
				}
				//Xu ly don hang
				else if (slc == 2) 
				{
					system("cls");
					cout << "Don hang dang dc xu ly";
					Sleep(500);
					cout << ".";
					Sleep(500);
					cout << ".";
					Sleep(500);
					cout << ".";
					Sleep(500);
					cout << ".";
					Sleep(500);
					cout << ".";
					cout << endl << "Da Xu Ly Thanh Cong";
					ResetLinkedList(ListXuLy);
					ofstream os("ThongTinDatHang.txt");
					os << "-1";
					os.close();
					goto Nay;
				}
				else if (3)
				{
					exit(0);
				}

			}
			else if (x == 2)
			{
				int s = LoadMenuXuLyHangHoa();
				if (s == 1)
				{
					goto Lai;
				}

			}
			else if (x == 3)
			{
				goto Start;
			}
		}
		else
		{
			goto Start;
		}
	}
	else if (SelectedMenu == 2) //Thong Tin
	{
		int Selected = LoadInfor();
		if (Selected == 1)
		{
			system("cls");
			goto Start;
		}
		else
		{
			exit(0);
		}
	}
	else if (SelectedMenu == 1) //Exit
	{
		exit(0);
	}

	system("pause");
}
int LoadMenuMain()
{
	int SelectMenu = 0;
	DrawNameProAndLogo();
	Menu("THONG TIN HANG HOA", "TIM KIEM THONG TIN", "DAT HANG ONLINE", "QUAN LI HANG", "THONG TIN", "THOAT");
	int xnow = 85, ynow = 18;
	gotoxy(xnow + 2, ynow);
	while (true)
	{
		if (GetAsyncKeyState(VK_UP))
		{
			if (ynow > 21)
			{
				SelectMenu += 1;
				ynow -= 3;
				gotoxy(xnow, ynow);
				Menu("THONG TIN HANG HOA", "TIM KIEM THONG TIN", "DAT HANG ONLINE", "QUAN LI HANG", "THONG TIN", "THOAT");
				switch (ynow)
				{
				case 20:
				{
					WriteTextAndColor(xnow, ynow, "THONG TIN HANG HOA", 132);
					SelectMenu = 6;
					break;
				}
				case 23:
				{
					WriteTextAndColor(xnow, ynow, "TIM KIEM THONG TIN", 132);
					SelectMenu = 5;
					break;
				}
				case 26:
				{
					WriteTextAndColor(xnow, ynow, "DAT HANG ONLINE", 132);
					SelectMenu = 4;
					break;
				}
				case 29:
				{
					WriteTextAndColor(xnow, ynow, "QUAN LI HANG", 132);
					SelectMenu = 3;
					break;
				}
				case 32:
				{
					WriteTextAndColor(xnow, ynow, "THONG TIN", 132);
					SelectMenu = 2;
					break;
				}
				case 35:
				{
					WriteTextAndColor(xnow, ynow, "THOAT", 132);
					SelectMenu = 1;
					break;
				}
				}
				gotoxy(xnow + 2, ynow + 1);

				Sleep(250);
			}
		}
		else if (GetAsyncKeyState(VK_DOWN))
		{
			if (ynow == 18)
			{
				ynow += 2;
				WriteTextAndColor(xnow, ynow, "THONG TIN HANG HOA", 132);
				gotoxy(xnow + 2, ynow + 1);
				SelectMenu = 6;
				Sleep(250);
			}
			else if (ynow < 35)
			{
				SelectMenu -= 1;
				ynow += 3;
				gotoxy(xnow, ynow);
				Menu("THONG TIN HANG HOA", "TIM KIEM THONG TIN", "DAT HANG ONLINE", "QUAN LI HANG", "THONG TIN", "THOAT");
				switch (ynow)
				{
				case 20:
				{
					WriteTextAndColor(xnow, ynow, "THONG TIN HANG HOA", 132);
					SelectMenu = 6;
					break;
				}
				case 23:
				{
					WriteTextAndColor(xnow, ynow, "TIM KIEM THONG TIN", 132);
					SelectMenu = 5;
					break;
				}
				case 26:
				{
					WriteTextAndColor(xnow, ynow, "DAT HANG ONLINE", 132);
					SelectMenu = 4;
					break;
				}
				case 29:
				{
					WriteTextAndColor(xnow, ynow, "QUAN LI HANG", 132);
					SelectMenu = 3;
					break;
				}
				case 32:
				{
					WriteTextAndColor(xnow, ynow, "THONG TIN", 132);
					SelectMenu = 2;
					break;
				}
				case 35:
				{
					WriteTextAndColor(xnow, ynow, "THOAT", 132);
					SelectMenu = 1;
					break;
				}
				}


				gotoxy(xnow + 2, ynow + 1);
				Sleep(250);

			}
		}
		if (GetAsyncKeyState(13) && ynow >= 20 && SelectMenu > 0)
		{
			return SelectMenu;
		}


	}
}
int LoadInforGoods()
{
	int _x = 57;
	int _y = 15;
	int selectedMenu = 1;
	system("cls");
	DrawLogoTTH();
	DrawInforGoodsAndButton(_x, _y, l);

	//cout << _x << " " << _y;
	//139 26   56
	_x -= 83;
	gotoxy(_x, _y);
	WriteTextAndColorAndWidth(_x, _y, "BACK ", 132, 10);
	WriteTextAndColorAndWidth(_x + 83, _y, "ESC", 8, 10);
	gotoxy(_x + 2, _y + 1);
	while (true)
	{
		if (GetAsyncKeyState(VK_LEFT))
		{
			if (_x >= 139)
			{
				_x -= 83;
				WriteTextAndColorAndWidth(_x, _y, "BACK ", 132, 10);
				WriteTextAndColorAndWidth(_x + 83, _y, "ESC", 8, 10);
				gotoxy(_x + 2, _y + 1);
				//riteTextAndColor(_x - 83, _y, "BACK", 132);
				//BACK
				selectedMenu = 1;
			}
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			if (_x <= 58)
			{
				_x += 83;
				WriteTextAndColorAndWidth(_x, _y, "ESC", 132, 10);
				WriteTextAndColorAndWidth(_x - 83, _y, "BACK", 8, 10);
				gotoxy(_x + 2, _y + 1);
				//WriteTextAndColor(_x + 83, _y, "BACK", 132);
				//ESC
				selectedMenu = 2;
			}
		}
		if (GetAsyncKeyState(13))
		{
			return selectedMenu;
		}
	}
}
int LoadInfor()
{
	system("cls");
	DrawInfor();
	int selectedMenu = 1;
	int _x = 57;
	int _y = 28;
	//_x -= 56;
	gotoxy(_x, _y);
	WriteTextAndColorAndWidth(_x, _y, "BACK ", 132, 10);
	WriteTextAndColorAndWidth(_x + 83, _y, "ESC", 8, 10);
	gotoxy(_x + 2, _y + 1);
	while (true)
	{
		if (GetAsyncKeyState(VK_LEFT))
		{
			if (_x >= 139)
			{
				_x -= 83;
				WriteTextAndColorAndWidth(_x, _y, "BACK ", 132, 10);
				WriteTextAndColorAndWidth(_x + 83, _y, "ESC", 8, 10);
				gotoxy(_x + 2, _y + 1);
				//riteTextAndColor(_x - 83, _y, "BACK", 132);
				//BACK
				selectedMenu = 1;
			}
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			if (_x <= 58)
			{
				_x += 83;
				WriteTextAndColorAndWidth(_x, _y, "ESC", 132, 10);
				WriteTextAndColorAndWidth(_x - 83, _y, "BACK", 8, 10);
				gotoxy(_x + 2, _y + 1);
				//WriteTextAndColor(_x + 83, _y, "BACK", 132);
				//ESC
				selectedMenu = 2;
			}
		}
		if (GetAsyncKeyState(13))
		{
			return selectedMenu;
		}
	}
}
int LoadSearchInfor()
{
	
	Lai:
	system("cls");
	int _x = 27, _y = 18;
	int selectedmenu = 1;
	DrawLogoTKTT();
	
	DrawInforGoods(_x, _y, l);
	DrawTextBox(130, 18, "Tim kiem : ", 7, 30);

	_y += 2;
	_x -= 1;
	//Button Back
	DrawRectangleWithWidth(_x, _y, "BACK", 15);
	//Button ESC
	DrawRectangleWithWidth(_x + 119, _y, "ESC", 15);

	
	
	_x -= 2;
	gotoxy(_x + 2, _y + 1);
	 //x=26 y=36

	while (true)
	{

		if (GetAsyncKeyState(VK_UP))
		{
			
			string str = "Tim kiem : ";
			int xsearch = 130 + str.size() + 1;
			int ysearch = 19;
			gotoxy(xsearch, ysearch);
			system("pause");
			gotoxy(xsearch, ysearch);
			textcolor(6);
			cout << "                  "<<char(179)<< "            ";
			textcolor(7);
			gotoxy(xsearch, ysearch);
			string searchstr = "";
			char x;
			while (true)
			{
				x = _getch();
				if (x == 13) // Phim enter
				{
					if (searchstr.size() == 0)
					{
						goto Lai;
					}
					else
					{
						Good* tmp = ReturnGoodMaHang(l, searchstr);
						if (tmp != NULL)
						{
							good = tmp;
							return 100;
						}
						else
						{
							goto Lai;
						}
					}
				}
				else if (GetAsyncKeyState(VK_DOWN)) //Phim xuong
				{
					gotoxy(_x + 2, _y + 1);
					goto Nay;
				}
				else if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(VK_RIGHT))
				{

				}
				else if (x == 8) //Phim backspace
				{
					if (searchstr.size() > 0)
					{
						searchstr.erase(searchstr.end() - 1);
						gotoxy(xsearch, ysearch);
						cout << searchstr+" ";
						gotoxy(xsearch, ysearch);
						cout << searchstr;
					}

				}
				else
				{
					searchstr += x;
					gotoxy(xsearch, ysearch);
					cout << searchstr;
				}
				
			}

		}
		Nay:
		if (GetAsyncKeyState(VK_DOWN))
		{

		}
		if (GetAsyncKeyState(VK_LEFT))
		{
			if (_x > 26)
			{

				_x -= 119;
				WriteTextAndColorAndWidth(_x, _y, "BACK ", 132, 15);
				WriteTextAndColorAndWidth(_x + 119, _y, "ESC", 8, 15);
				gotoxy(_x + 2, _y + 1);
				Sleep(300);
				selectedmenu = 1;
			}
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			if (_x == 24)
			{
				_x += 2;
				WriteTextAndColorAndWidth(_x, _y, "BACK", 132, 15);
				gotoxy(_x + 2, _y + 1);
				Sleep(250);
			}
			else if (_x <= 119)
			{

				_x += 119;
				WriteTextAndColorAndWidth(_x, _y, "ESC", 132, 15);
				WriteTextAndColorAndWidth(_x - 119, _y, "BACK", 8, 15);
				gotoxy(_x + 2, _y + 1);
				Sleep(300);
				selectedmenu = 2;
			}
		}
		if (GetAsyncKeyState(13) && _x>=26)
		{
			return selectedmenu;
		}

	}

}
int LoadBuyGoods()
{
	system("cls");
	int SelectedMenu = 1;
	int SelectedBuy = 0;
	int _x = 45, _y = 18;
	DrawLogoDHOL();
	DrawBuyGoods(_x, _y, l);
	//WriteTextAndColorAndWidth(_x+91, _y - 10,"BUY ",132,13);
	int xmax = _x, ymax = _y;

	_x += 93;
	_y -= ymax - 19;
	gotoxy(_x, _y);

	while (true)
	{
		if (GetAsyncKeyState(VK_UP))
		{
			if (_y > 21 && _y <= ymax - 1)
			{
				if (_y != ymax + 1)
					WriteTextAndColorAndWidth(_x - 2, _y - 1, "MUA ", 9, 13);
				_y -= 2;
				gotoxy(_x, _y);
				WriteTextAndColorAndWidth(_x - 2, _y - 1, "MUA ", 132, 13);
				gotoxy(_x, _y);
				Sleep(250);
				SelectedBuy -= 1;
			}
			else if (_y >= ymax - 1 && _x == 45)
			{

				WriteTextAndColorAndWidth(_x + 91, _y - 5, "MUA ", 132, 13);
				_x += 93;
				_y -= 4;
				gotoxy(_x, _y);
				WriteTextAndColorAndWidth(_x - 94, _y + 3, "BACK ", 8, 13);
				gotoxy(_x, _y);
				Sleep(250);
				//Set select = 1 // BACK
				SelectedMenu = 1;
			}

		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			if (_y < ymax - 1)
			{
				if (_y != 19) WriteTextAndColorAndWidth(_x - 2, _y - 1, "MUA ", 9, 13);
				_y += 2;
				WriteTextAndColorAndWidth(_x - 2, _y - 1, "MUA ", 132, 13);
				gotoxy(_x, _y);
				Sleep(250);
				//SelectedBuy
				SelectedBuy += 1;
			}
			else if (_y == ymax - 1)
			{
				if (_y != 19) WriteTextAndColorAndWidth(_x + 93, _y + 4, "MUA ", 9, 13);
				_x -= 93;
				_y += 4;
				gotoxy(_x, _y);
				WriteTextAndColorAndWidth(_x - 1, _y - 1, "BACK ", 132, 13);
				Sleep(250);
			}
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			if (_x == 45)
			{
				WriteTextAndColorAndWidth(_x - 1, _y - 1, "BACK ", 8, 13);
				_x += 43;
				gotoxy(_x, _y);
				WriteTextAndColorAndWidth(_x - 1, _y - 1, "Xem Danh Sach Mua", 132, 21);
				Sleep(250);
				SelectedMenu = 2; //Xem danh sach mua
			}
			else if (_x == 88)
			{
				WriteTextAndColorAndWidth(_x - 1, _y - 1, "Xem Danh Sach Mua ", 8, 21);
				_x += 49;
				gotoxy(_x, _y);
				WriteTextAndColorAndWidth(_x - 1, _y - 1, "ESC ", 132, 13);
				Sleep(250);
				SelectedMenu = 3; //ESC
			}
		}
		if (GetAsyncKeyState(VK_LEFT))
		{
			if (_x == 88)
			{
				WriteTextAndColorAndWidth(_x - 1, _y - 1, "Xem Danh Sach Mua ", 8, 21);
				_x -= 43;
				gotoxy(_x, _y);
				WriteTextAndColorAndWidth(_x - 1, _y - 1, "BACK ", 132, 13);
				Sleep(250);
				SelectedMenu = 1; //BACK
			}
			else if (_x == 137)
			{
				WriteTextAndColorAndWidth(_x - 1, _y - 1, "ESC ", 8, 13);
				_x -= 49;
				gotoxy(_x, _y);
				WriteTextAndColorAndWidth(_x - 1, _y - 1, "Xem Danh Sach Mua ", 132, 21);
				Sleep(250);
				SelectedMenu = 2;//Xem danh sach mua
			}
		}
		if (GetAsyncKeyState(13) && _y > ymax - 1)
		{

			return SelectedMenu;
		}
		if (GetAsyncKeyState(13) && _y <= ymax - 1)
		{

			//Xu ly mua hang



			//Giam so luong trong cua hang
			Delete_Amount(l, SelectedBuy, -1);

			//Tang so luong trong gio hang ( kiem tra xem da co trong gio hang hay chua bang ma sp)
			Add_Amount(ListHangMua, SelectedBuy, 1, ReturnGoodIndex(l, SelectedBuy));

			Sleep(250);
			SelectedBuy = 0;
			return 0;




		}
	}
}
int LoadListGoodsBuy()
{
	/*system("cls");
	int _x = 45, _y = 18;
	DrawLogoDHOL();
	DrawListGoodsBuy(_x, _y, ListHangMua);*/
	system("cls");
	int SelectedMenu = 1;
	int SelectedBuy = 0;
	int _x = 45, _y = 18;
	DrawLogoDSMH();
	DrawListGoodsBuy(_x, _y, ListHangMua);
	//WriteTextAndColorAndWidth(_x+91, _y - 10,"BUY ",132,13);
	int xmax = _x, ymax = _y;

	_x += 93;
	_y -= ymax - 19;
	gotoxy(_x, _y);

	while (true)
	{
		if (GetAsyncKeyState(VK_UP))
		{
			if (_y > 21 && _y <= ymax - 1)
			{
				if (_y != ymax + 1)
					WriteTextAndColorAndWidth(_x - 2, _y - 1, "XOA ", 12, 13);
				_y -= 2;
				gotoxy(_x, _y);
				WriteTextAndColorAndWidth(_x - 2, _y - 1, "XOA ", 132, 13);
				gotoxy(_x, _y);
				Sleep(250);
				SelectedBuy -= 1;
			}
			else if (_y >= ymax - 1 && _x == 45)
			{

				WriteTextAndColorAndWidth(_x + 91, _y - 5, "XOA ", 132, 13);
				_x += 93;
				_y -= 4;
				gotoxy(_x, _y);
				WriteTextAndColorAndWidth(_x - 94, _y + 3, "BACK ", 8, 13);
				gotoxy(_x, _y);
				Sleep(250);
				//Set select = 1 // BACK
				SelectedMenu = 1;
			}

		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			if (_y < ymax - 1)
			{
				if (_y != 19) WriteTextAndColorAndWidth(_x - 2, _y - 1, "XOA ", 12, 13);
				_y += 2;
				WriteTextAndColorAndWidth(_x - 2, _y - 1, "XOA ", 132, 13);
				gotoxy(_x, _y);
				Sleep(250);
				//SelectedBuy

				SelectedBuy += 1;
			}
			else if (_y == ymax - 1)
			{
				if (_y != 19) WriteTextAndColorAndWidth(_x + 93, _y + 4, "XOA ", 12, 13);
				_x -= 93;
				_y += 4;
				gotoxy(_x, _y);
				WriteTextAndColorAndWidth(_x - 1, _y - 1, "BACK ", 132, 13);
				Sleep(250);
			}
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			if (_x == 45)
			{
				WriteTextAndColorAndWidth(_x - 1, _y - 1, "BACK ", 8, 13);
				_x += 43;
				gotoxy(_x, _y);
				WriteTextAndColorAndWidth(_x - 1, _y - 1, "Xu Ly Don Hang ", 132, 21);
				Sleep(250);
				SelectedMenu = 2; //Xu Ly Don Hang
			}
			else if (_x == 88)
			{
				WriteTextAndColorAndWidth(_x - 1, _y - 1, "Xu Ly Don Hang ", 8, 21);
				_x += 49;
				gotoxy(_x, _y);
				WriteTextAndColorAndWidth(_x - 1, _y - 1, "ESC ", 132, 13);
				Sleep(250);
				SelectedMenu = 3; //ESC
			}

		}
		if (GetAsyncKeyState(VK_LEFT))
		{
			if (_x == 88)
			{
				WriteTextAndColorAndWidth(_x - 1, _y - 1, "Xu Ly Don Hang ", 8, 21);
				_x -= 43;
				gotoxy(_x, _y);
				WriteTextAndColorAndWidth(_x - 1, _y - 1, "BACK ", 132, 13);
				Sleep(250);
				SelectedMenu = 1; //BACK
			}
			else if (_x == 137)
			{
				WriteTextAndColorAndWidth(_x - 1, _y - 1, "ESC ", 8, 13);
				_x -= 49;
				gotoxy(_x, _y);
				WriteTextAndColorAndWidth(_x - 1, _y - 1, "Xu Ly Don Hang ", 132, 21);
				Sleep(250);
				SelectedMenu = 2;//Xu Ly Don Hang
			}
		}
		if (GetAsyncKeyState(13) && _y > ymax - 1)
		{
			return SelectedMenu;
		}
		if (GetAsyncKeyState(13) && _y <= ymax - 1)
		{

			//Xu ly mua hang




			//Giam so luong trong danh sach mua hang
			Good* t = ListHangMua.lhead;
			for (int i = 0; i < SelectedBuy - 1; i++)
			{
				t = t->next;
			}
			int tmpindex = t->index;
			if (t->soluong > 1)
			{
				Delete_Amount_Goods_Buy(ListHangMua, tmpindex, -1);
			}
			else if (t->soluong == 1)
			{
				DeleteAll(ListHangMua, tmpindex);
			}

			//Tang so luong trong cua hang 
			Add_Amount_Goods_Buy(l, tmpindex, 1);

			//Sleep(250);
			SelectedBuy = 0;
			return 0;
		}
	}
}
int LoadMenuXulyDonHang()
{
	system("cls");
	char c;
	cout << "Hay nhan phim enter !";
	while (true)
	{
		c = _getch();
		if (c != 32) {
			fflush(stdin);
			break;
		}
		//Sleep(3000);
	}
	system("cls");
	cout << "Vui long nhan phim space de chon !";

	DrawLogoQL();
	LoadData(ListXuLy, "ThongTinDatHang.txt");

	int SelectedMenu = 1;
	int _x = 45, _y = 18;
	//DrawQLDonHang(_x, _y, ListXuLy);
	DrawQLTableDonHang(_x, _y, ListXuLy);
	_x = 45;
	_y += 3;

	gotoxy(_x, _y);
	WriteTextAndColorAndWidth(_x - 1, _y - 1, "BACK ", 132, 13);
	while (true)
	{
		if (GetAsyncKeyState(VK_RIGHT))
		{
			if (_x == 45)
			{
				WriteTextAndColorAndWidth(_x - 1, _y - 1, "BACK ", 8, 13);
				_x += 43;
				gotoxy(_x, _y);
				WriteTextAndColorAndWidth(_x - 1, _y - 1, "Xu Ly Don Hang ", 132, 21);
				Sleep(250);
				SelectedMenu = 2; //Xu Ly Don Hang
			}
			else if (_x == 88)
			{
				WriteTextAndColorAndWidth(_x - 1, _y - 1, "Xu Ly Don Hang ", 8, 21);
				_x += 49;
				gotoxy(_x, _y);
				WriteTextAndColorAndWidth(_x - 1, _y - 1, "ESC ", 132, 13);
				Sleep(250);
				SelectedMenu = 3; //ESC
			}

		}
		if (GetAsyncKeyState(VK_LEFT))
		{
			if (_x == 88)
			{
				WriteTextAndColorAndWidth(_x - 1, _y - 1, "Xu Ly Don Hang ", 8, 21);
				_x -= 43;
				gotoxy(_x, _y);
				WriteTextAndColorAndWidth(_x - 1, _y - 1, "BACK ", 132, 13);
				Sleep(250);
				SelectedMenu = 1; //BACK
			}
			else if (_x == 137)
			{
				WriteTextAndColorAndWidth(_x - 1, _y - 1, "ESC ", 8, 13);
				_x -= 49;
				gotoxy(_x, _y);
				WriteTextAndColorAndWidth(_x - 1, _y - 1, "Xu Ly Don Hang ", 132, 21);
				Sleep(250);
				SelectedMenu = 2;//Xu Ly Don Hang
			}
		}
		if (GetAsyncKeyState(32))
		{
			return SelectedMenu;
		}
	}
}
int LoadMenuXuLyHangHoa()
{
	Lai:
	system("cls");
	DrawQLHangHoa();
	int x; cin >> x;
	if (x == 1) //Them sp;
	{

		string _mahang;
		string _tenhang;
		int    _giaban;
		string _noisx;
		string _ngaynhapkho;
		string _mausac;
		int    _soluong;

		cout << "\t\t\t\t\t\t\t\t Nhap ma Hang: ";
		cin >> _mahang;
		cin.ignore();
		cout << "\t\t\t\t\t\t\t\t Nhap Ten Hang: ";
		getline(cin, _tenhang);
		cout << "\t\t\t\t\t\t\t\t Nhap Gia Ban: ";
		cin >> _giaban;
		cin.ignore();
		cout << "\t\t\t\t\t\t\t\t Nhap noi san xuat: ";
		getline(cin, _noisx);
		cout << "\t\t\t\t\t\t\t\t Nhap ngay nhap kho: ";
		cin >> _ngaynhapkho;
		cout << "\t\t\t\t\t\t\t\t Nhap mau sac: ";
		cin >> _mausac;
		cout << "\t\t\t\t\t\t\t\t Nhap so luong: ";
		cin >> _soluong;
		Good* tmp = CreateGood(index, _mahang, _tenhang, _noisx, _giaban, _ngaynhapkho, _mausac, _soluong);
		InsertEnd(l, tmp);
		index++;
		cout << "Dang duoc xu ly vui long doi";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";

		cout << "endl" << "Xu ly thanh cong";
		system("pause");
		goto Lai;
	}
	else if (x == 2) //Xoa sp
	{

		cout << "\t\t\t\t\t\t\t\t Vui long nhap ma san pham can xoa : ";
		string s;
		cin >> s;

		cout << "Dang duoc xu ly vui long doi";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";

		cout << "endl" << "Xu ly thanh cong";
		DeleteMaSanPham(l, s);
		system("pause");
		goto Lai;
	}
	else if (x == 3) //Quay lai menu
	{
		return 1;
	}
	else if (x == 4) //ESC
	{
		exit(0);
	}
	return 0;
}
void XuLyDonHang()
{
	system("cls");
	//cout << "Xu Ly Thanh Cong";
	cout << "Dang duoc xu ly vui long doi ";
	Sleep(1000);
	cout << ".";
	Sleep(3000);
	cout << ".";
	Sleep(3000);
	cout << ".";

	WriteData(ListHangMua, "ThongTinDatHang");
	ResetLinkedList(ListHangMua);
	cout << endl << "Xu ly thanh cong !" << endl;
	system("pause");
}
bool Xuly()
{
	int count = 0;
	
	system("cls");
	char x;
	while (true)
	{
		x = _getch();
		if (x == 13) break;
	}
	Loadadmin:
	if (x == 13)
	{
		bool f = LoadAmin();
		if (f) //Dang nhap thanh cong
		{

		
			return true;

		}
		else //Dang nhap that bai
		{
			count++;
			if (count == 4)
			{
				return false;
			}
			else
			{
				goto Loadadmin;
			}
		}
	}
}
