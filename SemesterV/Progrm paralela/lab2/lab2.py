import threading
import queue

class SyncQueue:
    def __init__(self, capacity):
        self.q = queue.Queue(maxsize=capacity)
        self.mtx = threading.Lock()
        self.cap = capacity
    
    def empty(self):
        with self.mtx:
            return self.q.empty()

    def full(self):
        with self.mtx:
            return self.q.full()

    def enqueue(self, item):
        with self.mtx:
            self.q.put(item)

    def dequeue(self):
        with self.mtx:
            return self.q.get()


class ScalarProduct:
    def __init__(self, vector1, vector2, capacity=5):
        self.vector1 = vector1
        self.vector2 = vector2
        self.sync_queue = SyncQueue(capacity)
        self.result = 0
        self.condition = threading.Condition()

    def producer(self):
        for i in range(len(self.vector1)):
            with self.condition:
                while self.sync_queue.full():# Wait until there is space in the queue
                    self.condition.wait()

                # Compute the product and enqueue it
                product = self.vector1[i] * self.vector2[i]
                self.sync_queue.enqueue(product)

                # Notify the consumer that a new item is available
                self.condition.notify()

    def consumer(self):
        for _ in range(len(self.vector1)):
            with self.condition:
                
                while self.sync_queue.empty():# waits until is an itm in the queue
                    self.condition.wait()

                product = self.sync_queue.dequeue()
                self.result += product

                # Notify the producer that there is space in the queue
                self.condition.notify()


def main():
    vector1 = [1 for i in range(1,101)]
    vector2 = [i for i in range(1,101)]
    
    scalar_product = ScalarProduct(vector1, vector2)
    
    # Create producer and consumer threads
    producer_thread = threading.Thread(target=scalar_product.producer)
    consumer_thread = threading.Thread(target=scalar_product.consumer)
    
    producer_thread.start()
    consumer_thread.start()

    producer_thread.join()
    consumer_thread.join()
  
    print("scalar product of the vectors:", scalar_product.result)

if __name__ == "__main__":
    main()
