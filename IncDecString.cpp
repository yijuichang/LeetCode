//1370. Increasing Decreasing String
class Solution {
public:
    string sortString(string s) {
        string res;
        sort(s.begin(),s.end());
        cout<<s<<endl;
        while(!s.empty()){
            res.push_back(s.front());
            s.erase(0,1);
            for (size_t i = 0; i < s.size();++i){
                if( s.at(i) > res.back()){
                    res.push_back(s.at(i));
                    s.erase(i,1);
                    --i;
                } 
            }
            if(!s.empty()){
                res.push_back(s.back());
                s.erase(s.size() - 1 ,1);
                for (size_t i = 0; i < s.size();++i){
                    if( s.at(s.size() - 1 - i) <  res.back()){
                        res.push_back(s.at(s.size() - 1 - i));
                        s.erase(s.size() - 1 - i,1);
                        --i;
                    } 
                }
                
            }
            
        }
        return res;
    }
};
/*
1. first sort the letters

2. while(!s.empty())
    (1) append smallest letter
    (2) append largest letter



*/
/*
Runtime: 40 ms, faster than 27.96% of C++ online submissions for Increasing Decreasing String.
Memory Usage: 7.6 MB, less than 65.10% of C++ online submissions for Increasing Decreasing String.
*/
