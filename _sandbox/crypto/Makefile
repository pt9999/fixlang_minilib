CRYPTO_DIR = .
SUBDIRS = cipher cert tls https

include $(CRYPTO_DIR)/Makefile.inc
-include .depend

document:
	$(TOPDIR)/bin/fixdoc -i . -o .local/doc
