all: examples

clean:
	rm -f examples/*.out

#PARSER_LIB_SOUCE := lib/simple_parser.fix lib/string_ex.fix lib/unit_test.fix
JSON_LIB_SOURCE := lib/json.fix lib/json_encoder.fix lib/json_decoder.fix lib/simple_parser.fix lib/ordered_map.fix lib/string_ex.fix lib/unit_test.fix
TCP_LIB_SOURCE := lib/tcp.fix

test: test_ordered_map test_parser test_json

test_ordered_map:
	fix run -f tests/ordered_map_test.fix $(JSON_LIB_SOURCE)

test_parser:
	fix run -f tests/simple_parser_test.fix $(JSON_LIB_SOURCE)

test_json:
	fix run -f tests/json_test.fix $(JSON_LIB_SOURCE)

examples: examples/json_cat.out examples/sample_client.out examples/sample_server.out

examples/json_cat.out: examples/json_cat.fix $(JSON_LIB_SOURCE) 
	fix build -f examples/json_cat.fix $(JSON_LIB_SOURCE) -o examples/json_cat.out

examples/sample_client.out: examples/sample_client.fix $(TCP_LIB_SOURCE)
	fix build -f examples/sample_client.fix $(TCP_LIB_SOURCE) -o examples/sample_client.out

examples/sample_server.out: examples/sample_server.fix $(TCP_LIB_SOURCE)
	fix build -g -f examples/sample_server.fix $(TCP_LIB_SOURCE) -o examples/sample_server.out

