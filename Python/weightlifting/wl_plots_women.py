import numpy as np
import matplotlib.pyplot as plt
import wl_data as data

#   http://matplotlib.org/users/legend_guide.html
#   http://stackoverflow.com/questions/22408237/named-colors-in-matplotlib
#   http://matplotlib.org/api/markers_api.html


plt.scatter(data.x75pf,data.y75pf, marker='o', s=50, c='slategrey', edgecolor='none')
plt.scatter(data.x75f,data.y75f, marker='o', s=50, c='crimson', edgecolor='none')
plt.scatter(data.x69f,data.y69f, marker='o', s=50, c='mediumseagreen', edgecolor='none')
plt.scatter(data.x63f,data.y63f, marker='o', s=50, c='dodgerblue', edgecolor='none')
plt.scatter(data.x58f,data.y58f, marker='o', s=50, c='salmon', edgecolor='none')
plt.scatter(data.x53f,data.y53f, marker='o', s=50, c='darkorchid', edgecolor='none')
plt.scatter(data.x48f,data.y48f, marker='o', s=50, c='sienna', edgecolor='none')

plt.legend([ '75+' , '75' , '69' , '63' , '58' , '53' , '48' ], loc=4)

plt.title('Snatch to Clean & Jerk Ratio of 2012 London Olympic Weightlifters')
plt.xlabel('Snatch (Kg)')
plt.ylabel('Clean & Jerk (Kg)')

plt.grid(b=True, which='both', color='0.25',linestyle='-')

plt.show()
