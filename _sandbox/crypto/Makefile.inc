#CRYPTO_DIR = .
#SUBDIRS =

TOPDIR = $(CRYPTO_DIR)/../..
FIXAUTOLINK = $(TOPDIR)/bin/fixautolink
FIXAUTOTEST = $(TOPDIR)/bin/fixautotest
LIBS = -I $(TOPDIR)/lib -I $(TOPDIR)/_sandbox/crypto

OPT = separated
OPT_BUILD = -O $(OPT)
OPT_RUN = -O $(OPT)
OPT_TESTS = -O $(OPT)

%.out: %.fix
	$(FIXAUTOLINK) build -o $@ $(LIBS) -f $< $(OPT_BUILD)

%.run: %.fix
	$(FIXAUTOLINK) run $(LIBS) -f $< $(OPT_RUN)

all::

test:: test-curdir test-subdirs

test-curdir::
  ifneq ($(wildcard tests),)
	$(FIXAUTOTEST) $(LIBS) -T ./tests $(OPT_TESTS) $(TESTS) --keep-going
  endif

test-subdirs::
  ifneq ($(SUBDIRS),)
	set -e && for subdir in $(SUBDIRS); do $(MAKE) -C $$subdir test; done
  endif

clean::
	rm -f *.out
	rm -f .depend
	fix clean

