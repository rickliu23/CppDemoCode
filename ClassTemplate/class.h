#include <iostream>

class SingletonClass
{
public:
    static SingletonClass &GetInstance()
    {
        static SingletonClass instance;
        return instance;
    }

private:
    SingletonClass() {};
    ~SingletonClass() {};
    
    // 定义成私有，保证外部代码不能直接创建实例
    SingletonClass(const SingletonClass &) {};
    SingletonClass &operator=(const SingletonClass &) {return *this;};
    // 如果是C++11及以上版本，可以使用delete来删除拷贝构造函数和赋值运算符
    // SingletonClass(const SingletonClass &) = delete;

    friend class SingletonLockGuard;
    bool Lock(int timeout_ms = 0) { /* 获取递归互斥锁 */  return true; }
    void Unlock() { /* 释放递归互斥锁 */ }
};

/*
如果是一个独占性资源，可以加锁
*/
class SingletonLockGuard {
public:
    SingletonLockGuard(SingletonClass *singletonPtr) : m_singelton(singletonPtr) {

        if (!singletonPtr) {
            return;
        }

        m_locked = true;
        if (!m_singelton->Lock(30000)) {
            std::cerr << "Failed to acquire lock in SingletonLockGuard" << std::endl;
            m_locked = false;
        }
    }

    ~SingletonLockGuard() {
        if (m_locked) {
            m_singelton->Unlock();
        }
    }

    bool IsLocked() const { return m_locked; }

private:
    SingletonClass *m_singelton;
    bool m_locked = false;
};
