CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

TARGET = test

 # 测试构造函数相关
 # 测试构造函数相关
# TEST_CC	= TEST_CONSTRUCTOR
# 测试循环
# TEST_CC = TEST_RANGE_BASED_FOR_LOOP
# 测试循环
TEST_CC = TEST_LAMBDA

ifeq ($(TEST_CC), TEST_CONSTRUCTOR)
TEST_SRC = Constructor/constructor.cc
else ifeq ($(TEST_CC), TEST_RANGE_BASED_FOR_LOOP)
TEST_SRC = RangeBasedForLoop/range_based_for_loop.cc
else ifeq ($(TEST_CC), TEST_LAMBDA)
TEST_SRC = Lambda/lambda.cc
endif

TEST_DEFINE = -D$(TEST_CC)

SRC = main.cc $(TEST_SRC)

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(TEST_DEFINE) -o $(TARGET) $(SRC)

clean:
	del /Q $(TARGET).exe 2>nul || rm -f $(TARGET)