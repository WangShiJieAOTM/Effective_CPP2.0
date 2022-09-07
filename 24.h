/**
 * 24.若所有参数皆需类型转换,请为此采用 non-member函数
 */

namespace twentyFour
{
    class Rational
    {
    public:
        Rational(int numerator = 0,int denominator = 1);
        int numerator()const;
        int denominator()const;

        const Rational operator* (const Rational& rhs)const;


    private:
    };

    const Rational operator*(const Rational& lhs,const Rational& rhs)
    {
        return Rational(lhs.numerator()*rhs.numerator(),lhs.denominator()*rhs.denominator())
    }
}
/**
* 如果你需要为某个函数的所有参数(包括被 this 指针所指的那个隐喻参数)进行类型转换,那么这个函数必须是个 non-member
*/