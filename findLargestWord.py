f = open("text/100k_wrds_.txt", "r")

max = 0
for x in f:
    temp = len(x)
    if(temp > max):
        max = temp
print(max)

f.close()