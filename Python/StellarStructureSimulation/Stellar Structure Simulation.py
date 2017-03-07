import math
import matplotlib.pyplot as plt
import numpy as np

#Initial conditions

x = 0.01
pc = 0.1

xlist = []
qlist = []
plist = []
flist = []
tlist = []

dt = 0.0001
nsteps = 1000

xlist = np.arange(0.0, nsteps, 1)

#for i in range(nsteps):
#    xlist.append(i)

#Guess a value of pc and an initial x value

pc = 0.712081
x = 0.01

#Equations for defining initial conditions

q = ((pc)*(x**3))/3

p = pc - ((pc**2)*(x**2))/6

f = ((pc**2)*(x**3))/3

t = 1 - ((pc**4)*(x**4))/6

x = 0.08
q = 0.06
p = 80
f = 9.3e-7
t = 0.76

#Transformed differential equations

dqdx = (p*t**2)/t

dpdx = -(p*q)/(t*x**2)

dfdx = (p**2)*(t**2)*(x**2)

dtdx = -((p**2)*f)/((t**8.5)*(x**2))

#Initial integration step

#Integration
#Use Euler integration

for i in enumerate(xlist):
    q += dt*dqdx
    qlist.append(q)

    p += dt*dpdx
    plist.append(p)

    f += dt*dfdx
    flist.append(f)

    t += dt*dtdx
    tlist.append(t)

plt.plot(xlist, qlist)
plt.plot(xlist, plist)
plt.plot(xlist, flist)
plt.plot(xlist, tlist)
plt.show()
