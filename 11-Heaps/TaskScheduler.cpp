class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,char>> pq;
        vector<int> hash(26,0);
        for(auto ch : tasks){ //make frequency array
            hash[ch-'A']++;
        }
        for(int i=0;i<26;i++){
            if(hash[i] != 0){
                pq.push({hash[i],(char)(i+65)});
            }
        }
        int cycles=0;
        while(!pq.empty()){
            vector<pair<int,char>> temp;
            int cycles_left = n+1;
            while(cycles_left > 0 && !pq.empty()){
                auto [cnt,ch] = pq.top();
                pq.pop();
                cnt--; //execute task => freq decreases
                if(cnt>0) temp.push_back({cnt,ch});
                cycles++;
                cycles_left--;
            }
            for(auto t : temp){
                pq.push(t);
            }
            if(pq.empty()) break; //if all tasks done, no need to account for idle tasks
            cycles += cycles_left; //simulate the idle cycles
        }
        return cycles;
    }
};
