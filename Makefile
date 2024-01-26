all: examples

clean:
	rm -f examples/*.out

LIB_UNIT_TEST := lib/testing/unit_test.fix
LIB_STRING_EX := lib/text/string_ex.fix
LIB_IO_EX := lib/io/io_ex.fix lib/encoding/binary.fix
LIB_UNICODE := lib/text/unicode.fix $(LIB_STRING_EX)
LIB_CLAP := lib/app/clap.fix $(LIB_STRING_EX)
LIB_ORDERED_MAP := lib/collection/ordered_map.fix $(LIB_STRING_EX)
LIB_PARSER := lib/text/simple_parser.fix $(LIB_STRING_EX)
LIB_JSON := lib/encoding/json.fix lib/encoding/json/json_encoder.fix lib/encoding/json/json_decoder.fix \
			lib/text/simple_parser.fix \
			lib/collection/ordered_map.fix lib/text/unicode.fix $(LIB_STRING_EX)
LIB_TCP := lib/net/tcp.fix
LIB_URL := lib/net/url.fix $(LIB_STRING_EX)
LIB_HTTP_SERVER = lib/net/http_server.fix lib/net/router.fix lib/net/request.fix lib/net/url.fix $(LIB_IO_EX) $(LIB_TCP) $(LIB_STRING_EX)
LIB_REGEXP := lib/text/regexp.fix lib/text/regexp/regexp_nfa.fix lib/text/regexp/regexp_pattern.fix $(LIB_PARSER)

test: test_app test_collection test_crypto test_encoding test_io_ex test_text test_net

test_app: test_clap
test_clap:
	fix run -f tests/app/clap_test.fix $(LIB_CLAP) $(LIB_UNIT_TEST)

test_collection: test_ordered_map test_deque test_rbtree test_tree_map test_tree_set
test_ordered_map:
	fix run -f tests/collection/ordered_map_test.fix $(LIB_ORDERED_MAP) $(LIB_UNIT_TEST)
test_deque:
	fix run -f tests/collection/deque_test.fix lib/collection/deque.fix $(LIB_STRING_EX) $(LIB_UNIT_TEST)
test_rbtree:
	fix run -f tests/collection/rbtree_test.fix tests/collection/array_testutil.fix lib/collection/rbtree.fix $(LIB_STRING_EX) $(LIB_UNIT_TEST)
test_tree_map:
	fix run -f tests/collection/tree_map_test.fix tests/collection/array_testutil.fix lib/collection/tree_map.fix lib/collection/rbtree.fix $(LIB_STRING_EX) $(LIB_UNIT_TEST)
test_tree_set:
	fix run -f tests/collection/tree_set_test.fix tests/collection/array_testutil.fix lib/collection/tree_set.fix lib/collection/rbtree.fix $(LIB_STRING_EX) $(LIB_UNIT_TEST)

test_crypto: test_sha1 test_sha256
test_sha1:
	fix run -f tests/crypto/sha1_test.fix lib/crypto/sha1.fix lib/encoding/binary.fix $(LIB_STRING_EX) $(LIB_UNIT_TEST)
test_sha256:
	fix run -f tests/crypto/sha256_test.fix lib/crypto/sha256.fix lib/encoding/binary.fix $(LIB_STRING_EX) $(LIB_UNIT_TEST)

test_encoding: test_binary test_json
test_binary:
	fix run -f tests/encoding/binary_test.fix lib/encoding/binary.fix $(LIB_STRING_EX) $(LIB_UNIT_TEST)
test_json:
	fix run -f tests/encoding/json_test.fix $(LIB_JSON) $(LIB_UNIT_TEST)

test_io_ex:
	fix run -f tests/io/io_ex_test.fix $(LIB_IO_EX) $(LIB_STRING_EX) $(LIB_UNIT_TEST)

test_text: test_string_ex test_unicode test_parser test_regexp
test_string_ex:
	fix run -f tests/text/string_ex_test.fix $(LIB_STRING_EX) $(LIB_UNIT_TEST)
test_unicode:
	fix run -f tests/text/unicode_test.fix $(LIB_UNICODE) $(LIB_UNIT_TEST)
test_parser:
	fix run -f tests/text/simple_parser_test.fix $(LIB_PARSER) $(LIB_UNIT_TEST)
test_regexp:
	fix run -f tests/text/regexp_test.fix $(LIB_REGEXP) $(LIB_UNIT_TEST)

test_net: test_url test_request test_router test_html
test_url:
	fix run -f tests/net/url_test.fix $(LIB_URL) $(LIB_UNIT_TEST)
test_request:
	fix run -f tests/net/request_test.fix lib/net/request.fix lib/net/url.fix $(LIB_IO_EX) $(LIB_PARSER) $(LIB_UNIT_TEST)
test_router:
	fix run -f tests/net/router_test.fix lib/net/router.fix $(LIB_STRING_EX) $(LIB_UNIT_TEST)
test_html:
	fix run -f tests/net/html_test.fix lib/net/html.fix $(LIB_UNICODE) $(LIB_UNIT_TEST)


document: examples/fixdoc.out
	examples/fixdoc.out -i lib -o doc

examples: examples/json_cat.out examples/sample_client.out examples/sample_server.out \
		examples/fixdoc.out examples/sample_http_server.out \
		examples/grep.out examples/spell_checker.out

examples/json_cat.out: examples/json_cat.fix $(LIB_JSON) 
	fix build -f $^ -o $@

examples/sample_client.out: examples/sample_client.fix $(LIB_TCP) $(LIB_CLAP)
	fix build -f $^ -o $@

examples/sample_server.out: examples/sample_server.fix $(LIB_TCP) lib/collection/deque.fix
	fix build -f $^ -o $@

examples/fixdoc.out: examples/fixdoc.fix $(LIB_PARSER) lib/app/clap.fix $(LIB_IO_EX)
	fix build -f $^ -o $@

examples/sample_http_server.out: examples/sample_http_server.fix lib/net/html.fix lib/text/unicode.fix $(LIB_HTTP_SERVER)
	fix build -f $^ -o $@

http_server: examples/sample_http_server.fix lib/net/html.fix lib/text/unicode.fix $(LIB_HTTP_SERVER)
	fix run -f $^

examples/grep.out: examples/grep.fix $(LIB_REGEXP) lib/app/clap.fix
	fix build -f $^ -o $@

examples/spell_checker.out: examples/spell_checker.fix lib/collection/tree_map.fix lib/collection/tree_set.fix \
							lib/collection/rbtree.fix $(LIB_STRING_EX) $(LIB_IO_EX)
	fix build -f $^ -o $@
