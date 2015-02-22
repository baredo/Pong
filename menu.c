#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>

int main(void){
	int pos=0;
	printf("%d",get_key_ev());
	system("clear");	
	if(get_key_ev() == 103 && pos > 0) pos--;
	if(get_key_ev() == 108 && pos < 9) pos++;
	printf("###########################\n");
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
	printf("###########################\n");
}
