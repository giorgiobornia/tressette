// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__C0F7C4A2_35059CA33AE__INCLUDED_)
#define AFX_STDAFX_H__C0F7C4A2_35059CA33AE__INCLUDED_

#ifdef WIN32

#pragma warning(disable:4786)
#pragma warning(disable:4996)

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


//#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers
#define WIN32_LEAN_AND_MEAN
#include "win_type_global.h"

#include <windows.h>
#include <deque>
#include <string>
#include <assert.h>
#include <stdio.h>

#define APP_WIN_HEIGHT 480
#define APP_WIN_WIDTH 800

#define OPT_WIN_GAME_WIDTH	500
#define OPT_WIN_GAME_HEIGHT 390

#define OPT_WIN_DECK_WIDTH	500
#define OPT_WIN_DECK_HEIGHT 360

#define OPT_WIN_GENERAL_WIDTH	500
#define OPT_WIN_GENERAL_HEIGHT 420



#define DLL_EXPORTIMPORT   __declspec( dllimport )

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
#else


#include <deque>
#include <string>
#include <cstring>
#include <assert.h>
#include <stdio.h>

#define APP_WIN_HEIGHT 480
#define APP_WIN_WIDTH 800

#define OPT_WIN_GAME_WIDTH	500
#define OPT_WIN_GAME_HEIGHT 390

#define OPT_WIN_DECK_WIDTH	500
#define OPT_WIN_DECK_HEIGHT 360

#define OPT_WIN_GENERAL_WIDTH	500
#define OPT_WIN_GENERAL_HEIGHT 420


#endif // define WIN32



#endif // !defined(AFX_STDAFX_H__C0F7C4A2_35059CA33AE__INCLUDED_)
