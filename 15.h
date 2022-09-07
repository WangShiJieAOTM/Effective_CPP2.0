/**
 * 15.在资源管理类中提供对原始资源的访问
*/
#include <memory>

namespace fifteen
{
    class Investment
    {
    public:
        bool isTaxFree() const;
    };

    Investment* crestInvestment();

    std::shared_ptr<Investment> pi1(crestInvestment());
    bool taxable1 = !(pi1->isTaxFree());

    std::unique_ptr<Investment>pi2(crestInvestment());

    bool taxable2 = !((*pi2).isTaxFree());
}

/**
 * 1.APIs 往往要求访问原始资源,所以每一个 RAII class 应该提供一个 "取得其所管理之资源" 的办法
 * 2.对原始资源的访问可能经由显示转换或隐性转换.一般而言显示转换比较安全,但隐式转换对客户比较方便
 */
