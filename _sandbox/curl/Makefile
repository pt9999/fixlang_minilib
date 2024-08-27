TOPDIR = ../..
LIBS = -L . -d curl_glue -d curl

%.out: %.fix
	$(TOPDIR)/bin/fixautolink build -o $@ -I $(TOPDIR)/lib -I . $(LIBS) -f $< -O separated
%.run: %.fix
	$(TOPDIR)/bin/fixautolink run -o $@ -I $(TOPDIR)/lib -I . $(LIBS) -f $< -O separated

all:

libcurl_test.out: libcurl_test.c
	gcc -o $@ $< -l curl

libcurl_glue.so: libcurl_glue.c
	gcc $(INCLUDE) $(LIBPATH) -lcurl -shared -fPIC -o $@ $<

test: libcurl_glue.so curl_test1.out
	LD_LIBRARY_PATH=. MALLOC_PERTURB_=1 ./curl_test1.out

test0: libcurl_test.out
	./libcurl_test.out

clean:
	rm -f *.out *.so
	rm -f .depend
	fix clean

-include .depend
