all: tools examples

clean:
	rm -f examples/*.out
	rm -f $(TOOLS)

-include .depend

TOOLS = bin/fixautolink bin/fixautotest bin/fixdoc
tools: $(TOOLS)

bin/fixautolink: tools/fixautolink.fix lib/encoding/binary.fix lib/io/io_ex.fix lib/text/simple_parser.fix lib/text/string_ex.fix
	mkdir -p bin
	fix build -o $@ -f $^

bin/fixautotest: bin/fixautolink
	bin/fixautolink build -o $@ -L ./lib -f tools/fixautotest.fix

bin/fixdoc: bin/fixautolink
	bin/fixautolink build -o $@ -L ./lib -f tools/fixdoc.fix

test: bin/fixautotest
	bin/fixautotest -L ./lib -T ./tests

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
		examples/probable_primes.out

examples/json_cat.out: 
	bin/fixautolink build -o $@ -L ./lib -f examples/json_cat.fix

examples/sample_client.out:
	bin/fixautolink build -o $@ -L ./lib -f examples/sample_client.fix

examples/sample_server.out: 
	bin/fixautolink build -o $@ -L ./lib -f examples/sample_server.fix

examples/sample_http_server.out: 
	bin/fixautolink build -o $@ -L ./lib -f examples/sample_http_server.fix

examples/grep.out: 
	bin/fixautolink build -o $@ -L ./lib -f examples/grep.fix

examples/spell_checker.out:
	bin/fixautolink build -o $@ -L ./lib -f examples/spell_checker.fix

examples/calc_pi.out:
	bin/fixautolink build -o $@ -L ./lib -f examples/calc_pi.fix

examples/probable_primes.out:
	bin/fixautolink build -o $@ -L ./lib -f examples/probable_primes.fix
