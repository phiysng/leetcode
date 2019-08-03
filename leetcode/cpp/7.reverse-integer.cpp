class Solution {
public:
	int reverse(int _x) {
		bool neg = _x < 0 ? true : false;
        
        
		int64_t x = abs<int64_t>(_x);
		int res = 0;
		while (x)
		{
			int t = x % 10;
			x /= 10;
            if((INT_MAX - t) / 10 < res){
                return 0;
            }
			res = res * 10 + t;
		}
		res = (neg ? -res : res);
		return res;
	}
};
