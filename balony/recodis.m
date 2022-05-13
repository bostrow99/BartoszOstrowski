close all;
clear;
clc;

fs = 44100;

Test1= Response("przed wydzialem/test3.wav","f");

Reverb1 = Response("audytorium centralne/test2.wav","f",fs);
Reverb2 = Response("korytarz/test2.wav","f",fs);
Reverb3 = Response("gg aula/test5.wav","f",fs);
Reverb4 = Response("sala 133/test2.wav","f",fs);
%%
figure(1)
subplot(2,2,1)
Reverb1.time_norm("lin","t")
title("audytorium centralne",'FontSize', 24)
%set(gca,'XLim',[0 2])
%set(gca,'YLim',[-60 0])
subplot(2,2,2)
Reverb2.time_norm("dec","t")
title("Korytarz 4C",'FontSize', 24)
set(gca,'XLim',[0 2])
set(gca,'YLim',[-60 0])
subplot(2,2,3)
Reverb3.time_norm("dec","t")
title("aula gmach główny",'FontSize', 24)
set(gca,'XLim',[0 8])
set(gca,'YLim',[-60 0])
subplot(2,2,4)
Reverb4.time_norm("dec","t")
title("próbka testowa",'FontSize', 24)
set(gca,'XLim',[0 0.5])
set(gca,'YLim',[-60 0])
%%

xr=Reverb2.h;
xcr=(xcorr(xr(:,1),xr(:,1)));
tc=[(-length(xr(:,1))+1):(length(xr(:,1))-1)]./fs;
figure();
plot(tc*300,20*log10(abs(xcr)))
xlabel('[m]')
ylabel('dB')