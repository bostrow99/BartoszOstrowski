%{
loopLength = 10;

    a=zeros(1,10);
    b=zeros(1,10);
    c=zeros(1,10);
    d=zeros(1,10);


for z=1:loopLength
   
   a(z)=addition(Guitar.h,d);
   b(z) = convolution(a(z),Reverb1.h);
   c(z) = b(z-1);
   d(z) = convolution(c(z),feedback.h*0.1);
   Output = addition(Guitar.h,b(z));

   end
%}
    a=Guitar.h;
    b=convolution(a,Reverb1.h,"n");
    d1=convolution(b,feedback.h,"n");
    d2=convolution(d1,feedback.h,"n");
    d3=convolution(d2,feedback.h,"n");
    d4=convolution(d3,feedback.h,"n");
    e=addition(Guitar.h,b,"n");
    e=addition(e,d1);
    e=addition(e,d2);
    e=addition(e,d3);
    e=addition(e,d4);
