# Copyright [year] [organization]
#
# Top level makefile for cpp
#

# Output config path
CONFIG_OUTPUT_PATH = /usr/local/etc/cpp

# Local config path
LOCAL_CONFIG_PATH = ./config

# Output document path
DOC_OUTPUT_PATH = /usr/local/share/doc/cpp

# Local document path
LOCAL_DOC_PATH = ./build/doc

# Rules start here
all: cpp docs

cpp:
	$(MAKE) -C src/
	$(MAKE) -C tests/

clean:
	$(MAKE) -C src/ clean
	$(MAKE) -C tests/ clean
	$(RM) -r ./build/doc/*

install:
	$(MAKE) -C src/ install
	mkdir -p $(CONFIG_OUTPUT_PATH)
	cp $(LOCAL_CONFIG_PATH)/example.conf $(CONFIG_OUTPUT_PATH)
	touch $(CONFIG_OUTPUT_PATH)/example.log
	chmod 666 $(CONFIG_OUTPUT_PATH)/example.log
	mkdir -p $(DOC_OUTPUT_PATH)
	cp -r $(LOCAL_DOC_PATH)/* $(DOC_OUTPUT_PATH)

uninstall:
	$(MAKE) -C src/ uninstall
	$(RM) $(CONFIG_OUTPUT_PATH)/example.conf
	$(RM) -r $(DOC_OUTPUT_PATH)/*

test:
	./build/bin/test_log
	./build/bin/test_example

docs:
	/usr/bin/doxygen Doxyfile
