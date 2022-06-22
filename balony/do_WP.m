function [y,buf,p] = do_WP(x,alpha,buf,p)
    y = buf(p);
    y = y - alpha * x;
    new = y * alpha + x;
    buf(p) = new;
    p=p+1;
    if p == length(buf)
       p = 1;
    end
end