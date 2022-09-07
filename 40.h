/**
* 40.明智而审慎地使用多重继承
*/

namespace forty {
    class BorrowableItem {
    public:
        void checkOut();
    };

    class ElectronicGadget {
        bool checkOut() const;
    };

    class MP3Player : public BorrowableItem, public ElectronicGadget {
    }

    //MP3Player mp;
    //mp.checkOut();//error,因为checkOut()是一个overloaded function,编译器不知道调用哪个


    class File {
    };

    class InputFile : public File {
    };

    class OutputFile : public File {
    };

    class IOFile : public InputFile, public OutputFile {
    };
    //↑这种情况下,IOFile对象既是InputFile对象,也是OutputFile对象,但是它不是File对象,因为File不是IOFile的直接基类
    //菱形继承


}
//1.多重继承同名的问题
