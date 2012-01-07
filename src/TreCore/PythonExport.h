/*
    Tressette
    Copyright (C) 2005  Igor Sarzi Sartori

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public
    License along with this library; if not, write to the Free
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    Igor Sarzi Sartori
    www.invido.it
    6colpiunbucosolo@gmx.net
*/


//PythonExport.h

#ifndef __PYTHON_EXPORT_APP_H__
#define __PYTHON_EXPORT_APP_H__

class cCore;


extern cCore*  g_pCore;


//#ifndef NOPYTHON


//! export symbol table to python engine
void InitExport();
//! call callback defined in script
void NotifyCustomControlEvent(int iEvent);
//! python session is terminated
void ExportFinalize();

//#else
// no python, no definitions
//#endif


#endif
