# -*- coding: utf-8 -*-
"""
Created on Tue May 14 19:44:35 2019

@author: HZJ
"""

import logging


class Node():
    def __init__(self, next_node=None):
        self.next_node = next_node


class Student(Node):
    def __init__(self, next_node=None, name='', num=0):
        Node.__init__(self, next_node)
        self.name = name
        self.num = num
        
    def __str__(self):
        return 'Student Node (name: %s, num: %02d)' % (self.name, self.num)
        

class UniDLinked():
    '''
    单向链表
    param:
        head: Node object, head of the list
        length: int, length of the list
    '''        
    def __init__(self, head=None, length=0):
        self.head = head
        self.length = length
    
    def append(self, node):
        if not self.head:
            self.head = node
        else:
            ptr = self.head
            while ptr.next_node:
                ptr = ptr.next_node
            ptr.next_node = node
        self.length += 1
            
    def pop(self):
        if not self.head:
            print('No element in list. Fail to pop!')
            return None
        else:
            ptr = self.head
            for _ in range(self.length - 1):
                ptr = ptr.next_node
            ptr.next_node = None
            self.length -= 1
            return ptr
        
    def insert(self, node, inx):
        if inx == 1:
            node.next_node = self.head
            self.head = node
            self.length += 1
        elif inx > self.length + 1:
            print('inx out of range. Fail to insert!')
        else:
            ptr = self.head
            for _ in range(inx - 2):
                ptr = ptr.next_node
            ptr.next_node, node.next_node = node, ptr.next_node
            self.length += 1
            
    def remove(self, inx):
        temp = None
        if not self.head:
            print('No element in list. Fail to remove!')
            return None
        elif inx == 1:
            temp, self.head = self.head, self.head.next_node
            self.length -= 1
            return temp
        else:
            ptr = self.head
            for _ in range(inx - 2):
                ptr = ptr.next_node
            temp, ptr.next_node = ptr.next_node, ptr.next_node.next_node
            self.length -= 1
            return temp
        
    def reverse(self):       
        p = self.head
        q = None
        while p:
            r = q
            q = p
            p = p.next_node
            q.next_node = r
        self.head = q
    
    def disaplay(self):
        ptr = self.head
        while ptr:
            print(ptr)
            ptr = ptr.next_node

    def __str__(self):
        return 'LinkedList object [head: %s; length: %02d]' % (self.head.__str__(), self.length)
    

if __name__ == '__main__':
    l1 = UniDLinked()
    s1 = Student(None, '东哥', 1)
    s2 = Student(None, '西哥', 2)
    s3 = Student(None, '南哥', 3)
    s4 = Student(None, '北哥', 4)
    l1.append(s1)
    l1.append(s2)
    l1.append(s3)
    l1.append(s4)
    l1.reverse()
    l1.disaplay()
    print(l1)