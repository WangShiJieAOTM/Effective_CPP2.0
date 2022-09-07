/**
* 18.让接口更容易被正确使用,不易被误用
*/
struct Day
{
    explicit Day(int d):val(d){}
    int val;
};
struct Month{
    explicit Month(int m):val(m){}
    int val;
};
struct Year{
    explicit Year(int y):val(y){}
    int val;
};

namespace eighteen
{
    class Date
    {
    public:
        Date(int month,int day,int year);//不好! 容易被误用

        Date(Month month,Day day,Year year);//不错  不容易误用  每个类还能做类型的值检查
    };
}
/**
 * 1.好的接口很容易被正确使用,不容易被误误用
 * 2.促进正确使用的方法包括接口的一致性,以及与内置类型的行为兼容
 * 3."阻止误用"的方法包括建立新类型,限制类型上的操作,束缚对象值,以及消除客户的资源管理责任
 * 4.智能指针可以定制删除器
*/