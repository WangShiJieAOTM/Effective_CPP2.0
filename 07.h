/**
* 07.为多态基类声明 virtual 析构函数
*/

namespace seven {
    class TimeKeeper {
    public:
        TimeKeeper() = default;

        //~TimeKeeper();//析构时可能只是局部销毁
        virtual ~TimeKeeper() = default;
    };

    class AtomicClock : public TimeKeeper {
    };

    class WaterClock : public TimeKeeper {
    };

    class WristWatch : public TimeKeeper {
    };

    TimeKeeper* getTimeKeeper();


    TimeKeeper* ptk = getTimeKeeper();

    delete ptk;
}

/**
* !!! 注意 很多 STL的容器不带 virtual 析构函数
 * 1.Polymorphic(带有多态性质) base classes 应该声明一个 virtual 析构函数,如果 class带有任何virtual函数,它就应该拥有一个virtual析构函数
 * 2.Classes 的设计目的如果不是作为 base classes 使用,或不是为了具备多态,就不应该声明为 virtual(维护虚函数表会占用不必要的内存)
*/