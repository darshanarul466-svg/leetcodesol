class Solution:
    def plusOne(self, digits: list[int]) -> list[int]:
        temp="".join(str(x) for x in digits)
        int_temp = int(temp)+1
        temp=str(int_temp)
        return list(map(int,temp))


        