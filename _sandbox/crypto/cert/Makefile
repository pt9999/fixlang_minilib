FIXAUTOLINK = ../../../bin/fixautolink
FIXAUTOTEST = ../../../bin/fixautotest
LIBS = -L ../../../lib -L . -L ../tls13 -L ../cert

OPT = separated
OPT_BUILD = -O $(OPT)
OPT_RUN = -O $(OPT)
OPT_TESTS = -O $(OPT)

%.out: %.fix
	$(FIXAUTOLINK) build -o $@ $(LIBS) -f $< $(OPT_BUILD)

%.run: %.fix
	$(FIXAUTOLINK) run $(LIBS) -f $< $(OPT_RUN)

all:

test:
	$(FIXAUTOTEST) $(LIBS) -T ./tests $(OPT_TESTS) $(TESTS) --keep-going

clean:
	rm -f *.out
	rm -f .depend
	fix clean

-include .depend
