class KthLargest {
public:
    //MIN HEAP IMPLEMENTED TO STORE THE SMALLEST OF THE K LARGEST ELEMENTS
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(auto it : nums){
            pq.push(it);
            if(pq.size()>K){
                pq.pop();
            }
        };
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>K){
            pq.pop();
        }
        return pq.top();
    }
};
