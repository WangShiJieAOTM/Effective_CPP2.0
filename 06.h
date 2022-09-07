/**
* 06.若不想使用编译器自动生成的函数,就该明确拒绝
*/

class c1
{
private:
    c1();
};

c1::c1() {

}
class UnCopyable
{
protected:
    UnCopyable(){}
    ~UnCopyable(){}
private:
    UnCopyable(const UnCopyable&);
    UnCopyable& operator=(const UnCopyable&);
};
class c2 : private UnCopyable
{

};

class c3
{
public:
    c3() = delete;
};
/**
 * 三种手段可以实现对自动生成的函数拒绝:
 * 1.定义为 private函数
 * 2.继承 UnCopyable类
 * 3.明确写为delete
 */


