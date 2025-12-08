# Makefile for subprojects

.PHONY: all build test test-fix test-document clean document update-deps

all: build

build:
	fix build

test: test-fix test-document

test-fix:
	fix test

test-document:
	bash ../_gendoc.sh .

clean:
	fix clean
	rm -rf *.out

document:
	bash ../_gendoc.sh .
	if ! git diff --quiet HEAD -- docs; then \
		git add docs; \
		git commit -m 'update document' -- docs; \
	fi

update-deps:
	fix deps update
	if ! git diff --quiet HEAD -- fixdeps.lock; then \
		git add fixdeps.lock; \
		git commit -m 'update deps' -- fixdeps.lock; \
	fi

# Publish a subproject.
# - Clean
# - Update deps
# - Run test
# - Commit fixdeps.lock if needed
# - Version up and push if needed
publish:
	# git diff --exit-code HEAD											# Check if uncommit files exist
	/usr/bin/test "$$(git rev-parse --abbrev-ref HEAD)" == "main"		# Check if current branch is main
	fix clean
	fix deps update
	fix test
	if ! git diff --quiet HEAD -- fixdeps.lock; then \
		git add fixdeps.lock; \
		git commit -m 'update deps' -- fixdeps.lock; \
	fi
	python3 ../_verup.py --update-document --commit --tag --push

# Version up.
# - Increment the patch version of `[general]version` in `fixproj.toml`
# - Update document (Run `make -f ../subproject.make document`)
# - Commit `fixproj.toml` to the local git repository
# - Add tag to the local git repository
# - Push to the remote git repository
verup:
	python3 ../_verup.py --update-document --commit --tag --push
