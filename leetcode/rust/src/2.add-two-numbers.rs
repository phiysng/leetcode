// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        Self::add(l1,l2,0)
    }

    fn add(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>, carry: i32) -> Option<Box<ListNode>>{
        let mut sum = carry;
        
        let next_lhs = if let Some(nodel) = l1{
            sum += nodel.val;
            nodel.next
        }else{
            None
        };

        let next_rhs = if let Some(noder) = l2{
            sum += noder.val;
            noder.next
        } else{
            None
        };

        let mut sum_node = ListNode::new( sum % 10);

        if next_lhs != None || next_rhs != None || sum >= 10{
            sum_node.next = Self::add(next_lhs,next_rhs,sum / 10);
        }
        Some(Box::new(sum_node))

    }
}
