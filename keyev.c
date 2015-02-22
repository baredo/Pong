#include "keyev.h"
int get_key_ev(){
	char *dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
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
			if (errno == EINTR) continue; else break;
		} else if (n != sizeof ev) {
			errno = EIO;
			break;
		}
		//fprintf(stderr, "%s.\n", strerror(errno));
		if (ev.type == EV_KEY){
			fflush(stdout);
			return (int)ev.code;
		}
	}
}
