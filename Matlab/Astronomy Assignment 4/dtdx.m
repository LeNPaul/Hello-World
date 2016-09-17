function [dtdx] = dtdx(x,pc,ynt,ynf)

dtdx = -((pc^2)*ynf)/((ynt^8.5)*x^2)