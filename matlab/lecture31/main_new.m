period = 2e-3; % 2 millisecond period of Arduino PWM
amplitude = 5;
width = 0.2*period;
x = signalGenerator(period);  % instantiate signal class
x.pulse(amplitude, width);     % make x a pulse with amplitude and width
%x.hat(amplitude);             % x is a triangle hat function
%x.ramp(amplitude, pi/4);       % ramp and then zero
X = FourierSeries(x, 100);
figure(2), clf, X.plotCoefficients;
for K = [0,1,2,3,4,10,50,100]
    figure(1), clf, 
        t = x.time;
        t = [t, t(end)+x.time];
        t = [t, t(end)+x.time];
        xx = [x.signal, x.signal, x.signal];
        xhat = [X.approxSignal(K), X.approxSignal(K), X.approxSignal(K)];
        plot(t, xx, 'k', 'LineWidth', 2)
        hold on
        plot(t, xhat, 'b', 'LineWidth', 2)
        xlabel('t')
        ylabel(['N=' num2str(K)])
        foo = ['lecture31_fourier' num2str(K) '.png']
        print(foo, '-dpng')
        %K
        %pause
end

