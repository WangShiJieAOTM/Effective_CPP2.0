/**
 * 32.确定你的 public 继承是“is-a”的关系
*/

namespace thirtyTwo{
    class Bird
    {
    public:
        virtual void fly();
    };
    class Penguin :public Bird  // 企鹅不会飞 不是 is-a 的关系
    {

    };
}
/**
* "public" 继承意味着 "is-a" 关系,适用于 base classes 身上的每一件事情都适用于 derived classes,因为每一个 derived class 都是一个 base class.
*/