def suma(nums):   # 238 除了自身以外数组的乘积
    n = len(nums)
    ans = [1] * n
    for i in range(1,n):
        ans[i] = ans[i-1]*nums[i-1]
    right = 1
    for i in range(n-1, -1, -1):
        ans[i] = ans[i] * right
        right *= nums[i]
    return ans

if __name__ == "__main__":
    nums = list(map(int, input("shuru: ").split()))
    ans = suma(nums)
    print("shuzu:",ans)