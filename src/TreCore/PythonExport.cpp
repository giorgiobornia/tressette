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


// PythonExport.cpp
#include "StdAfx.h"
#include "win_type_global.h"

#ifdef NOPYTHON

    // python is not used on compile time

    // dummy notification
    void NotifyCustomControlEvent(int iEvent){}

#else

//use python script engine
#include "PythonExport.h"
#include <string>
#include "cSettings.h"

#include <fcntl.h>
#include <fstream>

#include <Python.h>
#include "resource.h"

#include "cCoreEngine.h"
#include "CoreEnv.h"

// script callback
static PyObject* g_Script_callback = NULL;

// python control callback
static PyObject* g_PytCtrl_callback = NULL;




////////////////////////////////////////
//       Tre_CheckVersion
/*! 
// \param PyObject *self : 
// \param PyObject *args : 
*/
static PyObject* Tre_CheckVersion(PyObject *self, PyObject *args)
{
    if(!PyArg_ParseTuple(args, ":CheckVersion"))
        return NULL;
    std::string strTmp;
    std::string strVer;

    strVer = "0.5"; 

    return Py_BuildValue("s", strVer.c_str());
}


////////////////////////////////////////
//       Tre_checkDeck
/*! 
// \param PyObject *self : 
// \param PyObject *args : 
*/
static PyObject* Tre_checkDeck(PyObject *self, PyObject *args)
{
    PyObject *result = NULL;
    ASSERT(g_pCore);
    if (g_pCore)
    {
        g_pCore->Script_CheckDeck(); 
    }

    Py_INCREF(Py_None);
    result = Py_None;
    
    return result;
}



////////////////////////////////////////
//       Tre_set_callbackCtrl
/*! Set Callback function called from TreCore
// \param PyObject *dummy : 
// \param PyObject *args : 
*/
static PyObject* Tre_set_callbackCtrl(PyObject *dummy, PyObject *args)
{
    PyObject *result = NULL;
    PyObject *temp;

    if (PyArg_ParseTuple(args, "O:set_callbackCtrl", &temp)) 
    {
        if (!PyCallable_Check(temp)) 
        {
            PyErr_SetString(PyExc_TypeError, "parameter must be callable");
            return NULL;
        }
        Py_XINCREF(temp);         /* Add a reference to new callback */
        Py_XDECREF(g_PytCtrl_callback);  /* Dispose of previous callback */
        g_PytCtrl_callback = temp;       /* Remember new callback */
        /* Boilerplate to return "None" */
        Py_INCREF(Py_None);
        result = Py_None;
    }
    return result;
}


////////////////////////////////////////
//       Tre_setPlayerDeck
/*! Override player deck 
// \param PyObject *dummy : 
// \param PyObject *args : 
*/
static PyObject* Tre_setPlayerDeck(PyObject *dummy, PyObject *args)
{
    PyObject *result = NULL;
    int iPlayerIx;
    
    int vctCardPlayer[NUM_CARDS_HAND];
    if (PyArg_ParseTuple(args, "iiiiiiiiiii", &iPlayerIx, &vctCardPlayer[0], &vctCardPlayer[1], &vctCardPlayer[2],
              &vctCardPlayer[3], &vctCardPlayer[4], &vctCardPlayer[5], &vctCardPlayer[6], 
              &vctCardPlayer[7], &vctCardPlayer[8], &vctCardPlayer[9] )) 
    {
        ASSERT(g_pCore);
        
        
        if (g_pCore)
        {
            g_pCore->Script_OverrideDeck(iPlayerIx, vctCardPlayer); 
        }

        Py_INCREF(Py_None);
        result = Py_None;
    }
    return result;
}



////////////////////////////////////////
//       Tre_startPlayer
/*! 
// \param PyObject *dummy : 
// \param PyObject *args : 
*/
static PyObject* Tre_startPlayer(PyObject *dummy, PyObject *args)
{
    PyObject *result = NULL;
    int iPlayerIx;
    
    if (PyArg_ParseTuple(args, "i", &iPlayerIx)) 
    {
        ASSERT(g_pCore);
        if (g_pCore)
        {
            g_pCore->Script_SetStartPlayer(iPlayerIx); 
        }

        Py_INCREF(Py_None);
        result = Py_None;
    }
    return result;
}

////////////////////////////////////////
//       Tre_Say
/*! Script say something
// \param PyObject *dummy : 
// \param PyObject *args : 
*/
static PyObject* Tre_Say(PyObject *dummy, PyObject *args)
{
    PyObject *result = NULL;
    int iPlayerIx;
    int iSay;
    
    if (PyArg_ParseTuple(args, "ii", &iPlayerIx, &iSay)) 
    {
        ASSERT(g_pCore);
        if (g_pCore)
        {
            g_pCore->Script_Say(iPlayerIx, (eSayPlayer)iSay); 
        }

        Py_INCREF(Py_None);
        result = Py_None;
    }
    return result;
}


////////////////////////////////////////
//       Tre_Play
/*! The algorith play something
// \param PyObject *dummy : 
// \param PyObject *args : 
*/
static PyObject* Tre_Play(PyObject *dummy, PyObject *args)
{
    PyObject *result = NULL;
    int iPlayerIx;
    int iCardIndex;
    
    if (PyArg_ParseTuple(args, "ii", &iPlayerIx, &iCardIndex)) 
    {
        ASSERT(g_pCore);
        if (g_pCore)
        {
            CardSpec Card;
            Card.SetCardIndex(iCardIndex); 
            g_pCore->Script_Play(iPlayerIx, Card); 
        }

        Py_INCREF(Py_None);
        result = Py_None;
    }
    return result;
}



// collection of exported functions
static PyMethodDef staPcsimEmbMethods[] = 
{
    {"CheckVersion", Tre_CheckVersion, METH_VARARGS,
     "Return the program version number."},
    {"set_callbackCtrl", Tre_set_callbackCtrl, METH_VARARGS,
    "Set the game loop callback."},
    {"setPlayerDeck", Tre_setPlayerDeck, METH_VARARGS,
    "Set the deck of a player."},
    {"Say", Tre_Say, METH_VARARGS,
    "Player say something."},
    {"Play", Tre_Play, METH_VARARGS,
    "Player play something."},
    {"checkDeck", Tre_checkDeck, METH_VARARGS,
    "Check if the deck is ok without duplicate."},
    {"startPlayer", Tre_startPlayer, METH_VARARGS,
    "Set the Start player."},
    {NULL, NULL, 0, NULL}
    
};



////////////////////////////////////////
//       InitExport
/*! Export the module
*/
void InitExport()
{
    // export the module and methods
    Py_InitModule("tre", staPcsimEmbMethods);
}




////////////////////////////////////////
//       NotifyCustomControlEvent
/*! Notify to python script a custom control event 
// \param int iEvent : event to be notified
*/
void NotifyCustomControlEvent(int iEvent)
{
    if (g_Options.All.bUsePythonNotification )
    {
        if (g_PytCtrl_callback)
        {
            int arg;
            PyObject *arglist;
            PyObject *result;
            arg = iEvent;
    
            arglist = Py_BuildValue("(i)", arg);
        
            result = PyEval_CallObject(g_PytCtrl_callback, arglist);
    
            Py_DECREF(arglist); 
        }
        else
        {
            std::cout << "*** ERR script not initialized or game-loop callback not set\n";
        }
    }
    else
    {
        std::cout << "*** ERR Python not active\n";
    }
}




////////////////////////////////////////
//       ExportFinalize
/*! Python session is ended
*/
void ExportFinalize()
{
    g_Script_callback = 0;
    g_PytCtrl_callback = 0;
}


#endif


