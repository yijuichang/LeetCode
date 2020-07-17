//690. Employee Importance
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getID(vector<Employee*> &employees, int id){
         auto it = *find_if (employees.cbegin(),employees.cend(),[&id](const Employee* em){
            return em->id == id;
        });
        int res = it ->importance;
        
        if ((it->subordinates).size() != 0){
            for (auto sub : (it->subordinates)){
                res += getID(employees,sub);
            }
        }     
        return res;            
    }
    int getImportance(vector<Employee*> employees, int id) {
        return getID(employees,id);            
    }
    
    
//     static int GetI(const vector<Employee*>& es, int id)
//     {
//         auto e = *find_if(begin(es), end(es), [&id](const Employee* e)
//                       {
//                           return e->id == id;
//                       });
        
//         return e->importance + accumulate(begin(e->subordinates), end(e->subordinates), 0, [&es](const int& v, const int& id)
//                        {
//                            return v + GetI(es, id);
//                        });
//     }
    
// public:
//     int getImportance(vector<Employee*> es, int id) {
//         return GetI(es, id);
//     }
};


/*
learned: find_if, lambda expression, static member function, defererencing iterator 

Runtime: 40 ms, faster than 83.22% of C++ online submissions for Employee Importance.
Memory Usage: 11.6 MB, less than 99.50% of C++ online submissions for Employee Importance.


*/
