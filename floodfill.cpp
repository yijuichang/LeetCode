//733. Flood Fill
class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor){
        if (sr > 0 && image.at(sr).at(sc) == image.at(sr - 1).at(sc)) 
            dfs(image,sr - 1, sc,newColor);              
        if (sr + 1 < image.size()  && image.at(sr).at(sc) == image.at(sr + 1).at(sc)) 
            dfs(image,sr + 1,sc,newColor);
        if (sc > 0 && image.at(sr).at(sc) == image.at(sr).at(sc-1)) 
            dfs(image,sr, sc - 1,newColor);  
        if (sc + 1 < image.front().size()  && image.at(sr).at(sc) == image.at(sr).at(sc+1)) 
            dfs(image,sr,sc + 1,newColor);
        image.at(sr).at(sc) = newColor;
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        dfs(image,sr,sc,newColor);
        return image;
    }
};



/*
AddressSanitizer:DEADLYSIGNAL
=================================================================
==33==ERROR: AddressSanitizer: stack-overflow on address 0x7ffcabd10ff8 (pc 0x000000372c01 bp 0x7ffcabd11060 sp 0x7ffcabd11000 T0)
    <empty stack>
SUMMARY: AddressSanitizer: stack-overflow
==33==ABORTING

*/



/*

flood function: 
    input = position , newColor




*/
