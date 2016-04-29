import matplotlib as plt
import csv

#Notes: add each input to list, refer to list index for line; monthly, total, categories (monthly, total), daily

#Taking in user input

choice = raw_input("To input data enter yes. \n")

fr = open("Personal Finance.txt", "r")
text = fr.read()
fr.close()

#Use while loop for multiple entries instead of just if statement

if choice == 'yes':
    date = raw_input("Enter the date of transaction (dd/mm/yyyy): ")
    place = raw_input("Enter the place of transaction: ")
    item = raw_input("Enter the items bought: ")
    price = raw_input("Enter the price of the items bought: ")
    category = raw_input("Enter the category of items bought: ")

    #Recording the data to .txt file

    fw = open("Personal Finance.txt", "w")
    fw.write(text)
    fw.write(date + ", ")
    fw.write(place + ", ")
    fw.write(item + ", ")
    fw.write(price + ", ")
    fw.write(category  + "\n")
    fw.close()

#Calculate total spendings

f = open("Personal Finance.txt")
csv_f = csv.reader(f)
total = 0

for row in csv_f:
    total = total + float(row[3])

#Calculate total grocery spendings

bin = []

f = open("Personal Finance.txt")
csv_f = csv.reader(f)
for i, row in enumerate(csv_f):
    if "Groceries" in row[4]:
        bin.append(i)

gtotal = 0

f = open("Personal Finance.txt")
csv_f = csv.reader(f)

#Problem: not going through the loop for each element in bin?

for i in bin:
    for n, j in enumerate(csv_f):
        print i
        if n == i:
            gtotal = gtotal + float(j[3])

print(gtotal)
