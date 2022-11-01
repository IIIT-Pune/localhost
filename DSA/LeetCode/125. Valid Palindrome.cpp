class Solution {
    private:
    char uppertolower(char  c){  // cinvert upper case to lower
    if(c>='A'&&c<='Z')
    return c-'A'+'a';
    else 
    return c;
}
    string is(string s,string b){
        int i=0;
        
        
        int e=s.length();
        while(i<e){
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9')) // for push only vaild element
            
                b.push_back(s[i]);
                
            
            i++;
        }
        
        return b;
    }
public:
    bool isPalindrome(string s) {
        string g="";
        string b="";
      b=is(s,g);
        int i=0;
        // cout<<b;
        
        int e=b.length();
        int j=e-1;
        while(i<=j){
            if( uppertolower(b[i++])!= uppertolower(b[j--]))
                return 0;
        
        }
        return 1;
    }
};