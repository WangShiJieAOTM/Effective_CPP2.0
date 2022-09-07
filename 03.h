/**
*  03.尽可能使用 const
 *  1.const 允许指定一个语义约束,编译器会强行实行这项约束
*/
namespace three
{
    char greeting[] = 'Hello';

    char* p = greeting;
    const char* p = greeting;//non-const pointer const data
    char* const p = greeting;//const pointer non-const data
    const char* const p = greeting;//const pointer const data

}
//引入 mutable 来允许在const成员函数对被mutable修饰的变量进行修改

/**
* 当 const 和 non-const 成员函数有着实质等价的实现时,令non-const版本调用const版本可避免代码重复
*/