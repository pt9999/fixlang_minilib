TOPDIR = ../..
FIXAUTOLINK = $(TOPDIR)/bin/fixautolink
FIXAUTOTEST = $(TOPDIR)/bin/fixautotest
LIBS = -I $(TOPDIR)/lib -I .

OPT = separated
OPT_BUILD = -O $(OPT)
OPT_RUN = -O $(OPT)

%.out: %.fix
	$(FIXAUTOLINK) build -o $@ $(LIBS) -f $< $(OPT_BUILD)

%.run: %.fix
	$(FIXAUTOLINK) run $(LIBS) -f $< $(OPT_RUN)

all::

clean::
	rm -f *.out
	rm -f .depend
	fix clean

ndarray_calc.run: ndarray_calc.fix
	$(FIXAUTOLINK) run $(LIBS) -f $< $(OPT_RUN) -d readline


