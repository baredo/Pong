#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>

static const char *const evval[3] = {
	"RELEASED",
	"PRESSED ",
	"REPEATED"
};

int main(void){
	const char *dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
	struct input_event ev;
	ssize_t n;
	int fd;
	int pos=0;
	fd = open(dev, O_RDONLY);
	if (fd == -1) {
		fprintf(stderr, "Cannot open %s: %s.\n", dev, strerror(errno));
		return EXIT_FAILURE;
	}
	
	while (1) {
		n = read(fd, &ev, sizeof ev);
		if (n == (ssize_t)-1) {
			if (errno == EINTR)
				continue;
			else
				break;
		} else if (n != sizeof ev) {
			errno = EIO;
			break;
		}
//		if (ev.type == EV_KEY && ev.value >= 0 && ev.value <= 2)
//			printf("%s 0x%04x (%d)\n", evval[ev.value], (int)ev.code, (int)ev.code);
//		fflush(stdout);
	//	fprintf(stderr, "%s.\n", strerror(errno));
	//	system("clear");
	//	return EXIT_FAILURE;
		
		if (ev.type == EV_KEY && (ev.value == 1 || ev.value == 2)){
			system("clear");	
			if((int)ev.code == 103 && pos > 0) pos--;
			if((int)ev.code == 108 && pos < 9) pos++;
			fflush(stdout);
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
	}
}
