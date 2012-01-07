// MatchTest.h

#ifndef _MATCHTEST_H_
#define _MATCHTEST_H_

#include <cxxtest/TestSuite.h>
#include "cMatchPoints.h"
#include "CoreEnv.h"

//! Test the class cMatchPoints
class cMatchPointsTest : public CxxTest::TestSuite
{
    enum
    {
        ASS_B = 0,
        DUE_B = 1,
        TRE_B = 2,
        QUA_B = 3,
        CIN_B = 4,
        SEI_B = 5,
        SET_B = 6,
        FAN_B = 7,
        CAV_B = 8,
        REE_B = 9,

        ASS_C = 10,
        DUE_C = 11,
        TRE_C = 12,
        QUA_C = 13,
        CIN_C = 14,
        SEI_C = 15,
        SET_C = 16,
        FAN_C = 17,
        CAV_C = 18,
        REE_C = 19,

        PL_1 = 0,
        PL_2 = 1,
        PL_3 = 2,
        PL_4 = 3
    };

public:
    void testManoEnd()
    {
        cMatchPoints aMatch;

        aMatch.MatchStart(4);
        aMatch.GiocataStart(); 
        
        CardSpec card1;
        card1.SetCardIndex(ASS_B); 
        aMatch.PlayerPlay(PL_1, card1.GetCardInfo()); 
        TS_ASSERT_EQUALS(aMatch.GetCurrNumCardPlayed(), 1 );

        card1.SetCardIndex(DUE_B);
        aMatch.PlayerPlay(PL_2, card1.GetCardInfo());
        TS_ASSERT_EQUALS(aMatch.GetCurrNumCardPlayed(), 2 );

        card1.SetCardIndex(REE_B);
        aMatch.PlayerPlay(PL_3, card1.GetCardInfo());
        TS_ASSERT_EQUALS(aMatch.GetCurrNumCardPlayed(), 3 );

        card1.SetCardIndex(FAN_B);
        aMatch.PlayerPlay(PL_4, card1.GetCardInfo());
        TS_ASSERT_EQUALS(aMatch.GetCurrNumCardPlayed(), 4 );

        aMatch.ManoEnd();

        TS_ASSERT_EQUALS( aMatch.GetManoWinner(), PL_2 );
    }
};

#endif