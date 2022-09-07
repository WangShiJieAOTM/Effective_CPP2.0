/**
* 41.了解隐式接口和编译期多态
*/

namespace fortyOne {
    class Widget {
    public:
        Widget();

        virtual ~Widget();

        virtual std::size_t size() const;

        virtual void normalize();

        void swap(Widget &other);
    };

    template<typename T>
    void doProcessing(T& w)
    {
        if(w.size()>10&&w!=someNetyWidget)
        {
            T temp(w);
            temp.normalize();
            temp.swap(w);
        }
    }
}
/**
 * 1.classes 和 templates 都支持接口和多态
 * 2.对 classes而言接口是显式的,以函数签名为中心,多态则是通过 virtual函数发生于运行期
 * 3.对 templates而言,接口是隐式的,奠基于有效表达式,多态则是通过template具现化和函数重载解析发生于编译期
*/