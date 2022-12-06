//Library yang digunakan
#include <stdio.h>
#include <stdlib.h>
//tes
//Deklarasi Function
void handling(); 
void menu_utama(); 
void menu_kalkulasi();
void menu_data();
void menu_help(); 
void help_pemakaian(); 
void help_kalkulasi(); 
void help_sumber(); 
void help_kontak(); 
void menu_credit();
void program_end(); 
int submenu_end(); 


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
	printf("Emission of GHG and Price Calculator for Electrical Appliances (EPCEA Jakarta Ver.)\nBy Kelompok 4\n");
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

void menu_kalkulasi(){
//Rumus : kwh = kw x h 
//		  co2 = kwh x co2/h
//		  Rp  = kwh x Rp/kwh
typedef struct input{
	char devicename [50];
	float kw;
	float h;
	float co2_h;
	int rp_kwh;
}device;
	int counter, continuation;
	int* biaya;
	int* co2;
	biaya = (int *) calloc (1, sizeof(int));
	co2 = (int *) calloc (1, sizeof(int));
	
	continuation = 1;
	while (continuation==1){
		//ini buat input data
	}
	printf("CALCULATION\n\n");
	printf("Menghitung Emisi CO2 per Jam");
	printf("");//ini ngeprint hasil data
}

//Function untuk submenu help
void menu_help(){
	int input;
	printf("HELP\n\n");
	printf("MAIN PURPOSE\nProgram EPCEA berfungsi untuk menghitung emisi karbon yang dihasilkan suatu rumah tangga berdasarkan penggunaan alat elektronik dalam jangka waktu 1 (satu) hari.\n\nFITUR TAMBAHAN\nSelain emisi karbon, Program juga akan menghitung biaya listrik sesuai dengan durasi pemakaian\n\nBENEFIT FOR USERS\nDengan menggunakan program ini user dapat berkontribusi dalam penerapan climate action dengan meningkatkan awareness akankan emisi dihasilkan rumah tangga serta dapat mengurangi emisi dihasilkan rumah tangga sendiri dengan membatasi penggunaan alat elektronik.\nUser juga dapat menghemat biaya listrik");
	printf("\n\nBANTUAN TAMBAHAN\n1. CARA PEMAKAIAN\n2. KALKULASI\n3. SUMBER INFORMASI\n4. CONTACT US!\n\n");
	input = submenu_end();
		switch (input){
			case 1 :
				help_pemakaian(); //function 
				break;
			case 2 : 
				help_kalkulasi(); //function 
				break;
			case 3 :
				help_sumber(); //function 
				break;
			case 4 :
				help_kontak(); //function 
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
	printf("CARA PEMAKAIAN\nAwal start program, pilihlah menu MULAI KALKULASI,lalu user diminta untuk mengisi nama dan atau jenis alat elektronik yang akan dihitung. Lalu user akan diminta untuk menginput variable variable yang diperlukan untuk menghitung CO2 dan Biaya listrik untuk tiap device.\nUser dapat memilih untuk menghitung device lain semaunya user hingga user menginput (INSERT SENTINEL HERE) sehingga program tidak akan meminta input lagi dan menjumlahkan total CO2/hari dan Biaya Listrik/hari dari seluruh alat elektronik dan menampilkannya\n\n");
	printf("Pilihan TAMPILKAN DATA akan menampilkan hasil kalkulasi dalam bentuk yang lebih teratur\n\n");
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
	printf("RUMUS KALKULASI\nRumus yang digunakan antara lain \n\nRumus Emisi CO2 per Hari :\nCO2 per jam x kWh\n\nRumus Biaya Listrik Rp per kWh x kWh\n\nRumus kWh\nkWh = kW x h\n\ndetails: \nkWh = Kilowatt hour atau Kilowatt per jam\nh  = hour atau jam\n\n");
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
	printf("SUMBER INFORMASI\nSumber Rumus yang digunakan:\nhttps://greenstarsproject.org/2016/12/30/how-to-calculate-carbon-footprint-home-appliances/\n\nSumber informasi mengenai biaya standar di Jakarta:\nhttps://ekonomi.bisnis.com/read/20221001/44/1583153/simak-tarif-listrik-pln-oktober-desember-2022-ini-daftar-lengkapnya\n\nSumber informasi mengenai standar emisi co2 yang dihasilkan oleh alat elektronik: \nhttps://www.kapitalelectric.com/blog/how-much-carbon-pollution-do-your-appliances-and-electronics-emit/\n\n");
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
