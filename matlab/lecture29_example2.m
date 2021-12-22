omega1 = 100;
[Hmag1, Hangle1] = circuitTF(omega1);
omega2 = 15000;
[Hmag2, Hangle2] = circuitTF(omega2);
mag1 = 5*Hmag1
angle1 = Hangle1
mag2 = 15*Hmag2
angle2 = Hangle2

function [Hmag, Hangle] = circuitTF(omega)
    R = 20;
    L = 15e-3;
    H = j*omega*L/(R+j*omega*L);
    Hmag = abs(H);
    Hangle = angle(H) * 180/pi;
end