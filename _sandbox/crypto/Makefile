FIXAUTOLINK = ../../bin/fixautolink
LIBS = -L ../../lib -L .

%.out: %.fix
	$(FIXAUTOLINK) build -o $@ $(LIBS) -f $<
%.run: %.fix
	$(FIXAUTOLINK) run -o $@ $(LIBS) -f $< -O separated

all:

md5_test1.out:
	$(FIXAUTOLINK) build -o $@ $(LIBS) -f md5_test1.fix

cipher_test1:
	$(FIXAUTOLINK) run $(LIBS) -f cipher_test1.fix -O minimum

secure_random_test1:
	$(FIXAUTOLINK) run $(LIBS) -f secure_random_test1.fix -O separated

aes_test1:
	$(FIXAUTOLINK) run $(LIBS) -f aes_test1.fix

aes_gcm_test1:
	$(FIXAUTOLINK) run $(LIBS) -f aes_gcm_test1.fix -O separated

aes_gcm_test1.out:
	$(FIXAUTOLINK) build -o $@ $(LIBS) -f aes_gcm_test1.fix -O default

gcmvs:
	$(FIXAUTOLINK) run $(LIBS) -f aes_gcmvs.fix -O separated
ecdsa_test1:
	$(FIXAUTOLINK) run $(LIBS) -f ecdsa_test1.fix -O separated
tls13:
	$(FIXAUTOLINK) run $(LIBS) -f tls13.fix -O separated
pkcs5_test1:
	$(FIXAUTOLINK) run $(LIBS) -f pkcs5_test1.fix

clean:
	rm -f *.out
	rm -f .depend
	fix clean

-include .depend
