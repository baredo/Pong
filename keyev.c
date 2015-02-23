#include "keyev.h"

int init_key_ev(){
	char *dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
	int fd = open(dev, O_RDONLY);
	if (fd == -1) {
		fprintf(stderr, "Cannot open %s: %s.\n", dev, strerror(errno));
		return EXIT_FAILURE;
	} return fd;
}

int get_key_ev(int fd,int t_out){
	struct input_event ev;
	ssize_t n;
	int pos=0;

	//Iniciamos parametros de select	
	fd_set read_fds;
	FD_SET(fd, &read_fds);
	
	//Ponemos el maximo tiempo de espera
	struct timeval timeout;
	timeout.tv_sec = 0;
	timeout.tv_usec = t_out;
	
	// Select comprueba cuando el teclado esta listo para ser leido(hay una entrada de datos)
	// Una vez hecho esto leemos esa entrada con read
	if (select(fd + 1, &read_fds, NULL, NULL, &timeout) == 1){
		n = read(fd, &ev, sizeof ev);
		if (ev.type == EV_KEY && ev.value == 1){
			usleep(t_out/2);
			return (int)ev.code;
		}
		return -1;
	}else{
		return 0;
	}
}


