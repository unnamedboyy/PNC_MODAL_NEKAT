
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>

typedef char string[100];

void cekTanggal(int *cektgl, int dd, int mm, int yyyy);
void tampilMenu();

int main(int argc, char const *argv[]) {
    // Deklarasi
    int dd, mm, yyyy, cektgl=0, menu, cekMenu=0;
    string user, pass, nama;

    // Kodingan
	
    printf("\n\n Selamat datang, Master...");
    do{
        printf("\n Masukan tangggal: "); scanf("%d-%d-%d",&dd, &mm, &yyyy);
        cekTanggal(&cektgl, dd, mm, yyyy);
    } while (cektgl == 0);

    do{

        system("cls");
        if(cekMenu>=0){
            printf("\n Tangggal: %.2d-%.2d-%.4d", dd, mm, yyyy);
        }

        tampilMenu();
        printf(">>> "); scanf("%d", &menu);
        switch (menu){
            case 1:// registrasi

            if (cekMenu == 0) {

                    puts("--=== REGISTRASI ===--");
                do{  
                    printf("Username:"); fflush(stdin); gets(user);
                    if(strcmp(user,"-") == 0 || strlen(user) == 0){
                        printf("[!] username tidak boleh kosong [!] \n\n");
                    }
                }while(strcmp(user,"-") == 0 || strlen(user) == 0);

                do{  
                    printf("Password:"); fflush(stdin); gets(pass);
                    if(strcmp(pass,"-") == 0 || strlen(pass) == 0){
                        printf("[!] password tidak boleh kosong [!]");
                    } else if (strcmp(user, pass) == 0){
                        printf("[!] password tidak boleh sama dengan username [!] \n\n");
                    } else {
                    }
                }while(strcmp(pass,"-") == 0 || strlen(pass) == 0 || strcmp(user, pass) == 0);

                do{  
                    printf("Nama    :"); fflush(stdin); gets(nama);
                    if(strcmp(nama,"-") == 0 || strlen(nama) == 0){
                        printf("[!] nama tidak boleh kosong [!] \n\n");
                    } 
                }while(strcmp(nama,"-") == 0 || strlen(nama) == 0 );

                printf("[*] berhasil registrasi [*] \n\n");
                cekMenu=1;
            }
            

                break;
            
            case 2:
                /* code */
                break;

            case 3:
                /* code */
                break;

            case 4:
                /* code */
                break; 

            case 5:
                /* code */
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
    } while (cektgl == 0);

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

