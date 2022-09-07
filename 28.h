/**
* 28.避免返回 handles指向对象成员内部成分
*/
#include<memory>

namespace twentyEight {
    class Point {
    public:
        explicit Point(int x, int y) : X(x), Y(y) {};

        void setX(int newVal) const;

        void setY(int newVal);

    private:
        int X;
        int Y;
    };

    struct RectData {
        explicit RectData(Point &coord1, Point &coord2) : ulhc(coord1), lrhc(coord2) {}

        Point ulhc;
        Point lrhc;
    };

    class Rectangle {
    public:
        Rectangle(Point &coord1, Point &coord2) : pData(new RectData(coord1, coord2)) {}

        const Point upperLeft() const { return pData->ulhc; }

        const Point &lowerRight() const { return pData->lrhc; }

    private:
        std::shared_ptr<RectData> pData;
    };

//    Point coord1(0, 0);
//    Point coord2(100, 100);
//
//    const Rectangle rec(coord1, coord2);

}


/**
 * 避免返回 handles (包括 references,指针,迭代器) 指向对象内部,遵守这个条款可以增加封装性,
 * 帮助 const 成员函数的行为 像个 const,并将发生 "dangling handles)的可能新降至最低
 */
