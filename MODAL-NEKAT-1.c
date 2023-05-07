
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
typedef char string[100];

void cekTanggal(int *cektgl, int dd, int mm, int yyyy);
void tampilMenu();
void kapasitasBaterai(int *Kapasitas, int *levelBaterai);
void aktifkanMesin(int *pakaiMesin, int *levelBaterai, int kapasitas, int *useTime, int *dd, int *mm, int *yyyy);
void isiBaterai(int *dayaBaterai, int *levelBaterai, int *kapasitas, int *tempBaterai);
void SetColor(unsigned short);
void tampilBaterai( char *ascii, int *kapasitas, int *levelBaterai);

int main(int argc, char const *argv[]) {
    // Deklarasi
    int dd, mm, yyyy, cektgl=0, cekMenu=0, id=100;
    string user, pass, nama, temp1, temp2;
    int kapasitas, levelBaterai, pakaiMesin, useTime=0, dayaBaterai, tempBaterai;
	char menu, ascii = 0;
    
    // Kodingan
	
    printf("\n\n Selamat datang, Master...");
    do{
        printf("\n Masukan tangggal: "); scanf("%d-%d-%d",&dd, &mm, &yyyy);
        cekTanggal(&cektgl, dd, mm, yyyy);
    } while (cektgl == 0);

    do{

        system("cls");
        if(cekMenu >= 0){
            printf("\n Tangggal	: %.2d-%.2d-%.4d", dd, mm, yyyy);
        }
        
        if (cekMenu >=2){
            printf("\n Id     	: %s_%d \n", nama, id);
        }

        if (cekMenu >= 3){
            printf(" Battery Level  : %d", levelBaterai);
            printf("\n Max Bar   	: %d", kapasitas);
            printf("\n Used Time    	: %d ", useTime);
        }

        tampilMenu();
        printf(">>> ");
        
        menu = getch();
        if (menu == 27){
        	return 0;
		}
		putchar(menu);
		printf(" \n");
		
        switch (menu){
            case '1':// registrasi
            	
                if (cekMenu == 0) {

                    puts("\n\n--=== REGISTRASI ===--");
                    do{  
                        printf(" Username	: "); fflush(stdin); gets(user);
                        if(strcmp(user,"-") == 0 || strlen(user) == 0){
                            printf("[!] username tidak boleh kosong [!] \n\n");
                        }
                    }while(strcmp(user,"-") == 0 || strlen(user) == 0);

                    do{  
                        printf(" Password	: "); fflush(stdin); gets(pass);
                        if(strcmp(pass,"-") == 0 || strlen(pass) == 0){
                            printf("[!] password tidak boleh kosong [!]\n");
                        } else if (strcmp(user, pass) == 0){
                            printf("[!] password tidak boleh sama dengan username [!] \n\n");
                        } else {
                        }
                    }while(strcmp(pass,"-") == 0 || strlen(pass) == 0 || strcmp(user, pass) == 0);

                    do{  
                        printf(" Nama    	: "); fflush(stdin); gets(nama);
                        if(strcmp(nama,"-") == 0 || strlen(nama) == 0){
                            printf("[!] nama tidak boleh kosong [!] \n\n");
                        } 
                    }while(strcmp(nama,"-") == 0 || strlen(nama) == 0 );

                    printf(" Id anda  	: %s_%d \n\n", nama, id);
                    printf("[*] berhasil registrasi [*]");
                    cekMenu=1;
                } else {
                    printf("[!] sudah registrasi [!] \n\n");
                }
                
                break;
            
            case '2':
                
                if (cekMenu == 1) {

                puts("\n\n--=== HALAMAN LOGIN ===--");
                printf("Username	: "); fflush(stdin); gets(temp1);
                printf("Password	: "); fflush(stdin); gets(temp2);
                    if(strcmp(user, temp1) != 0 || strcmp(pass, temp2) != 0){
                        printf("[!] username atau password salah [!] \n\n");
                    } else {
                        printf("\n[*] berhasil login [*] \n\n");
                        cekMenu=2;
                    }
                } else if (cekMenu==0){
                    printf("[!] belum registrasi [!] \n\n");
                } else {
                    printf("[!] sudah login [!] \n\n");
                }
                
                break;
                
            case '3':
            	
                if (cekMenu == 2) {
                    kapasitasBaterai(&kapasitas, &levelBaterai);
                    cekMenu = 3;
                } else if (cekMenu == 0){
                    printf("[!] belum registrasi [!] \n\n");
                } else if (cekMenu == 1){
                    printf("[!] belum login [!] \n\n");
                } else if (cekMenu == 3){
                    printf ("[!] sudah inisiasi baterai [!]");
                }
                
                break;

            case '4':
            	
                if (cekMenu == 3) {

                    aktifkanMesin(&pakaiMesin, &levelBaterai, kapasitas, &useTime, &dd, &mm, &yyyy );

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

            case '5':
            	
                if (cekMenu == 3) {
                    isiBaterai(&dayaBaterai, &levelBaterai, &kapasitas, &tempBaterai);
                } else if (cekMenu == 0){
                    printf("[!] belum registrasi [!] \n\n");
                } else if (cekMenu == 1){
                    printf("[!] belum login [!] \n\n");
                } else if (cekMenu == 2){
                    printf ("[!] Silahkan Inisialisasi Kapasitas Baterai Dahulu [!]");
                }
                break;  

            case '6':
            	
            	if (cekMenu == 3) {

                    tampilBaterai( &ascii, &kapasitas, &levelBaterai);
                    
                } else if (cekMenu == 0){
                    printf("[!] belum registrasi [!] \n\n");
                } else if (cekMenu == 1){
                    printf("[!] belum login [!] \n\n");
                } else if (cekMenu == 2){
                printf("[!] Silahkan Inisialisasi Kapasitas Baterai Dahulu [!] \n\n");
				}
                break;

            case '7':
            	
                if (cekMenu == 2 || cekMenu == 3) {
                    cekMenu = 0;
                    useTime = 0;
                    printf("\n\t[!] Berhasil Reset [!]");
                    id++;
                } else if (cekMenu == 0){
                    printf("[!] belum registrasi [!] \n\n");
                } else if (cekMenu == 1){
                    printf("[!] belum login [!] \n\n");
                }
                break;

            case '0':
                /* code */
                break;

            default:
            	printf("\n\n[!] Pilihan menu tidak ada ^_^");
                break;
        }getch();
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
}

void aktifkanMesin(int *pakaiMesin, int *levelBaterai, int kapasitas, int *useTime, int *dd, int *mm, int *yyyy){
    int temp;
    printf("\n\n Masukan Banyak Waktu yang Mau dipakai:"); scanf("%d", &temp);
    *pakaiMesin = temp;
    
    if(*pakaiMesin <= *levelBaterai){
        *levelBaterai = (*levelBaterai) - (*pakaiMesin);
        *useTime = (*useTime) + (*pakaiMesin);
        printf(" [*] Berhasil menyalakan mesin dengan %d daya [*]", *pakaiMesin);

        if(*useTime>24){
            *useTime = (*useTime)-24; //reset
            *dd = (*dd) + 1;
            
            if (*yyyy % 4 == 0 && *mm == 2 && *dd > 29 ){
				*dd = 1, *mm = (*mm +1);	
			} else if (*yyyy % 4 != 0 && *mm == 2 && *dd > 28 ) {
				*dd = 1, *mm = (*mm +1);
			} else if (*mm == 4 || *mm == 6 || *mm == 9 || *mm == 11){
				if (*dd > 30 ) {
				*dd = 1, *mm = (*mm +1);
				}				
			} else if (*mm == 12){
	            if (*dd > 31 ) {
				*dd = 1, *mm = 1, *yyyy = (*yyyy + 1);
				}	
			}
        }
        
    } else if (*pakaiMesin >= *levelBaterai){
        printf(" [!] WARNING, daya saat ini tidak mencukupi [!]");
    } else if (*pakaiMesin <= 0 ){
        printf(" [!] Waktu tidak boleh kurang dari sama dengan nol [!]");
    } else {
        printf(" [!] Inputan tidak valid [!]");
    }
}
void isiBaterai(int *dayaBaterai, int *levelBaterai, int *kapasitas, int *tempBaterai){
    printf("\nInput jumlah daya yang ingin diinput : "); scanf("%d", dayaBaterai);

    if((*levelBaterai) + (*dayaBaterai) > (*kapasitas)){
        printf("\n[!] Jumlah daya melebihi kapasitas [!]");
    }else if(*dayaBaterai < 0){
        printf("\n[!] Jumlah daya tidak boleh negatif [!]");
    }else{
    	(*levelBaterai) = (*dayaBaterai) + (*levelBaterai);
    	printf("\n[*] Berhasil Tambah Daya [*]");
	}
}

void SetColor(unsigned short color) {
    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleOutput,color);
}

void tampilBaterai( char *ascii, int *kapasitas, int *levelBaterai){
// itung baterai 
    int persen;
    int a, b;
    persen = ((*levelBaterai)*100) / *kapasitas;

    printf("\n Kapasitas Baterai Saat ini Adalah : %d %c \n\n", persen, ascii+37);
    for (a = 1 ; a <= (5) ; a++){
		for (b = 1 ; b <= (*kapasitas+2) ; b++){
				
			if ( ( (a == 1) && (b > 1) && (b < *kapasitas + 2) ) || ( (a == (5)) && (b > 1) && (b < *kapasitas +2 ) ) ){
				SetColor(7);
				printf("******");			
			} else if ( ((b == 1) && (a == 1)) || ((b == 1) && (a == (5))) ){
				SetColor(7);
				printf("**");			 
			} else if ( ((b == *kapasitas + 2) && (a == 1)) || ((b == *kapasitas + 2) && (a == (5))) ){
				SetColor(7);
				printf("* ");			 
			} else if ( b == 1|| b == (*kapasitas + 2)){
				SetColor(7);
				printf("**");
			}else {
				if (b <= *levelBaterai+1){
                                
                    if (persen <= 20){
                        SetColor(12);
                    } else if (persen <= 60){
                        SetColor(14);
                    } else {
                        SetColor(10);
                    }
                                
					if(a==2) {
				        printf("  ^^^^");
					} else if (a==3){
						printf(" ^^^^ ");
					} else if (a==4){
						printf("^^^^  ");
					} else {
						printf("");
					}
				} else {
					printf("      ");
				}	
			}
		}
		printf("\n");
	}
	SetColor(7);
}


