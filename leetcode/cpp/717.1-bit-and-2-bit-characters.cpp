class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits)
    {
        int i = 0;
        for (i = 0; i < bits.size() - 1; ++i) {
            if (bits[i])
                ++i;
        }
        return i == bits.size() - 1;
    }
};