close all;
clear;
clc;

fs = 44100;

Test1 = Response("przed wydzialem/test3.wav","f");
Test2 = Response("komora/test2.wav","f");
Reverb1 = Response("audytorium centralne/test2.wav","f",fs);
Reverb2 = Response("korytarz/test2.wav","f",fs);
Reverb3 = Response("gg aula/test5.wav","f",fs);
Reverb4 = Response("sala 133/test2.wav","f",fs);

close all;
clear;
clc;

fs = 44100;

Test1 = Response("przed wydzialem/test3.wav","f");
Test2 = Response("komora/test2.wav","f");
Reverb1 = Response("audytorium centralne/test2.wav","f",fs);
Reverb2 = Response("korytarz/test2.wav","f",fs);
Reverb3 = Response("gg aula/test5.wav","f",fs);
Reverb4 = Response("sala 133/test2.wav","f",fs);

%% Wykresy czasowe

figure(1);
subplot(2,3,1);
Test1.time_norm("dec","t");
title(["Przebieg czasowy - nagranie kontrolne","(teren otwarty)"], 'FontSize', 24);
set(gca,'XLim',[0 0.5]);
set(gca,'YLim',[-70 0]);

subplot(2,3,2);
Test2.time_norm("dec","t");
title(["Przebieg czasowy - nagranie kontrolne", "(komora bezechowa)"], 'FontSize', 24);
set(gca,'XLim',[0 0.5]);
set(gca,'YLim',[-70 0]);

subplot(2,3,3);
Reverb1.time_norm("dec","t");
title(["Przebieg czasowy - Audytorium centralne",""],'FontSize', 24);
set(gca,'XLim',[0 2]);
set(gca,'YLim',[-70 0]);

subplot(2,3,4);
Reverb2.time_norm("dec","t");
title("Przebieg czasowy - Korytarz 4C",'FontSize', 24);
set(gca,'XLim',[0 2]);
set(gca,'YLim',[-70 0]);

subplot(2,3,5);
Reverb3.time_norm("dec","t");
title("Przebieg czasowy - Aula GGPW",'FontSize', 24);
set(gca,'XLim',[0 7.8]);
set(gca,'YLim',[-70 0]);

subplot(2,3,6);
Reverb4.time_norm("dec","t");
title("Przebieg czasowy - Sala 133",'FontSize', 24);
set(gca,'XLim',[0 1.8]);
set(gca,'YLim',[-70 0]);




%% guitaris


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

%%

