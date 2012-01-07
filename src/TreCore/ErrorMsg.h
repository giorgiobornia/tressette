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

// ErrorMsg.h

#ifndef ERROR_MSG__H_____
#define ERROR_MSG__H_____

//! namespace Error
namespace Error
{
    enum
    {
        BUFDIM = 512
    };
    struct Init
    {
        STRING strErrMsg;
        //! constructor
        Init(LPCSTR lpsMsg){strErrMsg = lpsMsg;}
    };
    struct Generic
    {
        STRING strErrMsg;
        //! constructor
        Generic(LPCSTR lpsMsg){strErrMsg = lpsMsg;}
    };
};


#endif
