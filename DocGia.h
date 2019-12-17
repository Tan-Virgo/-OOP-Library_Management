#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <time.h>
#include <fstream>
#include <sstream>
#include <cstring>

#include "SachTiengViet.h"
#include "SachNgoaiVan.h"


class DocGia//: public Sach
{
protected:
	string MaDocGia;
	string TenDocGia;
	// ngay, thang, nam muon sach
	int Ngay;
	int Thang;
	int Nam;
	string MaSachMuon;

public:
	// ham getter, setter
	string layMaDocGia();
	string layTenDocGia();
	int layNgay() const;
	int layThang() const;
	int layNam() const;
	string layMaSachMuon() const;
	void ganMaDocGia(string id);
	void ganTenDocGia(string name);
	void ganNgay(int day);
	void ganThang(int month);
	void ganNam(int year);
	void ganMaSachMuon(string id_book);


	// ham kiem tra tinh hop le cua ngay thang nam nhap vao
	bool KTdate(int ngay, int thang, int nam);

	// ham tinh so ngay het han
	//Rata Die day one is 0001 - 01 - 01 (Lay moc la ngay 1 thang 1 nam 1)
	int Rdn(int day, int month, int year);
	int KhoangThoiGian(int day, int month, int year);

	// ham nhap, xuat
	void Nhap();
	void Xuat(ofstream& out);
	void XuatDayDu(ofstream& out);

	// Doc doc gia tu file
	DocGia DocDocGia(ifstream& DocDocGia);

public:
	// ham tao khong doi so
	DocGia();
	// ham tao co doi so
	DocGia(string id, string name, int day, int month, int year, string id_book);
	DocGia(string id, string name, string id_book);
	DocGia(string id, string id_book);
	// ham tao sao chep
	DocGia(const DocGia& other);
	// ham huy
	~DocGia();

};
