/**
* 13.以对象管理资源
*/

namespace thirteen
{
    //资源取得时机便是初始化时机 RAII
    //1.获取资源后立即放进管理对象
    //2.管理对象运用析构函数确保资源被释放
}
/**
 * 1.为了防止资源泄漏,请使用RAII对象,他们在构造函数中获得资源并在析构函数中释放资源
 * 2.常用的RAII类智能指针  多使用智能指针能够有效防止资源泄漏
*/