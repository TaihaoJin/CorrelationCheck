// T_Test.h: interface for the CT_Test class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_T_TEST_H__4AC79D57_467F_4B0F_953C_108B231C40B9__INCLUDED_)
#define AFX_T_TEST_H__4AC79D57_467F_4B0F_953C_108B231C40B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <vector>
using namespace std;

class CT_Test  
{
public:
	float GetTValue(int nDf, float fPValue);
	float GetPValue(int nDf, float fTValue);
	CT_Test();
	virtual ~CT_Test();
protected:
	int ClosestIndex(int nDf);
	void ReadTable();
	int* m_pnDf;
	float* m_pfPvalue;
	int m_nWidth;
	int m_nLength;
	vector <float*> m_vectpfTvalue;

};

#endif // !defined(AFX_T_TEST_H__4AC79D57_467F_4B0F_953C_108B231C40B9__INCLUDED_)
