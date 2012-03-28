all: $(PACKAGE)

TARBALL     = build/$(PACKAGE)-$(VERSION).tar.gz
TARBALL_URL = \
ftp://ftp.openrobots.org/pub/openrobots/roboptim/$(PACKAGE)-$(VERSION).tar.gz
UNPACK_CMD  = tar xfz
SOURCE_DIR  = build/$(PACKAGE)-$(VERSION)
TARBALL_PATCH =
MD5SUM_FILE = $(PACKAGE)-$(VERSION).tar.gz.md5sum

CMAKE_CPP_FLAGS=-DNDEBUG
CMAKE_CXX_FLAGS=-march=native -O3 -g

CMAKE_FLAGS = -DCMAKE_INSTALL_PREFIX:STRING="$(INSTALL_DIR)"		\
	      -DCMAKE_CPP_FLAGS:STRING="$(CMAKE_CPP_FLAGS)"             \
	      -DCMAKE_CXX_FLAGS:STRING="$(CMAKE_CXX_FLAGS)"		\
	      -DCMAKE_INSTALL_RPATH:STRING="$(RPATHS)"			\
	      -DBOOST_ROOT:STRING="$(BOOST_ROOT)"

include $(shell rospack find mk)/download_unpack_build.mk

$(PACKAGE): $(INSTALL_DIR)/installed

# FIXME: quick hack to disable tests, change this for the next
# release...
$(INSTALL_DIR)/installed: $(SOURCE_DIR)/unpacked
	export PKG_CONFIG_PATH="$(PKG_CONFIG_PATH)"	\
	&& cd $(SOURCE_DIR)				\
	&& sed -i 's|ADD_SUBDIRECTORY(tests)||g' CMakeLists.txt \
	&& cmake . ${CMAKE_FLAGS}			\
	&& make $(ROS_PARALLEL_JOBS)			\
	&& make install $(ROS_PARALLEL_JOBS)
	touch $(INSTALL_DIR)/installed

clean:
	-rm -rf $(SOURCE_DIR) $(INSTALL_DIR)

wipe: clean
	-rm -rf build

.PHONY: all $(PACKAGE) clean wipe
