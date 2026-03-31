CC=g++

SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
INS_DIR := /rs/rs_grp_walkerlab/GroupScripts/
AGIMUS_BIN_DIR := bin
EXE := $(BIN_DIR)/tcparse

SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CPPFLAGS := -Iinclude -MMD -MP
CFLAGS   := -Wall
LDFLAGS  := -Llib
LDLIBS   := -lm -lstdc++fs

EXECUTABLES := $(AGIMUS_BIN_DIR)/automd $(BIN_DIR)/automd_production $(BIN_DIR)/automd_preproduction $(BIN_DIR)/automd_initialize $(AGIMUS_BIN_DIR)/autoanalytics $(AGIMUS_BIN_DIR)/autommpbsa $(AGIMUS_BIN_DIR)/autoparams $(AGIMUS_BIN_DIR)/autoquantum $(AGIMUS_BIN_DIR)/autosolvent $(AGIMUS_BIN_DIR)/datasetbuilder $(AGIMUS_BIN_DIR)/featurefinder $(AGIMUS_BIN_DIR)/tcparse

.PHONY: all clean install

all: $(EXECUTABLES)

$(AGIMUS_BIN_DIR)/automd:
	cd AutoMD/; make && make install; cd ../;

$(AGIMUS_BIN_DIR)/automd_production:
	cd AutoMD/; make && make install; cd ../;

$(AGIMUS_BIN_DIR)/automd_preproduction:
	cd AutoMD/; make && make install; cd ../;

$(AGIMUS_BIN_DIR)/automd_initialize:
	cd AutoMD/; make && make install; cd ../;

$(AGIMUS_BIN_DIR)/autoparams:
	cd AutoParams/; make && make install; cd ../;

$(AGIMUS_BIN_DIR)/tcparse:
	cd TCSpectrumParse/; make && make install; cd ../;

# $(AGIMUS_BIN_DIR)/autoanalytics:
# 	cd AutoAnalytics/; make && make install; cd ../;

# $(AGIMUS_BIN_DIR)/autommpbsa:
# 	cd AutoMMPBSA/; make && make install; cd ../;

# $(AGIMUS_BIN_DIR)/autoquantum: 
# 	cd AutoQuantum/; make && make install; cd ../;

# $(AGIMUS_BIN_DIR)/autosolvent:
# 	cd AutoSolvent/; make && make install; cd ../;

# $(AGIMUS_BIN_DIR)/datasetbuilder:
# 	cd DataSetBuilder/; make && make install; cd ../;

# $(AGIMUS_BIN_DIR)/featurefinder:
# 	cd FeatureFinder/; make && make install; cd ../;

# $(AGIMUS_BIN_DIR)/overseer:
# 	cd Overseer/; make && make install; cd ../;
