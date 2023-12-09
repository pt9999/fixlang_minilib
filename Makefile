all: examples

clean:
	rm -f examples/*.out

LIB_UNIT_TEST := lib/unit_test.fix
LIB_STRING_EX := lib/string_ex.fix
LIB_CLAP := lib/clap.fix $(LIB_STRING_EX)
LIB_ORDERED_MAP := lib/ordered_map.fix $(LIB_STRING_EX)
LIB_PARSER := lib/simple_parser.fix $(LIB_STRING_EX)
LIB_JSON := lib/json.fix lib/json_encoder.fix lib/json_decoder.fix lib/simple_parser.fix lib/ordered_map.fix $(LIB_STRING_EX)
LIB_TCP := lib/tcp.fix

test: test_string_ex test_clap test_ordered_map test_parser test_json

test_string_ex:
	fix run -f tests/string_ex_test.fix $(LIB_STRING_EX) $(LIB_UNIT_TEST)

test_clap:
	fix run -f tests/clap_test.fix $(LIB_CLAP) $(LIB_UNIT_TEST)

test_ordered_map:
	fix run -f tests/ordered_map_test.fix $(LIB_ORDERED_MAP) $(LIB_UNIT_TEST)

test_parser:
	fix run -f tests/simple_parser_test.fix $(LIB_PARSER) $(LIB_UNIT_TEST)

test_json:
	fix run -f tests/json_test.fix $(LIB_JSON) $(LIB_UNIT_TEST)

examples: examples/json_cat.out examples/sample_client.out examples/sample_server.out examples/fixdoc.out

examples/json_cat.out: examples/json_cat.fix $(LIB_JSON) 
	fix build -f $^ -o $@

examples/sample_client.out: examples/sample_client.fix $(LIB_TCP) $(LIB_CLAP)
	fix build -f $^ -o $@

examples/sample_server.out: examples/sample_server.fix $(LIB_TCP)
	fix build -f $^ -o $@

examples/fixdoc.out: examples/fixdoc.fix $(LIB_PARSER) lib/clap.fix
	fix build -f $^ -o $@

