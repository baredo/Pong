#ifndef GET_KEY_EV
#define GET_KEY_EV
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>
#include <sys/select.h>

int init_key_ev();
int get_key_ev();

#endif
