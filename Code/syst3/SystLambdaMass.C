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

double yMmean[ptbin+1]={0};
double yMmean_e[ptbin+1]={0};

double dyMean[ptbin+1]={0};
double dyMean_e[ptbin+1]={0};


double yMmean4[ptbin+1]={0};
double yMmean4_e[ptbin+1]={0};
double dyMean4[ptbin+1]={0};
double dyMean4_e[ptbin+1]={0};

void SystLambdaMass(){

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

   TH1F *hRatDiff = new TH1F("hRatDiff","; Ratio", 100, 0, 25.);  
   TH1F *hStatDiff = new TH1F("hStatDiff","; Ratio", 100, 0, 25.);  

   Double_t emix, epol1,epol2,epol3,epol4,epol5, ed1,ed2,ed3,ed4,ed5;
   Double_t ratdiff1,ratdiff2,ratdiff3, ratdiff4,ratdiff5; 
   Double_t statdiff1,statdiff2,statdiff3, statdiff4, statdiff5; 
    
   Double_t nVars = 5;
    TFile *fmix = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-LamCut0.root");
   TFile *fpol1 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-LamCut1.root");
   TFile *fpol2 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-LamCut2.root");
   TFile *fpol3 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-LamCut3.root");
   TFile *fpol4 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-LamCut4.root");
   TFile *fpol5 = TFile::Open("../ss1/SigMac-v45-TTree-PolGauss-LamCut5.root");
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

    
    
    
    for(int ii=2; ii<ptbin+2; ii++) {
        double mix = 0;
        double pol1 = 0;  double pol2 = 0;  double pol3 = 0;   double pol4 = 0; double pol5 = 0;
        double d1 = 0;    double d2 = 0;    double d3 = 0;     double d4 = 0;   double d5 = 0;
        
        
        mix =hmix->GetBinContent(ii);
        pol1 =hpol1->GetBinContent(ii);  pol2 =hpol2->GetBinContent(ii);   pol3 =hpol3->GetBinContent(ii);
        pol4 =hpol4->GetBinContent(ii);  pol5 =hpol5->GetBinContent(ii);
        
        d1= fabs(pol1-mix); d2= fabs(pol2-mix); d3= fabs(pol3-mix); d4= fabs(pol4-mix); d5= fabs(pol5-mix);
        
	emix= sqrt(mix); epol1=  sqrt(pol1); epol2=  sqrt(pol2); epol3=  sqrt(pol3); epol4=  sqrt(pol4); epol5=  sqrt(pol5);

	ed1 = sqrt( epol1*epol1 + emix*emix);
	ed2 = sqrt( epol2*epol2 + emix*emix);
	ed3 = sqrt( epol3*epol3 + emix*emix);
	ed4 = sqrt( epol4*epol4 + emix*emix);
	ed5 = sqrt( epol5*epol5 + emix*emix);

	/*        ratdiff1 = fabs( d1/ sqrt( fabs( epol1*epol1 - emix*emix) ) );        ratdiff3 = fabs( d3/ sqrt( fabs( epol3*epol3 - emix*emix) ) );        ratdiff4 = fabs( d4/ sqrt( fabs( epol4*epol4 - emix*emix) ) );        ratdiff5 = fabs( d5/ sqrt( fabs( epol5*epol5 - emix*emix) ) );
        statdiff1 = ed1/ sqrt( fabs( epol1*epol1 - emix*emix) );        statdiff3 = ed3/ sqrt( fabs( epol3*epol3 - emix*emix) );        statdiff4 = ed4/ sqrt( fabs( epol4*epol4 - emix*emix) );        statdiff5 = ed5/ sqrt( fabs( epol5*epol5 - emix*emix) );	*/

	/*	cout << "  bin num = " << ii << "  diff pol1 - mix = " << d1 << endl;
        cout << "  bin num = " << ii << "  diff pol3 - mix = " << d3 << endl;
        cout << "  bin num = " << ii << "  diff pol4 - mix = " << d4 << endl;
        cout << "  bin num = " << ii << "  diff pol5 - mix = " << d5 << endl; 	*/
        

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


        printf("dev1 %f 2 %f 3 %f 4 %f 5 %f ii %d \n",yMpol1[ii],yMpol2[ii],yMpol3[ii],yMpol4[ii],yMpol5[ii],ii);

	yMmean[ii] = ( yMpol1[ii] + yMpol2[ii]+ yMpol3[ii] +  yMpol4[ii] + yMpol5[ii] )/nVars;  	
	yMmean_e[ii] = sqrt ( yMpol1_e[ii]*yMpol1_e[ii] + yMpol2_e[ii]*yMpol2_e[ii] 
                            + yMpol3_e[ii]*yMpol3_e[ii] + yMpol4_e[ii]*yMpol4_e[ii]+yMpol5_e[ii]*yMpol5_e[ii]); 

	yMmean4[ii] = (  yMpol1[ii] +  yMpol2[ii] +  yMpol3[ii] +  yMpol4[ii] +  yMpol5[ii] )/nVars;  	
	// add rel yields
	//	yMmean4[ii] = ( pol1 + pol2 + pol3 + pol4 )/4; 
	

	yMmean4_e[ii] = 1.e-5 ;
	  // sqrt ( yMpol1_e[ii]*yMpol1_e[ii]+yMpol3_e[ii]*yMpol3_e[ii]+
	  // yMpol4_e[ii]*yMpol4_e[ii]+yMpol5_e[ii]*yMpol5_e[ii]); 

        
    }

    // RMS==standard deviation calculation
    for(int ii=2; ii<ptbin+2; ii++) {
          
      // dyMean==Mean difference,    dyMean4 == standard deviation
      dyMean[ii]=sqrt( ( (yMpol1[ii]-yMmean[ii])*(yMpol1[ii]-yMmean[ii]) +
			 (yMpol2[ii]-yMmean[ii])*(yMpol2[ii]-yMmean[ii]) +
 			 (yMpol3[ii]-yMmean[ii])*(yMpol3[ii]-yMmean[ii]) +
			 (yMpol4[ii]-yMmean[ii])*(yMpol4[ii]-yMmean[ii]) + 
			 (yMpol5[ii]-yMmean[ii])*(yMpol5[ii]-yMmean[ii]) )/nVars )    ;
      dyMean_e[ii]=1.e-5;

      dyMean4[ii]=sqrt( ( (yMpol1[ii]-yMmean4[ii])*(yMpol1[ii]-yMmean4[ii]) + 
  	                  (yMpol2[ii]-yMmean4[ii])*(yMpol2[ii]-yMmean4[ii]) + 
  	                  (yMpol3[ii]-yMmean4[ii])*(yMpol3[ii]-yMmean4[ii]) +
	                  (yMpol4[ii]-yMmean4[ii])*(yMpol4[ii]-yMmean4[ii]) + 
			  (yMpol5[ii]-yMmean4[ii])*(yMpol5[ii]-yMmean4[ii]) )/(nVars-1) ) ;
        
      dyMean4_e[ii]=1.e-5;
    }

    printf("diff calc done---------> \n");    
    

    
    ///==================
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
 
    TLegend *legl1 = new TLegend(0.6,0.5,0.9,0.9); // TLegend( X0, Y0, X1, Y1 )
    legl1->AddEntry(hmix,"Base","lp");
    legl1->AddEntry(hpol1,"cut1","lp");
    legl1->AddEntry(hpol2,"cut2","lp");
    legl1->AddEntry(hpol3,"cut3","lp");
    legl1->AddEntry(hpol4,"cut4","lp");
    legl1->AddEntry(hpol5,"cut5","lp");
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
    hmeandiff->SetTitle("Mean0");
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
    hdmeandiff->SetTitle("Mean1");
    hdmeandiff->SetMarkerSize(2.5);
    hdmeandiff->SetMarkerStyle(25);
    for(int i=2; i<ptbin+2; i++) {
      hdmeandiff->SetBinContent(i,dyMean[i]);
      hdmeandiff->SetBinError(i,dyMean_e[i]);
      printf("hdmean %f  bin %d \n",dyMean[i],i);
    }
   
   TH1D *hdmean4 = new TH1D("hdmean4","Mean deviation of 4 differences",ptbin+1,ptedges);
    hdmean4->SetLineColor(1);
    hdmean4->SetLineWidth(2);
    hdmean4->SetMinimum(0.001);
    hdmean4->SetMaximum(1.5);
    hdmean4->SetTitle("Mean4");
    hdmean4->SetMarkerSize(2.5);
    hdmean4->SetMarkerColor(1);
    hdmean4->SetMarkerStyle(29);
    for(int i=2; i<ptbin+2; i++) {
      hdmean4->SetBinContent(i,dyMean4[i]);
      hdmean4->SetBinError(i,dyMean4_e[i]);
      printf("hdmean4 %f  bin %d \n",dyMean4[i],i);
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
     

     
     //     hmeandiff->Draw("Esame");
     hdmeandiff->Draw("Esame");
     hdmean4->Draw("Esame");
     //     hmix->Draw("Esame");  // it NOT a difference, but RAW data
     hdiff1->Draw("Esame");
     hdiff2->Draw("Esame");
     hdiff3->Draw("Esame");
     hdiff4->Draw("Esame");
     hdiff5->Draw("Esame");
     
 

     //     Diff_tot->BuildLegend(0.78,0.6,0.98,0.75,"");

    TLegend *legl = new TLegend(0.6,0.5,0.9,0.9); // TLegend( X0, Y0, X1, Y1 )
    //    legl->AddEntry(hmeandiff,"Mean deviation","lp");

    legl->AddEntry(hdmean4,"RMS of deviations","lp");
    legl->AddEntry(hdmeandiff,"Mean difference","lp");
    legl->AddEntry(hdiff1,"cut1","lp");
    legl->AddEntry(hdiff2,"cut2","lp");
    legl->AddEntry(hdiff3,"cut3","lp");
    legl->AddEntry(hdiff4,"cut4","lp");
    legl->AddEntry(hdiff5,"cut5","lp");
    legl->Draw("same");
  
     printf("Draw  done---------> \n");  
    
       //       if(1) return;   
    // output file //

     /*   TCanvas *cratdiff = new TCanvas("cratduff","Ratio of difference",0,0,800,800);
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



    
     TFile *fout = TFile::Open("Syst_fitFunction.root","RECREATE");
     RawYield_tot->Write("RawYield_tot");
     Diff_tot->Write("Difference");
     hdmeandiff->Write("hdmeandiff");
     hdmean4->Write("hdmean4");


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

     fout->Close();
    

     //   printf("Files  CLOSED---------> \n");  


     //   std::cout << "Hello, World\n";
   //   std::cin.ignore();
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
