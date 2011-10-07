include ../tools/variables.mk
include ../tools/rules.mk

ROBOPTIM_CORE=$(shell rospack find roboptim-core)/$(PKGCONFIGDIR)

PKG_CONFIG_PATH=$(ROBOPTIM_CORE)
RPATHS=$(shell rospack find roboptim-core)/$(LIBDIR)
