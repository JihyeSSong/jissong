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

class TTree;
class TParticle;
class TVector3;

//class AliMCEventHandler;
//class AliMCEvent;
//class AliStack;

class AliESDVertex;
class AliAODVertex;
class AliESDv0;
class AliAODv0;

#include <Riostream.h>
#include "TList.h"
#include "TH1.h"
#include "TH2.h"
#include "TH3.h"
#include "TFile.h"
#include "THnSparse.h"
#include "TVector3.h"
#include "TCanvas.h"
#include "TMath.h"
#include "TLegend.h"
//#include "AliLog.h"

#include "AliESDEvent.h"
#include "AliAODEvent.h"
#include "AliV0vertexer.h"
#include "AliCascadeVertexer.h"
#include "AliESDpid.h"
#include "AliESDtrack.h"
#include "AliESDtrackCuts.h"
#include "AliInputEventHandler.h"
#include "AliAnalysisManager.h"
#include "AliMCEventHandler.h"
#include "AliMCEvent.h"
#include "AliStack.h"
#include "AliCentrality.h"

#include "AliMultiplicity.h"
#include "AliAODMCParticle.h"
#include "AliESDcascade.h"
#include "AliAODcascade.h"
#include "AliESDUtils.h"
#include "AliGenEventHeader.h"
#include "AliAnalysisTaskSE.h"
#include "AliAnalysisUtils.h"
#include "AliPPVsMultUtils.h"
#include "AliOADBContainer.h"
#include "AliOADBMultSelection.h"
#include "AliMultEstimator.h"
#include "AliMultVariable.h"
#include "AliMultInput.h"
#include "AliMultSelection.h"
#include "AliAnalysisTaskSkeleton.h"

using std::cout;
using std::endl;

ClassImp(AliAnalysisTaskSkeleton)

AliAnalysisTaskSkeleton::AliAnalysisTaskSkeleton()
    : AliAnalysisTaskSE(), fListHist(0),
//Histos
fHistEventCounter(0),
fHistV0M(0),
fHistV0A(0),
fHistV0C(0),
fHistOnlineV0M(0),
fHistOnlineV0A(0),
fHistOnlineV0C(0),
fHistADM(0),
fHistADA(0),
fHistADC(0),
fHistSPDTracklets(0),
fHistSPDClusters(0),
fHistRefMult05(0),
fHistRefMult08(0)
{

}

AliAnalysisTaskSkeleton::AliAnalysisTaskSkeleton(const char *name)
    : AliAnalysisTaskSE(name), fListHist(0),
//Histos
fHistEventCounter(0),
fHistV0M(0),
fHistV0A(0),
fHistV0C(0),
fHistOnlineV0M(0),
fHistOnlineV0A(0),
fHistOnlineV0C(0),
fHistADM(0),
fHistADA(0),
fHistADC(0),
fHistSPDTracklets(0),
fHistSPDClusters(0),
fHistRefMult05(0),
fHistRefMult08(0)
{
    DefineOutput(1, TList::Class()); // List of Histograms
}


AliAnalysisTaskSkeleton::~AliAnalysisTaskSkeleton()
{
    //------------------------------------------------
    // DESTRUCTOR
    //------------------------------------------------

    delete fListHist;
    fListHist = 0x0;
}

//________________________________________________________________________
void AliAnalysisTaskSkeleton::UserCreateOutputObjects()
{

    AliAnalysisManager *man=AliAnalysisManager::GetAnalysisManager();
    AliInputEventHandler* inputHandler = (AliInputEventHandler*) (man->GetInputEventHandler());
    //fPIDResponse = inputHandler->GetPIDResponse();
    inputHandler->SetNeedField();

    // Create histograms
    OpenFile(1);
    fListHist = new TList();
    fListHist->SetOwner();  // See http://root.cern.ch/root/html/TCollection.html#TCollection:SetOwner

    //Storing the different event selection stages:
    
    
    if(! fHistEventCounter ) {
        //Histogram Output: Event-by-Event
        fHistEventCounter = new TH1D( "fHistEventCounter", ";Evt. Sel. Step;Count",2,0,2);
        fHistEventCounter->GetXaxis()->SetBinLabel(1, "Processed");
        fHistEventCounter->GetXaxis()->SetBinLabel(2, "IsEventSelected");
        fListHist->Add(fHistEventCounter);
    }

    if(! fHistV0M ) {
        //Histogram Output: Event-by-Event
        fHistV0M = new TH1D( "fHistV0M", ";Percentile;Count",300,0,300);
        fListHist->Add(fHistV0M);
    }
    if(! fHistV0A ) {
        //Histogram Output: Event-by-Event
        fHistV0A = new TH1D( "fHistV0A", ";Percentile;Count",300,0,300);
        fListHist->Add(fHistV0A);
    }
    if(! fHistV0C ) {
        //Histogram Output: Event-by-Event
        fHistV0C = new TH1D( "fHistV0C", ";Percentile;Count",300,0,300);
        fListHist->Add(fHistV0C);
    }
    
    if(! fHistOnlineV0M ) {
        //Histogram Output: Event-by-Event
        fHistOnlineV0M = new TH1D( "fHistOnlineV0M", ";Percentile;Count",300,0,300);
        fListHist->Add(fHistOnlineV0M);
    }
    if(! fHistOnlineV0A ) {
        //Histogram Output: Event-by-Event
        fHistOnlineV0A = new TH1D( "fHistOnlineV0A", ";Percentile;Count",300,0,300);
        fListHist->Add(fHistOnlineV0A);
    }
    if(! fHistOnlineV0C ) {
        //Histogram Output: Event-by-Event
        fHistOnlineV0C = new TH1D( "fHistOnlineV0C", ";Percentile;Count",300,0,300);
        fListHist->Add(fHistOnlineV0C);
    }
    
    if(! fHistADM ) {
        //Histogram Output: Event-by-Event
        fHistADM = new TH1D( "fHistADM", ";Percentile;Count",300,0,300);
        fListHist->Add(fHistADM);
    }
    if(! fHistADA ) {
        //Histogram Output: Event-by-Event
        fHistADA = new TH1D( "fHistADA", ";Percentile;Count",300,0,300);
        fListHist->Add(fHistADA);
    }
    if(! fHistADC ) {
        //Histogram Output: Event-by-Event
        fHistADC = new TH1D( "fHistADC", ";Percentile;Count",300,0,300);
        fListHist->Add(fHistADC);
    }

    if(! fHistSPDTracklets ) {
        //Histogram Output: Event-by-Event
        fHistSPDTracklets = new TH1D( "fHistSPDTracklets", ";Percentile;Count",300,0,300);
        fListHist->Add(fHistSPDTracklets);
    }
    if(! fHistSPDClusters ) {
        //Histogram Output: Event-by-Event
        fHistSPDClusters = new TH1D( "fHistSPDClusters", ";Percentile;Count",300,0,300);
        fListHist->Add(fHistSPDClusters);
    }
    if(! fHistRefMult05 ) {
        //Histogram Output: Event-by-Event
        fHistRefMult05 = new TH1D( "fHistRefMult05", ";Percentile;Count",300,0,300);
        fListHist->Add(fHistRefMult05);
    }
    if(! fHistRefMult08 ) {
        //Histogram Output: Event-by-Event
        fHistRefMult08 = new TH1D( "fHistRefMult08", ";Percentile;Count",300,0,300);
        fListHist->Add(fHistRefMult08);
    }
    
    
    //List of Histograms: Normal
    PostData(1, fListHist);
}// end UserCreateOutputObjects


//________________________________________________________________________
void AliAnalysisTaskSkeleton::UserExec(Option_t *)
{
    // Main loop
    // Called for each event

    AliVEvent *lVEvent = 0x0;

    lVEvent = dynamic_cast<AliVEvent*>( InputEvent() );
    if (!lVEvent) {
        AliWarning("ERROR: lVEvent not available \n");
        return;
    }

    //------------------------------------------------
    // All processed
    //------------------------------------------------

    fHistEventCounter->Fill(0.5);

    //================================================
    // USER ANALYSIS
    
    //Simple Test: Acquire information stored previously
    //             in AliMultContainer object
    
    Float_t lPercentiles[13];
    TString lNames[13] = {"V0M", "V0A", "V0C", "OnlineV0M", "OnlineV0A", "OnlineV0C",
        "ADM", "ADA", "ADC", "SPDClusters", "SPDTracklets", "RefMult05","RefMult08"};
    for(Int_t iEst=0; iEst<13; iEst++) lPercentiles[iEst] = 200;
    AliInfo("Skeleton will search for MultSelection object...");
    
    //This will work for both ESDs and AODs
    AliMultSelection *MultSelection = (AliMultSelection*) lVEvent -> FindListObject("MultSelection");
    
    if ( MultSelection ){
        for(Int_t iEst=0; iEst<13; iEst++)
            lPercentiles[iEst] = MultSelection->GetMultiplicityPercentile(lNames[iEst].Data());
    }else{
        AliInfo("Didn't find MultSelection!"); 
    }
    
    //================================================
    //Quick Percentile test histograms
    fHistV0M       -> Fill ( lPercentiles[0] );
    fHistV0A       -> Fill ( lPercentiles[1] );
    fHistV0C       -> Fill ( lPercentiles[2] );
    fHistOnlineV0M       -> Fill ( lPercentiles[3] );
    fHistOnlineV0A       -> Fill ( lPercentiles[4] );
    fHistOnlineV0C       -> Fill ( lPercentiles[5] );
    fHistADM       -> Fill ( lPercentiles[6] );
    fHistADA       -> Fill ( lPercentiles[7] );
    fHistADC       -> Fill ( lPercentiles[8] );
    fHistSPDClusters       -> Fill ( lPercentiles[9] );
    fHistSPDTracklets      -> Fill ( lPercentiles[10] );
    fHistRefMult05         -> Fill ( lPercentiles[11] );
    fHistRefMult08         -> Fill ( lPercentiles[12] );
    //================================================
    
    //Embedded in framework:
    // ---> if lPercentiles are 200 or above: event didn't pass event selections
    // ---> if lPercentiles are 0-100       : event passed, go ahead
    
    if ( lPercentiles[0] > 199 ){
        //Event didn't pass Event Selections
        PostData(1, fListHist);
        return;
    }
    
    //Do User Analysis here
    
    // Post output data.
    PostData(1, fListHist);
}

//________________________________________________________________________
void AliAnalysisTaskSkeleton::Terminate(Option_t *)
{
    // Draw result to the screen
    // Called once at the end of the query

    TList *cRetrievedList = 0x0;
    cRetrievedList = (TList*)GetOutputData(1);
    if(!cRetrievedList) {
        Printf("ERROR - AliAnalysisTaskSkeleton : ouput data container list not available\n");
        return;
    }

    fHistEventCounter = dynamic_cast<TH1D*> (  cRetrievedList->FindObject("fHistEventCounter")  );
    if (!fHistEventCounter) {
        Printf("ERROR - AliAnalysisTaskSkeleton : fHistEventCounter not available");
        return;
    }

    TCanvas *canCheck = new TCanvas("AliAnalysisTaskSkeleton","Control Histo",10,10,510,510);
    canCheck->cd(1)->SetLogy();

    fHistEventCounter->SetMarkerStyle(22);
    fHistEventCounter->DrawCopy("E");
}
