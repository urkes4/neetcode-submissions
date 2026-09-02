class Solution {
public:

    string encode(vector<string>& strs) {
        string code = "";
        for(string str:strs){
            code+=to_string(str.size());
            code+="#";
            code+=str;
        }
        return code;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        int index = 0;
        string cur;
        int len;
        while(index<s.size()){
            cur="";
            len = 0;
            while(s[index]!='#'){
                len = len*10+s[index]-'0';
                index++;
            }
            index++;
            int i;
            for(i=index;i<len+index;i++){
                cur+=s[i];
            }
            index = i;
            ans.push_back(cur);
        }
        return ans;
    }
};
