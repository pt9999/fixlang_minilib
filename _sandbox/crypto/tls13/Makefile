FIXAUTOLINK = ../../../bin/fixautolink
FIXAUTOTEST = ../../../bin/fixautotest
LIBS = -L ../../../lib -L .

%.out: %.fix
	$(FIXAUTOLINK) build -o $@ $(LIBS) -f $< -O separated

%.run: %.fix
	$(FIXAUTOLINK) run $(LIBS) -f $< -O separated

all:

test:
	$(FIXAUTOTEST) $(LIBS) -T ./tests -k -O separated $(TESTS)

handshake_test:
	$(FIXAUTOLINK) run $(LIBS) -f $@.fix -O separated

handshake_protocol_test:
	$(FIXAUTOLINK) run $(LIBS) -f $@.fix -O separated

record_protocol_test:
	$(FIXAUTOLINK) run $(LIBS) -f $@.fix -O separated

clean:
	rm -f *.out
	rm -f .depend
	fix clean

-include .depend
