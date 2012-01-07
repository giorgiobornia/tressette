
// cSettings.h 
// used to handle settings 
// Automatic generated header file by xml->xslt = header

#ifndef   __SETTINGS_INI_H_
#define   __SETTINGS_INI_H_  
 



#include <string>



namespace SpaceSearchSettings
{

//! class SearchSettings
class SearchSettings
{
public:
    
    SearchSettings();
    
    
    class SubAll
    {
        public:
            SubAll();
              
            //! Player that begin
            std::string inizia;
              
            //! Hand history
            std::string history;
              
    };
    
    
    
public:
    SubAll All;

    class SubNord
    {
        public:
            SubNord();
              
            //! Bastoni hand
            std::string bastoni;
              
            //! coppe hand
            std::string coppe;
              
            //! denari hand
            std::string denari;
              
            //! spade hand
            std::string spade;
              
    };
    
    
    
public:
    SubNord nord;

    class SubEst
    {
        public:
            SubEst();
              
            //! Bastoni hand
            std::string bastoni;
              
            //! coppe hand
            std::string coppe;
              
            //! denari hand
            std::string denari;
              
            //! spade hand
            std::string spade;
              
    };
    
    
    
public:
    SubEst est;

    class SubSud
    {
        public:
            SubSud();
              
            //! Bastoni hand
            std::string bastoni;
              
            //! coppe hand
            std::string coppe;
              
            //! denari hand
            std::string denari;
              
            //! spade hand
            std::string spade;
              
    };
    
    
    
public:
    SubSud sud;

    class SubWest
    {
        public:
            SubWest();
              
            //! Bastoni hand
            std::string bastoni;
              
            //! coppe hand
            std::string coppe;
              
            //! denari hand
            std::string denari;
              
            //! spade hand
            std::string spade;
              
    };
    
    
    
public:
    SubWest west;


};



    //! write settings in the registry
    void    WriteProfile(const char* strIniFileName);
    //! retrieves setting from the registry
    void    GetProfile(const char* strIniFileName);
    
    
};//end namespace

extern SpaceSearchSettings::SearchSettings g_Options;

#endif
