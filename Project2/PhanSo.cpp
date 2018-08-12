#include <iostream>
#include <conio.h>
using namespace std;

struct PhanSo
{
	int TuSo;
	int MauSo;
};

int UCLN(PhanSo a)
{
	int i;
	if (a.TuSo < a.MauSo) i = a.TuSo;
	else i = a.MauSo;
	if (i < 0) i = abs(i);
	for (; ; i--)
		if (a.TuSo % i == 0 && a.MauSo % i == 0)
			return i;
}

void Nhap(PhanSo &a)
{
	cout << "Nhap tu: ";
	cin >> a.TuSo;
	cout << "Nhap mau: ";
	cin >> a.MauSo;
	while (a.MauSo == 0)
	{
		cout << "Nhap sai. Nhap lai (mau != 0): ";
		cin >> a.MauSo;
	}
}

void RutGon(PhanSo a)
{
	PhanSo n = a;
	if (n.MauSo < 0)
	{
		n.TuSo *= -1;
		n.MauSo *= -1;
	}
	if (n.TuSo == 0) cout << "0";
	else if ((n.TuSo % 2 == 0 && n.MauSo % 2 == 0) || (n.TuSo % 3 == 0 && n.MauSo % 3 == 0) || (n.TuSo % 5 == 0 && n.MauSo % 5 == 0))
	{
		int i = UCLN(n);
		n.TuSo /= i;
		n.MauSo /= i;
		if (n.MauSo == 1)
			cout << n.TuSo;
		else cout << n.TuSo << "/" << n.MauSo;
	}
	else if (n.MauSo == 1)
		cout << n.TuSo;
	else cout << n.TuSo << "/" << n.MauSo;
}

void Cong(PhanSo a, PhanSo b)
{
	PhanSo c;
	c.TuSo = a.TuSo * b.MauSo + b.TuSo * a.MauSo;
	c.MauSo = a.MauSo * b.MauSo;
	RutGon(c);
}

void Tru(PhanSo a, PhanSo b)
{
	PhanSo c;
	c.TuSo = a.TuSo * b.MauSo - b.TuSo * a.MauSo;
	c.MauSo = a.MauSo * b.MauSo;
	RutGon(c);
}

void Nhan(PhanSo a, PhanSo b)
{
	PhanSo c;
	c.TuSo = a.TuSo * b.TuSo;
	c.MauSo = a.MauSo * b.MauSo;
	RutGon(c);
}

void Chia(PhanSo a, PhanSo b)
{
	PhanSo c;
	c.TuSo = a.TuSo * b.MauSo;
	c.MauSo = a.MauSo * b.TuSo;
	RutGon(c);
}

void Menu()
{
	cout << "=== CHON PHEP TINH ===\n";
	cout << "1. Cong (+)\n";
	cout << "2. Tru \t(-)\n";
	cout << "3. Nhan (*)\n";
	cout << "4. Chia (/)\n";
}

void main()
{
	PhanSo a, b;
	int t;
	do {
		system("cls");
		cout << "PHAN SO THU 1\n";
		Nhap(a);
		cout << "\nPhan so 1: ";
		RutGon(a);
		cout << "\n\nPHAN SO THU 2\n";
		Nhap(b);
		cout << "\nPhan so 2: ";
		RutGon(b);
		cout << endl << endl;
		Menu();
		cout << "\nChon phep tinh: ";
		cin >> t;
		while (t < 1 || t > 4)
		{
			cout << "\nChon sai. Chon lai (1 -> 4): ";
			cin >> t;
		}
		switch (t)
		{
		case 1:
			cout << "\nKet qua: ";
			Cong(a, b);
			break;
		case 2:
			cout << "\nKet qua: ";
			Tru(a, b);
			break;
		case 3:
			cout << "\nKet qua: ";
			Nhan(a, b);
			break;
		case 4:
			cout << "\nKet qua: ";
			Chia(a, b);
			break;
		}
		_getch();
		cout << "\n\nNhan phim bat ky de tiep tuc hoac ESC de thoat.";
	} while (_getch() != 0x1b);
}