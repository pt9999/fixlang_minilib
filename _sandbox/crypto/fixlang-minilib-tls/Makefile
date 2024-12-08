.PHONY: all test examples clean

all:

test:
	set -e && for f in $$(find tests -name "*_test.fix" | sort); do \
		echo "=== $$f ===" && fix run -f $$f; \
	done

examples:
	fix build -f examples/sample_https_client.fix -o examples/sample_https_client.out

clean:
	fix clean
	rm -f examples/*.out
