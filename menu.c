#include <stdio.h>
#include "keyev.h"

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
		
		//Dibujamos la pantalla
		system("clear");	
		printf("############################\n");
		if(pos == 0) printf("|"); printf("\n"); 
		if(pos == 1) printf("|"); printf("\n"); 
		if(pos == 2) printf("|"); printf("\n"); 
		if(pos == 3) printf("|"); printf("\n"); 
		if(pos == 4) printf("|"); printf("\n"); 
		if(pos == 5) printf("|"); printf("\n"); 
		if(pos == 6) printf("|"); printf("\n"); 
		if(pos == 7) printf("|"); printf("\n"); 
		if(pos == 8) printf("|"); printf("\n"); 
		if(pos == 9) printf("|"); printf("\n"); 
		printf("############################\n");
	}
}
