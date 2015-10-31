    Tressette: a software card game to play 4 players tressette.
    Copyright (C) 2005 Igor Sarzi Sartori
	
	
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    Author   : Igor Sarzi Sartori
    Home Page: www.invido.it
    Email    : 6colpiunbucosolo@gmx.net
     

    Documentation: see the doc sub directory.
    
    === HOW TO INSTALL AND RUN
    
    After cloning the repo, do 
    
    git checkout linux
    
    In opensuse 13.2, run as root:
    
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

    Then, return as user and run
    ./configure
    make

    Then,
    cd src/TreClientVs6/
    ./tressettetux      