FIX = fix
BUILD_OPTS = --deny-deprecated
FIX_RUN = $(FIX) run $(BUILD_OPTS)
FIX_BUILD = $(FIX) build $(BUILD_OPTS)
FIX_CLEAN = $(FIX) clean

all:

test: test-applicative test-array-t test-compose test-const \
		test-cont test-effect test-either-t test-eq1 \
		test-free test-free-t test-iterator-t test-pipe test-pipe-t \
		test-svar test-traversable-a test-yield test-yield-t test-misc

test-applicative:
	$(FIX_RUN) -f applicative.fix -f applicative_test.fix

test-array-t:
	$(FIX_RUN) -f array_t.fix -f array_t_test.fix

test-compose:
	$(FIX_RUN) -f compose.fix -f compose_test.fix -f applicative.fix

test-const:
	$(FIX_RUN) -f const.fix -f const_test.fix

test-cont:
	$(FIX_RUN) -f cont_test1.fix

test-effect:
	$(FIX_RUN) -f effect_example1.fix -f either_t.fix -f eq1.fix

test-either-t:
	$(FIX_RUN) -f either_t.fix -f either_t_test.fix -f eq1.fix
	$(FIX_RUN) -f either_t.fix -f either_t_example.fix -f eq1.fix

test-eq1:
	$(FIX_RUN) -f eq1.fix -f eq1_test.fix

test-free:
	$(FIX_RUN) -f free_example.fix

test-free-t:
	$(FIX_RUN) -f free_t.fix -f free_t_example.fix

test-iterator-t:
	$(FIX_RUN) -f iterator_t.fix -f iterator_t_test.fix

test-pipe:
	$(FIX_RUN) -f pipe.fix -f pipe_test.fix

test-pipe-t:
	$(FIX_RUN) -f pipe_t.fix -f pipe_t_test.fix -f iterator_t.fix
	$(FIX_RUN) -f pipe_t.fix -f pipe_t_example.fix -f iterator_t.fix

test-svar:
	$(FIX_RUN) -f svar_example.fix

test-traversable-a:
	$(FIX_RUN) -f traversable_a.fix -f traversable_a_test.fix -f applicative.fix

test-unlift-io:
	$(FIX_RUN) -f unlift_io.fix -f unlift_io_test.fix

test-yield:
	$(FIX_RUN) -f yield_example.fix

test-yield-t:
	$(FIX_RUN) -f yield_t.fix -f yield_t_example.fix

test-misc:
	$(FIX_RUN) -f alift.fix
	$(FIX_RUN) -f borrow.fix
	$(FIX_RUN) -f counter.fix
	$(FIX_RUN) -f denotation.fix
	$(FIX_RUN) -f fast_iter_bench.fix
	$(FIX_RUN) -f fib6s.fix
	$(FIX_RUN) -f fragment.fix -O max
	$(FIX_RUN) -f lens.fix
	$(FIX_RUN) -f monoid_ex.fix monoid_test1.fix
	$(FIX_RUN) -f newtype.fix
	$(FIX_RUN) -f reader_writer_test.fix
	$(FIX_RUN) -f state_monad_test2.fix
	$(FIX_RUN) -f state_monad_test3.fix
	$(FIX_RUN) -f to_string1.fix
