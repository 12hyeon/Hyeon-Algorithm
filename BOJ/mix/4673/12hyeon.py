nums = [x for x in range(1, 9994)]

def next(num):
    result = num + sum(map(int, list(str(num))))
    return result

def delete(num):
    if num in nums:
        nums.remove(num)
        delete(next(num))
        return 1
    return 0

i = 1
while i < 10000:
    result = delete(next(i))
    if result == 0:
        i += 1
print(nums)
