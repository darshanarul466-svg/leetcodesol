class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def first():
            l = 0
            r = len(nums)-1
            indx = -1
            while l<=r:
                mid = l + (r-l) //2
                if nums[mid]>=target:
                    r = mid - 1
                else:
                    l = mid+1
                if nums[mid] == target:
                    indx = mid
            return indx
        def last():
            l = 0 
            r = len(nums)-1
            indxl = -1
            while l<=r:
                mid = l + (r-l) //2
                if nums[mid]<=target:
                    l = mid+1
                else:
                    r = mid-1
                if nums[mid]==target:
                    indxl = mid
            return indxl
        return [first() , last()]