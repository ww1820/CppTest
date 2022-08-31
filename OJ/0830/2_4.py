import math

N=int(input())
IN=[]
shuru=input()
for i in range(N):
    IN.append(int(shuru.split(" ")[i]))
chazhi=[]
for i in range(N-1):
    chazhi.append(math.fabs(IN[i+1]-IN[i]))
max_num=max(chazhi)
index = chazhi.index(max_num)

if index==0:
    IN[1]=IN[0]
elif index==N-2:
    IN[N-1]=IN[N-2]
else:
    test1=[]
    test2=[]
    for m in range(N):
        test1.append(IN[m])
        test2.append(IN[m])
    test1[index]=(test1[index-1]+test2[index+1])//2
    test2[index+1]=(test2[index]+test2[index+2])//2

    chazhi1=[]
    for i in range(N - 1):
        chazhi1.append(math.fabs(test1[i + 1] - test1[i]))
    chazhi2=[]
    for i in range(N - 1):
        chazhi2.append(math.fabs(test2[i + 1] - test2[i]))
    if max(chazhi1)>max(chazhi2):
        IN=test1
    else:
        IN=test2


chazhi=[]
for i in range(N-1):
    chazhi.append(math.fabs(IN[i+1]-IN[i]))
print(int(max(chazhi)))