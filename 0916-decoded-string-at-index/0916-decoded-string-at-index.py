class Solution(object):
    def decodeAtIndex(self, s, k):
        length = 0
        
        for char in s:
            if char.isalpha():
                length += 1
            else:
                length *= int(char)
        
        for char in reversed(s):
            k %= length
            
            if k == 0 and char.isalpha():
                return char
            
            if char.isalpha():
                length -= 1
            else:
                length //= int(char)