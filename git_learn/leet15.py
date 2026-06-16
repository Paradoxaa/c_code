def rotate(nums,k):   # 189 轮转数组
    n = len(nums)
    k = k%n

    def reverse(left, right):
        while left<right:
            nums[left], nums[right] = nums[right], nums[left]
            left +=1
            right -=1
    
    reverse(0, n-1)
    reverse(0, k-1)
    reverse(k, n-1)

if __name__ == "__main__":
    nums = list(map(int, input("shuru: ").split()))
    k = int(input("lunzhuan: "))
    rotate(nums, k)
    print("shuzu:",nums)