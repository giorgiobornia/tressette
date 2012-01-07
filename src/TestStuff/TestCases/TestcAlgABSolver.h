// TestcAlgABSolver

#ifndef _TEST_ALG_ABSOLVER__H_
#define _TEST_ALG_ABSOLVER__H_

#include <cxxtest/TestSuite.h>
#include "cAlgABSolver.h"
#include "CoreEnv.h"


class TestcAlgABSolver : public CxxTest::TestSuite
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
        PL_4 = 3,
        NUM_PL = 4
    };

public:
    // hand1 players
    void hand1_players(CARDINFO* arrCards, int iIxPlayer)
    {
        // cards in the hand (indexes)
        const int HAND_PL1[] = 
        { 
            ASS_B,  
            QUA_C, 
            TRE_D
        };

        const int HAND_PL2[] = 
        { 
            DUE_B,  
            CIN_C, 
            ASS_D
        };

        const int HAND_PL3[] = 
        { 
            TRE_B,  
            ASS_C, 
            CIN_D
        };

        const int HAND_PL4[] = 
        { 
            DUE_S, SEI_S, SET_S
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

    // test on the last 3 tricks
    void testSolveLast3Tricks()
    {
        cAlgABSolver ABSolver;
        ABSolver.InitDeck(); 
        ABSolver.SetHandDeph(12); 

        int i;
        CARDINFO arrTrickHist[NUM_PL];
        CARDINFO arrCards[NUM_CARDS_HAND];
        for ( i = 0; i < NUM_PL; i++ )
        {
            hand1_players(arrCards, i);
            ABSolver.SetHands(i,  &arrCards[0], 3);
        }
        ABSolver.SetInitialPlayer(PL_1);  
        ABSolver.Solve();
        
        CARDINFO cardInfo;
        ABSolver.GetBestCardToPlay(PL_1, &cardInfo);
        
        TS_ASSERT_EQUALS(cardInfo.byIndex , ASS_B);
        arrTrickHist[0] = cardInfo;

        //--- second player
        cAlgABSolver ABSolver2;
        ABSolver2.InitDeck(); 
        ABSolver2.SetHandDeph(12);

        for ( i = 0; i < NUM_PL; i++ )
        {
            hand1_players(arrCards, i);
            ABSolver2.SetHands(i,  &arrCards[0], 3);
        }
        ABSolver2.SetCurrTrickHistory(PL_1, arrTrickHist, 1);

        //ABSolver2.SetMaxCalcTime(1000000000);     
        ABSolver2.SetInitialPlayer(PL_2);  
        ABSolver2.Solve();
        ABSolver2.GetBestCardToPlay(PL_2, &cardInfo);

        TS_ASSERT_EQUALS(cardInfo.byIndex , DUE_B);
        arrTrickHist[1] = cardInfo;

        //--- third player
        cAlgABSolver ABSolver3;
        ABSolver3.InitDeck(); 
        ABSolver3.SetHandDeph(12);

        for ( i = 0; i < NUM_PL; i++ )
        {
            hand1_players(arrCards, i);
            ABSolver3.SetHands(i,  &arrCards[0], 3);
        }
        ABSolver3.SetCurrTrickHistory(PL_1, arrTrickHist, 2);

        //ABSolver3.SetMaxCalcTime(1000000000);     
        ABSolver3.SetInitialPlayer(PL_3);  
        ABSolver3.Solve();
        ABSolver3.GetBestCardToPlay(PL_3, &cardInfo);

        TS_ASSERT_EQUALS(cardInfo.byIndex , TRE_B);
        arrTrickHist[2] = cardInfo;

        //--- forth player
        cAlgABSolver ABSolver4;
        ABSolver4.InitDeck(); 
        ABSolver4.SetHandDeph(12);

        for ( i = 0; i < NUM_PL; i++ )
        {
            hand1_players(arrCards, i);
            ABSolver4.SetHands(i,  &arrCards[0], 3);
        }
        ABSolver4.SetCurrTrickHistory(PL_1, arrTrickHist, 3);

        //ABSolver4.SetMaxCalcTime(1000000000);     
        ABSolver4.SetInitialPlayer(PL_4);  
        ABSolver4.Solve();
        ABSolver4.GetBestCardToPlay(PL_4, &cardInfo);

        TS_ASSERT_EQUALS(cardInfo.byIndex , SEI_S);
        arrTrickHist[3] = cardInfo;
    }   

};


#endif