/**
* 04.确定对象被使用前已先被初始化
*/
#include<string>
#include<list>
namespace four
{
    class PhoneNumber
    {

    };
    class ABEntry{
    public:
        ABEntry(const std::string& name ,const std::string& address,
                const std::list<PhoneNumber>& phones);
    private:
        std::string theName;
        std::string theAddress;
        std::list<PhoneNumber>thePhones;
        int numTimeConsulted;
    };

    //这是 initialization (初始化) 不是 assignments (赋值)
    ABEntry::ABEntry(const std::string &name, const std::string &address, const std::list<PhoneNumber> &phones):
    theName(name),
    theAddress(address),
    thePhones(phones),
    numTimeConsulted(0)
    {}

//    //这是 assignments (赋值) 不是 initialization (初始化)
//    ABEntry::ABEntry(const std::string &name, const std::string &address, const std::list<PhoneNumber> &phones) {
//        theName = name;
//        theAddress = address;
//        thePhones = phones;
//        numTimeConsulted = 0;
//    }

    /**
     * 对于一些无法确定初始化顺序的情况 可以将每个 non-local static对象搬到自己专属的函数内(该对象在此函数内被声明为 static)
     * 这些函数返回一个reference指向他所含的对象 这是单例模式的常见实现手法
     */
     class FileSystem{
     public:
         std::size_t  numDisks()const;
     };

     //这个函数用来替代tfs对象 也就是extern FileSystem tfs
     //这样可以确保子类调用这个对象的时候这个对象已经进行了初始化 (跨编译单元)
     FileSystem& tfs()
     {
         static FileSystem fs;
         return fs;
     }

     class Directory{
         Directory();
     };
     Directory::Directory() {
         std::size_t disks = tfs().numDisks();
     }

}

/***
 * 1.将内置型对象进行手工初始化, 因为 C++不保证初始化它们
 * 2.构造函数最好使用成员初值列,而不要在构造函数体内使用赋值操作,初值列列出的成员变量其排列次序和它们在class中的声明次序相同
 * 3.为了免除跨编译单元的初始换次序问题 以 local static 对象替换 non-local static 对象
*/