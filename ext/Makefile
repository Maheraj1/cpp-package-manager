CXX = clang++
MODE = -O3
_OS = $(shell uname)
_OBJ = libcpp-pkgm-ext
OBJ = 

_DIR = 

SRC = $(wildcard **/src/*.cpp) $(wildcard **/src/**/*.cpp)

INCLUDE = -Iinclude/CLIB -Iinclude/FS -Iinclude/ImLog
CXXFLAGS = -std=c++20 $(MODE) 

LDFLAGS =

ifeq ($(_OS), Darwin)
	CXX = clang++
	OBJ = $(_OBJ).dylib
	LDFLAGS = -dynamiclib -fPIC
	_DIR = /
else ifeq ($(_OS), Linux) 
	CXX = g++
	OBJ = $(_OBJ).so
	LDFLAGS = -shared -fPIC
	_DIR = /
else ifeq ($(OS), Windows_NT)
	CXX = g++
	OBJ = $(_OBJ).dll
	LDFLAGS = -shared -fPIC
	_DIR = \\ 
endif

OBJS = $(addsuffix .o, $(basename $(notdir $(SRC))))

%.o: **/src/%.cpp
	@$(CXX) -c -o $@ $< $(INCLUDE) $(CXXFLAGS)
	@echo "Built $@"
	
%.o: **/src/**/%.cpp
	@$(CXX) -c -o $@ $< $(INCLUDE) $(CXXFLAGS)
	@echo "Built $@"

all: $(OBJ)
	@rm $(OBJS)

$(OBJ):	$(OBJS)
	@$(CXX) -o $(OBJ) $^ $(LDFLAGS)
	@mv $(OBJ) ../lib/$(OBJ)

clean:
	@rm -f $(OBJS) $(OBJ)

