close all;
clear;
clc;

fs = 44100;
Guitar = Response("guitar.wav","f",fs);
piezo = Response("piezo.wav","f",fs);
GuitarPiezo = Guitar.filter(piezo.h,"t");

DelayTemp = zeros(0.5e5,1);
DelayTemp(1,1) = 1;
DelayTemp(end-1,1) = 0.5;

Delay = Response(DelayTemp,"t",fs);
%Delay.time("t");

feedback = Response("Speaker.wav","b",fs,"SpeakerToPiezo2.wav");
feedback.h(460000:end,1)=0;
feedback.H=fft(feedback.h);


Test1= Response("przed wydzialem/test3.wav","f");

Reverb1 = Response("audytorium centralne/test2.wav","b",fs,"komora/test2.wav");
Reverb2 = Response("korytarz/test2.wav","b",fs,"komora/test2.wav");
Reverb3 = Response("gg aula/test5.wav","b",fs,"przed wydzialem/test2.wav");
Reverb4 = Response("sala 133/test2.wav","f",fs);
GuitarReverb = Guitar.filter(Reverb3.H,"f");

GuitarDelay = Guitar.filter(Delay.H,"f");

%%
figure(1)
subplot(2,2,1)
Reverb4.time_norm("lin","t",2e-3)
title("Odpowiedź impulsowa - audytorium centralne",'FontSize', 24)
set(gca,'XLim',[0 1])
subplot(2,2,2)
Reverb2.time_norm("lin","t",2e-3)
title("Odpowiedź impulsowa - Korytarz 4C",'FontSize', 24)
set(gca,'XLim',[0 1])
subplot(2,2,3)
Reverb3.time_norm("lin","t",2e-3)
title("Odpowiedź impulsowa - aula gmach główny",'FontSize', 24)
set(gca,'XLim',[0 5])
subplot(2,2,4)
Test1.time_norm("lin","t",2e-3)
title("Odpowiedź impulsowa - próbka testowa",'FontSize', 24)
set(gca,'XLim',[0 0.1])

figure(2)
subplot(2,2,1)
Reverb1.spectrum("lin")
title("Widmo - audytorium centralne",'FontSize', 24)

subplot(2,2,2)
Reverb2.spectrum("lin")
title("Widmo- Korytarz 4C",'FontSize', 24)

subplot(2,2,3)
Reverb3.spectrum("lin")
title("Widmo - aula gmach główny",'FontSize', 24)

subplot(2,2,4)
Test1.spectrum("lin")
title("Widmo - próbka testowa",'FontSize', 24)
