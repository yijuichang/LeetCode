#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm> 

vector<int> findSubsequence(vector<int> arr) {
    int N = arr.size();
    if (N == 0){
        return {};
    }
    unordered_map<int,vector<int> > freq_idx;
    vector<int> non_unique_list;
    int i;
    for (i = 0; i< N; ++i){
        freq_idx[arr[i]].emplace_back(i);
    }  
    for (auto it = freq_idx.begin(); it != freq_idx.end(); ++it){
        if ((it->second).size() > 1){
            non_unique_list.emplace_back(it->first);
        }
    }
    if (non_unique_list.size() == 0){
      return {};
    }
    sort(non_unique_list.begin(),non_unique_list.end(),less<int>());
    vector<int> res;
    int idx_last = INT_MIN;
    for (auto &ele : non_unique_list){            
      if (idx_last > freq_idx[ele][1]){
        return {-1};
      }
      else{
        if (freq_idx[ele][0] > idx_last){
          i = 0;
          while(i < freq_idx[ele].size() - 1){
            res.emplace_back(ele);
            ++i;
          }
          idx_last = freq_idx[ele][freq_idx[ele].size() - 2]; 
        }
        else{
          i = 1;
          while(i < freq_idx[ele].size() ){
            res.emplace_back(ele);
            ++i;
          }
          idx_last = freq_idx[ele][freq_idx[ele].size() - 1]; 
        }
      }      
    }
    return res; 
    //unordered_map<int,int> freq_cnt;
    // int idx_min, min_number = INT_MAX;
    // vector<int> idx_list_min;
    // for (auto it = freq_idx.begin(); it != freq_idx.end(); ++it){
    //     freq_cnt[it->first] = (it->second).size();
    //     if (freq_cnt[it->first] > 1 && it->first < min_number){
    //         min_number = it->first;
    //         check = true;
    //     }
    // }
    // if (check){
    //     idx_list_min.assign((freq_idx[min_number]).begin(),(freq_idx[min_number]).end());
    //     sort(idx_list_min.begin(),idx_list_min.end(),less<int>());
    // }
    // else{
    //     return {};
    // }    
//     vector<vector<int> > res = {{},{}};
//     vector<int> res_len = {INT_MAX,INT_MAX};
//     for (int i = idx_list_min[0]; i < N; ++i){
//         if (res[0].size() > 0){
//             if (arr[i] < res[0].back() || freq_cnt[arr[i]] < 2){
//                 continue;
//             }
//         }
//         res[0].emplace_back(arr[i]);
//         --freq_cnt[arr[i]];
//         check = true;
//         for (auto it = freq_cnt.begin(); it != freq_cnt.end(); ++it){
//             if (it->second > 1){
//                 check = false;
//                 break;
//             }
//         }
//         cout<<res[0].back()<<" ";
//         if (check){
            
//             res_len[0] = res[0].size();
//             break;
//         }
//     } 
//     if (idx_list_min.size() > 1){
//         for (auto it = freq_idx.begin(); it != freq_idx.end(); ++it){
//             freq_cnt[it->first] = (it->second).size();            
//         }
//         for (int i = idx_list_min[1]; i < N; ++i){
//             if (res[1].size() > 0){
//                 if (arr[i] < res[1].back() || freq_cnt[arr[i]] < 2){
//                     continue;
//                 }
//             }
//             res[1].emplace_back(arr[i]);
//             --freq_cnt[arr[i]];
//             check = true;
//             for (auto it = freq_cnt.begin(); it != freq_cnt.end(); ++it){
//                 if (it->second > 1){
//                     check = false;
//                     break;
//                 }
//             }
//             if (check){
//                 res_len[1] = res[1].size();
//                 break;
//             }
//         } 
//     }
// cout<<res_len[0]<<" "<<res_len[1]<<endl;
//     if (res_len[0] != INT_MAX && res_len[1] != INT_MAX){
//         if ( res_len[0] < res_len[1]){
//             return res[0];
//         }
//         else{
//             return res[1];
//         }
//     }
//     else{
//         if (res_len[0] != INT_MAX){
//             return res[0];
//         }
//         else if (res_len[1] != INT_MAX){
//             return res[1];
//         }        
//     }
//     return {-1};
}
int main() {
	cout<<"Hello"<<endl;
  vector<int> s = {1,2,3};//{12,3,3,8,7,3,7,8,8,9,100,9,100};//{1, 2, 7, 8, 3};//{1, 2, 3, 4, 5, 5, 6, 6};//{1,3,2,2,3};//{1,2,3};//
  vector<int> res = findSubsequence(s);
  cout<<"input  = ";
  for (auto &ch : s){
    cout<<ch<<" ";
  }
  cout<<endl<<"output = ";
  for (auto &ch : res){
    cout<<ch<<" ";
  }
	return 0;
}


//3 3 7 8 8 9 1000000
