#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>

class SachTiengViet
{
protected:
	string MaSach; 
	string TenSach;
	string TacGia;
	string NhaXuatBan;
	float GiaSach;
public:
	// ham getter, setter
	string layMaSach();
	string layTenSach();
	string layTacGia();
	string layNhaXuatBan();
	float layGiaSach();
	void ganMaSach(string id);
	void ganTenSach(string name);
	void ganTacGia(string author);
	void ganNhaXuatBan(string producer);
	void ganGiaSach(float price);
	
	// kiem tra la sach tieng viet
	virtual bool KTSachTiengViet()
	{
		return true;
	}

	// ham nhap, xuat
	virtual void Nhap();
	virtual void Xuat(ofstream& out);
	
	// xuat co thong tin ro rang, su dung de IN PHIEU MUON, TRA
	virtual void XuatDayDu(ofstream& out);

	// Doc sach Tieng Viet tu file
	SachTiengViet DocSach(ifstream& DocSach);


public:
	// ham tao khong doi so
	SachTiengViet() {};
	// ham tao co doi so
	SachTiengViet(string id, string name, string author, string producer, float price);
	SachTiengViet(string id, string name, string author, float price);
	SachTiengViet(string name, string author, float price);
	SachTiengViet(string id, string name);
	// ham tao sao chep
	SachTiengViet(const SachTiengViet& other);
	// ham huy
	virtual ~SachTiengViet();


};

