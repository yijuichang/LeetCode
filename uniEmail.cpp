//929. Unique Email Addresses
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> email_set;
        string s,domain;
        size_t idx,temp;
        for (auto email : emails){
            idx = email.find('@');
            s = email.substr(0,idx);
            domain = email.substr(idx,email.size() - 1);            
            temp = s.find('+');
            if ( temp != string::npos) s.erase(temp, s.size() - temp); 
            temp = s.find('.');
            while ( temp != string::npos){
                s.erase(temp, 1);
                temp = s.find('.');
            }            
            email_set.emplace(s.append(domain));
        }
        return email_set.size();
    }
};


// learned:   usage of set,  substr
/*
Runtime: 52 ms, faster than 67.90% of C++ online submissions for Unique Email Addresses.
Memory Usage: 15.8 MB, less than 17.75% of C++ online submissions for Unique Email Addresses.

*/
