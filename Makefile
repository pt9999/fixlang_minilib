%.out: %.fix
	fix build -f $< -o $@

all: fib1.out fib2.out fib3.out fib4.out fib5.out fib6.out echo.out calc.out fix_func.out fork_exec.out

clean:
	rm -f *.out

test: test_parser test_json

PARSER_TEST_SOURCE := simple_parser_test.fix lib/simple_parser.fix lib/string_ex.fix lib/unit_test.fix

test_parser:
	fix run -f $(PARSER_TEST_SOURCE)

JSON_TEST_SOURCE := json_test.fix lib/json.fix lib/json_encoder.fix lib/json_decoder.fix lib/simple_parser.fix lib/string_ex.fix lib/unit_test.fix

test_json:
	fix run -f $(JSON_TEST_SOURCE)
#	gdb --args fix run -f $(JSON_TEST_SOURCE)
	
build_json:
	fix build -f $(JSON_TEST_SOURCE)

