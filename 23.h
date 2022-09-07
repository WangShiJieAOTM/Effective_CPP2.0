/**
 * 23.宁以 non-member,non-friend 替换 member函数
*/

namespace twentyThree
{
    class WebBrowser
    {
    public:
        void clearCache();
        void clearHistory();
        void removeCookies();
    };

    void clearBrowser(WebBrowser& wb)
    {
        wb.clearCache();
        wb.clearHistory();
        wb.removeCookies();
    }

}
namespace WebBrowserStuff
{
 class WebBrowser
 {

 };

}
// in "WebBrowserBookMark.h"
namespace WebBrowserStuff
{

}

// in "WebBrowserCookies.h"
namespace WebBrowserStuff
{

}

/**
* 宁可拿 non-member non-friend 函数替换 member函数,这样做可以增加封装性,包裹弹性和机能扩展性
*/