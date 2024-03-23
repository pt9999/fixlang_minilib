all: tools examples

clean:
	rm -f examples/*.out
	rm -f $(TOOLS)
	rm -f .depend
	fix clean

-include .depend

#OPT_TOOLS = -O default
OPT_TOOLS = -O separated

#OPT_EXAMPLES = -O default
OPT_EXAMPLES = -O separated

#OPT_TESTS = -O default
OPT_TESTS = -O separated
#OPT_TESTS = -O minimum

TOOLS = bin/fixautolink bin/fixautotest bin/fixdoc
tools: $(TOOLS)

bin/fixautolink: tools/fixautolink.fix lib/encoding/binary.fix lib/io/file_system.fix \
				 lib/io/platform.fix lib/io/path.fix lib/text/simple_parser.fix lib/text/string_ex.fix
	mkdir -p bin
	fix build -o $@ -f $^ $(OPT_TOOLS)

bin/fixautotest: bin/fixautolink
	bin/fixautolink build -o $@ -L ./lib -f tools/fixautotest.fix $(OPT_TOOLS)

bin/fixdoc: bin/fixautolink
	bin/fixautolink build -o $@ -L ./lib -f tools/fixdoc.fix $(OPT_TOOLS)

test: bin/fixautotest
	bin/fixautotest -L ./lib -T ./tests -k $(OPT_TESTS)

document: bin/fixdoc
	bin/fixdoc -i lib -o doc

examples: bin/fixautolink \
		examples/json_cat.out \
		examples/sample_client.out \
		examples/sample_server.out \
		examples/sample_http_server.out \
		examples/grep.out \
		examples/spell_checker.out \
		examples/calc_pi.out \
		examples/probable_primes.out \
		examples/fractal_server.out

examples/json_cat.out: 
	bin/fixautolink build -o $@ -L ./lib -f examples/json_cat.fix $(OPT_EXAMPLES)

examples/sample_client.out:
	bin/fixautolink build -o $@ -L ./lib -f examples/sample_client.fix $(OPT_EXAMPLES)

examples/sample_server.out: 
	bin/fixautolink build -o $@ -L ./lib -f examples/sample_server.fix $(OPT_EXAMPLES)

examples/sample_http_server.out: 
	bin/fixautolink build -o $@ -L ./lib -f examples/sample_http_server.fix $(OPT_EXAMPLES)

examples/grep.out: 
	bin/fixautolink build -o $@ -L ./lib -f examples/grep.fix $(OPT_EXAMPLES)

examples/spell_checker.out:
	bin/fixautolink build -o $@ -L ./lib -f examples/spell_checker.fix $(OPT_EXAMPLES)

examples/calc_pi.out:
	bin/fixautolink build -o $@ -L ./lib -f examples/calc_pi.fix $(OPT_EXAMPLES)

examples/probable_primes.out:
	bin/fixautolink build -o $@ -L ./lib -f examples/probable_primes.fix $(OPT_EXAMPLES)

examples/fractal_server.out:
	-bin/fixautolink build -o $@ -L ./lib -d png -d z -f examples/fractal_server.fix $(OPT_EXAMPLES)

