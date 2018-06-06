
#include <iostream>
// this is for systematic study

const int ptbin = 8;
double ptedges[ptbin+1+1]={0};
double ptedges_Sigma[ptbin+1] = { 1.0, 1.5, 2.0, 2.4, 2.8, 3.2, 4., 6.0, 10.0 };
double pt_points[ptbin] = {1.25, 1.75, 2.2, 2.6, 3.0, 3.6, 5., 8};
double pt_points_e[ptbin] = {.25, .25, .2, .2, .2, .4, 1., 2. };
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


void SysDev(){

  PPRstyle();              
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
    

   // TFile *fmix = TFile::Open("Sigma0_mix.root");
   //    TFile *fmix = TFile::Open("Sigma0-pol2-7jul15.root");

    /*    TFile *fpol1 = TFile::Open("Sigma0AP-p2-50-2010-Pt-polBG-gauss-7jul15.root");
    TFile *fpol3 = TFile::Open("Sigma0AP-p2-50-2010-Pt-polBG-bincount-7jul15.root");
    TFile *fpol4 = TFile::Open("Sigma0AP-p2-50-2010-Pt-mixBG-gaussmass-7jul15.root");
    TFile *fpol5 = TFile::Open("Sigma0AP-p2-50-2010-Pt-mixBG-bincount-7jul15.root");
    */
         
    TFile *fmix = TFile::Open("Sigma0-pol2-7jul15.root");
    TFile *fpol1 = TFile::Open("Sigma0AP-p2-50-2010-Pt-polBG-gauss-8jul15.root");
    TFile *fpol3 = TFile::Open("Sigma0AP-p2-50-2010-Pt-polBG-bincount-8jul15.root");
    TFile *fpol4 = TFile::Open("Sigma0AP-p2-50-2010-Pt-mixBG-gaussmass-8jul15.root");
    TFile *fpol5 = TFile::Open("Sigma0AP-p2-50-2010-Pt-mixBG-bincount-8jul15.root");
    
   

   /*  TFile *fmix = TFile::Open("../ss1/SigMac-v44-Bins2a-noTTRee-PolGauss-17oct16.root");  // what it is? 
    TFile *fpol5 = TFile::Open("../ss1/SigMac-v44-Bins2a-noTTRee-MixCount-17oct16.root");
    TFile *fpol4 = TFile::Open("../ss1/SigMac-v44-Bins2a-noTTRee-MixGauss-17oct16.root");
    TFile *fpol1 = TFile::Open("../ss1/SigMac-v44-Bins2a-noTTRee-PolGauss-17oct16.root");
    TFile *fpol3 = TFile::Open("../ss1/SigMac-v44-Bins2a-noTTRee-PolCount-17oct16.root");
   */
  

    printf("files opend \n");
    
    //    TH1D *hmix = (TH1D*)fmix->Get("h_Rawspectrum");
    //    TH1D *hmix = (TH1D*)fpol1->Get("hhPi0ev");
    TH1D *hmix = (TH1D*)fpol1->Get("stat");
    hmix->SetMarkerStyle(25);
    hmix->SetLineColor(2);
    hmix->SetMarkerColor(2);
    hmix->SetTitle("DF BG");


    TH1D *hpol1 = (TH1D*)fpol1->Get("stat"); 
    //        TH1D *hpol1 = (TH1D*)fpol1->Get("hhPi0ev");
    //    TH1D *hpol1 = (TH1D*)fpol1->Get("hhSumPi0ev");
    hpol1->SetMarkerStyle(21);
    hpol1->SetLineColor(2);
    hpol1->SetMarkerColor(2);
    hpol1->SetTitle("pol-gauss");

    TH1D *hpol3 = (TH1D*)fpol3->Get("stat");
    //        TH1D *hpol3 = (TH1D*)fpol3->Get("hhPi0ev");
    // TH1D *hpol3 = (TH1D*)fpol3->Get("hhSumPi0ev");
    hpol3->SetMarkerStyle(26);
    hpol3->SetLineColor(3);
    hpol3->SetMarkerColor(3);
    hpol3->SetTitle("pol-bin");

    TH1D *hpol4 = (TH1D*)fpol4->Get("stat");
    //        TH1D *hpol4 = (TH1D*)fpol4->Get("hhPi0ev");
    // TH1D *hpol4 = (TH1D*)fpol4->Get("hhSumPi0ev");
    hpol4->SetMarkerStyle(24);
    hpol4->SetLineColor(4);
    hpol4->SetMarkerColor(4);
    hpol4->SetTitle("mix-gauss");

    TH1D *hpol5 = (TH1D*)fpol5->Get("stat");
    //        TH1D *hpol5 = (TH1D*)fpol5->Get("hhPi0ev");
    // TH1D *hpol5 = (TH1D*)fpol5->Get("hhSumPi0ev");
    hpol5->SetMarkerStyle(25);
    hpol5->SetLineColor(6);
    hpol5->SetMarkerColor(6);
    hpol5->SetTitle("mix-bin");

    
    
    
    for(int ii=2; ii<ptbin+2; ii++) {
        double mix = 0;
        double pol1 = 0;
        double pol3 = 0;
        double pol4 = 0;
        double pol5 = 0;
        

        double d1 = 0;
        double d2 = 0;
        double d3 = 0;
        double d4 = 0;
        double d5 = 0;
        
        
        mix =hmix->GetBinContent(ii);
        pol1 =hpol1->GetBinContent(ii);
        pol3 =hpol3->GetBinContent(ii);
        pol4 =hpol4->GetBinContent(ii);
	pol5 =hpol5->GetBinContent(ii);

        
        d1 = fabs( pol1-mix );
	//	d2 = abs(pol2-mix);
        d3 = fabs( pol3-mix );        
        d4 = fabs( pol4-mix );        
        d5 = fabs( pol5-mix );
        
	emix = sqrt(mix);
	epol1 =  sqrt(pol1);
	epol3 =  sqrt(pol3);
	epol4 =  sqrt(pol4);
	epol5 =  sqrt(pol5);

	ed1 = sqrt( epol1*epol1 + emix*emix);
	ed3 = sqrt( epol3*epol3 + emix*emix);
	ed4 = sqrt( epol4*epol4 + emix*emix);
	ed5 = sqrt( epol5*epol5 + emix*emix);
	//	ed1 = sqrt( epol1*epol1 + emix*emix);

	/*
        ratdiff1 = fabs( d1/ sqrt( fabs( epol1*epol1 - emix*emix) ) );
        ratdiff3 = fabs( d3/ sqrt( fabs( epol3*epol3 - emix*emix) ) );
        ratdiff4 = fabs( d4/ sqrt( fabs( epol4*epol4 - emix*emix) ) );
        ratdiff5 = fabs( d5/ sqrt( fabs( epol5*epol5 - emix*emix) ) );

        statdiff1 = ed1/ sqrt( fabs( epol1*epol1 - emix*emix) );
        statdiff3 = ed3/ sqrt( fabs( epol3*epol3 - emix*emix) );
        statdiff4 = ed4/ sqrt( fabs( epol4*epol4 - emix*emix) );
        statdiff5 = ed5/ sqrt( fabs( epol5*epol5 - emix*emix) );
	*/

	//       	hRatDiff->Fill(ratdiff1);
	//	hRatDiff->Fill(ratdiff3);
	//	hRatDiff->Fill(ratdiff4);
	//	hRatDiff->Fill(ratdiff5); 

	//       	hStatDiff->Fill(statdiff1);
	//	hStatDiff->Fill(statdiff3);
	//	hStatDiff->Fill(statdiff4);
	// hStatDiff->Fill(statdiff5);
 

	/* 	cout << "  bin num = " << ii << "  diff pol1 - mix = " << d1 << endl;
        cout << "  bin num = " << ii << "  diff pol3 - mix = " << d3 << endl;
        cout << "  bin num = " << ii << "  diff pol4 - mix = " << d4 << endl;
        cout << "  bin num = " << ii << "  diff pol5 - mix = " << d5 << endl; 
	*/
        
        if(d1 ==0){
            yMpol1[ii] = d1; // 0
            yMpol1_e[ii] = d1;
        }else{
            yMpol1[ii] = d1/mix;
            yMpol1_e[ii]=1.e-4 ; // *yMpol1[ii]*sqrt(sqrt(d1)/d1*sqrt(d1)/d1+sqrt(mix)/mix*sqrt(mix)/mix);
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

	if( yMpol3[ii] == 0 ) yMpol3[ii] = 1.e-3;

        printf(" dev %f %f %f ii %d \n",yMpol3[ii], yMpol4[ii],  yMpol5[ii], ii );



	yMmean[ii] = (yMpol3[ii] +  yMpol4[ii] +  yMpol5[ii] )/3;  	
	yMmean_e[ii] = sqrt ( yMpol3_e[ii]*yMpol3_e[ii] +yMpol4_e[ii]*yMpol4_e[ii]+yMpol5_e[ii]*yMpol5_e[ii]); 

	yMmean4[ii] = (  yMpol1[ii] +  yMpol3[ii] +  yMpol4[ii] +  yMpol5[ii] )/4;  	
	// add rel yields
	//	yMmean4[ii] = ( pol1 + pol2 + pol3 + pol4 )/4; 
	

	yMmean4_e[ii] = 1.e-5 ;
	  // sqrt ( yMpol1_e[ii]*yMpol1_e[ii]+yMpol3_e[ii]*yMpol3_e[ii]+yMpol4_e[ii]*yMpol4_e[ii]+yMpol5_e[ii]*yMpol5_e[ii]); 

        
    }

    // RMS calculation
    for(int ii=2; ii<ptbin+2; ii++) {
          
      dyMean[ii]=sqrt( ( (yMpol3[ii]-yMmean[ii])*(yMpol3[ii]-yMmean[ii]) +
			 (yMpol4[ii]-yMmean[ii])*(yMpol4[ii]-yMmean[ii]) + 
                         (yMpol5[ii]-yMmean[ii])*(yMpol5[ii]-yMmean[ii]) )/3. )     ;
      dyMean_e[ii]=1.e-5;

      dyMean4[ii]=sqrt( ( 
	    (yMpol1[ii]-yMmean4[ii])*(yMpol1[ii]-yMmean4[ii]) + (yMpol3[ii]-yMmean4[ii])*(yMpol3[ii]-yMmean4[ii]) +
	    (yMpol4[ii]-yMmean4[ii])*(yMpol4[ii]-yMmean4[ii]) + (yMpol5[ii]-yMmean4[ii])*(yMpol5[ii]-yMmean4[ii]) )/4. )     ;
        
      dyMean4_e[ii]=1.e-5;


      printf("yMmean %f dyMean4 %f    ii %d \n",yMmean[ii],dyMean4[ii],ii);


    }

    printf("diff calc done---------> \n");    
    

    
    ///==================
    TCanvas *RawYield_tot = new TCanvas("RawYield_tot","Sigma0 raw yield",0,0,800,1000);
    RawYield_tot->cd();

    TH1F *boxU = new TH1F("boxU","",300,0.,30.);
    boxU->SetAxisRange(0.0,10.50,"X");
    boxU->SetAxisRange(1.e-6, 4.e-2,"Y");
    boxU->SetXTitle("p_{T}, GeV/c");
    //Youra-pi0  boxU->SetYTitle("1/N_{ev} d^{3}N/p_{T}dp_{T}dyd#phi (GeV/c)^{-2}");
    boxU->SetYTitle("(1/N_{inel}) d^{2}N/dydp_{T}, (GeV/c)^{-1}");
    boxU->SetTitleSize(0.04,"X");
    boxU->SetTitleSize(0.04,"Y");
    boxU->SetTitleOffset(1.10,"Y");
    boxU->SetLabelSize(0.02,"XY");
    boxU->Draw("");

    hmix->Draw("same");
    //    hpol1->Draw("same");
    hpol3->Draw("same");
    hpol4->Draw("same");
    hpol5->Draw("same");
    //    RawYield_tot->BuildLegend(0.78,0.4,0.98,0.75,"");
 
    TLegend *legl1 = new TLegend(0.6,0.5,0.9,0.9); // TLegend( X0, Y0, X1, Y1 )
    legl1->AddEntry(hmix,"Base: pol,gauss","lp");
    //  legl1->AddEntry(hpol1,"pol,gauss","lp");
    legl1->AddEntry(hpol3,"pol,bin","lp");
    legl1->AddEntry(hpol4,"mix,gauss","lp");
    legl1->AddEntry(hpol5,"mix,bin","lp");
    legl1->Draw("same");
    //====================================\\    
    
    

    TH1D *hdiff1 = new TH1D("hdiff1","pol1 - mix",ptbin+1,ptedges);
    hdiff1->SetLineColor(2);
    hdiff1->SetMarkerColor(2);
    hdiff1->SetLineWidth(2);
    hdiff1->SetMinimum(0.001);
    hdiff1->SetMaximum(1.5);
    hdiff1->SetMarkerSize(1.5);
    hdiff1->SetMarkerStyle(21);
    hdiff1->SetTitle("pol-gauss");

    for(int i=2; i<ptbin+2; i++) {
        hdiff1->SetBinContent(i,yMpol1[i]);
        hdiff1->SetBinError(i,yMpol1_e[i]);
    }

     
    
    TH1D *hdiff3 = new TH1D("hdiff3","pol3 - mix",ptbin+1,ptedges);
    hdiff3->SetLineColor(3);
    hdiff3->SetMarkerColor(3);
    hdiff3->SetLineWidth(2);
    hdiff3->SetMinimum(0.001);
    hdiff3->SetMaximum(1.5);
    hdiff3->SetTitle("pol-bin");
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
    hdiff4->SetTitle("mix-gauss");
    hdiff4->SetMarkerSize(1.5);
    hdiff4->SetMarkerStyle(24);

    for(int i=2; i<ptbin+2; i++) {
      hdiff4->SetBinContent(i,yMpol4[i]);
      hdiff4->SetBinError(i,yMpol4_e[i]);
    }
       
    TH1D *hdiff5 = new TH1D("hdiff5","pol5 - mix",ptbin+1,ptedges);
    hdiff5->SetLineColor(6);
    hdiff5->SetLineWidth(2);
    hdiff5->SetMinimum(0.001);
    hdiff5->SetMaximum(1.5);
    hdiff5->SetTitle("mix-bin");
    hdiff5->SetMarkerSize(1.5);
    hdiff5->SetMarkerColor(6);
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
    hdmeandiff->SetLineColor(kRed);
    hdmeandiff->SetLineWidth(2);
    hdmeandiff->SetMinimum(0.001);
    hdmeandiff->SetMaximum(1.5);
    hdmeandiff->SetTitle("Mean1");
    hdmeandiff->SetMarkerSize(2.5);
    hdmeandiff->SetMarkerColor(kRed);
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
     box->SetAxisRange(0., 0.4,"Y");
     box->SetXTitle("p_{T}, GeV/c");
     //Youra-pi0  boxU->SetYTitle("1/N_{ev} d^{3}N/p_{T}dp_{T}dyd#phi (GeV/c)^{-2}");
     //  box->SetYTitle("(1/N_{inel}) d^{2}N/dydp_{T}, (GeV/c)^{-1}");
     box->SetYTitle("(Y_{i} - Y_{def})/Y_{def}");
     box->SetTitleSize(0.04,"X");
     box->SetTitleSize(0.04,"Y");
     box->SetTitleOffset(1.1,"Y");
     box->SetLabelSize(0.02,"XY");
     box->Draw("");
     

     
     hmeandiff->Draw("Esame");   // mean deviation
       hdmeandiff->Draw("Esame");    //black   big square
       hdmean4->Draw("Esame");  // rms of deviation
       //  hdiff1->Draw("Esame");   // 0 == zero values
     hdiff3->Draw("Esame");
     hdiff4->Draw("Esame");
     hdiff5->Draw("Esame");
     


     //     Diff_tot->BuildLegend(0.78,0.6,0.98,0.75,"");

    TLegend *legl = new TLegend(0.6,0.5,0.9,0.9); // TLegend( X0, Y0, X1, Y1 )
    legl->AddEntry(hmeandiff,"Mean deviation","lp");
    legl->AddEntry(hdmeandiff,"base: pol, gauss","lp");
    legl->AddEntry(hdmean4,"RMS of deviations","lp");
    legl->AddEntry(hdiff3,"pol,bin-pol,gauss","lp");
    legl->AddEntry(hdiff4,"mix,gauss-pol,gauss","lp");
    legl->AddEntry(hdiff5,"mix,bin-pol,gauss","lp");
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
    hdiff1->Write("hdiff1");
    hdiff3->Write("hdiff3");
    hdiff4->Write("hdiff4");
    hdiff5->Write("hdiff5");

    fout->Close();
     
    if( 1 > 0 ) return;

    //   printf("Files  CLOSED---------> \n");  


   // std::cout << "Hello, World\n";
   //   std::cin.ignore();
   //  return 0;

  

}


//=============================================================================
PPRstyle()
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
