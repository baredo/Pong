#include <stdio.h>
#include "keyev.h"

#define TABLERO_ANCHO 25
#define TABLERO_ALTO 10

int main(void){
	int pos=0,k_code=0;
	//Obtenemos el descriptor de fichero del teclado
	int fd = init_key_ev(); 
	while(1){
		//Recogemos la tecla pulada
		k_code = get_key_ev(fd,5000);
		//Comprobamos las teclas
		if(k_code == 103 && pos > 0) pos--;
		if(k_code == 108 && pos < 9) pos++;
		if(k_code == 1) break;	
		
		//Iniciamos tablero(Por donde se movera la pelota)
		int tablero[TABLERO_ALTO][TABLERO_ANCHO];
		for(int i=0; i<TABLERO_ALTO; i++){
			for(int j=0; j<TABLERO_ANCHO; j++){
				tablero[i][j]=0;	
			}
		}
		tablero[3][16] = 1;

		//Dibujamos la pantalla provisional
		system("clear");	
		printf("##################################################\n");
		printf("#"); if(pos == 0) printf("|"); printf("\t\t\t|\t\t\t #\n"); 
		printf("#"); if(pos == 1) printf("|"); printf("\t\t\t|\t\t\t #\n"); 
		printf("#"); if(pos == 2) printf("|"); printf("\t\t\t|\t\t\t #\n"); 
		printf("#"); if(pos == 3) printf("|"); printf("\t\t\t|\t\t\t #\n"); 
		printf("#"); if(pos == 4) printf("|"); printf("\t\t\t|\t\t\t|#\n"); 
		printf("#"); if(pos == 5) printf("|"); printf("\t\t\t|\t\t\t|#\n"); 
		printf("#"); if(pos == 6) printf("|"); printf("\t\t\t|\t\t\t #\n"); 
		printf("#"); if(pos == 7) printf("|"); printf("\t\t\t|\t\t\t #\n"); 
		printf("#"); if(pos == 8) printf("|"); printf("\t\t\t|\t\t\t #\n"); 
		printf("#"); if(pos == 9) printf("|"); printf("\t\t\t|\t\t\t #\n"); 
		printf("##################################################\n");
	}
}
