TOPDIR = ../..
LIBS = -L . -d curl_glue -d curl

%.out: %.fix
	$(TOPDIR)/bin/fixautolink build -o $@ -I $(TOPDIR)/lib -I . $(LIBS) -f $< -O separated
%.run: %.fix
	$(TOPDIR)/bin/fixautolink run -o $@ -I $(TOPDIR)/lib -I . $(LIBS) -f $< -O separated

all: test

test: libcurl_glue.so curl_test.out
	LD_LIBRARY_PATH=. MALLOC_PERTURB_=1 ./curl_test.out

libcurl_glue.so: libcurl_glue.c
	gcc $(INCLUDE) $(LIBPATH) -lcurl -shared -fPIC -o $@ $<

clean:
	rm -f *.out *.so tmp.*
	rm -f .depend
	fix clean

-include .depend
