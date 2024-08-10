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
    pub fn reverse_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if head.is_none() {
            return head;
        }

        let mut  prev : Option<Box<ListNode>> = Option::None;
        let mut curr : Option<Box<ListNode>> = head;
        while  curr.is_some() {
            let mut curr_box = curr.unwrap();
            let next = curr_box.next.take();

            curr_box.next = prev;
            prev = Some(curr_box);
            curr = next;
        }

        prev
    }
}