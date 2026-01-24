# dwm - dynamic window manager
# See LICENSE file for copyright and license details.

include config.mk

SRC = drw.c vxwm.c util.c
OBJ = ${SRC:.c=.o}

all: vxwm

.c.o:
	${CC} -c ${CFLAGS} $<

${OBJ}: config.h modules.h config.mk

config.h:
	cp config.def.h $@

modules.h:
	cp modules.def.h $@

vxwm: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm -f vxwm ${OBJ} dwm-${VERSION}.tar.gz

dist: clean
	mkdir -p dwm-${VERSION}
	cp -R LICENSE Makefile README config.def.h config.mk\
		dwm.1 drw.h util.h ${SRC} dwm.png transient.c dwm-${VERSION}
	tar -cf dwm-${VERSION}.tar dwm-${VERSION}
	gzip dwm-${VERSION}.tar
	rm -rf dwm-${VERSION}

install: all
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f vxwm ${DESTDIR}${PREFIX}/bin
	cp -f rvx ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/vxwm
	chmod 755 ${DESTDIR}${PREFIX}/bin/rvx

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/vxwm

.PHONY: all clean dist install uninstall
