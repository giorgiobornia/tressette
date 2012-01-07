//file: Log.h
#ifndef __LOG_H_
#define __LOG_H_

#include "win_type_global.h"

#include <stdlib.h>
#include <stdio.h>




class Log 
{
public:

	static Log* Instance();

	void SetOutputFile(char* filename);

	void LogToScreen(bool enable);

	void LogToFile(bool enable);

	void Print(int level, const char* fmt, ...);

	void SetLevel(int level);
    //! trace data
    void TraceData(int level, const BYTE *pbyData, int nDataLen, char* pTextComment);
    
		
protected:
	
	Log();
	
	virtual ~Log();

private:

	static Log* _instance;

	bool log_to_file;

	bool log_to_screen;

	FILE* file;

	int level;
};

extern Log* debug;

#endif


