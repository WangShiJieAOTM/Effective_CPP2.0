/**
* 25.考虑写出一个不抛出异常的 swap函数
*/

#include<vector>

namespace twentyFive {
    class WidgetImpl {
    public:
    private:
        int a, b, c;
        std::vector<double> v;
    };

    class Widget {
    public:
        Widget(const Widget &rhs);

        Widgt &operator=(const Widget &rhs) {
            *pImpl = *(rhs.pImpl);
        }

        // 1. public swap member function
        void swap(Widget &other) {
            using namespace std::swap;
            swap(pImpl, other.pImpl); // swap pointer
        }

    private:
        WidgetImpl *pImpl;
    };

    // std::swap function 的偏特化版本
    namespace std {
        template<>
        void swap<Widget>(Widget &a, Widget &b) {
            a.swap(b);
        }
    }


    namespace WidgetStuff {
        class WidgetImpl {
        public:
        private:
            int a, b, c;
            std::vector<double> v;
        };
        template<typename T>
        class Widget {

        public:
            void swap(Widget &other)
            {
                swap(pImpl,other.pImpl);
            }
        private:
            WidgetImpl *pImpl;
        };
        //2.在命名空间内使用一个 non-member swap 函数实现swap
        //因为std的命名空间内不允许使用携带模板的偏特化(函数模板)
        template<typename T>
        void swap(Widget<T> &a, Widget &b) {

        }
    }
}

/**
* 如果 swap的缺省实现版本的效率不足,那几乎总是意味着你的 class 或 template 提供了某种 pimpl手法
 * 1.提供一个 public swap 成员函数,让他高效的置换你的类型的两个对象值,这个函数绝不该抛出异常.
 * 2.在你 class 或 template所在的命名空间内提供一个 non-member swap,并令他调用上诉 swap成员函数
 * 3.如果你正编写一个 class 而非 class template为你的 class 特化 std::swap 并令他调用你的swap函数
*/

/**
* 请记住:
 * 1. 当std::swap对你的了类型效率不高时,提供一个 swap 成员函数,并确定这个函数不抛出异常
 * 2. 如果你提供一个 member swap,也该提供一个 non-member swap 用来调用前者,对一classes 而非template也请特好std::swap
 * 3. 调用 swap时应针对 std::swap 使用 using 声明式,然后调用 swap 并且不带任何 "命名空间资格修饰"
 * 4. 用 "用户定义类型" 进行 std template 全特化是好的,但前往不要尝试在 std内加入某些对 std 而言全新的东西
*/