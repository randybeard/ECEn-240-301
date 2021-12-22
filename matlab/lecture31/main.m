period = 2*pi;
amplitude = 1;
width = 0.1*pi;
x = signalGenerator(period);  % instantiate signal class
x.pulse(amplitude, width);     % make x a pulse with amplitude and width
%x.hat(amplitude);             % x is a triangle hat function
%x.ramp(amplitude, pi/4);       % ramp and then zero
X = FourierSeries(x, 100);
figure(2), clf, X.plotCoefficients;
for K = 0:5:50
    figure(1), clf, 
        plot([x.time, x.signal)
        hold on
        plot(x.time, X.approx_signal(K))
        K
        pause
end

