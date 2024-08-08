%.out: %.fix
	../bin/fixautolink build -o $@ -I ../lib -I . -f $<

%.run: %.fix
	../bin/fixautolink run -o $@ -I ../lib -I . -f $< -O separated

all:

channel_test1: 
	../bin/fixautolink run -I ../lib -f channel_test1.fix

ndarray:
	../bin/fixautolink run -I ../lib -f ndarray_test.fix ndarray.fix ndarray_random.fix

ndarray_calc:
	../bin/fixautolink run -I ../lib -f ndarray_calc.fix ndarray.fix -d readline -O separated

ndarray_calc.out:
	../bin/fixautolink build -o $@ -I ../lib -f ndarray_calc.fix ndarray.fix -d readline -O separated

png: 
	../bin/fixautolink run -I ../lib -I . -f png_test.fix -d png -d z

png.out: 
	../bin/fixautolink build -o $@ -I ../lib -I . -f png_test.fix -d png -d z

obj_test:
	../bin/fixautolink run -I ../lib -I . -f obj_test.fix -O minimum

mandelbrot: 
	../bin/fixautolink run -I ../lib -I . -f mandelbrot.fix -d png -d z

lnum:
	../bin/fixautolink build -I ../lib -f lnum.fix

bigint_test1:
	../bin/fixautolink build -I ../lib -f bigint_test1.fix

bigfloat_test1:
	../bin/fixautolink build -I ../lib -I . -f bigfloat_test1.fix

algebra_test1:
	../bin/fixautolink run -I ../lib -I . -f algebra_test1.fix

xml_test1:
	../bin/fixautolink run -I ../lib -I . -f xml_test1.fix -O minimum

svg_test1:
	../bin/fixautolink run -I ../lib -I . -f svg_test1.fix -O minimum

clean:
	rm -f *.out
	rm -f .depend
	fix clean

-include .depend
