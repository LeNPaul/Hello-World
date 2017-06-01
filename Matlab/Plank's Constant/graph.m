function graph

M = dlmread('Data.txt')
	

x = M(:,1)
y = M(:,2)

scatter(x,y,'.')
title('Soyp')
xlabel('GLYCEROL CONTENT')
ylabel('VELOCITY (MICRONS/SEC)')