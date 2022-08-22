'''
Problem link: 
https://leetcode.com/problems/jewels-and-stones/

Problem:
You're given strings jewels representing the types of stones that are jewels, and stones representing the 
stones you have. Each character in stones is a type of stone you have. You want to know how many of the stone
 you have are also jewels.
Letters are case sensitive, so "a" is considered a different type of stone from "A".
'''
class Solution(object):
    def numJewelsInStones(self, jewels, stones):
        """
        :type jewels: str
        :type stones: str
        :rtype: int
        """
        m1 = {}
        count = 0
        # counting the frequencies of the characters in the string
        for i in jewels:
            if i in m1:
                m1[i] += 1
            else:
                m1[i] = 1
        
        for val in stones:
            if val in m1:
                count += 1 
        
        return count

obj = Solution()
print(obj.numJewelsInStones("aA","aAAbbbb"))
