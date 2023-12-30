%.out: %.fix
	fix build -f $< -o $@

all: fib1.out fib2.out fib3.out fib4.out fib5.out fib6.out echo.out calc.out fix_func.out fork_exec.out

channel: channel.fix ../lib/string_ex.fix ../lib/net/io_ex.fix
	fix run -f $^

ndarray: ndarray_test.fix ndarray.fix ../lib/simple_parser.fix ../lib/string_ex.fix 
	fix run -f $^

ndarray_calc: ndarray_calc.fix ndarray.fix state_monad.fix ../lib/simple_parser.fix ../lib/string_ex.fix 
	fix run -f $^ -d readline

test_state_monad:
	fix run -f state_monad_test.fix state_monad.fix $(LIB_UNIT_TEST)

clean:
	rm -f *.out
