#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>

#include "SachTiengViet.h"

class SachNgoaiVan : public SachTiengViet
{
	string ISBN;
public:
	// ham getter, setter
	// Ma sach, ten sach, tac gia, nha xuat ban, gia sach da ke thua trong class SachTiengViet
	string layISBN();
	void ganISBN(string str);

	// kiem tra la sach tieng viet
	bool KTSachTiengViet()
	{
		return false;
	}

	// ham nhap, xuat
	void Nhap();
	void Xuat(ofstream& out);

	// xuat co thong tin ro rang, su dung de IN PHIEU MUON, TRA
	void XuatDayDu(ofstream& out);


	// Doc sach Ngoai Van tu file
	SachNgoaiVan& DocSach(ifstream& DocSach);

public:
	// ham tao khong doi so
	SachNgoaiVan() : SachTiengViet()
	{
		ISBN = "";
	}

	// ham tao co doi so
	SachNgoaiVan(string id, string name, string author, string producer, int price, string str)
		: SachTiengViet(id, name, author, producer, price)
	{
		ISBN = str;
	}

	SachNgoaiVan(string id, string name, string author, int price, string str)
		: SachTiengViet(id, name, author, price)
	{
		ISBN = str;
	}

	SachNgoaiVan(string name, string author, int price)
		: SachTiengViet(name, author, price) {};

	SachNgoaiVan(string id, string name) : SachTiengViet(id, name) {};
	
	// ham tao sao chep
	SachNgoaiVan(const SachNgoaiVan& other) :SachTiengViet(other)
	{
		ISBN = other.ISBN;
	}
	// ham huy
	~SachNgoaiVan()
	{
		return;
	}
};

