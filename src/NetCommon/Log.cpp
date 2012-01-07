// Log.cpp

#include "win_type_global.h"
#include "Log.h"
#include <stdarg.h>

Log* Log::_instance = NULL;

Log* debug = Log::Instance();

Log::Log()
{
	this->file = NULL;
	this->log_to_screen = true;
	this->log_to_file 	= false;
	this->level = 0;
}

Log::~Log() {
	if (this->file) fclose(this->file);
}

Log* Log::Instance() {
	if (_instance == NULL) 
		_instance = new Log();
	return _instance;
}

void Log::SetOutputFile(char* filename) {
	
	this->file = fopen(filename, "w");

	if (this->file == NULL) {
		log_to_file = false;	
	} else {
		log_to_file = true;
	}
}

void Log::LogToScreen(bool enable) {
	this->log_to_screen =  enable;
}

void Log::LogToFile(bool enable) {
	this->log_to_file = enable;
}

void Log::Print(int level, const char* fmt, ...) {
	
	static char text[100000];

	if (this->level >= level) {
		
		va_list marker;
		va_start(marker, fmt);										
		vsprintf(text, fmt, marker);						
		va_end(marker);	

		if (log_to_screen) { 
#ifndef USEDIALOGTRACE
			fprintf(stdout, "%s", text);
			fflush(stdout);
#else
            std::cout << text << std::endl;
#endif
		}
	
		if (log_to_file) {
			fprintf(this->file, "%s", text);
			fflush(this->file);
		}
		
	}	
}

void Log::SetLevel(int level) {
	this->level = level;
}



////////////////////////////////////////
//       TraceData
/*! 
// \param const BYTE *pbyData : 
// \param int nDataLen : 
// \param char* pTextComment : 
*/
void Log::TraceData(int level, const BYTE *pbyData, int nDataLen, char* pTextComment)
{
    Print(level, pTextComment);
    Print(level," :\n");
    char buff[64];

    for (int i =0; i < nDataLen; i++)
    {

        sprintf(buff, "0x%02X ", (int)pbyData[i]);
        Print(level,buff);
    }
    Print(level,"\n");
}