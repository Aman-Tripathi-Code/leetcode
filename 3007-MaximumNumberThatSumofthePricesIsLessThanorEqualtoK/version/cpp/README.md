You are given an integer k and an integer x. The price of a number num is calculated by the count of set bits at positions x, 2x, 3x, etc., in its binary representation, starting from the least significant bit. The following table contains examples of how price is calculated.

xnumBinary RepresentationPrice1130000011013213000001101122330111010013313000001101133621011010102

The accumulated price of num is the total price of numbers from 1 to num. num is considered cheap if its accumulated price is less than or equal to k.

Return the greatest cheap number.

 
Example 1:


Input: k = 9, x = 1

Output: 6

Explanation:

As shown in the table below, 6 is the greatest cheap number.

xnumBinary RepresentationPriceAccumulated Price11001111201012130112414100151510127161102917111312


Example 2:


Input: k = 7, x = 2

Output: 9

Explanation:

As shown in the table below, 9 is the greatest cheap number.

xnumBinary RepresentationPriceAccumulated Price210001002200101123001112240100022501010226011013270111142810001529100116210101028


 
Constraints:


	1 <= k <= 1015
	1 <= x <= 8

