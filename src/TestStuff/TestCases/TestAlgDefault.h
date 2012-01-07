//TestAlgDefault.h

#ifndef _TESTALGDEFAULT_H
#define _TESTALGDEFAULT_H

#include <cxxtest/TestSuite.h>
#include "cAlgDefault.h"
#include "CoreEnv.h"

//! Test the class cAlgDefault
class cAlgDefaultTest : public CxxTest::TestSuite
{
    enum
    {
        ASS_B = 0, DUE_B = 1, TRE_B = 2, QUA_B = 3, CIN_B = 4,
        SEI_B = 5, SET_B = 6, FAN_B = 7, CAV_B = 8, REE_B = 9,

        ASS_C = 10,DUE_C = 11,TRE_C = 12,QUA_C = 13,CIN_C = 14,
        SEI_C = 15,SET_C = 16,FAN_C = 17,CAV_C = 18,REE_C = 19,

        ASS_D = 20,DUE_D = 21,TRE_D = 22,QUA_D = 23,CIN_D = 24,
        SEI_D = 25,SET_D = 26,FAN_D = 27,CAV_D = 28,REE_D = 29,

        ASS_S = 30,DUE_S = 31,TRE_S = 32,QUA_S = 33,CIN_S = 34,
        SEI_S = 35,SET_S = 36,FAN_S = 37,CAV_S = 38,REE_S = 39,

        PL_1 = 0,
        PL_2 = 1,
        PL_3 = 2,
        PL_4 = 3
    };

    //! class mockCore
    // substitution for cCore object
    class mockCore: public I_CORE_Game
    {
    public:
        mockCore(){}
        virtual BOOL      Player_saySomething(int iPlayerIx, eSayPlayer eSay ){m_iPlayerIx = iPlayerIx; m_ePlSay  = eSay; return TRUE;}
        virtual BOOL      Player_playCard(int iPlayerIx, CARDINFO* pCardInfo){m_iPlayerIx = iPlayerIx; m_CARD = *pCardInfo; return TRUE;}
        virtual void      AbandonGame(int iPlayerIx){m_iPlayerIx = iPlayerIx;}
        virtual BOOL      DeclareGoodGame(int iPlayerIx, eDeclGoodGame eValgg,  eSUIT eValsuit)
        {m_iPlayerIx = iPlayerIx; m_eGoodGame = eValgg; m_eSuit = eValsuit; return TRUE;}

        int           m_iPlayerIx;
        eSayPlayer    m_ePlSay;
        CARDINFO      m_CARD;
        eDeclGoodGame m_eGoodGame;
        eSUIT         m_eSuit;
    };

public :

// support routine

    // provides CARDINFO from index
    void getCardInfoOnIndex(CARDINFO& InfoRes, int iIndex)
    {
        CardSpec tmpCard;
        tmpCard.SetCardIndex(iIndex);
        tmpCard.FillInfo(&InfoRes); 
    }

    // hand1 player
    void hand1_player(CARDINFO* arrCards)
    {
        // cards in the hand (indexes)
        const int MYHAND[] = 
        { 
            ASS_B, DUE_B, TRE_B, 
            QUA_C, FAN_C, REE_C, SET_C,
            QUA_D, TRE_D,
            DUE_S
        };
        CardSpec tmpCard;
        for (int j = 0; j < NUM_CARDS_HAND; j++)
        {
            tmpCard.SetCardIndex(MYHAND[j]);
            tmpCard.FillInfo(&arrCards[j]);
        }

    }

    // hand2 player
    void hand2_player(CARDINFO* arrCards)
    {
        // cards in the hand (indexes)
        const int MYHAND[] = 
        { 
            ASS_B, DUE_B, 
            ASS_C, FAN_C, REE_C, SET_C,
            ASS_D, TRE_D, CAV_D, SEI_D
        };
        CardSpec tmpCard;
        for (int j = 0; j < NUM_CARDS_HAND; j++)
        {
            tmpCard.SetCardIndex(MYHAND[j]);
            tmpCard.FillInfo(&arrCards[j]);
        }
    }

    // hand3 player
    void hand3_player(CARDINFO* arrCards)
    {
        // cards in the hand (indexes)
        const int MYHAND[] = 
        { 
            ASS_B, DUE_B, 
            ASS_C, DUE_C, REE_C, SET_C, CIN_C,
            ASS_D, TRE_D, CAV_D
        };
        CardSpec tmpCard;
        for (int j = 0; j < NUM_CARDS_HAND; j++)
        {
            tmpCard.SetCardIndex(MYHAND[j]);
            tmpCard.FillInfo(&arrCards[j]);
        }
    }

    // hand4 player
    void hand4_player(CARDINFO* arrCards)
    {
        // cards in the hand (indexes)
        const int MYHAND[] = 
        { 
            ASS_B, DUE_B, 
            ASS_C, DUE_C, REE_C, SET_C, 
            ASS_D, TRE_D, CAV_D,
            SEI_S
        };
        CardSpec tmpCard;
        for (int j = 0; j < NUM_CARDS_HAND; j++)
        {
            tmpCard.SetCardIndex(MYHAND[j]);
            tmpCard.FillInfo(&arrCards[j]);
        }
    }

    // hand5 player
    void hand5_player(CARDINFO* arrCards)
    {
        // cards in the hand (indexes)
        const int MYHAND[] = 
        { 
            ASS_B, DUE_B, QUA_B,
            ASS_C, DUE_C, SET_C, 
            ASS_D, TRE_D, CAV_D,
            SEI_S
        };
        CardSpec tmpCard;
        for (int j = 0; j < NUM_CARDS_HAND; j++)
        {
            tmpCard.SetCardIndex(MYHAND[j]);
            tmpCard.FillInfo(&arrCards[j]);
        }
    }

    // hand all  players
    void hand_allplayers(CARDINFO* arrCards, int iIxPlayer)
    {
        // cards in the hand (indexes)
        const int HAND_PL1[] = 
        { 
            ASS_B, DUE_B, TRE_B, SEI_B, CAV_B, REE_B,  
            DUE_D, SET_D, CIN_D,
            DUE_S
        };

        const int HAND_PL2[] = 
        { 
            ASS_C, DUE_C, TRE_C,  CIN_C,  SET_C, FAN_C, CAV_C, REE_C,
            CIN_S, SEI_S
        };

        const int HAND_PL3[] = 
        { 
            QUA_B, FAN_B, SET_B,
            ASS_D, TRE_D, QUA_D, SEI_D, FAN_D, CAV_D, REE_D
        };

        const int HAND_PL4[] = 
        { 
            CIN_B,
            QUA_C, SEI_C,
            ASS_S,  TRE_S, QUA_S,  SET_S, FAN_S, CAV_S, REE_S
        };


        CardSpec tmpCard;

        if (iIxPlayer == PL_1)
        {
            for (int j = 0; j < sizeof(HAND_PL1)/sizeof(enum); j++)
            {
                tmpCard.SetCardIndex(HAND_PL1[j]);
                tmpCard.FillInfo(&arrCards[j]);
            }
        }
        else if (iIxPlayer == PL_2)
        {
            for (int j = 0; j < sizeof(HAND_PL2)/sizeof(enum); j++)
            {
                tmpCard.SetCardIndex(HAND_PL2[j]);
                tmpCard.FillInfo(&arrCards[j]);
            }
        }
        else if (iIxPlayer == PL_3)
        {
            for (int j = 0; j < sizeof(HAND_PL3)/sizeof(enum); j++)
            {
                tmpCard.SetCardIndex(HAND_PL3[j]);
                tmpCard.FillInfo(&arrCards[j]);
            }
        }
        else if (iIxPlayer == PL_4)
        {
            for (int j = 0; j < sizeof(HAND_PL4)/sizeof(enum); j++)
            {
                tmpCard.SetCardIndex(HAND_PL4[j]);
                tmpCard.FillInfo(&arrCards[j]);
            }
        }
    }

    void hand_errid2_player(CARDINFO* arrCards)
    {
        // cards in the hand (indexes)
        const int MYHAND[] = 
        { 
            DUE_B,  CAV_B,
            QUA_C, FAN_C, CIN_C, 
            CAV_D, FAN_D,
            TRE_S, QUA_S, CAV_S
        };
        CardSpec tmpCard;
        for (int j = 0; j < NUM_CARDS_HAND; j++)
        {
            tmpCard.SetCardIndex(MYHAND[j]);
            tmpCard.FillInfo(&arrCards[j]);
        }
    }


///////////////////////////////////////// TEST ///////////////////////////

    // test the new giocta
    void testNewGiocata()
    {
        cAlgDefault Alg; 
        CARDINFO arrCards[NUM_CARDS_HAND];
        hand1_player(arrCards);

        // new match first
        Alg.ALG_NewMatch(4); 
        // set index player
        Alg.ALG_SetPlayerIndex(PL_1);
        // new giocata
        Alg.ALG_NewGiocata( arrCards, NUM_CARDS_HAND, PL_1);
        AlgSupport::HandInfo  handInfo = Alg.GetCurrenHandInfo();

        TS_ASSERT_EQUALS( handInfo.ePizzOnBastoni, AlgSupport::NAPOLA );
        TS_ASSERT_EQUALS( handInfo.ePizzOnCoppe , AlgSupport::PIZZ_NONE );
        TS_ASSERT_EQUALS( handInfo.ePizzOnDenari, AlgSupport::TRE );
        TS_ASSERT_EQUALS( handInfo.ePizzOnSpade   , AlgSupport::DUE );
    }

    // test the new giocta
    void testNewGiocata2()
    {
        cAlgDefault Alg; 
        CARDINFO arrCards[NUM_CARDS_HAND];
        hand2_player(arrCards);

        // new match first
        Alg.ALG_NewMatch(4); 
        // set index player
        Alg.ALG_SetPlayerIndex(PL_1);
        // new giocata
        Alg.ALG_NewGiocata( arrCards, NUM_CARDS_HAND, PL_1);
        AlgSupport::HandInfo  handInfo = Alg.GetCurrenHandInfo();
        
        TS_ASSERT_EQUALS( handInfo.ePizzOnBastoni, AlgSupport::VENTOTTO );
        TS_ASSERT_EQUALS( handInfo.ePizzOnCoppe , AlgSupport::ASSO );
        TS_ASSERT_EQUALS( handInfo.ePizzOnDenari, AlgSupport::VENTINOVE );
        TS_ASSERT_EQUALS( handInfo.ePizzOnSpade   , AlgSupport::PIZZ_NONE );
    }

    // test play
    void testPlayFirst()
    {
        cAlgDefault Alg; 
        CARDINFO arrCards[NUM_CARDS_HAND];
        // use the hand1 card distribution
        hand1_player(arrCards);
        CARDINFO CardINFO_played;
        
        mockCore myCore;

        // set core interface
        Alg.ALG_SetCoreInterface(&myCore); 

        // new match first
        Alg.ALG_NewMatch(4); 
        // set index player
        Alg.ALG_SetPlayerIndex(PL_1);
        // new giocata
        Alg.ALG_NewGiocata( arrCards, NUM_CARDS_HAND, PL_1);
        
        // ----> play a card (1st trick)
        Alg.ALG_Play();
        // card played is stored in the mock core
        TS_ASSERT_EQUALS( myCore.m_CARD.byIndex, TRE_B);
        // continue the trick
        CardINFO_played = myCore.m_CARD;
        Alg.ALG_PlayerHasPlayed(PL_1, &CardINFO_played);
        
        // turn on second player
        getCardInfoOnIndex( CardINFO_played, CIN_B );
        Alg.ALG_PlayerHasPlayed(PL_2, &CardINFO_played);

        // third player
        getCardInfoOnIndex( CardINFO_played, CAV_B );
        Alg.ALG_PlayerHasPlayed(PL_3, &CardINFO_played);

        // forth player
        getCardInfoOnIndex( CardINFO_played, REE_B );
        Alg.ALG_PlayerHasPlayed(PL_4, &CardINFO_played);
        // trick end
        Alg.ALG_ManoEnd( NULL ); 

        // ----> second hand, play first
        // play a card (2st trick)
        Alg.ALG_Play();
        TS_ASSERT_EQUALS( myCore.m_CARD.byIndex, DUE_B);
        CardINFO_played = myCore.m_CARD;
        Alg.ALG_PlayerHasPlayed(PL_1, &CardINFO_played);
        
        // turn on second player
        getCardInfoOnIndex( CardINFO_played, SEI_B );
        Alg.ALG_PlayerHasPlayed(PL_2, &CardINFO_played);

        // third player
        getCardInfoOnIndex( CardINFO_played, SET_B );
        Alg.ALG_PlayerHasPlayed(PL_3, &CardINFO_played);

        // forth player
        getCardInfoOnIndex( CardINFO_played, FAN_B );
        Alg.ALG_PlayerHasPlayed(PL_4, &CardINFO_played);
        // trick end
        Alg.ALG_ManoEnd( NULL ); 

        // ----> third hand, play first
        // play a card (3st trick)
        Alg.ALG_Play();
        TS_ASSERT_EQUALS( myCore.m_CARD.byIndex, ASS_B);
        CardINFO_played = myCore.m_CARD;
        Alg.ALG_PlayerHasPlayed(PL_1, &CardINFO_played);
        
        // turn on second player
        getCardInfoOnIndex( CardINFO_played, QUA_B );
        Alg.ALG_PlayerHasPlayed(PL_2, &CardINFO_played);

        // third player
        getCardInfoOnIndex( CardINFO_played, ASS_S );
        Alg.ALG_PlayerHasPlayed(PL_3, &CardINFO_played);

        // forth player
        getCardInfoOnIndex( CardINFO_played, CIN_C );
        Alg.ALG_PlayerHasPlayed(PL_4, &CardINFO_played);
        // trick end
        Alg.ALG_ManoEnd( NULL ); 

        // ---> fourth trick
        Alg.ALG_Play();
        TS_ASSERT_EQUALS( myCore.m_CARD.byIndex, QUA_D);
    }

    // test the function player has played. The algorithm should sort cards
    void testHasPlayed()
    {
        
        cAlgDefault Alg; 
        CARDINFO arrCards[NUM_CARDS_HAND];
        // use the hand1 card distribution
        hand_allplayers(arrCards, PL_1);

        CARDINFO CardINFO_played;
        
        mockCore myCore;

        // set core interface
        Alg.ALG_SetCoreInterface(&myCore); 

        // new match first
        Alg.ALG_NewMatch(4); 
        // set index player
        Alg.ALG_SetPlayerIndex(PL_1);
        // new giocata
        Alg.ALG_NewGiocata( arrCards, NUM_CARDS_HAND, PL_1);
        Alg.ALG_Play();
        // card played is stored in the mock core
        TS_ASSERT_EQUALS( myCore.m_CARD.byIndex, TRE_B);
        
        // has played call
        CardINFO_played = myCore.m_CARD;
        Alg.ALG_PlayerHasPlayed(PL_1, &CardINFO_played);
        TS_ASSERT_EQUALS( Alg.m_arrCardAllPlayers[PL_1][NUM_CARDS_HAND-1].byIndex, 0xff);
        for (int i = 0; i < NUM_CARDS_HAND - 1; i++)
        {
            TS_ASSERT_DIFFERS( Alg.m_arrCardAllPlayers[PL_1][i].byIndex, 0xff);
        }
        // other players play a card

        hand_allplayers(arrCards, PL_2);
        Alg.ALG_PlayerHasPlayed(PL_2, &arrCards[0]); // play ASS_C
        for (int j = 0; j <= PL_4; j++)
        {
            for (int i = 0; i < NUM_CARDS_HAND - 1; i++)
            {
                // check if differ to the card played
                TS_ASSERT_DIFFERS( Alg.m_arrCardAllPlayers[j][i].byIndex, ASS_C);
            }
        }
        TS_ASSERT_EQUALS( Alg.m_arrCardAllPlayers[PL_2][NUM_CARDS_HAND-1].byIndex, 0xff);
    }

    
    // test the player play first
    void testFirstHandPlayFirst()
    {
        
        cAlgDefault Alg; 
        CARDINFO arrCards[NUM_CARDS_HAND];
        
        mockCore myCore;

        //(FORTE)
        // set core interface
        Alg.ALG_SetCoreInterface(&myCore); 
         // use the hand1 card distribution
        hand2_player(arrCards);
        // new match first
        Alg.ALG_NewMatch(4); 
        // set index player
        Alg.ALG_SetPlayerIndex(PL_1);
        // new giocata
        Alg.ALG_NewGiocata( arrCards, NUM_CARDS_HAND, PL_1);
        
        // ----> play a card (1st trick)
        Alg.ALG_Play();
        // card played is stored in the mock core
        TS_ASSERT_EQUALS( myCore.m_CARD.byIndex, TRE_D);

        // another hand on bastoni (ATTACCO)
        hand4_player(arrCards);
        Alg.ALG_NewMatch(4); 
        Alg.ALG_SetPlayerIndex(PL_1);
        Alg.ALG_NewGiocata( arrCards, NUM_CARDS_HAND, PL_1);
        Alg.ALG_Play();
        TS_ASSERT_EQUALS( myCore.m_CARD.byIndex, REE_C);

        // DEBOLE
        hand5_player(arrCards);
        Alg.ALG_NewMatch(4); 
        Alg.ALG_SetPlayerIndex(PL_1);
        Alg.ALG_NewGiocata( arrCards, NUM_CARDS_HAND, PL_1);
        Alg.ALG_Play();
        TS_ASSERT_EQUALS( myCore.m_CARD.byIndex, SEI_S);

        
    }
    
    // test function PizzicoOnbiggerSeed
    void testPizzicoOnbiggerSeed()
    {
        cAlgDefault Alg; 
        CARDINFO arrCards[NUM_CARDS_HAND];
        // use the hand1 card distribution
        hand2_player(arrCards);
        
        mockCore myCore;

        // set core interface
        Alg.ALG_SetCoreInterface(&myCore); 

        // new match first
        Alg.ALG_NewMatch(4); 
        // set index player
        Alg.ALG_SetPlayerIndex(PL_1);
        // new giocata
        Alg.ALG_NewGiocata( arrCards, NUM_CARDS_HAND, PL_1);

        eSUIT eSuitStark;
        AlgSupport::ePizzicoInSuit ePizz = Alg.pizzicoOnBiggerSeed(eSuitStark);
        TS_ASSERT_EQUALS(eSuitStark , DENARI);
        TS_ASSERT_EQUALS(ePizz , AlgSupport::VENTINOVE);

        // another hand on bastoni
        hand_allplayers(arrCards, PL_1);
        Alg.ALG_NewMatch(4); 
        Alg.ALG_SetPlayerIndex(PL_1);
        Alg.ALG_NewGiocata( arrCards, NUM_CARDS_HAND, PL_1);

        ePizz = Alg.pizzicoOnBiggerSeed(eSuitStark);
        TS_ASSERT_EQUALS(eSuitStark , BASTONI);
        TS_ASSERT_EQUALS(ePizz , AlgSupport::NAPOLA);

        // another hand on spade
        hand_allplayers(arrCards, PL_4);
        Alg.ALG_NewMatch(4); 
        Alg.ALG_SetPlayerIndex(PL_4);
        Alg.ALG_NewGiocata( arrCards, NUM_CARDS_HAND, PL_4);

        ePizz = Alg.pizzicoOnBiggerSeed(eSuitStark);
        TS_ASSERT_EQUALS(eSuitStark , SPADE);
        TS_ASSERT_EQUALS(ePizz , AlgSupport::VENTINOVE);

        // another hand on coppe
        hand3_player(arrCards);
        Alg.ALG_NewMatch(4); 
        Alg.ALG_SetPlayerIndex(PL_1);
        Alg.ALG_NewGiocata( arrCards, NUM_CARDS_HAND, PL_1);

        ePizz = Alg.pizzicoOnBiggerSeed(eSuitStark);
        TS_ASSERT_EQUALS(eSuitStark , COPPE);
        TS_ASSERT_EQUALS(ePizz , AlgSupport::VENTOTTO);

        // test with exclusion
        VCT_SUITE vctExcl;
        vctExcl.push_back(COPPE);
        hand3_player(arrCards);
        Alg.ALG_NewMatch(4); 
        Alg.ALG_SetPlayerIndex(PL_1);
        Alg.ALG_NewGiocata( arrCards, NUM_CARDS_HAND, PL_1);

        ePizz = Alg.pizzicoOnBiggerSeed(eSuitStark, &vctExcl);
        TS_ASSERT_EQUALS(eSuitStark , DENARI);
        TS_ASSERT_EQUALS(ePizz , AlgSupport::VENTINOVE);

    }

    // test the function that provides the biggest scartino in the list
    void testindexOfTheBiggerScartino()
    {
        cAlgDefault Alg; 
        CARDINFO arrCards[NUM_CARDS_HAND];
        // use the hand2 card distribution
        hand2_player(arrCards);
        
        mockCore myCore;

        // set core interface
        Alg.ALG_SetCoreInterface(&myCore); 

        // new match first
        Alg.ALG_NewMatch(4); 
        // set index player
        Alg.ALG_SetPlayerIndex(PL_1);
        // new giocata
        Alg.ALG_NewGiocata( arrCards, NUM_CARDS_HAND, PL_1);

        int iIndex = Alg.indexOfTheBiggerScartino(DENARI);
        TS_ASSERT_EQUALS(Alg.m_arrCardAllPlayers[PL_1][iIndex].byIndex , CAV_D);

        // another hand on bastoni
        hand_allplayers(arrCards, PL_1);
        Alg.ALG_NewMatch(4); 
        Alg.ALG_SetPlayerIndex(PL_1);
        Alg.ALG_NewGiocata( arrCards, NUM_CARDS_HAND, PL_1);
        iIndex = Alg.indexOfTheBiggerScartino(BASTONI);
        TS_ASSERT_EQUALS(Alg.m_arrCardAllPlayers[PL_1][iIndex].byIndex , REE_B);

        // another hand on spade
        hand_allplayers(arrCards, PL_4);
        Alg.ALG_NewMatch(4); 
        Alg.ALG_SetPlayerIndex(PL_4);
        Alg.ALG_NewGiocata( arrCards, NUM_CARDS_HAND, PL_4);
        iIndex = Alg.indexOfTheBiggerScartino(SPADE);
        TS_ASSERT_EQUALS(Alg.m_arrCardAllPlayers[PL_4][iIndex].byIndex , REE_S);

        // another hand on coppe
        hand3_player(arrCards);
        Alg.ALG_NewMatch(4); 
        Alg.ALG_SetPlayerIndex(PL_1);
        Alg.ALG_NewGiocata( arrCards, NUM_CARDS_HAND, PL_1);
        iIndex = Alg.indexOfTheBiggerScartino(COPPE);
        TS_ASSERT_EQUALS(Alg.m_arrCardAllPlayers[PL_1][iIndex].byIndex , REE_C);
    }

    // test player play as second and socio has said: busso la migliore
    void testPlayAsSecond_SocioCioca()
    {
        cAlgDefault Alg; 
        CARDINFO arrCards[NUM_CARDS_HAND];
        // use the hand1 card distribution
        hand1_player(arrCards);
        
        mockCore myCore;

        // set core interface
        Alg.ALG_SetCoreInterface(&myCore); 

        // new match first
        Alg.ALG_NewMatch(4); 
        // set index player
        Alg.ALG_SetPlayerIndex(PL_1);
        // new giocata, play on turn the player 3
        Alg.ALG_NewGiocata( arrCards, NUM_CARDS_HAND, PL_3);

        // player 3 cioca
        Alg.ALG_PlayerHasSaid(PL_3, BUSSO_LAMIGLIORE); 
        // player 3 play cinque di denari
        CARDINFO CardINFO_played;
        getCardInfoOnIndex( CardINFO_played, CIN_D );
        Alg.ALG_PlayerHasPlayed(PL_3, &CardINFO_played);

        // player 4 play
        getCardInfoOnIndex( CardINFO_played, FAN_D );
        Alg.ALG_PlayerHasPlayed(PL_4, &CardINFO_played);

        // playe 1 on turn
        Alg.ALG_Play();
        // card played is stored in the mock core
        TS_ASSERT_EQUALS( myCore.m_CARD.byIndex, TRE_D);

    }

    
    // test player as second and use the alpha beta 
    void testPlayAsSecond_alpahbeta()
    {
        
        cAlgDefault Alg; 
        CARDINFO arrCards[NUM_CARDS_HAND];
        // use the hand1 card distribution
        hand1_player(arrCards);
        
        mockCore myCore;

        // set core interface
        Alg.ALG_SetCoreInterface(&myCore); 

        // new match first
        Alg.ALG_NewMatch(4); 
        // set index player
        Alg.ALG_SetPlayerIndex(PL_1);
        // new giocata, play on turn the player 3
        Alg.ALG_NewGiocata( arrCards, NUM_CARDS_HAND, PL_3);

        // player 3 play cinque di denari
        CARDINFO CardINFO_played;
        getCardInfoOnIndex( CardINFO_played, CIN_D );
        Alg.ALG_PlayerHasPlayed(PL_3, &CardINFO_played);

        // player 4 play
        getCardInfoOnIndex( CardINFO_played, FAN_D );
        Alg.ALG_PlayerHasPlayed(PL_4, &CardINFO_played);

        // playe 1 on turn
        Alg.ALG_Play();
        // card played is stored in the mock core
        //TS_ASSERT_EQUALS( myCore.m_CARD.byIndex, QUA_D);

        // accept 3d, but it is not correct beacause on random cards distribution with bad assumption of partner cards.
        TS_ASSERT_EQUALS( myCore.m_CARD.byIndex, TRE_D); 
        
    }

    //test an error when  player 2 start 
    void testPlayAsSecond_err1_alpahbeta()
    {
        
        cAlgDefault Alg; 
        CARDINFO arrCards[NUM_CARDS_HAND];
        // use the hand1 card distribution
        hand1_player(arrCards);
        
        mockCore myCore;

        // set core interface
        Alg.ALG_SetCoreInterface(&myCore); 

        // new match first
        Alg.ALG_NewMatch(4); 
        // set index player
        Alg.ALG_SetPlayerIndex(PL_3);

        // new giocata, play on turn the player 2
        Alg.ALG_NewGiocata( arrCards, NUM_CARDS_HAND, PL_2);

        // player 2 play cinque di denari
        CARDINFO CardINFO_played;
        getCardInfoOnIndex( CardINFO_played, CIN_D );
        Alg.ALG_PlayerHasPlayed(PL_2, &CardINFO_played);

        // player 3 on turn
        Alg.ALG_Play();
        // card played is stored in the mock core
        //TS_ASSERT_EQUALS( myCore.m_CARD.byIndex, QUA_D);

        TS_ASSERT_EQUALS( myCore.m_CARD.byIndex, TRE_D); 
       
    }
    

    //test an error when  player 1 start 
    void testPlayAsSecond_err2_alpahbeta()
    {
        cAlgDefault Alg; 
        CARDINFO arrCards[NUM_CARDS_HAND];
        // use the hand1 card distribution
        hand1_player(arrCards);
        
        mockCore myCore;
        CARDINFO CardINFO_played;

        // set core interface
        Alg.ALG_SetCoreInterface(&myCore); 

        // new match first
        Alg.ALG_NewMatch(4); 
        // set index player
        Alg.ALG_SetPlayerIndex(PL_2);

        // new giocata, play on turn the player 2
        Alg.ALG_NewGiocata( arrCards, NUM_CARDS_HAND, PL_1);

        // player 1 play 
        
        getCardInfoOnIndex( CardINFO_played, CIN_C );
        Alg.ALG_PlayerHasPlayed(PL_1, &CardINFO_played);

        // player 2 on turn
        Alg.ALG_Play();
        // card played is stored in the mock core
        //TS_ASSERT_EQUALS( myCore.m_CARD.byIndex, QUA_D);
        //TS_ASSERT_EQUALS( myCore.m_CARD.byIndex, FAN_C);
        CardINFO_played = myCore.m_CARD;
        Alg.ALG_PlayerHasPlayed(PL_2, &CardINFO_played);

        getCardInfoOnIndex( CardINFO_played, SEI_C );
        Alg.ALG_PlayerHasPlayed(PL_3, &CardINFO_played);

        getCardInfoOnIndex( CardINFO_played, TRE_C );
        Alg.ALG_PlayerHasPlayed(PL_4, &CardINFO_played);

        Alg.ALG_ManoEnd(NULL); 
        

        // --- second trick --

        getCardInfoOnIndex( CardINFO_played, TRE_S );
        Alg.ALG_PlayerHasPlayed(PL_4, &CardINFO_played);

        getCardInfoOnIndex( CardINFO_played, ASS_S );
        Alg.ALG_PlayerHasPlayed(PL_1, &CardINFO_played);

        Alg.ALG_Play();
        TS_ASSERT_EQUALS( myCore.m_CARD.byIndex, DUE_S);

    }

    // test error case descripted in /Doc/bugs/errore_durantela_giocata_id2.txt
    void testErrorDescrId2()
    {
        
        cAlgDefault Alg; 
        CARDINFO arrCards[NUM_CARDS_HAND];
        // use the hand1 card distribution
        hand_errid2_player(arrCards);

        srand(1140133127); 
        
        mockCore myCore;
        CARDINFO CardINFO_played;

        // set core interface
        Alg.ALG_SetCoreInterface(&myCore); 

        // new match first
        Alg.ALG_NewMatch(4); 
        // set index player
        Alg.ALG_SetPlayerIndex(PL_3);

        // new giocata, play on turn
        Alg.ALG_NewGiocata( arrCards, NUM_CARDS_HAND, PL_4);

        // --- trick 1 --- 
        getCardInfoOnIndex( CardINFO_played, TRE_C );
        Alg.ALG_PlayerHasPlayed(PL_4, &CardINFO_played);
        getCardInfoOnIndex( CardINFO_played, SET_S );
        Alg.ALG_PlayerHasPlayed(PL_1, &CardINFO_played);
        getCardInfoOnIndex( CardINFO_played, SEI_C );
        Alg.ALG_PlayerHasPlayed(PL_2, &CardINFO_played);

        Alg.ALG_Play();
        getCardInfoOnIndex( CardINFO_played, FAN_C );
        Alg.ALG_PlayerHasPlayed(PL_3, &CardINFO_played);
        
        Alg.ALG_ManoEnd(NULL);

        // --- trick 2 --- 
        getCardInfoOnIndex( CardINFO_played, DUE_C );
        Alg.ALG_PlayerHasPlayed(PL_4, &CardINFO_played);
        getCardInfoOnIndex( CardINFO_played, QUA_D );
        Alg.ALG_PlayerHasPlayed(PL_1, &CardINFO_played);
        getCardInfoOnIndex( CardINFO_played, REE_C );
        Alg.ALG_PlayerHasPlayed(PL_2, &CardINFO_played);
        
        Alg.ALG_Play();
        getCardInfoOnIndex( CardINFO_played, CIN_C );
        Alg.ALG_PlayerHasPlayed(PL_3, &CardINFO_played);
        Alg.ALG_ManoEnd(NULL);

        // --- trick 3 --- 
        getCardInfoOnIndex( CardINFO_played, CAV_C );
        Alg.ALG_PlayerHasPlayed(PL_4, &CardINFO_played);
        getCardInfoOnIndex( CardINFO_played, SET_D );
        Alg.ALG_PlayerHasPlayed(PL_1, &CardINFO_played);
        getCardInfoOnIndex( CardINFO_played, ASS_C );
        Alg.ALG_PlayerHasPlayed(PL_2, &CardINFO_played);
        
        Alg.ALG_Play();



    }
    
};

#endif