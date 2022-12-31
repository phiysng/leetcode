class Solution {
    fun romanToInt(s: String): Int {
        /**
         * I             1
         * V             5
         * X             10
         * L             50
         * C             100
         * D             500
         * M             1000
         *
         * I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
         * X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
         * C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
         */

        if (s.isEmpty())
            return 0;
        return romanToInt(s, 0)
    }

    fun romanToInt(s: String, index: Int): Int {
        val romanChar = s[index]
        var value =
            when (romanChar) {
                'I' -> 1
                'V' -> 5
                'X' -> 10
                'L' -> 50
                'C' -> 100
                'D' -> 500
                'M' -> 1000
                else -> 0
            }
        if(index > 0){
            val prevRomanChar = s[index-1]
            if((romanChar == 'V' || romanChar == 'X') && prevRomanChar == 'I'){
                value -= 2
            }
            if((romanChar == 'L' || romanChar == 'C') && prevRomanChar == 'X'){
                value -= 20
            }
            if((romanChar == 'D' || romanChar == 'M') && prevRomanChar == 'C'){
                value -= 200
            }
        }
        val nextIndex = index + 1
        if (nextIndex >= s.length)
            return value
        return value + romanToInt(s, nextIndex)
    }
}