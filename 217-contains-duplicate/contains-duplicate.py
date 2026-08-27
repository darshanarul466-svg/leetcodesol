class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        fnd = set()
        for i in nums:
                if i in fnd:
                    return True
                fnd.add(i)
        return False