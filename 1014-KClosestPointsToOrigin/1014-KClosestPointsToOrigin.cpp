// Last updated: 1/11/2026, 1:00:50 PM
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<double,pair<int,int>>> pq;
        for(int i = 0; i<n; i++){
            double dis = pow(points[i][0],2) + pow(points[i][1],2);

            dis = sqrt(dis);
            cout << dis << endl;
            pq.push({dis,{points[i][0],points[i][1]}});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            vector<int> ds;
            ds.push_back(it.second.first);
            ds.push_back(it.second.second);
            ans.push_back(ds);
        }
        return ans;
        
    }
};