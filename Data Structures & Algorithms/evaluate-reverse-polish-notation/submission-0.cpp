class Solution {
public:
    bool isOperation(string str){
        return str=="+" || str=="-" || str=="*" || str=="/";
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(string token:tokens){
            if(isOperation(token)){
                int num1,num2;
                num2 = st.top();
                st.pop();
                num1 = st.top();
                st.pop();
                int res;
                if(token=="+"){
                    res = num1+num2;
                }
                if(token=="-"){
                    res = num1-num2;
                }
                if(token=="/"){
                    res = num1/num2;
                }
                if(token=="*"){
                    res = num1*num2;
                }
                st.push(res);
            }
            else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};
