//Library yang digunakan
#include <stdio.h>
#include <stdlib.h>

//Deklarasi Function
void handling(); 
void menu_utama(); 
void menu_kalkulasi();
float kalkulasi_rp_kwh();
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
	printf("\a");
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
				menu_kalkulasi(); //unfinished function
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
				system("cls");
				menu_utama();
				break;
	}
}

void menu_kalkulasi(){
//Rumus : kwh = kw x h 
//		  co2 = kwh x co2/h
//		  Rp  = kwh x Rp/kwh
typedef struct{
	char name [50];
	float kw;
	float h;
	float kwh;
	float co2_h;
	int biaya;
	int co2;
}input;

	int counter, n;
	int* biaya;
	int* co2;
	float rp_kwh;
	input *device;

	printf("CALCULATION\n\n");
	rp_kwh = kalkulasi_rp_kwh();
	system("cls");
	printf("Biaya listrik : Rp. %.2f per kwh\n\n", rp_kwh);

	printf("Jumlah Device yang akan di-input\t: ");
	scanf("%d",&n);

	device = (input *) calloc (n, sizeof(input));
	
	for(counter = 0; counter < n; counter++){
		//Input nama device atau alat elektronik
		printf("\n\nJenis device\t\t\t\t: ");
		scanf(" %[^\n]", &device[counter].name);
		printf("KW per jam\t\t\t\t: ");
		scanf("%f", &device[counter].kw);
		printf("Durasi penggunaan per hari (Jam)\t: ");
		scanf("%f", &device[counter].h);
		printf("Emisi CO2 per jam\t\t\t: ");
		scanf("%f", &device[counter].co2_h);
	} 

	printf("\nMenghitung Emisi CO2 per Jam\n");
	for(counter = 0; counter < n; counter++){
		device[counter].kwh = device[counter].kw * device[counter].h;
		device[counter].co2 = device[counter].kwh * device[counter].co2_h;
		device[counter].biaya = device[counter].kwh * rp_kwh;
		printf("Kalkulasi %s:\n",device[counter].name);
		printf("KWH\t: %.2f\n", device[counter].kwh);
		printf("CO2\t: %d gram\n", device[counter].co2);
		printf("Biaya\t: %d Rupiah\n", device[counter].biaya);
		printf("\n");
	}

	printf("\nTekan tombol apapun untuk kembali ke menu utama\n");
	system("pause");
	system("cls");
	menu_utama();
}

//function untuk menginput kalkulasi rp per kwh
float kalkulasi_rp_kwh(){
	float rp_kwh;
	int daya;
	printf("Pilih besaran daya rumah tangga anda\n");
	printf("1. 450 VA (Rp. 415/kWh)\n2. 900 VA (Rp. 605/kWh)\n3. 900 VA RTM (Rumah Tangga Mampu)(Rp. 1352/kWh)\n4. 1300-2200 VA(Rp. 1444,70/kWh)\n5. 3500+ VA(Rp. 1699,53/kWh)\nInput :");
	scanf("%d", &daya);
	switch (daya){
		case 1 :
			rp_kwh = 415;
			break;
		case 2 :
			rp_kwh = 605;
			break;
		case 3 :
			rp_kwh = 1352;
			break;
		case 4 :
			rp_kwh = 1444.70;
			break;
		case 5 :
			rp_kwh = 1699.53;
			break;
		default :
			printf("WARNING : PILIHAN TIDAK TERSEDIA\nSILAHKAN MENGULANG LAGI");
			handling();
			kalkulasi_rp_kwh();
			break;
	}
	return rp_kwh;
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
