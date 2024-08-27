TOPDIR = ../..
LIBS = -L . -d fixglue_curl -d curl

%.out: %.fix
	$(TOPDIR)/bin/fixautolink build -o $@ -I $(TOPDIR)/lib -I . $(LIBS) -f $< -O separated
%.run: %.fix
	$(TOPDIR)/bin/fixautolink run -o $@ -I $(TOPDIR)/lib -I . $(LIBS) -f $< -O separated

all: test

test: libfixglue_curl.so curl_test.out
	LD_LIBRARY_PATH=. MALLOC_PERTURB_=1 ./curl_test.out

libfixglue_curl.so: libfixglue_curl.c
	gcc $(INCLUDE) $(LIBPATH) -lcurl -shared -fPIC -o $@ $<

#%.o: %.c
#	gcc $(INCLUDE) $(LIBPATH) -lcurl -c -o $@ $<
#libfixglue_curl.a: libfixglue_curl.o
#	ar r $@ $^

clean:
	rm -f *.out *.so tmp.*
	rm -f .depend
	fix clean

-include .depend
