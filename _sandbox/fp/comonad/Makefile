FIX = fix
BUILD_OPTS = --deny-deprecated
FIX_RUN = $(FIX) run $(BUILD_OPTS)
FIX_BUILD = $(FIX) build $(BUILD_OPTS)
FIX_CLEAN = $(FIX) clean

all:

test: test-duality1 test-duality2 test-duality3 test-duality4

test-duality1:
	$(FIX_RUN) -f duality_example1.fix -o a.out

test-duality2:
	$(FIX_RUN) -f duality_example2.fix -o a.out

test-duality3:
	$(FIX_RUN) -f duality_example3.fix -o a.out

test-duality4:
	$(FIX_RUN) -f duality_example4.fix -o a.out
