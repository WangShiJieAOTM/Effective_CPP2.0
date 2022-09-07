/**
* 27.尽量少做转型动作
*/

namespace twentySeven
{
    //C++ 提供四种新式转型 (通常被称为 new-style 或 c++ style casts)
    //1.const_cast<T>(expression)
    //通常被用来将对象的常量性移除(cast away the constness) 他是唯一有此能力的C++ style 转型操作符
    //2.dynamic_cast<T>(expression)
    //主要被用来执行 "安全向下转型"(safe downcasting),也就是用来决定某对某对象是否附属继承体系中的某个类型,
    //他是唯一无法由旧式语法执行的动作,也是唯一可能耗费重大运行成本的转型动作
    //3.reinterpret_cast<T>(expression)
    //reinterpret_cast意图执行低级转型,实际动作(及结果)可能取决于编译器,这也表示他不可移植,例如一个
    //pointer to int 转型为一个 int ,这一类转型在低级代码以外很少见
    //4.static_cast 来强迫隐式转换,例如将 non--const对象转为const对象,或将int对象转换为double等等
    //他也可以用来执行上诉多种转换的反向转换,例如将 void* 指针 转换为typed 指针,将pointer-to-base转换
    //为 pointer-to--derived,但他无法将 const 转换为 non-const 这一点只有const_cast能够做到


    /**
     * 旧式转型仍然合法,但是新式转型较受欢迎,原因是:
     * 1.他们很容易在代码中被便是出来,因而得以简化 "找出类型系统在哪个地点被破坏"
     * 2.各转型动作的目标越窄化,编译器越可能诊断出错误的应用,例如,如果你打算将常量性去掉,除非使用新式转型中的const_cast否则无法通过编译
     */
}

/**
 * 1.如果可以,尽量避免转型,特别是在注重效率的代码中避免使用 dynamic_cast,如果有个设计需要转型动作,试着发展无需转型的替代设计
 * 2.如果转型是必要的,摄者将他隐藏在某个函数背后,客户随后可以调用该函数,而不需要将转型放在他们自己的代码内
 * 3.宁可使用 C++ style(新式) 转型,不要使用旧式转型,前者很容易辨识出来,而且也比较有着分门别类的功能
*/