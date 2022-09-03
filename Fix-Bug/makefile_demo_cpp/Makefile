
BUILD = make
CLEAN = make clean
BUILD_DIR = make build_dir
#THIRDP_LIB_PATH=/usr/local/mylibs/

INSTALLATION_PATH = $(shell echo $$INSTALLATION_PATH)
ifeq ($(INSTALLATION_PATH),)
        INSTALLATION_PATH = $(shell echo $$PWD)
        export INSTALLATION_PATH
#       INSTALLATION_PATH = /usr/local/mycustombuild
endif

SOURCE_DIR := ./src

# User-defined function
define makeallmodules
	for dir in $(SOURCE_DIR)/*; \
		do \
		make -C $$dir $(1); \
		done
endef

all:
	@echo $(INSTALLATION_PATH)
	@echo "###### BUILDING  ALL MODULES########"
	$(call makeallmodules, all)

3rd-party-libs:
#	(cd src/3rd_party/libzmq; $(BUILD) install)

build_dir:
	@echo "#######BUILDING DIRECTORIES FOR OUTPUT BINARIES#######"
	$(call makeallmodules, build_dir)
clean:
	@echo "####### CLEANING BINS/OBJS/.SO/.a #######"
	-$(call makeallmodules, clean)

install:
	$(call makeallmodules, install)

.PHONY: all 3rd-party-libs build_dir clean install
