#include <stdio.h>
#include "keyev.h"

#define TABLERO_ANCHO 45 
#define TABLERO_ALTO 10

int main(void){
	int pos=0,k_code=0;
	
	//Iniciamos la pelota
	struct str_pelota{
		int x;
		int y;
		int vel_x;
		int vel_y;
	};
	struct str_pelota pelota;
	pelota.y = 3;
	pelota.x = 36;
	pelota.vel_x = -2;
	pelota.vel_y = 1;	
	
	//Obtenemos el descriptor de fichero del teclado
	int fd = init_key_ev(); 
	while(1){
		//Recogemos la tecla pulada
		do{
		k_code = get_key_ev(fd,200000);
		}while(k_code == -1);
		
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
		
		//Movemos la pelota
		tablero[pelota.y][pelota.x]=0;
		if(pelota.x + pelota.vel_x > 44){
			int vel_real = -1*pelota.vel_x-(44-pelota.x);
			pelota.vel_x = pelota.vel_x*-1;
			pelota.x += vel_real;
		}else if(pelota.x + pelota.vel_x < 0 && pelota.y == pos){
			int vel_real = -1*pelota.vel_x-(-pelota.x);
			pelota.vel_x = pelota.vel_x*-1;
			pelota.x += vel_real;
		}else pelota.x += pelota.vel_x;
		if(pelota.y+pelota.vel_y > 9 ){
			int vel_real = -1*pelota.vel_y-(9-pelota.y);
			pelota.vel_y = pelota.vel_y*-1;
			pelota.y += vel_real;
		}else if(pelota.y+pelota.vel_y < 0){
			int vel_real = -1*pelota.vel_y-(-pelota.y);
			pelota.vel_y = pelota.vel_y*-1;
			pelota.y += vel_real;
		}else pelota.y += pelota.vel_y;
		tablero[pelota.y][pelota.x]=1;		

		//Dibujamos la pantalla
		system("clear");	
		printf("#################################################\n");
		for(int i=0; i<TABLERO_ALTO; i++){
			printf("#"); if(pos == i) printf("|"); else printf(" ");
			for(int j=0; j<TABLERO_ANCHO; j++){
				if(tablero[i][j] == 0) printf(" "); else printf("*");	
			}
			printf(" #\n");
		}
		printf("#################################################\n");
	}
}
