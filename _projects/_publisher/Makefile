fix=fix

all: build

build:
	$(fix) build -o publisher.out --deny-deprecated

document:
	$(fix) docs -o docs

test:
	$(fix) test -o a.out

clean:
	$(fix) clean
	rm -f *.out perf.data*

install:
	install publisher.out $(HOME)/.cargo/bin/publisher


