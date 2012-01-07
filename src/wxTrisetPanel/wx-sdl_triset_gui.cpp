/*******************************************************************************
 * wx-sdl tutorial v1.0
 * Copyright (C) 2005 John David Ratliff
 *
 * wx-sdl is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * wx-sdl is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with wx-sdl; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*******************************************************************************/

/*******************************************************************************
// Headers-
*******************************************************************************/

#include "StdAfx.h"

#include <iostream>

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/dcbuffer.h>
#include <wx/image.h>

#include "win_type_global.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "EngineApp.h"
#include <string>
#include "ErrorMsg.h"


/*******************************************************************************
// Global Declarations
*******************************************************************************/

enum {
    ID_FRAME = 10000,
    ID_PANEL,
    IDM_FILE_EXIT,
    IDM_HELP_ABOUT
};

/*******************************************************************************
// SDLPanel Class
*******************************************************************************/

class SDLPanel : public wxPanel {
    DECLARE_CLASS(SDLPanel)
    DECLARE_EVENT_TABLE()
    
private:
    SDL_Surface *screen;

    /**
     * Called to paint the panel.
     *
     * @param event The triggering wxPaintEvent (unused).
     */
    void onPaint(wxPaintEvent &event);
    
    /**
     * Called to erase the background.
     *
     * @param event The triggering wxEraseEvent (unused).
     */
    void onEraseBackground(wxEraseEvent &event);
    
    /**
     * Called to update the panel.
     *
     * @param event The triggering wxIdleEvent (unused).
     */
    void onIdle(wxIdleEvent &event);
    
    /**
     * Creates the SDL_Surface used by this SDLPanel.
     */
    void createScreen();
    
public:
    cEngineApp*  m_pEngineApp;
    /**
     * Creates a new SDLPanel.
     *
     * @param parent The wxWindow parent.
     */
    SDLPanel(wxWindow *parent);
    
    /**
     * Destructs this SDLPanel.
     */
    ~SDLPanel();
};

inline void SDLPanel::onEraseBackground(wxEraseEvent &) {}

IMPLEMENT_CLASS(SDLPanel, wxPanel)

BEGIN_EVENT_TABLE(SDLPanel, wxPanel)
    EVT_PAINT(SDLPanel::onPaint)
    EVT_ERASE_BACKGROUND(SDLPanel::onEraseBackground)
    EVT_IDLE(SDLPanel::onIdle)
END_EVENT_TABLE()

SDLPanel::SDLPanel(wxWindow *parent) : wxPanel(parent, ID_PANEL), screen(NULL) {
    // ensure the size of the wxPanel
    wxSize size(800, 600);
    
    SetMinSize(size);
    SetMaxSize(size);
}

SDLPanel::~SDLPanel() {
    if (screen != NULL) {
        SDL_FreeSurface(screen);
    }
}

void SDLPanel::onPaint(wxPaintEvent &) {
    // can't draw if the screen doesn't exist yet
    if (screen == NULL) {
        return;
    }
    
    // lock the surface if necessary
    if (SDL_MUSTLOCK(screen)) {
        if (SDL_LockSurface(screen) < 0) {
            return;
        }
    }
    
    // create a bitmap from our pixel data
    wxBitmap bmp(wxImage(screen->w, screen->h, 
                    static_cast<unsigned char *>(screen->pixels), true));
    
    // unlock the screen
    if (SDL_MUSTLOCK(screen)) {
        SDL_UnlockSurface(screen);
    }
    
    // paint the screen
    wxBufferedPaintDC dc(this, bmp);
}

void SDLPanel::onIdle(wxIdleEvent &) {
    // create the SDL_Surface
    createScreen();
    
    // Lock surface if needed
    /*
    if (SDL_MUSTLOCK(screen)) {
        if (SDL_LockSurface(screen) < 0) {
            return;
        }
    }
    */
    
    /*
    // Ask SDL for the time in milliseconds
    int tick = SDL_GetTicks();
    
    for (int y = 0; y < 480; y++) {
        for (int x = 0; x < 640; x++) {
            wxUint32 color = (y * y) + (x * x) + tick;
            wxUint8 *pixels = static_cast<wxUint8 *>(screen->pixels) + 
                              (y * screen->pitch) +
                              (x * screen->format->BytesPerPixel);

            #if SDL_BYTEORDER == SDL_BIG_ENDIAN
                pixels[0] = color & 0xFF;
                pixels[1] = (color >> 8) & 0xFF;
                pixels[2] = (color >> 16) & 0xFF;
            #else
                pixels[0] = (color >> 16) & 0xFF;
                pixels[1] = (color >> 8) & 0xFF;
                pixels[2] = color & 0xFF;
            #endif
        }
    }
    */
    
    // Unlock if needed
    /*
    if (SDL_MUSTLOCK(screen)) {
        SDL_UnlockSurface(screen);
    }
    */
    m_pEngineApp->WxClient_GameLoop();

    // refresh the panel
    Refresh(false);
    
    // throttle to keep from flooding the event queue
    wxMilliSleep(33);
}

void SDLPanel::createScreen() {
    if (screen == NULL) {
        /*
        int width, height;
        GetSize(&width, &height);
        
        screen = SDL_CreateRGBSurface(SDL_SWSURFACE, width, height, 
                                      24, 0, 0, 0, 0);     
                                      */
        screen = m_pEngineApp->GetWxDrawScreen();
        m_pEngineApp->WxClient_InitGame();
    }
}

/*******************************************************************************
// SDLFrame Class
*******************************************************************************/

class SDLFrame : public wxFrame {
    DECLARE_CLASS(SDLFrame)
    DECLARE_EVENT_TABLE()
    
private:
    SDLPanel *panel;
    
    /**
     * Called when exit from the file menu is selected.
     *
     * @param event The associated wxCommandEvent (unused).
     */
    void onFileExit(wxCommandEvent &event);
    
    /**
     * Called when about from the help menu is selected.
     *
     * @param event The associated wxCommandEvent (unused).
     */
    void onHelpAbout(wxCommandEvent &event);
    
public:
     cEngineApp*  m_pEngineApp;

    /**
     * Creates a new SDLFrame.
     */
    SDLFrame();
    
    /**
     * Gets the SDLPanel within this SDLFrame.
     *
     * @return The SDLPanel.
     */
    SDLPanel &getPanel();
};

inline void SDLFrame::onFileExit(wxCommandEvent &) { Close(); }
inline SDLPanel &SDLFrame::getPanel() { return *panel; }

IMPLEMENT_CLASS(SDLFrame, wxFrame)

BEGIN_EVENT_TABLE(SDLFrame, wxFrame)
    EVT_MENU(IDM_FILE_EXIT, SDLFrame::onFileExit)
    EVT_MENU(IDM_HELP_ABOUT, SDLFrame::onHelpAbout)
END_EVENT_TABLE()

SDLFrame::SDLFrame() {
    // Create the SDLFrame
    Create(NULL, ID_FRAME, wxT("Frame Title"), wxDefaultPosition,
           wxDefaultSize, wxCAPTION | wxSYSTEM_MENU | 
           wxMINIMIZE_BOX | wxCLOSE_BOX);

    // create the main menubar
    wxMenuBar *mb = new wxMenuBar;
    
    // create the file menu
    wxMenu *fileMenu = new wxMenu;
    fileMenu->Append(IDM_FILE_EXIT, wxT("E&xit"));
    
    // add the file menu to the menu bar
    mb->Append(fileMenu, wxT("&File"));
    
    // create the help menu
    wxMenu *helpMenu = new wxMenu;
    helpMenu->Append(IDM_HELP_ABOUT, wxT("About"));
    
    // add the help menu to the menu bar
    mb->Append(helpMenu, wxT("&Help"));
    
    // add the menu bar to the SDLFrame
    SetMenuBar(mb);
    
    // create the SDLPanel
    panel = new SDLPanel(this);
}

void SDLFrame::onHelpAbout(wxCommandEvent &) {
    wxMessageBox(wxT("wx-sdl tutorial\nCopyright (C) 2005 John Ratliff"),
                 wxT("about wx-sdl tutorial"), wxOK | wxICON_INFORMATION);
}

/*******************************************************************************
// SDLApp Class
*******************************************************************************/

class SDLApp : public wxApp {
    DECLARE_CLASS(SDLApp)
    
private:
    SDLFrame *frame;
    cEngineApp*  m_pEngineApp;
    int m_iSize_W;
    int m_iSize_H;
    
public:
    /**
     * Called to initialize this SDLApp.
     *
     * @return true if initialization succeeded; false otherwise.
     */
    bool OnInit();
    
    /**
     * Called to run this SDLApp.
     *
     * @return The status code (0 if good, non-0 if bad).
     */
    int OnRun();
    
    /**
     * Called when this SDLApp is ready to exit.
     *
     * @return The exit code.
     */
    int OnExit();
};

bool SDLApp::OnInit() {
    // create the SDLFrame
    m_iSize_W = 800;
    m_iSize_H = 600;
    frame = new SDLFrame;
    frame->SetClientSize(m_iSize_W, m_iSize_H);
    frame->Centre();
    frame->Show();

    m_pEngineApp = new cEngineApp;
    frame->m_pEngineApp = m_pEngineApp;
    frame->getPanel().m_pEngineApp = m_pEngineApp;
    
    // Our SDLFrame is the Top Window
    SetTopWindow(frame);

    // initialization should always succeed
    return true;
}

int SDLApp::OnRun() {
    /*
    // initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "unable to init SDL: " << SDL_GetError() << '\n';
        
        return -1;
    }
    
    // Setup video mode, but don't create a window
    SDL_SetVideoMode(0, 0, 0, SDL_SWSURFACE);
    */
    
    m_pEngineApp->SetWxClientFlag(TRUE);
    m_pEngineApp->Init();
    
    // generate an initial idle event to start things
    wxIdleEvent event;
    event.SetEventObject(&frame->getPanel());
    frame->getPanel().AddPendingEvent(event);

    // start the main loop
    return wxApp::OnRun();
}

int SDLApp::OnExit() {
    // cleanup SDL
    SDL_Quit();

    delete m_pEngineApp;
    
    // return the standard exit code
    return wxApp::OnExit();
}

IMPLEMENT_CLASS(SDLApp, wxApp)
IMPLEMENT_APP(SDLApp)

