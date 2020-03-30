class Solution
{
public:
    int numberOfSteps(int num)
    {
        int times = 0;

        while (num)
        {
            if (num % 2 == 1)
            {
                --num;
            }
            else
            {
                num /= 2;
            }
            ++times;
        }

        return times;
    }
};
