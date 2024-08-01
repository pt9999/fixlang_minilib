all: tools examples

clean:
	rm -f $(TOOLS)
	rm -f .depend
	fix clean
	$(MAKE) -C examples clean

-include .depend

#OPT_TOOLS = -O default
OPT_TOOLS = -O separated

#OPT_TESTS = -O default
OPT_TESTS = -O separated
#OPT_TESTS = -O minimum

TOOLS = bin/fixautolink bin/fixautotest bin/fixdoc
tools: $(TOOLS)

bin/fixautolink: tools/fixautolink.fix lib/encoding/binary.fix lib/io/file_system.fix \
				 lib/io/platform.fix lib/io/path.fix lib/io/errno.fix lib/text/simple_parser.fix lib/text/string_ex.fix
	mkdir -p bin
	fix build -o $@ -f $^ $(OPT_TOOLS)

bin/fixautotest: bin/fixautolink
	bin/fixautolink build -o $@ -I ./lib -f tools/fixautotest.fix $(OPT_TOOLS)

bin/fixdoc: bin/fixautolink
	bin/fixautolink build -o $@ -I ./lib -f tools/fixdoc.fix $(OPT_TOOLS)

test: bin/fixautotest
	bin/fixautotest -I ./lib -T ./tests -k $(OPT_TESTS)

test-crypto: bin/fixautotest
	make -C _sandbox/crypto test

document: bin/fixdoc
	bin/fixdoc -i lib -o doc

.PHONY: examples
examples: bin/fixautolink
	$(MAKE) -C examples all
