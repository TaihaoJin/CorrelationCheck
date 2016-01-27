// Polarization.h: interface for the CPolarization class.

//

//////////////////////////////////////////////////////////////////////



#if !defined(AFX_POLARIZATION_H__4534785F_BC92_40F0_9F94_C67CA9AB38A4__INCLUDED_)
#define AFX_POLARIZATION_H__4534785F_BC92_40F0_9F94_C67CA9AB38A4__INCLUDED_
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MAlign.h"
#include "T_Test.h"
typedef vector <float> FloatVect;
typedef vector <int> IntVect;
typedef vector <double> DoubleVect;
typedef vector <bool> BoolVect;
class CPolarization  

{

public:
	void Cal_Ave_Dev_Hits();
	void OutputProfile(FILE* fpFile);
	void GetFunctionalIndex();
	void GetOptions();
	void OutputPolarization();
	void OutputCorrelation();
	void CalPolarization();
	void CalCorrelation_Pearson();
	void CalCorrelation_SpearMan();

	CPolarization();
	CPolarization(CMAlign cMAlign);
	virtual ~CPolarization();

protected:
	void SortFunctionalIndece();
	void SpearmanCorr(vector<double> vdX, vector <double> vdY, double &d, double &zd,  double &dProbd, double &rs, double &probrs);
	void SortPolarization();
	void Initialization();
	void SortCorrelation();
	void OutputSubstitutionMatrix();
	void CalClusterCorrelation_Pearson();
	void CalClusterCorrelation_Spearman();
	void ConservationScore();
	bool Printable(int i0, int j0);
	float TValue(int nDf, float fCorrelation);
	void ReScaleCorrelation();
	void MaximumPolarization();
	void OutputNumberConversion(FILE* fp);
	void AssignResNumber();
	void OldConservationIndex();
	void ConservationIndex();
	void Sort(float* pfData, int const nSize, int* nOrder);
	vector <float> m_vectfAvePolarization;
	vector <float> m_vectfMaxPolarization;
	vector <IntVect> m_vectnTopPolarization;
	FILE* fpIni;
	vector <IntVect> m_vectnHits;

	vector <IntVect> m_vectnSequence;
		//m_vectnSequence[i][j]: the residue type of the sequence (i) at the position (j) of the alignment.
		//0 indicates deletion
	vector <IntVect> m_vectnResidueNumber;
		//m_vectnResidueNumber[i][j]: the residue number (without counting the deletion) of the sequence
		//(i) the the position (j) of the alignment
	vector <float*> m_vectfCoordinates;
		//Each element (float*) holds the numerical value of 20 residue types that discribe a 
		//particular physical-chemical property (charge, hydrophobicity, etc.).
		//Its size equals to the number of different physical-chemical properties of residues taken into account.
	vector <CString> m_vectsPropertyName;
		//Charges, volume, etc...
	CMAlign m_cMAlign;
	vector <float> m_vectfFunctionalIndex;
		//Its size equals to the number of sequences in the sequences alignment file.
	vector <int> m_vectnCount;
		//Its elements contain 0 or 1. 1 indicates that the sequence in the multiple alignment should be 
		//taken in to account, while a 0 indicates that the sequence should not be counted in the 
		//calculations (usually because its functional index was not determined)
		//Its size equals to the number of sequences in the sequences alignment file.
	vector <FloatVect> m_vectfPolarization;
		//m_vectfPolarization[i][j]: Polarization of a particular physical-chemical property (i) at
		//the position (j) in the mutiple sequence alignment.
	vector <FloatVect> m_vectfCorrelation;
		//m_vectfPolarization[i][j]: correlation of a particular physical-chemical property (i) at
		//the position (j) in the mutiple sequence alignment.
	vector <float> m_vectfConservationScore;
		//Calculated for the sequence substitution matrix. Lower m_vectfConservationScore[i] indicates
		//the sequence is highly conserved at the position (i) of the alignment.
	vector <float> m_vectfClusterCorrelation;
	float m_fDevFunctionalIndex;
	float m_fRescalingFactor;
	int m_nNumOfSequences;
	int m_nSeqLength;
	int m_nPropertyDim;
	float m_fFactor;
	float m_fPValue;
	int m_nHits;
		//the cutoff value of the hit value
	int m_nDf;
	int m_nNumberIndex;
	vector <IntVect> m_vectnCorrelationOrder;
		//m_vectnCorrelationOrder[i][j]: the ranking (desending) of correlation between the functional
		//index and the physical-chemical property (i) at the position (j) of the alignment.
	vector <IntVect> m_vectnPolarizationOrder;
		//m_vectnPolarizationOrder[i][j]: the ranking (desending) of polarization the physical-chemical property (i) at the position (j) of the alignment.
	bool m_bPolarization;
	bool m_bCorrelation;
	bool m_bBrief;
	bool m_bRescaled;
	bool m_bpValue;
	bool m_brValue;
	bool m_bDetailed;
	bool m_bPearson;
	bool m_bSpearman;
	vector <float> m_vectfOutputCutoff;
	vector <CString> m_vectsSeqNames;
	int m_fSubstitutionMatrix[21][21];
	vector <FloatVect> m_vectfConservationIndex;
	float* m_pfMaxPolarization;
	vector <FloatVect> m_vectfDevCoordinate;
	vector <FloatVect> m_vectfAveCoordinate;
	vector <float> m_vectfMaxDevCoordinate;
	bool* m_pbDeletion;
	CT_Test m_cT_Test;

	vector <DoubleVect> m_vdD;
	vector <DoubleVect> m_vdZd;
	vector <DoubleVect> m_vdProbd;
	vector <DoubleVect> m_vdRs;
	vector <DoubleVect> m_vdProbrs;
	vector <BoolVect> m_vbConserved;
	vector <int> m_vnFunctionalIndexOrder;
};



#endif // !defined(AFX_POLARIZATION_H__4534785F_BC92_40F0_9F94_C67CA9AB38A4__INCLUDED_)

