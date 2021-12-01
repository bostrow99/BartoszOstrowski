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

Reverb1 = Response("gg aula/test5.wav","b",fs,"przed wydzialem/test3.wav");

GuitarReverb = Guitar.filter(Reverb1.H,"f");

GuitarDelay = Guitar.filter(Delay.H,"f");


%GuitarReverb.play;