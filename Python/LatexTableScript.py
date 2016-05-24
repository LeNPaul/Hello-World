print("Enter the title of the table")
title = raw_input()

print("Enter the number of columns")
numbcol = int(raw_input())

fw = open("table.txt", "w")
fw.write(r"\begin{table}[H]" + "\n")
fw.write("\centering \n")
fw.write("\caption{" + title + "} \n")
fw.write("\begin{tabular}{")

colcount = 0

while(colcount < numbcol):
    fw.write("c ")
    colcount = colcount + 1

fw.write("} \n")

fw.close()

fr = open("table.txt", "r")
text = fr.read()
print(text)
fr.close()

'''
An example LaTeX table

\begin{table}[h]
\centering
\caption{Miscellaneous Measurements and Values}
\begin{tabular}{c c}
Wavelength of HeNe Laser (m) & $6.328 \times 10^{-7} \pm 2 \times 10^{-8} $ \\
Initial Length of Invar (m) & 0.080 $\pm 0.005$ \\
Initial Length of Copper (m) & 0.065 $\pm 0.005$ \\
Initial Length of Alumina (m) & 0.075 $\pm 0.005$ \\
\end{tabular}
\label{tab:my_label}
\end{table}
'''
