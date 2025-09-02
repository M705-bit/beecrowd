class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        x = len(str1)
        while (len(str1) % x !=0) or (len(str2) % x != 0):
            x-=1
        if str1 + str2 != str2 + str1:
            return ""
        else:
            return str1[:x]
