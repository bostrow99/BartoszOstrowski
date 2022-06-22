Test2 = Response("komora/test2.wav","f",44100);
DelayTemp = zeros(0.5e5,1);
DelayTemp(1,1) = 1;
G = Response("guitar2.wav","f",44100);
y = zeros(0.5e5,1);
DelayTemp = G.h;

Buf_G1 = zeros(1730,1);
Buf_G2 = zeros(1494,1);
Buf_G3 = zeros(1941,1);
Buf_G4 = zeros(2156,1);
Buf_WP1 = zeros(240,1);
Buf_WP2 = zeros(81,1);
Buf_WP3 = zeros(23,1);

p_G1 = 1;
p_G2 = 1;
p_G3 = 1;
p_G4 = 1;
p_WP1 = 1;
p_WP2 = 1;
p_WP3 = 1;

alpha_G1 = 0.805;
alpha_G2 = 0.827;
alpha_G3 = 0.783;
alpha_G4 = 0.764;
alpha_WP1 = 0.7;
alpha_WP2 = 0.7;
alpha_WP3 = 0.7;

for i=1:length(DelayTemp)
    sum = DelayTemp(i);

    [eu, Buf_WP1, p_WP1]= do_WP(DelayTemp(i),alpha_WP1,Buf_WP1,p_WP1);

    [eu, Buf_WP2, p_WP2] = do_WP(eu,alpha_WP2,Buf_WP2,p_WP2);

    [eu, Buf_WP3, p_WP3] = do_WP(eu,alpha_WP3,Buf_WP3,p_WP3);

    [G1, Buf_G1, p_G1] = do_G(eu,alpha_G1,Buf_G1,p_G1); 
    [G2, Buf_G2, p_G2] = do_G(eu,alpha_G2,Buf_G2,p_G2);
    [G3, Buf_G3, p_G3] = do_G(eu,alpha_G3,Buf_G3,p_G3);
    [G4, Buf_G4, p_G4] = do_G(eu,alpha_G4,Buf_G4,p_G4);
    
    eu = (G1 + G2 + G3 + G4)/4;

    sum = 0.5 * sum + 0.5 * eu;
    y1(i) = sum;
end

for i=1:length(DelayTemp)
    sum = DelayTemp(i);


    [G1, Buf_G1, p_G1] = do_G(sum,alpha_G1,Buf_G1,p_G1); 
    [G2, Buf_G2, p_G2] = do_G(sum,alpha_G2,Buf_G2,p_G2);
    [G3, Buf_G3, p_G3] = do_G(sum,alpha_G3,Buf_G3,p_G3);
    [G4, Buf_G4, p_G4] = do_G(sum,alpha_G4,Buf_G4,p_G4);
    
    eu = (G1 + G2 + G3 + G4)/4;

    [eu, Buf_WP1, p_WP1]= do_WP(eu,alpha_WP1,Buf_WP1,p_WP1);

    [eu, Buf_WP2, p_WP2] = do_WP(eu,alpha_WP2,Buf_WP2,p_WP2);

    [eu, Buf_WP3, p_WP3] = do_WP(eu,alpha_WP3,Buf_WP3,p_WP3);
    
    sum = 0.5 * sum + 0.5 * eu;
    y2(i) = sum;
end
%%
y1r = Response(y1,'t',44100);
y2r = Response(y2,'t',44100);
figure(1);
subplot(2,1,1);
y1r.time_norm('dec','t');
subplot(2,1,2);
y2r.time_norm('dec','t');
figure(2);
subplot(2,1,1);
y1r.time_norm('lin','t');
subplot(2,1,2);
y2r.time_norm('lin','t');

fs=44100;
        f = linspace(-fs/2,fs/2, length(y1r.H));
        x1 = fftshift(abs((y1r.H))/length(y1r.H));     
        x2 = fftshift(abs((y1r.H))/length(y1r.H));   
        semilogx(f, x1/max(x1)); 
        hold on;
        semilogx(f, x2/max(x2)); 
        hold off;
