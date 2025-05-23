#No Dummy Node Approach

class Node():
    def __init__(self, value = None, next = None, prev = None):
        self.value = value
        self.next = next
        self.prev = prev

class Linked_List():

    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def append(self, value):
        current = self.head
        if self.size == 0:
            new_node = Node(value)
            self.tail = new_node
            self.head = new_node
            self.size += 1
        else:
            current = self.tail
            new_node = Node(value, None, current)
            current.next = new_node
            self.tail = new_node
            self.size += 1

    def print_node(self): 
        current = self.head
        while current.next is not None:
            print(f"{current.value} <-> ", end = "")
            current = current.next
        print(f"{current.value} <-> ", end = "")
        print("None")
    
    def insert_new_head(self, value):
        self.insert(value, 0)

    def insert(self, value, index):
        current = self.head
        if index > self.size:
            print("Index out of range!")
            return
        if index == 0:
            new_node = Node(value, current)
            if current is not None:
                current.prev = new_node
            else:
                self.tail = new_node
            self.head = new_node
            self.size += 1
            return
        if index <= self.size // 2:
            for i in range(index - 1):
                current = current.next
            temp = current.next
            new_node = Node(value, temp, current)
            current.next = new_node 
            if temp is not None:
                temp.prev = new_node 
            else:
                self.tail = new_node 
            self.size += 1
        else:
            current = self.tail
            size = self.size - index
            for i in range(size):
                current = current.prev
            temp = current.next
            new_node = Node(value, temp, current)
            current.next = new_node
            if temp is not None:
                temp.prev = new_node
            else:
                self.tail = new_node 
            self.size += 1

    def delete(self, index):
        if self.size == 0:
            print("The Linked List is Empty")
            return
        current = self.head
        if index > self.size:
            print("Index out of range!")
            return
        if index == 0:
            self.head = current.next
            self.head.prev = None
            self.size -= 1
            return
        if index == self.size - 1:
            current = self.tail.prev
            current.next = None
            self.tail = current
            self.size -= 1
            return
        if index <= self.size // 2:
            for i in range(index - 1):
                current = current.next
            current.next = current.next.next
            current.next.prev = current
            self.size -= 1
        else:
            current = self.tail
            size = self.size - index
            for i in range(size):
                current = current.prev
            current.next = current.next.next
            current.next.prev = current
            self.size -= 1
    
    def pop(self):
        if self.size == 0:
            print("The Linked List is Empty")
            return
        current = self.tail.prev
        current.next = None
        self.tail = current
        self.size -= 1

    def find(self, value):
        if self.size == 0:
            print("The Linked List is Empty")
            return
        current = self.head
        index = 0
        while current.value != value:
            if current.next is not None:
                current = current.next
                index += 1
            else:
                print(f"Cannot find value: {value}")
                return
        print(f"{value} is at index: {index}")
        return index



linked_list = Linked_List()

linked_list.append(1)
linked_list.print_node()
linked_list.append(4)
linked_list.print_node()
linked_list.print_node()
# print("Size", linked_list.size)
linked_list.append(10)
linked_list.append(12)
# print("Size", linked_list.size)
linked_list.print_node()
linked_list.insert(11, 3)
linked_list.print_node()
linked_list.append(5)
linked_list.print_node()
linked_list.delete(2)
linked_list.find(5)
linked_list.print_node()