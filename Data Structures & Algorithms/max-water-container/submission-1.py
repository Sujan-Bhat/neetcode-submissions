class Solution:
    def maxArea(self, heights: List[int]) -> int:
        i, j = 0, len(heights) - 1
        max_vol = 0
        while i < j:
            # compute area for current pair
            width = j - i
            h = min(heights[i], heights[j])
            max_vol = max(max_vol, h * width)

            # move only the pointer with smaller height
            if heights[i] < heights[j]:
                i += 1
            else:
                j -= 1
        return max_vol
