FIXAUTOLINK = ../../../bin/fixautolink
LIBS = -L ../../../lib -L .

%.out: %.fix
	$(FIXAUTOLINK) build -o $@ $(LIBS) -f $<

%.run: %.fix
	$(FIXAUTOLINK) run $(LIBS) -f $<

all:

handshake_protocol_test:
	$(FIXAUTOLINK) run $(LIBS) -f handshake_protocol_test.fix -O separated

record_protocol_test:
	$(FIXAUTOLINK) run $(LIBS) -f record_protocol_test.fix -O separated

clean:
	rm -f *.out
	rm -f .depend
	fix clean

-include .depend
