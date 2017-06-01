function [dfdx] = dfdx(x,pc,ynt)

dfdx = pc^2*(ynt^2)*(x^2)