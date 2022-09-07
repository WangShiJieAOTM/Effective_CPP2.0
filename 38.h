/**
* 38.通过复合出 has-a 或 "根据某物实现出"
*/

namespace thirtyEight
{
    class Address{};

    class PhoneNumber{};

    class Person
    {
    public:
    private:
        std::string name;
        Address address;
        PhoneNumber voiceNumber;
        PhoneNumber faxNumber;
    };

    template<class T>
    class Set
    {
    public:
        bool member(const T& item) const;
        void insert(const T& item);
        void remove(const T& item);
        std::size_t size() const;
    private:
        std::list<T> rep;
    };
}

/**
 * 1.复合的意义和 public继承完全不同
 * 2.在应用域,复合意味着 has-a,在实现域,复合意味着 "根据某物实现出"
*/