function mainfun(pc,h,max)

%Defining initial functions and conditions

x = 0.01;

ynq = (1/3)*pc*x^3;
ynp = pc - (1/6)*(pc^2)*(x^2);
ynf = (1/3)*(pc^2)*(x^3);
ynt = 1 - (1/6)*(pc^4)*(x^4);

Q = [];
P = [];
F = [];
T = [];
U = [];
V = [];

%Integrating using Euler's Method

while x < max
    
    ynq = ynq + h*(pc*(x^2))/(ynt);
    Q = [Q;ynq];
    
    ynp = ynp - h*(pc*ynq)/(ynt*x^2);
    P = [P;ynp];
    
    ynf = ynf + h*pc^2*(ynt^2)*(x^2);
    F = [F;ynf];
    
    ynt = ynt - h*((pc^2)*ynf)/((ynt^8.5)*x^2);
    T = [T;ynt];
    
    x = x + h;
    
end

%Plotting all of the graphs

figure(1)
subplot(2,2,1)
plot(Q)
title('Continuity of Mass')
xlabel('x')
ylabel('q')

subplot(2,2,2)
plot(P)
title('Hydrostatic Equilibrium')
xlabel('x')
ylabel('p')

subplot(2,2,3)
plot(F)
title('Thermal Equilbrium')
xlabel('x')
ylabel('f')

subplot(2,2,4)
plot(T)
title('Radiative Transfer')
xlabel('x')
ylabel('t')

%Calculating the UV invariants

i = 1;

while i < (max/h)

    ui = 1*(P(i)*i^3)/(T(i)*Q(i));
    U = [U;ui];
    
    vi = 1*Q(i)/(T(i)*i);
    V = [V;vi];
    
    i = i + 1;
    
end

%Plotting the UV invariants and the envelope functions

figure(2)
hold on
scatter(V,U,'.')
title('UV Invariants')
xlabel('V')
ylabel('U')

M = dlmread('E1.txt');
x = M(:,2);
y = M(:,1);
plot(x,y,'m')

M = dlmread('E1.5.txt');
x = M(:,2);
y = M(:,1);
plot(x,y,'c')

M = dlmread('E2.txt');
x = M(:,2);
y = M(:,1);
plot(x,y,'r')

M = dlmread('E3.txt');
x = M(:,2);
y = M(:,1);
plot(x,y,'g')

M = dlmread('E4.txt');
x = M(:,2);
y = M(:,1);
plot(x,y,'b')

M = dlmread('E5.txt');
x = M(:,2);
y = M(:,1);
plot(x,y,'m')

M = dlmread('E6.txt');
x = M(:,2);
y = M(:,1);
plot(x,y,'r')

M = dlmread('E7.txt');
x = M(:,2);
y = M(:,1);
plot(x,y,'c')

M = dlmread('E8.txt');
x = M(:,2);
y = M(:,1);
plot(x,y,'r')

hold off

end