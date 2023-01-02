class Solution {
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
     *
     * 1 <= num <= 3999
     *
     */
    fun intToRoman(num: Int): String {
        val buffer = StringBuffer()
        intToRoman(num, buffer)
        return buffer.toString()
    }

    companion object {
        val map = listOf(
            1000 to "M",
            900 to "CM",
            500 to "D",
            400 to "CD",
            100 to "C",
            90 to "XC",
            50 to "L",
            40 to "XL",
            10 to "X",
            9 to "IX",
            5 to "V",
            4 to "IV",
            1 to "I"
        )
    }

    private fun intToRoman(num: Int, buffer: StringBuffer) {
        if (num <= 0) return;
        for ((value, roman) in map) {
            if (num >= value) {
                buffer.append(roman)
                return intToRoman(num - value, buffer)
            }
        }
    }
}
