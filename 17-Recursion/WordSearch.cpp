/*
NOTES:

- Initially started DFS only from (0,0). Realized the word can start from any cell, so iterate over the entire board and start DFS wherever board[i][j] == word[0].

- First tried marking the word ('word[wordInd] = #') instead of the board. The visited state belongs to the board cell, not the target word.

- Forgot to restore the board after recursion. Every change to shared state must be undone before returning (Choose -> Explore -> Undo).

- Restored the board after each recursive call at first. The cell should remain marked while exploring all four directions and be restored only once afterwards.

- Used a bool passed by reference initially. Returning bool directly makes the recursion much cleaner.

- Missed the single-character word case. The correct approach is to first verify the current character matches, then if it is the last character of the word, return true immediately.

- Initially mixed up the parameter order while calling DFS from exist().

- Optimization: pass 'word' as const string& to avoid copying it in every recursive call.

- Optimization: return immediately when one DFS succeeds instead of continuing to search the remaining starting cells.
*/
class Solution {
public:
    bool wordSearch(vector<vector<char>>& board, string word, int wordInd, int row, int col){
        if(wordInd == word.size()) {
            //word found
            return true;
        }
        if(board[row][col] == word[wordInd] && wordInd == word.size()-1) return true;
        if(board[row][col] != word[wordInd]){
            return false;
        } //unmatched char
        char ch = board[row][col]; //save char
        board[row][col]='#'; //replace with dummy char so that cannot discover again
        bool top=false,right=false,left=false,bottom=false;
        //top
        if(row-1 >= 0) {
            top = wordSearch(board,word,wordInd+1,row-1,col);
        }
        //bottom
        if(row+1 < board.size()){
            bottom = wordSearch(board,word,wordInd+1,row+1,col);
        } 
        //right
        if(col+1 < board[0].size()){
            right = wordSearch(board,word,wordInd+1,row,col+1);
        } 
        //left
        if(col-1 >= 0){
            left = wordSearch(board,word,wordInd+1,row,col-1);
        }
        board[row][col]=ch;
        return left || right || top || bottom;
    }

    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0])
                    ans |= wordSearch(board,word,0,i,j);
            }
        }
        return ans;
    }
};
