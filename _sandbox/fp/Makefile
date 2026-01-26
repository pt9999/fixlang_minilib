all:

test: test-applicative test-array-t test-compose test-const \
		test-cont test-effect test-either-t test-eq1 \
		test-free test-free-t test-iterator-t test-pipe test-pipe-t \
		test-svar test-traversable-a test-yield test-yield-t test-misc

test-applicative:
	fix run -f applicative.fix -f applicative_test.fix

test-array-t:
	fix run -f array_t.fix -f array_t_test.fix

test-compose:
	fix run -f compose.fix -f compose_test.fix -f applicative.fix

test-const:
	fix run -f const.fix -f const_test.fix

test-cont:
	fix run -f cont_test1.fix

test-effect:
	fix run -f effect_example1.fix -f either_t.fix -f eq1.fix -f free.fix

test-either-t:
	fix run -f either_t.fix -f either_t_test.fix -f eq1.fix
	fix run -f either_t.fix -f either_t_example.fix -f eq1.fix

test-eq1:
	fix run -f eq1.fix -f eq1_test.fix

test-free:
	fix run -f free.fix -f free_test.fix
	fix run -f free.fix -f free_example.fix

test-free-t:
	fix run -f free_t.fix -f free_t_example.fix

test-iterator-t:
	fix run -f iterator_t.fix -f iterator_t_test.fix

test-pipe:
	fix run -f pipe.fix -f pipe_test.fix

test-pipe-t:
	fix run -f pipe_t.fix -f pipe_t_test.fix -f iterator_t.fix
	fix run -f pipe_t.fix -f pipe_t_example.fix -f iterator_t.fix

test-svar:
	fix run -f svar_example.fix

test-traversable-a:
	fix run -f traversable_a.fix -f traversable_a_test.fix -f applicative.fix

test-unlift-io:
	fix run -f unlift_io.fix -f unlift_io_test.fix

test-yield:
	fix run -f yield_example.fix

test-yield-t:
	fix run -f yield_t.fix -f yield_t_example.fix

test-misc:
	fix run -f alift.fix
	fix run -f borrow.fix
	fix run -f counter.fix
	fix run -f denotation.fix
	fix run -f fast_iter_bench.fix
	fix run -f fib6s.fix
	fix run -f fragment.fix
	fix run -f lens.fix
	# fix run -f monoid_ex.fix monoid_test1.fix			# requires minilib-math
	fix run -f newtype.fix
	fix run -f reader_writer_test.fix
	fix run -f state_monad_test2.fix
	fix run -f state_monad_test3.fix
	fix run -f to_string1.fix
