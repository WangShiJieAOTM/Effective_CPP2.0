/**
* 29.为"异常安全" 而努力是值得的
*/
#include<iostream>

namespace twentyNine
{
    class PrettyMenu
    {
    public:
        void changBackground(std::istream& imgSrc);

    private:
        Muex mutex;
        Image* bgImage;
        int imageChanges;
    };

    void PrettyMenu::changBackground(std::istream &imgSrc) {
        lock(&mutex);
        delete bgImage;
        ++imageChanges;
        bgImage  = new Image(imgSrc);
        unlock(&mutex);9
    }
}