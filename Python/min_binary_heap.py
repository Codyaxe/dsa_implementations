class MinHeap():
    def __init__(self):
        self.heap = []
        self.size = 0
    
    def extractmin(self):
        if self.size != 0:
            return self.heap[0]
        else:
            print("Min-Heap is empty!")

    def heapappendkey(self, value):
        self.heap.append(value)
        self.size += 1
        index = self.size - 1
        #Swims up
        while index != 0 and self.heap[self.parent(index)] > self.heap[index]:
            parent = self.parent(index)
            self.swap(index, parent)
            index = parent

    def heapdeletekey(self, index):
        if self.size == 0:
            print("Min-Heap is empty!")
            return
        last_index = self.size - 1
        if index > last_index:
            print("Index out of bounds!")
            return
        self.swap(index, last_index)
        self.heap.pop()
        #Swims down
        while self.heap[index] > self.heap[self.left(index)] or self.heap[index] > self.heap[self.right(index)]:
            left = self.left(index)
            right = self.left(index)
            if left < right:
                self.swap(index, left)
                index = left
            else:
                self.swap(index, right)
                index = right
        #Swims up
        while index != 0 and self.heap[self.parent(index)] > self.heap[index]:
            parent = self.parent(index)
            self.swap(index, parent)
            index = parent

    def swap(self, index, index_two):
        temp = self.heap[index_two]
        self.heap[index_two] = self.heap[index]
        self.heap[index] = temp
    
    def decreasekey(self):
        pass

    @staticmethod
    def parent(index):
        return (index-2)//2

    @staticmethod
    def left(index):
        return 2*index + 1
    
    @staticmethod
    def right(index):
        return 2*index + 2
