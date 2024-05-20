FIXAUTOLINK = ../../bin/fixautolink
LIBS = -L ../../lib -L .

%.out: %.fix
	$(FIXAUTOLINK) build -o $@ $(LIBS) -f $<

all: fib1.out fib2.out fib3.out fib4.out fib5.out fib6.out echo.out calc.out

clean:
	rm -f *.out
	rm -f .depend
	fix clean

-include .depend