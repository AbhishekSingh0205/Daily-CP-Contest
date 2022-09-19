# Boolean function, it will be used to sort the pair of arrays (2d array).
 
def good(element1, element2):
    if(element1[1]<element2[1]):
        return True
    elif(element1[1]==element2[1] and element1[0]<=element2[0]):
        return True
    else:
        return False
 
# Following function is used for merging the array.
# left index is the starting of the array.
# right index is ending of the array.
def merge(array, left_index, right_index, middle):
    # Left_copy is the array left array from left to middle element.
    # Right_copy is the right array from right to middle element.
    left_copy = array[left_index:middle + 1]
    right_copy = array[middle+1:right_index+1]
 
    left_copy_index = 0
    right_copy_index = 0
    sorted_index = left_index
 
    while left_copy_index < len(left_copy) and right_copy_index < len(right_copy):
        if good(left_copy[left_copy_index],right_copy[right_copy_index]):
            array[sorted_index] = left_copy[left_copy_index]
            left_copy_index = left_copy_index + 1
 
        else:
            array[sorted_index] = right_copy[right_copy_index]
            right_copy_index = right_copy_index + 1
 
        sorted_index = sorted_index + 1
       
    while left_copy_index < len(left_copy):
        array[sorted_index] = left_copy[left_copy_index]
        left_copy_index = left_copy_index + 1
        sorted_index = sorted_index + 1
 
    while right_copy_index < len(right_copy):
        array[sorted_index] = right_copy[right_copy_index]
        right_copy_index = right_copy_index + 1
        sorted_index = sorted_index + 1
# Following the merge sort function which will recursively call its right and left halves.
def merge_sort(array, left_index, right_index):
    if left_index >= right_index:
        return
 
    middle = (left_index + right_index)//2
    merge_sort(array, left_index, middle)
    merge_sort(array, middle + 1, right_index)
    merge(array, left_index, right_index, middle)
 
 
 
n=int(input("Give the number of Jobs: "))
JobsTime=[]
for i in range(n):
    x=int(input("Give the start time: "))
    y=int(input("Give the end time: "))
    JobsTime.append([x,y])
merge_sort(JobsTime,0,len(JobsTime)-1)
print(JobsTime)
endingTime=0
cnt=0
startTime=0
for i in range(n):
    if(JobsTime[i][0]>=endingTime):
        cnt=cnt+1
        endingTime=JobsTime[i][1]
 
print("We can do maximum ",cnt," Jobs")
