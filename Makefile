VERSION        := 0.0.1
CC             := g++
AR             := ar
CXXFLAGS       := -Wall
ARFLAGS        := rcs

TEST_NAME      := test.out
NUMCU_NAME     := libnumcu.a

SOURCE_DIR     := src
INCLUDE_DIR    := include
TESTS_DIR      := tests
BUILD_DIR      := build

TEST_TARGET    := $(BUILD_DIR)/$(TEST_NAME)
NUMCU_TARGET   := $(BUILD_DIR)/$(NUMCU_NAME)

NUMCU_SOURCES  := $(wildcard $(SOURCE_DIR)/*.cpp)
INCLUDES       := $(wildcard $(INCLUDE_DIR)/*.hpp)
TEST_SOURCES   := $(wildcard $(TESTS_DIR)/*.cpp)

NUMCU_OBJFILES := $(NUMCU_SOURCES:.cpp=.o)
TEST_OBJFILES  := $(TEST_SOURCES:.cpp=.o)

SOURCES         := $(NUMCU_SOURCES)
SOURCES         += $(TEST_SOURCES)
OBJECTS         := $(NUMCU_OBJFILES)
OBJECTS         += $(TEST_OBJFILES)


.PHONY: test clean build_test


$(NUMCU_TARGET): $(NUMCU_OBJFILES)
	$(AR) $(ARFLAGS) $@ $^


build_test: $(TEST_OBJFILES) $(NUMCU_TARGET)
	$(CC) $(CXXFLAGS) -I$(INCLUDE_DIR) -o $(TEST_TARGET) $^ -lm


test: build_test
	$(TEST_TARGET)

%.o: %.cpp
	echo $(SOURCES)
	echo $(OBJECTS)
	$(CC) $(CXXFLAGS) -c -I$(INCLUDE_DIR) -o $@ $^


clean:
	-rm -rf *.o ./**/*.o


clean_dist:
	rm -rf build/*
