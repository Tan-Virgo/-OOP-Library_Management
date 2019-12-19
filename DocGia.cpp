#include "DocGia.h"

// ham tao khong doi so
DocGia::DocGia()
{
	MaDocGia = "";
	TenDocGia = "";
	Ngay = 1;
	Thang = 1;
	Nam = 2000;
	SoSachMuon = 0;
}

// ham tao co doi so
DocGia::DocGia(string id, string name, int day, int month, int year, int num)
{
	MaDocGia = id;
	TenDocGia = name;
	if (KTdate(day, month, year) == false)
		throw "Sai ngay thang nam muon sach";
	Ngay = day;
	Thang = month;
	Nam = year;
	if (num <= 0)
		throw "Sai so sach muon";
	SoSachMuon = num;
}

DocGia::DocGia(string id, string name, int num)
{
	MaDocGia = id;
	TenDocGia = name;
	SoSachMuon = num;
}

DocGia::DocGia(string id, int num)
{
	MaDocGia = id;
	if (num <= 0)
		throw "Sai so sach muon";
	SoSachMuon = num;
}

// ham tao sao chep
DocGia::DocGia(const DocGia& other)
{
	MaDocGia = other.MaDocGia;
	TenDocGia = other.TenDocGia;
	Ngay = other.Ngay;
	Thang = other.Thang;
	Nam = other.Nam;
	SoSachMuon = other.SoSachMuon;
}

// ham huy
DocGia::~DocGia()
{
	return;
}


// ham getter, setter
string DocGia::layMaDocGia()
{
	return MaDocGia;
}

string DocGia::layTenDocGia()
{
	return TenDocGia;
}

int DocGia::layNgay() const
{
	return Ngay;
}

int DocGia::layThang() const
{
	return Thang;
}

int DocGia::layNam() const
{
	return Nam;
}

int DocGia::laySoSachMuon() const
{
	return SoSachMuon;
}

string DocGia::layMaSachMuon(int vt) const
{
	return MangSachMuon[vt];
}

void DocGia::ganMaDocGia(string id)
{
	MaDocGia = id;
}

void DocGia::ganTenDocGia(string name)
{
	TenDocGia = name;
}

void DocGia::ganNgay(int day)
{
	if (day < 1 || day > 31)
		throw "Sai ngay muon sach";
	Ngay = day;
}

void DocGia::ganThang(int month)
{
	if (month < 1 || month > 12)
		throw "Sai thang muon sach";
	Thang = month;
}

void DocGia::ganNam(int year)
{
	if (year < 1900)
		throw "Sai nam muon sach";
	Nam = year;
}

void DocGia::ganSoSachMuon(int num)
{
	if (num <= 0)
		throw "Sai so sach muon";
	SoSachMuon = num;
}

void DocGia::ganMaSachMuon(int vt, string id)
{
	MangSachMuon[vt] = id;
}

// ham kiem tra tinh hop le cua ngay thang nam nhap vao
bool DocGia::KTdate(int ngay, int thang, int nam)
{
	switch (thang)
	{
	case 1: case 3: case 5: case 7: case 8: case 10:  case 12:
		if (ngay > 0 && ngay <= 31)
			return true;
		else
			return false;

	case 4: case 6: case 9: case 11:
		if (ngay <= 30 && ngay > 0)
			return true;
		else
			return false;

	case 2:
		if (ngay <= 28 && ngay > 0)
			return true;
		else
			return false;

	default:
		return false;
	}
}

// ham tinh so ngay het han
//Rata Die day one is 0001 - 01 - 01 (Lay moc la ngay 1 thang 1 nam 1)
int DocGia::Rdn(int day, int month, int year)
{
	if (month < 3) 
	{
		year--;
		month += 12;
	}
	return 365 * year + year / 4 - year / 100 + year / 400 + (153 * month - 457) / 5 + day - 306;
}

int DocGia::KhoangThoiGian(int day, int month, int year)
{
	// lay thoi gian cua he thong
	time_t now = time(0);
	tm local;
	localtime_s(&local, &now);
	int daynow = local.tm_mday;
	int monthnow = local.tm_mon + 1;
	int yearnow = local.tm_year + 1900;

	int a = Rdn(day, month, year);
	int b = Rdn(daynow, monthnow, yearnow);

	return (b - a);
}

// ham nhap, xuat
void DocGia::Nhap()
{
	cout << "Nhap ma doc gia: ";
	getline(cin, MaDocGia);
	cout << "Nhap ten doc gia: ";
	getline(cin, TenDocGia);
	cout << "Nhap ngay, thang, nam muon sach: " << endl;
	while (1)
	{
		cout << "  Ngay: ";
		cin >> Ngay;
		cout << "  Thang: ";
		cin >> Thang;
		cout << "  Nam: ";
		cin >> Nam;
		if (KTdate(Ngay, Thang, Nam) == false)
			cout << " <!> Nhap sai ngay, thang, nam. Nhap lai!" << endl;
		else
			break;
	}
	while (1)
	{
		cout << "Nhap so sach muon: ";
		cin >> SoSachMuon;
		if (SoSachMuon <= 0)
			cout << " <!> So sach muon phai lon hon 0. Nhap lai" << endl;
		else
			break;
	}
	
}

void DocGia::Xuat(ofstream& out)
{
	out << MaDocGia << endl;
	out << TenDocGia << endl;
	out << Ngay << " " << Thang << " " << Nam << endl;
	out << SoSachMuon << endl;
	for (int i = 0; i < SoSachMuon; i++)
	{
		out << MangSachMuon[i] << endl;
	}
}

void DocGia::XuatDayDu(ofstream& out)
{
	out << "     Ma doc gia:              " << MaDocGia << endl;
	out << "     Ten tac gia:             " << TenDocGia << endl;
	out << "     Ngay muon sach:          " << Ngay << "/" << Thang << "/" << Nam << endl;
	out << "     So sach muon:            " << SoSachMuon << endl;
	for (int i = 0; i < SoSachMuon; i++)
	{
		out << "       + Ma sach muon thu " << i + 1 << ":  " << MangSachMuon[i] << endl;
	}
}



// Doc doc gia tu file
DocGia& DocGia::DocDocGia(ifstream& DocDocGia)
{
	string s1, s2;

	// doc ma doc gia
	getline(DocDocGia, s1);
	MaDocGia = s1;

	// doc ten doc gia
	getline(DocDocGia, s2);
	TenDocGia = s2;

	// doc ngay muon sach
	int day, month, year;
	DocDocGia >> day;
	Ngay = day;
	DocDocGia >> month;
	Thang = month;
	DocDocGia >> year;
	Nam = year;

	// doc so sach muon
	int num;
	DocDocGia >> num;
	SoSachMuon = num;

	DocDocGia.get();
	for (int i = 0; i < num; i++)
	{
		string s3;
		getline(DocDocGia, s3);
		ganMaSachMuon(i, s3);
	}

	return *this;
}
