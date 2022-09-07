/**
* 39.明智而审慎地使用 private 继承
*/

namespace thirtyNine {
    class Person {
    };

    class Student : private Person {
    };
    //如果classes之间的继承关系是private的编译器不会自动将一个derived class的对象转换为base class的对象

    void eat(const Person &p);

    void study(const Student &s);


    class Timer {
    public:
        explicit Timer(int tickInterval);

        virtual void onTick() const;
    };

    //private继承的方式实现
    class Widget : private Timer {
    private:
        virtual void onTick() const;//查看Widget的数据等等
    };
    class Widget2
    {
    private:
        class WidgetTimer : public Timer
        {
        public:
            WidgetTimer(Widget2 *theWidget, int tickInterval);
        private:
            virtual void onTick() const;
            Widget2 *widget;
        };
        WidgetTimer timer;
    };

}

/**
 * 1.private 继承意味着根据某物实现出,他通常比复合的级别低,但是当 derived class 需要访问 protected base class 的成员
 * 或需要重新定义继承而来的 virtual函数时, 这样设计是合理的
 * 2.和复合不同,private继承可以造成 empty base 最优化,对于对象尺寸最小化有要求的程序库,可能很重要.
*/