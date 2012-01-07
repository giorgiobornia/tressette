// tracestl.h


#ifndef _TRACER_STL__H
#define _TRACER_STL__H

#include <fstream>
#include <iostream>
#include <sstream>

// trace the container in the debug window
template <class T> inline
VOID TraceContainer( T &myContainer, const std::string &strComment )
{
    T::const_iterator Icontainer;
   
    std::ostringstream out;
    std::string w;

    out << strComment << std::endl;

    Icontainer = myContainer.begin();
    while (Icontainer != myContainer.end())
    {
        out << *Icontainer << std::endl;
        Icontainer++;
    }

    w = out.str();
    ::OutputDebugString(w.c_str());
}//end TraceContainer


#endif