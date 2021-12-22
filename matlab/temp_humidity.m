load temp_humidity

humidity = dht(250:end,1);
%humidity_smoothed = dht(:,2);
temperature = dht(250:end,3);
%temp_smoothed = dht(:,4);

alpha = 0.8;
t_smoothed = zeros(size(temperature));
t_smoothed(1) = temperature(1);
h_smoothed = zeros(size(temperature));
h_smoothed(1) = humidity(1);
for i=2:length(temperature)
    t_smoothed(i) = alpha*t_smoothed(i-1)...
        + (1-alpha)*temperature(i);
    h_smoothed(i) = alpha*h_smoothed(i-1)...
        + (1-alpha)*humidity(i);
end
    
    

figure(1)
    clf, hold on
    ylabel('humidity')
    xlabel('time (2 seconds)')
    plot(humidity,'k')
    plot(h_smoothed,'b')
    print -dpng humidity
    
figure(2)
    clf, hold on
    ylabel('temperature in degrees F')
    xlabel('time (2 seconds)')    
    plot(temperature,'k')
    plot(t_smoothed,'b')
    print -dpng temperature