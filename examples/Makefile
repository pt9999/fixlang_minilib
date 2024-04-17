#OPT_EXAMPLES = -O default
OPT_EXAMPLES = -O separated

SOURCES := $(wildcard *.fix)
BINARIES := $(SOURCES:.fix=.out)

all: $(BINARIES)

clean:
	rm -f *.out .depend
	fix clean

%.out: %.fix
	../bin/fixautolink build -o $@ -L ../lib -f $< $(OPT_EXAMPLES)

fractal_server.out: fractal_server.fix
	-../bin/fixautolink build -o $@ -L ../lib -f $< $(OPT_EXAMPLES) -d png -d z

