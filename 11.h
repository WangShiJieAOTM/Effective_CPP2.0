/**
* 在 operator= 中处理 "自我赋值"
*/

//潜在的自我赋值情况
#include <bitset>

namespace eleven
{
    class Widget{
        //出现自我赋值的情况   在pb = new bitset(*rhs.pb);的时候 rhs.pb已经被delete  出错
        Widget& Widget::operator=(const Widget &rhs){
            delete pb;
            pb = new bitset<8>(*rhs.pb);
            return *this;
        }

        //证同测试
        Widget& Widget::operator=(const Widget &rhs) {
            if(this == &rhs)return *this;
            delete pb;
            pb = new bitset<8>(*rhs.pb);
            return *this;
        }

        //删除之前先记住
        Widget& Widget::operator=(const Widget &rhs) {
            bitset<8>* pOrig = pb;
            pb = new bitset<8>(*rhs.pb);
            delete pOrig;
            return *this;
        }

        void Widget::swap(Widget& rhs)
        {

        }
        Widget& Widget::operator=(const Widget &rhs) {
            Widget temp(rhs);
            swap(temp);
            return *this;
        }
    };
}
/**
 * 1.确保当对象自我赋值时 operator= 有良好行为,其中技术包括比较 "来源对象" 和 "目标对象" 的地址,精心周到的语句顺序,以及copy-and-swap
 * 2.确定任何函数如果操作一个以上的对象,而其中多个对象是同一对象时,其行为依然正确.
*/