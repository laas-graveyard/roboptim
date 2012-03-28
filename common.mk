include ../variables.mk
include ../rules.mk

ROBOPTIM_CORE=$(shell rospack find roboptim-core)/$(PKGCONFIGDIR)

PKG_CONFIG_PATH=$(ROBOPTIM_CORE):$(shell rospack find cminpack)/lib/pkgconfig
RPATHS=$(shell rospack find roboptim-core)/$(LIBDIR)
