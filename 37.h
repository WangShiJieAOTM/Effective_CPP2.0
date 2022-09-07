/**
* 37.绝不重新定义继承而来的缺省参数值
*/

namespace thirtySeven{
    class Shape
    {
        public:
        enum ShapeColor {Red, Green, Blue};
        virtual void draw(ShapeColor color = Red) const = 0;
    };

    class Rectangle: public Shape
    {
        public:
        virtual void draw(ShapeColor color = Green) const;//赋予了不同的缺省参数值!!!!


        //Shape sr* = new Rectangle();
        //sr.draw();//调用的是Rectangle::draw(ShapeColor color = Red) const
    };

    //为了运行期效率,如果缺省参数值是动态绑定的,编译器就必须有某种办法在运行期为 virtual 函数决定适当的缺省参数值.这样效率就很慢
    //所以C++在是实现的时候,使用的是静态绑定,也就是说,编译器在编译期就决定了缺省参数值,而不是在运行期决定
}

/**
* 绝对不要重新定义一个继承而来的缺省参数值,因为缺省参数值是静态绑定的,而不是动态绑定的,而 virtual 函数中唯一应该重写的东西是动态绑定的部分
*/