#include <gtest/gtest.h>
#include <iostream>
#include <thread>
#include <vector>

class Singleton {
public:
    static Singleton* getInstance() {
        if (_instance == nullptr) {
            _instance = new Singleton();
        }
        return _instance;
    }

private:
    static Singleton* _instance;
    Singleton() {
        std::cout << "singleton..." << std::endl;
    }
};

Singleton* Singleton::_instance = nullptr;

TEST(SingletonTest, SingleInstanceWithoutThreads) {
    Singleton* sgn1 = Singleton::getInstance();
    Singleton* sgn2 = Singleton::getInstance();
    ASSERT_EQ(sgn1, sgn2);
}

TEST(SingletonTest, ThreadSafety) {
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back([]() {
            Singleton::getInstance();
        });
    }

    for (auto& thread : threads) {
        thread.join();
    }

    Singleton* sgn1 = Singleton::getInstance();
    Singleton* sgn2 = Singleton::getInstance();
    ASSERT_EQ(sgn1, sgn2);
}

TEST(SingletonTest, MultipleInstancesWithoutThreadSafety) {
    Singleton* sgn1 = Singleton::getInstance();
    Singleton* sgn2 = nullptr;
    Singleton* sgn3 = nullptr;

    std::thread t1([&]() {
        sgn2 = Singleton::getInstance();
    });

    std::thread t2([&]() {
        sgn3 = Singleton::getInstance();
    });

    t1.join();
    t2.join();

    ASSERT_NE(sgn1, sgn2);
    ASSERT_NE(sgn1, sgn3);
    ASSERT_NE(sgn2, sgn3);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

