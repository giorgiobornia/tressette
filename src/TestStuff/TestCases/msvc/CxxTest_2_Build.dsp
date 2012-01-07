# Microsoft Developer Studio Project File - Name="CxxTest_2_Build" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=CxxTest_2_Build - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "CxxTest_2_Build.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "CxxTest_2_Build.mak" CFG="CxxTest_2_Build - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CxxTest_2_Build - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "CxxTest_2_Build - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "CxxTest_2_Build - Win32 Release"

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
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /I "..\.." /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x40d /d "NDEBUG"
# ADD RSC /l 0x40d /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386 /out:"Release/runner.exe"

!ELSEIF  "$(CFG)" == "CxxTest_2_Build - Win32 Debug"

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
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "..\.." /I "..\..\..\TreClientVs6" /I "..\..\..\..\include" /I "..\..\..\TreCore" /I "../MySearchAlpha" /I "..\..\..\MySearchAlpha" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "NOPYTHON" /FR /Yu"StdAfx.h" /FD /GZ /c
# ADD BASE RSC /l 0x40d /d "_DEBUG"
# ADD RSC /l 0x40d /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib sdl.lib SDLmain.lib SDL_image.lib SDL_mixer.lib SDL_ttf.lib libexpat.lib /nologo /subsystem:console /debug /machine:I386 /out:"..\..\..\..\out/runner.exe" /pdbtype:sept /libpath:"..\..\..\..\lib"

!ENDIF 

# Begin Target

# Name "CxxTest_2_Build - Win32 Release"
# Name "CxxTest_2_Build - Win32 Debug"
# Begin Group "application"

# PROP Default_Filter ""
# Begin Group "Core"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\TreCore\AlgCompareFunct.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\AlgPlayerInterface.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\AlgSupport.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\AlgSupport.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\cAlgDefault.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\cAlgDefault.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\cAlgNetClientPlayer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\cAlgNetClientPlayer.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\cAlgPlugin.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\cAlgPlugin.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\cAlgPythonPlayer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\cAlgPythonPlayer.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\CardSpec.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\CardSpec.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\cCoreEngine.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\cCoreEngine.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\cGiocata.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\cGiocata.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\cMano.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\cMano.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\cMatchPoints.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\cMatchPoints.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\cMazzo.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\cMazzo.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\CoreEnv.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\cPartita.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\cPartita.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\cPlayer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\cPlayer.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\cPlayersOnTable.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\cPlayersOnTable.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\cPlayerStatistic.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\cPlayerStatistic.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\cProbality.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\cProbality.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\ErrorMsg.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\fuzzy.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\InfoComm.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\PythonExport.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\PythonExport.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\save_utility.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\TraceService.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreCore\TraceService.h
# End Source File
# End Group
# Begin Group "gfx"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\TreClientVs6\cBalloonGfx.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\cBalloonGfx.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\cButtonGfx.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\cButtonGfx.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\cCardGfx.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\cCardGfx.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\cCheckBoxGfx.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\cCheckBoxGfx.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\cComboGfx.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\cComboGfx.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\cDelayNextAction.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\cDelayNextAction.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\cEditGfx.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\cEditGfx.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\cHightScoreMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\cHightScoreMgr.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\cLabelGfx.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\cLabelGfx.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\cLabelLinkGfx.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\cLabelLinkGfx.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\cMenuMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\cMenuMgr.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\cMesgBoxGfx.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\cMesgBoxGfx.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\cMusicManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\cMusicManager.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\cPopUpMenuGfx.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\cPopUpMenuGfx.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\cProgressBarGfx.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\cProgressBarGfx.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\credits.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\credits.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\cTipoDiMazzo.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\cTipoDiMazzo.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\EngineApp.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\EngineApp.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\EnterNameGfx.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\EnterNameGfx.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\fading.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\fading.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\gfx_util.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\gfx_util.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\OptionDeckGfx.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\OptionDeckGfx.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\OptionGameGfx.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\OptionGameGfx.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\OptionGfx.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\OptionGfx.h
# End Source File
# End Group
# Begin Group "alpha"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\MySearchAlpha\cAlgABSolver.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\MySearchAlpha\cAlgABSolver.h
# End Source File
# Begin Source File

SOURCE=..\..\..\MySearchAlpha\cCardItem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\MySearchAlpha\cCardItem.h
# End Source File
# Begin Source File

SOURCE=..\..\..\MySearchAlpha\cHand.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\MySearchAlpha\cHand.h
# End Source File
# Begin Source File

SOURCE=..\..\..\MySearchAlpha\cStateAB.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\MySearchAlpha\cStateAB.h
# End Source File
# Begin Source File

SOURCE=..\..\..\MySearchAlpha\TrickHistory.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\MySearchAlpha\TrickHistory.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\..\TreClientVs6\cGameMainGfx.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\cGameMainGfx.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\cSettings.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\cSettings.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\lang_gen.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\lang_gen.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\regkey.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\regkey.h
# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\StdAfx.cpp

!IF  "$(CFG)" == "CxxTest_2_Build - Win32 Release"

!ELSEIF  "$(CFG)" == "CxxTest_2_Build - Win32 Debug"

# ADD CPP /Yc

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\TreClientVs6\StdAfx.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=.\runner.cpp
# End Source File
# End Target
# End Project
