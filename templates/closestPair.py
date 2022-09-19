import math
def dis(point1,point2):
    return math.sqrt((point1[0]-point2[0])*(point1[0]-point2[0]) + (point1[1]-point2[1])*(point1[1]-point2[1]))

def closedDis(point,n):
    # For n<=3 points, we will brute force
    if(n<=3):

        mnm=100000000000
        for i in range(n):
            for j in range(n):
                if(i!=j):
                    mnm=min(mnm,dis(point[i],point[j]))
        return mnm
    
    # We will divide the range in two half
    mid=n//2
    leftPoints =  point[:mid]
    rightPoints= point[mid:]
    # Recursively calling left half and right half
    lVal = closedDis(leftPoints,mid)
    rVal =  closedDis(rightPoints,n-mid)

    # d in minimum of both sides
    d=min(lVal,rVal)

    # Storing the other points which are d<=middle point
    otherP=[]
    
    for i in range(mid):
        if(dis(leftPoints[i],point[mid])<=d):
            otherP.append(leftPoints[i])
    for i in range(n-mid):
        if(dis(rightPoints[i],point[mid])<=d):
            otherP.append(rightPoints[i])
    otherP.sort(key = lambda x:x[1])
    otherMinm=10000000
    
    # Using bottom up approach checking greedily these points.  
    lP=len(otherP)
    for i in range(lP-1,-1,-1):
        cnt=0

        for j in range(i-1,-1,-1):
            cnt=cnt+1
            otherMinm=min(otherMinm,dis(otherP[i],otherP[j]))
            if(cnt>6):
                break
    return min(otherMinm,d)



n=int(input("Give the number of Points: "))
point=[]
for i in range(n):
    x=int(input("Give X coordinate: "))
    y=int(input("Give Y coordinate: "))
    point.append([x,y])
point=sorted(point)
ans=closedDis(point,n)
print("Minimum distance is : ",ans)
