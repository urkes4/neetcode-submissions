class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int d = s.size()-1;
        while(l<d){
            if(!isalnum(s[l]))l++;
            else if(!isalnum(s[d]))d--;
            else {if(tolower(s[l])!=tolower(s[d])){
                return false;
            }
            l++;
            d--;
            }
        }
        return true;
    }
};
