class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end()); //using set for fast lookup in word list
        if(st.find(endWord) == st.end()) return 0; //if ending not present in wordlist, word can't be made
        queue<string> q;
        q.push(beginWord); //bfs for finding shortest transformation length
        int len = 1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){ //level order traversal: put all words with one char difference at the same level
                string currWord = q.front();
                q.pop();
                if(currWord == endWord) return len;
                for(int i=0;i<currWord.size();i++){
                    string next = currWord;
                    char original = currWord[i];
                    for(char ch = 'a';ch <='z';ch++){
                        if(ch == original) //skip if the word becomes same as currWord (small optimization)
                            continue;
                        next[i] = ch;
                        if(st.find(next) != st.end()){
                            q.push(next);
                            st.erase(next); //erase from set since it should not be reached again
                        }
                    }
                }    
            }
            len++;
        }
        return 0;
    }
};
