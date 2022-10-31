class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int s=0;
        int r=matrix.size();//number of row
        int c=matrix[0].size();//number of col
        int e=r*c-1; //find total number-1
        int mid=s+(e-s)/2;//for mid
        while(s<=e){
            int ele=matrix[mid/c][mid%c]; //find element using mid //row=mid/c // col=mid%c
            if(ele==target) 
                return 1;
            else if(ele>target)
                e=mid-1;
            else 
                s=mid+1;
            mid=s+(e-s)/2;
        }
        return 0;
    }
};