/**
* 42.了解 typename的双重意义
*/
namespace fortyTwo {
    template<typename T>
    class Widget1 {
    };

    template<class T>
    class Widget2 {
    };

    //↑两者等价

    //嵌套从属名称会出现解析(parsing)困难
    template<typename T>
    void print2nd() {
        T::const_iterator *x;//这里不知道C::const_iterator是一个类型还是一个成员变量
        typename T::const_iterator *y;//这里明确知道C::const_iterator是一个类型
    };
}


/**
 * 1.声明 template 参数时,typename和 class是等价的
 * 2.请使用关键字 typename来标识嵌套从属类型名称,但不得在 base class list(基类列)或者
 * member initialization list(成员初值列)内为base class修饰符号
*/