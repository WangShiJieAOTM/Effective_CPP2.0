/**
* 以独立语句将 newed对象置入智能指针
*/
#include<memory>

namespace seventeen
{
    class Widget
    {

    };
    int priority();
    void processWidget(std::shared_ptr<Widget>, int priority);

    //不要这样调用
    processWidget(new Widget,priority());
    //因为 万一priority()函数抛出异常  这时候 new出来的Widget 就可能会丢失指针导致内存泄漏

    //正确是做法是用独立的语句将 newed对象置入智能指针↓

    std::shared_ptr<Widget> pw(new Widget);

    processWidget(pw,priority());
}

/**
 * 以独立语句将 newed对象存储于 (置入)智能指针内,如果不这样做,一旦异常被抛出,有可能导致难以察觉的资源泄漏
 */
