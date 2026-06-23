// Last updated: 6/24/2026, 5:03:06 AM
1public class Pair<K,V>{
2    K key;
3    V value;
4
5    public Pair(K key, V value){
6        this.key = key;
7        this.value = value;
8    }
9}
10class Solution {
11    public int[] topKFrequent(int[] nums, int k) {
12        int n = nums.length;
13        int[] kFrequentElements = new int[k];
14        Map<Integer,Integer> freqMap = new HashMap<>();
15        Queue<Pair<Integer,Integer>> pq = new PriorityQueue<>(Comparator.comparingInt(pair->pair.key));
16
17        for(int num: nums){
18            freqMap.put(num, freqMap.getOrDefault(num,0) + 1);
19        }
20
21        for(Map.Entry<Integer,Integer> entry: freqMap.entrySet()){
22            pq.offer(new Pair<>(entry.getValue(),entry.getKey()));
23            if(pq.size() > k){
24                pq.poll();
25            }
26        }
27        int i = 0;
28        while(!pq.isEmpty()){
29            kFrequentElements[i] = pq.poll().value;
30            i++;
31        }
32
33        return kFrequentElements;
34
35    }
36}