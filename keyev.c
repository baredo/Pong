#include "keyev.h"

int init_key_ev(){
	char *dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
	int fd = open(dev, O_RDONLY);
	if (fd == -1) {
		fprintf(stderr, "Cannot open %s: %s.\n", dev, strerror(errno));
		return EXIT_FAILURE;
	} return fd;
}

int get_key_ev(int fd){

	struct input_event ev;
	ssize_t n;
	int pos=0;
		
	fd_set read_fds;
	FD_SET(fd, &read_fds);
	
	//Set timeout to 1.0 seconds
	struct timeval timeout;
	timeout.tv_sec = 5;
	timeout.tv_usec = 0;
	
	// Wait for input to become ready or until the time out; the first parameter is
	// 1 more than the largest file descriptor in any of the sets
	if (select(fd + 1, &read_fds, NULL, NULL, &timeout) == 1){
		n = read(fd, &ev, sizeof ev);
		if (ev.type == EV_KEY && ev.value >= 1 && ev.value <= 2)return (int)ev.code;
		printf("Tipo: %d,\tValor: %d,\tCodigo: %d\n",(int)ev.type,(int)ev.value,(int)ev.code);
	}else{
	
	}
/*
if (n == (ssize_t)-1) {
if (errno == EINTR) continue; else break;
} else if (n != sizeof ev) {
errno = EIO;
break;
*/
//fprintf(stderr, "%s.\n", strerror(errno));
//if (ev.type == EV_KEY){
//fflush(stdout);
//return (int)ev.code;
}


