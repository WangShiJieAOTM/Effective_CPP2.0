/**
* 31. 将文件间的编译依存关系降至最低
*/

namespace thirtyOne {
    class Person {
    public:
        Person(const std::string &name, const Date &birthday);

        std::string name() const;

        std::string birthDate() const;

        std::string address() const;

    private:
        std::string theName;//实现细目
        Date theBirthDate;//实现细目
        std::string theAddress;//实现细目
    };
}
/**
 * 1.如果使用 object references 或者 object pointers 可以完成任务,就不要使用 objects
 * 2.如果能够,尽量以 class声明式替换 class定义式
 * 3.为声明式和定义式分别提供头文件
 */


/**
 * 1.支持 "编译依存关系" 的最小化的一般构想是:相依于声明式,不要相依于定义式.基于此构想的两个手段是 Handle classes 和 Interface classes.
 * 2.程序库头文件以 "完全且仅有声明式" 的形式存在,这种做法无论是否设计 templates 都适用.
*/