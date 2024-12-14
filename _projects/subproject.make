# Makefile for subprojects

.PHONY: all build test clean document update-deps

all: build

build:
	fix build

test:
	fix test

clean:
	fix clean
	rm -rf *.out

document:
	bash ../_gendoc.sh .
	git add doc
	if ! git diff-index --quiet HEAD doc; then \
		git commit -m 'update document' ; \
	fi

update-deps:
	fix deps update
	git add fixdeps.lock
	if ! git diff-index --quiet HEAD fixdeps.lock; then \
		git commit -m 'update deps' ; \
	fi

# Publish a subproject.
# - Update dependencies
# - Run test
# - Commit `fixdeps.lock`
# - Push to the remote repository
publish:
	git checkout main
	fix clean
	fix deps update
	fix test
	git add fixdeps.lock
	if ! git diff-index --quiet --cached HEAD; then \
		git commit -m 'update deps' ; \
	fi
	git push

# Version up.
# - Increment the patch version of `[general]version` in `fixproj.toml`
# - Commit `fixproj.toml` to the local git repository
# - Add tag to the local git repository
# - Push to the remote git repository
verup:
	python3 ../_verup.py --commit --tag --push
