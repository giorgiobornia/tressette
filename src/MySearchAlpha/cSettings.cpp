
// cSettings.cpp
// implementation of  settings 
// Automatic generated header file by xml->xslt = header
  


#include "StdAfx.h"
#include "win_type_global.h"
#include "cSettings.h"



  


 

using namespace SpaceSearchSettings;

    
// global options object
SearchSettings  g_Options;
    

static const char* lpszSubAll = "SubAll";
    
        
    
static const char* lpszSubAllinizia = "SubAllinizia";
    
static const char* lpszSubAllhistory = "SubAllhistory";
    
static const char* lpszSubNord = "SubNord";
    
        
    
static const char* lpszSubNordbastoni = "SubNordbastoni";
    
static const char* lpszSubNordcoppe = "SubNordcoppe";
    
static const char* lpszSubNorddenari = "SubNorddenari";
    
static const char* lpszSubNordspade = "SubNordspade";
    
static const char* lpszSubEst = "SubEst";
    
        
    
static const char* lpszSubEstbastoni = "SubEstbastoni";
    
static const char* lpszSubEstcoppe = "SubEstcoppe";
    
static const char* lpszSubEstdenari = "SubEstdenari";
    
static const char* lpszSubEstspade = "SubEstspade";
    
static const char* lpszSubSud = "SubSud";
    
        
    
static const char* lpszSubSudbastoni = "SubSudbastoni";
    
static const char* lpszSubSudcoppe = "SubSudcoppe";
    
static const char* lpszSubSuddenari = "SubSuddenari";
    
static const char* lpszSubSudspade = "SubSudspade";
    
static const char* lpszSubWest = "SubWest";
    
        
    
static const char* lpszSubWestbastoni = "SubWestbastoni";
    
static const char* lpszSubWestcoppe = "SubWestcoppe";
    
static const char* lpszSubWestdenari = "SubWestdenari";
    
static const char* lpszSubWestspade = "SubWestspade";
    
    

//! constructor
SearchSettings::SearchSettings()
{

}


SearchSettings::SubAll::SubAll()
{
        
        
    inizia = "est";
    history = "";
    
}

SearchSettings::SubNord::SubNord()
{
        
        
    bastoni = "27";
    coppe = "3C5";
    denari = "RF";
    spade = "7C4";
    
}

SearchSettings::SubEst::SubEst()
{
        
        
    bastoni = "RF4";
    coppe = "A6";
    denari = "3265";
    spade = "R";
    
}

SearchSettings::SubSud::SubSud()
{
        
        
    bastoni = "A3C6";
    coppe = "2F4";
    denari = "A";
    spade = "A5";
    
}

SearchSettings::SubWest::SubWest()
{
        
        
    bastoni = "5";
    coppe = "R7";
    denari = "C74";
    spade = "32F6";
    
}




void SpaceSearchSettings::WriteProfile(const char* strIniFileName)
{
   char buff[2048];
	buff[0] = '\0';
   
  
    WritePrivateProfileString(lpszSubAll, lpszSubAllinizia, g_Options.All.inizia.c_str(),strIniFileName);
    
    WritePrivateProfileString(lpszSubAll, lpszSubAllhistory, g_Options.All.history.c_str(),strIniFileName);
    
    WritePrivateProfileString(lpszSubNord, lpszSubNordbastoni, g_Options.nord.bastoni.c_str(),strIniFileName);
    
    WritePrivateProfileString(lpszSubNord, lpszSubNordcoppe, g_Options.nord.coppe.c_str(),strIniFileName);
    
    WritePrivateProfileString(lpszSubNord, lpszSubNorddenari, g_Options.nord.denari.c_str(),strIniFileName);
    
    WritePrivateProfileString(lpszSubNord, lpszSubNordspade, g_Options.nord.spade.c_str(),strIniFileName);
    
    WritePrivateProfileString(lpszSubEst, lpszSubEstbastoni, g_Options.est.bastoni.c_str(),strIniFileName);
    
    WritePrivateProfileString(lpszSubEst, lpszSubEstcoppe, g_Options.est.coppe.c_str(),strIniFileName);
    
    WritePrivateProfileString(lpszSubEst, lpszSubEstdenari, g_Options.est.denari.c_str(),strIniFileName);
    
    WritePrivateProfileString(lpszSubEst, lpszSubEstspade, g_Options.est.spade.c_str(),strIniFileName);
    
    WritePrivateProfileString(lpszSubSud, lpszSubSudbastoni, g_Options.sud.bastoni.c_str(),strIniFileName);
    
    WritePrivateProfileString(lpszSubSud, lpszSubSudcoppe, g_Options.sud.coppe.c_str(),strIniFileName);
    
    WritePrivateProfileString(lpszSubSud, lpszSubSuddenari, g_Options.sud.denari.c_str(),strIniFileName);
    
    WritePrivateProfileString(lpszSubSud, lpszSubSudspade, g_Options.sud.spade.c_str(),strIniFileName);
    
    WritePrivateProfileString(lpszSubWest, lpszSubWestbastoni, g_Options.west.bastoni.c_str(),strIniFileName);
    
    WritePrivateProfileString(lpszSubWest, lpszSubWestcoppe, g_Options.west.coppe.c_str(),strIniFileName);
    
    WritePrivateProfileString(lpszSubWest, lpszSubWestdenari, g_Options.west.denari.c_str(),strIniFileName);
    
    WritePrivateProfileString(lpszSubWest, lpszSubWestspade, g_Options.west.spade.c_str(),strIniFileName);
    
    
  
}

void SpaceSearchSettings::GetProfile(const char* strIniFileName)
{
  char buff[2048];
  
    GetPrivateProfileString(lpszSubAll, lpszSubAllinizia, "est",buff, 2048,strIniFileName);
    g_Options.All.inizia = buff;
    
    GetPrivateProfileString(lpszSubAll, lpszSubAllhistory, "",buff, 2048,strIniFileName);
    g_Options.All.history = buff;
    
    GetPrivateProfileString(lpszSubNord, lpszSubNordbastoni, "27",buff, 2048,strIniFileName);
    g_Options.nord.bastoni = buff;
    
    GetPrivateProfileString(lpszSubNord, lpszSubNordcoppe, "3C5",buff, 2048,strIniFileName);
    g_Options.nord.coppe = buff;
    
    GetPrivateProfileString(lpszSubNord, lpszSubNorddenari, "RF",buff, 2048,strIniFileName);
    g_Options.nord.denari = buff;
    
    GetPrivateProfileString(lpszSubNord, lpszSubNordspade, "7C4",buff, 2048,strIniFileName);
    g_Options.nord.spade = buff;
    
    GetPrivateProfileString(lpszSubEst, lpszSubEstbastoni, "RF4",buff, 2048,strIniFileName);
    g_Options.est.bastoni = buff;
    
    GetPrivateProfileString(lpszSubEst, lpszSubEstcoppe, "A6",buff, 2048,strIniFileName);
    g_Options.est.coppe = buff;
    
    GetPrivateProfileString(lpszSubEst, lpszSubEstdenari, "3265",buff, 2048,strIniFileName);
    g_Options.est.denari = buff;
    
    GetPrivateProfileString(lpszSubEst, lpszSubEstspade, "R",buff, 2048,strIniFileName);
    g_Options.est.spade = buff;
    
    GetPrivateProfileString(lpszSubSud, lpszSubSudbastoni, "A3C6",buff, 2048,strIniFileName);
    g_Options.sud.bastoni = buff;
    
    GetPrivateProfileString(lpszSubSud, lpszSubSudcoppe, "2F4",buff, 2048,strIniFileName);
    g_Options.sud.coppe = buff;
    
    GetPrivateProfileString(lpszSubSud, lpszSubSuddenari, "A",buff, 2048,strIniFileName);
    g_Options.sud.denari = buff;
    
    GetPrivateProfileString(lpszSubSud, lpszSubSudspade, "A5",buff, 2048,strIniFileName);
    g_Options.sud.spade = buff;
    
    GetPrivateProfileString(lpszSubWest, lpszSubWestbastoni, "5",buff, 2048,strIniFileName);
    g_Options.west.bastoni = buff;
    
    GetPrivateProfileString(lpszSubWest, lpszSubWestcoppe, "R7",buff, 2048,strIniFileName);
    g_Options.west.coppe = buff;
    
    GetPrivateProfileString(lpszSubWest, lpszSubWestdenari, "C74",buff, 2048,strIniFileName);
    g_Options.west.denari = buff;
    
    GetPrivateProfileString(lpszSubWest, lpszSubWestspade, "32F6",buff, 2048,strIniFileName);
    g_Options.west.spade = buff;
    
}
