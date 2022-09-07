/**
* 26.尽可能延后变量定义式的出现时间
*/
#include<string>

namespace twentySix
{
    size_t MinimumPasswordLength = 100;
    std:: string encryptPassword(const std::string& password)
    {
        using namespace std;
        string encrypted;//太早构造  如果下面的内容抛出错误  这一行就没有意义

        if(password.length() < MinimumPasswordLength)
        {
            throw logic_error("Password is too short");
        }
        encrypted = password;
        return encrypted;
    }
}

/**
* 尽可能延后变量定义式的出现,这样做可以增加程序的清晰度并改善程序效率
*/