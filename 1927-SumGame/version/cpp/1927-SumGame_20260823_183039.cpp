// Last updated: 8/23/2026, 6:30:39 PM
1class Solution {
2public:
3    int findSum(int left, int right, string num){
4        int res = 0;
5        for(int i = left; i<right; i++){
6            if(num[i] == '?') continue;
7            res += (num[i] - '0');
8        }
9        return res;
10    }
11    bool sumGame(string num) {
12        int n = num.size();
13        int firstHalf = count(num.begin(),num.begin()+(n/2),'?'),secondHalf = count(num.begin()+(n/2),num.end(),'?');
14        int firstHalfSum = findSum(0,n/2,num),secondHalfSum = findSum(n/2,n,num);
15
16        if((firstHalf + secondHalf) & 1) return true;
17        int diff = abs(firstHalf - secondHalf);
18        int firstHalfSumDiff = (firstHalfSum - secondHalfSum);
19        int secondHalfSumDiff = (secondHalfSum - firstHalfSum);
20
21        if(firstHalf > secondHalf){
22            return secondHalfSumDiff != ((diff/2) * 9);
23        }
24        
25        return (firstHalfSumDiff != ((diff/2) * 9));
26    }
27};
28
29/*
30
31alice plays first then bob
32bob wins if both side have equal sum
33if alice wins false bob then true
34
35leftside - odd rightside - odd total - even
36leftside - odd rightside - even total - odd
37leftside - even rigtside - odd total - odd
38leftside - even rightside - even total - even
39
40if total even both will get equal changes and bob can try
41if total odd alice always gets more changes and she can determin the outcome and always wins
42
43if total is odd alice always wins
44
45
46for even case
47
48find - abs(leftside - rightside) as bob can replicate the opposite side moves
49we only have to check the feasibility
50
51alice will try to increase on more sum side and decrease on less sum side
52
53so alice will add 9's to side with more sum and 0 to side with less sum
54
55but if there is possibility that bob can reach the sum on less sum with 9 then that startegy will fail
56
57number of ? on less sum side matter
58
59find the abs diff of ? on both side and if in the abs(diff)/2 we can reach then it is fine 
60
61
62*/
63
64
65
66