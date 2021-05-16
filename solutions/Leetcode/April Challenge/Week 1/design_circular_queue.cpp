class MyCircularQueue {
    int *arr;
    int head;
    int tail;
    int size;
    int k;
public:
    MyCircularQueue(int k) {
        arr = new int[k];
        this->k = k;
        head = -1;
        tail = -1;
        size = 0;
    }
    
    ~MyCircularQueue() {
        delete[] arr;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        tail++;
        tail %= k;
        arr[tail] = value;
        if (isEmpty()) head = tail;
        size++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        head++;
        head %= k;
        size--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return arr[head];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return arr[tail];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == k;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
