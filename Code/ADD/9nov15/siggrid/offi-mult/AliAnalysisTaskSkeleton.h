/**************************************************************************
 * Copyright(c) 1998-1999, ALICE Experiment at CERN, All rights reserved. *
 *                                                                        *
 * Author: The ALICE Off-line Project.                                    *
 * Contributors are mentioned in the code where appropriate.              *
 *                                                                        *
 * Permission to use, copy, modify and distribute this software and its   *
 * documentation strictly for non-commercial purposes is hereby granted   *
 * without fee, provided that the above copyright notice appears in all   *
 * copies and that both the copyright notice and this permission notice   *
 * appear in the supporting documentation. The authors make no claims     *
 * about the suitability of this software for any purpose. It is          *
 * provided "as is" without express or implied warranty.                  *
 **************************************************************************/

// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// This is a simple task designed to test AliPPVsMultUtils functionality.
// --- david.dobrigkeit.chinellato@cern.ch
//
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

#ifndef AliAnalysisTaskSkeleton_H
#define AliAnalysisTaskSkeleton_H

class TList;
class TH1F;
class TH2F;
class TH3F;
class TVector3;

class AliESDpid;
class AliESDtrackCuts;
class AliAnalysisUtils;
class AliESDEvent;
class AliPhysicsSelection;

//#include "TString.h"
//#include "AliESDtrackCuts.h"
//#include "AliAnalysisTaskSE.h"

class AliAnalysisTaskSkeleton : public AliAnalysisTaskSE {
public:
    AliAnalysisTaskSkeleton();
    AliAnalysisTaskSkeleton(const char *name);
    virtual ~AliAnalysisTaskSkeleton();

    virtual void   UserCreateOutputObjects();
    virtual void   UserExec(Option_t *option);
    virtual void   Terminate(Option_t *);

private:
    // Note : In ROOT, "//!" means "do not stream the data from Master node to Worker node" ...
    // your data member object is created on the worker nodes and streaming is not needed.
    // http://root.cern.ch/download/doc/11InputOutput.pdf, page 14
    TList  *fListHist;  //! List of histograms

//===========================================================================================
//   Histograms
//===========================================================================================

    TH1D *fHistEventCounter; //!

    TH1D *fHistV0M; //!
    TH1D *fHistV0A; //!
    TH1D *fHistV0C; //!

    TH1D *fHistOnlineV0M; //!
    TH1D *fHistOnlineV0A; //!
    TH1D *fHistOnlineV0C; //!
    
    TH1D *fHistADM; //!
    TH1D *fHistADA; //!
    TH1D *fHistADC; //!

    TH1D *fHistSPDTracklets; //!
    TH1D *fHistSPDClusters;  //!
    TH1D *fHistRefMult05;  //!
    TH1D *fHistRefMult08;  //!
    
    AliAnalysisTaskSkeleton(const AliAnalysisTaskSkeleton&);            // not implemented
    AliAnalysisTaskSkeleton& operator=(const AliAnalysisTaskSkeleton&); // not implemented

    ClassDef(AliAnalysisTaskSkeleton, 11);
};

#endif
