all:

# Test all subprojects (except examples).
test:
	set -e; for d in $(SUBPROJECTS); do (cd $$d && fix clean && fix test); done

# Build all examples.
examples:
	$(MAKE) -C fixlang-minilib-examples clean all

# Clean all subprojects and examples.
clean:
	for d in $(SUBPROJECTS); do (cd $$d && if [ -f fixproj.toml ]; then fix clean; fi); done
	$(MAKE) -C fixlang-minilib-examples clean

# Generate documents for all subprojects.
document:
	bash _gendoc.sh $(SUBPROJECTS)

# Generate a dependency graph (using `dot` program from `graphviz` package).
dep-graph:
	cd _depgraph && fix run
	dot -T png -o dependencies.png < _depgraph/tmp.dot

# Update dependencies all subprojects and examples.
# Note that the subprojects and examples will be committed and pushed to remote repositories.
update-deps-publish: \
	update-deps-publish-subprojects \
	update-deps-publish-examples \
	commit-git-submodules

update-deps-publish-subprojects:
	set -e; for d in $(SUBPROJECTS); do ( \
		echo "=== $$d ===" \
		&& cd $$d \
		&& git checkout main \
		&& fix clean \
		&& fix deps update \
		&& git add fixdeps.lock \
		&& if ! git diff-index --quiet --cached HEAD; then \
			git commit -m 'update deps' \
			&& python3 ../_verup.py --commit \
		; fi \
		&& git push \
	); done

update-deps-publish-examples:
	$(MAKE) -C $(EXAMPLES) update-deps-publish

commit-git-submodules:
	git add $(SUBPROJECTS) $(EXAMPLES)
	git diff-index --quiet --cached HEAD || git commit -m 'update submodules'

publish: update-deps-publish test examples
	git push origin

# The subprojects in dependency order
SUBPROJECTS = \
	fixlang-minilib-common \
	fixlang-minilib-binary \
	fixlang-minilib-text \
	fixlang-minilib-monad \
	fixlang-minilib-comonad \
	fixlang-minilib-collection \
	fixlang-minilib-crypto \
	fixlang-minilib-io \
	fixlang-minilib-math \
	fixlang-minilib-regexp \
	fixlang-minilib-thread \
	fixlang-minilib-app \
	fixlang-minilib-media \
	fixlang-minilib-json \
	fixlang-minilib-xml \
	fixlang-minilib-net 

EXAMPLES = \
	fixlang-minilib-examples
