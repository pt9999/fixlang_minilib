%.out: %.fix
	fix build -f $< -o $@

all: fib1.out fib2.out fib3.out fib4.out fib5.out fib6.out echo.out calc.out fix_func.out fork_exec.out

channel: channel.fix ../lib/string_ex.fix ../lib/net/io_ex.fix
	fix run -f $^

clean:
	rm -f *.out
