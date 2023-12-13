%.out: %.fix
	fix build -f $< -o $@

all: fib1.out fib2.out fib3.out fib4.out fib5.out fib6.out echo.out calc.out fix_func.out fork_exec.out

http.out: http.fix ../lib/tcp.fix ../lib/simple_parser.fix ../lib/string_ex.fix
	fix build -f $^ -o $@

router.out: router.fix ../lib/simple_parser.fix ../lib/string_ex.fix
	fix build -f $^ -o $@

clean:
	rm -f *.out
