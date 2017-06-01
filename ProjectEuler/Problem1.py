import math
import time

#Add up all multiples of 3 and 5
#Generate list of numbers from 0 to 1000
#Divide each number by 3 and 5, if whole number, add number to a list (avoid duplicates)
#Find total in that list

start = time.time()

numberlist = []
finallist = []
i = 0

while i < 1000:
    numberlist.append(i)
    i += 1

for i in numberlist:

    if i%3 == 0:
        finallist.append(i)

    elif i%5 == 0:
        finallist.append(i)

print sum(finallist)

elapsed1 = time.time() - start

print elapsed1

#This way uses less code and is more efficient

counter = 0
for x in range(1000):
    if x%3 == 0 or x%5 == 0:
        counter += x
print counter

elapsed2 = time.time() - elapsed1 - start

print elapsed2
