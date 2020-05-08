#!/bin/bash



    git checkout linux  #if you do a checkout as root, will all files belong to root? I don't think so...
    
#     In opensuse 13.2, run as root:
    
     zypper in libSDL-1_2-0 \
        libSDL-devel  \
        libSDL_gfx15   \
        libSDL_gfx-devel   \
        libSDL_image-1_2-0 \
        libSDL_image-devel \
        libSDL_mixer-1_2-0 \
        libSDL_mixer-devel \
        libSDL_net-1_2-0 \
        libSDL_net-devel \
        libSDL_sound-1_0-1 \
        libSDL_sound-devel \
        libSDL_ttf-2_0-0 \
        libSDL_ttf-devel \
        libexpat1        \
        libexpat-devel;

#     Then, return as user and run
#     ./configure
#     make
# 
#     Then,
#     cd src/TreClientVs6/
#     ./tressettetux
