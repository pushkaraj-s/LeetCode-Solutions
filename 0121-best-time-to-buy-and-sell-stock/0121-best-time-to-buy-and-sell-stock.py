class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        # Get 2 variables, Traverse through an array
        # Keep storing min and max but also check index of numbers
        min_price = float('inf') # Store minimum value
        max_profit = 0 # Store max profit
        
        
        for i in range(len(prices)):
            potential_profit = prices[i] - min_price
            if potential_profit > max_profit:
                max_profit = potential_profit
            
            if prices[i] < min_price:
                min_price = prices[i]
        
        return max_profit