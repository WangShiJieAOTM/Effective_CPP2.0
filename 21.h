/**
* 21.必须返回对象时,别妄想返回 reference
*/

namespace twentyOne
{

}

/**
 * 绝对不要返回 pointer 或 reference指向一个local stack对象,或返回 reference指向一个 heap-allocated对象
 * 或返回 pointer 或 reference指向一个 local static对象而有可能同时需要多个这样的对象.  直接返回 pass-by-value更好
*/