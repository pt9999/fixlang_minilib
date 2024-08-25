%.out: %.fix
	../../bin/fixautolink build -o $@ -I ../lib -I . -f $<

%.run: %.fix
	../../bin/fixautolink run -o $@ -I ../lib -I . -f $< -O separated

all:

libcurl_test.out: libcurl_test.c
	gcc -o $@ $< -l curl

test: libcurl_test.out
	./libcurl_test.out

clean:
	rm -f *.out
	rm -f .depend
	fix clean

-include .depend
