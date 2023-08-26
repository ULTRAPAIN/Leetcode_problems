class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x<0:
            return False
        ans=0
        n=x
        while(x!=0):
            rem=x%10
            ans=ans*10+rem
            x=x//10
        if (ans==n):
            return True
        else:
            return False