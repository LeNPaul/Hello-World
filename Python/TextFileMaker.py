fw = open("sample.txt", "w")
fw.write("Testing writing some stuff\n")
fw.write("Another line\n")
fw.close()

fr = open("sample.txt", "r")
text = fr.read()
print(text)
fr.close()