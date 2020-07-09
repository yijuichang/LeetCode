//804. Unique Morse Code Words
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> set;
        string s;
        for (auto word : words){
            s.clear();
            for(char c : word){
                s.append(morse[c - 'a']);
            }
            set.insert(s);
        }
        return set.size();
    }
};
/*
Runtime: 8 ms, faster than 58.56% of C++ online submissions for Unique Morse Code Words.
Memory Usage: 8.6 MB, less than 89.41% of C++ online submissions for Unique Morse Code Words.
*/
