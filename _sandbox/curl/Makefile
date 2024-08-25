TOPDIR = ../..
LIBS = -L . -d curl

%.out: %.fix
	$(TOPDIR)/bin/fixautolink build -o $@ -I $(TOPDIR)/lib -I . $(LIBS) -f $<
%.run: %.fix
	$(TOPDIR)/bin/fixautolink run -o $@ -I $(TOPDIR)/lib -I . $(LIBS) -f $< -O separated

all:

libcurl_test.out: libcurl_test.c
	gcc -o $@ $< -l curl

libcurl_glue.so: libcurl_glue.c
	gcc $(INCLUDE) $(LIBPATH) -lcurl -shared -fPIC -o $@ $<

test: libcurl_test.out
	./libcurl_test.out

test2: curl_test1.run

clean:
	rm -f *.out *.so
	rm -f .depend
	fix clean

-include .depend
