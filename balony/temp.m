 Guitar = Response("guitar.wav","f",fs);
 fs=44100; 
 Reverb1 = Response("audytorium centralne/test2.wav","b",fs,"przed wydzialem/test3.wav");
 GuitarReverb = Guitar.filter(Reverb1.H,"f");
 GuitarReverb.time("t");

 [m]