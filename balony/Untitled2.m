close all;
clear;
[reverb1,fs]=audioread("gg aula/test5.wav");
[reverb2,fs]=audioread("korytarz/test2.wav");
[reverb3,fs]=audioread("audytorium centralne/test2.wav");
[test,fs]=audioread("przed wydzia³em/test2.wav");

[guitar,fs]=audioread("guitar.wav");


%%
%obróbka d³ugoœci

reverb1=reverb1(1:240000,:);
reverb2=reverb2(1:240000,:);
test=test(1:240000,:);
guitar=guitar(1:240000,:);

%%
%korelcja

reverb1CR=(xcorr(reverb1(:,1),reverb1(:,1)));                           %gmach g³ówny
reverb2CR=(xcorr(reverb2(:,1),reverb2(:,1)));                           %korytarz
reverb3CR=(xcorr(reverb3(:,1),reverb3(:,1)));                           %audytorium centralne
testCR=(xcorr(test(:,1),test(:,1)));                                    %bez pog³osu

%pozycjonowanie
reverb1TC=[(-length(reverb1(:,1))+1):(length(reverb1(:,1))-1)]./fs;     %gmach g³ówny
reverb2TC=[(-length(reverb2(:,1))+1):(length(reverb2(:,1))-1)]./fs;     %korytarz
reverb3TC=[(-length(reverb3(:,1))+1):(length(reverb3(:,1))-1)]./fs;     %audytorium centralne
testTC=[(-length(test(:,1))+1):(length(test(:,1))-1)]./fs;              %bez pog³osu

%%
%rysowanie
close all;
figure;
subplot(5,1,1);
plot(reverb1);
title("Gmach g³ówny")
subplot(5,1,2);
plot(reverb2);
title("Korytarz")
subplot(5,1,3);
plot(reverb2);
title("Audytorium Centralne")
subplot(5,1,4);
plot(test);
title("Bez pog³osu")
%{
subplot(5,1,5);
plot(guitar);
title("Gitara")
%}

figure;

subplot(2,2,1);
plot(reverb1TC*300,20*log10(abs(reverb1CR)));
title("Gmach g³ówny")
set(gca,"xlim",[-10,50])
set(gca,"ylim",[0,35])

subplot(2,2,2);
plot(reverb2TC*300,20*log10(abs(reverb2CR)));
title("Korytarz")
set(gca,"xlim",[-10,50])
set(gca,"ylim",[9,35])

subplot(2,2,3);
plot(reverb3TC*300,20*log10(abs(reverb3CR)));
title("Audytorium centralne")
set(gca,"xlim",[-10,50])
set(gca,"ylim",[9,40])


subplot(2,2,4);
plot(testTC*300,20*log10(abs(testCR)));
title("Bez pog³osu")
set(gca,"xlim",[-10,50])
set(gca,"ylim",[-10,35])