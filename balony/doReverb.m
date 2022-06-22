function y = doReverb(x,alpha_G1,alpha_G1,alpha_G1)
    y = do_G(x,alpha_G1,buf_G1,p_G1) + do_G(x,alpha_G2,buf_G2,p_G2) + do_G(x,alpha_G3,buf_G3,p_G3) + do_G(x,alpha_G4,buf_G4,p_G4);
    y = do_WP(y,alpha_WP1,buf_WP1,p_WP1);
    y = do_WP(y,alpha_WP2,buf_WP2,p_WP2);
    y = do_WP(y,alpha_WP3,buf_WP3,p_WP3);
end
