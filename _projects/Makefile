all:

test:
	for d in $(SUBPROJECTS); do (cd $$d && if [ -f fixproj.toml ]; then fix clean && fix test; fi); done
	$(MAKE) -C fixlang-minilib-examples clean all

clean:
	for d in $(SUBPROJECTS); do (cd $$d && if [ -f fixproj.toml ]; then fix clean; fi); done
	$(MAKE) -C fixlang-minilib-examples clean

update:
	for d in $(SUBPROJECTS); do (cd $$d && if [ -f fixproj.toml ]; then fix deps update; fi); done
	$(MAKE) -C fixlang-minilib-examples update

update-push:
	for d in $(SUBPROJECTS); do (cd $$d && if [ -f fixproj.toml ]; then \
		git checkout main && \
		fix deps update && \
		(git add fixdeps.lock && \
		git commit -m 'update deps' && \
		git push) || true; \
	fi); done
	#$(MAKE) -C fixlang-minilib-examples update

document:
	bash _gendoc.sh

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
