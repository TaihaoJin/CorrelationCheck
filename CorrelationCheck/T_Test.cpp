// T_Test.cpp: implementation of the CT_Test class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PolarizationProfile.h"
#include "T_Test.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CT_Test::CT_Test()
{
	m_nWidth=9;
	m_nLength=14;
	ReadTable();

}

CT_Test::~CT_Test()
{

}

void CT_Test::ReadTable()
{
	int i,j,nTemp,nWidth,nLength;
	float* pfTemp;
	m_pfPvalue=new float[m_nWidth];
	m_pnDf=new int[m_nLength];
	nWidth=9;
	nLength=14;
	FILE* fp=fopen("t_test_table.txt","r");
	fscanf(fp,"%d",&nTemp);
	for(i=0;i<m_nWidth;i++)
	{
		fscanf(fp,"%f",m_pfPvalue+i);
	}

	for(i=0;i<nLength;i++)
	{
		pfTemp=new float[9];
		fscanf(fp,"%d",m_pnDf+i);
		for(j=0;j<nWidth;j++)
		{
			fscanf(fp,"%f",pfTemp+j);
		}
		m_vectpfTvalue.push_back(pfTemp);
	}
	fclose(fp);
}

float CT_Test::GetPValue(int nDf, float fTValue)
{
	float fPValue,fTemp,fTemp1;
	int i,nTemp;
	nTemp=ClosestIndex(nDf);
	fTemp=*(m_vectpfTvalue[nTemp]);
	if(fTemp>fTValue)
	{
		return 1.;
	}
	for(i=0;i<m_nWidth-1;i++)
	{
		fTemp1=*(m_vectpfTvalue[nTemp]+i+1);
		if(fTemp<=fTValue&&fTValue<fTemp1)
		{
			fPValue=1.f-m_pfPvalue[i];
			return fPValue;
		}
		fTemp=fTemp1;
	}
	fPValue=m_pfPvalue[m_nWidth-1];
	return 1.f-fPValue;
}

float CT_Test::GetTValue(int nDf, float fPValue)
{
	float fTValue,fTemp,fTemp1;
	int i,nTemp;
	nTemp=ClosestIndex(nDf);
	fTemp=*(m_pfPvalue);
	if(fTemp>fPValue)
	{
		return 0.f;
	}
	for(i=0;i<m_nWidth-1;i++)
	{
		fTemp1=m_pfPvalue[i+1];
		if(fTemp<=fPValue&&fPValue<fTemp1)
		{
			fTValue=*(m_vectpfTvalue[nTemp]+i);
			return fTValue;
		}
		fTemp=fTemp1;
	}
	fTValue=*(m_vectpfTvalue[nTemp]+m_nWidth-1);
	return fTValue;
}

int CT_Test::ClosestIndex(int nDf)
{
	int i,nTemp;
	for(i=0;i<m_nLength;i++)
	{
		if(nDf>=m_pnDf[i]&&nDf<m_pnDf[i+1])
		{
			nTemp=i;
			return nTemp;
		}
	}
}
