f = 490;  % pwm frequency
T = 1/f;  % pwm period
Vcc = 5;  % supply voltage

tau = [T/2, T, 2*T, 3*T, 4*T, 5*T, 10*T, 100*T];
tau = [T, 10*T, 100*T, 1000*T];
alpha = 0:.1:1;

for i=1:length(tau)
    for j=1:length(alpha)
        V_plus(i,j) = Vcc*(1-exp(-alpha(j)*T/tau(i)))/(1-exp(-T/tau(i)));
        V_minus(i,j) = V_plus(i,j)*exp(-(1-alpha(j))*T/tau(i));
    end
end

figure(1), clf
for i=1:length(tau)
    plot(alpha, V_plus(i,:),'r')
    hold on
    plot(alpha, V_minus(i,:),'k')
    pause
end

figure(2), clf
for i=1:length(tau)
    plot(alpha, V_plus(i,:)-V_minus(i,:))
    hold on
    pause
end