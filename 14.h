/**
* 在资源管理类中小心 copying行为
*/

namespace fourteen
{


}
/**
 * 1.复制 RAII对象必须一并复制它管理的资源,所以资源的 copying行为决定 RAII对象的copying
 * 2.普遍而常见的 RAII class copying 行为是: 抑制 coping (delete或者private),施行引用计数法(使用shared_ptr).
*/