fs = 44100;
Guitar = Response("guitar.wav","f",fs);
Reverb1 = Response("audytorium centralne/test2.wav","b",fs,"przed wydzialem/test3.wav");
DelayTemp = zeros(0.5e5,1);
DelayTemp(100,1) = 1;
DelayTemp(0.4e5,1) = 0.5;
Delay = Response(DelayTemp,"t",fs);
feedback = Response("Speaker.wav","b",fs,"SpeakerToPiezo2.wav");
feedback.h(460000:end,1)=0;
feedback.H=fft(feedback.h);
% Y=zeros(length(conv(Guitar.h,Delay.h)),1);

% L=length(Delay.h);
% 
% bufor1 = Guitar.h;
% bufor1(end:end+L)=0;
%%
% for n=1:96023
%     Y(n)=bufor1(n:(n+L-1))'*Delay.h;
% 
% 
% 
% end
%%
x=Guitar.h;
h=Delay.h;
f=feedback.h;
m=length(x);
n=length(h);
o=length(f);
X=[x',zeros(1,n+o)];
H=[h',zeros(1,m+o)];
F=[f',zeros(1,m+n)];
for i=1:n+m-1
    B(i)=0;
    for j=1:m
        if(i-j+1>0)
            B(i)=(B(i)+X(j)*H(i-j+1));
            
            
        else
        end
    end
end

figure(1)
plot(B)
%sound(GD,fs);
%pause(3)
%sound(Y,fs);
