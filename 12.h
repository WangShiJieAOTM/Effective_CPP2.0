/**
* 复制对象时勿忘其每一个成分
*/

namespace twelve
{

}
/**
 * 1. Copying 函数应该确保复制 "对象内的所有与成员变量" 及 "所有 base class成分"
 * 2. 不要尝试以某个 copying函数实现另一个 copying函数.应该将共同机能放进第三个函数中,并由两个coping函数共同调用
*/