'''
Problem link: 
https://leetcode.com/problems/delete-characters-to-make-fancy-string/

Problem:
A fancy string is a string where no three consecutive characters are equal.

Given a string s, delete the minimum possible number of characters from s to make it fancy.

Return the final string after the deletion. It can be shown that the answer will always be unique.
'''

class Solution:
    def makeFancyString(self, s: str) -> str:
        ans = ""
        i = 0
        j = 0
        while i < len(s):
            ans += s[i]
            count = 1
            j = i+1
            while j < len(s):
                if s[i] != s[j]:
                    break
                count += 1
                j += 1

            if count >= 3:
                ans += s[i]
                i += count-1
            i += 1
        return ans        

obj = Solution()
print(obj.makeFancyString("leeeeeeetcode"))