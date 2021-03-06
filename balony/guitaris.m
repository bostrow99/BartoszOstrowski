% CLEARING
close all;
clear;
clc;

% READING GUITAR
fs = 44100;
G = Response("guitar2.wav","f",fs);
% EXTRACION OF IMPULSE RESPONSE 

% OUTDOOR 
H1_1 = Response("audytorium centralne/test2.wav","b",fs, ...
    "przed wydzialem/test3.wav");
H2_1 = Response("korytarz/test2.wav","b",fs,"przed wydzialem/test3.wav");
H3_1 = Response("gg aula/test5.wav","b",fs,"przed wydzialem/test2.wav");
H4_1 = Response("sala 133/test2.wav","b",fs,"przed wydzialem/test2.wav");
% NOECHO CHAMBER
H1_2 = Response("audytorium centralne/test2.wav","b",fs, ...
    "komora/test2.wav");
H2_2 = Response("korytarz/test2.wav","b",fs,"komora/test2.wav");
H3_2 = Response("gg aula/test5.wav","b",fs,"komora/test2.wav");
H4_2 = Response("sala 133/test2.wav","b",fs,"komora/test2.wav");
%% 
% CONVOLUTION

% OUTDOOR 
R1_1 = G.filter(H1_1.H,"f");
R2_1 = G.filter(H2_1.H,"f");
R3_1 = G.filter(H3_1.H,"f");
R4_1 = G.filter(H4_1.H,"f");
% NOECHO CHAMBER
R1_2 = G.filter(H1_2.H,"f");
R2_2 = G.filter(H2_2.H,"f");
R3_2 = G.filter(H3_2.H,"f");
R4_2 = G.filter(H4_2.H,"f");

%%
% GRAPHS
figure(1);
subplot(2,1,1);
G.time_norm("lin","t");
title("Przebieg czasowy - Próbka gitary",'FontSize', 24);
set(gca,'XLim',[0 15]);
set(gca,'YLim',[-1 1]);

figure(2);
subplot(2,1,1);
R1_2.time_norm("lin","t");
title("Przebieg czasowy - Gitara z pogłosem (Audytorium Centralne)", ...
    'FontSize', 24);
set(gca,'XLim',[0 15]);
set(gca,'YLim',[-1 1]);
subplot(2,1,2);
R2_2.time_norm("lin","t");
title("Przebieg czasowy - Gitara z pogłosem (Korytarz 4C)", ...
    'FontSize', 24);
set(gca,'XLim',[0 15]);
set(gca,'YLim',[-1 1]);

figure(3);
subplot(2,1,1);
R3_2.time_norm("lin","t");
title("Przebieg czasowy - Gitara z pogłosem (Aula GGPW)", ...
    'FontSize', 24);
set(gca,'XLim',[0 15]);
set(gca,'YLim',[-1 1]);
subplot(2,1,2);
R4_2.time_norm("lin","t");
title("Przebieg czasowy - Gitara z pogłosem (Sala 133)", ...
    'FontSize', 24);
set(gca,'XLim',[0 15]);
set(gca,'YLim',[-1 1]);






