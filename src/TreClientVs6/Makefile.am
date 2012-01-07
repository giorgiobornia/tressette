MY_INCLUDES =\
  -I../../include\
  -I../../src/TreCore\
  -I../../src/MySearchAlpha\
  -I../../src/gfx_widgets

MY_DEFINE = -DNOPYTHON

MY_LIBS = -lSDL_image\
      -lSDL_mixer\
      -lSDL_ttf

bin_PROGRAMS = tressettetux
tressettetux_SOURCES = main.cpp \
            EngineApp.cpp\
            cCardGfx.cpp\
            cDelayNextAction.cpp\
            cGameMainGfx.cpp\
            cHightScoreMgr.cpp\
            cMenuMgr.cpp\
            credits.cpp\
            cSettings.cpp\
            cTipoDiMazzo.cpp\
            EnterNameGfx.cpp\
            fading.cpp\
            cMusicManager.cpp\
            lang_gen.cpp\
            OptionDeckGfx.cpp\
            OptionGameGfx.cpp\
            OptionGfx.cpp\
            ../gfx_widgets/cBalloonGfx.cpp\
            ../gfx_widgets/cButtonGfx.cpp\
            ../gfx_widgets/cCheckBoxGfx.cpp\
            ../gfx_widgets/cComboGfx.cpp\
            ../gfx_widgets/cEditGfx.cpp\
            ../gfx_widgets/cLabelGfx.cpp\
            ../gfx_widgets/cLabelLinkGfx.cpp\
            ../gfx_widgets/cMesgBoxGfx.cpp\
            ../gfx_widgets/cPopUpMenuGfx.cpp\
            ../gfx_widgets/cProgressBarGfx.cpp\
            ../gfx_widgets/gfx_util.cpp\
            ../TreCore/AlgSupport.cpp\
            ../TreCore/cAlgDefault.cpp\
            ../TreCore/cAlgPythonPlayer.cpp\
            ../TreCore/cAlgPlugin.cpp\
            ../TreCore/cAlgNetClientPlayer.cpp\
            ../TreCore/cCoreEngine.cpp\
            ../TreCore/cGiocata.cpp\
            ../TreCore/cMano.cpp\
            ../TreCore/cMatchPoints.cpp\
            ../TreCore/cMazzo.cpp\
            ../TreCore/cPartita.cpp\
            ../TreCore/CardSpec.cpp\
            ../TreCore/cPlayer.cpp\
            ../TreCore/cPlayersOnTable.cpp\
            ../TreCore/cPlayerStatistic.cpp\
            ../TreCore/cProbality.cpp\
            ../TreCore/PythonExport.cpp\
            ../TreCore/TraceService.cpp\
            ../MySearchAlpha/cAlgABSolver.cpp\
            ../MySearchAlpha/cCardItem.cpp\
            ../MySearchAlpha/cHand.cpp\
            ../MySearchAlpha/cStateAB.cpp\
            ../MySearchAlpha/TrickHistory.cpp\
            StdAfx.cpp

            
            
# set the include path found by configure
AM_CPPFLAGS = $(all_includes) $(LIBSDL_CFLAGS) $(MY_INCLUDES) $(MY_DEFINE)

# the library search path.
tressettetux_LDFLAGS = $(all_libraries) $(LIBSDL_RPATH)
tressettetux_LDADD = $(LIBSDL_LIBS) $(MY_LIBS) $(LIBEXPAT)
