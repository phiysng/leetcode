class Solution{
    fun evalRPN(tokens: Array<String>): Int {
        val stack = ArrayDeque<Int>();

        for (token in tokens) {
            if (token == "+") {
                val op1 = stack.removeLast()
                val op2 = stack.removeLast()
                stack.addLast(op2 + op1)
            } else if (token == "-") {
                val op1 = stack.removeLast()
                val op2 = stack.removeLast()
                stack.addLast(op2 - op1)

            } else if (token == "*") {
                val op1 = stack.removeLast()
                val op2 = stack.removeLast()
                stack.addLast(op2 * op1)

            } else if (token == "/") {
                val op1 = stack.removeLast()
                val op2 = stack.removeLast()
                stack.addLast(op2 / op1)

            } else {
                val value = token.toInt()
                stack.addLast(value);
            }
        }
        return stack.last();
    }
}