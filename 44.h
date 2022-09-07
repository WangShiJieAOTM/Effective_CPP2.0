/**
* 44.将与参数无关的代码抽离 templates
*/

namespace fortyFour {
    template<typename T, std::size_t n>
    class SquareMatrix {
    public:
        void invert();
    };
}