class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        n = len(nums)
        m = len(set(nums))
        if(n==m):
            return False
        else:
            return True
    

        