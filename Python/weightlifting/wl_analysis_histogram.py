import numpy as np
import csv
import matplotlib.lines as mlines
import matplotlib.pyplot as plt
from scipy.fftpack import fft, rfft

f = open('wl_data_male_2000-2016.csv')
csv_f = csv.reader(f)

#Skip header
next(csv_f)

#weight: 2
#snatch: 6
#total: 11
#clean & jerk: 10

x_data = []
y_data = []
point_size = 20
x_value = 6
y_value = 10

weight_classes = [ '105+' , '105' , '94' , '85' , '77' , '69' , '62' , '56' ]
class_colours = ['slategrey', 'crimson', 'mediumseagreen', 'dodgerblue', 'salmon', 'darkorchid', 'sienna', 'orangered']

for row in csv_f:
    x_data.append(float(row[x_value]))
    y_data.append(float(row[y_value]))

data = x_data

binwidth = 1
bin_size = np.arange(min(x_data), max(x_data) + binwidth, binwidth)
#plt.hist(data, bins=bin_size, color='dodgerblue', edgecolor='none', rwidth=0.9)

y_hist, bin_edges = y_hist,binEdges=np.histogram(data,bins=bin_size)

y_hist = y_hist[27:105]

x_hist = np.arange(len(y_hist))/(2 * np.pi)
fourier = rfft(y_hist)/len(y_hist)
#plt.plot(x_hist, abs(fourier))

fig, ax = plt.subplots(2, 1)
ax[0].hist(data, bins=bin_size, color='dodgerblue', edgecolor='none', rwidth=0.9)
ax[1].plot(x_hist, abs(fourier))

print(y_hist)

plt.show()
