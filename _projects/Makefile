# Makefile for projects directory

# The subprojects in dependency order
SUBPROJECTS = \
	fixlang-minilib-common \
	fixlang-minilib-binary \
	fixlang-minilib-text \
	fixlang-minilib-monad \
	fixlang-minilib-comonad \
	fixlang-minilib-random \
	fixlang-minilib-collection \
	fixlang-minilib-crypto \
	fixlang-minilib-io \
	fixlang-minilib-math \
	fixlang-minilib-thread \
	fixlang-minilib-app \
	fixlang-minilib-media \
	fixlang-minilib-json \
	fixlang-minilib-xml \
	fixlang-minilib-net 

EXAMPLES = \
	fixlang-minilib-examples

SUBPROJECT_MAKEFILE = $$(pwd)/subproject.make

.PHONY: all test examples clean publish
.SUFFIXES: .test .clean .document .update-deps .publish .verup

all:

# Test all subprojects (except examples).
test: $(SUBPROJECTS:%=%.test)

# Build all examples.
examples:
	$(MAKE) -C fixlang-minilib-examples clean all

# Clean all subprojects and examples.
clean: $(SUBPROJECTS:%=%.clean)
	$(MAKE) -C fixlang-minilib-examples clean

# Generate documents for all subprojects.
document: $(SUBPROJECTS:%=%.document)

# Update dependencies
update-deps: $(SUBPROJECTS:%=%.update-deps)

#document:
#	bash _gendoc.sh $(SUBPROJECTS)

verup-all: $(SUBPROJECTS:%=%.verup)

# Generate a dependency graph (using `dot` program from `graphviz` package).
dep-graph:
	cd _depgraph && fix run
	dot -T png -o dependencies.png < _depgraph/tmp.dot

publish: \
	publish-subprojects \
	publish-examples \
	push-submodules

# Publish all subprojects. (Update deps, Test, Commit & Push)
publish-subprojects: $(SUBPROJECTS:%=%.publish)

# Publish all examples. (Update deps, Build, Commit & Push)
publish-examples:
	$(MAKE) -C $(EXAMPLES) publish

push-submodules:
	git add $(SUBPROJECTS) $(EXAMPLES)
	git diff-index --quiet --cached HEAD || git commit -m 'update submodules'
	git push origin


%.test:
	$(MAKE) -C $* -f $(SUBPROJECT_MAKEFILE) clean test

%.clean:
	$(MAKE) -C $* -f $(SUBPROJECT_MAKEFILE) clean

%.document:
	$(MAKE) -C $* -f $(SUBPROJECT_MAKEFILE) document

%.update-deps:
	$(MAKE) -C $* -f $(SUBPROJECT_MAKEFILE) update-deps

%.publish:
	$(MAKE) -C $* -f $(SUBPROJECT_MAKEFILE) publish

%.verup:
	$(MAKE) -C $* -f $(SUBPROJECT_MAKEFILE) verup
