t=0:.01:2;
x = sin(t);
y = x + 0.1*randn(1,length(t));

yhat = zeros(size(t));
alpha =0.9;

for i=2:length(t)
    yhat(i) = alpha*yhat(i-1) + (1-alpha)*y(i);
end

figure(1)
    clf, hold on
    plot(t, y, 'k')
    plot(t, yhat, 'b')
    xlabel('time')
    ylabel('sensor')
    
  