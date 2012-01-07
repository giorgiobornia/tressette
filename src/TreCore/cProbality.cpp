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



//cProbality.cpp
#include "StdAfx.h"
#include "cProbality.h"


////////////////////////////////////////////////////////////////
//   *******************      cProbality CLASS ******************
////////////////////////////////////////////////////////////////



////////////////////////////////////////
//       SvilCombiHands
/*! Develop all possible hands with input deck 
// \param VCT_MAZZO &vct_Mazzo : input deck
*/
void cProbality::SvilCombiHands(VCT_MAZZO &vct_Mazzo)
{
    long lNumCard = vct_Mazzo.size();

    long lNumCombi =  (long)BinomialCoef(lNumCard, m_iCardOnHand);

                       
    if (m_bIndexNotInit)
    {
        m_vctCounter.clear();
                           // inizializza counter
        for (long i = 0; i < m_iCardOnHand; i++)
        {
            m_vctCounter.push_back(i);
        }
    }

    m_bIndexNotInit = false;

                           // riserva spazio per lo sviluppo integrale
    m_mtxAllHands.reserve(lNumCombi);

    VCT_SINGLECARD vct_tmpRow(m_iCardOnHand);
                           // sviluppo delle colonne
    for (long lCurrRow = 0; lCurrRow < lNumCombi; lCurrRow ++)
    {
		long j;
        for ( j = 0; j < m_iCardOnHand; j ++ )
        {
             long lIndex = m_vctCounter[j];
             ASSERT(lIndex < lNumCard && lIndex >= 0);
             vct_tmpRow[j] = vct_Mazzo[lIndex]; 
        }

        m_mtxAllHands.push_back(vct_tmpRow);

        if (lCurrRow == lNumCombi - 1)
        {
                           // ultima colonna, non c'è bisogno di calcolare gli indici
            break;
        }

        long i = 0;
        long lChangeSubIndex = 0;
                           // incrementa gli indici
        for (j = m_iCardOnHand - 1; j >= 0; j-- )
        {
             m_vctCounter[j] ++;
             if (m_vctCounter[j] == lNumCard - i)
             {
                           // indice a fine corsa
                lChangeSubIndex = i + 1;
             }
             else
             {
                break;
             }
             i ++;
        }
                           // aggiorna tutti gli indici
        for (; lChangeSubIndex > 0; lChangeSubIndex --)
        {
             j = m_iCardOnHand - lChangeSubIndex;
             ASSERT( j - 1 >= 0);
             ASSERT(m_vctCounter[j - 1] + 1 < lNumCard);
             m_vctCounter[j] = m_vctCounter[j - 1] + 1;
        }
    }

    Utility::SaveItemToFile(m_mtxAllHands, DEF_path_s, "first_hand.txt"); 

    
}

////////////////////////////////////////
//       CheckBriscFreq
/*! provides a probability value on 1/1000 of the opponent has a min of a briscola
// \param int iIndexBris : index card of briscola
// \param int* piRes : result
*/
void cProbality::CheckBriscFreq(int iIndexBris, int* piRes)
{
    int iMax_i = m_mtxAllHands.size();
    if (iMax_i <= 0 || piRes == 0)
        return;


    int iMax_j = m_mtxAllHands[0].size();
    ASSERT(iMax_j == 3);
    ASSERT(iMax_i > 0);
    int iFreq = 0;

    int iBrisc0 = (iIndexBris / 10) * 10;
    if (iIndexBris == 10)
        iBrisc0 = 0;
    if (iIndexBris == 20)
        iBrisc0 = 10;
    if (iIndexBris == 30)
        iBrisc0 = 20;
    if (iIndexBris == 40)
        iBrisc0 = 30;

    int iBrisc10 = iBrisc0 + 10;

    for (int i = 0; i < iMax_i; i++)
    {
        for (int j = 0; j < iMax_j; j++)
        {
            int iIndexEle = m_mtxAllHands[i][j];
            if (iIndexEle > iBrisc0 && iIndexEle <= iBrisc10)
            {
                iFreq++;
                // search for a minimum of brisc
                break ;
            }
        }
    }
    
    *piRes = iFreq * 1000 / (iMax_i);
}


////////////////////////////////////////
//       Clear
/*! 
*/
void cProbality::Clear()
{
    m_bIndexNotInit = true;
    m_mtxAllHands.clear();
}

////////////////////////////////////////
//       BinomialCoef
/*! Coefficiente binomiale
// \param long lN : numero di elementi
// \param long lK : classe
*/
double cProbality::BinomialCoef(long lN, long lK)
{
   double dResult = 0.0;
   double dNum, dDen;

   dNum = Fattorial(lN);
   dDen = Fattorial(lN - lK) * Fattorial(lK);

   dResult = dNum / dDen;

   return dResult;
}

////////////////////////////////////////
//       Fattorial
/*! Fattoriale di n elementi 
// \param long lN : numero degli elementi
*/
double cProbality::Fattorial(long lN)
{
   double dResult = 1.0;

   for (long i = 0; i < lN - 1; i++)
   {
      dResult *= lN - i;
   }
   
   return dResult;
}

////////////////////////////////////////
//       << 
/*! Dump dello sviluppo in stream
// \param std::ostream &stream : output stream
// \param const MTX_HANDCOMBI &o : 
*/
std::ostream &operator << (std::ostream &stream, const MTX_HANDCOMBI &o)
{
   long lCount = 0;
   int iNumEle = o.size();
   for (long i = 0; i < iNumEle; i++)
   {
      lCount ++;
      VCT_SINGLECARD vct_tmpRow;
      vct_tmpRow = o[i];

      if (lCount < 10)
	  {
         stream <<  " [" << lCount << "] ";
	  }
      else
	  {
         stream <<  "[" << lCount << "] ";
	  }
      
	  int iNumRow = vct_tmpRow.size();
      for (long j = 0; j < iNumRow; j++)
      {
         if (vct_tmpRow[j] < 10)
         {
            stream << " " << ((int) vct_tmpRow[j]) << " "; 
         }
         else
         {
            stream << ((int) vct_tmpRow[j]) << " ";
         }
      }
      stream << std::endl;
   }
   return stream;
}
