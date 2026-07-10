// Last updated: 7/11/2026, 2:33:16 AM
1class Solution {
2    public List<List<Integer>> generate(int numRows) {
3        List<List<Integer>> triangle = new ArrayList<>();
4        for(int i = 0; i<numRows; i++){
5            List<Integer> row = new ArrayList<>();
6            for(int j = 0; j<=i; j++){
7                if(j == 0 || j == i){
8                    row.add(1);
9                }else{
10                    row.add(triangle.get(i-1).get(j) + triangle.get(i-1).get(j-1));
11                }
12            }
13            triangle.add(row);
14        }
15        return triangle;
16    }
17}