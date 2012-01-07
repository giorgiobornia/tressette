# Microsoft Developer Studio Project File - Name="TreClientVs6" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=TreClientVs6 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "TreClientVs6.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "TreClientVs6.mak" CFG="TreClientVs6 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "TreClientVs6 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "TreClientVs6 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "TreClientVs6 - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I ".\include" /I ".." /I "." /I "../TreCore" /I "./console" /I "../include" /I "../../include" /I "../MySearchAlpha" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "NOPYTHON" /FR /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc07 /d "NDEBUG"
# ADD RSC /l 0xc07 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib sdl.lib SDLmain.lib SDL_image.lib SDL_mixer.lib SDL_ttf.lib libexpat.lib /nologo /subsystem:windows /debug /machine:I386 /out:"../../out/tre.exe" /libpath:".\lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "TreClientVs6 - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I ".\include" /I ".." /I "." /I "../TreCore" /I "../include" /I "../../include" /I "../../python_2_3/include" /I "../MySearchAlpha" /I "../gfx_widgets" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "NOPYTHON" /FR /Yu"StdAfx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc07 /d "_DEBUG"
# ADD RSC /l 0xc07 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib sdl.lib SDLmain.lib SDL_image.lib SDL_mixer.lib SDL_ttf.lib libexpat.lib gfx_widgets_d.lib /nologo /subsystem:windows /debug /machine:I386 /out:"../../out/tre_d.exe" /pdbtype:sept /libpath:".\lib" /libpath:"..\..\lib" /libpath:"..\..\python_2_3\lib"

!ENDIF 

# Begin Target

# Name "TreClientVs6 - Win32 Release"
# Name "TreClientVs6 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "core"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\TreCore\AlgCompareFunct.h
# End Source File
# Begin Source File

SOURCE=..\TreCore\AlgPlayerInterface.h
# End Source File
# Begin Source File

SOURCE=..\TreCore\AlgSupport.cpp
# End Source File
# Begin Source File

SOURCE=..\TreCore\AlgSupport.h
# End Source File
# Begin Source File

SOURCE=..\TreCore\cAlgDefault.cpp
# End Source File
# Begin Source File

SOURCE=..\TreCore\cAlgDefault.h
# End Source File
# Begin Source File

SOURCE=..\TreCore\cAlgNetClientPlayer.cpp
# End Source File
# Begin Source File

SOURCE=..\TreCore\cAlgNetClientPlayer.h
# End Source File
# Begin Source File

SOURCE=..\TreCore\cAlgPlugin.cpp
# End Source File
# Begin Source File

SOURCE=..\TreCore\cAlgPlugin.h
# End Source File
# Begin Source File

SOURCE=..\TreCore\cAlgPythonPlayer.cpp
# End Source File
# Begin Source File

SOURCE=..\TreCore\cAlgPythonPlayer.h
# End Source File
# Begin Source File

SOURCE=..\TreCore\CardSpec.cpp
# End Source File
# Begin Source File

SOURCE=..\TreCore\CardSpec.h
# End Source File
# Begin Source File

SOURCE=..\TreCore\cCoreEngine.cpp
# End Source File
# Begin Source File

SOURCE=..\TreCore\cCoreEngine.h
# End Source File
# Begin Source File

SOURCE=..\TreCore\cGiocata.cpp
# End Source File
# Begin Source File

SOURCE=..\TreCore\cGiocata.h
# End Source File
# Begin Source File

SOURCE=..\TreCore\cMano.cpp
# End Source File
# Begin Source File

SOURCE=..\TreCore\cMano.h
# End Source File
# Begin Source File

SOURCE=..\TreCore\cMatchPoints.cpp
# End Source File
# Begin Source File

SOURCE=..\TreCore\cMatchPoints.h
# End Source File
# Begin Source File

SOURCE=..\TreCore\cMazzo.cpp
# End Source File
# Begin Source File

SOURCE=..\TreCore\cMazzo.h
# End Source File
# Begin Source File

SOURCE=..\TreCore\CoreEnv.h
# End Source File
# Begin Source File

SOURCE=..\TreCore\cPartita.cpp
# End Source File
# Begin Source File

SOURCE=..\TreCore\cPartita.h
# End Source File
# Begin Source File

SOURCE=..\TreCore\cPlayer.cpp
# End Source File
# Begin Source File

SOURCE=..\TreCore\cPlayer.h
# End Source File
# Begin Source File

SOURCE=..\TreCore\cPlayersOnTable.cpp
# End Source File
# Begin Source File

SOURCE=..\TreCore\cPlayersOnTable.h
# End Source File
# Begin Source File

SOURCE=..\TreCore\cPlayerStatistic.cpp
# End Source File
# Begin Source File

SOURCE=..\TreCore\cPlayerStatistic.h
# End Source File
# Begin Source File

SOURCE=..\TreCore\cProbality.cpp
# End Source File
# Begin Source File

SOURCE=..\TreCore\cProbality.h
# End Source File
# Begin Source File

SOURCE=..\TreCore\fuzzy.h
# End Source File
# Begin Source File

SOURCE=..\TreCore\InfoComm.h
# End Source File
# Begin Source File

SOURCE=..\TreCore\PythonExport.cpp
# End Source File
# Begin Source File

SOURCE=..\TreCore\PythonExport.h
# End Source File
# Begin Source File

SOURCE=..\TreCore\save_utility.h
# End Source File
# Begin Source File

SOURCE=..\TreCore\TraceService.cpp
# End Source File
# Begin Source File

SOURCE=..\TreCore\TraceService.h
# End Source File
# End Group
# Begin Group "gfx"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\cCardGfx.cpp
# End Source File
# Begin Source File

SOURCE=.\cCardGfx.h
# End Source File
# Begin Source File

SOURCE=.\EnterNameGfx.cpp
# End Source File
# Begin Source File

SOURCE=.\EnterNameGfx.h
# End Source File
# Begin Source File

SOURCE=.\OptionDeckGfx.cpp
# End Source File
# Begin Source File

SOURCE=.\OptionDeckGfx.h
# End Source File
# Begin Source File

SOURCE=.\OptionGameGfx.cpp
# End Source File
# Begin Source File

SOURCE=.\OptionGameGfx.h
# End Source File
# Begin Source File

SOURCE=.\OptionGfx.cpp
# End Source File
# Begin Source File

SOURCE=.\OptionGfx.h
# End Source File
# End Group
# Begin Group "alpha"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\MySearchAlpha\cAlgABSolver.cpp
# End Source File
# Begin Source File

SOURCE=..\MySearchAlpha\cAlgABSolver.h
# End Source File
# Begin Source File

SOURCE=..\MySearchAlpha\cCardItem.cpp
# End Source File
# Begin Source File

SOURCE=..\MySearchAlpha\cCardItem.h
# End Source File
# Begin Source File

SOURCE=..\MySearchAlpha\cHand.cpp
# End Source File
# Begin Source File

SOURCE=..\MySearchAlpha\cHand.h
# End Source File
# Begin Source File

SOURCE=..\MySearchAlpha\cStateAB.cpp
# End Source File
# Begin Source File

SOURCE=..\MySearchAlpha\cStateAB.h
# End Source File
# Begin Source File

SOURCE=..\MySearchAlpha\TrickHistory.cpp
# End Source File
# Begin Source File

SOURCE=..\MySearchAlpha\TrickHistory.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\cDelayNextAction.cpp
# End Source File
# Begin Source File

SOURCE=.\cDelayNextAction.h
# End Source File
# Begin Source File

SOURCE=.\cGameMainGfx.cpp
# End Source File
# Begin Source File

SOURCE=.\cGameMainGfx.h
# End Source File
# Begin Source File

SOURCE=.\cHightScoreMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\cHightScoreMgr.h
# End Source File
# Begin Source File

SOURCE=.\cMenuMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\cMenuMgr.h
# End Source File
# Begin Source File

SOURCE=.\cMusicManager.cpp
# End Source File
# Begin Source File

SOURCE=.\cMusicManager.h
# End Source File
# Begin Source File

SOURCE=.\credits.cpp
# End Source File
# Begin Source File

SOURCE=.\credits.h
# End Source File
# Begin Source File

SOURCE=.\cSettings.cpp
# End Source File
# Begin Source File

SOURCE=.\cSettings.h
# End Source File
# Begin Source File

SOURCE=.\cTipoDiMazzo.cpp
# End Source File
# Begin Source File

SOURCE=.\cTipoDiMazzo.h
# End Source File
# Begin Source File

SOURCE=.\EngineApp.cpp
# End Source File
# Begin Source File

SOURCE=.\EngineApp.h
# End Source File
# Begin Source File

SOURCE=.\fading.cpp
# End Source File
# Begin Source File

SOURCE=.\fading.h
# End Source File
# Begin Source File

SOURCE=.\FastDelegate.h
# End Source File
# Begin Source File

SOURCE=.\lang_gen.cpp
# End Source File
# Begin Source File

SOURCE=.\lang_gen.h
# End Source File
# Begin Source File

SOURCE=.\main.cpp
# End Source File
# Begin Source File

SOURCE=.\regkey.cpp
# End Source File
# Begin Source File

SOURCE=.\regkey.h
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "TreClientVs6 - Win32 Release"

!ELSEIF  "$(CFG)" == "TreClientVs6 - Win32 Debug"

# ADD CPP /Yc

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\tre.rc
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\TreCore\ErrorMsg.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\tre.ico
# End Source File
# End Group
# End Target
# End Project
