TOPDIR = ../..
LIBS = -L . -d curl

%.out: %.fix
	$(TOPDIR)/bin/fixautolink build -o $@ -I $(TOPDIR)/lib -I . $(LIBS) -f $<
%.run: %.fix
	$(TOPDIR)/bin/fixautolink run -o $@ -I $(TOPDIR)/lib -I . $(LIBS) -f $< -O separated

all:

libcurl_test.out: libcurl_test.c
	gcc -o $@ $< -l curl

test: libcurl_test.out
	./libcurl_test.out

test2: curl_test1.run

clean:
	rm -f *.out
	rm -f .depend
	fix clean

-include .depend
