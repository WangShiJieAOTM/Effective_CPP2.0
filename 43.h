/**
* 43.学习处理模板化基类内的名称
*/

namespace fortyThree {
    class companyA {
        void sendCleartext(const std::string &msg) const;

        void sendEncrypted(const std::string &msg) const;
    };

    class companyB {
        void sendCleartext(const std::string &msg) const;

        void sendEncrypted(const std::string &msg) const;
    };

    //用来保存信息,以备将来产生信息
    class MsgInfo {
    };

    template<typename Company>
    class MsgSender {
    public:
        void sendClear(const MsgInfo &info) {
            Company c;
            c.sendCleartext(info);
        }

        void sendSecret(const MsgInfo &info) {
            Company c;
            c.sendEncrypted(info);
        }
    };

    class CompanyZ {
    public:
        void sendEncrypted(const MsgInfo &info);//不提供 sendCleartext()函数
    };

    template<typename Company>
    class LoggingMsgSender : public MsgSender<Company> {
    public:
        void sendClear(const MsgInfo &info) {
            //记录日志
            sendClear(info);
            //不行  因为 编译器不知道是否有sendCleartext函数  line 27 如果传入的是CompanyZ作为template参数,就没有这个函数
            //解决方法:
            //1.在base class 函数调用动作之前加上this->
            this->sendClear(info);//成立,假设sendClear被继承
            //2.使用using声明
            using MsgSender<Company>::sendClear; //告诉编译器,请他假设sendClear 位于 base class中
            sendClear(info);//成立,假设sendClear被继承
            //3.明白指出被调用函数位于base class中
            MsgSender<Company>::sendClear(info);//成立,假设sendClear被继承
        }
    };
}

/**
* 可在 derived class template 内通过 "this->"指向base class template内的成员名称,或借由明白写出的 "base class 资格修饰符"完成
*/