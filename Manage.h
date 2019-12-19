#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <time.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstring>

#include "DocGia.h"
#include "SachTiengViet.h"
#include "SachNgoaiVan.h"

class Manage
{
	vector<DocGia*> reader;
	vector<SachTiengViet*> book;

	// MANG DOC GIA
public:
	// ham lay so doc gia
	int laySoDocGia()
	{
		return reader.size();
	}

	// ham lay mang cac doc gia
	vector<DocGia*> layMangDocGia()
	{
		return reader;
	}

	// ham tra ve vi tri cua doc gia co MaDocGia la id trong mang
	int layViTriDocGia(string id)
	{
		for (int i = 0; i < reader.size(); i++)
		{
			if (reader[i]->layMaDocGia() == id)
				return i;
		}
		return -1;
	}

	// gan mang doc gia
	void ganMangDocGia(const vector<DocGia*>& other)
	{
		int size = other.size();
		for (int i = 0; i < size; i++)
		{
			reader.push_back(other[i]);
		}
	}

	// ham nhap, xuat
	void NhapMangDocGia();
	void XuatMangDocGia(ofstream& out);
	void XuatMangDocGiaDayDu(ofstream& out);

	// Them doc gia
	void ThemDocGia();

	// Xoa doc gia dua vao MaDocGia
	void XoaDocGia(string id);

	// Sua thong tin doc gia dua vao MaDocGia
	void SuaDocGia(string id);

	// tim doc gia co MaDocGia cho truoc
	DocGia* TimDocGia(string id);

	// MANG SACH
public:
	// ham lay so sach
	int laySoSach() { return book.size(); }

	// ham lay vi tri sach trong mang book
	int layViTriSach(string id)
	{
		for (int i = 0; i < book.size(); i++)
		{
			if (book[i]->layMaSach() == id)
				return i;
		}
		return -1; // khong tim thay vi tri
	}

	// ham lay mang cac loai sach
	vector<SachTiengViet*> layMangSach()
	{
		return book;
	}

	// Gan mang sach
	void ganMangSach(const vector<SachTiengViet*>& other)
	{
		int size = other.size();
		for (int i = 0; i < size; i++)
		{
			book.push_back(other[i]);
		}
	}

	// ham nhap, xuat
	void NhapMangSach();
	void XuatMangSach(ofstream& out);
	void XuatMangSachDayDu(ofstream& out);

	// ham them sach
	void ThemSach();

	// ham xoa sach
	void XoaSach(string id);

	// ham sua thong tin sach
	void SuaSach(string id);

	// ham tim kiem sach
	SachTiengViet* TimSach(string id);

	// Kiem tra sach co trong thu vien hay khong
	bool KTid_book(string id)
	{
		if (layViTriSach(id) == -1)
			return false;
		else
			return true;
	}

public:
	// tinh tien phat cua doc gia co MaDocGia la id
	float TienPhat(DocGia *p);

	// in phieu muon sach cua tat ca cac doc gia
	void PhieuMuon(ofstream& out);

	// in phieu muon sach cua doc gia co MaDocGia
	void PhieuMuon(ofstream& out, string ID);

	// in phieu tra sach cua tat ca cac doc gia
	void PhieuTra(ofstream& out);

	// in phieu tra sach cua doc gia co MaDocGia
	void PhieuTra(ofstream& out, string ID);

	// danh sach doc gia qua han muon sach
	void QuaHan(ofstream& out);

	
	// Doc mang sach tu file
	vector<SachTiengViet*> DocMangSachTuFile();

	// Doc mang doc gia tu file
	vector<DocGia*> DocMangDocGiaTuFile();

	// Kiem tra da co du lieu cho mang sach chua
	bool KTMangSach();


	// kiem tra da co mang doc gia chua
	bool KTMangDocGia();


public:
	// ham tao
	Manage() {};
	// ham huy
	~Manage()
	{
		reader.clear();
		book.clear();
	}
};

