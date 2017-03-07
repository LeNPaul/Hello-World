import numpy as np
import csv
import matplotlib.lines as mlines
import matplotlib.pyplot as plt

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
x_value = 2
y_value = 11
weight_classes = [ '105+' , '105' , '94' , '85' , '77' , '69' , '62' , '56' ]
class_colours = ['slategrey', 'crimson', 'mediumseagreen', 'dodgerblue', 'salmon', 'darkorchid', 'sienna', 'orangered']

for row in csv_f:
    x_data.append(float(row[x_value]))
    y_data.append(float(row[y_value]))
    if float(row[2]) >105:
        plt.scatter(row[x_value],row[y_value], marker='o', s=point_size,c='slategrey', edgecolor='none')
    elif float(row[2]) <105 and float(row[2]) > 94:
        plt.scatter(row[x_value],row[y_value], marker='o', s=point_size,c='crimson', edgecolor='none')
    elif float(row[2]) <94 and float(row[2]) > 85:
        plt.scatter(row[x_value],row[y_value], marker='o', s=point_size,c='mediumseagreen', edgecolor='none')
    elif float(row[2]) <85 and float(row[2]) > 77:
        plt.scatter(row[x_value],row[y_value], marker='o', s=point_size,c='dodgerblue', edgecolor='none')
    elif float(row[2]) <77 and float(row[2]) > 69:
        plt.scatter(row[x_value],row[y_value], marker='o', s=point_size,c='salmon', edgecolor='none')
    elif float(row[2]) <69 and float(row[2]) > 62:
        plt.scatter(row[x_value],row[y_value], marker='o', s=point_size,c='darkorchid', edgecolor='none')
    elif float(row[2]) <62 and float(row[2]) > 56:
        plt.scatter(row[x_value],row[y_value], marker='o', s=point_size,c='sienna', edgecolor='none')
    elif float(row[2]) <56:
        plt.scatter(row[x_value],row[y_value], marker='o', s=20,c='orangered', edgecolor='none')

for weight, colour in enumerate(class_colours):
    x = []
    y = []
    plt.scatter(x,y, c=colour, s=point_size, label=weight_classes[weight], edgecolor='none')

plt.legend(loc=4, title="Weightclass (Kg)")

plt.title('Total to Bodyweight Ratio of Male Olympic Weightlifters (2000 - 2016)')
plt.yscale('log')
plt.xlabel('Bodyweight (Kg)')
plt.ylabel('Total (Kg)')

coefficients = np.polyfit(x_data, y_data, 1) #before: 3
polynomial = np.poly1d(coefficients)
x_data.sort()
ys = polynomial(x_data)

plt.plot(x_data,ys, c='black')

plt.grid(b=True, which='both', color='0.25',linestyle='-')

plt.show()
