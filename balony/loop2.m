fs = 44100;
Guitar = Response("guitar.wav","f",fs);
DelayTemp = zeros(0.5e5,1);
DelayTemp(1,1) = 1;
DelayTemp(end-1,1) = 0.5;
Delay = Response(DelayTemp,"t",fs);

Y=zeros(length(conv(Guitar.h,Delay.h)),1);
L=length(Delay.h);
for n=1:L
    Y(n)=Guitar.h(n:(n+L-1))'*Delay.h;




end
