class MyCircularDeque {
public:

    vector<int> dq;

    int front;
    int rear;
    int sz;
    int cap;

    MyCircularDeque(int k) {

        cap = k;
        dq.resize(k);

        front = 0;
        rear = 0;
        sz = 0;
    }

    bool insertFront(int value) {

        if (isFull())
            return false;

        front = (front - 1 + cap) % cap;

        dq[front] = value;

        sz++;

        return true;
    }

    bool insertLast(int value) {

        if (isFull())
            return false;

        dq[rear] = value;

        rear = (rear + 1) % cap;

        sz++;

        return true;
    }

    bool deleteFront() {

        if (isEmpty())
            return false;

        front = (front + 1) % cap;

        sz--;

        return true;
    }

    bool deleteLast() {

        if (isEmpty())
            return false;

        rear = (rear - 1 + cap) % cap;

        sz--;

        return true;
    }

    int getFront() {

        if (isEmpty())
            return -1;

        return dq[front];
    }

    int getRear() {

        if (isEmpty())
            return -1;

        return dq[(rear - 1 + cap) % cap];
    }

    bool isEmpty() {

        return sz == 0;
    }

    bool isFull() {

        return sz == cap;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */