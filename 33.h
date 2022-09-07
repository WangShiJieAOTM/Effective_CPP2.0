/**
* 33.避免遮掩继承而来的名称
*/

namespace thirtyThree {
    class Base {
    private:
        int x;
    public:
        virtual void mf1() = 0;

        virtual void mf1(int);

        virtual void mf2();

        void mf3();

        void mf3(double);
    };

    class Derived : public Base {
    public:
        using Base::mf1;
        using Base::mf3;

        virtual void mf1();

        void mf3();

        void mf4();
    };
}

/**
 * 1.derived classes 内的名称会遮掩 base classes 内的名称,在 public 继承下从来没有人希望如此.
 * 2.为了让被遮掩的名称重新可见,可以使用 using 声明式,让被遮掩的名称重新可见.
*/