# Microsoft Developer Studio Project File - Name="gfx_widgets" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=gfx_widgets - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "gfx_widgets.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "gfx_widgets.mak" CFG="gfx_widgets - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "gfx_widgets - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "gfx_widgets - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "gfx_widgets - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD BASE RSC /l 0xc07 /d "NDEBUG"
# ADD RSC /l 0xc07 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "gfx_widgets - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ  /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I ".\include" /I ".." /I "." /I "../TreCore" /I "../include" /I "../../include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ  /c
# ADD BASE RSC /l 0xc07 /d "_DEBUG"
# ADD RSC /l 0xc07 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\..\lib\gfx_widgets_d.lib"

!ENDIF 

# Begin Target

# Name "gfx_widgets - Win32 Release"
# Name "gfx_widgets - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\cBalloonGfx.cpp
# End Source File
# Begin Source File

SOURCE=.\cButtonGfx.cpp
# End Source File
# Begin Source File

SOURCE=.\cCheckBoxGfx.cpp
# End Source File
# Begin Source File

SOURCE=.\cComboGfx.cpp
# End Source File
# Begin Source File

SOURCE=.\cEditGfx.cpp
# End Source File
# Begin Source File

SOURCE=.\cLabelGfx.cpp
# End Source File
# Begin Source File

SOURCE=.\cLabelLinkGfx.cpp
# End Source File
# Begin Source File

SOURCE=.\cMesgBoxGfx.cpp
# End Source File
# Begin Source File

SOURCE=.\cPopUpMenuGfx.cpp
# End Source File
# Begin Source File

SOURCE=.\cProgressBarGfx.cpp
# End Source File
# Begin Source File

SOURCE=.\gfx_util.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\cBalloonGfx.h
# End Source File
# Begin Source File

SOURCE=.\cButtonGfx.h
# End Source File
# Begin Source File

SOURCE=.\cCheckBoxGfx.h
# End Source File
# Begin Source File

SOURCE=.\cComboGfx.h
# End Source File
# Begin Source File

SOURCE=.\cEditGfx.h
# End Source File
# Begin Source File

SOURCE=.\cLabelGfx.h
# End Source File
# Begin Source File

SOURCE=.\cLabelLinkGfx.h
# End Source File
# Begin Source File

SOURCE=.\cMesgBoxGfx.h
# End Source File
# Begin Source File

SOURCE=.\cPopUpMenuGfx.h
# End Source File
# Begin Source File

SOURCE=.\cProgressBarGfx.h
# End Source File
# Begin Source File

SOURCE=.\FastDelegate.h
# End Source File
# Begin Source File

SOURCE=.\gfx_util.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# End Target
# End Project
