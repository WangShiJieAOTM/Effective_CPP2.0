/**
* 02.尽量以 const,enum,inline 替代 #define
 * 1.#define 只是简单的文本替换,不会在编译期被编译期进行检查
 * 2.class const member must be static (确保只有一个实体)
 * 3.#define can't not realized in class namespace
*/
#include<iostream>
#define CALL_WITH_MAX(a,b) f((a) > (b) ? (a) : (b))
void f(int a)
{
    std::cout<<a<<std::endl;
}
class GamePlayer
{
private:
    enum {NumTurn = 5};//使用 enum hack 可以在class namespace 中实现 #define的功能且他和const相比不能被寻址
    //且有些不够优秀的编译器不会将 const 加入常量区,这会造成内存的分配  用enum来替代#define就不会导致非必要的内存分配

    int score[NumTurn];

    template<class T>
    inline void callWithMax(const T& a,const T&b)
    {
        f(a > b ? a : b);
    }
};