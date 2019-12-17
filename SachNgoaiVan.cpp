#include "SachNgoaiVan.h"

// ham getter, setter
	// Ma sach, ten sach, tac gia, nha xuat ban, gia sach da ke thua trong class SachTiengViet
string SachNgoaiVan::layISBN()
{
	return ISBN;
}

void SachNgoaiVan::ganISBN(string str)
{
	ISBN = str;
}

// ham nhap, xuat
void SachNgoaiVan::Nhap()
{
	SachTiengViet::Nhap();
	cin.ignore();
	cout << "Nhap ma so tieu chuan ISBN: ";
	getline(cin, ISBN);
}

void SachNgoaiVan::Xuat(ofstream& out)
{
	SachTiengViet::Xuat(out);
	out << ISBN << endl;
}

void SachNgoaiVan::XuatDayDu(ofstream& out)
{
	SachTiengViet::XuatDayDu(out);
	out << "     Ma so ISBN:              " << ISBN << endl;
}


// Doc sach Ngoai Van tu file
SachNgoaiVan SachNgoaiVan::DocSach(ifstream& DocSach) 
{
	string s1, s2, s3, s4, s;

	// Doc ma sach
	DocSach.get();
	getline(DocSach, s);
	MaSach = s;

	// Doc ten sach
	getline(DocSach, s1);
	TenSach = s1;

	// Doc tac gia
	getline(DocSach, s2);
	TacGia = s2;

	// Doc nha xuat ban
	getline(DocSach, s3);
	NhaXuatBan = s3;

	// doc gia sach
	float p;
	DocSach >> p;
	GiaSach = p;

	// Doc so ISBN
	DocSach.get();
	getline(DocSach, s4);
	ISBN = s4;
	
	return *this;
}