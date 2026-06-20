// Last updated: 6/21/2026, 1:52:25 AM
1class Solution {
2    public int countSort(int[] costs, int coins){
3        int maxCost = costs[0], n = costs.length;
4        for(int i = 0; i<n; i++){
5            if(costs[i] > maxCost) maxCost = costs[i];
6        }
7        int[] count = new int[maxCost+1];
8
9        for(int i = 0; i<n; i++){
10            count[costs[i]]++;
11        }
12        int i = 1, cnt = 0;
13        while(i <= maxCost && coins >= i){
14            if(count[i] > 0){
15                int curr = count[i]*i;
16                if(coins >= curr){
17                    cnt += count[i];
18                    coins -= curr;
19                }else{
20                    curr = coins/i;
21                    cnt += curr;
22                    break;
23                }
24            }
25            i++;
26        }
27        return cnt;
28        
29    }
30    public int maxIceCream(int[] costs, int coins) {
31        return countSort(costs,coins);
32    }
33}