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


// cMenuMgr.cpp: implementation of the cMenuMgr class.
//
//////////////////////////////////////////////////////////////////////
#include "StdAfx.h"
#include "win_type_global.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <math.h>
#include "cMenuMgr.h"
#include "EngineApp.h"
#include "cMenuMgr.h"
#include "lang_gen.h"
#include "gfx_util.h"
#include "cLabelLinkGfx.h"
#include "cImageLinkGfx.h"
#include "cLabelGfx.h"
#include "ErrorMsg.h"

static const char* lpszUrlHome = "http://www.invido.it";
static const char* lpszUrlDonate = "http://sourceforge.net/donate/index.php?group_id=155065";
static const char* lpszMsgUrl = "Creato da www.invido.it";
static const char* lpszVersion = "Tressette ver. 0.7.4";
static const char* lpszIniFontVera = "data/font/vera.ttf"; 
static const char* lpszDonateImage = "data/images/donate.png";
static const char* lpszDonateImageOver = "data/images/donate_over.png";

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

const SDL_Color cMenuMgr::staColor_on = {253, 252, 250};
const SDL_Color cMenuMgr::staColor_off = {128,128,128};
const SDL_Color cMenuMgr::staColor_white = {255,255,255};
const SDL_Color cMenuMgr::staColor_ombre = { 87, 87, 87, 50 };
const SDL_Color cMenuMgr::staColor_black= { 0, 0, 0 };
const SDL_Color cMenuMgr::staColor_gray= { 128, 128, 128};



////////////////////////////////////////
//       cMenuMgr
/*! 
// \param cEngineApp* pApp : 
// \param cGameMainGfx* pGfx : 
*/
cMenuMgr::cMenuMgr(cEngineApp* pApp, cGameMainGfx* pGfx)
{
    m_pApp = pApp;
    m_pfont1 = 0;
    m_pfont2 = 0;
    m_pInvidoGfx = pGfx;
    m_ifocus_valuesM_A = 0;
    m_pLanString = 0;
    m_pSurf_Bar = 0;
    m_pScene_background = 0;
    m_bMouseInside = FALSE;
    m_pLabelVersion = 0;

}


////////////////////////////////////////
//       ~cMenuMgr
/*! 
*/
cMenuMgr::~cMenuMgr()
{
    if (m_pSurf_Bar)
    {
        SDL_FreeSurface(m_pSurf_Bar);
        m_pSurf_Bar = NULL;
    }
    delete m_phomeUrl;
    delete m_pLabelVersion;
    delete m_pdonateUrl;
}


////////////////////////////////////////
//       Init
/*! Initilialize stuff
*/
void cMenuMgr::Init(SDL_Surface *s)
{
    CHAR ErrBuff[Error::BUFDIM];
    m_pScreen = s;

    m_iSx = m_pScreen->clip_rect.w;
    m_iDebx = m_iSx / 6;
    m_iSy = m_pScreen->clip_rect.h;
    m_iDeby = m_iSy / 5;

    m_rctPanel.w = m_iSx - m_iDebx*2;
    m_rctPanel.h = m_iSy - m_iDeby*2;
    m_rctPanel.x = m_iDebx;
    m_rctPanel.y = m_iDeby;

    m_pfont1 = m_pApp->GetFontAriblk(); 
    m_pfont2 = m_pApp->GetFontVera(); 
    m_pLanString = m_pApp->GetLanguageMan();
    
    m_pSurf_Bar = SDL_CreateRGBSurface(SDL_SWSURFACE, m_rctPanel.w, m_rctPanel.h, 32, 0, 0, 0, 0);
    SDL_FillRect(m_pSurf_Bar, NULL, SDL_MapRGBA(m_pScreen->format, 255, 0, 0, 0));
    SDL_SetAlpha(m_pSurf_Bar, SDL_SRCALPHA, 127);

    // link to invido.it
    m_pfont3 = TTF_OpenFont(lpszIniFontVera, 11);
    if (m_pfont3 == 0)
    {
        sprintf(ErrBuff, "Unable to load font %s, error: %s\n", lpszIniFontVera , SDL_GetError());
        throw Error::Init(ErrBuff);
    }
    TTF_SetFontStyle(m_pfont3, TTF_STYLE_UNDERLINE);
    SDL_Rect rctBt1;
    rctBt1.h = 28;
    rctBt1.w = 150;
    rctBt1.y = m_pScreen->h -  rctBt1.h  - 0;
    rctBt1.x = m_pScreen->w -  rctBt1.w  - 20;
    m_phomeUrl = new cLabelLinkGfx;
    m_phomeUrl->m_fncbClickEvent = MakeDelegate(this, &cMenuMgr::LabelClicked);
    m_phomeUrl->Init(&rctBt1, m_pScreen,  m_pfont3, MYIDLABELURL); 
    m_phomeUrl->SetState(cLabelLinkGfx::INVISIBLE);
    m_phomeUrl->SetUrl(lpszUrlHome); 
    m_phomeUrl->SetWindowText(lpszMsgUrl);

    // label version
    m_pLabelVersion = new cLabelGfx;
    rctBt1.h = 28;
    rctBt1.w = 150;
    rctBt1.y = m_phomeUrl->m_rctButt.y - 20;
    rctBt1.x = m_phomeUrl->m_rctButt.x;
    m_pLabelVersion->m_fncbClickEvent = MakeDelegate(this, &cMenuMgr::LabelClicked);
    m_pLabelVersion->Init(&rctBt1, m_pScreen,  m_pfont2, MYIDLABELVER); 
    m_pLabelVersion->SetState(cLabelGfx::INVISIBLE);
    m_pLabelVersion->SetWindowText(lpszVersion);

    // link to donate image
    rctBt1.h = 30;
    rctBt1.w = 150;
    rctBt1.y = m_pLabelVersion->m_rctButt.y - 50;
    rctBt1.x = m_pLabelVersion->m_rctButt.x;
    m_pdonateUrl = new cImageLinkGfx;
    m_pdonateUrl->m_fncbClickEvent = MakeDelegate(this, &cMenuMgr::LabelClicked);
    m_pdonateUrl->Init(&rctBt1, m_pScreen, lpszDonateImage, lpszDonateImageOver, MYIDLABELURL); 
    m_pdonateUrl->SetState(cLabelLinkGfx::INVISIBLE);
    m_pdonateUrl->SetUrl(lpszUrlDonate); 
    
}



////////////////////////////////////////
//       drawStaticSpriteEx
/*! 
// \param int src_x : 
// \param int src_y : 
// \param int src_dx : 
// \param int src_dy : 
// \param int dst_x : 
// \param int dst_y : 
// \param SDL_Surface* sprite : 
*/
void cMenuMgr::drawStaticSpriteEx(int src_x, int src_y, int src_dx, int src_dy, 
                                  int dst_x, int dst_y, SDL_Surface* sprite) 
{
    SDL_Rect src_rec = {src_x, src_y, src_dx, src_dy};
    SDL_Rect dst_rec = {dst_x, dst_y, 0, 0};
    SDL_BlitSurface(sprite, &src_rec, m_pScreen, &dst_rec);
}

void cMenuMgr::drawRect(int x, int y, int dx, int dy, SDL_Color c) 
{
    drawStaticLine(x, y, dx, y, c);
    drawStaticLine(x, y, x, dy, c);
    drawStaticLine(dx, y, dx, dy, c);
    drawStaticLine(x, dy, dx, dy, c);
}

void cMenuMgr::drawStaticLine(int x0, int y0, int x1, int y1, SDL_Color color) 
{
    int d = (int)sqrtf(
        pow((float)(x1 - x0), 2.0f) +
        pow((float)(y1 - y0), 2.0f)
    );
    static int x = 0, y = 0;
    static int w = m_pScreen->w;
    static int h = m_pScreen->h;
    for(int t = 0; t < d; t++) 
    {
        x = x0 + (x1 - x0)*t/d;
        y = y0 + (y1 - y0)*t/d;
        if((x >= 0) && (y >= 0) && (x < w) && (y < h)) 
        {
            setPixel(m_pScreen, x, y, color);
        }
    }
}


////////////////////////////////////////
//       setPixel
/*! 
// \param  SDL_Surface* pSurface : 
// \param int x : 
// \param int y : 
// \param SDL_Color color : 
*/
void cMenuMgr::setPixel ( SDL_Surface* pSurface , int x , int y , SDL_Color color ) 
{
    //convert color
    Uint32 col = SDL_MapRGB ( pSurface->format , color.r , color.g , color.b ) ;

    //determine position
    char* pPosition = ( char* ) pSurface->pixels ;

    //offset by y
    pPosition += ( pSurface->pitch * y ) ;

    //offset by x
    pPosition += ( pSurface->format->BytesPerPixel * x ) ;

    //copy pixel data
    memcpy ( pPosition , &col , pSurface->format->BytesPerPixel ) ;
}


////////////////////////////////////////
//       fillRect
/*! 
// \param int x0 : 
// \param int y0 : 
// \param int width : 
// \param int height : 
// \param Uint32 color : 
*/
void cMenuMgr::fillRect(int x0, int y0, int width, int height, Uint32 color) 
{
    SDL_Rect rect = { x0, y0, width, height };
    SDL_FillRect(m_pScreen, &rect, color);
}

////////////////////////////////////////
//       drawBackground
/*! Draw menu background
*/
void cMenuMgr::drawBackground()
{
    //SDL_BlitSurface(m_pScene_background, &m_rctPanel, m_pScreen, &m_rctPanel);
    SDL_BlitSurface(m_pScene_background, NULL, m_pScreen, NULL);

    m_iSx = m_pScreen->clip_rect.w;
    m_iDebx = m_iSx / 6;
    m_iSy = m_pScreen->clip_rect.h;
    m_iDeby = m_iSy / 5;

    Uint32 c_bluefg = SDL_MapRGB(m_pScreen->format, 51, 72, 133);
    Uint32 c_redfg = SDL_MapRGB(m_pScreen->format, 153, 202, 51);
    
    // don't invert, because content overwrite header
    // content
    //fillRect(m_iDebx, m_iDeby, m_iSx - m_iDebx*2, m_iSy - m_iDeby*2, c_bluefg);
    GFX_UTIL::DrawStaticSpriteEx(m_pScreen, 0, 0, m_rctPanel.w, m_rctPanel.h, m_rctPanel.x, m_rctPanel.y, m_pSurf_Bar);

    // header bar
    fillRect(m_iDebx, m_iDeby-2, m_iSx - m_iDebx*2, 38, c_redfg);
    
    
    drawRect(m_iDebx-1, m_iDeby-1, m_iSx - m_iDebx + 1, m_iSy - m_iDeby + 1, staColor_gray);
    drawRect(m_iDebx-2, m_iDeby-2, m_iSx - m_iDebx + 2, m_iSy - m_iDeby + 2, staColor_black);
    drawRect(m_iDebx, m_iDeby, m_iSx - m_iDebx, m_iSy - m_iDeby, staColor_white);
    drawRect(m_iDebx, m_iDeby, m_iSx - m_iDebx, m_iDeby + 36, staColor_white);
    
}


////////////////////////////////////////
//       drawStringSH
/*! 
*/
void cMenuMgr::drawStringSH(const char* tmp, int x, int y, SDL_Color& color, TTF_Font* customfont)
{
    int tx, ty;
    TTF_SizeText(customfont, tmp, &tx, &ty);
    SDL_Surface* s = TTF_RenderText_Blended(customfont, tmp, staColor_ombre);
    drawStaticSpriteEx(0, 0, tx, ty, x+2, y+2, s);
    SDL_FreeSurface(s);
    s = TTF_RenderText_Blended(customfont, tmp, color);
    drawStaticSpriteEx(0, 0, tx, ty, x, y, s);
    SDL_FreeSurface(s);
}


////////////////////////////////////////
//       HandleOptionMenu
/*! Menu options
*/
void   cMenuMgr::HandleOptionMenu()
{
    SDL_Color c = staColor_white;
    drawBackground();
    int iNumItemInMenu = 4;
    
    // Draw title bar
    drawStringSH(m_pLanString->GetStringId(cLanguages::ID_MEN_OPTIONS).c_str(), 
                 m_iDebx+10, m_iDeby+5, c, m_pfont1);
    
    // General
    if (m_ifocus_valuesM_A != 0)
    {
        c = staColor_off; 
    }
    else 
    {
        c = staColor_on;
    }
    drawStringSH(m_pLanString->GetStringId(cLanguages::ID_OPT_GENERAL).c_str(),
                 m_iDebx+10, m_iDeby+50, c, m_pfont1);
    // Deck
    if (m_ifocus_valuesM_A != 1) 	
    {
        c = staColor_off; 
    }
    else 
    {
        c = staColor_on;
    }
    drawStringSH( m_pLanString->GetStringId(cLanguages::ID_MAZZONAME).c_str(),
                  m_iDebx+10, m_iDeby+90, c, m_pfont1);
    // Match
    if (m_ifocus_valuesM_A != 2)
    {
        c = staColor_off;
    }
    else 
    {
        c = staColor_on;
    }
    drawStringSH(m_pLanString->GetStringId(cLanguages::ID_OPT_GAME).c_str(),
                 m_iDebx+10, m_iDeby+130, c, m_pfont1);

    // Go back
    if (m_ifocus_valuesM_A != 3) 	
    {
        c = staColor_off;
    }
    else 
    {
        c = staColor_on;
    }
    drawStringSH( m_pLanString->GetStringId(cLanguages::ID_BACK).c_str(),
                  m_iDebx+10, m_iSy-m_iDeby-40, c, m_pfont1);

   
    SDL_Event event;
    while (SDL_PollEvent(&event)) 
    {
        if(event.type == SDL_QUIT) 
        {
            m_pApp->LeaveMenu(); 
            break;
        }

        if(event.type == SDL_KEYDOWN) 
        {			
            if(event.key.keysym.sym == SDLK_UP) 
            {
                m_ifocus_valuesM_A--;
                if(m_ifocus_valuesM_A < 0) 
                {
                    m_ifocus_valuesM_A = 0;
                }
            }			
            if(event.key.keysym.sym == SDLK_DOWN) 
            {
                m_ifocus_valuesM_A++;
                if(m_ifocus_valuesM_A > iNumItemInMenu) 
                {
                    m_ifocus_valuesM_A = iNumItemInMenu;
                }
            }
            if(event.key.keysym.sym == SDLK_RETURN) 
            {
                optionMenuNext();
            }
            if (event.key.keysym.sym == SDLK_ESCAPE ) 
            {
                m_pApp->LeaveMenu(); 
            }
        }
        if (event.type == SDL_MOUSEMOTION)
        {
            if ( event.motion.x >= m_rctPanel.x && event.motion.x <=  m_rctPanel.x + m_rctPanel.h &&
                 event.motion.y >= m_rctPanel.y && event.motion.y <= m_rctPanel.y + m_rctPanel.h)
            {
                // mouse is inner to the box 
                if ( event.motion.y >= m_iDeby+90 && event.motion.y < m_iDeby+130 )
                {
                    m_ifocus_valuesM_A = 1;
                }
                else if ( event.motion.y >= m_iDeby+130 && event.motion.y < m_iDeby+170 )
                {
                    m_ifocus_valuesM_A = 2;
                }
                else if ( event.motion.y < m_iDeby+90)
                {
                    m_ifocus_valuesM_A = 0;
                }
                /*
                else if ( event.motion.y >= m_iDeby+170 && event.motion.y < m_iDeby+230 )
                {
                    m_ifocus_valuesM_A = 3;
                }
                */
                else if ( event.motion.y >= m_iSy-m_iDeby-40)
                {
                    m_ifocus_valuesM_A = 3;
                }
                
            }
        }
        if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            optionMenuNext();
        }
    }
}


////////////////////////////////////////
//       LabelClicked
/*! 
*/
void cMenuMgr::LabelClicked(int iButID)
{

}

////////////////////////////////////////
//       HandleRootMenu
/*! This is the first menu 0.1
*/
void   cMenuMgr::HandleRootMenu()
{
    // show the link url label 
    m_phomeUrl->SetState(cLabelLinkGfx::VISIBLE); 
    m_pLabelVersion->SetState(cLabelGfx::VISIBLE);
    m_pdonateUrl->SetState(cLabelLinkGfx::VISIBLE);
        
    SDL_Color c = staColor_white;
    drawBackground();
    int iNumItemInMenu = 4;
    
    // Draw title bar
    drawStringSH(m_pLanString->GetStringId(cLanguages::ID_WELCOMETITLEBAR).c_str(), 
                 m_iDebx+10, m_iDeby+5, c, m_pfont1);
    
    // Play
    if (m_ifocus_valuesM_A != 0)
    {
        c = staColor_off; 
    }
    else 
    {
        c = staColor_on;
    }
    drawStringSH(m_pLanString->GetStringId(cLanguages::ID_START).c_str(),
                 m_iDebx+10, m_iDeby+50, c, m_pfont1);
    // Options
    if (m_ifocus_valuesM_A != 1)
    {
        c = staColor_off; 
    }
    else 
    {
        c = staColor_on;
    }
    drawStringSH( m_pLanString->GetStringId(cLanguages::ID_MEN_OPTIONS).c_str(),
                  m_iDebx+10, m_iDeby+90, c, m_pfont1);
    // Credits
    if (m_ifocus_valuesM_A != 2)
    {
        c = staColor_off;
    }
    else 
    {
        c = staColor_on;
    }
    drawStringSH(m_pLanString->GetStringId(cLanguages::ID_CREDITS).c_str(),
                 m_iDebx+10, m_iDeby+130, c, m_pfont1);

    // Help
    if (m_ifocus_valuesM_A != 3)
    {
        c = staColor_off;
    }
    else 
    {
        c = staColor_on;
    }
    drawStringSH(m_pLanString->GetStringId(cLanguages::ID_MN_HELP).c_str(),
                 m_iDebx+10, m_iDeby+170, c, m_pfont1);

    // Quit
    if (m_ifocus_valuesM_A != 4)
    {
        c = staColor_off;
    }
    else 
    {
        c = staColor_on;
    }
    drawStringSH( m_pLanString->GetStringId(cLanguages::ID_EXIT).c_str(),
                  m_iDebx+10, m_iSy-m_iDeby-40, c, m_pfont1);
    
    SDL_Event event;
    while (SDL_PollEvent(&event)) 
    {
        if(event.type == SDL_QUIT) 
        {
            m_pApp->LeaveMenu(); 
            break;
        }

        if(event.type == SDL_KEYDOWN) 
        {
            if(event.key.keysym.sym == SDLK_UP) 
            {
                m_ifocus_valuesM_A--;
                if(m_ifocus_valuesM_A < 0) 
                {
                    m_ifocus_valuesM_A = 0;
                }
            }
            if(event.key.keysym.sym == SDLK_DOWN) 
            {
                m_ifocus_valuesM_A++;
                if(m_ifocus_valuesM_A > iNumItemInMenu) 
                {
                    m_ifocus_valuesM_A = iNumItemInMenu;
                }
            }
            if(event.key.keysym.sym == SDLK_RETURN) 
            {
                rootMenuNext();
            }
            if (event.key.keysym.sym == SDLK_ESCAPE ) 
            {
                m_pApp->LeaveMenu(); 
            }
        }
        if (event.type == SDL_MOUSEMOTION)
        {
            if ( event.motion.x >= m_rctPanel.x && event.motion.x <=  m_rctPanel.x + m_rctPanel.h &&
                 event.motion.y >= m_rctPanel.y && event.motion.y <= m_rctPanel.y + m_rctPanel.h)
            {
                // mouse is inner to the box 
                if ( event.motion.y >= m_iDeby+90 && event.motion.y < m_iDeby+130 )
                {
                    m_ifocus_valuesM_A = 1;
                }
                else if ( event.motion.y >= m_iDeby+130 && event.motion.y < m_iDeby+170 )
                {
                    m_ifocus_valuesM_A = 2;
                }
                else if ( event.motion.y < m_iDeby+90)
                {
                    m_ifocus_valuesM_A = 0;
                }
                else if ( event.motion.y >= m_iDeby+170 && event.motion.y < m_iDeby+230 )
                {
                    m_ifocus_valuesM_A = 3;
                }
                else if ( event.motion.y >= m_iSy-m_iDeby-40)
                {
                    m_ifocus_valuesM_A = 4;
                }
                m_bMouseInside = TRUE;
            }
            else
            {
                // mouse outside, no focus
                m_bMouseInside = FALSE;
            }
        }
        if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            if (m_bMouseInside)
            {
                rootMenuNext();
            }
        }
        else if (event.type == SDL_MOUSEBUTTONUP)
        {
            m_phomeUrl->MouseUp(event);
            m_pdonateUrl->MouseUp(event);
        }
    }
    // draw url label
    m_phomeUrl->Draw(m_pScreen);
    // draw label version
    m_pLabelVersion->Draw(m_pScreen);
    m_pdonateUrl->Draw(m_pScreen);
}


////////////////////////////////////////
//       rootMenuNext
/*! Next menu after root
*/
void   cMenuMgr::rootMenuNext()
{

    switch(m_ifocus_valuesM_A) 
    {
        case 0 :			// Play
            m_pApp->SetNextMenu(MENU_GAME); 
            break;
        case 1 :		 	// Options
            m_pApp->SetNextMenu(MENU_OPTIONS);
            break;
        case 2 :		 	// Credits
            m_pApp->SetNextMenu(MENU_CREDITS);
            break;
        case 3 :		 	// Help
            m_pApp->SetNextMenu(MENU_HELP);
            break;
        case 4 :			// Quit
            m_pApp->LeaveMenu(); 
            break;
    }
}


////////////////////////////////////////
//       optionMenuNext
/*! 
*/
void   cMenuMgr::optionMenuNext()
{

    switch(m_ifocus_valuesM_A) 
    {
        case 0 :			// Play
            m_pApp->SetNextMenu(OPT_GENERAL); 
            break;
        case 1 :		 	// Options
            m_pApp->SetNextMenu(OPT_DECK);
            break;
        case 2 :		 	// Credits
            m_pApp->SetNextMenu(OPT_GAME);
            break;
        case 3 :		 	// Go back
            m_pApp->LeaveMenu();
            break;
        default:
            ASSERT(0);
            break;
    }
}
