intervals=[]
for i in range(1,10):
    x=int(input())
    y=int(input())
    intervals.append([x,y])
intervals.sort( key= lambda x:x[1] )
