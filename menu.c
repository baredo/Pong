#include <stdio.h>
#include "keyev.h"

#define TABLERO_ANCHO 45 
#define TABLERO_ALTO 10
#define START_TIME_OUT 200000

struct str_pelota{
	int x;
	int y;
	int vel_x;
	int vel_y;
};

int main(void){
	int cont_jugador=0, puntuacion=0;
	//Iniciamos posicion de la barra del jugador
	short pos[TABLERO_ALTO];
	for(int i=0; i<TABLERO_ALTO; i++){
		pos[i]=0;
	}
	pos[3]=1;
		
	//Iniciamos la pelota
	struct str_pelota pelota;
	pelota.y = 3;
	pelota.x = 36;
	pelota.vel_x = -2;
	pelota.vel_y = 1;	
	
	//Obtenemos el descriptor de fichero del teclado
	int k_code=0;
	int fd = init_key_ev(); 
	int time_out = START_TIME_OUT;
	int time_out_vel = 1000;

	while(1){
		//Recogemos la tecla pulada
		do{
			k_code = get_key_ev(fd,time_out);
		}while(k_code == -1); //Recogera el evento tecla mientras que salga mediante una tecla k_code > 0, o se agote el tiempo k_code = 0;
		
		//Actualizamos el timeout //El juego cada vez ira mas rapido
		if(time_out >50000) time_out -= time_out_vel;
		//Actualizamos puntuacion
		puntuacion += (START_TIME_OUT-time_out)/1000;

		//Comprobamos las teclas
		//Subir barra
		if(k_code == 103 && !pos[0]){
			for(int i=0; i<TABLERO_ALTO-1;i++){
				if(pos[i+1]){
					pos[i+1]=0;
					pos[i]=1;
				}
			}
		} 
		//Bajar barra
		if(k_code == 108 && !pos[TABLERO_ALTO-1]){
			for(int i=TABLERO_ALTO-1; i>0; i--){
				if(pos[i-1]){
					pos[i-1]=0;
					pos[i]=1;
				}
			}
		}
		//Salir del juego
		if(k_code == 1) break;	
		
		//Iniciamos tablero(Por donde se movera la pelota)
		int tablero[TABLERO_ALTO][TABLERO_ANCHO];
		for(int i=0; i<TABLERO_ALTO; i++){
			for(int j=0; j<TABLERO_ANCHO; j++){
				tablero[i][j]=0;	
			}
		}
		
		//Movemos la pelota
		//Borramos la posicion de la pelota
		tablero[pelota.y][pelota.x]=0;
		
		//Cauclamos su posicion en x
		if(pelota.x + pelota.vel_x > 44){
			int vel_real = -1*pelota.vel_x-(44-pelota.x);//La pelota rebota si llega a la pared del contrario
			pelota.vel_x = pelota.vel_x*-1;
			pelota.x += vel_real;
		}else if(pelota.x + pelota.vel_x < 0 && pos[pelota.y]){//La pelota rebota si toca con la barra del jugador
			int vel_real = -1*pelota.vel_x-(-pelota.x);
			pelota.vel_x = pelota.vel_x*-1;
			pelota.x += vel_real;
		}else if(pelota.x + pelota.vel_x < 0 && ((pos[pelota.y+1] && pelota.vel_y > 0) || (pos[pelota.y-1] && pelota.vel_y < 0))){
			//La pelota rebota si toca la esquina superior/inferior de la barra
			int vel_real = -1*pelota.vel_x-(-pelota.x);
			pelota.vel_x = pelota.vel_x*-1;
			pelota.x += vel_real;
			pelota.vel_y = pelota.vel_y*-1;
		}else if(pelota.x + pelota.vel_x < 0){//La pelota ha entrado en el marcador del jugador
			cont_jugador++;
			time_out = START_TIME_OUT;
			pelota.x = TABLERO_ANCHO/2;
			pelota.vel_x *= -1;	
		}else pelota.x += pelota.vel_x;
		
		//Calculamos su posicion en y
		if(pelota.y+pelota.vel_y > 9 ){
			int vel_real = -1*pelota.vel_y-(9-pelota.y);
			pelota.vel_y = pelota.vel_y*-1;
			pelota.y += vel_real;
		}else if(pelota.y+pelota.vel_y < 0){
			int vel_real = -1*pelota.vel_y-(-pelota.y);
			pelota.vel_y = pelota.vel_y*-1;
			pelota.y += vel_real;
		}else pelota.y += pelota.vel_y;
		
		//Guardamos su posicion
		tablero[pelota.y][pelota.x]=1;		

		//Dibujamos la pantalla
		system("clear");	
		printf("#################################################\n");
		for(int i=0; i<TABLERO_ALTO; i++){
			printf("#"); if(pos[i]) printf("|"); else printf(" ");
			for(int j=0; j<TABLERO_ANCHO; j++){
				if(tablero[i][j] == 0) printf(" "); else printf("*");	
			}
			printf(" #\n");
		}
		printf("#################################################\n");
		printf("Fallos: %d    Velocidad: %d    Puntos: %d\n",cont_jugador,(START_TIME_OUT-time_out)/1000,puntuacion);
	}
}
