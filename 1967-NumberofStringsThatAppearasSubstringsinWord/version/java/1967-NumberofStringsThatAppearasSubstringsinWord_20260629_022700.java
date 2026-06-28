// Last updated: 6/29/2026, 2:27:00 AM
1class Solution {
2    public boolean presentInWord(String pattern, String word){
3        int wordLen = word.length(), patLen = pattern.length();
4        for(int i = 0; i<=wordLen-patLen; i++){
5            String wordSubStr = word.substring(i,i+patLen);
6            System.out.println("wordSubStr " + wordSubStr);
7            if(pattern.equals(wordSubStr)) return true;
8        }
9        return false;
10
11    }
12    public int numOfStrings(String[] patterns, String word) {
13        int cnt = 0;
14        for(String pattern: patterns){
15            if(presentInWord(pattern, word)){
16                cnt++;
17            }
18        }
19        return cnt;
20    }
21}