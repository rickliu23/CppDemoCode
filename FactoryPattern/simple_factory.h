#ifndef SIMPLE_FACTORY_H
#define SIMPLE_FACTORY_H

#include <iostream>

void* create_board();

class Board {
private:
    Board(const Board&) = delete; // 禁用拷贝构造函数
    Board& operator=(const Board&) = delete; // 禁用赋值操作

protected:
    Board(){};

public:
    static Board& GetInstance() {
        static Board* instance = static_cast<Board*>(create_board());
        return *instance;
    }

    virtual ~Board() = default;

    virtual void PrintType(void) {
        std::cout << "This is a generic Board." << std::endl;
    };
};

class BoardA : public Board {
public:
    void PrintType(void) override {
        std::cout << "This is BoardA." << std::endl;
    }
};

class BoardB : public Board {
public:
    void PrintType(void) override {
        std::cout << "This is BoardB." << std::endl;
    }
};

#define DECLARE_BOARD(BOARD_CLASS_NAME) \
void* create_board() { \
    return new BOARD_CLASS_NAME(); \
}

DECLARE_BOARD(BoardA)

#endif // SIMPLE_FACTORY_H