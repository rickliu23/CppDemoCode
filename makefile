CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

TARGET = test

 # 测试构造函数相关
 # 测试构造函数相关
# TEST_CC	= TEST_CONSTRUCTOR
# 测试循环
# TEST_CC = TEST_RANGE_BASED_FOR_LOOP
# 测试循环
# TEST_CC = TEST_CONSTRUCTOR
# 测试lambda表达式
# TEST_CC = TEST_LAMBDA
# 测试RAII锁
# TEST_CC = TEST_RAII
# 测试简单工厂模式
TEST_CC = TEST_SIMPLE_FACTORY

ifeq ($(TEST_CC), TEST_CONSTRUCTOR)
TEST_SRC = Constructor/constructor.cc
else ifeq ($(TEST_CC), TEST_RANGE_BASED_FOR_LOOP)
TEST_SRC = RangeBasedForLoop/range_based_for_loop.cc
else ifeq ($(TEST_CC), TEST_LAMBDA)
TEST_SRC = Lambda/lambda.cc
else ifeq ($(TEST_CC), TEST_RAII)
TEST_SRC = Lock/RAII.cc
else ifeq ($(TEST_CC), TEST_SIMPLE_FACTORY)
# TEST_SRC = FactoryPattern/simple_factory.cc
else
$(error TEST_CC not set to a valid value)
endif

TEST_DEFINE = -D$(TEST_CC)

SRC = main.cc $(TEST_SRC)

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(TEST_DEFINE) -o $(TARGET) $(SRC)

clean:
	del /Q $(TARGET).exe 2>nul || rm -f $(TARGET)