class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();//number of row
        int c=matrix[0].size(); //number of col
        int ri=0; //row index
        int ci=c-1;//col index
        while(ri<r&&ci>=0){
            int el=matrix[ri][ci];// find last element of every row 
            if(el==target)
                return 1;
            else if(el>target) //decresing col index 
                ci--;
            else ri++; //increasing row index
        }
        return 0;
    }
};