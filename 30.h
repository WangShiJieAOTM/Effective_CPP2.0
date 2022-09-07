/**
* 30. 透彻了解 inlining 的里里外外
*/


namespace thirty {
    class Person {
    public:
        int age() const { return theAge; }

    private:
        int theAge;
    };
}

// STL 标准的 max 函数如下↓
template<typename T>
inline const T &std::max(const T &a, const T &b) {
    return a < b ? b : a;
}

/**
 * 1.绝大多数 inlining 限制在小型，被频繁调用的函数身上。这可使日后调试过程和二进制升级更加容易，也可使得潜在的代码膨胀问题最小化，是程序的速度提升机会最大化
 * 2.不要只因为 function templates 出现在头文件，就将它们声明为 inline
*/