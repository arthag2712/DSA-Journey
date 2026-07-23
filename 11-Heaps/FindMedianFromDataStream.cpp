class MedianFinder {
public:
    priority_queue<int> left; //maxheap for left
    priority_queue<int,vector<int>,greater<int>> right; //minheap for right
    MedianFinder() {
        //empty constructor
    }

    void addNum(int num) {
        if(left.empty() || num < left.top()) left.push(num);
        else right.push(num);
        rebalance();
    }
    
    void rebalance(){
        if(left.size() > right.size()+1){
            int num = left.top();
            left.pop();
            right.push(num);
        }else if(left.size() < right.size()){
            int num = right.top();
            right.pop();
            left.push(num);
        }
    }

    double findMedian() {
        if(left.size() == right.size()+1) return left.top();
        return (left.top()+right.top())/2.0;
    }
};
