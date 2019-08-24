impl Solution {
    pub fn merge_two_lists(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        //递归 返回当前两个链表的最小的节点
        let some_box_list = |val, next| Some(Box::new(ListNode { val, next }));

        match( l1 , l2){
            (Some(v1), None) => Some(v1), 
            (None, Some(v2)) => Some(v2), 
            (Some(mut v1), Some(mut v2)) => {
                if v1.val < v2.val {
                    some_box_list(v1.val , Self::merge_two_lists(v1.next, Some(v2)))
                }
                else{
                    some_box_list(v2.val , Self::merge_two_lists(v2.next, Some(v1)))
                }
             },
            _ => None
        }

    }
}
