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
LIB_HTTP_SERVER = lib/net/http_server.fix lib/net/router.fix lib/net/request.fix lib/net/url.fix lib/net/io_ex.fix $(LIB_TCP) $(LIB_STRING_EX)

test: test_string_ex test_unicode test_clap test_ordered_map test_deque test_parser test_json \
	test_url test_io_ex test_request test_router test_html

test_string_ex:
	fix run -f tests/string_ex_test.fix $(LIB_STRING_EX) $(LIB_UNIT_TEST)

test_unicode:
	fix run -f tests/unicode_test.fix $(LIB_UNICODE) $(LIB_UNIT_TEST)

test_clap:
	fix run -f tests/clap_test.fix $(LIB_CLAP) $(LIB_UNIT_TEST)

test_ordered_map:
	fix run -f tests/collection/ordered_map_test.fix $(LIB_ORDERED_MAP) $(LIB_UNIT_TEST)

test_deque:
	fix run -f tests/collection/deque_test.fix lib/collection/deque.fix $(LIB_STRING_EX) $(LIB_UNIT_TEST)

test_parser:
	fix run -f tests/simple_parser_test.fix $(LIB_PARSER) $(LIB_UNIT_TEST)

test_json:
	fix run -f tests/json_test.fix $(LIB_JSON) $(LIB_UNIT_TEST)

test_url:
	fix run -f tests/net/url_test.fix $(LIB_URL) $(LIB_UNIT_TEST)

test_io_ex:
	fix run -f tests/net/io_ex_test.fix lib/net/io_ex.fix $(LIB_UNIT_TEST)

test_request:
	fix run -f tests/net/request_test.fix lib/net/request.fix lib/net/url.fix lib/net/io_ex.fix $(LIB_PARSER) $(LIB_UNIT_TEST)

test_router:
	fix run -f tests/net/router_test.fix lib/net/router.fix $(LIB_STRING_EX) $(LIB_UNIT_TEST)

test_html:
	fix run -f tests/net/html_test.fix lib/net/html.fix $(LIB_STRING_EX) $(LIB_UNIT_TEST)

document: examples/fixdoc.out
	find lib -name "*.fix" -print | while read input; do \
		mkdir -pv $$(dirname doc/$$input) && \
		examples/fixdoc.out $$input -o doc/$${input%%.fix}.md && \
		echo $$input; done

examples: examples/json_cat.out examples/sample_client.out examples/sample_server.out examples/fixdoc.out examples/sample_http_server.out

examples/json_cat.out: examples/json_cat.fix $(LIB_JSON) 
	fix build -f $^ -o $@

examples/sample_client.out: examples/sample_client.fix $(LIB_TCP) $(LIB_CLAP)
	fix build -f $^ -o $@

examples/sample_server.out: examples/sample_server.fix $(LIB_TCP)
	fix build -f $^ -o $@

examples/fixdoc.out: examples/fixdoc.fix $(LIB_PARSER) lib/clap.fix
	fix build -f $^ -o $@

examples/sample_http_server.out: examples/sample_http_server.fix lib/net/html.fix $(LIB_HTTP_SERVER)
	fix build -f $^ -o $@

http_server: examples/sample_http_server.fix lib/net/html.fix $(LIB_HTTP_SERVER)
	fix run -f $^
