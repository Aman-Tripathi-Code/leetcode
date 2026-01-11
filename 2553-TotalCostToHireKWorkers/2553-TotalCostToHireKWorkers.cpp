// Last updated: 1/11/2026, 12:59:38 PM
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int cand) {
        int n =  costs.size();
        long long sum = 0;
        priority_queue<int,vector<int>,greater<int>> pq1,pq2;
        
        for(int i = 0; i<cand; i++){
            pq1.push(costs[i]);
        }

        for(int i = max(cand,n-cand); i<n; i++){
            pq2.push(costs[i]);
        }

        int i = cand-1, j = max(n-cand,cand);
        while(k--){

            if(pq1.empty() || pq2.empty()){
                if(pq1.empty()){
                    sum += pq2.top();
                    pq2.pop();
                }
                else{
                    sum += pq1.top();
                    pq1.pop();
                }
            }

            else if(pq1.top()<= pq2.top()){
                long long cost = pq1.top();
                pq1.pop();
                sum = sum + cost;
                i++;
                if(i < j) pq1.push(costs[i]);
            }

            else{
                long long cost = pq2.top();
                pq2.pop();
                sum = sum + cost;
                j--;
                if(i<j) pq2.push(costs[j]);
            }


        }
        return sum;
    }
};