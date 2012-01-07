// file: cImageLinkGfx.cpp

/*
    Tressette
    Copyright (C) 2005  Igor Sarzi Sartori

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public
    License along with this library; if not, write to the Free
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    Igor Sarzi Sartori
    www.invido.it
    6colpiunbucosolo@gmx.net
*/



// cImageLinkGfx.cpp: implementation of the cImageLinkGfx class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "cImageLinkGfx.h"
#include "gfx_util.h"

#ifdef WIN32
#include "shellapi.h"
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

cImageLinkGfx::cImageLinkGfx()
{

}

cImageLinkGfx::~cImageLinkGfx()
{

}



void   cImageLinkGfx::Draw(SDL_Surface*  pScreen)
{
    if (m_eState != INVISIBLE)
    {
        if (m_bIsEnabled)
        {
            // begin stuff mouse
            Uint8 state;
            int mx, my;
            state = SDL_GetMouseState(&mx, &my);
            if ( mx >=  m_rctButt.x  && mx <= m_rctButt.x + m_rctButt.w &&
                  my >=  m_rctButt.y  && my <= m_rctButt.y + m_rctButt.h)
            {
                // mouse on button
                m_colCurrent = GFX_UTIL_COLOR::Orange;
            }
            else
            {
                m_colCurrent = GFX_UTIL_COLOR::White;
            }
            // end stuff mouse

            int tx, ty;
	        TTF_SizeText(m_pFontText, m_strButText.c_str(), &tx, &ty);
            int iXOffSet = (m_rctButt.w - tx)/2 ;
            if (iXOffSet < 0)
            {
                iXOffSet = 1;
            }
            int iYOffset = (m_rctButt.h - ty)/2 ;

            iYOffset = 0;
            iXOffSet = 0;
            GFX_UTIL::DrawString(pScreen, m_strButText.c_str(), m_rctButt.x + iXOffSet, 
                                 m_rctButt.y + iYOffset, m_colCurrent, m_pFontText);

            
        }
        else
        {
            // button disabled 
            // TO DO
        }
    }
}
