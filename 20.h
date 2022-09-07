/**
* 20.宁以 pass-by-reference-to-const 替换 pass-by-value
*/

//减少使用 pass-by-value的方式传递参数  可以有效地减少无谓的构造和新(临时)对象的创建

//切割问题
namespace twenty {
    class Base {

    };

    class Derived : public Base {

    };

    void f(Base b){}

    void f1(const Base& b){}

    Derived* b1 = new Derived();

    f(b1);//出现切割
    f1(b1);
}
/**
 * 1.尽量以 pass-by-reference 替换 pass-by-value,前者通常比较高效,并且可以避免切割问题
 * 2.以上规则不适用于内置类型,以及 STL的迭代器和函数对象,对天猫而言, pass-by-value往往比较适当
*/