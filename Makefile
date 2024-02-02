all: bin/fixautolink examples

clean:
	rm -f examples/*.out
	rm -f bin/fixautolink

bin/fixautolink: tools/fixautolink.fix lib/encoding/binary.fix lib/io/io_ex.fix lib/text/simple_parser.fix lib/text/string_ex.fix
	mkdir -p bin
	fix build -o $@ -f $^

-include .depends

test: bin/fixautolink test_app test_collection test_crypto test_encoding test_io_ex test_math test_text test_net

test_app: test_clap
test_clap:
	bin/fixautolink run -f tests/app/clap_test.fix -L ./lib

test_collection: test_ordered_map test_deque test_rbtree test_tree_map test_tree_set
test_ordered_map:
	bin/fixautolink run -f tests/collection/ordered_map_test.fix -L ./lib
test_deque:
	bin/fixautolink run -f tests/collection/deque_test.fix -L ./lib
test_rbtree:
	bin/fixautolink run -f tests/collection/rbtree_test.fix -L ./lib
test_tree_map:
	bin/fixautolink run -f tests/collection/tree_map_test.fix -L ./lib
test_tree_set:
	bin/fixautolink run -f tests/collection/tree_set_test.fix -L ./lib

test_crypto: test_sha1 test_sha256
test_sha1:
	bin/fixautolink run -f tests/crypto/sha1_test.fix -L ./lib
test_sha256:
	bin/fixautolink run -f tests/crypto/sha256_test.fix -L ./lib

test_encoding: test_binary test_json
test_binary:
	bin/fixautolink run -f tests/encoding/binary_test.fix -L ./lib
test_json:
	bin/fixautolink run -f tests/encoding/json_test.fix -L ./lib

test_io_ex:
	bin/fixautolink run -f tests/io/io_ex_test.fix -L ./lib

test_math: test_bigint test_bigint_prime
test_bigint:
	bin/fixautolink run -f tests/math/bigint_test.fix -L ./lib
test_bigint_prime:
	bin/fixautolink run -f tests/math/bigint_prime_test.fix -L ./lib

test_text: test_string_ex test_unicode test_parser test_regexp
test_string_ex:
	bin/fixautolink run -f tests/text/string_ex_test.fix -L ./lib
test_unicode:
	bin/fixautolink run -f tests/text/unicode_test.fix -L ./lib
test_parser:
	bin/fixautolink run -f tests/text/simple_parser_test.fix -L ./lib
test_regexp:
	bin/fixautolink run -f tests/text/regexp_test.fix  -L ./lib

test_net: test_url test_request test_router test_html
test_url:
	bin/fixautolink run -f tests/net/url_test.fix -L ./lib
test_request:
	bin/fixautolink run -f tests/net/request_test.fix -L ./lib
test_router:
	bin/fixautolink run -f tests/net/router_test.fix -L ./lib
test_html:
	bin/fixautolink run -f tests/net/html_test.fix -L ./lib

document: examples/fixdoc.out
	examples/fixdoc.out -i lib -o doc

examples: examples/json_cat.out examples/sample_client.out examples/sample_server.out \
		examples/fixdoc.out examples/sample_http_server.out \
		examples/grep.out examples/spell_checker.out

examples/json_cat.out: 
	bin/fixautolink build -o $@ -L ./lib -f examples/json_cat.fix

examples/sample_client.out:
	bin/fixautolink build -o $@ -L ./lib -f examples/sample_client.fix

examples/sample_server.out: 
	bin/fixautolink build -o $@ -L ./lib -f examples/sample_server.fix

examples/fixdoc.out:
	bin/fixautolink build -o $@ -L ./lib -f examples/fixdoc.fix

examples/sample_http_server.out: 
	bin/fixautolink build -o $@ -L ./lib -f examples/sample_http_server.fix

examples/grep.out: 
	bin/fixautolink build -o $@ -L ./lib -f examples/grep.fix

examples/spell_checker.out:
	bin/fixautolink build -o $@ -L ./lib -f examples/spell_checker.fix
