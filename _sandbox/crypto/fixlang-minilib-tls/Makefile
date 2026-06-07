TEST_OPTS = $(if $(CIENV), --allow-preliminary-commands, )
BUILD_OPTS = $(if $(CIENV), --allow-preliminary-commands, )

.PHONY: all test examples clean

all:

test:
	fix test $(TEST_OPTS)

examples:
	fix build $(BUILD_OPTS) -f examples/sample_https_client.fix -o examples/sample_https_client.out

clean:
	fix clean
	rm -f examples/*.out
