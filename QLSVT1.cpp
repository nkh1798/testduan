#include<iostream>
#include<windows.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include"dohoa.h"

using namespace std;


char FName[]="filedata.txt";

struct Date{
	int Ngay, Thang, Nam;
};

struct SinhVien {
	char HoVaTen[50];
	char MaLop[20];
	int MaSinhVien;
	Date date;
	float DiemTB;
};

SinhVien sinhVien[1000];
SinhVien sv;
int SoSinhVien;

void HienThiMenu(int LuaChon);
void menu1(int LuaChon);
void ThongKe();
void TimKiem(int LuaChon);
int DocFile();
void GhiFile1(int i);

//---------------------------------------------------------------------------------------------------

int main()
{
	SetWindow(115,35);
	DocFile();
	HienThiMenu(1);

}

//----------------------------------------------------------------------------------

void menu1(int LuaChon) {	//Khung chuong trinh

	textcolor(14);
	gotoxy(31,2);	cout<<"/================================================\\";
	gotoxy(31,3);	cout<<"|                Quan_Ly_Sinh_Vien               |";
	gotoxy(31,4);	cout<<"\\================================================/";
	textcolor(11);
	int a=6;
	int b=a+1;
	textcolor(11);
	for(int i=0; i<31; i++)
	{
		gotoxy(41+i,6);
		cout<<(char)205;
	}
	gotoxy(40,6);	cout<<(char)201;
	gotoxy(72,6);	cout<<(char)187;
	for(int i=0; i<5; i++) 
	{
		for(int j=0; j<31; j++) {
			gotoxy(41+j,a+2);
			cout<<"-";
		}
		a++;
		if(i!=7) {
			gotoxy(40,a);
			cout<<(char)186;
			gotoxy(40,a+1);
			cout<<(char)186;
			gotoxy(72,a);
			cout<<(char)186;
			gotoxy(72,a+1);
			cout<<(char)186;
		}
		a++;
	}
	gotoxy(40,17);	cout<<(char)186;
	gotoxy(72,17);	cout<<(char)186;
	for(int i=0; i<31; i++)
	{
		gotoxy(41+i,18);
		cout<<(char)205;
	}
	gotoxy(40,18);	cout<<(char)200;
	gotoxy(72,18);	cout<<(char)188;
	if(LuaChon==1) {
		textcolor(12);
	} else
		textcolor(11);
	gotoxy(50,7);
	cout<<"1. Them ho so\n";
	gotoxy(50,9);
	if(LuaChon==2) {
		textcolor(12);
	} else
		textcolor(11);
	cout<<"2. In danh sach\n";
	gotoxy(50,11);
	if(LuaChon==3) {
		textcolor(12);
	} else
		textcolor(11);
	cout<<"3. Sap xep\n";
	if(LuaChon==4) {
		textcolor(12);
	} else
		textcolor(11);
	gotoxy(50,13);
	cout<<"4. Tim kiem\n";
	if(LuaChon==5) {
		textcolor(12);
	} else
		textcolor(11);
	gotoxy(50,15);
	cout<<"5. Thong ke\n";
	gotoxy(50,19);
	if(LuaChon==6) {
		textcolor(12);
	} else
		textcolor(11);
	gotoxy(50,17);
	cout<<"6. Thoat\n";
	XoaConTro();
}

//---------------------------------------------------------------------------------------------------

void HienThiMenu(int LuaChon) {		//Lua chon menu
	//system("cls");
	fflush(stdin);
	textcolor(11);
	menu1(LuaChon); 
	while(1) {
		char phim=getch();
		//cout<<"Phim dang an"<<key;
		switch(phim) {
				//Phim len=72, xuongg 80, trai 75, phai 77, enter 13
			case 72:
				fflush(stdin);
				LuaChon--;
				if(LuaChon<=0)
					LuaChon=6;
				break;
			case 80:
				fflush(stdin);
				LuaChon++;
				if(LuaChon>=7)
					LuaChon=1;
				break;
			case 13: {
				switch(LuaChon) {
					case 1:
					//	system("cls");
						//ThemHoSo();
						break;
					case 2:
						//InDanhSach();
						break;
					case 3:
						//SapXep(1);
						break;
					case 4:
						//TimKiem(1);
						break;
					case 5:
						//ThongKe();
						break;
					case 6:
						exit(0);
						break;
				}
			}
			break;
		}
		menu1(LuaChon);
}
}

//---------------------------------------------------------------------------------------------------

 

int DocFile() 
  {
   
   FILE *f1;
   int i=0;
   if((f1 = fopen(FName,"r")) == NULL)
   {
   	gotoxy(50,8);
   	cout<<"Khong the mo file "<<FName;
   	
   }
   else{
   	  while(fread(&sinhVien[i],sizeof(sv),1,f1),!feof(f1))
  	 {
  	 	 i++;	
	 }
	   SoSinhVien=i;

   }
    fclose(f1);	
  }

//---------------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------------------

void GhiFile1(int i)
{
//	FILE *f1 = fopen(FName,"a+");
//	FILE *f2 = fopen(Name,"w");
	system("del filedata.txt");
	FILE *f2=NULL;
	f2 = fopen("filedata.txt","a+");
	memcpy(&sinhVien[i], &sv, sizeof(SinhVien));
	for(int j=0; j<SoSinhVien; j++)
	{
		sv=sinhVien[j];
		if(j==i)	fwrite(&sinhVien[i],sizeof(sinhVien[i]),1,f2);
		else 		fwrite(&sv,sizeof(sv),1,f2);
	}
	//memcpy(&sinhVien[i], &sv, sizeof(SinhVien));
   	fclose(f2);		
}

//---------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------





