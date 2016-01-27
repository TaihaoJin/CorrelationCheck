// Polarization.cpp: implementation of the CPolarization class.

//

//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PolarizationProfile.h"
#include "math.h"
#include "Polarization.h"
#include "OutputCutoffDialog.h"
#include "nr.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


//////////////////////////////////////////////////////////////////////

// Construction/Destruction

//////////////////////////////////////////////////////////////////////

CPolarization::CPolarization()
{
}


CPolarization::CPolarization(CMAlign cMAlign)
{
	//".0 A1 C2 D3 E4 F5 G6 H7 I8 K9 L10 M11 N12 P13 Q14 R15 S16 T17 V18 W19 Y20");
	int i,j;

	m_cMAlign=cMAlign;
	CString sName;
	m_bCorrelation=true;
	m_bPolarization=false;
	m_bSpearman=true;
	m_bPearson=false;

	m_vectnSequence=m_cMAlign.Get_nSeq();
//	sName="Charge:";
//	float fCharge[21]={0,0,0,-1,-1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0};
//	m_vectfCoordinates.push_back(fCharge);
//	m_vectsPropertyName.push_back(sName);

//	float fBetaCarbon[21]={-1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1};
//	float fBetaCarbon[21]={0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0};
//	m_vectfCoordinates.push_back(fBetaCarbon);
//	sName="BetaCarbon:";
//	m_vectsPropertyName.push_back(sName);

//	float fHydrophobicity[21]={0,1,1,-1,-1,1,0,-1,1,-1,1,1,-1,1,-1,-1,-1,-1,1,1,-1};
//	float fHydrophobicity[21]={0,-0.50f, 0.02f, -3.64f, -3.63f, 1.71f,  -1.15f,  -2.33f,  1.12f, -2.80f,  1.25f, 0.67f, -0.85f, -0.14f, -0.77f, -1.81f, -0.46f, -0.25f, 0.46f, 2.09f, 0.71f};
//	float fHydrophobicity[21]={0.,0.0, 0., -1., -1., 2.f,  -0.f,  -1.f,  2.f, -1.f,  2.f, 1.f, 0.f, 0.f, 0.f, -1.f, 0.f, 0.f, 1.f, 2.0f, 1.f};
//	m_vectfCoordinates.push_back(fHydrophobicity);
//	sName="Hydrophobicity:";
//	m_vectsPropertyName.push_back(sName);

	//".0 A1 C2 D3 E4 F5 G6 H7 I8 K9 L10 M11 N12 P13 Q14 R15 S16 T17 V18 W19 Y20");
//	float fSize[21]={0,2,5,5,6,9,1,10,4,7,4,5,5,5,6,8,3,4,3,12,10};
//	float fSize[21]={0.f,54.70f, 67.71f, 68.56f, 84.0f, 116.06f, 37.5f, 93.06f, 99.86f, 105.7f, 113.16f, 99.62f, 71.56f, 74.80f, 88.16f, 121.2f, 54.95f, 71.12f, 99.13f, 138.16f, 118.0f};
//	float fSize[21]={0.f,-1.0f, 0.0f, 0.f, 1.0f, 2.0f, -1.f, 1.0f, 1.f, 2.f, 2.f, 1.0f, 0.0f, 0.0f, 1.f, 2.f, -1.f, 0.f, 1.f, 2.f, 2.0f};
//	m_vectfCoordinates.push_back(fSize);
//	sName="Volume:";
//	m_vectsPropertyName.push_back(sName);


//	float fProline[21]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,-1};
//	m_vectfCoordinates.push_back(fProline);
//	sName="Proline:";
//	m_vectsPropertyName.push_back(sName);



//	float fCystein[21]={-1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
//	m_vectfCoordinates.push_back(fCystein);
//	sName="Cystein:";
//	m_vectsPropertyName.push_back(sName);

//	float fAramoticity[21]={-1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1};
//	m_vectfCoordinates.push_back(fAramoticity);
//	sName="Aromaticity:";
//	m_vectsPropertyName.push_back(sName);

//	float fHydrogen[21]={0,-1,-1,1,1,-1,-1,1,-1,1,-1,-1,1,-1,1,1,1,1,-1,1,1};
//	m_vectfCoordinates.push_back(fHydrogen);
//	sName="Hydrogen";
//	m_vectsPropertyName.push_back(sName);

	Initialization();


//	float fFunctionalIndex[15]={0.01,0.01,0.01,0.01,0.36,0.34,0.26,0.16,0.10,1.0,0.07,0.00,0.06,0.062,0.014};
	float fFunctionalIndex[15]={-1,-1,-1,-1,1,1,0,0,0,1,-1,0,-1,-1,-1};
//	float fFunctionalIndex[15]={1,1,1,1,0,0,0,0,0,0,0,0,0,0,0};
//	int nCount[15]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

//	float PIP2Int[15]={0f,0f,0f,0.01f,0,36f,0.34f,0.25f,0.05f,0.12f,1.0f,0.31f,0f,0f,0.062f,0.014f};
	int nPIP2Int[15]={0,0,0,5,2,2,2,4,3,1,2,0,0,4,5};
	int nPIP2IntCount[15]={0,0,0,1,1,1,1,1,1,1,1,0,0,1,1};

	int nPIP2Specificity[15]={0,0,0,3,2,1,2,2,1,1,2,0,0,4,2};
	int nPIP2SpecificityCount[15]={0,0,0,1,1,1,1,1,1,1,1,0,0,1,1};

	int nPIP2_34[15]={0,0,0,3,1,1,1,1,1,1,1,0,0,4,1};
	int nCount_34[15]={0,0,0,1,1,1,1,1,1,1,1,0,0,1,1};

	int nPIP2_35[15]={0,0,0,3,2,1,2,3,1,1,2,0,0,4,2};
	int nCount_35[15]={0,0,0,1,1,1,1,1,1,1,1,0,0,1,1};

	int nPIP2_345[15]={0,0,0,3,2,1,2,3,1,1,2,0,0,4,2};
	int nCount_345[15]={0,0,0,1,1,1,1,1,1,1,1,0,0,1,1};

	int PMAInhibition[15]={3,0,0,3,1,1,3,3,1,1,2,0,0,3,3};
	int nCount_PMA[15]={1,0,0,1,1,1,1,1,1,1,1,0,0,1,1};

	int M1Inhibition[15]={4,0,0,4,1,1,2,3,1,1,2,0,0,4,3};
	int nCount_M1[15]={1,0,0,1,1,1,1,1,1,1,1,0,0,1,1};


//	for(i=0;i<15;i++)
//	{
//		nCount[i]=nCount_M1[i];
//		m_vectfFunctionalIndex.push_back(float(nPIP2Int[i]));
//	}

//	nCount[14]=0;
	GetFunctionalIndex();
	m_nPropertyDim=m_vectfCoordinates.size();

	m_nSeqLength=m_vectnSequence[0].size();
	m_pbDeletion=new bool[m_nSeqLength];
	for(i=0;i<m_nSeqLength;i++)
	{
		m_pbDeletion[i]=false;
	}

	int nSubstitutionMatrix[21][21]={
		-20,-60,-60,-60,-60,-60,-60,-60,-60,-60,-60,-60,-60,-60,-60,
		-60,-60,-60,-60,-60,-60,
		-60,2,-2,0,0,-4,1,-1,-1,-1,-2,-1,0,1,0,-2,1,1,0,-6,-3,
		-60,-2,12,-5,-5,-4,-3,-3,-2,-5,-6,-5,-4,-3,-5,-4,0,-2,-2,-8,0,
		-60,0,-5,4,3,-6,1,1,-2,0,-4,-3,2,-1,2,-1,0,0,-2,-7,-4,
		-60,0,-5,3,4,-5,0,1,-2,0,-3,-2,1,-1,2,-1,0,0,-2,-7,-4,
		-60,-4,-4,-6,-5,9,-5,-2,1,-5,2,0,-4,-5,-5,-4,-3,-3,-1,0,7,
		-60,1,-3,1,0,-5,5,-2,-3,-2,-4,-3,0,-1,-1,-3,1,0,-1,-7,-5,
		-60,-1,-3,1,1,-2,-2,6,-2,0,-2,-2,2,0,3,2,-1,-1,-2,-3,0,
		-60,-1,-2,-2,-2,1,-3,-2,5,-2,2,2,-2,-2,-2,-2,-1,0,4,-5,-1,
		-60,-1,-5,0,0,-5,-2,0,-2,5,-3,0,1,-1,1,3,0,0,-2,-3,-4,
		-60,-2,-6,-4,-3,2,-4,-2,2,-3,6,4,-3,-3,-2,-3,-3,-2,2,-2,-1,
		-60,-1,-5,-3,-2,0,-3,-2,2,0,4,6,-2,-2,-1,0,-2,-1,2,-4,-2,
		-60,0,-4,2,1,-4,0,2,-2,1,-3,-2,2,-1,1,0,1,0,-2,-4,-2,
		-60,1,-3,-1,-1,-5,-1,0,-2,-1,-3,-2,-1,6,0,0,1,0,-1,-6,-5,
		-60,0,-5,2,2,-5,-1,3,-2,1,-2,-1,1,0,4,1,-1,-1,-2,-5,-4,
		-60,-2,-4,-1,-1,-4,-3,2,-2,3,-3,0,0,0,1,6,0,-1,-2,2,-4,
		-60,1,0,0,0,-3,1,-1,-1,0,-3,-2,1,1,-1,0,2,1,-1,-2,-3,
		-60,1,-2,0,0,-3,0,-1,0,0,-2,-1,0,0,-1,-1,1,3,0,-5,-3,
		-60,0,-2,-2,-2,-1,-1,-2,4,-2,2,2,-2,-1,-2,-2,-1,0,4,-6,-2,
		-60,-6,-8,-7,-7,0,-7,-3,-5,-3,-2,-4,-4,-6,-5,2,-2,-5,-6,17,0,
		-60,-3,0,-4,-4,7,-5,0,-1,-4,-1,-2,-2,-5,-4,-4,-3,-3,-2,0,10};

	for(i=0;i<21;i++)
	{
		for(j=0;j<21;j++)
		{
			m_fSubstitutionMatrix[i][j]=float(nSubstitutionMatrix[i][j]);
		}
	}
	OutputSubstitutionMatrix();
	GetOptions();
	CT_Test m_cT_test;
	AssignResNumber();
	m_fFactor=2.5f;
	OldConservationIndex();
	if(m_bPolarization)
	{
		CalPolarization();
		SortPolarization();
		OutputPolarization();
	}
	else if(m_bCorrelation)
	{
		if(m_bSpearman)
		{
			CalCorrelation_SpearMan();
			Cal_Ave_Dev_Hits();
			ConservationScore();
			CalClusterCorrelation_Spearman();
			if(m_bRescaled)
				ReScaleCorrelation();
			SortCorrelation();
			SortFunctionalIndece();
			OutputCorrelation();
		}
		else if(m_bPearson)
		{
			CalCorrelation_Pearson();
			ConservationScore();
			CalClusterCorrelation_Pearson();
			if(m_bRescaled)
				ReScaleCorrelation();
			SortCorrelation();
			SortFunctionalIndece();
			OutputCorrelation();
		}
	}
}



CPolarization::~CPolarization()
{
}


void CPolarization::CalPolarization()
{
	int i,j,k;
	float fTemp=0.f;
	for(i=0;i<m_nPropertyDim;i++)
	{
		m_vectfAvePolarization.push_back(0.0f);
		vector <float> fVector;
		float fMaxPolarization=0.0f;
		for(j=0;j<m_nSeqLength;j++)
		{
			float fCoordinate=0.0f;
			int nCount=0;
			for(k=0;k<m_nNumOfSequences;k++)
			{
				int nTemp=m_vectnSequence[k].at(j);
				float fTemp1=*(m_vectfCoordinates[i]+nTemp);
				int nTemp2=m_vectnCount[k];
				nCount+=nTemp2;
				fCoordinate+=fTemp1;
				if(nTemp==0) m_pbDeletion[j]=true;
				//Position j in the alignment contain at least a deletion (insertion)
			}
			//nCount and fCoordinate are calculated
			//Isn't nCount a fixed number? why it is calculated at every position (j)?


			float fPolarization=0.0f;
			for(k=0;k<m_nNumOfSequences;k++)
			{
				int nTemp=m_vectnSequence[k].at(j);
				float fTemp1=*(m_vectfCoordinates[i]+nTemp);
				int nTemp2=m_vectnCount[k];
				float fTemp=m_vectfFunctionalIndex[k];
				fPolarization+=fTemp*fTemp1*float(nTemp2);
			}
//			fPolarization=fabs(fPolarization);
			fTemp=m_vectfConservationIndex[i].at(j);
//			fPolarization/=fTemp;
			fVector.push_back(fPolarization);
			m_vectfAvePolarization[i]+=fPolarization;
			if(fabs(fPolarization)>fMaxPolarization)
			{
				fMaxPolarization=fabs(fPolarization);
			}
		}
		m_vectfPolarization.push_back(fVector);
		m_vectfMaxPolarization.push_back(fMaxPolarization);
		m_vectfAvePolarization[i]/=float(m_nSeqLength);

	}
}

void CPolarization::CalCorrelation_SpearMan()
{
	int i,j,k,nTemp,nTemp2;
	double dTemp=0.f;
	double dMaxCorr=0.;
	double dMinCorr=0.;
	double dTol=0.000001;
	vector<double> vdX; 
	vector <double> vdY; 

	double d, zd, dProbd, rs, probrs;

	for(k=0;k<m_nNumOfSequences;k++)
	{
		nTemp2=m_vectnCount[k];
		if(nTemp2!=0)
		{
			vdY.push_back(m_vectfFunctionalIndex[k]);
		}
	}

	int nYSize=vdY.size();
	int nXSize=vdX.size();

	for(i=0;i<m_nPropertyDim;i++)
	{
		vector <float>  fVector;
		vector <double> vdD;
		vector <double> vdZd;
		vector <double> vdProbd;
		vector <double> vdRs;
		vector <double> vdProbrs;
		vector <bool> vbConserved;
		for(j=0;j<m_nSeqLength;j++)
		{
			vdX.clear();
			dMaxCorr=-1.e99;
			dMinCorr=1.e99;
			for(k=0;k<m_nNumOfSequences;k++)
			{
				nTemp2=m_vectnCount[k];
				if(nTemp2!=0)
				{
					nTemp=m_vectnSequence[k].at(j);
//					dTemp=m_vectfCoordinates[i][nTemp]*double(nTemp2);
					dTemp=m_vectfCoordinates[i][nTemp];
					if(dTemp<dMinCorr)
					{
						dMinCorr=dTemp;
					}
					else if(dTemp>dMaxCorr)
					{
						dMaxCorr=dTemp;
					}
					vdX.push_back(dTemp);
				}
			}
			nXSize=vdX.size();
			SpearmanCorr(vdX, vdY, d, zd, dProbd, rs, probrs);
			vdD.push_back(d);
			vdZd.push_back(zd);
			vdProbd.push_back(dProbd);
			vdRs.push_back(rs);
			vdProbrs.push_back(probrs);
			fVector.push_back(rs);
			bool bConserved=false;
			if(fabs(dMaxCorr-dMinCorr)<dTol)
			{
				bConserved=true;
			}
			vbConserved.push_back(bConserved);
		}
		m_vdD.push_back(vdD);
		m_vdZd.push_back(vdZd);
		m_vdProbd.push_back(vdProbd);
		m_vdRs.push_back(vdRs);
		m_vdProbrs.push_back(vdProbrs);
		m_vectfCorrelation.push_back(fVector);
		m_vbConserved.push_back(vbConserved);
	}
}

void CPolarization::CalCorrelation_Pearson()
{
	int i,j,k,nTemp,nCount,nTemp2;
	float fTemp=0.f,fAveCoordinate=0.f,fAveFunctionalIndex=0.f,fCorrelation,fTemp1;
	float fDevCoordinate;
	float fMaxDevCoordinate=-100000000.f;
	int nHits[2];
	for(i=0;i<m_nPropertyDim;i++)
	{
		vector <float> fVector;
		vector <float> vectfDevfCoordinate;
		vector <float> vectfAvefCoordinate;
		vector <int> vectnHits;
		fMaxDevCoordinate=-10000000.f;
		for(j=0;j<m_nSeqLength;j++)
		{
			fAveCoordinate=0.f;
			nCount=0;
			for(k=0;k<m_nNumOfSequences;k++)
			{
				nTemp=m_vectnSequence[k].at(j);
				nTemp2=m_vectnCount[k];
				fTemp=*(m_vectfCoordinates[i]+nTemp)*float(nTemp2);
				nCount+=nTemp2;
				if(nTemp==0) m_pbDeletion[j]=true;
				fAveCoordinate+=fTemp;
			}
			fAveCoordinate/=float(nCount);
			vectfAvefCoordinate.push_back(fAveCoordinate);

			fCorrelation=0.0f;
			fDevCoordinate=0.f;

			for(k=0;k<2;k++)
			{
				nHits[k]=0;
			}

			for(k=0;k<m_nNumOfSequences;k++)
			{
				nTemp2=m_vectnCount[k];
				if(nTemp2==1)
				{
					nTemp=m_vectnSequence[k].at(j);
					fTemp=(*(m_vectfCoordinates[i]+nTemp)-fAveCoordinate)*float(nTemp2);
					fTemp1=m_vectfFunctionalIndex[k]*fTemp;
					fCorrelation+=fTemp1;
					if(fTemp1>0.0001)
					{
						nHits[0]++;
					}
					else if(fTemp1<-0.0001)
//					else
					{
						nHits[1]++;
					}
//					fDevCoordinate+=(fTemp-fAveCoordinate)*fTemp;
					fDevCoordinate+=fTemp*fTemp;
				}
			}
			vectfDevfCoordinate.push_back(fDevCoordinate);
			if(fDevCoordinate>0.00001)
			{
				fCorrelation/=sqrt(fDevCoordinate);
				fCorrelation/=sqrt(m_fDevFunctionalIndex);
				fVector.push_back(fCorrelation);
			}
			else
			{
				fVector.push_back(0.f);
			}
			if(fDevCoordinate>fMaxDevCoordinate)
			{
				fMaxDevCoordinate=fDevCoordinate;
			}

			if(fCorrelation>0)
			{
				vectnHits.push_back(nHits[0]-nHits[1]);
			}
			else
			{
				vectnHits.push_back(nHits[1]-nHits[0]);
			}

		}
		m_vectfCorrelation.push_back(fVector);
		m_vectfDevCoordinate.push_back(vectfDevfCoordinate);
		m_vectfAveCoordinate.push_back(vectfAvefCoordinate);
		m_vectfMaxDevCoordinate.push_back(fMaxDevCoordinate);
		m_vectnHits.push_back(vectnHits);
	}
}

void CPolarization::OutputPolarization()
{
	FILE* fpFile;
	char AminoAcid[22]=".ACDEFGHIKLMNPQRSTVWY";
	char* pch="Polarization File (*.plr)\0*.plr\0\0\0";
	CFileDialog aFileDlg( false, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT|OFN_EXPLORER|OFN_ENABLESIZING, NULL, NULL );
	aFileDlg.m_ofn.lpstrFilter=pch;
	int i,j,nTemp;
	if(aFileDlg.DoModal()==IDOK)
	{
//		GetSeqNames();
		fpFile=fopen(aFileDlg.GetPathName(),"w");
		fprintf(fpFile,"Functional Index:\n");
		for (i=0;i<m_nNumOfSequences;i++)
		{
			CString astring;
			astring=m_vectsSeqNames[i];
			fprintf(fpFile,"%12s %12.3f %2d\n",astring,m_vectfFunctionalIndex[i]*float(m_vectnCount[i]), m_vectnCount[i]);
		}
		fprintf(fpFile,"\n\n");

		fprintf(fpFile,"Count:\n");
		for (i=0;i<m_nNumOfSequences;i++)
		{
			fprintf(fpFile," %5d",m_vectnCount[i]);
		}
		fprintf(fpFile,"\n\n");

		for (i=0;i<m_nPropertyDim;i++)
		{
			fprintf(fpFile,"  %s  (Cutoff:%4.2f)\n",m_vectsPropertyName[i],m_vectfOutputCutoff[i]);
			for(j=0;j<7;j++)
			{
				fprintf(fpFile,"   %c%6.2f",AminoAcid[j],*(m_vectfCoordinates[i]+j));
			}
			fprintf(fpFile,"\n");
			for(j=7;j<14;j++)
			{
				fprintf(fpFile,"   %c%6.2f",AminoAcid[j],*(m_vectfCoordinates[i]+j));
			}
			fprintf(fpFile,"\n");
			for(j=14;j<21;j++)
			{
				fprintf(fpFile,"   %c%6.2f",AminoAcid[j],*(m_vectfCoordinates[i]+j));
			}
			fprintf(fpFile,"\n\n");
			for(j=0;j<m_nSeqLength;j++)
			{
				nTemp=m_vectnPolarizationOrder[i].at(j);
				float fPolarization=m_vectfPolarization[i].at(nTemp)/fabs(m_vectfMaxPolarization[i]);
				if(fabs(fPolarization)>m_vectfOutputCutoff[i])
				{
					int nG4=m_vectnResidueNumber[m_nNumberIndex].at(nTemp);
					fprintf(fpFile,"%8d  ",nG4);
					for(int k=0;k<m_nPropertyDim;k++)
					{
							float fTemp=m_vectfPolarization[k].at(nTemp);
//							fprintf(fpFile," %5.3f ",m_vectfPolarization[k].at(j));
							fprintf(fpFile," %8.3f ",fTemp);
//							fprintf(fpFile," %5.3f ",m_vectfPolarization[k].at(j)*m_vectfConservationIndex[k].at(j));
//							fprintf(fpFile," %5.3f ",m_vectfConservationIndex[k].at(j));
					}
					fprintf(fpFile,"\n");
				}
			}
			fprintf(fpFile,"\n\n");
		}

		for(i=0;i<m_nSeqLength;i++)
		{
			int nG1=m_vectnResidueNumber[0].at(i);
			int nG2=m_vectnResidueNumber[1].at(i);
			int nG3=m_vectnResidueNumber[2].at(i);
			int nG4=m_vectnResidueNumber[m_nNumberIndex].at(i);
			fprintf(fpFile,"%8d  ",nG4);
			for(j=0;j<m_nPropertyDim;j++)
			{
//				fprintf(fpFile,"  %8.5f  ",m_vectfPolarization[j].at(i)/m_vectfMaxPolarization[j]);
						fprintf(fpFile," %8.3f ",m_vectfPolarization[j].at(i));
//						fprintf(fpFile," %5.3f ",m_vectfPolarization[j].at(i)*m_vectfConservationIndex[j].at(i));
//						fprintf(fpFile," %5.3f ",m_vectfConservationIndex[j].at(i));
			}
			fprintf(fpFile,"\n");
		}

//		OutputNumberConversion(fpFile);
		fclose(fpFile);
	}
}



void CPolarization::OutputCorrelation()
{
	FILE* fpFile;
	char AminoAcid[22]=".ACDEFGHIKLMNPQRSTVWY";
	char* pch="Correlation File (*.cor)\0*.cor\0\0\0";
	CFileDialog aFileDlg( false, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT|OFN_EXPLORER|OFN_ENABLESIZING, NULL, NULL );
	aFileDlg.m_ofn.lpstrFilter=pch;
	int i,j,k,nTemp,nCountT,nTemp1,nTemp2;
	bool bPrintDetail=!m_bBrief;
	float fPvalue;
	if(aFileDlg.DoModal()==IDOK)
	{
		fpFile=fopen(aFileDlg.GetPathName(),"w");
		fprintf(fpFile,"Functional Index:\n");
		nCountT=0;
		
		vector <CString> vsNames;
		vector <float> vfFunctionalIndex;
		vector <int> vnCount;

		for(i=0;i<m_nNumOfSequences;i++)
		{
			nTemp=m_vnFunctionalIndexOrder[i];
			if(m_vectnCount[nTemp]!=0)
			{
				CString astring=m_vectsSeqNames[nTemp];
				vsNames.push_back(astring);
				vfFunctionalIndex.push_back(m_vectfFunctionalIndex[nTemp]);
				vnCount.push_back(m_vectnCount[nTemp]);
			}
		}

		for (i=0;i<m_nNumOfSequences;i++)
		{
			CString astring;
			astring=m_vectsSeqNames[i];
			fprintf(fpFile,"%12s %12.3f %2d",astring,m_vectfFunctionalIndex[i]*float(m_vectnCount[i]), m_vectnCount[i]);
			nCountT+=m_vectnCount[i];

			if(i<vsNames.size())
			{
				astring=vsNames[i];
				fprintf(fpFile,"    %12s %12.3f %2d",astring,vfFunctionalIndex[i], vnCount[i]);
			}
			fprintf(fpFile,"\n");
		}
		fprintf(fpFile,"\n\n");

		float fTemp,fTemp1;
		fprintf(fpFile,"Df: %5d\n\n",nCountT-2);
		int nDf=nCountT-2;
		m_nDf=nDf;

		fprintf(fpFile,"r:  ");
		for (i=0;i<10;i++)
		{
			fTemp=0.05*float(i)+0.05;
			fprintf(fpFile," %6.3f",fTemp);
		}
		fprintf(fpFile,"\n");
		fprintf(fpFile,"t:  ");
		for (i=0;i<10;i++)
		{
			fTemp=0.05*float(i)+0.05;
			fTemp1=fTemp*sqrt(nCountT-2);
			fTemp1/=sqrt(1.f-fTemp*fTemp);
			fprintf(fpFile," %6.3f",fTemp1);
		}
		fprintf(fpFile,"\n");
		fprintf(fpFile,"p:  ");
		for (i=0;i<10;i++)
		{
			fTemp=0.05*float(i)+0.05;
			fTemp1=fTemp*sqrt(nCountT-2);
			fTemp1/=sqrt(1.f-fTemp*fTemp);
			fPvalue=m_cT_Test.GetPValue(nDf,fTemp1);
			fprintf(fpFile," %6.3f",fPvalue);
		}

		fprintf(fpFile,"\n\n");
		fprintf(fpFile,"r:  ");
		for (i=0;i<9;i++)
		{
			fTemp=0.05*float(i)+0.55;
			fprintf(fpFile," %6.3f",fTemp);
		}
		fprintf(fpFile,"\n");
		fprintf(fpFile,"t:  ");
		for (i=0;i<9;i++)
		{
			fTemp=0.05*float(i)+0.55;
			fTemp1=fTemp*sqrt(nCountT-2);
			fTemp1/=sqrt(1.f-fTemp*fTemp);
			fprintf(fpFile," %6.3f",fTemp1);
		}
		fprintf(fpFile,"\n");
		fprintf(fpFile,"p:  ");
		for (i=0;i<9;i++)
		{
			fTemp=0.05*float(i)+0.55;
			fTemp1=fTemp*sqrt(nCountT-2);
			fTemp1/=sqrt(1.f-fTemp*fTemp);
			fPvalue=m_cT_Test.GetPValue(nDf,fTemp1);
			fprintf(fpFile," %6.3f",fPvalue);
		}
		fprintf(fpFile,"\n");
		fprintf(fpFile,"\n");

		for (i=0;i<m_nPropertyDim;i++)
		{
			fprintf(fpFile,"  %s  (Cutoff:%4.2f",m_vectsPropertyName[i],m_vectfOutputCutoff[i]);
			if(m_bRescaled) 
				fprintf(fpFile,", Rescaled: sqrt(dev/(dev+%3.2f*(%6.3f-dev))",m_fRescalingFactor,m_vectfMaxDevCoordinate[i]);
			fprintf(fpFile,")\n");
			for(j=0;j<7;j++)
			{
				fprintf(fpFile,"  %c%6.1f",AminoAcid[j],*(m_vectfCoordinates[i]+j));
			}
			fprintf(fpFile,"\n");
			for(j=7;j<14;j++)
			{
				fprintf(fpFile,"  %c%6.1f",AminoAcid[j],*(m_vectfCoordinates[i]+j));
			}
			fprintf(fpFile,"\n");
			for(j=14;j<21;j++)
			{
				fprintf(fpFile,"  %c%6.1f",AminoAcid[j],*(m_vectfCoordinates[i]+j));
			}
			fprintf(fpFile,"\n\n");
			float fCorrelation;
			double dProb;
			for(j=0;j<m_nSeqLength;j++)
			{
				nTemp=m_vectnCorrelationOrder[i].at(j);
				fCorrelation=m_vectfCorrelation[i].at(nTemp);
				if(m_bSpearman)
				{
					dProb=m_vdProbrs.at(i)[nTemp];
				}
				else
				{
					dProb=m_cT_Test.GetPValue(nDf,TValue(nDf,fCorrelation));
				}
				if(Printable(i,nTemp))
				{
					int nG4=m_vectnResidueNumber[m_nNumberIndex].at(nTemp);
					fprintf(fpFile,"%8d  ",nG4);
					fprintf(fpFile," %8.3f  %8.3f  %3d ",fCorrelation,dProb,m_vectnHits[i].at(nTemp));
//					fprintf(fpFile," %8.3f  %8.3f  %3d  %8.3f   ",fCorrelation,m_cT_Test.GetPValue(nDf,TValue(nDf,fCorrelation)),m_vectnHits[i].at(nTemp),m_vectfConservationScore[nTemp]);
					for(k=0;k<m_nNumOfSequences;k++)
					{
						nTemp1=m_vectnSequence[k].at(nTemp);
						fprintf(fpFile,"%c",AminoAcid[nTemp1]);
					}
					fprintf(fpFile,"        ");
					for(k=0;k<m_nNumOfSequences;k++)
					{
						nTemp2=m_vnFunctionalIndexOrder[k];
						if(m_vectnCount[nTemp2]!=0)
						{
							nTemp1=m_vectnSequence[nTemp2].at(nTemp);
							fprintf(fpFile,"%c",AminoAcid[nTemp1]);
						}
					}
					fprintf(fpFile,"\n");
					if(bPrintDetail)
					{
						fprintf(fpFile,"\n");

						fprintf(fpFile,"                   %6.2f",sqrt(m_fDevFunctionalIndex));
						for(int k=0;k<m_nNumOfSequences;k++)
						{
							fprintf(fpFile," %6.2f",m_vectfFunctionalIndex[k]);
						}
						fprintf(fpFile,"\n");
						fprintf(fpFile,"                   %6.2f",sqrt(m_vectfDevCoordinate[i].at(nTemp)));
						for(k=0;k<m_nNumOfSequences;k++)
						{
							nTemp=m_vectnSequence[k].at(j);
							fprintf(fpFile," %6.2f",*(m_vectfCoordinates[i]+nTemp)-m_vectfAveCoordinate[i].at(nTemp));
						}
						fprintf(fpFile,"\n");
					}
				}
			}
			fprintf(fpFile,"                                   ");
			for(int k=0;k<m_nNumOfSequences;k++)
			{
				nTemp1=m_vectnCount[k];
				fprintf(fpFile,"%d",nTemp1);
			}
			fprintf(fpFile,"\n\n");
		}

		fprintf(fpFile,"\n\n");
			fprintf(fpFile,"  Substitution:  (Cutoff:%4.2f",m_vectfOutputCutoff[i-1]);
			if(m_bRescaled) 
				fprintf(fpFile,", Reslaced: sqrt(dev/(dev+%3.2f*(%6.3f-dev))",m_fRescalingFactor,m_vectfMaxDevCoordinate[i]);
			fprintf(fpFile,")\n\n");
		for(j=0;j<m_nSeqLength;j++)
		{
			nTemp=m_vectnCorrelationOrder[i].at(j);
			float fCorrelation=m_vectfCorrelation[i].at(nTemp);
			if(Printable(i,nTemp))
			{
				int nG4=m_vectnResidueNumber[m_nNumberIndex].at(nTemp);
				fprintf(fpFile,"%8d  ",nG4);
				fprintf(fpFile," %8.3f  %8.3f ",fCorrelation,m_cT_Test.GetPValue(nDf,TValue(nDf,fCorrelation)));
				for(int k=0;k<m_nNumOfSequences;k++)
				{
					nTemp1=m_vectnSequence[k].at(nTemp);
					fprintf(fpFile,"%c",AminoAcid[nTemp1]);
				}

				fprintf(fpFile,"        ");
				for(k=0;k<m_nNumOfSequences;k++)
				{
					nTemp2=m_vnFunctionalIndexOrder[k];
					if(m_vectnCount[nTemp2]!=0)
					{
						nTemp1=m_vectnSequence[nTemp2].at(nTemp);
						fprintf(fpFile,"%c",AminoAcid[nTemp1]);
					}
				}
				fprintf(fpFile,"\n");
			}
		}
		fprintf(fpFile,"                              ");
		for(int k=0;k<m_nNumOfSequences;k++)
		{
			nTemp1=m_vectnCount[k];
			fprintf(fpFile,"%d",nTemp1);
		}
		fprintf(fpFile,"\n\n");


		if(m_bDetailed)
		{
			for(i=0;i<m_nSeqLength;i++)
			{
				int nG1=m_vectnResidueNumber[0].at(i);
				int nG2=m_vectnResidueNumber[1].at(i);
				int nG3=m_vectnResidueNumber[2].at(i);
				int nG4=m_vectnResidueNumber[m_nNumberIndex].at(i);
				fprintf(fpFile,"%8d  ",nG4);
				for(j=0;j<m_nPropertyDim;j++)
				{
							fprintf(fpFile," %8.3f ",m_vectfCorrelation[j].at(i));
				}
				fprintf(fpFile,"% 8.3f  ",m_vectfConservationScore[i]);
				for(int k=0;k<m_nNumOfSequences;k++)
				{
						nTemp=m_vectnSequence[k].at(i);
						fprintf(fpFile,"%c",AminoAcid[nTemp]);
				}
				fprintf(fpFile,"\n");

				for(j=0;j<m_nPropertyDim;j++)
				{
							fprintf(fpFile," %8d ",m_vectnHits[j].at(i));
				}
				fprintf(fpFile,"\n\n");
				if(bPrintDetail)
				{
					for(j=0;j<m_nPropertyDim;j++)
					{
						fprintf(fpFile,"                   %6.2f",sqrt(m_fDevFunctionalIndex));
						for(int k=0;k<m_nNumOfSequences;k++)
						{
							fprintf(fpFile," %6.2f",m_vectfFunctionalIndex[k]);
						}
						fprintf(fpFile,"\n");
						fprintf(fpFile,"                   %6.2f",sqrt(m_vectfDevCoordinate[j].at(i)));
						for(k=0;k<m_nNumOfSequences;k++)
						{
							nTemp=m_vectnSequence[k].at(i);
							fprintf(fpFile," %6.2f",*(m_vectfCoordinates[j]+nTemp)-m_vectfAveCoordinate[j].at(i));
						}
						fprintf(fpFile,"\n");
						fprintf(fpFile,"\n");
					}
				}
			}
		}

//		OutputNumberConversion(fpFile);
		OutputProfile(fpFile);
		fclose(fpFile);
	}
}



void CPolarization::Sort(float* pfData, int const nSize, int* nOrder)
{
	int i,j,nMax,nTemp;
	bool* pbSorted;
	float fTemp,fMax;
	float* vectfData=new float[nSize];

	for(i=0;i<nSize;i++)
	{
		vectfData[i]=*(pfData+i);
	}

	pbSorted=new bool[nSize];

	for(i=0;i<nSize;i++)
	{
		fMax=vectfData[i];
		nMax=i;
		for(j=i+1;j<nSize;j++)
		{
			fTemp=vectfData[j];
			if(fTemp>fMax)
			{
				fMax=fTemp;
				nMax=j;
			}
		}
		if(nMax!=i)
		{
			fTemp=vectfData[nMax];
			nTemp=nOrder[nMax];
			vectfData[nMax]=vectfData[i];
			nOrder[nMax]=nOrder[i];
			vectfData[i]=fTemp;
			nOrder[i]=nTemp;
		}
	}
}

void CPolarization::ConservationIndex()
{
	const float fFactor=5.5f;
	int i,j,nI,nJ,nDim,nPosition;
	float fConservationIndex=0.f,fCoor1,fCoor2;
	bool bDeletion=false;
//	int nScore[21]={20,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	for(nDim=0;nDim<m_nPropertyDim;nDim++)
	{
		vector <float> fVector;
		float fMax=-200.f,fMin=2000000.f;
		for(nPosition=0;nPosition<m_nSeqLength;nPosition++)
		{
			int nCount=0;
			for(i=0;i<m_nNumOfSequences;i++)
			{
				nI=m_vectnSequence[i].at(nPosition);
				fCoor1=*(m_vectfCoordinates[nDim]+nI);
				for(j=i+1;j<m_nNumOfSequences;j++)
				{
					nJ=m_vectnSequence[j].at(nPosition);
					fCoor2=*(m_vectfCoordinates[nDim]+nJ);
					if(nI==nJ)
					{
						if(nI==0||nJ==0)
						{
							bDeletion=true;
						}
						fConservationIndex+=
							(m_fSubstitutionMatrix[nI][nI]-m_fSubstitutionMatrix[nI][nJ]+1.f);
						nCount++;
					}
				}
			}
			if(nCount==0)
			{
				nCount=nCount;
			}
			fConservationIndex/=float(nCount);
			if(!bDeletion)
			{
				if(fConservationIndex>fMax)
				{
					fMax=fConservationIndex;
				}
				if(fConservationIndex<fMin)
				{
					fMin=fConservationIndex;
				}
			}
			else
			{
				bDeletion=false;
			}
			fVector.push_back(fConservationIndex);
		}

		float fTemp=0;
		for(nPosition=0;nPosition<m_nSeqLength;nPosition++)
		{
			fTemp=fVector[nPosition];
			fTemp=1.0f+(fFactor-1.0f)*(fTemp-fMin)/(fMax-fMin);
			fVector[nPosition]=fTemp;
			fTemp=fVector[nPosition];
		}		
		m_vectfConservationIndex.push_back(fVector);
	}
}

void CPolarization::OldConservationIndex()
{
	const float fFactor=2.50f;
	int i,nI,nDim,nPosition;
	bool bDeletion=false;
	for(nDim=0;nDim<m_nPropertyDim;nDim++)
	{
		vector <float> fVector;
		float fMax=-200.f,fMin=2000000.f;
		for(nPosition=0;nPosition<m_nSeqLength;nPosition++)
		{
			int nScore[21]={20,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
			int nCount=0;
			float fConservationIndex=0.f;
			for(i=0;i<m_nNumOfSequences;i++)
			{
				nI=m_vectnSequence[i].at(nPosition);
				if(nI==0)
				{
					bDeletion=true;
				}
				fConservationIndex+=float(nScore[nI]);
				nScore[nI]=0;
			}
			if(!bDeletion)
			{
				if(fConservationIndex>fMax)
				{
					fMax=fConservationIndex;
				}
				if(fConservationIndex<fMin)
				{
					fMin=fConservationIndex;
				}
			}
			else
			{
				bDeletion=false;
			}
			fVector.push_back(fConservationIndex);
		}

		float fTemp=0;
		for(nPosition=0;nPosition<m_nSeqLength;nPosition++)
		{
			fTemp=fVector[nPosition];
			fTemp=1.0f+(m_fFactor-1.0f)*(fTemp-fMin)/(fMax-fMin);
			fVector[nPosition]=fTemp;
			fTemp=fVector[nPosition];
		}		
		m_vectfConservationIndex.push_back(fVector);
	}
}

void CPolarization::AssignResNumber()
{
	for(int i=0;i<m_nNumOfSequences;i++)
	{
		vector <int> nVector;
		int nSeqLength=0;
		for(int j=0;j<m_nSeqLength;j++)
		{
			if(m_vectnSequence[i].at(j)>0)
			{
				nSeqLength++;
			}
			nVector.push_back(nSeqLength);
		}
		m_vectnResidueNumber.push_back(nVector);
	}
}

void CPolarization::OutputNumberConversion(FILE* fp)
{
	const int nDim=9;
	const int nChannel=1;
	char sResidCode[22]=".ACDEFGHIKLMNPQRSTVWY";
	int nNumArray[nDim]={50,98,129,172,234,330,341,379,386};
	int i,j,k,l;
	fprintf(fp,"\n\n\n");
	for(i=0;i<nDim;i++)
	{
		int nTemp=nNumArray[i];
		j=0;
		while (m_vectnResidueNumber[nChannel].at(j)<nTemp)
		{
			j++;
		}
		for(k=0;k<m_nNumOfSequences;k++)
		{
			fprintf(fp," %3d",m_vectnResidueNumber[k].at(j));
			for(l=0;l<2;l++)
			{
				fprintf(fp,"%c",sResidCode[m_vectnSequence[k].at(j+l)]);
			}
		}
		fprintf(fp,"\n");
	}
}

void CPolarization::GetOptions()
{
	COutputCutoffDialog aDlg;
	float fTemp;
	if(aDlg.DoModal()==IDOK)
	{
		OptionNode aNode;
		aNode=aDlg.GetOptions();
		float *fOutputCutoff=aNode.pfCutoff;
		for(int i=0;i<8;i++)
		{
			fTemp=fOutputCutoff[i];
			m_vectfOutputCutoff.push_back(fTemp);
		}
		fTemp=fOutputCutoff[7];
		m_vectfOutputCutoff.push_back(fTemp);
		m_bBrief=aNode.bBrief;
		m_bRescaled=aNode.bRescaled;
		m_bDetailed=aNode.bDetailed;
		m_bpValue=aNode.bpValue;
		m_brValue=aNode.brValue;
		m_nHits=aNode.nHits;
		m_bCorrelation=aNode.bCorrelation;
		m_bPolarization=aNode.bPolarization;
		m_fPValue=aNode.fpValue;aNode.nNumberIndex;
		m_nNumberIndex=aNode.nNumberIndex;
		m_fRescalingFactor=aNode.fRescaleFactor;
		m_bPearson=aNode.bPearson;
		m_bSpearman=aNode.bSpearman;
	}
}

//void CPolarization::GetSeqNames()
//{
//	SequenceNameNode aNode;
//	aNode=m_cMAlign.GetSequenceNames();
//	int nSize=aNode.SequenceName.size();
//	for(int i=0;i<nSize;i++)
//	{
//		CString astring;
//		astring=aNode.SequenceName[i];
//		m_vectsSeqNames.push_back(astring);
//	}
//}

void CPolarization::GetFunctionalIndex()
{
	FILE* PARFile;
	CString sFileName;
	char* pch="Parameter file (*.PAR or *.par)\0*.PAR\0*.par\0\0";
	CFileDialog aFileDlg( true, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT|OFN_EXPLORER|OFN_ENABLESIZING, NULL, NULL );
	aFileDlg.m_ofn.lpstrFilter=pch;
	int i;
	CString aString;
	char cTemp;

	float fTemp='c';
	CString sTemp;
	int nTemp;
	if(aFileDlg.DoModal()==IDOK)
	{
		sFileName=aFileDlg.GetPathName();
		PARFile=fopen(sFileName,"r");
		while(!feof(PARFile))
		{
			fscanf(PARFile,"%s%f%d",sTemp,&fTemp,&nTemp);
//			cTemp=sTemp.GetAt(0);
			if(cTemp!='#')
			{
				m_vectsSeqNames.push_back(sTemp);
				m_vectfFunctionalIndex.push_back(fTemp);
				m_vectnCount.push_back(nTemp);
			}
		}
		fclose(PARFile);
	}

	m_nNumOfSequences=m_vectnSequence.size();

	int nCountT=0;
	fTemp=0.f;
	for(i=0;i<m_nNumOfSequences;i++)
	{
		fTemp+=(m_vectfFunctionalIndex[i])*m_vectnCount[i];
		nCountT+=m_vectnCount[i];
	}
	fTemp/=float(nCountT);
	m_nDf=nCountT-2;
	m_fDevFunctionalIndex=0.f;
	for(i=0;i<m_nNumOfSequences;i++)
	{
		if(m_vectnCount[i]==1)
		{
			m_vectfFunctionalIndex[i]-=fTemp;
			m_fDevFunctionalIndex+=m_vectfFunctionalIndex[i]*m_vectfFunctionalIndex[i];
		}
	}

}

void CPolarization::MaximumPolarization()
{
	int i,j,nTemp1,nTemp2;
	float fTemp;
	int* pnOrder1,*pnOrder2;
	pnOrder1=new int[m_nNumOfSequences];
	pnOrder2=new int[m_nNumOfSequences];
	float* pfTemp=new float[m_nPropertyDim];

	for(i=0;i<m_nPropertyDim;i++)
	{
		*(pfTemp+i)=m_vectfFunctionalIndex[i];
	}

	Sort(pfTemp,m_nPropertyDim,pnOrder1);
	delete m_pfMaxPolarization;
	m_pfMaxPolarization=new float[m_nNumOfSequences];
	for(i=0;i<m_nPropertyDim;i++)
	{
		Sort(m_vectfCoordinates[i],m_nPropertyDim,pnOrder2);
		fTemp=0.f;
		for(j=0;j<m_nNumOfSequences;j++)
		{
			nTemp1=pnOrder1[j];
			nTemp2=pnOrder2[j];
			fTemp+=m_vectfFunctionalIndex[nTemp1]**(m_vectfCoordinates[i]+nTemp2);
		}
		m_pfMaxPolarization[i]=fTemp;
	}
}

void CPolarization::ReScaleCorrelation()
{
	int i,j;
	float fTemp,fTemp1;
	m_fRescalingFactor=0.3f;
	for(i=0;i<m_nPropertyDim;i++)
	{
		fTemp=m_vectfMaxDevCoordinate[i];
		for(j=0;j<m_nSeqLength;j++)
		{
			fTemp1=m_vectfDevCoordinate[i].at(j);
			fTemp1/=(fTemp1+m_fRescalingFactor*(fTemp-fTemp1));
			m_vectfCorrelation[i].at(j)*=sqrt(fTemp1);
		}
	}
}

float CPolarization::TValue(int nDf, float fCorrelation)
{
	float	fTemp1=fabs(fCorrelation)*sqrt(nDf);
	fTemp1/=sqrt(1.f-fCorrelation*fCorrelation);
	return fTemp1;
}

bool CPolarization::Printable(int i0, int j0)
{
	bool bPrintable=true;
	float r=m_vectfCorrelation[i0].at(j0);
	float ftValue,fpValue;
	int nHits;
	if(i0<m_nPropertyDim)
	{
		nHits=m_vectnHits[i0].at(j0);
	}
	else
	{
		nHits=20;
	}
	if(m_bpValue)
	{
		if(m_bSpearman)
		{
			fpValue=m_vdProbrs.at(i0)[j0];
			if(fpValue>m_fPValue)
			{
				bPrintable=false;
			}
		}
		else
		{
			ftValue=TValue(m_nDf,r);
			fpValue=m_cT_Test.GetPValue(m_nDf,ftValue);
			if(fpValue>m_fPValue||nHits<m_nHits)
			{
				bPrintable=false;
			}
		}
	}
	else
	{
		if(fabs(r)<m_vectfOutputCutoff[i0])
		{
			bPrintable=false;
		}
	}
	if(m_pbDeletion[j0])
	{
		bPrintable=false;
	}
	if(i0<m_nPropertyDim)
	{
		if(m_vbConserved.at(i0)[j0])
		{
			bPrintable=false;
		}
	}
	return bPrintable;
}

void CPolarization::ConservationScore()
{
	int i,j,nI,nJ,nPosition;
	float fScore=0.f;
	bool bDeletion=false;
	float fMax=-2000000.f,fMin=2000000.f;
	for(nPosition=0;nPosition<m_nSeqLength;nPosition++)		
	{
		int nCount=0;
		fScore=0.f;
		for(i=0;i<m_nNumOfSequences;i++)
		{
			nI=m_vectnSequence[i].at(nPosition);
			for(j=i+1;j<m_nNumOfSequences;j++)
			{
				if(m_vectnCount[i]*m_vectnCount[j]>0)
				{
					nJ=m_vectnSequence[j].at(nPosition);
					fScore+=m_fSubstitutionMatrix[nI][nJ];
					nCount++;
				}
			}
		}
		fScore/=float(nCount);
		m_vectfConservationScore.push_back(fScore);
	}
}

void CPolarization::CalClusterCorrelation_Spearman()
{
	int i,j,nI,nJ,nPosition;
	float fScore=0.f;
	bool bDeletion=false;
	float fMax=-2000000.f,fMin=2000000.f,fTemp;

	fTemp=0;
	int nCount=0;
	for(i=0;i<m_nNumOfSequences;i++)
	{
		for(j=i+1;j<m_nNumOfSequences;j++)
		{
			if(m_vectnCount[i]*m_vectnCount[j]>0)
			{
				nCount++;
				fTemp+=fabs(m_vectfFunctionalIndex[i]-m_vectfFunctionalIndex[j]);
			}
		}
	}

	float fMeanFunctionalScore=fTemp/float(nCount);

	float fDev1=0,fDev2=0;
	float fTemp1;
	float fTemp2,fCorrelation,fMaxDev;
	vector <float> fVector1;
	vector <float> fVector2;
	vector <float> fVector3;
	vector <double> dvProbs;
	fMaxDev=-1000000.f;
	for(nPosition=0;nPosition<m_nSeqLength;nPosition++)		
	{
		fDev1=0;
		fDev2=0;
		fTemp1=0.f;
		fTemp2=0.f;
		float fTemp4=0.f;
		float fTemp5=0.f;
		fCorrelation=0.f;
		for(i=0;i<m_nNumOfSequences;i++)
		{
			nI=m_vectnSequence[i].at(nPosition);
			for(j=i+1;j<m_nNumOfSequences;j++)
			{
				if(m_vectnCount[i]*m_vectnCount[j]>0)
				{
					nJ=m_vectnSequence[j].at(nPosition);
					fTemp2=m_fSubstitutionMatrix[nI][nJ]-m_vectfConservationScore[nPosition];
					fTemp1=fabs(m_vectfFunctionalIndex[i]-m_vectfFunctionalIndex[j])-fMeanFunctionalScore;
					fDev1+=fTemp1*fTemp1;
					fDev2+=fTemp2*fTemp2;
					fCorrelation+=fTemp1*fTemp2;
					fTemp4+=fTemp1;
					fTemp5+=fTemp2;
				}
			}
		}
		if(fDev2>0.0001)
		{
			fTemp=fCorrelation/sqrt(fDev1*fDev2);
			fVector1.push_back(fTemp);
		}
		else
		{
			fVector1.push_back(0.f);
		}
		fVector2.push_back(fDev1);
		fVector3.push_back(fDev2);
		if(fDev2>fMaxDev)
		{
			fMaxDev=fDev2;
		}
		dvProbs.push_back(m_cT_Test.GetPValue(m_nDf,TValue(m_nDf,fTemp)));		
	}
	m_vdProbrs.push_back(dvProbs);
	m_vectfCorrelation.push_back(fVector1);
	m_vectfDevCoordinate.push_back(fVector3);
	m_vectfMaxDevCoordinate.push_back(fMaxDev);
}
void CPolarization::CalClusterCorrelation_Pearson()
{
	int i,j,nI,nJ,nPosition;
	float fScore=0.f;
	bool bDeletion=false;
	float fMax=-2000000.f,fMin=2000000.f,fTemp;

	fTemp=0;
	int nCount=0;
	for(i=0;i<m_nNumOfSequences;i++)
	{
		for(j=i+1;j<m_nNumOfSequences;j++)
		{
			if(m_vectnCount[i]*m_vectnCount[j]>0)
			{
				nCount++;
				fTemp+=fabs(m_vectfFunctionalIndex[i]-m_vectfFunctionalIndex[j]);
			}
		}
	}

	float fMeanFunctionalScore=fTemp/float(nCount);

	float fDev1=0,fDev2=0;
	float fTemp1;
	float fTemp2,fCorrelation,fMaxDev;
	vector <float> fVector1;
	vector <float> fVector2;
	vector <float> fVector3;
	fMaxDev=-1000000.f;
	for(nPosition=0;nPosition<m_nSeqLength;nPosition++)		
	{
		fDev1=0;
		fDev2=0;
		fTemp1=0.f;
		fTemp2=0.f;
		float fTemp4=0.f;
		float fTemp5=0.f;
		fCorrelation=0.f;
		for(i=0;i<m_nNumOfSequences;i++)
		{
			nI=m_vectnSequence[i].at(nPosition);
			for(j=i+1;j<m_nNumOfSequences;j++)
			{
				if(m_vectnCount[i]*m_vectnCount[j]>0)
				{
					nJ=m_vectnSequence[j].at(nPosition);
					fTemp2=m_fSubstitutionMatrix[nI][nJ]-m_vectfConservationScore[nPosition];
					fTemp1=fabs(m_vectfFunctionalIndex[i]-m_vectfFunctionalIndex[j])-fMeanFunctionalScore;
					fDev1+=fTemp1*fTemp1;
					fDev2+=fTemp2*fTemp2;
					fCorrelation+=fTemp1*fTemp2;
					fTemp4+=fTemp1;
					fTemp5+=fTemp2;
				}
			}
		}
		if(fDev2>0.0001)
		{
			fTemp=fCorrelation/sqrt(fDev1*fDev2);
			fVector1.push_back(fTemp);
		}
		else
		{
			fVector1.push_back(0.f);
		}
		fVector2.push_back(fDev1);
		fVector3.push_back(fDev2);
		if(fDev2>fMaxDev)
		{
			fMaxDev=fDev2;
		}
	}
	m_vectfCorrelation.push_back(fVector1);
	m_vectfDevCoordinate.push_back(fVector3);
	m_vectfMaxDevCoordinate.push_back(fMaxDev);
}

void CPolarization::OutputSubstitutionMatrix()
{
	FILE* fp=fopen("Pam250.txt","w");
	int i,j;
	char AminoAcid[22]=".ACDEFGHIKLMNPQRSTVWY";
	fprintf(fp,"   ");
	for(i=0;i<21;i++)
	{
		fprintf(fp,"%4c",AminoAcid[i]);
	}
	fprintf(fp,"\n");
	for(i=0;i<21;i++)
	{
		fprintf(fp," %c ",AminoAcid[i]);
		for(j=0;j<21;j++)
		{
			fprintf(fp,"%4d",m_fSubstitutionMatrix[i][j]);
		}
		fprintf(fp,"\n\n");
	}

	int nMatrix[21][21];

	for(i=0;i<21;i++)
	{
		for(j=0;j<21;j++)
		{
			nMatrix[i][j]=-(m_fSubstitutionMatrix[i][i]+m_fSubstitutionMatrix[j][j])/2+m_fSubstitutionMatrix[i][j];
		}
	}

	for(i=0;i<21;i++)
	{
		for(j=0;j<21;j++)
		{
			m_fSubstitutionMatrix[i][i]=nMatrix[i][j];
		}
	}
		fprintf(fp,"\n\n");
		fprintf(fp,"\n\n");


	fprintf(fp,"   ");
	for(i=0;i<21;i++)
	{
		fprintf(fp,"%4c",AminoAcid[i]);
	}
	fprintf(fp,"\n");
	for(i=0;i<21;i++)
	{
		fprintf(fp," %c ",AminoAcid[i]);
		for(j=0;j<21;j++)
		{
			fprintf(fp,"%4d",nMatrix[i][j]);
		}
		fprintf(fp,"\n\n");
	}

	fclose(fp);
}

void CPolarization::SortCorrelation()
{
	int i,j,nTemp;
	int* pnTemp=new int[m_nSeqLength];
	float* pfTemp=new float[m_nSeqLength];
	for(i=0;i<m_nPropertyDim+1;i++)
	{
		for(j=0;j<m_nSeqLength;j++)
		{
			pnTemp[j]=j;
			pfTemp[j]=fabs(m_vectfCorrelation[i].at(j));
		}
		Sort(pfTemp,m_nSeqLength,pnTemp);
		vector <int> nVector;
		for(j=0;j<m_nSeqLength;j++)
		{
			nTemp=pnTemp[j];
			nVector.push_back(nTemp);
		}
		m_vectnCorrelationOrder.push_back(nVector);
	}
}

void CPolarization::Initialization()
{
	int i,j;
	CString sTemp;
	char cTemp;
	float *pfTemp;
	fpIni=fopen("Correlation.ini","r");
	fscanf(fpIni,"%d",&m_nPropertyDim);
	for(i=0;i<m_nPropertyDim;i++)
	{
		CString sName;
		fscanf(fpIni,"%s",sName);
		m_vectsPropertyName.push_back(sName);
		pfTemp=new float[21];
		for(j=0;j<21;j++)
		{
			fscanf(fpIni,"%s %f",sTemp,pfTemp+j);
		}
		m_vectfCoordinates.push_back(pfTemp);
	}
}

void CPolarization::SortPolarization()
{

	int i,j,nTemp;
	int* pnTemp=new int[m_nSeqLength];
	float* pfTemp=new float[m_nSeqLength];
	for(i=0;i<m_nPropertyDim;i++)
	{
		for(j=0;j<m_nSeqLength;j++)
		{
			pnTemp[j]=j;
			pfTemp[j]=fabs(m_vectfPolarization[i].at(j));
		}
		Sort(pfTemp,m_nSeqLength,pnTemp);
		vector <int> nVector;
		for(j=0;j<m_nSeqLength;j++)
		{
			nTemp=pnTemp[j];
			nVector.push_back(nTemp);
		}
		m_vectnPolarizationOrder.push_back(nVector);
	}
}

void CPolarization::OutputProfile(FILE *fpFile)
{

}

void CPolarization::SpearmanCorr(vector<double> vdX, vector <double> vdY, double &d, double &zd, double &dProbd, double &rs, double &probrs)
{
	int nSize=vdX.size();
	Vec_DP data1(nSize),data2(nSize); //double nr array
	for(int i=0;i<nSize;i++)
	{
		data1[i]=vdX[i];
		data2[i]=vdY[i];
	}
	NR::spear(data1, data2, d, zd, dProbd, rs, probrs);
}

void CPolarization::Cal_Ave_Dev_Hits()
{
	int i,j,k,nTemp,nCount,nTemp2;
	float fTemp=0.f,fAveCoordinate=0.f,fAveFunctionalIndex=0.f,fCorrelation,fTemp1;
	float fDevCoordinate;
	float fMaxDevCoordinate=-100000000.f;
	int nHits[2];
	for(i=0;i<m_nPropertyDim;i++)
	{
		vector <float> fVector;
		vector <float> vectfDevfCoordinate;
		vector <float> vectfAvefCoordinate;
		vector <int> vectnHits;
		fMaxDevCoordinate=-10000000.f;
		for(j=0;j<m_nSeqLength;j++)
		{
			fAveCoordinate=0.f;
			nCount=0;
			for(k=0;k<m_nNumOfSequences;k++)
			{
				nTemp=m_vectnSequence[k].at(j);
				nTemp2=m_vectnCount[k];
				fTemp=*(m_vectfCoordinates[i]+nTemp)*float(nTemp2);
				nCount+=nTemp2;
				if(nTemp==0) m_pbDeletion[j]=true;
				fAveCoordinate+=fTemp;
			}
			fAveCoordinate/=float(nCount);
			vectfAvefCoordinate.push_back(fAveCoordinate);

			fCorrelation=0.0f;
			fDevCoordinate=0.f;

			for(k=0;k<2;k++)
			{
				nHits[k]=0;
			}

			for(k=0;k<m_nNumOfSequences;k++)
			{
				nTemp2=m_vectnCount[k];
				if(nTemp2==1)
				{
					nTemp=m_vectnSequence[k].at(j);
					fTemp=(*(m_vectfCoordinates[i]+nTemp)-fAveCoordinate)*float(nTemp2);
					fTemp1=m_vectfFunctionalIndex[k]*fTemp;
					fCorrelation+=fTemp1;
					if(fTemp1>0.0001)
					{
						nHits[0]++;
					}
					else if(fTemp1<-0.0001)
//					else
					{
						nHits[1]++;
					}
//					fDevCoordinate+=(fTemp-fAveCoordinate)*fTemp;
					fDevCoordinate+=fTemp*fTemp;
				}
			}
			vectfDevfCoordinate.push_back(fDevCoordinate);

			if(fCorrelation>0)
			{
				vectnHits.push_back(nHits[0]-nHits[1]);
			}
			else
			{
				vectnHits.push_back(nHits[1]-nHits[0]);
			}

		}
		m_vectfDevCoordinate.push_back(vectfDevfCoordinate);
		m_vectfAveCoordinate.push_back(vectfAvefCoordinate);
		m_vectfMaxDevCoordinate.push_back(fMaxDevCoordinate);
		m_vectnHits.push_back(vectnHits);
	}
}

void CPolarization::SortFunctionalIndece()
{
	m_vnFunctionalIndexOrder.clear;
	int i,nTemp;
	int* pnTemp=new int[m_nNumOfSequences];
	float* pfTemp=new float[m_nNumOfSequences];
	for(i=0;i<m_nNumOfSequences;i++)
	{
		pnTemp[i]=i;
		pfTemp[i]=m_vectfFunctionalIndex[i];
	}
	Sort(pfTemp,m_nNumOfSequences,pnTemp);
	for(i=0;i<m_nNumOfSequences;i++)
	{
		nTemp=pnTemp[i];
		m_vnFunctionalIndexOrder.push_back(nTemp);
	}
}
