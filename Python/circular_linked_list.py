class Node():
    def __init__(self, value = None, next = None):
        self.value = value
        self.next = next

class Linked_List():

    def __init__(self):
        self.head = None
        self.size = 0

    def insert(self):
        pass

    def append(self, value):
        current = self.head
        if self.size == 0:
            new_node = Node(value)
            self.head = new_node
            new_node.next = self.head
            self.size += 1
        else:
            current = self.traverse()
            new_node = Node(value, self.head)
            current.next = new_node
            self.size += 1

    def prepend(self, value):
        current = self.head
        if self.size == 0:
            new_node = Node(value)
            self.head = new_node
            new_node.next = self.head
            self.size += 1
        else:
            new_node = Node(value, current)
            self.head = new_node
            current = self.traverse()
            current.next = self.head
            self.size += 1


    def delete(self):
        pass

    def traverse(self, pointer):
        while pointer.next is not None:
            pointer = pointer.next
        return pointer
    
    def search(self):
        pass