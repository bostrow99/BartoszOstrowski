close all;
clear;
clc;

fs = 44100;

piezo = Response("piezo.wav","f",fs);

DelayTemp = zeros(1,50000);
DelayTemp(1,1) = 1;
DelayTemp(1,2e4) = 1;

Delay = Response(DelayTemp,"t",fs);
Delay.time("t");

Reverb1 = Response("gg aula/test5.wav","b",fs);

Guitar = Response("guitar.wav","f",fs);
GuitarReverb = Guitar.filter(Reverb1.H,"f");

%GuitarReverb.play;