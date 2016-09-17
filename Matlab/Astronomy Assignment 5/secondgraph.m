function secondgraph

hold on

M = dlmread('1M07.txt')	
x = M(:,3)
y = M(:,2)
plot(x,y,'b','Linewidth',2)

%plot(x(36),y(36),'r.','MarkerSize',20)
%plot(x(51),y(51),'b.','MarkerSize',20)
%plot(x(66),y(66),'c.','MarkerSize',20)
%plot(x(78),y(78),'m.','MarkerSize',20)

%legend('0.7 M','1.0 M','1.5 M','3.0 M')

M = dlmread('2M10.txt')	
x = M(:,3)
y = M(:,2)
plot(x,y,'g','Linewidth',2)

%plot(x(36),y(36),'r.','MarkerSize',20)
%plot(x(51),y(51),'b.','MarkerSize',20)
%plot(x(68),y(68),'k.','MarkerSize',20)
%plot(x(134),y(134),'m.','MarkerSize',20)

M = dlmread('3M15.txt')	
x = M(:,3)
y = M(:,2)
plot(x,y,'r','Linewidth',2)

%plot(x(42),y(42),'r.','MarkerSize',20)
%plot(x(68),y(68),'b.','MarkerSize',20)
%plot(x(83),y(83),'k.','MarkerSize',20)

M = dlmread('4M30.txt')	
x = M(:,3)
y = M(:,2)
plot(x,y,'c','Linewidth',2)

%plot(x(61),y(61),'r.','MarkerSize',20)
%plot(x(73),y(73),'b.','MarkerSize',20)

title('Temperature as Function of Density')
xlabel('Density')
ylabel('Temperature')
%legend('0.7 M','1.0 M','1.5 M','3.0 M')