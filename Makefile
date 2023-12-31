all: examples

clean:
	rm -f examples/*.out

LIB_UNIT_TEST := lib/unit_test.fix
LIB_STRING_EX := lib/string_ex.fix
LIB_UNICODE := lib/unicode.fix $(LIB_STRING_EX)
LIB_CLAP := lib/clap.fix $(LIB_STRING_EX)
LIB_ORDERED_MAP := lib/collection/ordered_map.fix $(LIB_STRING_EX)
LIB_PARSER := lib/simple_parser.fix $(LIB_STRING_EX)
LIB_JSON := lib/json.fix lib/json_encoder.fix lib/json_decoder.fix lib/simple_parser.fix \
			lib/collection/ordered_map.fix lib/unicode.fix $(LIB_STRING_EX)
LIB_TCP := lib/net/tcp.fix
LIB_URL := lib/net/url.fix $(LIB_STRING_EX)
LIB_HTTP_SERVER = lib/net/http_server.fix lib/net/router.fix lib/net/request.fix lib/net/url.fix lib/io_ex.fix $(LIB_TCP) $(LIB_STRING_EX)
LIB_REGEXP := lib/text/regexp/regexp.fix lib/text/regexp/regexp_nfa.fix lib/text/regexp/regexp_pattern.fix $(LIB_PARSER)

test: test_app_support test_collection test_file_format test_io_ex test_text test_net

test_app_support: test_clap
test_clap:
	fix run -f tests/clap_test.fix $(LIB_CLAP) $(LIB_UNIT_TEST)

test_collection: test_ordered_map test_deque
test_ordered_map:
	fix run -f tests/collection/ordered_map_test.fix $(LIB_ORDERED_MAP) $(LIB_UNIT_TEST)
test_deque:
	fix run -f tests/collection/deque_test.fix lib/collection/deque.fix $(LIB_STRING_EX) $(LIB_UNIT_TEST)

test_file_format: test_json
test_json:
	fix run -f tests/json_test.fix $(LIB_JSON) $(LIB_UNIT_TEST)

test_io_ex:
	fix run -f tests/io_ex_test.fix lib/io_ex.fix $(LIB_STRING_EX) $(LIB_UNIT_TEST)

test_text: test_string_ex test_unicode test_parser test_regexp
test_string_ex:
	fix run -f tests/string_ex_test.fix $(LIB_STRING_EX) $(LIB_UNIT_TEST)
test_unicode:
	fix run -f tests/unicode_test.fix $(LIB_UNICODE) $(LIB_UNIT_TEST)
test_parser:
	fix run -f tests/simple_parser_test.fix $(LIB_PARSER) $(LIB_UNIT_TEST)
test_regexp:
	fix run -f tests/text/regexp/regexp_test.fix $(LIB_REGEXP) $(LIB_UNIT_TEST)

test_net: test_url test_request test_router test_html
test_url:
	fix run -f tests/net/url_test.fix $(LIB_URL) $(LIB_UNIT_TEST)
test_request:
	fix run -f tests/net/request_test.fix lib/net/request.fix lib/net/url.fix lib/io_ex.fix $(LIB_PARSER) $(LIB_UNIT_TEST)
test_router:
	fix run -f tests/net/router_test.fix lib/net/router.fix $(LIB_STRING_EX) $(LIB_UNIT_TEST)
test_html:
	fix run -f tests/net/html_test.fix lib/net/html.fix lib/unicode.fix $(LIB_STRING_EX) $(LIB_UNIT_TEST)


document: examples/fixdoc.out
	examples/fixdoc.out -i lib -o doc

examples: examples/json_cat.out examples/sample_client.out examples/sample_server.out \
		examples/fixdoc.out examples/sample_http_server.out \
		examples/grep.out

examples/json_cat.out: examples/json_cat.fix $(LIB_JSON) 
	fix build -f $^ -o $@

examples/sample_client.out: examples/sample_client.fix $(LIB_TCP) $(LIB_CLAP)
	fix build -f $^ -o $@

examples/sample_server.out: examples/sample_server.fix $(LIB_TCP) lib/collection/deque.fix
	fix build -f $^ -o $@

examples/fixdoc.out: examples/fixdoc.fix $(LIB_PARSER) lib/clap.fix lib/io_ex.fix
	fix build -f $^ -o $@

examples/sample_http_server.out: examples/sample_http_server.fix lib/net/html.fix lib/unicode.fix $(LIB_HTTP_SERVER)
	fix build -f $^ -o $@

http_server: examples/sample_http_server.fix lib/net/html.fix lib/unicode.fix $(LIB_HTTP_SERVER)
	fix run -f $^

examples/grep.out: examples/grep.fix $(LIB_REGEXP) lib/clap.fix
	fix build -f $^ -o $@
