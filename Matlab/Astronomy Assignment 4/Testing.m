M = dlmread('E2.txt')

x = M(:,1)
y = M(:,2)

plot(x,y)
title('Position Voltage as a Function of Velocity Function')
xlabel('Position Voltage (V)')
ylabel('Velocity Voltage (V)')