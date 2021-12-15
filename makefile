all:
	gcc main.c glad_gl.c -Ofast -lglfw -lm -o snowling

install:
	cp snowling $(DESTDIR)

uninstall:
	rm $(DESTDIR)/snowling

clean:
	rm snowling