class CustomStack {
private:
    int* st;
    int index;
    int maxSize;

public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        st = new int[maxSize];
        index = -1; 
    }

    void push(int x) {
        if (index < maxSize - 1) {
            st[++index] = x;
        }
    }

    int pop() {
        if (index == -1) return -1;
        return st[index--];
    }

    void increment(int k, int val) {
        int limit = (k < index + 1) ? k : (index + 1);
        
        for (int i = 0; i < limit; i++) {
            st[i] += val;
        }
    }
};