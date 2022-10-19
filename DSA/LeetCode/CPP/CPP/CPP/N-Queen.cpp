// Backtracking

// Backtracking can be defined as a general algorithmic technique that considers searching every possible combination in order to solve a computational problem.

// The idea is to place queens one by one in different columns, starting from the leftmost column. When we place a queen in a column, we check for clashes with already placed queens. In the current column, if we find a row for which there is no clash, we mark this row and column as part of the solution. If we do not find such a row due to clashes, then we backtrack and return false.

// Time complexity :- O(N!) . Required for choices.
//                    O(N*N). Required for board and recursive stack.
 
 #include<bits/stdc++.h>
 using namespace std;
    //globally declaring
    vector<vector<string>>ans;
    vector<int>cols;                    //checking chess board through column
    vector<int>chess;
    vector<int>main_diag;
    vector<int>anti_diag;

 void addAnswer(int n)
 {
    vector<string>v;
    for(int i=0;i<n;i++)
    {
        string s(n,'.');        //s=....
        s[chess[i]]='Q';          
        v.push_back(s);
        
    }
    
    ans.push_back(v);
}
 

void dfs(int row)
{
    
    int N=chess.size();
    if(row==N)
    {
        addAnswer(N);
        return;
    }
    
    
    for(int i=0;i<N;i++)
    {   
        //if nothing marked 1 then we can place queen there
        
        if(cols[i]==0 && main_diag[row+i]==0 && anti_diag[row-i+N]==0)
        {
            cols[i]=main_diag[row+i]=anti_diag[row-i+N]=1;
            chess[row]=i;
            //chess[0]=2; means marking for row 0 the column no where the queen is present
            
            dfs(row+1);
            cols[i]=main_diag[row+i]=anti_diag[row-i+N]=0;  //for backtrack
        }
    }
    
}


 vector<vector<string>> solveNQueens(int n) {
    
        cols = vector<int>(n, 0);   //initalising with zero
        main_diag = vector<int>(2 * n, 0);  //normalized diagonal=2*n-1;
        anti_diag = vector<int>(2 * n, 0);
        chess = vector<int>(n, 0);
    
    dfs(0);

        return ans;
    
    
}
