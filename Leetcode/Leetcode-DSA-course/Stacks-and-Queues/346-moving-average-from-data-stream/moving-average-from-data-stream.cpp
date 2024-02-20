class MovingAverage {
public:
    int windowSize;
    int sum;
    queue<int> queue;
    MovingAverage(int size) {
        windowSize = size;
        sum = 0;
    }

    double next(int val) {
        sum += val;
        queue.push(val);
        while (queue.size() > windowSize) {
            sum -= queue.front();
            queue.pop();
        }

        return (double)sum / queue.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */