all:

build:
	$(MAKE) -C mylib build
	fix build

run: build
	LD_LIBRARY_PATH=mylib ./a.out

clean:
	$(MAKE) -C mylib clean
	fix clean
	rm -f a.out
