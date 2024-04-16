CXX = g++
CXXFLAGS = -std=c++11 -Wall
BUILD_DIR = build
INCLUDE_DIR = include
SRC_DIR = src

TARGET = $(BUILD_DIR)/LibrarySoftware
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))
INCLUDES := $(wildcard $(INCLUDE_DIR)/*.hpp)

$(TARGET): $(OBJS) main.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -o $@ main.cpp $(OBJS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDES) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c -o $@ $<

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: clean