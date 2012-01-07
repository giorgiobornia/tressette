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

//cTipoDiMazzo.cpp
#include "StdAfx.h"
#include "cTipoDiMazzo.h"
#include "lang_gen.h"


////////////////////////////////////////
//       GetCurrMazzoName
/*! 
*/
STRING  cTipoDiMazzo::GetCurrMazzoName()
{
    m_strMazzoName = getMazzoName(m_eType);
    return m_strMazzoName;
}


////////////////////////////////////////
//       GetMazzoNameOnType
/*! 
// \param eTypeMazzo eType : 
*/
STRING  cTipoDiMazzo::GetMazzoNameOnType(eTypeMazzo eType)
{
    STRING strMazzo = getMazzoName(eType);
    return strMazzo;
}


////////////////////////////////////////
//       getMazzoName
/*! 
// \param eTypeMazzo eType : 
*/
STRING cTipoDiMazzo::getMazzoName(eTypeMazzo eType)
{
    STRING strName;
    cLanguages* pLan = cLanguages::Instance();

    switch(eType)
    {
    case PIACENTINA:
        strName = pLan->GetCStringId(cLanguages::ID_PIACENTINA ) ;
        break;
    case BERGAMO:
        strName = pLan->GetCStringId(cLanguages::ID_BERGAMO ) ;
        break;
    case BOLOGNA:
        strName = pLan->GetCStringId(cLanguages::ID_BOLOGNA ) ;
        break;
    case GENOVA:
        strName = pLan->GetCStringId(cLanguages::ID_GENOVA ) ;
        break;
    case MILANO:
        strName = pLan->GetCStringId(cLanguages::ID_MILANO ) ;
        break;
    case NAPOLI:
        strName = pLan->GetCStringId(cLanguages::ID_NAPOLI ) ;
        break;
    case PIEMONTE:
        strName = pLan->GetCStringId(cLanguages::ID_PIEMONTE ) ;
        break;
    case ROMAGNA:
        strName = pLan->GetCStringId(cLanguages::ID_ROMAGNA ) ;
        break;
    case SARDEGNA:
       strName = pLan->GetCStringId(cLanguages::ID_SARDEGNA ) ;
        break;
    case SICILIA:
        strName = pLan->GetCStringId(cLanguages::ID_SICILIA) ;
        break;
    case TOSCANA:
        strName = pLan->GetCStringId(cLanguages::ID_TOSCANA ) ;
        break;
    case TRENTO:
       strName = pLan->GetCStringId(cLanguages::ID_TRENTO ) ;
        break;
    case TREVISO:
       strName = pLan->GetCStringId(cLanguages::ID_TREVISO ) ;
        break;
        /*
    case TRIESTE:
        strName = pLan->GetCStringId(cLanguages::ID_TRIESTE ) ;
        break;
        */
    default:
        assert(0);
    }

    return strName;
}

////////////////////////////////////////
//       SetType
/*! Set type of the new deck
*/
void cTipoDiMazzo::SetType(eTypeMazzo eType)
{
    m_eType = eType;
    switch(eType)
    {
    case PIACENTINA:
        m_strResFileName = "mazzo_piac.pac";
        m_strSymbolName = "symb_336.bmp";
        break;
    case BERGAMO:
        m_strResFileName = "bergamo_cards.pac";
        m_strSymbolName = "symb_320.bmp";
        break;
    case BOLOGNA:
        m_strResFileName = "bologna_cards.pac";
        m_strSymbolName = "symb_320.bmp";
        break;
    case GENOVA:
        m_strResFileName = "genova_cards.pac";
        m_strSymbolName = "symb_368.bmp";
        break;
    case MILANO:
        m_strResFileName = "milano_cards.pac";
        m_strSymbolName = "symb_320.bmp";
        break;
    case NAPOLI:
        m_strResFileName = "napoli_cards.pac";
        m_strSymbolName = "symb_368.bmp";
        break;
    case PIEMONTE:
        m_strResFileName = "piemonte_cards.pac";
        m_strSymbolName = "symb_368.bmp";
        break;
    case ROMAGNA:
        m_strResFileName = "romagna_cards.pac";
        m_strSymbolName = "symb_336.bmp";
        break;
    case SARDEGNA:
        m_strResFileName = "sardegna_cards.pac";
        m_strSymbolName = "symb_368.bmp";
        break;
    case SICILIA:
        m_strResFileName = "sicilia_cards.pac";
        m_strSymbolName = "symb_368.bmp";
        break;
    case TOSCANA:
        m_strResFileName = "toscana_cards.pac";
        m_strSymbolName = "symb_368.bmp";
        break;
    case TRENTO:
        m_strResFileName = "trento_cards.pac";
        m_strSymbolName = "symb_336.bmp";
        break;
    case TREVISO:
        m_strResFileName = "carte_trevisane.pac";
        m_strSymbolName = "symb_320.bmp";
        break;
        /*
    case TRIESTE:
        m_strResFileName = "trieste_cards.pac";
        m_strSymbolName = "symb_320.bmp";
        break;
        */
    default:
        assert(0);

    }
}


////////////////////////////////////////
//       Clone
/*! 
// \param cTipoDiMazzo &Val : 
*/
void cTipoDiMazzo::Clone(cTipoDiMazzo &Val)
{
    m_eType = Val.GetType();
    m_strMazzoName = Val.GetCurrMazzoName() ;
    m_strResFileName = Val.GetResFileName() ;
    m_strSymbolName = Val.GetSymbolFileName() ;
}


