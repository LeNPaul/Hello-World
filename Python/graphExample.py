import matplotlib.pyplot as plt
import numpy as np

domain = 4
stepSize = 0.01

x = np.arange(0.0, domain, stepSize)
function = np.sin(2*np.pi*x)
plt.plot(x, function)

plt.xlabel('time (s)')
plt.ylabel('voltage (mV)')
plt.title('About as simple as it gets, folks')
plt.grid(True)
plt.savefig("test.png")
plt.show()
