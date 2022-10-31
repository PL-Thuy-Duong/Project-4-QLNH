#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Good {
	int index;
	string mahang;
	string tenhang;
	string noisx;
	int giaban;
	string ngaynhapkho;
	string mausac;
	int soluong;
	Good* next;
};
Good* CreateGood(int _index, string _mahang, string _tenhang, string _noisx, int _giaban, string _ngaynhapkho, string _mausac, int _soluong)
{
	Good* tmp = new Good;
	tmp->index = _index;
	tmp->mahang = _mahang;
	tmp->tenhang = _tenhang;
	tmp->giaban = _giaban;
	tmp->noisx = _noisx;
	tmp->ngaynhapkho = _ngaynhapkho;
	tmp->mausac = _mausac;
	tmp->soluong = _soluong;
	tmp->next = NULL;
	return tmp;
}
struct LinkedList
{
	Good* lhead;
	Good* ltail;
};
Good* ReturnGoodIndex(LinkedList l, int index)
{

	Good* tmp = NULL;
	Good* run = l.lhead;
	while (run != NULL)
	{
		if (run->index == index - 1)
		{
			tmp = run;
			break;
		}
		else
		{
			run = run->next;
		}
	}
	return tmp;
}
Good* ReturnGoodMaHang(LinkedList l, string _mahang)
{

	Good* tmp = NULL;
	Good* run = l.lhead;
	while (run != NULL)
	{
		if (run->mahang == _mahang)
		{
			tmp = run;
			break;
		}
		else
		{
			run = run->next;
		}
	}
	return tmp;
}
void Display(LinkedList l)
{
	while (l.lhead != NULL)
	{
		cout << l.lhead->index << endl;
		cout << l.lhead->mahang << endl;
		cout << l.lhead->tenhang << endl;
		cout << l.lhead->giaban << endl;
		cout << l.lhead->noisx << endl;
		cout << l.lhead->ngaynhapkho << endl;
		cout << l.lhead->mausac << endl;
		cout << l.lhead->soluong << endl;
		l.lhead = l.lhead->next;
	}
}
int Size(LinkedList l)
{
	int count = 0;
	while (l.lhead != NULL)
	{
		count++;
		l.lhead = l.lhead->next;
	}
	return count;
}
void CreateLinkedList(LinkedList& l)
{
	l.lhead = NULL;
	l.ltail = NULL;
}
void InsertEnd(LinkedList& l, Good* g)
{
	if (l.lhead == NULL)
	{
		l.lhead = g;
		l.ltail = g;
	}
	else
	{

		l.ltail->next = g;
		l.ltail = g;

	}
}
void DeleteHead(LinkedList& ds)
{
	//tao node p
	Good* p = new Good;
	//gan p bang node pHead dau tien cua danh sach 
	p = ds.lhead;
	//thay doi lai pHead cua danh sach
	ds.lhead = ds.lhead->next;
	//gan node p ban dau tro den NULL
	p->next = NULL;
	//xoa node p
	delete p;
}
void DeleteEnd(LinkedList& ds)
{
	//duyet cac phan tu co trong danh sach
	for (Good* k = ds.lhead; k != NULL; k = k->next)
	{
		//neu duyet den phan tu pTail cuoi trong danh sach
		if (k->next == ds.ltail)
		{
			//xoa phan tu cuoi
			delete ds.ltail;
			//tro phan tu truoc phan tu cuoi ve NULL
			k->next = NULL;
			//thay doi lai phan tu cuoi pTail cua danh sach
			ds.ltail = k;
		}
	}
}
void DeleteAll(LinkedList& ds, int data)
{
	//tao node p de luu tru phan tu truoc node k can xoa
	Good* p = new Good;
	//neu data dau vao bang voi pHead->data thi xoa dau
	if (ds.lhead->index == data) {
		//goi ham xoa dau
		DeleteHead(ds);
		//ket thuc ham
		return;
	}
	//neu data bang voi pTail->data thi xoa cuoi
	if (ds.ltail->index == data) {
		//goi ham xoa cuoi
		DeleteEnd(ds);
		//ket thuc ham
		return;
	}
	//duyet qua cac phan tu co trong danh sach
	for (Good* k = ds.lhead; k != NULL; k = k->next) {
		//neu tim thay data trung voi k->data dang duyet
		if (k->index == data) {
			//gan con tro next cua node p bang con tro next cua node k
			p->next = k->next;
			//xoa di node k
			delete k;
			//ket thuc ham
			return;
		}
		//gan node p bang node k de node p luon la node dung truoc node k
		p = k;
	}
}
void DeleteMaSanPham(LinkedList& ds, string data)
{
	//tao node p de luu tru phan tu truoc node k can xoa
	Good* p = new Good;
	//neu data dau vao bang voi pHead->data thi xoa dau
	if (ds.lhead->mahang == data) {
		//goi ham xoa dau
		DeleteHead(ds);
		//ket thuc ham
		return;
	}
	//neu data bang voi pTail->data thi xoa cuoi
	if (ds.ltail->mahang == data) {
		//goi ham xoa cuoi
		DeleteEnd(ds);
		//ket thuc ham
		return;
	}
	//duyet qua cac phan tu co trong danh sach
	for (Good* k = ds.lhead; k != NULL; k = k->next) {
		//neu tim thay data trung voi k->data dang duyet
		if (k->mahang == data) {
			//gan con tro next cua node p bang con tro next cua node k
			p->next = k->next;
			//xoa di node k
			delete k;
			//ket thuc ham
			return;
		}
		//gan node p bang node k de node p luon la node dung truoc node k
		p = k;
	}
}
void LoadData(LinkedList& l, string addressdata)
{
	int _index;
	string _mahang;
	string _tenhang;
	int _giaban;
	string _noisx;
	string _ngaynhapkho;
	string _mausac;
	int _soluong;


	ifstream read;
	read.open(addressdata);
	while (!read.eof())
	{
		read >> _index;
		if (_index == -1) return;
		read >> _mahang;
		read.ignore();
		getline(read, _tenhang);

		read >> _giaban;
		read.ignore();
		getline(read, _noisx);
		read >> _ngaynhapkho;
		read >> _mausac;
		read >> _soluong;



		//Creat new Node
		Good* tmp = CreateGood(_index, _mahang, _tenhang, _noisx, _giaban, _ngaynhapkho, _mausac, _soluong);
		//Insert End LinkedList
		InsertEnd(l, tmp);

	}
	read.close();
}
void WriteData(LinkedList l, string addressdata)
{
	ofstream write("ThongTinDatHang.txt");
	while (l.lhead != NULL)
	{
		write << l.lhead->index<<endl;
		write << l.lhead->mahang << endl;
		write << l.lhead->tenhang << endl;
		write << l.lhead->giaban << endl;
		write << l.lhead->noisx << endl;
		write << l.lhead->ngaynhapkho << endl;
		write << l.lhead->mausac << endl;
		write << l.lhead->soluong << endl;
		l.lhead = l.lhead->next;
	}
	write << -1;
	write.close();
}
void ResetLinkedList(LinkedList& l)
{
	while (l.lhead != NULL)
	{
		DeleteHead(l);
	}
}
bool Delete_Amount(LinkedList& l, int indexitem, int sl)
{
	Good* tmp = ReturnGoodIndex(l, indexitem);
	if (tmp->soluong > 0)
	{
		tmp->soluong += sl;
		return true;
	}
	else //<=0 thì ko
	{
		return false;
	}

}
bool Add_Amount(LinkedList& l, int indexitem, int sl, Good* g)
{
	//Kiem tra xem da co trong gio chua
	Good* tmp = l.lhead;
	while (tmp != NULL)
	{
		if (tmp->index == indexitem - 1)
		{
			tmp->soluong += sl;
			return true;
		}
		tmp = tmp->next;
	}
	Good* Gnew = CreateGood(g->index, g->mahang, g->tenhang, g->noisx, g->giaban, g->ngaynhapkho, g->mausac, sl);
	InsertEnd(l, Gnew);
	return true;
}
bool Add_Amount_Goods_Buy(LinkedList& l, int indexitem, int sl)
{
	Good* tmp = l.lhead;
	while (tmp != NULL)
	{
		if (tmp->index == indexitem)
		{
			tmp->soluong += sl;
			return true;
		}
		else
			tmp = tmp->next;
	}
	return false;
}
bool Delete_Amount_Goods_Buy(LinkedList& l, int indexitem, int sl)
{
	Good* tmp = l.lhead;
	while (tmp != NULL)
	{
		if (tmp->index == indexitem)
		{
			tmp->soluong += sl;
			return true;
		}
	}
	return false;
}