//Library yang digunakan
#include <stdio.h>
#include <stdlib.h>

//Deklarasi Function
void program_end(); //line 25
void handling(); //line 32
void menu_utama(); //line 55
void menu_kalkulasi();
void menu_data();
void menu_help(); //line 91
void help_pemakaian(); //line 118
void help_kalkulasi(); //line 136
void help_sumber(); //line 154
void help_kontak(); //line 172
void menu_credit();
int submenu_end(); //line 38


int main(){	
	menu_utama();
	}

//function buat mengakhiri program
void program_end(){
	system("cls");
	printf("Terima Kasih Sudah Menggunakan Program ini");
	exit(0);
}

//Untuk Error Handling jika user menginput angka yang tidak sesuai dengan pilihan diberikan
void handling(){
	system("pause");
	system("cls");
}

//Untuk memberikan pilihan kepada user untuk kembali ke menu utama atau mengakhiri program ketika user membuka sebuah submenu
int submenu_end(){
	int input;
	printf("\n0 untuk mengakhiri program");
	printf("\n9 untuk kembali ke menu utama");
	printf("\nInput :");
	scanf("%d", &input);
	if(input==0){
		program_end();
	}
	else if(input==9){
		system("cls");
		menu_utama();
	}
	return input;
}

//Function untuk menu utama atau menu startup
void menu_utama(){
	int result = 0;
	printf("Emission and Price Calculator for Electrical Appliances (EPCEA)\nBy Kelompok 4\n");
	printf("---------------------------------------------------------");
	printf("\n1. Kevin Raihan\n2. Hanif Nur Ilham Sanjaya\n3. Tjokorde Gde Agung Abel Putra\n4. Samuel Tanaka Sibarani\n");
	printf("---------------------------------------------------------");
	printf("\nSTART UP MENU\n\n1. MULAI KALKULASI\n2. TAMPILKAN DATA\n3. HELP\n4. CREDITS\n5. EXIT\n\n");
	printf("Input : ");
	scanf("%d", &result);
		switch (result){
			case 1 :
				system("cls");
				printf("ini kalkulasi");//Placeholder, Ganti dengan function kalkulasi yang bakal ngitung dan nyimpan data, nanti di akhir function mungkin bisa ditambahkan saran untuk user 
				break;
			case 2 : 
			system("cls");
				printf("ini tampilan data yang dimasukkan");//Placeholder, untuk menampilkan data tersimpan
				break;
			case 3 :
				system("cls");
				menu_help(); //ini pilihan ke-3 MENU HELP
				break;
			case 4 :
				system("cls");
				printf("ini credit, tapi kyknya bisa diganti reset data, kalau pada mau");
			case 5 :
				program_end();
			default :
				printf("WARNING :\nPILIHAN TIDAK TERSEDIA\nSILAHKAN MENGULANG INPUT\n");
				handling();
				menu_utama();
				break;
	}
}

//Function untuk submenu help
void menu_help(){
	int input;
	printf("HELP\n\n");
	printf("MAIN PURPOSE\nProgram EPCEA berfungsi untuk menghitung emisi karbon yang dihasilkan suatu rumah tangga berdasarkan penggunaan alat elektronik dalam jangka waktu 1 (satu) hari.\n\nFITUR TAMBAHAN\nSelain emisi karbon, Program juga akan menghitung biaya listrik sesuai dengan durasi pemakaian\n\nBENEFIT FOR USERS\nDengan menggunakan program ini user dapat berkontribusi dalam penerapan climate action dengan meningkatkan awareness akankan emisi dihasilkan rumah tangga serta dapat mengurangi emisi dihasilkan rumah tangga sendiri dengan membatasi penggunaan alat elektronik.\nUser juga dapat menghemat biaya listrik");
	printf("\n\nBANTUAN TAMBAHAN\n1. CARA PEMAKAIAN\n2. KALKULASI\n3. SUMBER INFORMASI\n4. CONTACT US!");
	input = submenu_end();
		switch (input){
			case 1 :
				help_pemakaian(); //function di-define pada line 118
				break;
			case 2 : 
				help_kalkulasi(); //function di-define pada line 136
				break;
			case 3 :
				help_sumber(); //function di-define pada line 154
				break;
			case 4 :
				help_kontak(); //function di-define pada line 172
				break;
			default :
				printf("WARNING :\nPILIHAN TIDAK TERSEDIA\nSILAHKAN MENGULANG INPUT\n");
				handling();
				menu_help();
				break;
		}
}

void help_pemakaian(){
	int input;
	system("cls");
	//penjelasan cara pemakaian
	printf("ini cara pemakaian\n");
	printf("\n1 untuk kembali ke menu HELP");
	input = submenu_end();
		if(input==1){
			system("cls");
			menu_help();
		}
		else{
			printf("WARNING :\nPILIHAN TIDAK TERSEDIA\nSILAHKAN MENGULANG INPUT\n");
			handling();
			help_pemakaian();
		}
}

void help_kalkulasi(){
	int input;
	system("cls");
	//penjelasan rumus apa yang dipakai
	printf("ini rumus yang digunakan\n");
	printf("\n1 untuk kembali ke menu HELP");
	input = submenu_end();
		if(input==1){
			system("cls");
			menu_help();
		}
		else{
			printf("WARNING :\nPILIHAN TIDAK TERSEDIA\nSILAHKAN MENGULANG INPUT\n");
			handling();
			help_kalkulasi();
		}
}

void help_sumber(){
	int input;
	system("cls");
	//penjelasan sumber informasi untuk rumus, standar biaya, standar emisi yang dihasilkan
	printf("ini cara pemakaian\n");
	printf("\n1 untuk kembali ke menu HELP");
	input = submenu_end();
		if(input==1){
			system("cls");
			menu_help();
		}
		else{
			printf("WARNING :\nPILIHAN TIDAK TERSEDIA\nSILAHKAN MENGULANG INPUT\n");
			handling();
			help_sumber();
		}
}

void help_kontak(){
	int input;
	system("cls");
	//penyampaian informasi kontak developer, untuk kritik saran, troubleshooting, dan tips (baik duit maupun lisan ehehehe)
	printf("ini kontak kami\n");
	printf("\n1 untuk kembali ke menu HELP");
	input = submenu_end();
		if(input==1){
			system("cls");
			menu_help();
		}
		else{
			printf("WARNING :\nPILIHAN TIDAK TERSEDIA\nSILAHKAN MENGULANG INPUT\n");
			handling();
			help_kontak();
		}
}
