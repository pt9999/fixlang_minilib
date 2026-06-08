FIX = fix
BUILD_OPTS = --deny-deprecated
FIX_RUN = $(FIX) run $(BUILD_OPTS)
FIX_BUILD = $(FIX) build $(BUILD_OPTS)
FIX_TEST = $(FIX) test $(BUILD_OPTS)

all:

test:
	$(FIX_TEST)

examples: ex-retained-ptr ex-typename ex-typed-ptr

ex-retained-ptr:
	$(FIX_RUN) -f examples/retained_ptr_example.fix

ex-typename:
	$(FIX_RUN) -f examples/typename_example.fix

ex-typed-ptr:
	$(FIX_RUN) -f examples/typed_ptr_example.fix

