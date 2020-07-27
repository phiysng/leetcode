#include "oj_header.h"

class Solution {
public:
	int countOdds(int low, int high) {
        // example:
		// 0 4 2
		// 0 5 3
		// 1 4 2
		// 1 5 3
		if (low == high) return low %2;
		int r = 0;
		if(low % 2)
		{
			++low;
			++r;
		}
		if(high % 2)
		{
			--high;
			++r;
		}

		return (high - low) / 2 + r;
		
	}
};
