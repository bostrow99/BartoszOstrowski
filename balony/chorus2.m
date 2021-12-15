[x,fs]=audioread('guitar.wav');
f=1;
delay_in_sampels=0.05*fs;%50 ms delay
index=1:length(x);
sincurve = 1*sin(2*pi*index*f);
y = zeros(length(x):1);
y(1:delay_in_sampels)=x(1:delay_in_sampels);
a=1;
b=5;
for i =(delay_in_sampels+1):length(x)
    sink=abs(sincurve(i));
    delay=(delay_in_sampels+sink);
      o=ceil(i-delay);
      y(i)=(a*x(i)) + b*(x(o)); 
  end
  soundsc(y,fs)