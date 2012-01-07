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


// cAlgNetClientPlayer.cpp: implementation of the cAlgNetClientPlayer class.
//
//////////////////////////////////////////////////////////////////////
#include "StdAfx.h"
#include "cAlgNetClientPlayer.h"
#include "cCoreEngine.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

cAlgNetClientPlayer::cAlgNetClientPlayer()
{
    m_pCoreGame = 0;
    m_iOppIndex = NOT_VALID_INDEX;
}

cAlgNetClientPlayer::~cAlgNetClientPlayer()
{

}


////////////////////////////////////////
//       ALG_SetCoreInterface
/*! 
// \param I_CORE_Game* pCore : 
*/
void cAlgNetClientPlayer::ALG_SetCoreInterface(I_CORE_Game* pCore)
{
    m_pCoreGame = pCore;
}


////////////////////////////////////////
//       ALG_SetPlayerIndex
/*! set player index
// \param int iIndex : 
*/
void cAlgNetClientPlayer::ALG_SetPlayerIndex(int iIndex) 
{
    m_iMyIndex = iIndex;
}

////////////////////////////////////////
//       ALG_PLayerDeclareGoodGame
/*! 
// \param int iPlayerIx : 
// \param eDeclGoodGame eValgg : 
// \param eSUIT eValsuit : 
*/
void cAlgNetClientPlayer::ALG_PLayerDeclareGoodGame(int iPlayerIx, eDeclGoodGame eValgg,  eSUIT eValsuit)
{
    
}


////////////////////////////////////////
//       ALG_SetOpponentIndex
/*! set opponent index
// \param int iIndex : 
// \param int iOpponentNr : 
*/
void cAlgNetClientPlayer::ALG_SetOpponentIndex(int iIndex, int iOpponentNr) 
{
    m_iOppIndex =  iIndex;
}


////////////////////////////////////////
//       ALG_SetAssociateIndex
/*! set associate index
// \param int iIndex : 
*/
void cAlgNetClientPlayer::ALG_SetAssociateIndex(int iIndex) 
{

}


////////////////////////////////////////
//       ALG_NewMatch
/*! new match notification
// \param int iNumPlayer : 
*/
void cAlgNetClientPlayer::ALG_NewMatch(int iNumPlayer) 
{
    
}


////////////////////////////////////////
//       ALG_NewGiocata
/*! new giocata notification
// \param CARDINFO* pCardArray : 
// \param int iNumOfCards : 
*/
void cAlgNetClientPlayer::ALG_NewGiocata(CARDINFO* pCardArray, int iNumOfCards, int iPlayerIx) 
{
    
}


////////////////////////////////////////
//       ALG_PlayerHasPlayed
/*! player has played a card
// \param int iPlayerIx : 
// \param CARDINFO* pCard : 
*/
void cAlgNetClientPlayer::ALG_PlayerHasPlayed(int iPlayerIx, CARDINFO* pCard) 
{
    
}

////////////////////////////////////////
//       ALG_PlayerHasSaid
/*! player has said something
// \param int iPlayerIx : 
// \param eSayPlayer eSay : 
*/
void cAlgNetClientPlayer::ALG_PlayerHasSaid(int iPlayerIx, eSayPlayer eSay) 
{
}


////////////////////////////////////////
//       ALG_Play
/*! player have to play notification
*/
void cAlgNetClientPlayer::ALG_Play() 
{
    std::cout << "[Net] Have to play\n";

    PlayCardFromNet();
}

////////////////////////////////////////
//       ALG_Say
/*! Algorithm is invited to responce
*/
void cAlgNetClientPlayer::ALG_Say()
{
    std::cout << "[Net] Have to say\n";

    SayFromNet();
   
}

////////////////////////////////////////
//       ALG_ManoEnd
/*! mano end notification
*/
void cAlgNetClientPlayer::ALG_ManoEnd(I_MatchScore* pScore) 
{

}

////////////////////////////////////////
//       ALG_GiocataEnd
/*! 
*/
void cAlgNetClientPlayer::ALG_GiocataEnd(I_MatchScore* pScore) 
{

}

////////////////////////////////////////
//       ALG_MatchEnd
/*! match end notification
*/
void cAlgNetClientPlayer::ALG_MatchEnd(I_MatchScore* pScore) 
{

}




////////////////////////////////////////
//       ALG_GicataScoreChange
/*! 
// \param eGiocataScoreState eNewScore : 
*/
void cAlgNetClientPlayer::ALG_GicataScoreChange(eGiocataScoreState eNewScore)
{
    
}


////////////////////////////////////////
//       ALG_PLayerSaidFalse
/*! player said somithing false
// \param int iPlayerIx : 
*/
void cAlgNetClientPlayer::ALG_PLayerSaidFalse(int iPlayerIx)
{
}

///////////////////////////////// Interface with NetClient



////////////////////////////////////////
//       PlayCardFromNet
/*! Play a card that was send over the network
*/
void cAlgNetClientPlayer::PlayCardFromNet()
{
    CardSpec             CardPlayed;
    // to do: get information m_CardPlayed about the card from net client
    BOOL bRes = m_pCoreGame->Player_playCard(m_iMyIndex, CardPlayed.GetCardInfo());
    ASSERT(bRes);
}


////////////////////////////////////////
//       SayFromNet
/*! Say something from network
*/
void cAlgNetClientPlayer::SayFromNet()
{
    
}





