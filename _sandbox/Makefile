%.out: %.fix
	../bin/fixautolink build -o $@ -L ../lib -f $<

all: fib1.out fib2.out fib3.out fib4.out fib5.out fib6.out echo.out calc.out \
	channel.out png.out ndarray_calc.out

channel: 
	../bin/fixautolink run -L ../lib -f channel.fix

ndarray:
	../bin/fixautolink run -L ../lib -f ndarray_test.fix ndarray.fix

ndarray_calc:
	../bin/fixautolink run -L ../lib -f ndarray_calc.fix ndarray.fix state_monad.fix -d readline

ndarray_calc.out:
	../bin/fixautolink build -o $@ -L ../lib -f ndarray_calc.fix ndarray.fix state_monad.fix -d readline

png: 
	../bin/fixautolink run -L ../lib -f png.fix ndarray.fix -d png -d z

png.out: 
	../bin/fixautolink build -o $@ -L ../lib -f png.fix ndarray.fix -d png -d z

test_state_monad:
	../bin/fixautolink run -L ../lib -f state_monad_test.fix state_monad.fix

bigint:
	../bin/fixautolink run -L ../lib -f bigint.fix

clean:
	rm -f *.out

veryclean: clean
	rm -f .depend

-include .depend
