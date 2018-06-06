#include <iostream>
#include <TApplication.h>
#include <TMatrix.h>
#include <TROOT.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TList.h>
#include <TTree.h>
#include <TDirectoryFile.h>
#include <TLorentzVector.h>
#include <TString.h>
#include <TStopwatch.h>
#include <TPaveText.h>
#include <cstdlib>
#include <iomanip>

#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <Riostream.h>
#include "RooFit.h"
#include "RooVoigtian.h"
#include "RooAbsReal.h"
#include "RooRealVar.h"
#include "RooComplex.h"
#include "RooMath.h"

#include "TVector2.h"
#include "TFile.h"
#include "TString.h"
#include "TF1.h"
#include "TH1.h"
#include "TH2.h"
#include "TH3.h"
#include "TProfile.h"
#include "TProfile2D.h"
#include "TMath.h"
#include "TText.h"
#include "TRandom3.h"
#include "TArray.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TMinuit.h"

#include "TCanvas.h"
#include "TLatex.h"
#include "TImage.h"
#include "TGaxis.h"
#include "TGraphErrors.h"
#include "TPaveStats.h"
using namespace std;

// #include <iostream>

// this is for systematic study

const int ptbin = 8;
double ptedges[ptbin+1+1]={0};

/* Bins0
 double ptedges_Sigma[ptbin+1] = { 1.0, 1.5, 2.0, 2.4, 2.8, 3.2, 4., 6.0, 10.0 };
double pt_points[ptbin] = {1.25, 1.75, 2.2, 2.6, 3.0, 3.6, 5., 8};
double pt_points_e[ptbin] = {.25, .25, .2, .2, .2, .4, 1., 2. };
*/


// * Bins2b 18oct16
Int_t iBinPt[40]=               { 12,  17,  21,  25,  29,  35,  41, 51,  81, 241,281,321,361,401 };
double ptedges_Sigma[ptbin+1] = { 1.1, 1.6, 2.0, 2.4, 2.8, 3.4, 4., 5.0, 8.0 };
double pt_points[ptbin] =       { 1.35,1.8, 2.2, 2.6, 3.0, 3.8,    4.5, 6.5 };
double pt_points_e[ptbin] =     {  .25, .2,  .2, .2,   .3,  .3,    0.5, 1.5 };
// */


 TH1F *hRatDiffSum = new TH1F("hRatDiffSum","; Ratio", 100, -5, 5.);

double yMpol1[ptbin+1]={0};
double yMpol1_e[ptbin+1]={0};
double yMpol2[ptbin+1]={0};
double yMpol2_e[ptbin+1]={0};
double yMpol3[ptbin+1]={0};
double yMpol3_e[ptbin+1]={0};
double yMpol4[ptbin+1]={0};
double yMpol4_e[ptbin+1]={0};
double yMpol5[ptbin+1]={0};
double yMpol5_e[ptbin+1]={0};

double yiel1[ptbin+1]={0};
double yiel1_e[ptbin+1]={0};
double yiel2[ptbin+1]={0};
double yiel2_e[ptbin+1]={0};
double yiel3[ptbin+1]={0};
double yiel3_e[ptbin+1]={0};
double yiel4[ptbin+1]={0};
double yiel4_e[ptbin+1]={0};
double yiel5[ptbin+1]={0};
double yiel5_e[ptbin+1]={0};


double yMmean[ptbin+1]={0};
double yMmean_e[ptbin+1]={0};

double dyMean[ptbin+1]={0};
double dyMean_e[ptbin+1]={0};


double diff1[ptbin+1]={0};
double diff1_e[ptbin+1]={0};
double reldiff1[ptbin+1]={0};
double reldiff1_e[ptbin+1]={0};
double relstat1[ptbin+1]={0};
double relstat1_e[ptbin+1]={0};

double diff2[ptbin+1]={0};
double diff2_e[ptbin+1]={0};
double reldiff2[ptbin+1]={0};
double reldiff2_e[ptbin+1]={0};
double relstat2[ptbin+1]={0};
double relstat2_e[ptbin+1]={0};

double diff3[ptbin+1]={0};
double diff3_e[ptbin+1]={0};
double reldiff3[ptbin+1]={0};
double reldiff3_e[ptbin+1]={0};
double relstat3[ptbin+1]={0};
double relstat3_e[ptbin+1]={0};

double diff4[ptbin+1]={0};
double diff4_e[ptbin+1]={0};
double reldiff4[ptbin+1]={0};
double reldiff4_e[ptbin+1]={0};
double relstat4[ptbin+1]={0};
double relstat4_e[ptbin+1]={0};

double diff5[ptbin+1]={0};
double diff5_e[ptbin+1]={0};
double reldiff5[ptbin+1]={0};
double reldiff5_e[ptbin+1]={0};
double relstat5[ptbin+1]={0};
double relstat5_e[ptbin+1]={0};

double delta1[ptbin+1]={0};
double delta2[ptbin+1]={0};
double delta3[ptbin+1]={0};
double delta4[ptbin+1]={0};
double delta5[ptbin+1]={0};

double delta1_e[ptbin+1]={0};
double delta2_e[ptbin+1]={0};
double delta3_e[ptbin+1]={0};
double delta4_e[ptbin+1]={0};
double delta5_e[ptbin+1]={0};


double ratdiff1[ptbin+1]={0};
double ratdiff2[ptbin+1]={0};
double ratdiff3[ptbin+1]={0};
double ratdiff4[ptbin+1]={0};
double ratdiff5[ptbin+1]={0};

double ratdiff1_e[ptbin+1]={0};
double ratdiff2_e[ptbin+1]={0};
double ratdiff3_e[ptbin+1]={0};
double ratdiff4_e[ptbin+1]={0};
double ratdiff5_e[ptbin+1]={0};



void SystGamma01(){          // -LamCosPAvar

  //  PPRstyle();              
  //      gStyle->SetOptStat(111111);
   gStyle->SetOptStat(0);       // global options for ALL plots
   gStyle->SetOptFit(111);

    for(int i=0; i<ptbin+1; i++){        
        if(i==0) ptedges[i]=0;
        else {
            ptedges[i] = ptedges_Sigma[i-1];
            ptedges[ptbin+1] = ptedges_Sigma[ptbin];
        }
    }
    
    //    TH1F *hRatDiff = new TH1F("hRatDiff","; Ratio", 100, -15, 15.);  

   TH1F *hRatDiffSum = new TH1F("hRatDiff","; Ratio", 100, -5, 5.);  
   TH1F *hRatDiff1 = new TH1F("hRatDiff","; Ratio", 100, -5, 5.);  
   TH1F *hRatDiff2 = new TH1F("hRatDiff","; Ratio", 100, -5, 5.);  
   TH1F *hRatDiff3 = new TH1F("hRatDiff","; Ratio", 100, -5, 5.);  
   TH1F *hRatDiff4 = new TH1F("hRatDiff","; Ratio", 100, -5, 5.);  
   TH1F *hRatDiff5 = new TH1F("hRatDiff","; Ratio", 100, -5, 5.);  

   TH1F *hStatDiffSum = new TH1F("hStatDiff","; Ratio", 100, 0, 25.);  

  TH1D *hRatDiffPt[15];
  for(int i=1; i<ptbin+5; i++){
   hRatDiffPt[i]= new TH1D(Form("hRatDiffPt_%d",i),Form("RatDiffPt_%d",i), 100, -5, 5 );
   hRatDiffPt[i]->SetMarkerStyle(21);
   hRatDiffPt[i]->SetMarkerSize(0.5);
   hRatDiffPt[i]->SetLineColor(kRed-3);
   hRatDiffPt[i]->SetMarkerColor(kRed-3);
   } 


   Double_t emix, epol1,epol2,epol3,epol4,epol5, ed1,ed2,ed3,ed4,ed5;
   Double_t statdiff1,statdiff2,statdiff3, statdiff4, statdiff5; 
    
   Double_t nVars = 5;

   /* var1
    TFile *fmix = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-BASE-7nov16.root");
   TFile *fpol1 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-CosPA-cut1-8nov16.root");
   TFile *fpol2 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-CosPA-cut2-8nov16.root");
   TFile *fpol3 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-CosPA-cut3-8nov16.root");
   TFile *fpol4 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-CosPA-cut4-8nov16.root");
   TFile *fpol5 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-CosPA-cut5-8nov16.root");
     */


   /* var2
    TFile *fmix = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-BASE-7nov16.root");
   TFile *fpol1 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-DCADaught-cut1-8nov16.root");
   TFile *fpol2 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-DCADaught-cut2-8nov16.root");
   TFile *fpol3 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-DCADaught-cut3-8nov16.root");
   TFile *fpol4 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-DCADaught-cut4-8nov16.root");
   TFile *fpol5 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-DCADaught-cut5-8nov16.root");
   */

    /* var3
   TFile *fmix = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-BASE-7nov16.root");
   TFile *fpol1 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-DCAPVneg-cut1-8nov16.root");
   TFile *fpol2 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-DCAPVneg-cut2-8nov16.root");
   TFile *fpol3 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-DCAPVneg-cut3-8nov16.root");
   TFile *fpol4 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-DCAPVneg-cut4-8nov16.root");
   TFile *fpol5 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-DCAPVneg-cut5-8nov16.root");
      */
   /* var 4
   TFile *fmix = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-BASE-7nov16.root");
   TFile *fpol1 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-DCAPVpos-cut1-8nov16.root");
   TFile *fpol2 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-DCAPVpos-cut2-8nov16.root");
   TFile *fpol3 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-DCAPVpos-cut3-8nov16.root");
   TFile *fpol4 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-DCAPVpos-cut4-8nov16.root");
   TFile *fpol5 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-DCAPVpos-cut5-8nov16.root");
      */
   /* var 5
   TFile *fmix = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-BASE-7nov16.root");
   TFile *fpol1 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-DCAztoPV-cut1-8nov16.root");
   TFile *fpol2 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-DCAztoPV-cut2-8nov16.root");
   TFile *fpol3 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-DCAztoPV-cut3-8nov16.root");
   TFile *fpol4 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-DCAztoPV-cut4-8nov16.root");
   TFile *fpol5 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-DCAztoPV-cut5-8nov16.root");
     */
   /* var 6
   TFile *fmix = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-BASE-7nov16.root");
   TFile *fpol1 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-Chi2-cut1-8nov16.root");
   TFile *fpol2 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-Chi2-cut2-8nov16.root");
   TFile *fpol3 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-Chi2-cut3-8nov16.root");
   TFile *fpol4 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-Chi2-cut4-8nov16.root");
   TFile *fpol5 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-Chi2-cut5-8nov16.root");
      */
  /* var 7
   TFile *fmix = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-BASE-7nov16.root");
   TFile *fpol1 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-Radius-cut1-8nov16.root");
   TFile *fpol2 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-Radius-cut2-8nov16.root");
   TFile *fpol3 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-Radius-cut3-8nov16.root");
   TFile *fpol4 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-Radius-cut4-8nov16.root");
   TFile *fpol5 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-Radius-cut5-8nov16.root");
      */
  /* var 8
   TFile *fmix = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-BASE-7nov16.root");
   TFile *fpol1 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-NsigePos-cut1-8nov16.root");
   TFile *fpol2 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-NsigePos-cut2-8nov16.root");
   TFile *fpol3 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-NsigePos-cut3-8nov16.root");
   TFile *fpol4 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-NsigePos-cut4-8nov16.root");
   TFile *fpol5 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-NsigePos-cut5-8nov16.root");
      */
  /* var 9
   TFile *fmix = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-BASE-7nov16.root");
   TFile *fpol1 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-NsigeNeg-cut1-8nov16.root");
   TFile *fpol2 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-NsigeNeg-cut2-8nov16.root");
   TFile *fpol3 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-NsigeNeg-cut3-8nov16.root");
   TFile *fpol4 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-NsigeNeg-cut4-8nov16.root");
   TFile *fpol5 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-NsigeNeg-cut5-8nov16.root");
      */
  /* var 10
   TFile *fmix = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-BASE-7nov16.root");
   TFile *fpol1 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-NsigPiPos-cut1-8nov16.root");
   TFile *fpol2 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-NsigPiPos-cut2-8nov16.root");
   TFile *fpol3 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-NsigPiPos-cut3-8nov16.root");
   TFile *fpol4 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-NsigPiPos-cut4-8nov16.root");
   TFile *fpol5 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-NsigPiPos-cut5-8nov16.root");
      */

  // * var 11
   TFile *fmix = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-BASE-7nov16.root");
   TFile *fpol1 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-NsigPiNeg-cut1-8nov16.root");
   TFile *fpol2 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-NsigPiNeg-cut2-8nov16.root");
   TFile *fpol3 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-NsigPiNeg-cut3-8nov16.root");
   TFile *fpol4 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-NsigPiNeg-cut4-8nov16.root");
   TFile *fpol5 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-Bins2b-Gamma-NsigPiNeg-cut5-8nov16.root");
   //   */

 
    printf("files opend \n");
    

    TH1D *hmix = (TH1D*)fmix->Get("stat");
    hmix->SetMarkerStyle(21);
    hmix->SetMarkerSize(1.0);    
    hmix->SetLineColor(1);
    hmix->SetMarkerColor(1);
    hmix->SetTitle("cutDF");

    TH1D *hpol1 = (TH1D*)fpol1->Get("stat"); 
    hpol1->SetMarkerStyle(23);
    hpol1->SetLineColor(kRed+3);
    hpol1->SetMarkerColor(kRed+3);
    hpol1->SetTitle("cut1");

    TH1D *hpol2 = (TH1D*)fpol2->Get("stat"); 
    hpol2->SetMarkerStyle(22);
    hpol2->SetLineColor(2);
    hpol2->SetMarkerColor(2);
    hpol2->SetTitle("cut2");

    TH1D *hpol3 = (TH1D*)fpol3->Get("stat");
    hpol3->SetMarkerStyle(26);
    hpol3->SetLineColor(3);
    hpol3->SetMarkerColor(3);
    hpol3->SetTitle("cut3");

    TH1D *hpol4 = (TH1D*)fpol4->Get("stat");
    hpol4->SetMarkerStyle(24);
    hpol4->SetLineColor(4);
    hpol4->SetMarkerColor(4);
    hpol4->SetTitle("cut4");

    TH1D *hpol5 = (TH1D*)fpol5->Get("stat");
    hpol5->SetMarkerStyle(25);
    hpol5->SetLineColor(6);
    hpol5->SetMarkerColor(6);
    hpol5->SetTitle("cut5");

    
  TH1D *hyielbase = (TH1D*)fmix->Get("h_Rawspectrum");     hyielbase->SetTitle("hyielbase");  
  TH1D *hyiel1 = (TH1D*)fpol1->Get("h_Rawspectrum");   hyiel1->SetTitle("hyiel1"); 
  TH1D *hyiel2 = (TH1D*)fpol2->Get("h_Rawspectrum");   hyiel2->SetTitle("hyiel2");     
  TH1D *hyiel3 = (TH1D*)fpol3->Get("h_Rawspectrum");   hyiel3->SetTitle("hyiel3");    
  TH1D *hyiel4 = (TH1D*)fpol4->Get("h_Rawspectrum");   hyiel4->SetTitle("hyiel4");    
  TH1D *hyiel5 = (TH1D*)fpol5->Get("h_Rawspectrum");   hyiel5->SetTitle("hyiel5");   
 

  for(int ii=2; ii<ptbin+2; ii++) {

  double yieldbase = 0;
  double yield1 = 0;  double yield2 = 0;  double yield3 = 0;   double yield4 = 0; double yield5 = 0;

  double mix = 0;
  double pol1 = 0;  double pol2 = 0;  double pol3 = 0;   double pol4 = 0; double pol5 = 0;
  double d1 = 0;    double d2 = 0;    double d3 = 0;     double d4 = 0;   double d5 = 0;

      
    // calculate signal-loss function in pT bins = 1 - yield-cut_i/yield_base
    yiel1_e[ii]= 1.e-6; 
    yiel2_e[ii]= 1.e-6; 
    yiel3_e[ii]= 1.e-6; 
    yiel4_e[ii]= 1.e-6; 
    yiel5_e[ii]= 1.e-6;
    printf("ey1 %f  %f  %f %f %f  pTbin %d \n ",yiel1_e[ii],yiel2_e[ii],yiel3_e[ii],yiel4_e[ii],yiel5_e[ii],  ii);

    yieldbase =hyielbase->GetBinContent(ii);
    yiel1[ii] =1- hyiel1->GetBinContent(ii)/yieldbase;  
    yiel2[ii] =1- hyiel2->GetBinContent(ii)/yieldbase;   
    yiel3[ii] =1- hyiel3->GetBinContent(ii)/yieldbase;  
    yiel4[ii] =1- hyiel4->GetBinContent(ii)/yieldbase;  
    yiel5[ii] =1- hyiel5->GetBinContent(ii)/yieldbase;

    printf("y1 %f  %f  %f %f %f  pTbin %d \n ",yiel1[ii],yiel2[ii],yiel3[ii],yiel4[ii],yiel5[ii],  ii);
        
        mix =hmix->GetBinContent(ii);
        pol1 =hpol1->GetBinContent(ii);  pol2 =hpol2->GetBinContent(ii);   pol3 =hpol3->GetBinContent(ii);
        pol4 =hpol4->GetBinContent(ii);  pol5 =hpol5->GetBinContent(ii);
        
        d1= fabs(pol1-mix); d2= fabs(pol2-mix); d3= fabs(pol3-mix); d4= fabs(pol4-mix); d5= fabs(pol5-mix);
        
        // stat errors of spectra points
	emix= hmix->GetBinError(ii);
	epol1= hpol1->GetBinError(ii);	epol2= hpol2->GetBinError(ii);	epol3= hpol3->GetBinError(ii);
 	epol4= hpol4->GetBinError(ii);	epol5= hpol5->GetBinError(ii);

        // No difference for calc. of RMC as we neglect the errors of deviations CURRENTLY!
	// ??? check error is not a SQRT
	//  emix= sqrt(mix); epol1=  sqrt(pol1); epol2=  sqrt(pol2); epol3=  sqrt(pol3); epol4=  sqrt(pol4); epol5=  sqrt(pol5);

	ed1 = sqrt( epol1*epol1 + emix*emix);
	ed2 = sqrt( epol2*epol2 + emix*emix);
	ed3 = sqrt( epol3*epol3 + emix*emix);
	ed4 = sqrt( epol4*epol4 + emix*emix);
	ed5 = sqrt( epol5*epol5 + emix*emix);


	// calculate standard deviation relative hmix value
        if(d1 ==0){
            yMpol1[ii] = d1; // 0
            yMpol1_e[ii] = d1;
        }else{
            yMpol1[ii] = d1/mix;
            yMpol1_e[ii]=1.e-4 ; // *yMpol1[ii]*sqrt(sqrt(d1)/d1*sqrt(d1)/d1+sqrt(mix)/mix*sqrt(mix)/mix);
        }
        
        if(d2 ==0){
            yMpol2[ii] = d2; // 0
            yMpol2_e[ii] = d2;
        }else{
            yMpol2[ii] = d2/mix;
            yMpol2_e[ii]=1.e-4 ; // *yMpol1[ii]*sqrt(sqrt(d1)/d1*sqrt(d1)/d1+sqrt(mix)/mix*sqrt(mix)/mix);
        }
        
        if(d3 ==0){
            yMpol3[ii] = d3;
            yMpol3_e[ii] = d3;
        }
	else{  
	  yMpol3[ii] = d3/mix;
	  yMpol3_e[ii]=1.e-4 ; // *yMpol3[ii]*sqrt(sqrt(d3)/d3*sqrt(d3)/d3+sqrt(mix)/mix*sqrt(mix)/mix);            
        }

        if(d4 ==0){
            yMpol4[ii] = d4;
            yMpol4_e[ii] = d4;
        }else{
            yMpol4[ii] = d4/mix;
            yMpol4_e[ii]=1.e-4; // *yMpol4[ii]*sqrt(sqrt(d4)/d2*sqrt(d4)/d2+sqrt(mix)/mix*sqrt(mix)/mix);           
        }

        if(d5 ==0){
            yMpol5[ii] = d5;
            yMpol5_e[ii] = d5;
        }else{
            yMpol5[ii] = d5/mix;
            yMpol5_e[ii]=1.e-4 ; // *yMpol5[ii]*sqrt(sqrt(d5)/d5*sqrt(d5)/d5+sqrt(mix)/mix*sqrt(mix)/mix);            
        }                
	// calculation of Mean Deviaton relative mix==default value
	yMmean[ii] = ( yMpol1[ii] + yMpol2[ii]+ yMpol3[ii] +  yMpol4[ii] + yMpol5[ii] )/nVars;  	
	yMmean_e[ii] = sqrt ( yMpol1_e[ii]*yMpol1_e[ii] + yMpol2_e[ii]*yMpol2_e[ii] 
                            + yMpol3_e[ii]*yMpol3_e[ii] + yMpol4_e[ii]*yMpol4_e[ii]
                            + yMpol5_e[ii]*yMpol5_e[ii]); 

        printf("dev1 %f 2 %f 3 %f 4 %f 5 %f yMMean %f +- %f   pTbin %d \n"
	       ,yMpol1[ii],yMpol2[ii],yMpol3[ii],yMpol4[ii],yMpol5[ii],yMmean[ii],yMmean_e[ii], ii);
  }

  // RMS==standard deviation calculation with (N-1) normalization
  for(int ii=2; ii<ptbin+2; ii++) {
          
    // dyMean==Mean difference,    dyMean4 == standard deviation
    dyMean[ii]=sqrt( ( (yMpol1[ii]-yMmean[ii])*(yMpol1[ii]-yMmean[ii]) +
		       (yMpol2[ii]-yMmean[ii])*(yMpol2[ii]-yMmean[ii]) +
		       (yMpol3[ii]-yMmean[ii])*(yMpol3[ii]-yMmean[ii]) +
		       (yMpol4[ii]-yMmean[ii])*(yMpol4[ii]-yMmean[ii]) + 
		       (yMpol5[ii]-yMmean[ii])*(yMpol5[ii]-yMmean[ii]) )/(nVars-1) )    ;
    dyMean_e[ii]=1.e-5;
 
    printf("dyMean %f +- %f  pTbin %d \n ",dyMean[ii],dyMean_e[ii], ii);
  }
  printf("diff calc done---------> \n");    
  
  ///==================
  TH1D *hyie1 = new TH1D("hyie1","SigLoss1",ptbin+1,ptedges);
  hyie1->SetLineColor(kRed+3);
  hyie1->SetMarkerColor(kRed+3);
  hyie1->SetLineWidth(2);
  hyie1->SetMinimum(0.001);
  hyie1->SetMaximum(1.5);
  hyie1->SetMarkerSize(1.5);
  hyie1->SetMarkerStyle(23);
  hyie1->SetTitle("cut1");
  for(int i=2; i<ptbin+2; i++) {
    hyie1->SetBinContent(i,yiel1[i]);        hyie1->SetBinError(i,yiel1_e[i]);    }

  TH1D *hyie2 = new TH1D("hyie2","SigLoss2",ptbin+1,ptedges);
  hyie2->SetLineColor(2);
  hyie2->SetMarkerColor(2);
  hyie2->SetLineWidth(2);
  hyie2->SetMinimum(0.001);
  hyie2->SetMaximum(1.5);
  hyie2->SetMarkerSize(1.5);
  hyie2->SetMarkerStyle(22);
  hyie2->SetTitle("cut2");
  for(int i=2; i<ptbin+2; i++) {
    hyie2->SetBinContent(i,yiel2[i]);        hyie2->SetBinError(i,yiel2_e[i]);    }

  TH1D *hyie3 = new TH1D("hyie3","SigLoss3",ptbin+1,ptedges);
  hyie3->SetLineColor(3);
  hyie3->SetMarkerColor(3);
  hyie3->SetLineWidth(2);
  hyie3->SetMinimum(0.001);
  hyie3->SetMaximum(1.5);
  hyie3->SetMarkerSize(1.5);
  hyie3->SetMarkerStyle(26);
  hyie3->SetTitle("cut3");
  for(int i=2; i<ptbin+2; i++) {
    hyie3->SetBinContent(i,yiel3[i]);        hyie3->SetBinError(i,yiel3_e[i]);    }

  TH1D *hyie4 = new TH1D("hyie4","SigLoss4",ptbin+1,ptedges);
  hyie4->SetLineColor(4);
  hyie4->SetMarkerColor(4);
  hyie4->SetLineWidth(2);
  hyie4->SetMinimum(0.001);
  hyie4->SetMaximum(1.5);
  hyie4->SetMarkerSize(1.5);
  hyie4->SetMarkerStyle(24);
  hyie4->SetTitle("cut4");
  for(int i=2; i<ptbin+2; i++) {
    hyie4->SetBinContent(i,yiel4[i]);        hyie4->SetBinError(i,yiel4_e[i]);    }

  TH1D *hyie5= new TH1D("hyie5","SigLoss5",ptbin+1,ptedges);
  hyie5->SetLineColor(6);
  hyie5->SetMarkerColor(6);
  hyie5->SetLineWidth(2);
  hyie5->SetMinimum(0.001);
  hyie5->SetMaximum(1.5);
  hyie5->SetMarkerSize(1.5);
  hyie5->SetMarkerStyle(25);
  hyie5->SetTitle("cut5");
  for(int i=2; i<ptbin+2; i++) {
    hyie5->SetBinContent(i,yiel5[i]);        hyie5->SetBinError(i,yiel5_e[i]);    }


  TCanvas *cSigLos = new TCanvas("cSigLos","Loss Sigma0",0,0,800,1000);
  //  cSigLos->Divide (2,3) ;
 
  hyie1->Draw("");
  hyie2->Draw("same");
  hyie3->Draw("same");
  hyie4->Draw("same");
  hyie5->Draw("same");
  TLegend *legl1 = new TLegend(0.6,0.5,0.9,0.9); // TLegend( X0, Y0, X1, Y1 )
  legl1->AddEntry(hmix,"Base","lp");
  legl1->AddEntry(hpol1,"cut1","lp");
  legl1->AddEntry(hpol2,"cut2","lp");
  legl1->AddEntry(hpol3,"cut3","lp");
  legl1->AddEntry(hpol4,"cut4","lp");
  legl1->AddEntry(hpol5,"cut5","lp");
  legl1->Draw("same");



    TCanvas *RawYield_tot = new TCanvas("RawYield_tot","Sigma0 raw yield",0,0,800,1000);
    RawYield_tot->SetLogy(1);
    RawYield_tot->cd();

    TH1F *boxU = new TH1F("boxU","",300,0.,30.);
    boxU->SetAxisRange(0.0,10.50,"X");
    boxU->SetAxisRange(1.e-6, 4.e-2,"Y");
    boxU->SetXTitle("p_{T}, GeV/c");
    //Youra-pi0  boxU->SetYTitle("1/N_{ev} d^{3}N/p_{T}dp_{T}dyd#phi (GeV/c)^{-2}");
    boxU->SetYTitle("(1/N_{inel}) d^{2}N/dydp_{T}, (GeV/c)^{-1}");
    boxU->SetTitleSize(0.04,"X");
    boxU->SetTitleSize(0.02,"Y");
    boxU->SetTitleOffset(1.10,"Y");
    boxU->SetLabelSize(0.02,"XY");
 
    boxU->Draw("");

    hmix->Draw("same");
    hpol1->Draw("same");
    hpol2->Draw("same");
    hpol3->Draw("same");
    hpol4->Draw("same");
    hpol5->Draw("same");
    //    RawYield_tot->BuildLegend(0.78,0.4,0.98,0.75,"");
 
   
    legl1->Draw("same");
    //====================================\\    
        

    TH1D *hdiff1 = new TH1D("hdiff1","pol1 - mix",ptbin+1,ptedges);
    hdiff1->SetLineColor(kRed+3);
    hdiff1->SetMarkerColor(kRed+3);
    hdiff1->SetLineWidth(2);
    hdiff1->SetMinimum(0.001);
    hdiff1->SetMaximum(1.5);
    hdiff1->SetMarkerSize(1.5);
    hdiff1->SetMarkerStyle(23);
    hdiff1->SetTitle("cut1");

    for(int i=2; i<ptbin+2; i++) {
        hdiff1->SetBinContent(i,yMpol1[i]);
        hdiff1->SetBinError(i,yMpol1_e[i]);
    }

    TH1D *hdiff2 = new TH1D("hdiff2","pol3 - mix",ptbin+1,ptedges);
    hdiff2->SetLineColor(2);
    hdiff2->SetMarkerColor(2);
    hdiff2->SetLineWidth(2);
    hdiff2->SetMinimum(0.001);
    hdiff2->SetMaximum(1.5);
    hdiff2->SetTitle("cut2");
    hdiff2->SetMarkerSize(1.5);
    hdiff2->SetMarkerStyle(22);
   for(int i=2; i<ptbin+2; i++) {
        hdiff2->SetBinContent(i,yMpol2[i]);
        hdiff2->SetBinError(i,yMpol2_e[i]);
    }
  
    
    TH1D *hdiff3 = new TH1D("hdiff3","pol3 - mix",ptbin+1,ptedges);
    hdiff3->SetLineColor(3);
    hdiff3->SetMarkerColor(3);
    hdiff3->SetLineWidth(2);
    hdiff3->SetMinimum(0.001);
    hdiff3->SetMaximum(1.5);
    hdiff3->SetTitle("cut3");
    hdiff3->SetMarkerSize(1.5);
    hdiff3->SetMarkerStyle(26);
   for(int i=2; i<ptbin+2; i++) {
        hdiff3->SetBinContent(i,yMpol3[i]);
        hdiff3->SetBinError(i,yMpol3_e[i]);
    }
    
    TH1D *hdiff4 = new TH1D("hdiff4","pol4 - mix",ptbin+1,ptedges);
    hdiff4->SetLineColor(4);
    hdiff4->SetMarkerColor(4);
    hdiff4->SetLineWidth(2);
    hdiff4->SetMinimum(0.001);
    hdiff4->SetMaximum(1.5);
    hdiff4->SetTitle("cut4");
    hdiff4->SetMarkerSize(1.5);
    hdiff4->SetMarkerStyle(24);

    for(int i=2; i<ptbin+2; i++) {
      hdiff4->SetBinContent(i,yMpol4[i]);
      hdiff4->SetBinError(i,yMpol4_e[i]);
    }
       
    TH1D *hdiff5 = new TH1D("hdiff5","pol5 - mix",ptbin+1,ptedges);
    hdiff5->SetLineColor(6);
    hdiff5->SetMarkerColor(6);
    hdiff5->SetLineWidth(2);
    hdiff5->SetMinimum(0.001);
    hdiff5->SetMaximum(1.5);
    hdiff5->SetTitle("cut5");
    hdiff5->SetMarkerSize(1.5);
    hdiff5->SetMarkerStyle(25);
    for(int i=2; i<ptbin+2; i++) {
      hdiff5->SetBinContent(i,yMpol5[i]);
      hdiff5->SetBinError(i,yMpol5_e[i]);
    }
   
    TH1D *hmeandiff = new TH1D("hmeandiff","Mean difference",ptbin+1,ptedges);
    hmeandiff->SetLineColor(1);
    hmeandiff->SetLineWidth(2);
    hmeandiff->SetMinimum(0.001);
    hmeandiff->SetMaximum(1.5);
    hmeandiff->SetTitle("Mean deviation");
    hmeandiff->SetMarkerSize(2.5);
    hmeandiff->SetMarkerColor(1);
    hmeandiff->SetMarkerStyle(20);
    for(int i=2; i<ptbin+2; i++) {
      hmeandiff->SetBinContent(i,yMmean[i]);
      hmeandiff->SetBinError(i,yMmean_e[i]);
      printf("hmean %f  bin %d \n",yMmean[i],i);
    }
   
    TH1D *hdmeandiff = new TH1D("hdmeandiff","Mean deviation of difference",ptbin+1,ptedges);
    hdmeandiff->SetLineColor(1);
    hdmeandiff->SetMarkerColor(1);
    hdmeandiff->SetLineWidth(2);
    hdmeandiff->SetMinimum(0.001);
    hdmeandiff->SetMaximum(1.5);
    hdmeandiff->SetTitle("Dispersion of deviation");
    hdmeandiff->SetMarkerSize(2.5);
    hdmeandiff->SetMarkerStyle(29);
    for(int i=2; i<ptbin+2; i++) {
      hdmeandiff->SetBinContent(i,dyMean[i]);
      hdmeandiff->SetBinError(i,dyMean_e[i]);
      printf("hdmean %f  bin %d \n",dyMean[i],i);
    }
    printf("diff  done---------> \n");    

 
  
     TCanvas *Diff_tot = new TCanvas("Diff_tot","Sigma0 diff",0,0,800,1000);
     Diff_tot->cd();
     //     Diff_tot->SetLogy(1);
    
     
      TH1F *box = new TH1F("box","",300,0.,30.);
     box->SetAxisRange(0.0,10.50,"X");
     box->SetAxisRange(0., 0.55,"Y");
     box->SetXTitle("p_{T}, GeV/c");
     //Youra-pi0  boxU->SetYTitle("1/N_{ev} d^{3}N/p_{T}dp_{T}dyd#phi (GeV/c)^{-2}");
     // box->SetYTitle("(1/N) d^{2}N/dydp_{T}, (GeV/c)^{-1}");
     box->SetYTitle("(Y_{i} - Y_{def})/Y_{def}");
     box->SetTitleSize(0.04,"X");
     box->SetTitleSize(0.04,"Y");
     box->SetTitleOffset(1.1,"Y");
     box->SetLabelSize(0.02,"XY");
     box->Draw("");
     
     hdmeandiff->Draw("Esame");
     hmeandiff->Draw("Esame");
     //     hmix->Draw("Esame");  // it NOT a difference, but RAW data
     hdiff1->Draw("Esame");
     hdiff2->Draw("Esame");
     hdiff3->Draw("Esame");
     hdiff4->Draw("Esame");
     hdiff5->Draw("Esame");
     
     //     Diff_tot->BuildLegend(0.78,0.6,0.98,0.75,"");

    TLegend *legl = new TLegend(0.6,0.5,0.9,0.9); // TLegend( X0, Y0, X1, Y1 )
    //    legl->AddEntry(hmeandiff,"Mean deviation","lp");

    legl->AddEntry(hdmeandiff,"RMS of deviations","lp");
    legl->AddEntry(hmeandiff,"Mean difference","lp");
    legl->AddEntry(hdiff1,"cut1","lp");
    legl->AddEntry(hdiff2,"cut2","lp");
    legl->AddEntry(hdiff3,"cut3","lp");
    legl->AddEntry(hdiff4,"cut4","lp");
    legl->AddEntry(hdiff5,"cut5","lp");
    legl->Draw("same");
  
    printf("Draw  done---------> \n");  
    
     //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // For Barlow cross-check difference in quadrature of stat errors:
    for(int ii=2; ii<ptbin+2; ii++) {

      double mix = 0;
      double pol1 = 0;  double pol2 = 0;  double pol3 = 0;   double pol4 = 0; double pol5 = 0;
      double d1 = 0;    double d2 = 0;    double d3 = 0;     double d4 = 0;   double d5 = 0;
        
        
      mix =hmix->GetBinContent(ii);
      pol1 =hpol1->GetBinContent(ii);  pol2 =hpol2->GetBinContent(ii);   pol3 =hpol3->GetBinContent(ii);
      pol4 =hpol4->GetBinContent(ii);  pol5 =hpol5->GetBinContent(ii);
        
      d1= fabs(pol1-mix); d2= fabs(pol2-mix); d3= fabs(pol3-mix); d4= fabs(pol4-mix); d5= fabs(pol5-mix);
        
        // stat errors of spectra points
      emix= hmix->GetBinError(ii);
      epol1= hpol1->GetBinError(ii);	epol2= hpol2->GetBinError(ii);	epol3= hpol3->GetBinError(ii);
      epol4= hpol4->GetBinError(ii);	epol5= hpol5->GetBinError(ii);
        
      diff1[ii]= ( pol1 - mix );  diff1_e[ii] = sqrt( epol1*epol1 + emix*emix );
      diff2[ii]= ( pol2 - mix );  diff2_e[ii] = sqrt( epol2*epol2 + emix*emix );
      diff3[ii]= ( pol3 - mix );  diff3_e[ii] = sqrt( epol3*epol3 + emix*emix );
      diff4[ii]= ( pol4 - mix );  diff4_e[ii] = sqrt( epol4*epol4 + emix*emix );
      diff5[ii]= ( pol5 - mix );  diff5_e[ii] = sqrt( epol5*epol5 + emix*emix );

      reldiff1[ii] = diff1[ii]/pol1;   reldiff1_e[ii] = 1.e-6 ; //diff1_e[ii]/pol1 ;
      reldiff2[ii] = diff2[ii]/pol2;   reldiff2_e[ii] = 1.e-6 ; // diff2_e[ii]/pol1 ;
      reldiff3[ii] = diff3[ii]/pol3;   reldiff3_e[ii] = 1.e-6 ; // diff3_e[ii]/pol1 ;
      reldiff4[ii] = diff4[ii]/pol4;   reldiff4_e[ii] = 1.e-6 ; //diff4_e[ii]/pol1 ;
      reldiff5[ii] = diff5[ii]/pol5;   reldiff5_e[ii] = 1.e-6 ; // diff5_e[ii]/pol1 ;


      // check:  relstat1[ii]==relstat1_e[ii]
      relstat1[ii] = epol1/pol1;   relstat1_e[ii] = 1.e-6 ; //  epol1/pol1 ;
      relstat2[ii] = epol2/pol2;   relstat2_e[ii] = 1.e-6 ; //  epol2/pol2 ;
      relstat3[ii] = epol3/pol3;   relstat3_e[ii] = 1.e-6 ; //  epol3/pol3 ;
      relstat4[ii] = epol4/pol4;   relstat4_e[ii] = 1.e-6 ; //  epol4/pol4 ;
      relstat5[ii] = epol5/pol5;   relstat5_e[ii] = 1.e-6 ; //  epol5/pol5 ;

      // have to understand it
      delta1[ii] = sqrt( fabs( epol1*epol1 - emix*emix ) );
      delta2[ii] = sqrt( fabs( epol2*epol2 - emix*emix ) );
      delta3[ii] = sqrt( fabs( epol3*epol3 - emix*emix ) );
      delta4[ii] = sqrt( fabs( epol4*epol4 - emix*emix ) );
      delta5[ii] = sqrt( fabs( epol5*epol5 - emix*emix ) );

      delta1_e[ii] = 1.e-6 ; // sqrt( fabs( epol1*epol1 - emix*emix ) );
      delta2_e[ii] = 1.e-6 ; // sqrt( fabs( epol2*epol2 - emix*emix ) );
      delta3_e[ii] = 1.e-6 ; // sqrt( fabs( epol3*epol3 - emix*emix ) );
      delta4_e[ii] = 1.e-6 ; // sqrt( fabs( epol4*epol4 - emix*emix ) );
      delta5_e[ii] = 1.e-6 ; // sqrt( fabs( epol5*epol5 - emix*emix ) );
      
      ratdiff1[ii] = 0; // (pol1  - mix)/ delta1[ii]   ;
      ratdiff2[ii] = 0; //  (pol2  - mix)/ delta2[ii]   ;
      ratdiff3[ii] = 0; //  (pol3  - mix)/ delta3[ii]   ;
      ratdiff4[ii] = 0; //  (pol4  - mix)/ delta4[ii]   ;
      ratdiff5[ii] = 0; //  (pol5  - mix)/ delta5[ii]   ;

      ratdiff1[ii] = (pol1  - mix)/ delta1[ii]   ;
      ratdiff2[ii] = (pol2  - mix)/ delta2[ii]   ;
      ratdiff3[ii] = (pol3  - mix)/ delta3[ii]   ;
      ratdiff4[ii] = (pol4  - mix)/ delta4[ii]   ;
      ratdiff5[ii] = (pol5  - mix)/ delta5[ii]   ;

      ratdiff1_e[ii] = 1.e-6 ; // (pol1  - mix)/ delta1[ii]   ;
      ratdiff2_e[ii] = 1.e-6 ; // (pol2  - mix)/ delta2[ii]   ;
      ratdiff3_e[ii] = 1.e-6 ; // (pol3  - mix)/ delta3[ii]   ;
      ratdiff4_e[ii] = 1.e-6 ; // (pol4  - mix)/ delta4[ii]   ;
      ratdiff5_e[ii] = 1.e-6 ; // (pol5  - mix)/ delta5[ii]   ;

      hRatDiffSum->Fill( ratdiff1[ii]);    hRatDiff1->Fill( ratdiff1[ii]); 
      hRatDiffSum->Fill( ratdiff2[ii]);    hRatDiff2->Fill( ratdiff2[ii]); 
      hRatDiffSum->Fill( ratdiff3[ii]);    hRatDiff3->Fill( ratdiff3[ii]); 
      hRatDiffSum->Fill( ratdiff4[ii]);    hRatDiff4->Fill( ratdiff4[ii]); 
      hRatDiffSum->Fill( ratdiff5[ii]);    hRatDiff5->Fill( ratdiff5[ii]); 

      hRatDiffPt[ii]->Fill( ratdiff1[ii] ); hRatDiffPt[ii]->Fill( ratdiff2[ii] ); hRatDiffPt[ii]->Fill( ratdiff3[ii] ); 
      hRatDiffPt[ii]->Fill( ratdiff4[ii] ); hRatDiffPt[ii]->Fill( ratdiff5[ii] );
   }
   printf("Barlow calc done---------> \n");    

  
   TH1D *hRelDiff1 = new TH1D("hRelDiff1","diff1/pol1",ptbin+1,ptedges);
   hRelDiff1->SetLineColor(kRed+3);   hRelDiff1->SetMarkerColor(kRed+3);
   hRelDiff1->SetLineWidth(2);   hRelDiff1->SetMinimum(0.001);   hRelDiff1->SetMaximum(1.5);
   hRelDiff1->SetMarkerSize(1.5);   hRelDiff1->SetMarkerStyle(23);   hRelDiff1->SetTitle("reldiff1");
   for(int i=2; i<ptbin+2; i++) {
     hRelDiff1->SetBinContent(i,fabs(reldiff1[i]));     hRelDiff1->SetBinError(i,reldiff1_e[i]);
   }
   TH1D *hRelDiff2 = new TH1D("hRelDiff2","diff2/pol3",ptbin+1,ptedges);
   hRelDiff2->SetLineColor(2);   hRelDiff2->SetMarkerColor(2);
   hRelDiff2->SetLineWidth(2);        hRelDiff2->SetMinimum(0.001);    hRelDiff2->SetMaximum(1.5);
   hRelDiff2->SetMarkerSize(1.5);     hRelDiff2->SetMarkerStyle(22);   hRelDiff2->SetTitle("reldiff2");
   for(int i=2; i<ptbin+2; i++) {
     hRelDiff2->SetBinContent(i,fabs(reldiff2[i]));     hRelDiff2->SetBinError(i,reldiff2_e[i]);
   }
   TH1D *hRelDiff3 = new TH1D("hRelDiff3","diff3/pol3",ptbin+1,ptedges);
   hRelDiff3->SetLineColor(3);   hRelDiff3->SetMarkerColor(3);
   hRelDiff3->SetLineWidth(2);   hRelDiff3->SetMinimum(0.001);   hRelDiff3->SetMaximum(1.5);
   hRelDiff3->SetMarkerSize(1.5);   hRelDiff3->SetMarkerStyle(26);   hRelDiff3->SetTitle("reldiff3");
   for(int i=2; i<ptbin+2; i++) {
     hRelDiff3->SetBinContent(i,fabs(reldiff3[i]));     hRelDiff3->SetBinError(i,reldiff3_e[i]);
   }
   TH1D *hRelDiff4 = new TH1D("hRelDiff4","diff4/pol4",ptbin+1,ptedges);
   hRelDiff4->SetLineColor(4);   hRelDiff4->SetMarkerColor(4);
   hRelDiff4->SetLineWidth(2);   hRelDiff4->SetMinimum(0.001);   hRelDiff4->SetMaximum(1.5);
   hRelDiff4->SetMarkerSize(1.5);   hRelDiff4->SetMarkerStyle(24);   hRelDiff4->SetTitle("reldiff4");
   for(int i=2; i<ptbin+2; i++) {
     hRelDiff4->SetBinContent(i,fabs(reldiff4[i]));     hRelDiff4->SetBinError(i,reldiff4_e[i]);
   }
   TH1D *hRelDiff5 = new TH1D("hRelDiff5","diff1/pol1",ptbin+1,ptedges);
   hRelDiff5->SetLineColor(6);   hRelDiff5->SetMarkerColor(6);
   hRelDiff5->SetLineWidth(2);   hRelDiff5->SetMinimum(0.001);   hRelDiff5->SetMaximum(1.5);
   hRelDiff5->SetMarkerSize(1.5);   hRelDiff5->SetMarkerStyle(25);   hRelDiff5->SetTitle("reldiff5");
   for(int i=2; i<ptbin+2; i++) {
     hRelDiff5->SetBinContent(i,fabs(reldiff5[i]));     hRelDiff5->SetBinError(i,reldiff5_e[i]);
   }
   TCanvas *cRelDiff = new TCanvas("cRelDiff","Rel Diff",0,0,800,1000);
   cRelDiff->cd();
   hRelDiff1->Draw("");
   hRelDiff2->Draw("same");
   hRelDiff3->Draw("same");
   hRelDiff4->Draw("same");
   hRelDiff5->Draw("same");


   // gStyle->SetOptFit(111);
   TH1D *hRelStat1 = new TH1D("hRelStat1","diff1/pol1",ptbin+1,ptedges);
   hRelStat1->SetLineColor(kRed+3);   hRelStat1->SetMarkerColor(kRed+3);
   hRelStat1->SetLineWidth(2);   hRelStat1->SetMinimum(0.001);   hRelStat1->SetMaximum(.2);
   hRelStat1->SetMarkerSize(0.5);   hRelStat1->SetMarkerStyle(23);   hRelStat1->SetTitle("relstat1");
   for(int i=2; i<ptbin+2; i++) {
     hRelStat1->SetBinContent(i,relstat1[i]);     hRelStat1->SetBinError(i,relstat1_e[i]);
   }
   //   hRelStat1->Fit("pol0","","",1.1, 8.);

   TH1D *hRelStat2 = new TH1D("hRelStat2","diff2/pol3",ptbin+1,ptedges);
   hRelStat2->SetLineColor(2);   hRelStat2->SetMarkerColor(2);
   hRelStat2->SetLineWidth(2);        hRelStat2->SetMinimum(0.001);    hRelStat2->SetMaximum(.2);
   hRelStat2->SetMarkerSize(0.5);     hRelStat2->SetMarkerStyle(22);   hRelStat2->SetTitle("relstat2");
   for(int i=2; i<ptbin+2; i++) {
     hRelStat2->SetBinContent(i,relstat2[i]);     hRelStat2->SetBinError(i,relstat2_e[i]);
   }
   //   hRelStat2->Fit("pol0","","",1.1, 8.);

   TH1D *hRelStat3 = new TH1D("hRelStat3","diff3/pol3",ptbin+1,ptedges);
   hRelStat3->SetLineColor(3);   hRelStat3->SetMarkerColor(3);
   hRelStat3->SetLineWidth(2);   hRelStat3->SetMinimum(0.001);   hRelStat3->SetMaximum(.2);
   hRelStat3->SetMarkerSize(0.5);   hRelStat3->SetMarkerStyle(26);   hRelStat3->SetTitle("relstat3");
   for(int i=2; i<ptbin+2; i++) {
     hRelStat3->SetBinContent(i,relstat3[i]);     hRelStat3->SetBinError(i,relstat3_e[i]);
   }
   //   hRelStat3->Fit("pol0","","",1.1, 8.);

   TH1D *hRelStat4 = new TH1D("hRelStat4","diff4/pol4",ptbin+1,ptedges);
   hRelStat4->SetLineColor(4);   hRelStat4->SetMarkerColor(4);
   hRelStat4->SetLineWidth(2);   hRelStat4->SetMinimum(0.001);   hRelStat4->SetMaximum(.2);
   hRelStat4->SetMarkerSize(0.5);   hRelStat4->SetMarkerStyle(24);   hRelStat4->SetTitle("relstat4");
   for(int i=2; i<ptbin+2; i++) {
     hRelStat4->SetBinContent(i,relstat4[i]);     hRelStat4->SetBinError(i,relstat4_e[i]);
   }
   //   hRelStat4->Fit("pol0","","",1.1, 8.);

   TH1D *hRelStat5 = new TH1D("hRelStat5","diff1/pol1",ptbin+1,ptedges);
   hRelStat5->SetLineColor(6);   hRelStat5->SetMarkerColor(6);
   hRelStat5->SetLineWidth(2);   hRelStat5->SetMinimum(0.001);   hRelStat5->SetMaximum(.2);
   hRelStat5->SetMarkerSize(0.5);   hRelStat5->SetMarkerStyle(25);   hRelStat5->SetTitle("relstat5");
   for(int i=2; i<ptbin+2; i++) {
     hRelStat5->SetBinContent(i,relstat5[i]);     hRelStat5->SetBinError(i,relstat5_e[i]);
   }
   //   hRelStat5->Fit("pol0","","",1.1, 8.);


   TCanvas *cRelStat = new TCanvas("cRelStat","Rel Stat Error vs Cut Variations",0,0,800,1000);
   cRelStat->Divide (2,3) ;
   cRelStat->cd (1) ;
   hRelStat1->Draw("");
   hRelDiff1->Draw("same"); 
   cRelStat->cd (2) ;
   hRelStat2->Draw("");
   hRelDiff2->Draw("same");
 
   cRelStat->cd (3) ;
   // gStyle->SetOptFit(111);
   hRelStat3->Draw("");
   // gStyle->SetOptFit(0);
   hRelDiff3->Draw("same"); 
   cRelStat->cd (4) ;
   hRelStat4->Draw("");
   hRelDiff4->Draw("same"); 
   cRelStat->cd (5) ;
   hRelStat5->Draw("");
   hRelDiff5->Draw("same"); 

   cRelStat->cd(6);
   hRelStat1->Draw("");
   hRelStat2->Draw("same");
   hRelStat3->Draw("same");
   hRelStat4->Draw("same");
   hRelStat5->Draw("same");

    printf("Histos ratios started \n");
   //  TH1D *hRatDiff1 = new TH1D("hRatDiff1","diff1/pol1",ptbin+1,ptedges);
   hRatDiff1->SetLineColor(kRed+3);   hRatDiff1->SetMarkerColor(kRed+3);
   hRatDiff1->SetLineWidth(2);   hRatDiff1->SetMinimum(0.001);   hRatDiff1->SetMaximum(1.5);
   hRatDiff1->SetMarkerSize(1.5);   hRatDiff1->SetMarkerStyle(23);   hRatDiff1->SetTitle("ratdiff1");
   //   for(int i=2; i<ptbin+2; i++) {     hRatDiff1->Fill(ratdiff1[i]);  
     //     hRatDiff1->SetBinContent(i,ratdiff1[i]);     hRatDiff1->SetBinError(i,ratdiff1_e[i]);   }
   //   TH1D *hRatDiff2 = new TH1D("hRatDiff2","diff2/pol3",ptbin+1,ptedges);
   hRatDiff2->SetLineColor(2);   hRatDiff2->SetMarkerColor(2);
   hRatDiff2->SetLineWidth(2);        hRatDiff2->SetMinimum(0.001);    hRatDiff2->SetMaximum(1.5);
   hRatDiff2->SetMarkerSize(1.5);     hRatDiff2->SetMarkerStyle(22);   hRatDiff2->SetTitle("ratdiff2");
   // for(int i=2; i<ptbin+2; i++) {     hRatDiff2->Fill(ratdiff2[i]);  
     //     hRatDiff2->SetBinContent(i,ratdiff2[i]);     hRatDiff2->SetBinError(i,ratdiff2_e[i]);   }
   //   TH1D *hRatDiff3 = new TH1D("hRatDiff3","diff3/pol3",ptbin+1,ptedges);
   hRatDiff3->SetLineColor(3);   hRatDiff3->SetMarkerColor(3);
   hRatDiff3->SetLineWidth(2);   hRatDiff3->SetMinimum(0.001);   hRatDiff3->SetMaximum(1.5);
   hRatDiff3->SetMarkerSize(1.5);   hRatDiff3->SetMarkerStyle(26);   hRatDiff3->SetTitle("ratdiff3");
   //   for(int i=2; i<ptbin+2; i++) {     hRatDiff3->Fill(ratdiff3[i]);  
     //  hRatDiff3->SetBinContent(i,ratdiff3[i]);     hRatDiff3->SetBinError(i,ratdiff3_e[i]);   }
   //   TH1D *hRatDiff4 = new TH1D("hRatDiff4","diff4/pol4",ptbin+1,ptedges);
   hRatDiff4->SetLineColor(4);   hRatDiff4->SetMarkerColor(4);
   hRatDiff4->SetLineWidth(2);   hRatDiff4->SetMinimum(0.001);   hRatDiff4->SetMaximum(1.5);
   hRatDiff4->SetMarkerSize(1.5);   hRatDiff4->SetMarkerStyle(24);   hRatDiff4->SetTitle("ratdiff4");
   // for(int i=2; i<ptbin+2; i++) {     hRatDiff4->Fill(ratdiff4[i]);  
     //hRatDiff4->SetBinContent(i,ratdiff4[i]);     hRatDiff4->SetBinError(i,ratdiff4_e[i]);   }
   //   TH1D *hRatDiff5 = new TH1D("hRatDiff5","diff1/pol1",ptbin+1,ptedges);
   hRatDiff5->SetLineColor(6);   hRatDiff5->SetMarkerColor(6);
   hRatDiff5->SetLineWidth(2);   hRatDiff5->SetMinimum(0.001);   hRatDiff5->SetMaximum(1.5);
   hRatDiff5->SetMarkerSize(1.5);   hRatDiff5->SetMarkerStyle(25);   hRatDiff5->SetTitle("ratdiff5");
   //   for(int i=2; i<ptbin+2; i++) {     hRatDiff5->Fill(ratdiff5[i]);  
     //hRatDiff5->SetBinContent(i,ratdiff5[i]);     hRatDiff5->SetBinError(i,ratdiff5_e[i]);   }
   TCanvas *cRatDiff = new TCanvas("cRatDiff","Ratio Diff",0,0,800,1000);
  gStyle->SetOptStat(111111);
  cRatDiff->Divide (3,2) ;
   cRatDiff->cd (1) ;
  gStyle->SetOptStat(111111);
     hRatDiff1->Draw("");
   cRatDiff->cd (2) ;
  gStyle->SetOptStat(111111);
     hRatDiff2->Draw("same");
   cRatDiff->cd (3) ;
  gStyle->SetOptStat(111111);
    hRatDiff3->Draw("same");
   cRatDiff->cd (4) ;
  gStyle->SetOptStat(111111);
    hRatDiff4->Draw("same");
   cRatDiff->cd (5) ;
  gStyle->SetOptStat(111111);
     hRatDiff5->Draw("same");
   cRatDiff->cd (6) ;
    hRatDiffSum->Draw("same");

    
 TCanvas *cRatDiffSum = new TCanvas("cRatDiffSum","Ratio Diff Sum",0,0,800,1000);
  gStyle->SetOptStat(111111);
  cRatDiffSum->Divide(1,2);
  cRatDiffSum->cd(1);
 hRatDiffSum->Draw("same");
 gStyle->SetOptStat(111111);
 cRatDiffSum->cd(2);
 // gStyle->SetOptStat(0000);
    TH1F *box2 = new TH1F("box2","",300,0.,30.);
    box2->SetAxisRange(0.0, 4, "X");
    box2->SetAxisRange(0., 1.1,"Y");
    box2->SetXTitle("RMS");
    //Youra-pi0  boxU->SetYTitle("1/N_{ev} d^{3}N/p_{T}dp_{T}dyd#phi (GeV/c)^{-2}");
    box2->SetYTitle("ratio");
    box2->SetTitleSize(0.04,"X");
    box2->SetTitleSize(0.02,"Y");
    box2->SetTitleOffset(1.10,"Y");
    box2->SetLabelSize(0.02,"XY");
    //  box2->SetOptStat(0);
    //gStyle->SetOptStat(0000);
    box2->Draw("");

 Int_t nrangem3 = hRatDiffSum->GetXaxis()->FindBin(-3.0);
 Int_t nrangep3 = hRatDiffSum->GetXaxis()->FindBin(3.0);
 Double_t diffsum3 = 0;

 Int_t nrangem2 = hRatDiffSum->GetXaxis()->FindBin(-2.0);
 Int_t nrangep2 = hRatDiffSum->GetXaxis()->FindBin(2.0);
 Double_t diffsum2 = 0;

 Int_t nrangem1 = hRatDiffSum->GetXaxis()->FindBin(-1.0);
 Int_t nrangep1 = hRatDiffSum->GetXaxis()->FindBin(1.0);
 Double_t diffsum1 = 0;
 for(int ii=nrangem1; ii<=nrangep1; ii++) {
  diffsum1 +=    hRatDiffSum->GetBinContent(ii);  
 }
 for(int ii=nrangem2; ii<=nrangep2; ii++) {
  diffsum2 +=    hRatDiffSum->GetBinContent(ii);  
 }
 for(int ii=nrangem3; ii<=nrangep3; ii++) {
  diffsum3 +=    hRatDiffSum->GetBinContent(ii);  
 }

 // printf(" nrangem2 %d nrangep2 %d sum %f ratio/40 %f \n",nrangem2, nrangep2,diffsum,  diffsum/40 ); 
 // printf(" nrangem1 %d nrangep1 %d sum1 %f ratio1/40 %f \n",nrangem1, nrangep1,diffsum1,  diffsum1/40 ); 

 if (diffsum3!= 0)   printf("+-3sigma sum %f ratio %f rest %f \n",
	diffsum3,  diffsum3/40, 40 - diffsum3 ); 
 printf("+- 3 +-2sigma sum %f ratio %f rest %f    +-1sigma  sum1 %f ratio1 %f rest1 %f \n",
	diffsum2,  diffsum2/40, 40 - diffsum2, diffsum1,  diffsum1/40, 40 - diffsum1 ); 
 // printf("m1 %d nrangep1 %d sum1 %f ratio1/40 %f \n",nrangem1, nrangep1,diffsum1,  diffsum1/40 ); 
 // gStyle->SetOptStat(0000);
 if (diffsum3!= 0){
   TLine *line3 = new TLine(0, diffsum3/40, 3,  diffsum3/40);
  line3->SetLineColor(kBlue);
  line3->SetLineWidth(7);
  line3->Draw("same");
 }

 TLine *line2 = new TLine(0, diffsum2/40,2,  diffsum2/40);
 TLine *linedef2 = new TLine(0, 0.9545, 2 ,  0.9545);
 linedef2->SetLineColor(kRed);
  line2->SetLineColor(kBlue);
line2->SetLineWidth(4);
linedef2->SetLineWidth(4);
  line2->Draw("same");
  linedef2->Draw("same");

 TLine *line1 = new TLine(0, diffsum1/40, 1,  diffsum1/40);
 TLine *linedef1 = new TLine( 0, 0.6827,  1 ,  0.6827);
 linedef1->SetLineColor(kRed);
 linedef1->SetLineWidth(2);
  line1->SetLineColor(kBlue);
 line1->SetLineWidth(1);
  line1->Draw("same");
  linedef1->Draw("same");
  linedef1->SetLineColor(kRed);
  line1->SetLineColor(kBlue);
  line1->Draw("same");
  linedef1->Draw("same");


  // * PT-dependence can add   
        TCanvas *cRatDiffPt = new TCanvas("cRatDiffPt","Ratio Diff in Pt",0,0,800,1000);
  gStyle->SetOptStat(1111);
  cRatDiffPt->Divide (3,4) ;
  //  for(int ll=2; ll<=ptbin+2; ll++){
   for(int ll=1; ll<=10; ll++){
     cRatDiffPt->cd(ll+1);
     gStyle->SetOptStat(1111);
     gStyle->SetOptFit(0);
     printf(" ratdiffpt %d \n", ll );
     hRatDiffPt[ll]->Draw("");
     }      
   //   */


  printf("Hisots done \n");

  /*		      
  cRatDiffPt->cd (1) ;
  hRatDiff[2]->Draw("");
  cRatDiffPt->cd (2) ;
  hRatDiff[3]->Draw("same");
  cRatDiffPt->cd (3) ;
  hRatDiff[4]->Draw("same");
  cRatDiffPt->cd (4) ;
  hRatDiff[5]->Draw("same");
  cRatDiffPt->cd (5) ;
  hRatDiff[6]->Draw("same");
  cRatDiffPt->cd (6) ;
  hRatDiff[7]->Draw("same");
  cRatDiffPt->cd (7) ;
  hRatDiff[8]->Draw("same");
  cRatDiffPt->cd (8) ;
  hRatDiff[9]->Draw("same");
		      */


   /*
  TH1D *hDelta1 = new TH1D("hDelta1","diff1/pol1",ptbin+1,ptedges);
   hDelta1->SetLineColor(kRed+3);   hDelta1->SetMarkerColor(kRed+3);
   hDelta1->SetLineWidth(2);   hDelta1->SetMinimum(0.001);   hDelta1->SetMaximum(1.5);
   hDelta1->SetMarkerSize(1.5);   hDelta1->SetMarkerStyle(23);   hDelta1->SetTitle("delta1");
   for(int i=2; i<ptbin+2; i++) {
     hDelta1->SetBinContent(i,delta1[i]);     hDelta1->SetBinError(i,delta1_e[i]);
   }
   TH1D *hDelta2 = new TH1D("hDelta2","diff2/pol3",ptbin+1,ptedges);
   hDelta2->SetLineColor(2);   hDelta2->SetMarkerColor(2);
   hDelta2->SetLineWidth(2);        hDelta2->SetMinimum(0.001);    hDelta2->SetMaximum(1.5);
   hDelta2->SetMarkerSize(1.5);     hDelta2->SetMarkerStyle(22);   hDelta2->SetTitle("delta2");
   for(int i=2; i<ptbin+2; i++) {
     hDelta2->SetBinContent(i,delta2[i]);     hDelta2->SetBinError(i,delta2_e[i]);
   }
   TH1D *hDelta3 = new TH1D("hDelta3","diff3/pol3",ptbin+1,ptedges);
   hDelta3->SetLineColor(3);   hDelta3->SetMarkerColor(3);
   hDelta3->SetLineWidth(2);   hDelta3->SetMinimum(0.001);   hDelta3->SetMaximum(1.5);
   hDelta3->SetMarkerSize(1.5);   hDelta3->SetMarkerStyle(26);   hDelta3->SetTitle("delta3");
   for(int i=2; i<ptbin+2; i++) {
     hDelta3->SetBinContent(i,delta3[i]);     hDelta3->SetBinError(i,delta3_e[i]);
   }
   TH1D *hDelta4 = new TH1D("hDelta4","diff4/pol4",ptbin+1,ptedges);
   hDelta4->SetLineColor(4);   hDelta4->SetMarkerColor(4);
   hDelta4->SetLineWidth(2);   hDelta4->SetMinimum(0.001);   hDelta4->SetMaximum(1.5);
   hDelta4->SetMarkerSize(1.5);   hDelta4->SetMarkerStyle(24);   hDelta4->SetTitle("delta4");
   for(int i=2; i<ptbin+2; i++) {
     hDelta4->SetBinContent(i,delta4[i]);     hDelta4->SetBinError(i,delta4_e[i]);
   }
   TH1D *hDelta5 = new TH1D("hDelta5","diff1/pol1",ptbin+1,ptedges);
   hDelta5->SetLineColor(6);   hDelta5->SetMarkerColor(6);
   hDelta5->SetLineWidth(2);   hDelta5->SetMinimum(0.001);   hDelta5->SetMaximum(1.5);
   hDelta5->SetMarkerSize(1.5);   hDelta5->SetMarkerStyle(25);   hDelta5->SetTitle("delta5");
   for(int i=2; i<ptbin+2; i++) {
     hDelta5->SetBinContent(i,delta5[i]);     hDelta5->SetBinError(i,delta5_e[i]);
   }

   TCanvas *cDelta = new TCanvas("cDelta","Delta",0,0,800,1000);
   cDelta->cd();
   hDelta1->Draw("");
   hDelta2->Draw("same");
   hDelta3->Draw("same");
   hDelta4->Draw("same");
   hDelta5->Draw("same");
   */

    //
    //
  /*     TCanvas *cratdiff = new TCanvas("cratduff","Ratio of difference",0,0,800,800);
     cratdiff->Divide(1,2);
     cratdiff->cd (1);
     hStatDiff->SetLineColor(kBlue);
     // hStatDiff->SetOptStat(11111);
     // hRatDiff->SetOptStat(11111);
     hRatDiff->Draw("");
     cratdiff->cd (2);
     hStatDiff->Draw(""); 
   */	

     //    cratdiff->cd (3); hRatDiff->Draw("");  hStatDiff->Draw("sameE"); 



    // output file //    
     TFile *fout = TFile::Open("Syst_fitFunction.root","RECREATE");

     hyie1->Write("hyie1");
     hyie2->Write("hyie2");
     hyie3->Write("hyie3");
     hyie4->Write("hyie4");
     hyie5->Write("hyie5");

     RawYield_tot->Write("RawYield_tot");
     Diff_tot->Write("Difference");
     hdmeandiff->Write("hdmeandiff");
     hmeandiff->Write("hmeandiff");

     hmix->Write("hmix");
     hpol1->Write("hpol1");
     hpol2->Write("hpol2");
     hpol3->Write("hpol3");
     hpol4->Write("hpol4");
     hpol5->Write("hpol5");

     hdiff1->Write("hdiff1");
     hdiff2->Write("hdiff2");
     hdiff3->Write("hdiff3");
     hdiff4->Write("hdiff4");
     hdiff5->Write("hdiff5");

     hRelDiff1->Write("hRelDiff1");
     hRelDiff2->Write("hRelDiff2");
     hRelDiff3->Write("hRelDiff3");
     hRelDiff4->Write("hRelDiff4");
     hRelDiff5->Write("hRelDiff5");

     hRatDiff1->Write("hRatDiff1");
     hRatDiff2->Write("hRatDiff2");
     hRatDiff3->Write("hRatDiff3");
     hRatDiff4->Write("hRatDiff4");
     hRatDiff5->Write("hRatDiff5");
     hRatDiffSum->Write("hRatDiffSum");
     cRelDiff->Write("cRelDiff");
     cRelStat->Write("cRelStat");
     cRatDiff->Write("cRatDiff");
     //    cRatDiffPt->Write("cRatDiffPt");
     cRatDiffSum->Write("cRatDiffSum");

     fout->Close();
    
     //   printf("Files  CLOSED---------> \n");  


     //       std::cout << "Hello, World\n";
     //       std::cin.ignore();
   //  return 0;

  

}


//=============================================================================
/* PPRstyle()
{
  //////////////////////////////////////////////////////////////////////
  //
  // ROOT style macro for the TRD TDR
  //
  //////////////////////////////////////////////////////////////////////

  gStyle->SetPalette(1);
  gStyle->SetCanvasBorderMode(-1);
  gStyle->SetCanvasBorderSize(1);
  gStyle->SetCanvasColor(10);

  gStyle->SetFrameFillColor(10);
  gStyle->SetFrameBorderSize(1);
  gStyle->SetFrameBorderMode(-1);
  gStyle->SetFrameLineWidth(1.2);
  gStyle->SetFrameLineColor(1);

  gStyle->SetHistFillColor(kBlack);
  gStyle->SetHistLineWidth(2);
  gStyle->SetHistLineColor(1);

  gStyle->SetPadColor(10);
  gStyle->SetPadBorderSize(1);
  gStyle->SetPadBorderMode(-1);

  gStyle->SetStatColor(10);
  gStyle->SetTitleColor(kBlack,"X");
  gStyle->SetTitleColor(kBlack,"Y");

  gStyle->SetLabelSize(0.024,"X");
  gStyle->SetLabelSize(0.024,"Y");
  gStyle->SetLabelSize(0.024,"Z");
  gStyle->SetTitleSize(0.024,"X");
  gStyle->SetTitleSize(0.024,"Y");
  gStyle->SetTitleSize(0.024,"Z");
  gStyle->SetTitleFont(42,"X");
  gStyle->SetTitleFont(42,"Y");
  gStyle->SetTitleFont(42,"X");
  gStyle->SetLabelFont(42,"X");
  gStyle->SetLabelFont(42,"Y");
  gStyle->SetLabelFont(42,"Z");
  gStyle->SetStatFont(42);

  gStyle->SetTitleOffset(1.0,"X");
  gStyle->SetTitleOffset(1.4,"Y");

//   gStyle->SetFillColor(kWhite);
  gStyle->SetTitleFillColor(kWhite);

  gStyle->SetOptDate(0);
  gStyle->SetOptTitle(1);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(0);

}
*/
