%.out: %.fix
	fix build -f $< -o $@

all: fib1.out fib2.out fib3.out fib4.out fib5.out fib6.out echo.out calc.out fix_func.out fork_exec.out

clean:
	rm -f *.out

test: test_parser test_json

test_ordered_map:
	fix run -f ordered_map_test.fix lib/ordered_map.fix lib/string_ex.fix lib/unit_test.fix

PARSER_TEST_SOURCE := simple_parser_test.fix lib/simple_parser.fix lib/string_ex.fix lib/unit_test.fix

test_parser:
	fix run -f $(PARSER_TEST_SOURCE)

JSON_LIB_SOURCE := lib/json.fix lib/json_encoder.fix lib/json_decoder.fix lib/simple_parser.fix lib/ordered_map.fix lib/string_ex.fix lib/unit_test.fix

test_json:
	fix run -f json_test.fix $(JSON_LIB_SOURCE)
#	gdb --args fix run -f json_test.fix $(JSON_LIB_SOURCE)
	
build_json:
	fix build -f json_test.fix $(JSON_LIB_SOURCE)

run_json_cat:
	fix run -f json_cat.fix $(JSON_LIB_SOURCE) < data/bin-fix.json > tmp/out.json

build_json_cat:
	fix build -f json_cat.fix $(JSON_LIB_SOURCE) -o json_cat.out


