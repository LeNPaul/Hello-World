function [dpdx] = dpdx(x,pc,ynq,ynt)

dpdx = -(pc*ynq)/(ynt*x^2)