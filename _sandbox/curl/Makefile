all:

test:
	fix test

EXAMPLES = \
	examples/curl_example1.out

examples: $(EXAMPLES)

clean:
	fix clean
	rm -f *.o
	rm -f examples/*.out
	rm -rf tmp.*.txt

%.o : %.c
	gcc -Wall -o $@ -c $<

%.out: %.fix
	fix build -f $< -o $@
