import math
import matplotlib.pyplot as plt
import numpy as np

nsteps = 1000
xlist = []
x = 0

for i in range(nsteps):
    xlist.append(x)
    x += 1
    print x

plt.plot(xlist, t)
plt.show()
