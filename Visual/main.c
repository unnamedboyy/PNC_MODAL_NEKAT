#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void SetColor(unsigned short);

int main(int argc, char *argv[]) {
	
	
	int a,b,c;
	int lebar= 3, panjang= 20;
	int baterai=1;

	for (a = 1 ; a <= (lebar+2) ; a++){
			for (b = 1 ; b <= (panjang+2) ; b++){
				
				if ( ( (a == 1) && (b > 1) && (b < panjang+2) ) || ( (a == (lebar+2)) && (b > 1) && (b < panjang+2) ) ){
				 	SetColor(13);
					printf("******");			 
				} else if ( ((b == 1) && (a == 1)) || ((b == 1) && (a == (lebar+2))) ){
				 	SetColor(13);
					printf("**");			 
				} else if ( ((b == panjang+2) && (a == 1)) || ((b == panjang+2) && (a == (lebar+2))) ){
				 	SetColor(13);
					printf("* ");			 
				} else if ( b == 1|| b == (panjang+2)){
				 	SetColor(13);
					printf("**");
				}   else {
					if (b<=baterai+1){
						if(a==2) {
							SetColor(10);
							printf("  ^^^^");
						} else if (a==3){
							SetColor(10);
							printf(" ^^^^ ");
						} else if (a==4){
							SetColor(10);
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
	} getch();
	
	return 0;
}

void SetColor(unsigned short color) {
HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsoleOutput,color);
}
