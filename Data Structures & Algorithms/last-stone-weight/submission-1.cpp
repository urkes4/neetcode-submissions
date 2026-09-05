class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int st:stones){
            pq.push(st);
        }
        while(pq.size()>1){
            int x,y;
            x = pq.top();
            pq.pop();
            y = pq.top();
            pq.pop();
            if(x<y){
                pq.push(y-x);
            }
            else if(x>y){
                pq.push(x-y);
            }
            else{
                // nista
            }
        }
        return pq.size()>0?pq.top():0;
    }
};
