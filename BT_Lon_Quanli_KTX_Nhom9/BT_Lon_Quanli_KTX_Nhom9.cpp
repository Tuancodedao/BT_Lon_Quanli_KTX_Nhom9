#include <iostream>

using namespace std;

struct Date
{
	int d, m, y;
};
struct SinhVien
{
	int ma;
	char ten[150];
	char diachi[50];
	Date ngaysinh;
};
struct Nhanvien
{
	int ma;
	char ten[150];
	char diachi[50];
	Date ngaysinh;
};
struct KTX
{
	SinhVien sv;
	Nhanvien nv;
};
//tao cau truc danh sach lien ket don
struct Node
{
	SinhVien* data;
	Node* pNext;
};
struct SingleList
{
	Node* pHead;
};
//khoi tao danh sach lien ket don
void Initialize(SingleList*& list)
{
	list = new SingleList;
	list->pHead = NULL;
}
SinhVien* NhapSinhVien()
{
	SinhVien* sv = new SinhVien;
	cout << "Nhap MSSV:";
	cin >> sv->ma;
	cin.ignore();
	cout << "Nhap ho va ten:";
	fgets(sv->ten,150,stdin);
	cout << "Nhap dia chi: ";
	fgets(sv->diachi, 50, stdin);
	cout << "Nhap ngay sinh : ";
	cin >> sv->ngaysinh.d;
	cout << "Nhap thang sinh: ";
	cin >> sv->ngaysinh.m;
	cout << "Nhap nam sinh: ";
	cin >> sv->ngaysinh.y;
	return sv;
}
//tao node sinh vien
Node* CreateNode(SinhVien* sv)
{
	Node* pNode = new Node;
	if (pNode != NULL)
	{
		pNode->data = sv;
		pNode->pNext = NULL;
	}
	else
	{
		cout << "cap phat bo nho that bai!!!";
	}
	return pNode;
}
//hien thi danh sach
void PrintList(SingleList* list)
{
	Node* pTmp = list->pHead;
	if (pTmp == NULL)
	{
		cout << "Danh sach rong";
		return;
	}
	while (pTmp != NULL)
	{
		SinhVien* sv = pTmp->data;
		cout << sv->ma << "\t" << sv->ten << "\n";
		pTmp = pTmp->pNext;
	}
}
//them node vao cuoi danh sach
void InsertLast(SingleList*& list, SinhVien* sv)
{
	Node* pNode = CreateNode(sv);
	if (list->pHead == NULL)
	{
		list->pHead = pNode;
	}
	else
	{
		Node* pTmp = list->pHead;

		while (pTmp->pNext != NULL)
		{
			pTmp = pTmp->pNext;
		}
		pTmp->pNext = pNode;
	}
}
void SortList(SingleList*& list)
{
	for (Node* pTmp = list->pHead; pTmp != NULL; pTmp = pTmp->pNext)
	{
		for (Node* pTmp2 = pTmp->pNext; pTmp2 != NULL; pTmp2 = pTmp2->pNext)
		{
			SinhVien* svTmp = pTmp->data;
			SinhVien* svTmp2 = pTmp2->data;
			if (svTmp2->ma < svTmp->ma)
			{
				int ma = svTmp->ma;
				char ten[150];
				strcpy_s(ten, svTmp->ten);

				svTmp->ma = svTmp2->ma;
				strcpy_s(svTmp->ten, svTmp2->ten);
				svTmp2->ma = ma;
				strcpy_s(svTmp2->ten, ten);
			}
		}
	}
}
void RemoveNode(SingleList*& list, int ma)
{
	Node* pDel = list->pHead;
	if (pDel == NULL)
	{
		cout << "Danh sach rong!";
	}
	else
	{
		Node* pPre = NULL;
		while (pDel != NULL)
		{
			SinhVien* sv = pDel->data;
			if (sv->ma == ma)
				break;
			pPre = pDel;
			pDel = pDel->pNext;
		}
		if (pDel == NULL)
		{
			cout << "khong tim thay MSSV: " << ma;
		}
		else
		{
			if (pDel == list->pHead)
			{
				list->pHead = list->pHead->pNext;
				pDel->pNext = NULL;
				delete pDel;
				pDel = NULL;
			}
			else
			{
				pPre->pNext = pDel->pNext;
				pDel->pNext = NULL;
				delete pDel;
				pDel = NULL;
			}
		}
	}
}
int main(int argc, char** argv)
{
	cout << "                    ****        Q U A N   L I   K T X     ****        **   N H O M   9     ****    \n";
	cout << "                *** DANH SACH THANH VIEN ========== TRAN QUOC TUAN========== HA THANH TUNG ============\n";
	cout << "                 ***              PHAM THI BICH PHUONG ==============PHUN KOAN SENH===========   ****\n ";
	cout << "                     ******                                                                 ******* \n";
	cout << "                            *********                                            **********      \n ";
	cout << "                                      ******************       *****************       \n";
	cout << "                                                          ***                       \n";
	//cout << "Nhap thong tin Boss KTX \n";
//	NhapSinhVien();
	SinhVien* teo;
	SingleList* list;
	Initialize(list);
	int ch;
	do {
		cout << "================= M E N U ============ K T X ============ \n";
		cout << "1.Nhap them thong tin sinh vien \n";
		cout << "2.Nhap them thong tin nhan vien\n";
		cout << "3.In ra danh sach sinh vien\n";
		cout << "4.Ghi vao file\n";
		cout << "5.Doc file\n";
		cout << "6.Them sinh vien\n";
		cout << "7.Them nhan vien\n";
		cout << "8.Xoa thong tin 1 sinh vien\n";
		cout << "9.Xoa thong tin 1 nhan vien\n";
		cout << "10.Tim kiem 1 sinh vien\n";
		cout << "11.Tim kiem 1 nhan vien\n";
		cout << "12.Sap xep sinh vien\n";
		cout << "13.Sap xep nhan vien\n";
		cout << "0.Thoat chuong trinh\n";
		cout << "==========================================================\n";
		do {
			cout << "Moi chon: ";
			cin >> ch;
			if (ch < 0 || ch>13) cout << "Nhap sai nhap lai: ";
		} while (ch < 0 || ch>13);
		switch (ch)
		{
		case 0:
		{
			return 0;
			break;
		}
		case 1:
		{
			NhapSinhVien();
			break;
		}
		case 3:
		{
			PrintList(list);
			break;
		}
		case 4:
		{
			break;
		}
		case 5:
		{
			break;
		}
		case 6:
		{
			SinhVien* teo = NhapSinhVien();
			InsertLast(list, teo);
			break;
		}
		case 7:
		{
			break;
		}
		case 8:
		{
			cout << "\Ban muon xoa sinh vien co MSSV: ";
			int ma;
			cin >> ma;
			RemoveNode(list, ma);
			cout << "\nSau khi xoa:\n";
			PrintList(list);
			break;
		}
		case 9:
		{
			break;
		}
		case 10:
		{
			break;
		}
		case 11:
		{
			break;
		}
		case 12:
		{
			SortList(list);
			cout << "\nSau khi sap xep:\n";
			PrintList(list);
			break;
		}
		case 13:
		{
			break;
		}
		default:
		{
			cout << "Hello\n`";
		}
		}
	} while (true);
	system("pause");
	return 0;
}