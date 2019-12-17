#include "Manage.h"


// ham nhap, xuat sach
void Manage::NhapMangSach()
{
	int key;
	cout << "_____ Nhap thong tin cho cac loai sach trong thu vien _______" << endl;
	cout << "Qui uoc nhap: 0 - Ket thuc nhap; 1 - Sach Tieng Viet; 2 - Sach Ngoai Van" << endl;
	while (1)
	{
		cout << "\n -> Nhap loai sach: ";
		cin >> key;
		SachTiengViet* p;
		if (key == 0)
			break;
		else if (key == 1)
		{
			p = new SachTiengViet;
			p->Nhap();
			book.push_back(p);
		}
		else if (key == 2)
		{
			p = new SachNgoaiVan;
			p->Nhap();
			book.push_back(p);
		}
		else
			cout << " <!> Nhap sai thao tac. Nhap lai " << endl;
	}
}

void Manage::XuatMangSach(ofstream& out)
{
	out << book.size() << endl;
	for (int i = 0; i < book.size(); i++)
	{
		if (book[i]->KTSachTiengViet() == true)
			out << 1 << endl;
		else
			out << 2 << endl;
		book[i]->Xuat(out);
	}
}

void Manage::XuatMangSachDayDu(ofstream& out)
{
	// lay thoi gian cua he thong
	time_t now = time(0);
	tm local;
	localtime_s(&local, &now);
	int daynow = local.tm_mday;
	int monthnow = local.tm_mon + 1;
	int yearnow = local.tm_year + 1900;

	if (book.size() == 0)
		out << " <!> Chua co danh sach cac sach trong thu vien";
	else
	{
		out << "      _______________ DANH SACH CAC SACH TRONG THU VIEN __________________" << endl;
		out << "  " << daynow << "/" << monthnow << "/" << yearnow << endl << endl;
		out << "  Co tong cong " << book.size() << " quyen sach" << endl << endl;
		for (int i = 0; i < book.size(); i++)
		{
			out << " + Quyen thu " << i + 1 << " : " << endl;
			if (book[i]->KTSachTiengViet() == true)
				out << "     Loai sach:               Sach Tieng Viet" << endl;
			else
				out << "     Loai sach:               Sach Ngoai van" << endl;
			book[i]->XuatDayDu(out);
			out << "-----------------------------------------------------------------------" << endl;
		}
	}
}

// ham them sach
void Manage::ThemSach()
{
	cout << "Nhap thong tin sach can them: " << endl;
	cout << "Qui uoc loai sach: 1 - Sach Tieng Viet; 2 - Sach Ngoai Van" << endl;

	SachTiengViet* p;
	while (1)
	{
		int key;
		cout << "\n -> Nhap loai sach: ";
		cin >> key;
		if (key == 1)
		{
			p = new SachTiengViet();
			break;
		}
		else if (key == 2)
		{
			p = new SachNgoaiVan();
			break;
		}
		else
			cout << " Nhap sai loai sach. Nhap lai!" << endl;
	}
	p->Nhap();
	book.push_back(p);
}

// ham xoa sach
void Manage::XoaSach(string id)
{
	if (TimSach(id) == NULL)
	{
		cout << " <!> Khong co quyen sach nao co MaSach nay trong thu vien" << endl;
	}
	else
	{
		int vitri = layViTriSach(id);
		for (int i = vitri; i < book.size() - 1; i++)
		{
			book[i] = book[i + 1];
		}
		book.pop_back();
		cout << "   -> 100% - Da xoa thanh cong." << endl;
	}

}


// ham sua thong tin sach
void Manage::SuaSach(string id)
{
	if (TimSach(id) == NULL)
	{
		cout << " <!> Khong co quyen sach nao co MaSach nay trong thu vien" << endl;
	}
	else
	{
		int vitri = layViTriSach(id);
		cout << "Nhap thong tin sach can sua" << endl;
		cout << "Qui uoc loai sach: 1 - Sach Tieng Viet; 2 - Sach Ngoai Van" << endl;

		SachTiengViet* p;
		while (1)
		{
			int key;
			cout << " -> Nhap loai sach: ";
			cin >> key;
			if (key == 1)
			{
				p = new SachTiengViet();
				break;
			}
			else if (key == 2)
			{
				p = new SachNgoaiVan();
				break;
			}
			else
				cout << " Nhap sai loai sach. Nhap lai!" << endl;
		}
		p->Nhap();
		book[vitri] = p;
		cout << "   -> 100% - Da sua thanh cong." << endl;
	}
}

// ham tim kiem sach
SachTiengViet* Manage::TimSach(string id)
{
	for (int i = 0; i < book.size(); i++)
	{
		if (book[i]->layMaSach() == id)
		{
			return book[i];
		}
	}

	return NULL;
}






// ham nhap, xuat doc gia
void Manage::NhapMangDocGia()
{
	cout << "_______ Nhap thong tin cho cac doc gia _________" << endl;
	cout << "Qui uoc nhap: 0 - Ket thuc nhap; 1 - Nhap doc gia moi" << endl;
	while (1)
	{
		int key;
		DocGia* p;
		cout << "\n Nhap lua chon: ";
		cin >> key;
		if (key == 0)
			break;
		else if (key == 1)
		{
			p = new DocGia();
			p->Nhap();
			if (KTid_book(p->layMaSachMuon()) == false)
			{
				cout << "  <!> Ma sach nay khong co trong thu vien. Nhap lai." << endl;
			}
			else
				reader.push_back(p);
		}
		else
		{
			cout << " <!> Nhap sai thao tac. Nhap lai. " << endl;
		}
	}
}

void Manage::XuatMangDocGia(ofstream& out)
{
	out << reader.size() << endl;
	for (int i = 0; i < reader.size(); i++)
	{
		reader[i]->Xuat(out);
	}
}

void Manage::XuatMangDocGiaDayDu(ofstream& out)
{
	// lay thoi gian cua he thong
	time_t now = time(0);
	tm local;
	localtime_s(&local, &now);
	int daynow = local.tm_mday;
	int monthnow = local.tm_mon + 1;
	int yearnow = local.tm_year + 1900;

	if (reader.size() == 0)
		out << " <!> Chua co danh sach cac doc gia";
	else
	{
		out << "      _________ DANH SACH CAC DOC GIA MUON SACH TRONG THU VIEN ___________" << endl;
		out << "  " << daynow << "/" << monthnow << "/" << yearnow << endl << endl;
		out << "  Co tong cong " << reader.size() << " doc gia muon sach" << endl << endl;
		for (int i = 0; i < reader.size(); i++)
		{
			out << " + Quyen thu " << i + 1 << " : " << endl;
			reader[i]->XuatDayDu(out);
			out << "\n        === Thong tin sach da muon ===" << endl;
			SachTiengViet* p = TimSach(reader[i]->layMaSachMuon());
			if (p->KTSachTiengViet() == true)
				out << "     Loai sach muon:          Sach Tieng Viet" << endl;
			else
				out << "     Loai sach muon:          Sach Ngoai van" << endl;
			p->XuatDayDu(out);
			out << "-----------------------------------------------------------------------" << endl;
		}
	}
}

// Them doc gia
void Manage::ThemDocGia()
{
	while (1)
	{
		cout << "Nhap thong tin doc gia can them: " << endl;
		DocGia* p;
		p = new DocGia();
		p->Nhap();
		if (KTid_book(p->layMaSachMuon()) == false)
		{
			cout << "  <!> Ma sach nay khong co trong thu vien. Nhap lai." << endl;
		}
		else
		{
			reader.push_back(p);
			break;
		}
	}
}

// Xoa doc gia dua vao MaDocGia
void Manage::XoaDocGia(string id)
{
	if (TimDocGia(id) == NULL)
	{
		cout << " <!> Khong co doc gia nay trong danh sach" << endl;
	}
	else
	{
		int vitri = layViTriDocGia(id);
		for (int i = vitri; i < reader.size() - 1; i++)
		{
			reader[i] = reader[i + 1];
		}
		reader.pop_back();
		cout << "   -> 100% - Da xoa thanh cong." << endl;
	}
}

// Sua thong tin doc gia dua vao MaDocGia
void Manage::SuaDocGia(string id)
{
	if (TimDocGia(id) == NULL)
	{
		cout << " <!> Khong co doc gia nay trong danh sach" << endl;
	}
	else
	{
		while (1)
		{
			int vitri = layViTriDocGia(id);
			DocGia* p = new DocGia();
			cout << " Nhap thong tin doc gia can sua: " << endl;
			p->Nhap();
			if (KTid_book(p->layMaSachMuon()) == false)
			{
				cout << "  <!> Ma sach nay khong co trong thu vien. Nhap lai." << endl;
			}
			else
			{
				reader[vitri] = p;
				break;
			}
		}
		cout << "   -> 100% - Da sua thanh cong." << endl;
		
	}
}

// tim doc gia co MaDocGia cho truoc
DocGia* Manage::TimDocGia(string id)
{
	for (int i = 0; i < reader.size(); i++)
	{
		if (reader[i]->layMaDocGia() == id)
		{
			return reader[i];
		}
	}
	return NULL;
}



// tinh tien phat cua doc gia co MaDocGia la id
float Manage::TienPhat(DocGia* p)
{
	int soNgay = p->KhoangThoiGian(p->layNgay(), p->layThang(), p->layNam());
	if (TimSach(p->layMaSachMuon())->KTSachTiengViet() == true)
	{
		if (soNgay > 7)
			return ((soNgay - 7) * 10000);
		else return 0;
	}
	else
	{
		if (soNgay > 7)
			return ((soNgay - 7) * 20000);
		else return 0;
	}
}


// in phieu muon sach cua tat ca cac doc gia
void Manage::PhieuMuon(ofstream& out)
{
	// lay thoi gian cua he thong
	time_t now = time(0);
	tm local;
	localtime_s(&local, &now);
	int hournow = local.tm_hour;
	int minutenow = local.tm_min;
	int daynow = local.tm_mday;
	int monthnow = local.tm_mon + 1;
	int yearnow = local.tm_year + 1900;

	if (reader.size() == 0)
	{
		out << " <!> Chua co danh sach doc gia de in phieu nay";
		cout << " <!> Chua co danh sach doc gia de in phieu nay";
	}
	else
	{
		for (int i = 0; i < reader.size(); i++)
		{
			out << "\n ____________________ PHIEU MUON SACH ____________________ " << endl << endl;
			out << "Thoi gian in phieu: " << daynow << "/" << monthnow << "/" << yearnow << "  " << hournow << ":" << minutenow << endl << endl;
			//reader[i]->Xuat(out);
			out << "     Ma doc gia:              " << reader[i]->layMaDocGia() << endl;
			out << "     Ten doc gia:             " << reader[i]->layTenDocGia() << endl;
			out << "     Ngay muon sach:          " << reader[i]->layNgay() << "/" << reader[i]->layThang() << "/" << reader[i]->layNam() << endl;
			out << "\n               -----Thong tin sach da muon----- " << endl;
			SachTiengViet* p = TimSach(reader[i]->layMaSachMuon());
			if (p->KTSachTiengViet() == true)
				out << "     Loai sach muon:          Sach Tieng Viet" << endl;
			else
				out << "     Loai sach muon:          Sach Ngoai van" << endl;
			p->XuatDayDu(out);
			out << "\n                                        Quan ly thu vien" << endl;
			out << "____________________________________________________________\n" << endl << endl;
		}
		cout << "   -> 100% - Da xuat ra file thanh cong." << endl;
	}
}

// in phieu muon sach cua doc gia co MaDocGia
void Manage::PhieuMuon(ofstream& out, string ID)
{
	// lay thoi gian cua he thong
	time_t now = time(0);
	tm local;
	localtime_s(&local, &now);
	int hournow = local.tm_hour;
	int minutenow = local.tm_min;
	int daynow = local.tm_mday;
	int monthnow = local.tm_mon + 1;
	int yearnow = local.tm_year + 1900;

	DocGia* p = TimDocGia(ID);
	if (p == NULL)
	{
		out << " <!> Khong co doc gia co MaDocGia trong danh sach" << endl;
		cout << " <!> Khong co doc gia co MaDocGia trong danh sach" << endl;
	}
	else
	{
		out << "\n ____________________ PHIEU MUON SACH ____________________ " << endl << endl;
		out << "Thoi gian in phieu: " << daynow << "/" << monthnow << "/" << yearnow << "  " << hournow << ":" << minutenow << endl << endl;
		//reader[i]->Xuat(out);
		out << "     Ma doc gia:              " << p->layMaDocGia() << endl;
		out << "     Ten doc gia:             " << p->layTenDocGia() << endl;
		out << "     Ngay muon sach:          " << p->layNgay() << "/" << p->layThang() << "/" << p->layNam() << endl;
		out << "\n               -----Thong tin sach da muon----- " << endl;
		SachTiengViet* q = TimSach(p->layMaSachMuon());
		if (q->KTSachTiengViet() == true)
			out << "     Loai sach muon:          Sach Tieng Viet" << endl;
		else
			out << "     Loai sach muon:          Sach Ngoai van" << endl;
		q->XuatDayDu(out);
		out << "\n                                        Quan ly thu vien" << endl;
		out << "____________________________________________________________\n" << endl << endl;
		
		cout << "   -> 100% - Da xuat ra file thanh cong." << endl;
	}
}

// in phieu tra sach cua tat ca cac doc gia
void Manage::PhieuTra(ofstream& out)
{
	// lay thoi gian cua he thong
	time_t now = time(0);
	tm local;
	localtime_s(&local, &now);
	int hournow = local.tm_hour;
	int minutenow = local.tm_min;
	int daynow = local.tm_mday;
	int monthnow = local.tm_mon + 1;
	int yearnow = local.tm_year + 1900;

	if (reader.size() == 0)
	{
		out << " <!> Chua co danh sach doc gia de in phieu nay";
		cout << " <!> Chua co danh sach doc gia de in phieu nay";
	}
	else
	{
		for (int i = 0; i < reader.size(); i++)
		{
			out << "\n ____________________ PHIEU TRA SACH _____________________ " << endl << endl;
			out << "Thoi gian in phieu: " << daynow << "/" << monthnow << "/" << yearnow << "  " << hournow << ":" << minutenow << endl << endl;
			out << "     Ma doc gia:              " << reader[i]->layMaDocGia() << endl;
			out << "     Ten doc gia:             " << reader[i]->layTenDocGia() << endl;
			out << "     Ngay muon sach:          " << reader[i]->layNgay() << "/" << reader[i]->layThang() << "/" << reader[i]->layNam() << endl;
			out << "\n               -----Thong tin sach da muon----- " << endl;
			SachTiengViet* p = TimSach(reader[i]->layMaSachMuon());
			if (p->KTSachTiengViet() == true)
				out << "     Loai sach muon:          Sach Tieng Viet" << endl;
			else
				out << "     Loai sach muon:          Sach Ngoai van" << endl;
			p->XuatDayDu(out);
			out << "  -> Ngay tra: " << daynow << "/" << monthnow << "/" << yearnow << endl;
			out << "\n                                        Quan ly thu vien" << endl;
			out << "____________________________________________________________\n" << endl << endl;
		}
		cout << "   -> 100% - Da xuat ra file thanh cong." << endl;
	}
}

// in phieu tra sach cua doc gia co MaDocGia
void Manage::PhieuTra(ofstream& out, string ID)
{
	// lay thoi gian cua he thong
	time_t now = time(0);
	tm local;
	localtime_s(&local, &now);
	int hournow = local.tm_hour;
	int minutenow = local.tm_min;
	int daynow = local.tm_mday;
	int monthnow = local.tm_mon + 1;
	int yearnow = local.tm_year + 1900;

	DocGia* p = TimDocGia(ID);
	if (p == NULL)
	{
		out << " <!> Khong co doc gia co MaDocGia trong danh sach" << endl;
		cout << " <!> Khong co doc gia co MaDocGia trong danh sach" << endl;
	}
	else
	{
		out << "\n ____________________ PHIEU TRA SACH _____________________ " << endl << endl;
		out << "Thoi gian in phieu: " << daynow << "/" << monthnow << "/" << yearnow << "  " << hournow << ":" << minutenow << endl << endl;
		out << "     Ma doc gia:              " << p->layMaDocGia() << endl;
		out << "     Ten doc gia:             " << p->layTenDocGia() << endl;
		out << "     Ngay muon sach:          " << p->layNgay() << "/" << p->layThang() << "/" << p->layNam() << endl;
		out << "\n               -----Thong tin sach da muon----- " << endl;
		SachTiengViet* q = TimSach(p->layMaSachMuon());
		if (q->KTSachTiengViet() == true)
			out << "     Loai sach muon:          Sach Tieng Viet" << endl;
		else
			out << "     Loai sach muon:          Sach Ngoai van" << endl;
		q->XuatDayDu(out);
		out << "  -> Ngay tra: " << daynow << "/" << monthnow << "/" << yearnow << endl;
		out << "\n                                        Quan ly thu vien" << endl;
		out << "____________________________________________________________\n" << endl << endl;
		cout << "   -> 100% - Da xuat ra file thanh cong." << endl;
	}
}

// danh sach doc gia qua han muon sach
void Manage::QuaHan(ofstream& out)
{
	// lay thoi gian cua he thong
	time_t now = time(0);
	tm local;
	localtime_s(&local, &now);
	int hournow = local.tm_hour;
	int minutenow = local.tm_min;
	int daynow = local.tm_mday;
	int monthnow = local.tm_mon + 1;
	int yearnow = local.tm_year + 1900;

	out << "______________DANH SACH DOC GIA HET HAN MUON SACH___________________" << endl;
	out << "Thoi gian in: " << daynow << "/" << monthnow << "/" << yearnow << "  " << hournow << ":" << minutenow << endl << endl;
	int d = 0;
	for (int i = 0; i < reader.size(); i++)
	{
		DocGia* p = reader[i];
		if (p->KhoangThoiGian(p->layNgay(), p->layThang(), p->layNam()) > 7)
		{
			d++;
			out << " + Doc gia het han thu " << d << " : " << endl;
			out << "     Ma doc gia:              " << reader[i]->layMaDocGia() << endl;
			out << "     Ten doc gia:             " << reader[i]->layTenDocGia() << endl;
			out << "     Ngay muon sach:          " << reader[i]->layNgay() << "/" << reader[i]->layThang() << "/" << reader[i]->layNam() << endl;
			out << "\n               -----Thong tin sach da muon----- " << endl;
			SachTiengViet* q = TimSach(p->layMaSachMuon());
			if (q->KTSachTiengViet() == true)
				out << "     Loai sach muon:          Sach Tieng Viet" << endl;
			else
				out << "     Loai sach muon:          Sach Ngoai van" << endl;
			q->XuatDayDu(out);
			out << "   ==> So tien phat:          " << TienPhat(p)/1000 << " nghin VND" << endl << endl;
		}
	}

	if (d == 0)
	{
		out << " <!> Khong co doc gia nao het han, tinh tai thoi diem " << daynow << "/" << monthnow << "/" << yearnow << endl;
		cout << " <!> Khong co doc gia nao het han, tinh tai thoi diem " << daynow << "/" << monthnow << "/" << yearnow << endl;
	}
	else
		cout << "   -> 100% - Da xuat ra file thanh cong." << endl;
}


// Doc mang sach tu file
vector<SachTiengViet*> Manage::DocMangSachTuFile() const
{
	vector<SachTiengViet*> _book;
	ifstream boDoc;
	// mo file
	boDoc.open("book_list_manage.txt");
	//if (boDoc == NULL)
	//	return 0;
	int idx, n;
	boDoc >> n;
	for (int i = 0; i < n; i++)
	{
		SachTiengViet* p;
		SachNgoaiVan* q;
		boDoc >> idx;
		if (idx == 1)
		{
			p = new SachTiengViet();
			p->DocSach(boDoc);
			_book.push_back(p);
		}
		else
		{
			q = new SachNgoaiVan();
			q->DocSach(boDoc);
			_book.push_back(q);
		}
	}

	boDoc.close();
	return _book;
}

// Doc mang doc gia tu file
vector<DocGia*> Manage::DocMangDocGiaTuFile() const
{
	vector<DocGia*> _reader;
	ifstream boDoc;
	// mo file
	boDoc.open("reader_list_manage.txt");
	//if (!boDoc)
	//	return _reader;
	int n;
	boDoc >> n;
	boDoc.ignore();
	for (int i = 0; i < n; i++)
	{
		DocGia* DG = new DocGia();
		DG->DocDocGia(boDoc);
		_reader.push_back(DG);
	}

	boDoc.close();
	return _reader;
}


// Kiem tra da co du lieu cho mang sach chua
bool Manage::KTMangSach()
{
	if (DocMangSachTuFile().size() == 0)
		return false;
	else
		return true;
}


// kiem tra da co mang doc gia chua
bool Manage::KTMangDocGia()
{
	if (DocMangDocGiaTuFile().size() == 0)
		return false;
	else
		return true;
}