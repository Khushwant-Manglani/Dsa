class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int sum=0,carry=0;
        int i=a.length()-1,j=b.length()-1;
        while(i>=0 || j>=0){
            sum = carry;
            if(i>=0) sum += a[i--] - '0';
            if(j>=0) sum += b[j--] - '0';
            carry = sum > 1 ? 1 : 0; 
            result.append(to_string(sum%2)); //result += to_string(sum%2);
        }
        if(carry) result += '1';
        reverse(result.begin(),result.end());
        return result;
        
        
        /*string s;
        int i = a.length()-1;
        int j = b.length()-1;
        int carry=0,c,d;
        while(i>=0 || j>=0){
            int res = 0;
            if(i>=0){
                if(a[i] == 49) c = 1;
                else c = 0;
            }
            if(j>=0){
                if(b[j] == 49) d = 1;
                else d = 0;
            }
            if(i>=0 && j>=0){
                res = c + d + carry;
                i--;
                j--;
            }
            else if(i>=0){
                res = c + carry;
                i--;
            }
            else{
                res = d + carry;
                j--;
            }
            
            carry=0;
            if(res == 3){
                s += '1'; //s.push_back('1');
                carry++;
            } 
            else if(res == 2){
                s += '0';
                carry++;
            } 
            else if(res == 1) s += '1';
            else s += '0';
        }
        
        if(carry == 1) s += '1';
        //cout<<s;
        for(int i=0,j=s.length()-1; j>i ; i++,j--)
            swap(s[i],s[j]);
        return s;*/
    }
};
