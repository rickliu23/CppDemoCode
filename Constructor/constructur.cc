#include <iostream>



class Constructor {
public:
    static Constructor& GetInstance() {
        static Constructor instance;
        return instance;
    }

    // Constructor(const Constructor&) {
    //     std::cout << "Copy Constructor called!" << std::endl;
    // }
    // 删除拷贝构造函数
    Constructor(const Constructor&) = delete;

    // Constructor& operator=(const Constructor&) {
    //     std::cout << "Copy Assignment Operator called!" << std::endl;
    //     return *this;
    // }
    // 删除赋值运算符
    Constructor& operator=(const Constructor&) = delete;

private:
    /* 
    私有化拷贝构造函数
    针对非C++11版本的代码
    这样可以防止外部代码直接创建实例
    */
    // Constructor(const Constructor&) {
    //     std::cout << "Copy Constructor called!" << std::endl;
    // }
    
    /* 
    私有赋值运算符
    针对非C++11版本的代码
    这样可以防止外部代码直接创建实例
    */
    // Constructor& operator=(const Constructor&) {
    //      std::cout << "Copy Assignment Operator called!" << std::endl;
    //      return *this;
    // }

    Constructor() {
        std::cout << "Constructor called!" << std::endl;
    }
    public:
    ~Constructor() {
        std::cout << "Destructor called!" << std::endl;
    }
};

void ConstructorTest() 
{
    Constructor& c1 = Constructor::GetInstance();
    Constructor& c2 = Constructor::GetInstance();
    if (&c1 == &c2) 
    {
        std::cout << "Same instance." << std::endl;
    } else {
        std::cout << "Different instances!" << std::endl;
    }

    // Constructor c3;
    /*由于默认构造函数被私有化，无法直接创建实例
    这行代码会导致编译错误
    这类局部变量，在函数结束时会自动调用析构函数
    */

    // Constructor *c4 = new Constructor();
    /*
    由于默认构造函数被私有化，无法直接创建实例
    这行代码会导致编译错误
    这类动态分配的对象需要手动调用析构函数
    delete c4; // 手动调用析构函数
    如果不调用 delete，将导致内存泄漏
    */

    // Constructor c5 = c1; // 调用拷贝构造函数
    // Constructor c6(c1); // 调用拷贝构造函数
    /*
    如果拷贝构造函数被删除，会导致编译错误

    如果析构函数是私有的，即使存在拷贝构造函数，也无法创建对象，因为无法销毁对象
    */

    // c6 = c2; // 调用赋值运算符
    /*
    如果赋值运算符被删除，这行代码会导致编译错误
    这行代码尝试使用赋值运算符将 c2 的值赋给 c5
    注意：赋值运算符不会调用拷贝构造函数
    */
}
