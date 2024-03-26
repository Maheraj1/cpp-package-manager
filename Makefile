include ext/ext.mk

CXX = clang++
MODE = -O3
_OS = $(shell uname)
_OBJ = cpp-pkgmc
OBJ = 

SRC = $(wildcard src/**/*.cpp) $(wildcard src/*.cpp)

INCLUDE = -Iinclude -Iext/include
CXXFLAGS = -std=c++20 $(MODE) $(EXT_CFLAGS)

LDFLAGS = -Llib/ -lcpp-pkgm-ext

ifeq ($(_OS), Darwin)
	CXX = clang++
	OBJ = $(_OBJ).dylib
else ifeq ($(_OS), Linux) 
	CXX = g++
	OBJ = $(_OBJ).so
else ifeq ($(OS), Windows_NT)
	CXX = g++
	OBJ = $(_OBJ).dll
endif

OBJS = $(addsuffix .o, $(basename $(notdir $(SRC))))

%.o: src/%.cpp
	@$(CXX) -c -o $@ $< $(INCLUDE) $(CXXFLAGS)
	@echo "Built $@"
	
%.o: src/**/%.cpp
	@$(CXX) -c -o $@ $< $(INCLUDE) $(CXXFLAGS)
	@echo "Built $@"

all: $(OBJ)
	@rm $(OBJS)

$(OBJ):	$(OBJS)
	@$(CXX) -o $(OBJ) $^ $(LDFLAGS)
	@cp $(OBJ) bin/$(OBJ)

clean:
	@rm -f $(OBJS) $(OBJ)

