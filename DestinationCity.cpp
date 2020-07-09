//1436. Destination City
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
       
        std::unordered_map<std::string, std::string> des_city;
        for(auto p : paths){
            des_city.insert({p[0], p[1]});
        }
        
        string current_city = paths[0][0];
        auto search = des_city.find(current_city);
        while (search != des_city.end()){
            current_city = search->second;
            search = des_city.find(current_city);
        }
        return current_city;
    }
};
/*
Runtime: 20 ms, faster than 94.49% of C++ online submissions for Destination City.
Memory Usage: 11.7 MB, less than 18.47% of C++ online submissions for Destination City.
*/
