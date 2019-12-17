#include <iostream>
using namespace std;

#include "Manage.h"

int main()
{
	try
	{
		cout << "  ###############################################################################################################" << endl;
		cout << "  ##                                     PHAN MEN QUAN LY THU VIEN                                             ##" << endl;
		cout << "  ##                               _____________________________________                                       ##" << endl;
		cout << "  ##    QUI UOC NHAP:                                                                                          ##" << endl
			<< "  ##      0 -  Dung chuong trinh                                                                               ##" << endl
			<< "  ##  - QUAN LY SACH:                                                                                          ##" << endl
			<< "  ##      1  -  Kiem tra xem da co danh sach sach trong file \"book_list.txt\" da luu truoc do chua              ##" << endl
			<< "  ##        + Neu da co he thong se cap nhat danh sach do va cho phep thuc hien cac thao tac duoi              ##" << endl
			<< "  ##        + Neu chua co he thong se yeu cau nhap MOI danh sach sach                                          ##" << endl
			<< "  ##         (Ket thuc nhap he thong se tu dong xuat ra file \"book_list.txt\"                                   ##" << endl
			<< "  ##      2  -  Them thong tin mot quyen sach moi                                                              ##" << endl
			<< "  ##      3  -  Xoa quyen sach co MaSach biet truoc                                                            ##" << endl
			<< "  ##      4  -  Sua thong tin sach co MaSach biet truoc                                                        ##" << endl
			<< "  ##      5  -  Tim sach co MaSach biet truoc va ghi vao file \"find_book.txt\"                                  ##" << endl
			<< "  ##  - QUAN LY DOC GIA:                                                                                       ##" << endl
			<< "  ##      6  -  Kiem tra xem da co danh sach cac doc gia trong file \"reader_list.txt\" da luu truoc do chua     ##" << endl
			<< "  ##        + Neu da co he thong se cap nhat danh sach do va cho phep thuc hien cac thao tac duoi              ##" << endl
			<< "  ##        + Neu chua co he thong se yeu cau nhap MOI danh sach doc gia                                       ##" << endl
			<< "  ##         (Ket thuc nhap he thong se tu dong xuat ra file \"reader_list.txt\"                                 ##" << endl
			<< "  ##      7  -  Them thong tin mot doc gia moi                                                                 ##" << endl
			<< "  ##      8  - Xoa mot doc gia co MaDocGia biet truoc                                                          ##" << endl
			<< "  ##      9  - Sua thong tin mot doc gia co MaDocGia biet truoc                                                ##" << endl
			<< "  ##      10 - Tim doc gia co MaDocGia biet truoc va ghi vao file \"find_reader.txt\"                            ##" << endl
			<< "  ##  - IN PHIEU:                                                                                              ##" << endl
			<< "  ##      11 - In phieu muon sach cua doc gia co MaDocGia va ghi vao file \"borrow_a_reader.txt\"                ##" << endl
			<< "  ##      12 - In phieu tra sach cua doc gia co MaDocGia va ghi vao file \"return_a_reader.txt\"                 ##" << endl
			<< "  ##      13 - In phieu muon sach cua tat ca cac doc gia vao file \"borrow_note.txt\"                            ##" << endl
			<< "  ##      14 - In phieu tra sach cua tat ca cac doc gia vao file \"return_note.txt\"                             ##" << endl
			<< "  ##      15 - Liet ke danh sach doc gia het han muon sach \"out_of_date.txt\"                                   ##" << endl
			<< "  ##                                                                                                           ##" << endl
			<< "  ###############################################################################################################" << endl << endl;


		Manage Q;

		while (1)
		{
			int key;
			cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
			cout << " ~ Nhap thao tac: ";
			cin >> key;

			// Ket thuc chuong trinh
			if (key == 0)
			{
				cout << "\n        ######################   END   ####################" << endl;
				break;
			}

			// kiem tra du lieu hoac nhap moi danh sach sach
			else if (key == 1)
			{
				if (Q.KTMangSach() == true)
				{
					cout << "  -> Da co danh sach sach nhap truoc do!" << endl;
					Q.ganMangSach(Q.DocMangSachTuFile()); // Cap nhat du lieu da co truoc do vao mang hien tai
				}
				else
				{
					Q.NhapMangSach();
					ofstream outfile_book_list("book_list.txt");
					ofstream outfile_book_manage("book_list_manage.txt");
					if (outfile_book_list.fail())
					{
						cout << "<!> Failed to open this file" << endl;
						return -1;
					}
					Q.XuatMangSach(outfile_book_manage);
					Q.XuatMangSachDayDu(outfile_book_list);
					cout << "   -> 100% - Da xuat ra file thanh cong." << endl;
					outfile_book_list.close();
					outfile_book_manage.close();
				}
			}


			// them sach vao danh sach sach
			else if (key == 2)
			{
				ofstream outfile_book_list("book_list.txt");
				ofstream outfile_book_manage("book_list_manage.txt");
				if (outfile_book_list.fail())
				{
					cout << "<!> Failed to open this file" << endl;
					return -1;
				}
				Q.ThemSach();
				Q.XuatMangSach(outfile_book_manage); // cap nhat lai du lieu moi sau khi them
				Q.XuatMangSachDayDu(outfile_book_list);
				cout << "   -> 100% - Da them vao danh sach thanh cong." << endl;
				outfile_book_list.close();
				outfile_book_manage.close();
			}


			// xoa sach co MaSach biet truoc
			else if (key == 3)
			{
				ofstream outfile_book_list("book_list.txt");
				ofstream outfile_book_manage("book_list_manage.txt");
				if (outfile_book_list.fail())
				{
					cout << "<!> Failed to open this file" << endl;
					return -1;
				}
				string id;
				cin.ignore();
				cout << " Nhap MaSach can xoa: ";
				getline(cin, id);
				Q.XoaSach(id);
				Q.XuatMangSach(outfile_book_manage); // cap nhat lai du lieu moi sau khi xoa
				Q.XuatMangSachDayDu(outfile_book_list);
				outfile_book_list.close();
				outfile_book_manage.close();
			}


			// Sua thong tin sach co MaSach
			else if (key == 4)
			{
				ofstream outfile_book_list("book_list.txt");
				ofstream outfile_book_manage("book_list_manage.txt");
				if (outfile_book_list.fail())
				{
					cout << "<!> Failed to open this file" << endl;
					return -1;
				}
				string id;
				cin.ignore();
				cout << " Nhap MaSach can sua: ";
				getline(cin, id);
				Q.SuaSach(id);
				Q.XuatMangSach(outfile_book_manage); // cap nhat lai du lieu moi sau khi sua
				Q.XuatMangSachDayDu(outfile_book_list);
				outfile_book_list.close();
				outfile_book_manage.close();
			}


			// Tim sach
			else if (key == 5)
			{
				ofstream outfile_find_book("find_book.txt");
				if (outfile_find_book.fail())
				{
					cout << "<!> Failed to open this file" << endl;
					return -1;
				}
				string id;
				cin.ignore();
				cout << " Nhap MaSach can tim: ";
				getline(cin, id);
				if (Q.TimSach(id) == NULL)
					cout << "   -> <!> Khong tim thay sach nay trong danh sach" << endl;
				else
				{
					Q.TimSach(id)->XuatDayDu(outfile_find_book);
					cout << "   -> 100% - Da tim ra." << endl;
				}
				outfile_find_book.close();
			}


			// kiem tra du lieu hoac nhap moi danh sach doc gia
			else if (key == 6)
			{
				if (Q.KTMangDocGia() == true)
				{
					cout << "  -> Da co danh sach doc gia nhap truoc do!" << endl;
					Q.ganMangDocGia(Q.DocMangDocGiaTuFile());
				}
				else
				{
					Q.NhapMangDocGia();
					ofstream outfile_reader_list("reader_list.txt");
					ofstream outfile_reader_manage("reader_list_manage.txt");
					if (outfile_reader_list.fail())
					{
						cout << "<!> Failed to open this file" << endl;
						return -1;
					}
					Q.XuatMangDocGia(outfile_reader_manage);
					Q.XuatMangDocGiaDayDu(outfile_reader_list);
					cout << "   -> 100% - Da xuat ra file thanh cong." << endl;
					outfile_reader_list.close();
					outfile_reader_manage.close();
				}
			}


			// them  mot doc gia vao danh sach
			else if (key == 7)
			{
				ofstream outfile_reader_list("reader_list.txt");
				ofstream outfile_reader_manage("reader_list_manage.txt");
				if (outfile_reader_list.fail())
				{
					cout << "<!> Failed to open this file" << endl;
					return -1;
				}
				Q.ThemDocGia();
				Q.XuatMangDocGia(outfile_reader_manage); // cap nhat du lieu moi sau khi them
				Q.XuatMangDocGiaDayDu(outfile_reader_list);
				cout << "   -> 100% - Da them vao danh sach thanh cong." << endl;
				outfile_reader_list.close();
				outfile_reader_manage.close();
			}


			// xoa mot doc gia co MaDocGia biet truoc
			else if (key == 8)
			{
				ofstream outfile_reader_list("reader_list.txt");
				ofstream outfile_reader_manage("reader_list_manage.txt");
				if (outfile_reader_list.fail())
				{
					cout << "<!> Failed to open this file" << endl;
					return -1;
				}
				string id;
				cin.ignore();
				cout << " Nhap MaDocGia can xoa: ";
				getline(cin, id);
				Q.XoaDocGia(id);
				Q.XuatMangDocGia(outfile_reader_manage); // cap nhat du lieu moi sau khi xoa
				Q.XuatMangDocGiaDayDu(outfile_reader_list);
				outfile_reader_list.close();
				outfile_reader_manage.close();
			}


			// sua thong tin doc gia co MaDocGia
			else if (key == 9)
			{
				ofstream outfile_reader_list("reader_list.txt");
				ofstream outfile_reader_manage("reader_list_manage.txt");
				if (outfile_reader_list.fail())
				{
					cout << "<!> Failed to open this file" << endl;
					return -1;
				}
				string id;
				cin.ignore();
				cout << " Nhap MaDocGia can sua: ";
				getline(cin, id);
				Q.SuaDocGia(id);
				Q.XuatMangDocGia(outfile_reader_manage); // cap nhat du lieu moi sau khi sua
				Q.XuatMangDocGiaDayDu(outfile_reader_list);
				outfile_reader_list.close();
				outfile_reader_manage.close();
			}


			// tim doc gia dua vao MaDocGia
			else if (key == 10)
			{
				ofstream outfile_find_reader("find_reader.txt");
				if (outfile_find_reader.fail())
				{
					cout << "<!> Failed to open this file" << endl;
					return -1;
				}
				string id;
				cin.ignore();
				cout << " Nhap MaDocGia can tim: ";
				getline(cin, id);
				if (Q.TimDocGia(id) == NULL)
					cout << "  <!> Khong tin thay doc gia nay trong danh sach " << endl;
				else
				{
					Q.TimDocGia(id)->XuatDayDu(outfile_find_reader);
					Q.TimSach(Q.TimDocGia(id)->layMaSachMuon())->XuatDayDu(outfile_find_reader);
					cout << "   -> 100% - Da tim ra." << endl;
				}
				outfile_find_reader.close();
			}


			// in phieu muon cua doc gia co MaDocGia
			else if (key == 11)
			{
				ofstream outfile_borrow_a_reader("borrow_note_a_reader.txt");
				if (outfile_borrow_a_reader.fail())
				{
					cout << "<!> Failed to open this file" << endl;
					return -1;
				}
				string id;
				cin.ignore();
				cout << " Nhap MaDocGia can in phieu muon: ";
				getline(cin, id);
				Q.PhieuMuon(outfile_borrow_a_reader, id);
				outfile_borrow_a_reader.close();
			}


			// in phieu tra cua doc gia co MaDocGia
			else if (key == 12)
			{
				ofstream outfile_return_a_reader("return_note_a_reader.txt");
				if (outfile_return_a_reader.fail())
				{
					cout << "<!> Failed to open this file" << endl;
					return -1;
				}
				string id;
				cin.ignore();
				cout << " Nhap MaDocGia can in phieu tra: ";
				getline(cin, id);
				Q.PhieuTra(outfile_return_a_reader, id);
				outfile_return_a_reader.close();
			}


			// in tat ca phieu muon 
			else if (key == 13)
			{
				ofstream outfile_borrow_note("borrow_note.txt");
				if (outfile_borrow_note.fail())
				{
					cout << "<!> Failed to open this file" << endl;
					return -1;
				}
				Q.PhieuMuon(outfile_borrow_note);
				outfile_borrow_note.close();
			}


			// in tat ca phieu tra
			else if (key == 14)
			{
				ofstream outfile_return_note("return_note.txt");
				if (outfile_return_note.fail())
				{
					cout << "<!> Failed to open this file" << endl;
					return -1;
				}
				Q.PhieuTra(outfile_return_note);
				outfile_return_note.close();
			}


			// in danh sach het han muon sach
			else if (key == 15)
			{
				ofstream outfile_out_of_date("out_of_date.txt");
				if (outfile_out_of_date.fail())
				{
					cout << "<!> Failed to open this file" << endl;
					return -1;
				}
				Q.QuaHan(outfile_out_of_date);
				outfile_out_of_date.close();
			}


			// sai thao tac
			else
				cout << " <!> Nhap sai thao tac. Nhap lai" << endl;
		}
	}
	catch (const char* s)
	{
		cout << s;
	}
	catch (...)
	{
		cout << " <<!>> ERROR";
	}


	system("pause");
	return 0;
}