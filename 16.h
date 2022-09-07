/**
* 16.成对使用 new和delete时要采取相同形式
*/

#include<string>

namespace sixteen
{
    std::string* stringArray = new std::string[100];

    delete stringArray;

    //↑ new 的时候是new了一个数组  delete的时候应该也delete数组

    //正确的形式应该是下面这两种方式↓
    std::string* stringPtr1 = new std::string;
    std::string* stringPtr2 = new std::string[100];

    delete stringPtr1;
    delete [] stringPtr2;

}

/**
 * 如果你在 new表达式中使用[],必须在相应的 delete表达式中也使用 [].如果你在 new表达式中不使用 [],一定不要在相应的 delete表达式中使用 []
*/