CRYPTO_DIR = .
SUBDIRS = cipher cert tls http

include $(CRYPTO_DIR)/Makefile.inc
-include .depend

document:
	$(TOPDIR)/bin/fixdoc -i . -o .local/doc
