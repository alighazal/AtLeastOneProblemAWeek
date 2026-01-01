class Solution:
    operations = {
        "+": lambda x,y : x+y,
        "-": lambda x,y : x-y,
        "*": lambda x,y : x*y,
    }

    def diffWaysToCompute(self, expression: str) -> List[int]:
        ans = []
        for index in range(len(expression)):
            if ( expression[index] in self.operations ):
                nums1 = self.diffWaysToCompute( expression[0:index])
                nums2 = self.diffWaysToCompute( expression[index+1:])
                for n1 in nums1:
                    for n2 in nums2:
                        ans.append(  self.operations[ expression[index] ](n1,n2) )
        if ans == []:
            return [ int(expression) ]
        return ans
