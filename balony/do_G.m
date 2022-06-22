function [y,buf,p] = do_G(x,alpha,buf,p)
    y = buf(p);
    new = y * alpha + x;
    buf(p) = new;
    p=p+1;
    if p == length(buf)
      p = 1;
    end 
end