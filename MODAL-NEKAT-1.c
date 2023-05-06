
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>

typedef char string[100];

void cekTanggal(int *cektgl, int dd, int mm, int yyyy);
void tampilMenu();
void kapasitasBaterai(int *Kapasitas, int *levelBaterai);
void aktifkanMesin(int *pakaiMesin, int *levelBaterai, int kapasitas, int *useTime);

int main(int argc, char const *argv[]) {
    // Deklarasi
    int dd, mm, yyyy, cektgl=0, menu, cekMenu=0, id=100;
    string user, pass, nama, temp1, temp2;
    int kapasitas, levelBaterai, pakaiMesin, useTime;

    // Kodingan
	
    printf("\n\n Selamat datang, Master...");
    do{
        printf("\n Masukan tangggal: "); scanf("%d-%d-%d",&dd, &mm, &yyyy);
        cekTanggal(&cektgl, dd, mm, yyyy);
    } while (cektgl == 0);

    do{

        system("cls");
        if(cekMenu >= 0){
            printf("\n Tangggal: %.2d-%.2d-%.4d", dd, mm, yyyy);
        }
        
        if (cekMenu >=2){
            printf("\n Id     : %s_%d \n\n", nama, id++);
        }

        if (cekMenu >= 3){
            printf(" Battery Level  : %d", levelBaterai);
            printf("\n Max Bar   : %d", kapasitas);
            printf("\n Used Time    : ");
        }

        tampilMenu();
        printf(">>> "); scanf("%d", &menu);
        switch (menu){
            case 1:// registrasi

                if (cekMenu == 0) {

                    puts("--=== REGISTRASI ===--");
                    do{  
                        printf(" Username:"); fflush(stdin); gets(user);
                        if(strcmp(user,"-") == 0 || strlen(user) == 0){
                            printf("[!] username tidak boleh kosong [!] \n\n");
                        }
                    }while(strcmp(user,"-") == 0 || strlen(user) == 0);

                    do{  
                        printf(" Password:"); fflush(stdin); gets(pass);
                        if(strcmp(pass,"-") == 0 || strlen(pass) == 0){
                            printf("[!] password tidak boleh kosong [!]");
                        } else if (strcmp(user, pass) == 0){
                            printf("[!] password tidak boleh sama dengan username [!] \n\n");
                        } else {
                        }
                    }while(strcmp(pass,"-") == 0 || strlen(pass) == 0 || strcmp(user, pass) == 0);

                    do{  
                        printf(" Nama    :"); fflush(stdin); gets(nama);
                        if(strcmp(nama,"-") == 0 || strlen(nama) == 0){
                            printf("[!] nama tidak boleh kosong [!] \n\n");
                        } 
                    }while(strcmp(nama,"-") == 0 || strlen(nama) == 0 );

                    printf(" Id anda  : %s_%d \n\n", nama, id++);
                    printf("[*] berhasil registrasi [*]");
                    cekMenu=1;
                } else {
                    printf("[!] sudah registrasi [!] \n\n");
                }
                getch();
                break;
            
            case 2:
                
                if (cekMenu == 1) {

                puts("--=== HALAMAN LOGIN ===--");
                printf("Username:"); fflush(stdin); gets(temp1);
                printf("Password:"); fflush(stdin); gets(temp2);
                    if(strcmp(user, temp1) != 0 || strcmp(pass, temp2) != 0){
                        printf("[!] username atau password salah [!] \n\n");
                    } else {
                        printf("[*] berhasil login [*] \n\n");
                        cekMenu=2;
                    }
                } else if (cekMenu==0){
                    printf("[!] belum registrasi [!] \n\n");
                } else {
                    printf("[!] sudah login [!] \n\n");
                }

                getch();
                break;

            case 3:
                if (cekMenu == 2) {
                    kapasitasBaterai(&kapasitas, &levelBaterai);
                    cekMenu == 3;
                } else if (cekMenu == 0){
                    printf("[!] belum registrasi [!] \n\n");
                } else if (cekMenu == 1){
                    printf("[!] belum login [!] \n\n");
                } else if (cekMenu == 3){
                    printf ("[!] sudah inisiasi baterai [!]");
                }
            
                break;

            case 4:
                if (cekMenu == 3) {

                    aktifkanMesin(&pakaiMesin, &levelBaterai, kapasitas, &useTime);

                } else if (cekMenu == 0){
                    printf("[!] belum registrasi [!] \n\n");
                } else if (cekMenu == 1){
                    printf("[!] belum login [!] \n\n");
                } else if (cekMenu == 2){
                    printf("[!] belum inisiasi [!] \n\n");
                } else {
                    printf ("[!] sudah inisiasi baterai [!]");
                }

                
                break; 

            case 5:
                if (cekMenu == 2) {
                    kapasitasBaterai(&kapasitas, &levelBaterai);
                    cekMenu == 3;
                } else if (cekMenu == 0){
                    printf("[!] belum registrasi [!] \n\n");
                } else if (cekMenu == 1){
                    printf("[!] belum login [!] \n\n");
                } else if (cekMenu == 2){
                    printf ("[!] Silahkan Inisialisasi Kapasitas Baterai Dahulu [!]");
                }
                break;  

            case 6:
                /* code */
                break;

            case 7:
                /* code */
                break;

            case 0:
                /* code */
                break;

            default:
                break;
        }
    } while (menu != 0);

    return 0;
}

/*-------------------------------------------------------------------------------------------------------------------------------------*/

void cekTanggal(int *cektgl, int dd, int mm, int yyyy){

        if (dd > 31 || mm >12 || dd <=0 || mm <=0 || yyyy <=0){
			printf("\n [!] Maaf, inputan tanggal tidak valid [!]");	
		} else if (yyyy % 4 == 0 && mm == 2 && dd > 29 ){
			printf("\n [!] Maaf, inputan tanggal tidak valid [!]");	
		} else if (yyyy % 4 != 0 && mm == 2 && dd > 28 ) {
			printf("\n [!] Maaf, inputan tanggal tidak valid [!]");
		} else if (mm == 4 || mm == 6 || mm == 9 || mm == 11){
			if (dd > 30 ) {
			printf("\n [!] Maaf, inputan tanggal tidak valid [!]");
			} else {
                printf("\n [*] Input berhasil [*]");
                *cektgl = 1;
			}				
		} else {
            printf("\n [*] Input berhasil [*]");
            *cektgl = 1;
		}
}

void tampilMenu(){

    puts("\n\n --=== ANJAY MESIN WAKTU NIH BOS ===--");
    puts("[1] Register");
    puts("[2] Login");
    puts("[3] Inisialisasi Kapasitas Baterai");
    puts("[4] Aktifkan Mesin");
    puts("[5] Isi daya");
    puts("[6] Tampilkan Indikot Baterai");
    puts("[7] Reset Data");
    puts("[ESC] Keluar dari Program");
}

void kapasitasBaterai(int *kapasitas, int *levelBaterai){
    printf("Input Kapasitas Baterai (1-30) : "); scanf("%d", &*kapasitas);

    while(*kapasitas < 1 || *kapasitas > 30){
        if(*kapasitas < 1){
            printf("\n[!] Minimal Terdapat 1 Bar [!]\n");
            printf("Input Kapasitas Baterai (1-30) : "); scanf("%d", &*kapasitas);
        }else{
            printf("\n[!] Maximal Terdapat 30 Bar [!]\n");
            printf("Input Kapasitas Baterai (1-30) : "); scanf("%d", &*kapasitas);
        }
    }

    srand(time(NULL));
    *levelBaterai = rand() % (*kapasitas) + 1;

    printf("\n[*] Level Baterai : %d", *levelBaterai);
    printf("\n[*] Inisialisasi Kapasitas Berhasil [*]");
    getch();
}

void aktifkanMesin(int *pakaiMesin, int *levelBaterai, int kapasitas, int *useTime){
    int temp;
    printf(" Masukan Banyak Waktu yang Mau dipakai:"); scanf("%d", temp);
    *pakaiMesin = temp;
    
    if(*pakaiMesin <= *levelBaterai){
        *levelBaterai = (*levelBaterai) - (*pakaiMesin);
        *useTime = (*useTime) - (*pakaiMesin);
        printf(" [*] Berhasil menyakan mesin dengan &d daya [*]", *pakaiMesin); 
    } else if (*pakaiMesin >= *levelBaterai){
        printf(" [!] WARNING, daya saat ini tidak mencukupi [!]");
    } else if (*pakaiMesin <= 0 ){
        printf(" [!] Waktu tidak boleh kurang dari sama dengan nol [!]");
    } else {
        printf(" [!] Inputan tidak valid [!]");
    }
}