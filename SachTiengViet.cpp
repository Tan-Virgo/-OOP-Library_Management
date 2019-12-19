#include "SachTiengViet.h"

// ham tao khong doi so
SachTiengViet::SachTiengViet()
{
	MaSach = "";
	TenSach = "";
	TacGia = "";
	NhaXuatBan = "";
	GiaSach = 0;
}

// ham tao co doi so
SachTiengViet::SachTiengViet(string id, string name, string author, string producer, float price)
{
	MaSach = id;
	TenSach = name;
	TacGia = author;
	NhaXuatBan = producer;
	if (price < 0)
		throw "Sai gia sach!";
	GiaSach = price;
}

SachTiengViet::SachTiengViet(string id, string name, string author, float price)
{
	MaSach = id;
	TenSach = name;
	TacGia = author;
	if (price < 0)
		throw "Sai gia sach!";
	GiaSach = price;
}

SachTiengViet::SachTiengViet(string name, string author, float price)
{
	TenSach = name;
	TacGia = author;
	if (price < 0)
		throw "Sai gia sach!";
	GiaSach = price;
}

SachTiengViet::SachTiengViet(string id, string name)
{
	MaSach = id;
	TenSach = name;
}

// ham tao sao chep
SachTiengViet::SachTiengViet(const SachTiengViet& other)
{
	MaSach = other.MaSach;
	TenSach = other.TenSach;
	TacGia = other.TacGia;
	NhaXuatBan = other.NhaXuatBan;
	GiaSach = other.GiaSach;
}

// ham huy
SachTiengViet::~SachTiengViet()
{
	return;
}

// ham getter, setter
string SachTiengViet::layMaSach()
{
	return MaSach;
}

string SachTiengViet::layTenSach()
{
	return TenSach;
}

string SachTiengViet::layTacGia()
{
	return TacGia;
}

string SachTiengViet::layNhaXuatBan()
{
	return NhaXuatBan;
}

float SachTiengViet::layGiaSach()
{
	return GiaSach;
}

void SachTiengViet::ganMaSach(string id)
{
	MaSach = id;
}

void SachTiengViet::ganTenSach(string name)
{
	TenSach = name;
}

void SachTiengViet::ganTacGia(string author)
{
	TacGia = author;
}

void SachTiengViet::ganNhaXuatBan(string producer)
{
	NhaXuatBan = producer;
}

void SachTiengViet::ganGiaSach(float price)
{
	if (price >= 0)
		GiaSach = price;
}


// ham nhap, xuat
void SachTiengViet::Nhap()
{
	cin.ignore();
	cout << "\nNhap ma sach: ";
	getline(cin, MaSach);
	cout << "Nhap ten sach: ";
	getline(cin, TenSach);
	cout << "Nhap ten tac gia: ";
	getline(cin, TacGia);
	cout << "Nhap ten nha xuat ban: ";
	getline(cin, NhaXuatBan);
	while (1)
	{
		cout << "Nhap gia sach (VND): ";
		cin >> GiaSach;
		if (GiaSach < 0)
			cout << " <!> Nhap sai. Nhap lai gia sach" << endl;
		else
			break;
	}
}

void SachTiengViet::Xuat(ofstream& out)
{
	out << MaSach << endl;
	out << TenSach << endl;
	out << TacGia << endl;
	out << NhaXuatBan << endl;
	out << GiaSach << endl;
}

// xuat co thong tin ro rang, su dung de IN PHIEU MUON, TRA
void SachTiengViet::XuatDayDu(ofstream& out)
{
	out << "     Ma sach:                 " << MaSach << endl;
	out << "     Ten sach:                " << TenSach << endl;
	out << "     Tac gia:                 " << TacGia << endl;
	out << "     Nha xuat ban:            " << NhaXuatBan << endl;
	out << "     Gia sach:                " << GiaSach / 1000 << " nghin VND" << endl;
}

// Doc sach Tieng Viet tu file
SachTiengViet& SachTiengViet::DocSach(ifstream& DocSach)
{
	string s1, s2, s3, s4;

	// Doc ma sach
	DocSach.get();
	getline(DocSach, s1);
	MaSach = s1;

	// Doc ten sach
	getline(DocSach, s2);
	TenSach = s2;

	// Doc tac gia
	getline(DocSach, s3);
	TacGia = s3;

	// Doc nha xuat ban
	getline(DocSach, s4);
	NhaXuatBan = s4;

	// doc gia sach
	float p;
	DocSach >> p;
	GiaSach = p;

	return *this;
}