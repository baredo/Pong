CFLAGS=-std=c99
OBJETOS=menu.o keyev.o
FUENTES=menu.c keyev.c

pong : $(OBJETOS) 
	gcc $(OBJETOS) -o pong 

depend:
	makedepend $(FUENTES)
# DO NOT DELETE

menu.o: /usr/include/stdio.h /usr/include/features.h
menu.o: /usr/include/stdc-predef.h /usr/include/libio.h
menu.o: /usr/include/_G_config.h /usr/include/wchar.h keyev.h
menu.o: /usr/include/stdlib.h /usr/include/alloca.h /usr/include/unistd.h
menu.o: /usr/include/getopt.h /usr/include/fcntl.h /usr/include/time.h
menu.o: /usr/include/errno.h /usr/include/linux/input.h
menu.o: /usr/include/linux/types.h /usr/include/linux/posix_types.h
menu.o: /usr/include/linux/stddef.h /usr/include/string.h
menu.o: /usr/include/xlocale.h
keyev.o: keyev.h /usr/include/stdlib.h /usr/include/features.h
keyev.o: /usr/include/stdc-predef.h /usr/include/alloca.h
keyev.o: /usr/include/unistd.h /usr/include/getopt.h /usr/include/fcntl.h
keyev.o: /usr/include/time.h /usr/include/errno.h /usr/include/linux/input.h
keyev.o: /usr/include/linux/types.h /usr/include/linux/posix_types.h
keyev.o: /usr/include/linux/stddef.h /usr/include/string.h
keyev.o: /usr/include/xlocale.h /usr/include/stdio.h /usr/include/libio.h
keyev.o: /usr/include/_G_config.h /usr/include/wchar.h
