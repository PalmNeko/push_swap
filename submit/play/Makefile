

CFLAG += -I.

LIBS = libstr.a libwrap.a

main.out: $(LIBS)
	cc -o $@ main.c -L. -l str -l wrap

libstr.a: libstr.o
	ar rcs $@ $^

libwrap.a: libwrap.o
	ar rcs $@ $^
