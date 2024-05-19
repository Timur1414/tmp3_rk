#include <gtest/gtest.h>
#include <iostream>

class Singleton {
public:
    static Singleton* getInstance() {
        if (_instance == 0) {
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

Singleton* Singleton::_instance = 0;

TEST(SingletonTest, GetInstance) {
    Singleton* sgn1 = Singleton::getInstance();
    Singleton* sgn2 = Singleton::getInstance();
    ASSERT_EQ(sgn1, sgn2);
}

TEST(SingletonTest, DeleteInstance) {
    Singleton* sgn1 = Singleton::getInstance();
    Singleton* sgn2 = Singleton::getInstance();
    delete sgn1;
    ASSERT_NO_THROW(Singleton::getInstance());
}

TEST(SingletonTest, MultipleInstances) {
    Singleton* sgn1 = Singleton::getInstance();
    Singleton* sgn2 = Singleton::getInstance();
    Singleton* sgn3 = Singleton::getInstance();
    ASSERT_EQ(sgn1, sgn2);
    ASSERT_EQ(sgn2, sgn3);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

