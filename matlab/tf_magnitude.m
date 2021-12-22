omega = 0:.1:100;
for i=1:length(omega)
    mag(i) = abs(1/(1+j*omega(i)));
end
figure(1), clf
    plot(omega, mag, 'linewidth', 2)
    grid on
    ylabel('|H(omega)|')
    xlabel('omega in rad/s')
    title('TF magnitude of H=1/(1+j*omega)')
    print -dpng tf_magnitude

omega = logspace(-3, 3);
for i=1:length(omega)
    magLog(i) = abs(1/(1+j*omega(i)));
    phaseLog(i) = 180/pi*angle(1/(1+j*omega(i)));
end

figure(2), clf
    semilogx(omega, magLog, 'linewidth', 2)
    grid on
    ylabel('|H(omega)|')
    xlabel('log(omega) in rad/s')
    title('TF magnitude of H=1/(1+j*omega)')    
    print -dpng tf_magnitude_log

figure(3), clf
    semilogx(omega, phaseLog, 'linewidth', 2)
    grid on
    ylabel('phase(H(omega)) in degrees')
    xlabel('log(omega) in rad/s')
    title('TF phase of H=1/(1+j*omega)')    
    print -dpng tf_phase_log
    