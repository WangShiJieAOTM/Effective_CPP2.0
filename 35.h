/**
* 35.考虑 virtual 函数以外的其他选择
*/

namespace thirtyFive{
    // 藉由Non-Virtual Interface 手法实现 Template Method 模式

    class GameCharacter {
        public:
        int healthValue() const;
        {
            int retVal = doHealthValue();
            return retVal;
        }
    private:
        virtual int doHealthValue() const
        {
            return 0;
        }
    };
}