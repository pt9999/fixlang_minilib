%.out: %.fix
	../bin/fixautolink build -o $@ -L ../lib -f $<

all: fib1.out fib2.out fib3.out fib4.out fib5.out fib6.out echo.out calc.out \
	png.out ndarray_calc.out

md5_test1.out:
	../bin/fixautolink build -o $@ -L ../lib -L . -f md5_test1.fix

channel_test1: 
	../bin/fixautolink run -L ../lib -f channel_test1.fix

ndarray:
	../bin/fixautolink run -L ../lib -f ndarray_test.fix ndarray.fix ndarray_random.fix

ndarray_calc:
	../bin/fixautolink run -L ../lib -f ndarray_calc.fix ndarray.fix state_monad.fix -d readline

ndarray_calc.out:
	../bin/fixautolink build -o $@ -L ../lib -f ndarray_calc.fix ndarray.fix state_monad.fix -d readline

png: 
	../bin/fixautolink run -L ../lib -L . -f png_test.fix -d png -d z

png.out: 
	../bin/fixautolink build -o $@ -L ../lib -L . -f png_test.fix -d png -d z

obj_test:
	../bin/fixautolink run -L ../lib -L . -f obj_test.fix -O minimum

mandelbrot: 
	../bin/fixautolink run -L ../lib -L . -f mandelbrot.fix -d png -d z

lens:
	../bin/fixautolink run -L ../lib -L . -f lens.fix

state_monad_test:
	../bin/fixautolink run -L ../lib -f state_monad_test.fix

state_monad_test2:
	../bin/fixautolink run -L ../lib -L . -f state_monad_test2.fix -O minimum

reader_writer_test:
	../bin/fixautolink run -L ../lib -f reader_writer_test.fix

aes_test1:
	../bin/fixautolink run -L ../lib -L . -f aes_test1.fix

lnum:
	../bin/fixautolink build -L ../lib -f lnum.fix

bigint_test1:
	../bin/fixautolink build -L ../lib -f bigint_test1.fix

bigfloat_test1:
	../bin/fixautolink build -L ../lib -L . -f bigfloat_test1.fix

algebra_test1:
	../bin/fixautolink run -L ../lib -L . -f algebra_test1.fix

monoid_test1:
	../bin/fixautolink run -L ../lib -L . -f monoid_test1.fix -O separated

clean:
	rm -f *.out

veryclean: clean
	rm -f .depend

-include .depend
