// Last updated: 7/11/2026, 2:23:48 AM
1class Solution {
2    public List<List<Integer>> generate(int numRows) {
3        List<List<Integer>> triangle = new ArrayList<>(numRows);
4        List<Integer> row = new ArrayList<>(1);
5        row.add(1);
6        triangle.add(row); 
7        for(int i = 1; i<numRows; i++){
8            row = new ArrayList<>(i);
9            row.add(1);
10            for(int j = 1; j<i; j++){
11                int sum = triangle.get(i-1).get(j) + triangle.get(i-1).get(j-1);
12                row.add(sum);
13
14            }
15            row.add(1);
16            triangle.add(row);
17        }
18        return triangle;
19    }
20}