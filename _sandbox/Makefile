%.out: %.fix
	../bin/fixautolink build -o $@ -L ../lib -f $<

all: fib1.out fib2.out fib3.out fib4.out fib5.out fib6.out echo.out calc.out \
	png.out ndarray_calc.out pi.out

channel_test1: 
	../bin/fixautolink run -L ../lib -f channel_test1.fix

ndarray:
	../bin/fixautolink run -L ../lib -f ndarray_test.fix ndarray.fix

ndarray_calc:
	../bin/fixautolink run -L ../lib -f ndarray_calc.fix ndarray.fix state_monad.fix -d readline

ndarray_calc.out:
	../bin/fixautolink build -o $@ -L ../lib -f ndarray_calc.fix ndarray.fix state_monad.fix -d readline

png: 
	../bin/fixautolink run -L ../lib -L . -f png_test.fix -d png -d z

png.out: 
	../bin/fixautolink build -o $@ -L ../lib -L . -f png_test.fix -d png -d z

mandelbrot: 
	../bin/fixautolink run -L ../lib -L . -f mandelbrot.fix -d png -d z

test_state_monad:
	../bin/fixautolink run -L ../lib -f state_monad_test.fix state_monad.fix

bigint_test1:
	../bin/fixautolink build -L ../lib -f bigint_test1.fix

bigfloat_test1:
	../bin/fixautolink build -L ../lib -L . -f bigfloat_test1.fix

algebra1:
	../bin/fixautolink run -L ../lib -L . -f algebra1.fix

clean:
	rm -f *.out

veryclean: clean
	rm -f .depend

-include .depend
