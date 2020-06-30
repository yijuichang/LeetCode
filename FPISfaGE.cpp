//1237. Find Positive Integer Solution for a Given Equation
/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    const int upperbound=1000;
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> solution_pairs;
        vector<int> pair(2,0);
        int x=1;
        int yleft, yright, ymid;
        while(customfunction.f(x,1)<=z){
            pair[0]=x;            
            if(customfunction.f(x,1)<=z && customfunction.f(x,upperbound)>= z){           
                yleft=1;
                yright=upperbound;
                while(yright > yleft){
                    if(customfunction.f(x,yleft)==z){
                        pair[1]=yleft;
                        solution_pairs.emplace_back(pair);
                        break;
                    }
                    else if(customfunction.f(x,yright)==z){
                        pair[1]=yright;
                        solution_pairs.emplace_back(pair);
                        break;
                    }
                    ymid=yleft+(yright-yleft)/2;
                    if(customfunction.f(x,ymid)==z){  
                        pair[1]=ymid;
                        solution_pairs.emplace_back(pair);
                        break;
                    }
                    else if(customfunction.f(x,ymid)<z){
                        yleft=ymid+1;                    
                    }
                    else{
                        yright=ymid;
                    }
                }
                
            }            
            x++;
        }
        return solution_pairs;
    }
};
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Find Positive Integer Solution for a Given Equation.
Memory Usage: 6.4 MB, less than 39.08% of C++ online submissions for Find Positive Integer Solution for a Given Equation.
*/
