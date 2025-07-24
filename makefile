CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

TARGET = test

# 选择要测试的模块，修改下面的TEST_SRC和TEST_DEFINE即可
# 例如：测试Constructor/constructur.cc
TEST_SRC = Constructor/constructur.cc
TEST_DEFINE = -DTEST_CONSTRUCTOR

SRC = main.cc $(TEST_SRC)

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(TEST_DEFINE) -o $(TARGET) $(SRC)

clean:
	del /Q $(TARGET).exe 2>nul || rm -f $(TARGET)