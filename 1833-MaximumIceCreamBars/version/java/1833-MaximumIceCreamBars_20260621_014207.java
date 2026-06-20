// Last updated: 6/21/2026, 1:42:07 AM
1class Solution {
2    public int[] countSort(int[] costs){
3        int maxCost = costs[0], n = costs.length;
4        for(int i = 0; i<n; i++){
5            if(costs[i] > maxCost) maxCost = costs[i];
6        }
7        int[] count = new int[maxCost+1];
8        int[] sortedCosts = new int[n];
9
10        for(int i = 0; i<n; i++){
11            count[costs[i]]++;
12        }
13        for(int i = 1; i<=maxCost; i++){
14            count[i] += count[i-1];
15        }
16        for(int i = n-1; i>=0; i--){
17            int ind = count[costs[i]]-1;
18            sortedCosts[ind] = costs[i];
19            count[costs[i]]--;
20        }
21        return sortedCosts;
22    }
23    public int maxIceCream(int[] costs, int coins) {
24        int[] sortedCosts = countSort(costs);
25        int cnt = 0, i = 0, n = costs.length;
26        while(i < n && coins > 0){
27            if(coins >= sortedCosts[i]){
28                coins -= sortedCosts[i];
29                cnt++;
30            }else{
31                break;
32            }
33            i++;
34        }
35        return cnt;
36    }
37}