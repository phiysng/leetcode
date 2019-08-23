use std::cmp::max;
use std::collections::HashMap;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut map = HashMap::new();

        let mut answer = 0;
        let mut before = -1; //当前字符串开始的前一个位置 即前一个重复子串的位置
        let mut current = 0; //当前字符结尾的位置

        for ch in s.chars(){
            // 如果字符串已经存在的话
            //map如果已存在返回现在的值
            //如果更新之前不存在 则这个值 c 肯定不会重复
            if let Some(last) = map.insert(ch, current){
                // 如果说出现的位置在before之前没有影响 更新新的位置就好
                // 如果出现在(before, current),则这个字串重复了，
                // 则只能从出现的这个位置的后一位开始取子串
                before = max(before,last);
            }
            answer = max(answer,current-before);
            current +=1;
        }
        answer
    }
}
