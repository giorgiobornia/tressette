#python test script 1 for invido test engine
import tre

#print version number
print "TestEngine version:", tre.CheckVersion()


#callback define
SCR_NFY_SHUFFLEDECK = 0
SCR_NFY_HAVETO_SAY = 1

ASS_B = 0
DUE_B = 1
TRE_B = 2
QUA_B = 3
CIN_B = 4
SEI_B = 5
SET_B = 6
FAN_B = 7
CAV_B = 8
REE_B = 9

ASS_C = 10
DUE_C = 11
TRE_C = 12
QUA_C = 13
CIN_C = 14
SEI_C = 15
SET_C = 16
FAN_C = 17
CAV_C = 18
REE_C = 19

ASS_D = 20
DUE_D = 21
TRE_D = 22
QUA_D = 23
CIN_D = 24
SEI_D = 25
SET_D = 26
FAN_D = 27
CAV_D = 28
REE_D = 29

ASS_S = 30
DUE_S = 31
TRE_S = 32
QUA_S = 33
CIN_S = 34
SEI_S = 35
SET_S = 36
FAN_S = 37
CAV_S = 38
REE_S = 39


#player index
CPU_OPP_2 = 3
CPU_SOCIO = 2
CPU_OPP_1 = 1
HUMAN = 0
RANDOM_PLAYER = -1

#override deck
#tre.setPlayerDeck(HUMAN,     ASS_B, DUE_B, TRE_B , DUE_D, DUE_S, SEI_B, SET_D, CIN_D, CAV_B, REE_B)
#tre.setPlayerDeck(CPU_OPP_1, ASS_C, DUE_C, TRE_C, CIN_S, CIN_C, SEI_S, SET_C, FAN_C, CAV_C, REE_C)
#tre.setPlayerDeck(CPU_SOCIO, ASS_D, QUA_B, TRE_D, QUA_D, FAN_B, SEI_D, SET_B, FAN_D, CAV_D, REE_D)
#tre.setPlayerDeck(CPU_OPP_2, ASS_S, CIN_B, TRE_S, QUA_S, QUA_C, SEI_C, SET_S, FAN_S, CAV_S, REE_S)
#tre.checkDeck()
tre.startPlayer(HUMAN)
