all:

test:
	fix run -f algebra_test1.fix
	fix run -f bigfloat_test1.fix
	#fix run -f bigint_test1.fix		# requires BigIntPrime
	fix run -f imp_prop.fix
	fix run -f lnum.fix
	fix run -f ndarray_test.fix ndarray.fix ndarray_random.fix

examples:
	fix build -f ndarray_calc.fix ndarray.fix ndarray_random.fix -o ndarray_calc.out -d readline

clean:
	fix clean
	rm -f *.out
