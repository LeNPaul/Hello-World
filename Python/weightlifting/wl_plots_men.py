import numpy as np
import matplotlib.pyplot as plt
import wl_data as data

#   http://matplotlib.org/users/legend_guide.html
#   http://stackoverflow.com/questions/22408237/named-colors-in-matplotlib
#   http://matplotlib.org/api/markers_api.html

plt.scatter(data.x105pm,data.y105pm, marker='o', s=50, c='slategrey', edgecolor='none')
plt.scatter(data.x105m,data.y105m, marker='o', s=50, c='crimson', edgecolor='none')
plt.scatter(data.x94m,data.y94m, marker='o', s=50, c='mediumseagreen', edgecolor='none')
plt.scatter(data.x85m,data.y85m, marker='o', s=50, c='dodgerblue', edgecolor='none')
plt.scatter(data.x77m,data.y77m, marker='o', s=50, c='salmon', edgecolor='none')
plt.scatter(data.x69m,data.y69m, marker='o', s=50, c='darkorchid', edgecolor='none')
plt.scatter(data.x62m,data.y62m, marker='o', s=50, c='sienna', edgecolor='none')
plt.scatter(data.x56m,data.y56m, marker='o', s=50, c='orangered', edgecolor='none')

'''
plt.scatter(data.x75pf,data.y75pf, marker='^', s=50, c='dodgerblue', edgecolor='none')
plt.scatter(data.x75f,data.y75f, marker='^', s=50, c='darkorchid', edgecolor='none')
plt.scatter(data.x69f,data.y69f, marker='^', s=50, c='crimson', edgecolor='none')
plt.scatter(data.x63f,data.y63f, marker='^', s=50, c='mediumseagreen', edgecolor='none')
plt.scatter(data.x58f,data.y58f, marker='^', s=50, c='orangered', edgecolor='none')
plt.scatter(data.x53f,data.y53f, marker='^', s=50, c='darkturquoise', edgecolor='none')
plt.scatter(data.x48f,data.y48f, marker='^', s=50, c='steelblue', edgecolor='none')
'''

plt.legend([ '105+' , '105' , '94' , '85' , '77' , '69' , '62' , '56' ], loc=4, title="Weightclass (Kg)")
#plt.legend([ '105+' , '105' , '94' , '85' , '77' , '69' , '62' , '56',  '75+' , '75' , '69' , '63' , '58' , '53' , '48' ], loc=4)

plt.title('Snatch to Clean & Jerk Ratio of 2012 London Male Olympic Weightlifters')
plt.xlabel('Snatch (Kg)')
plt.ylabel('Clean & Jerk (Kg)')

plt.grid(b=True, which='both', color='0.25',linestyle='-')

plt.show()
