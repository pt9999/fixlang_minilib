FIXAUTOLINK = ../../../bin/fixautolink
FIXAUTOTEST = ../../../bin/fixautotest
LIBS = -L ../../../lib -L . -L ../cert

OPT_BUILD = -O separated
OPT_RUN = -O separated
OPT_TESTS = -O separated

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
