#Dummy Node Approach

class Node():
    def __init__(self, value = None, next = None):
        self.value = value
        self.next = next

class Linked_List():

    def __init__(self):
        self.head = None
        self.size = 0

    def append(self, value):
        current = self.head
        if self.size == 0:
            new_node = Node(value)
            self.head = new_node
            self.size += 1
        else:
            while current.next is not None:
                current = current.next
            new_node = Node(value)
            current.next = new_node
            self.size += 1

    def print_node(self):
        current = self.head
        while current.next is not None:
            print(f"{current.value} -> ", end = "")
            current = current.next
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
            self.head = new_node
            self.size += 1
            return
        for i in range(index - 1):
            current = current.next
        temp = current.next
        current.next = Node(value, temp)
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
            self.size -= 1
            return
        for i in range(index - 1):
            current = current.next
        current.next = current.next.next
        self.size -= 1
    
    #Via Two Pointer Approach
    def pop(self):
        if self.size == 0:
            print("The Linked List is Empty")
            return
        trav_one = self.head
        trav_two = trav_one.next
        while trav_two.next is not None:
            trav_one = trav_one.next
            trav_two = trav_one.next.next
        trav_one.next = trav_two.next
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
linked_list.append(4)
print(linked_list.size)
linked_list.append(10)
linked_list.append(12)
linked_list.insert(2, 0)
linked_list.insert(2, 0)
linked_list.print_node()
linked_list.insert(3, 1)
linked_list.print_node()
linked_list.append(4)
linked_list.print_node()
linked_list.append(11)
linked_list.delete(1)
linked_list.print_node()
linked_list.delete(0)
linked_list.print_node()
linked_list.print_node()
linked_list.append(5)
linked_list.append(6)
linked_list.append(8)
linked_list.pop()
linked_list.pop()
linked_list.print_node()
linked_list.append(5)
linked_list.print_node()
linked_list.insert_new_head(99)
linked_list.insert_new_head(22)
linked_list.find(5)
linked_list.print_node()