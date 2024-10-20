all:

test:
	for d in fix*; do (cd $$d && if [ -f fixproj.toml ]; then fix clean && fix test; fi); done
	$(MAKE) -C fixlang-minilib-examples clean all

clean:
	for d in fix*; do (cd $$d && if [ -f fixproj.toml ]; then fix clean; fi); done
	$(MAKE) -C fixlang-minilib-examples clean

update:
	for d in fix*; do (cd $$d && if [ -f fixproj.toml ]; then fix deps update; fi); done
#$(MAKE) -C fixlang-minilib-examples update

