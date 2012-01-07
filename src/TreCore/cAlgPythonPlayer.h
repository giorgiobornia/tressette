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



// cAlgPythonPlayer.h: interface for the cAlgPythonPlayer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALGPYTHONPLAYER_H__AFC3BF94_6748_4C5C_AB8F_5A75A6B59A4A__INCLUDED_)
#define AFX_CALGPYTHONPLAYER_H__AFC3BF94_6748_4C5C_AB8F_5A75A6B59A4A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AlgPlayerInterface.h"
#include "CoreEnv.h"
#include "CardSpec.h"

class cAlgPythonPlayer : public I_ALG_Player  
{
public:
	cAlgPythonPlayer();
	virtual ~cAlgPythonPlayer();

// interface I_ALG_Player
    virtual void ALG_SetCoreInterface(I_CORE_Game* pCore);
    //! set player index
    virtual void ALG_SetPlayerIndex(int iIndex) ;
    //! set opponent index
    virtual void ALG_SetOpponentIndex(int iIndex, int iOpponentNr) ;
    //! set associate index
    virtual void ALG_SetAssociateIndex(int iIndex) ;
    //! new match notification
    virtual void ALG_NewMatch(int iNumPlayer) ;
    //! new giocata notification
    virtual void ALG_NewGiocata(CARDINFO* pCardArray, int iNumOfCards, int iPlayerIx) ;
    //! player has played a card
    virtual void ALG_PlayerHasPlayed(int iPlayerIx, CARDINFO* pCard) ;
    //! player has said something
    virtual void ALG_PlayerHasSaid(int iPlayerIx, eSayPlayer eSay) ;
    //! player have to play notification
    virtual void ALG_Play() ;
    //! mano end notification
    virtual void ALG_ManoEnd(I_MatchScore* pScore) ;
    //! giocata end notification
    virtual void ALG_GiocataEnd(I_MatchScore* pScore) ;
    //! match end notification
    virtual void ALG_MatchEnd(I_MatchScore* pScore) ;
    //! player say
    virtual void ALG_Say();
    //! giocata score changed
    virtual void ALG_GicataScoreChange(eGiocataScoreState eNewScore);
    //! player said somithing false
    virtual void ALG_PLayerSaidFalse(int iPlayerIx);
    //! player has declared a good game
    virtual void ALG_PLayerDeclareGoodGame(int iPlayerIx, eDeclGoodGame eValgg,  eSUIT eValsuit);


private:
    //! cards hold on algorithm
    CardSpec             m_vct_Cards_CPU[NUM_CARDS_HAND];
    //! card played from opponent
    CardSpec             m_CardPlayed;
    //! current giocata score
    eGiocataScoreState   m_eScoreCurrent;
    //! core invido pointer
    I_CORE_Game*         m_pCoreGame;
    //! player index 
    int                  m_iMyIndex;
    //! opponent index
    int                  m_iOppIndex;
    //! opponent word
    eSayPlayer           m_OpponentSay;

};

#endif // !defined(AFX_CALGPYTHONPLAYER_H__AFC3BF94_6748_4C5C_AB8F_5A75A6B59A4A__INCLUDED_)
