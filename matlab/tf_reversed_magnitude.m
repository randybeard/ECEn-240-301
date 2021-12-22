omega = logspace(-3, 3);
for i=1:length(omega)
    magLog(i) = abs(j*omega(i)/(1+j*omega(i)));
    phaseLog(i) = 180/pi*angle(j*omega(i)/(1+j*omega(i)));
end

figure(1), clf
    semilogx(omega, magLog, 'linewidth', 2)
    grid on
    ylabel('|H(omega)|')
    xlabel('log(omega) in rad/s')
    title('TF magnitude of H=j*omega/(1+j*omega)')    
    print -dpng tf_reversed_magnitude_log

figure(2), clf
    semilogx(omega, phaseLog, 'linewidth', 2)
    grid on
    ylabel('phase(H(omega)) in degrees')
    xlabel('log(omega) in rad/s')
    title('TF phase of H=j*omega/(1+j*omega)')    
    print -dpng tf_reversed_phase_log
    