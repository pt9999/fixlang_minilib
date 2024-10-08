TOPDIR = ../..

GLUE_NAME = fixglue_curl
GLUE_LIB = lib$(GLUE_NAME).a

LIBS = -L . -s $(GLUE_NAME) -d curl

%.out: %.fix $(GLUE_LIB)
	$(TOPDIR)/bin/fixautolink build -o $@ -I $(TOPDIR)/lib -I . $(LIBS) -f $< -O separated
%.run: %.fix $(GLUE_LIB)
	$(TOPDIR)/bin/fixautolink run -o $@ -I $(TOPDIR)/lib -I . $(LIBS) -f $< -O separated

all: test

test: curl_test.out
	./curl_test.out

#libfixglue_curl.so: libfixglue_curl.c
#	gcc $(INCLUDE) $(LIBPATH) -lcurl -shared -fPIC -o $@ $<

%.o: %.c
	gcc $(INCLUDE) $(LIBPATH) -c -fPIC -o $@ $<
$(GLUE_LIB): libfixglue_curl.o
	ar r $@ $^

clean:
	rm -f *.out *.so *.a *.o tmp.*
	rm -f .depend
	fix clean

-include .depend
