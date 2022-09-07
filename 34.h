/**
* 34.区分接口继承和实现继承的区别
*/

namespace thirtyFour {
    class Shape {
    public:
        vrtual void draw() const = 0; //声明为 pure virtual function 的目的是让 derived classes只继承函数的接口，而不继承函数的实现

        virtual void error(const std::string &msg);//声明 impure virtual function 的目的是让 derived classes继承函数的接口和缺省实现

        int objectID() const;
    };
    class Rectangle : public Shape {};
    class Ellipse : public Shape {};

}

/**
 * 1.接口继承和实现继承不同,在public继承之下,derived classes 总是继承 base class 的所有接口.
 * 2.pure virtual 函数只具体指定接口继承
 * 3.impure virtual 函数具体指定接口继承和缺省实现继承
 * 4.non-virtual 函数具体指定接口继承以及强制性实现继承
*/