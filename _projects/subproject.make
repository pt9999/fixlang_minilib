# Makefile for subprojects

.PHONY: all build test test-fix test-document clean document update-deps

### Options for `_verup.py` and `_publisher`
CONFIRM = --confirm
CONFIRM_OPTS = $(if $(CONFIRM), $(CONFIRM), --no-confirm)
RELEASE =
RELEASE_OPTS = $(if $(RELEASE), --release, --no-release)
VERUP_OPTS = --update-document --commit --tag --push $(CONFIRM_OPTS)
# VERUP_OPTS = $(CONFIRM_OPTS)
PUBLISHER_OPTS = --update-document --commit --tag --push $(CONFIRM_OPTS) $(RELEASE_OPTS)
# PUBLISHER_OPTS = $(CONFIRM_OPTS) $(RELEASE_OPTS)

all: build

build:
	fix build

test: test-fix test-document

test-fix:
	fix test -O basic
	fix test -O max

test-document:
	fix deps update
	fix docs -o docs

reset-document:
	git checkout -- fixdeps.lock

clean:
	fix clean
	rm -rf *.out *.o

document:
	fix deps install
	fix docs -o docs
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
# - Run test (-O basic, -O max)
# - Commit fixdeps.lock if needed
# - Version up and push if needed
publish:
	../_publisher/publisher.out . $(PUBLISHER_OPTS)


publish_old:
	git diff --exit-code HEAD											# Check if uncommit files exist
	/usr/bin/test "$$(git rev-parse --abbrev-ref HEAD)" == "main"		# Check if current branch is main
	fix clean
	fix deps update
	fix test -O basic
	fix test -O max
	if ! git diff --quiet HEAD -- fixdeps.lock; then \
		git add fixdeps.lock; \
		git commit -m 'update deps' -- fixdeps.lock; \
	fi
	python3 ../_verup.py $(VERUP_OPTS)

# Version up.
# - Increment the patch version of `[general]version` in `fixproj.toml`
# - Update document (Run `make -f ../subproject.make document`)
# - Commit `fixproj.toml` to the local git repository
# - Add tag to the local git repository
# - Push to the remote git repository
verup:
	python3 ../_verup.py $(VERUP_OPTS)
