import matplotlib.pyplot as plt
import math
import numpy as np

x = np.linspace(0, 100, 1000)

y = []

d = []

for i, p in enumerate(x):
    f = 50*(1 - math.exp(-0.1*x[i]))
    y.append(f)

for i, p in enumerate(x):
    f = 100*(math.exp(-0.1*x[i] - 0.7)) + 50
    d.append(f)

plt.title("Number Of Particles In Each Quadrant")
plt.xlabel("Time (arb. Units)")
plt.ylabel("Counts In Each Quadtrant (arb. Units)")

plt.xlim(0,100)
plt.ylim(0,100)

plt.plot(x, y, 'r', label = 'Right Quadrant')
plt.plot(x, d, label = 'Left Quadrant')
plt.legend(loc = 'upper right')
plt.show()
