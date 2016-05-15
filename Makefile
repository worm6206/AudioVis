# Makefile created by Kevin Yen
CPP_FILES := $(wildcard src/*.cpp)
H_FILES := $(wildcard header/*.cpp)
EXE_FILES := $(addprefix build/,$(notdir $(CPP_FILES:.cpp=)))
CC := g++
PRE_FLAG := -pipe -Wall -O2 -fPIC -I/usr/local/include/essentia/ -I/usr/local/include/essentia/scheduler/ -I/usr/local/include/essentia/streaming/  -I/usr/local/include/essentia/utils -I/usr/include/taglib -I/usr/include/qt4 -D__STDC_CONSTANT_MACROS
POST_FLAG := -L/usr/local/lib -lessentia -lfftw3 -lyaml -lavcodec -lavformat -lavutil -lsamplerate -ltag -lfftw3f
PURPLE=\033[0;35m
GREEN=\033[0;32m
NC=\033[0m

MKDIR_P = mkdir -p
OUT_DIR = build

all: ${OUT_DIR} $(EXE_FILES)

${OUT_DIR}:
	@$ ${MKDIR_P} ${OUT_DIR}
	@echo "${PURPLE}directory \"${OUT_DIR}\" created${NC}"

build/%: src/%.cpp header/pipeline.cpp header/pipeline.hpp
	@$ $(CC) $(PRE_FLAG) $< $(H_FILES) -o $@ $(POST_FLAG)
	@echo "=> ${GREEN}$(notdir $(<:.cpp=))${NC}"

clean: 
	@$ rm -Rf build/
	@echo "${PURPLE}directory \"build\" removed${NC}"