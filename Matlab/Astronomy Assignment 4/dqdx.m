function [dqdx] = dqdx(x,pc,ynt)

dqdx = (pc*(x^2))/(ynt)