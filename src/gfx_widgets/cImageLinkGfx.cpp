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
#include <SDL_image.h>
#include "cImageLinkGfx.h"
#include "gfx_util.h"
#include "ErrorMsg.h"

#ifdef WIN32
#include "shellapi.h"
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

cImageLinkGfx::cImageLinkGfx()
{
    m_pLinkImage = NULL;
}

cImageLinkGfx::~cImageLinkGfx()
{
    if(m_pLinkImage)
    {
        SDL_FreeSurface(m_pLinkImage);
        m_pLinkImage = NULL;
    }
    if(m_pLinkImageOver)
    {
        SDL_FreeSurface(m_pLinkImageOver);
        m_pLinkImageOver = NULL;
    }
}

void cImageLinkGfx::Init(SDL_Rect* pRect, SDL_Surface*  pScreen, LPCSTR imageFile, LPCSTR imageFileOver, int iButID)
{
    m_rctButt = *pRect;
    m_pLinkImage = IMG_Load(imageFile);
    CheckErrorLoadImage(m_pLinkImage, imageFile);
    m_pLinkImageOver = IMG_Load(imageFileOver);
    CheckErrorLoadImage(m_pLinkImageOver, imageFileOver);

    m_iButID = iButID;
}

void cImageLinkGfx::CheckErrorLoadImage(SDL_Surface* pImgSrf, LPCSTR imageFile)
{
    if (pImgSrf == 0)
    {
        CHAR ErrBuff[512];
        sprintf(ErrBuff, "Unable to load %s  image\n" , imageFile);
        throw Error::Init(ErrBuff);
    }
}


void cImageLinkGfx::Draw(SDL_Surface*  pScreen)
{
    if (m_eState != INVISIBLE && m_pLinkImage != NULL)
    {
        if (m_bIsEnabled)
        {
            SDL_Surface* psurfImg = m_pLinkImage;
            // begin stuff mouse
            Uint8 state;
            int mx, my;
            state = SDL_GetMouseState(&mx, &my);
            if ( mx >=  m_rctButt.x  && mx <= m_rctButt.x + m_rctButt.w &&
                  my >=  m_rctButt.y  && my <= m_rctButt.y + m_rctButt.h)
            {
                // mouse on button
                psurfImg = m_pLinkImageOver;
                
            }
            // end stuff mouse

            
            SDL_BlitSurface(psurfImg, &psurfImg->clip_rect, pScreen, &m_rctButt);

            
        }
        else
        {
            // link disabled 
            // TO DO
        }
    }
}
