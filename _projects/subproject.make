# Makefile for subprojects

.PHONY: all build test clean update-deps

all: build

build:
	fix build

test:
	fix test

clean:
	fix clean
	rm -rf *.out

update-deps:
	fix deps update

# Publish a subproject.
# - Update dependencies
# - Run test
# - Commit dependencies
# - Push to the remote repository
publish:
	git checkout main
	fix clean
	fix deps update
	fix test
	git add fixdeps.lock
	if ! git diff-index --quiet --cached HEAD; then \
		git commit -m 'update deps' \
		&& python3 ../_verup.py --commit \
	; fi
	git push

