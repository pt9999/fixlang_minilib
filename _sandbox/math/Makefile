FIX = fix
BUILD_OPTS = --deny-deprecated
FIX_RUN = $(FIX) run $(BUILD_OPTS)
FIX_BUILD = $(FIX) build $(BUILD_OPTS)
FIX_CLEAN = $(FIX) clean

all:

test:
	$(FIX_RUN) -f algebra_test1.fix
	$(FIX_RUN) -f algebra_test2.fix
	$(FIX_RUN) -f bigfloat_test1.fix
#	$(FIX_RUN) -f bigint_test1.fix		# requires BigIntPrime
	$(FIX_RUN) -f collatz.fix
	$(FIX_RUN) -f imp_prop.fix
	$(FIX_RUN) -f lnum.fix
	$(FIX_RUN) -f montgomery_test1.fix -f montgomery.fix
	$(FIX_RUN) -f montgomery_test2.fix -f montgomery.fix
	$(FIX_RUN) -f ndarray_test.fix ndarray.fix ndarray_random.fix -o a.out

examples:
	$(FIX_BUILD) -f ndarray_calc.fix ndarray.fix ndarray_random.fix -o ndarray_calc.out -d readline

clean:
	$(FIX_CLEAN)
	rm -f *.out
