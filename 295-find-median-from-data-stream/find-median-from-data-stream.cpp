class MedianFinder {
public:

    // max heap
    priority_queue<int> left;

    // min heap
    priority_queue<int, vector<int>, greater<int>> right;

    MedianFinder() {
    }

    void addNum(int num) {

        left.push(num);

        // maintain order
        right.push(left.top());
        left.pop();

        // balance sizes
        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {

        if (left.size() > right.size())
            return left.top();

        return (left.top() + right.top()) / 2.0;
    }
};