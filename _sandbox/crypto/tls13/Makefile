FIXAUTOLINK = ../../../bin/fixautolink
LIBS = -L ../../../lib -L .

%.out: %.fix
	$(FIXAUTOLINK) build -o $@ $(LIBS) -f $<

all:

tls13_test1:
	$(FIXAUTOLINK) run $(LIBS) -f tls13_test1.fix -O separated

clean:
	rm -f *.out
	rm -f .depend
	fix clean

-include .depend
