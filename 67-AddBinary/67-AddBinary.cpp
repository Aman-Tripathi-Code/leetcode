// Last updated: 1/11/2026, 1:03:40 PM
class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int n = a.size();
        int m = b.size();
        int i = n-1, j = m-1;
        int carry = 0;
        while(i>=0 && j>=0){
            int sum = a[i]-'0' + b[j]-'0';
            if(carry==1){
                sum += 1;
            }
            if(sum==0){
                ans.push_back('0');
                carry = 0;
            }
            else if(sum==1){
                ans.push_back('1');
                carry = 0;
            }
            else if(sum==2){
                ans.push_back('0');
                carry = 1;
            }
            else{
                ans.push_back('1');
                carry = 1;
            }
            i--;
            j--;
        }
        while(i>=0){
            
            if(carry==1){
                
                if(a[i]=='1'){
                    ans.push_back('0');    
                }
                else{
                    ans.push_back('1');
                    carry = 0;
                }
                
            }
            else{
                ans.push_back(a[i]);
            }
            i--;
        }
        
         while(j>=0){
            if(carry==1){
                if(b[j]=='1'){
                    ans.push_back('0');
                }
                else{
                    ans.push_back('1');
                    carry = 0;
                }    
            }
            else{
                ans.push_back(b[j]);
            }
            j--;
        }
        if(carry==1){
            ans.push_back('1');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};