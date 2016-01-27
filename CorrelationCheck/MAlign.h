// MAlign.h: interface for the CMAlign class.

//

//////////////////////////////////////////////////////////////////////



#if !defined(AFX_MALIGN_H__E5274611_F36A_4466_9119_8CEC45E9746A__INCLUDED_)

#define AFX_MALIGN_H__E5274611_F36A_4466_9119_8CEC45E9746A__INCLUDED_



#if _MSC_VER > 1000

#pragma once

#endif // _MSC_VER > 1000

#include "stdafx.h"

#include <string>

#include <vector>

using namespace std;

typedef vector <int> IntVect;



class CMAlign  

{

public:

	void IntSequences();

	void OutputMAlign();

	CMAlign();

	void ReadMAlign();

	virtual ~CMAlign();

	vector <IntVect> Get_nSeq();

private:

	int m_nSeqLength;

	int m_nNumOfSeq;

	vector <string> m_vectsSeqNames;
	vector <string> m_vectsSequence;
	vector <IntVect> m_vectnSequence;

protected:

	bool IsChannelName(char aString[80]);

	CString m_sMAlignFileName;

	char m_sAminoAcidNames[21];

};



#endif // !defined(AFX_MALIGN_H__E5274611_F36A_4466_9119_8CEC45E9746A__INCLUDED_)

