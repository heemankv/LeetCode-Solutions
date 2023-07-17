class MedianFinder {

private:
    priority_queue<int, vector<int>, greater<int>> rightSideMinTop;
    priority_queue<int> leftSideMaxTop;

public:
    MedianFinder() {
        // ntg to init
    }
    
    void addNum(int num) {
        // add to leftSideMaxTop
        leftSideMaxTop.push(num);

        // if leftTop > right Top
        // shift
        if(!rightSideMinTop.empty() && leftSideMaxTop.top() > rightSideMinTop.top()){
            int temp = leftSideMaxTop.top();
            rightSideMinTop.push(temp);
            leftSideMaxTop.pop();
        }

        // if size right > size left +1
        // shift
        if(rightSideMinTop.size() > leftSideMaxTop.size() + 1){
            int temp = rightSideMinTop.top();
            leftSideMaxTop.push(temp);
            rightSideMinTop.pop();
        }

        // if size left > size right +1
        // shift
        if(leftSideMaxTop.size() > rightSideMinTop.size() + 1){
            int temp = leftSideMaxTop.top();
            rightSideMinTop.push(temp);
            leftSideMaxTop.pop();
        }
    }
    
    double findMedian() {
        double value = -1;
        // if max == min size
        // even /2
        if(leftSideMaxTop.size() == rightSideMinTop.size()){
            value = (leftSideMaxTop.top() + rightSideMinTop.top()) / 2.0;
        }
        if(leftSideMaxTop.size() > rightSideMinTop.size()){
            value = leftSideMaxTop.top();
        }

        if(leftSideMaxTop.size() < rightSideMinTop.size()){
            value = rightSideMinTop.top();
        }
        return value; 
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
