class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int r=matrix.size(); //number row
        int c=matrix[0].size();  // number column
        for(int i=0;i<r;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]); //transpose of matrix
            }
        }
        
        for(int i=0;i<r;i++){
        reverse(matrix[i].begin(),matrix[i].end());}  //reverse martix transpose
    }
};