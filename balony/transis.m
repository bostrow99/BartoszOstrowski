close all;
clear;
clc;

fs = 44100;

G = Response("guitar2.wav","f");
R = Response("guitarR.wav","f");

figure(1);
subplot(2,1,1);
G.time_norm("lin","t");
title("Pzrbeig czasowy nagrania gitary akustycznej", ...
    'FontSize', 24);
set(gca,'XLim',[0 10]);
set(gca,'YLim',[-1 1]);
subplot(2,1,2);
R.time_norm("lin","t");
title("Przebieg czasowy nagrania gitary transakustycznej", ...
    'FontSize', 24);
set(gca,'XLim',[0 10]);
set(gca,'YLim',[-1 1]);

figure(2);
subplot(2,1,1);
G.spectrum_norm("lin");
title("Widmo - nagranie gitary akustycznej",'FontSize', 24);
set(gca,'XLim',[20 2e4]);
set(gca,'YLim',[0 1]);
subplot(2,1,2);
R.spectrum_norm("lin");
title("Widmo - nagranie gitary transakustycznej",'FontSize', 24);
set(gca,'XLim',[20 2e4]);
set(gca,'YLim',[0 1]);