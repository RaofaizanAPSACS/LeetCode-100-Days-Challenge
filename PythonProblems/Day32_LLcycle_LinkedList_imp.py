'''
Problem link: 
https://leetcode.com/problems/linked-list-cycle/

Problem:
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.
'''

class Node:
    def __init__(self, val=None):
        self.val = val
        self.next = None

def hasCycle(head):
    dictionary = {}
    while head is not None:
        # storing the frequencies of the Node's
        dictionary[head] = dictionary.get(head, 0) + 1
        if dictionary[head] > 1:
            return True
        head = head.next
    return False
        

# driver code

temp = Node(3)
u = temp
u.next = Node(2)
u.next.next = Node(0)
u.next.next.next = Node(-4)
#u.next.next.next.next = u.next
print(hasCycle(u))