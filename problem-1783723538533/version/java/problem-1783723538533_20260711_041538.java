// Last updated: 7/11/2026, 4:15:38 AM
1class Solution {
2    public int[][] merge(int[][] intervals) {
3
4        Arrays.sort(intervals, (a,b) -> {
5            if(a[0] == b[0]){
6                return Integer.compare(a[1],b[1]);
7            }
8            return Integer.compare(a[0],b[0]);
9        });
10
11        int start = intervals[0][0], end = intervals[0][1];
12
13        List<int[]> mergedInt = new ArrayList<>();
14
15        for(int[] interval: intervals){
16            if(end >= interval[0]){
17                end = Math.max(end,interval[1]);
18            }else{
19                mergedInt.add(new int[]{start,end});
20                start = interval[0];
21                end = interval[1];
22            }
23        }
24
25        mergedInt.add(new int[]{start,end});
26
27        return mergedInt.toArray(new int[mergedInt.size()][2]);
28    }
29}