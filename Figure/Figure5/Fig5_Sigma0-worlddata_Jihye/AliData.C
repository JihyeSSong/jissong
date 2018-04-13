void SetStyle(Bool_t graypalette=kFALSE);
void myPadSetUp(TPad *currentPad, float currentLeft=0.11, float currentTop=0.04, float currentRight=0.04, float currentBottom=0.15);
void DrawLogo (Int_t logo=0, Double_t xmin =  0.28, Double_t ymin= 0.68, Double_t size = 0.15) ;

void AliData(int w=5) {

  gROOT->Reset();
  
  // type
  // plab
  // sqrts
  // ratio
  // error
  const int maxoftype = 32;
  const int maxtypes = 10;   // wo ALICE point - have to add it!
  const int max = maxoftype*maxtypes;


  int noft[32];
  double xe[32];
  memset(noft,0,32*sizeof(int));
  memset(xe,0,32*sizeof(double));
  double plab[320];
  double s[320];
  double ratio[320];
  double err[320];
  TGraphErrors* gr[10];
  memset(gr,0,10*sizeof(TGraphErrors*));
  TString lbl[11];
  
  TNtuple* rat = new TNtuple("rat","Sig/Lam ratio","type:plab:s:ratio:err");
  rat->ReadFile("data.txt");
  
  lbl[0] = "e^{+}e^{-}";
  lbl[1] = "#bar{p}p";
  lbl[2] = "pp";
  lbl[3] = "p-Be";
  lbl[4] = "p-Ne";
  lbl[9] = "K--N";
  lbl[5] = "ALICE";
  
  
  for (int i=0; i<rat->GetEntries(); i++) {

    rat->GetEntry(i);
    int type = (int) (rat->GetLeaf("type")->GetValue(0));
    if (type>5) continue; // Ignore meson-induced reactions
    int offset = type*maxoftype + noft[type];
    noft[type]++;
    plab[offset] = rat->GetLeaf("plab")->GetValue(0);
    s[offset] = rat->GetLeaf("s")->GetValue(0);
    ratio[offset] = rat->GetLeaf("ratio")->GetValue(0);
    err[offset] = rat->GetLeaf("err")->GetValue(0);

    printf(" p %f s %f r %f er %f noft %d  i %d \n",  plab[offset],   s[offset] ,   ratio[offset],   err[offset],  noft[type], i );

   
  }
  for (int i=0; i<maxtypes; i++) {
    
    // if( i == 3 ) continue; // p-Ne data


    //    if( i == 4 ) continue; // p-Ne  data: B.S. Yuldashev et al, Phys.Rev. D 43 2792 (1991)
    //  if( i == 1 ) continue; // p anti-p. Where are from? 
    //  if( i == 2 ) continue; // pp data COSY to update + ALICE: Kowina P et al (COSY-11 Collaboration) 2004 Proc. Tenth Int. Conf. on Hadron Spectroscopy (Aschaffenburg) vol 1 (Berlin: Springer) p 852, Update ASibirtsev Eur.Phys. J 29, 363-367 (2006)
    //  if( i == 0 ) continue; // e+e- data: Yuldashev-10TeV + LEP 
    // if( i == 3 ) continue; // p-Be data: Sullivan M W et al 1987 Phys. Rev. D 36 674


     if (noft[i] > 0) {
      int j = i*maxoftype;
      gr[i] = new TGraphErrors(noft[i],&(s[j]),&(ratio[j]),xe,&(err[j]));
     }
  }

  // Add  ALICE point as gr[]!!!
  //  gr[10] = new TGraphErrors(noft[10],&(7000.),&(0.315),0.05,& 0.005 ));



  gStyle->SetOptStat(0);
  //TH2F* hh = new TH2F("hh","#Sigma^{0}/#Lambda ratio",1,1.0,500.,1,0.03,1.5);

  //orig  
  // TH2F* hh = new TH2F("hh","#Sigma^{0}/#Lambda ratio",1,1.3,150.,1,0.025,1.3);

   TH2F* hh = new TH2F("hh","#Sigma^{0}/#Lambda ratio",1,2.0,10000.,1,0.0025,23 );

  //TH2F* hh = new TH2F("hh","#Sigma^{0}/#Lambda ratio",1,0.6,6,1,0.025,1.3);



  TH2F* h2 = new TH2F("h2","#Sigma^{0}/#Lambda ratio",1,1.5,4.0,1,0.025,1.0);
  //  TH2F* h3 = new TH2F("h3","#Sigma^{0}/#Lambda ratio",1,1.8765,1.8775,1,0.02,0.2);

  TH2F* h3 = new TH2F("h3","#Sigma^{0}/#Lambda ratio",1,2., 7750,1,0.02,0.2);

  TH2F* h4 = new TH2F("h4","#Sigma^{0}/#Lambda ratio",1,1.8775,150.,1,0.02,1.3);
  TH2F* h5 = new TH2F("h5","#Sigma^{0}/#Lambda ratio",1, 1.88, 32000.0, 1, 0.02, 2.5);


 SetStyle();

  TCanvas* c1 = new TCanvas("c1","plots",900,600);
  //  TPad* p1 = new TPad("p1","pad1",0.401,0.02,1.0,0.98);
  TPad* p2 = new TPad("p2","pad1",0.01,0.01,0.990,0.99 );
  // p1->SetLogy(1);
  //  p1->SetLogx(1);
  //  p1->Draw();
  p2->SetLogy(1);
  p2->SetLogx(1);
  if (w>=4) p2->Draw();
  TLine* l1 = new TLine;
  TH2F* hl=hh;
  TH2F* hx=h3;
  if (w==1) hl = h2;
  if (w==2) hl = h3;
  if (w==5) {
    hl = h4; hx= h5;
    hl->SetLabelOffset(1000,"y");
    hl->SetLabelOffset(-0.005,"x");
    hl->SetTickLength(0,"y");
    hl->GetXaxis()->SetNdivisions(505);
    //    hx->GetXaxis()->SetNdivisions(999999,0);
    // hx->SetLabelSize(0.045,"y");
    // hx->SetLabelSize(0.045,"x");
    hl->SetLabelSize(0.045,"x");
    hl->SetTitle("");
    hl->SetTitleSize(0.05,"x");
    hl->SetTitleOffset(1.05,"x");
    // p1->SetLeftMargin(0.000);
    p2->SetRightMargin(0.01);
    p2->SetLeftMargin(0.096);
    p2->SetBottomMargin(0.129);
    // p1->SetBottomMargin(0.11);
    p2->SetTopMargin(0.01);
    // p1->SetTopMargin(0.02);
  }
    


  TLatex* lt = new TLatex();
  //old  TLegend* ll = new TLegend(0.55,0.14,0.8,0.65,"System:");
  //  TLegend* ll = new TLegend(0.6,0.15,0.8,0.4);
 TLegend* ll = new TLegend(0.5,0.19,0.8,0.55,"Collision systems:");
 // TLegend* ll3 = new TLegend(0.65, 0.65, 0.70, 0.75,"1/3");
  
   //  hl->SetXTitle("#sqrt{s} [GeV]");
  int clrs[10] = {4,1,2,2,2,0,0,0,4,4};
  // int stys[10] = {25,23,26,20,21,0,0,0,0,28};  // original

 int stys[10] = {20,25,21,24,27,0,0,0,0,28}; 
  
  //   p1->cd();
  //  hl->Draw(); // That's TLEGEND => update!!!
   gStyle->SetPalette(1);
  


 for (int i=0;i<maxtypes;i++) {

   // SKIP some data here:
   //        if( i == 3 ) continue;
   //     if( i == 4 ) continue;

    if (gr[i]) {
      cout << "-siz= " << gr[i]->GetN() << endl;
      gr[i]->SetMarkerColor(clrs[i]);
      gr[i]->SetMarkerStyle(stys[i]);
      gr[i]->SetLineColor(clrs[i]);
      if ( i != 39 )    gr[i]->Draw("p");
      //      if ( i == maxtypes-1 )  gr[i]->Draw("pE2");     
      if ( i == 39 )  {  
	gr[i]->Draw("Psame");
	printf(" draw \n");
      }
      ll->AddEntry(gr[i],lbl[i].Data(),"p");
    }
  }
 // ll->AddEntry(gr[i],lbl[10].Data(),"p"); 
 

   if (w>=4) {
   
    p2->cd();
    hx->SetTitle("");
    hx->SetXTitle("#sqrt{#it{s}} (GeV)");
    hx->SetYTitle("(#Sigma^{0}+#bar{#Sigma}^{0}) / 2#Lambda");
    hx->SetTitleSize(0.060,"x");
    hx->SetTitleSize(0.060,"y");

    hx->SetLabelSize(0.050,"x");
    hx->SetLabelSize(0.050,"y");

    hx->SetTitleOffset(1.1,"x");
    hx->SetTitleOffset(0.75,"y"); 

    hx->Draw();

    for (int i=0;i<maxtypes;i++) {
      
      
      //         if (i == 3) continue;
      //         if (i == 4) continue;
 

      if (gr[i]) {
	gr[i]->SetMarkerColor(clrs[i]);
	gr[i]->SetMarkerStyle(stys[i]);
	gr[i]->SetMarkerSize(1.5);
	gr[i]->Draw("p");
      }
    }
    //    l1->DrawLine(hx->GetXaxis()->GetXmin(),0.333,hx->GetXaxis()->GetXmax(),0.333);
    lt->SetTextSize(0.15);
    //    lt->DrawLatex(1.87665,0.7,"#Sigma^{0}/#Lambda");
    //      lt->DrawLatex(300,0.7,"#Sigma^{0}/#Lambda");
    //   lt->DrawLatex(1000,0.7,"ALICE Preliminary");
    lt->SetTextSize(0.065);

    //  lt->SetXTitle("#sqrt{s} [GeV]");

    //  lt->DrawLatex(1.87632,0.0155,"1.8765");
    //  lt->DrawLatex(1.87728,0.0155,"1.8775");
    for (float xx=1.8766;xx<1.8775;xx+=0.0001) l1->DrawLine(xx,0.02,xx,0.0212);
    l1->DrawLine(xx,0.02,xx,0.0228);
   }
  
   ll->Draw();
   //    ll3->Draw();
   //  l1->SetLineStyle(2);
   // l1->DrawLine(hl->GetXaxis()->GetXmin(),0.333,hl->GetXaxis()->GetXmax(),0.333);

   TLatex * text = new TLatex (0.38,0.87,"ALICE,  pp #sqrt{#it{s}} = 7 TeV");
  text->SetTextSize(0.06);
 // text.SetNDC();
  text->SetTextFont(42);
  text->Draw();

   TLatex * text3 = new TLatex (0.41,0.78,"#Sigma^{0} #rightarrow #Lambda #gamma,  #bar{#Sigma^{0}} #rightarrow #bar{#Lambda} #gamma");
 // text3.SetNDC();
  text3->SetTextSize(0.07);
  text3->SetTextFont(42);
  //  text3->Draw();


  TLatex * text2 = new TLatex (0.43,0.77,"Uncertainties: stat. (inner bars), sys. (outer bars)");
 // text2.SetNDC();
  text2->SetTextSize(0.04);
  text2->SetTextFont(42);
  text2->Draw();



  
  c1->Update();
  
}

//-----------------------------------------------------------------------------
void ALICEPreliminary(TPad *c,
		      const Float_t bbllx=0.60, const Float_t bblly=0.44,
		      const Float_t bburx=0.95, const Float_t bbury=0.62)  //0.72
{
  c->cd();
  const Float_t logoSize = 0.14;
  Float_t llx = (bbllx+bburx)/2 - logoSize/2;
  Float_t urx = (bbllx+bburx)/2 + logoSize/2;
  Float_t lly =  bbury - logoSize;
  Float_t ury =  bbury;
  printf("llx=%f, lly=%f, urx=%f, ury=%f\n",llx, lly, urx, ury);
  TPad *myPadLogo = new TPad("myPadLogo", "Pad for ALICE Logo",
                             llx, lly, urx, ury);
  myPadLogo->SetFillColor(0); 
  myPadLogo->SetBorderMode(1);
  myPadLogo->SetBorderSize(2);
  myPadLogo->SetFrameBorderMode(0);
  myPadLogo->SetLeftMargin(0.0);
  myPadLogo->SetTopMargin(0.0);
  myPadLogo->SetBottomMargin(0.0);
  myPadLogo->SetRightMargin(0.0);
  myPadLogo->SetFillStyle(0);
  myPadLogo->Draw();
  myPadLogo->cd();
  TASImage *myAliceLogo = new TASImage("./alice_logo.png");
  myAliceLogo->Draw();
  c->cd();

  llx = bbllx;
  lly = bblly;
  urx = bburx;
  ury = bbury - logoSize - 0.01;
  TPaveText* t1=new TPaveText(llx, lly, urx, ury,"NDC");
  t1->SetFillStyle(0);
  t1->SetBorderSize(0);
  t1->AddText(0.,0.,"ALICE performance");
  t1->AddText(0.,0.,"pp#rightarrow#Sigma^{0}( #gamma_{EMCAL} #gamma_{conv})  X");
  t1->AddText(0.,0.,"#sqrt{s}=7 TeV");
  t1->AddText(0.,0.,"17 May 2011"); 
  t1->SetTextColor(kRed);
  t1->SetTextFont(42);
  t1->Draw();
  c->cd();
}
//-------------------------------------------------------------------------------------------------
Double_t CBfit(Double_t * x, Double_t * par){
  Double_t m=par[1] ;
  Double_t s=par[2] ;
  Double_t n=par[3] ;
  Double_t a=par[4] ;
  Double_t dx=(x[0]-m)/s ;
  if(dx>-a)
    return par[0]*exp(-dx*dx/2.)+par[5]+par[6]*(x[0]-kMean) ;
  else{
    Double_t A=TMath::Power((n/TMath::Abs(a)),n)*TMath::Exp(-a*a/2) ;
    Double_t B=n/TMath::Abs(a)-TMath::Abs(a) ;
    return par[0]*A*TMath::Power((B-dx),-n)+par[5]+par[6]*(x[0]-kMean) ;
  }
}
//---------------------------------------------------------------------------------------------------
Double_t CB2fit(Double_t * x, Double_t * par){
  Double_t m=par[1] ;
  Double_t s=par[2] ;
  Double_t n=par[3] ;
  Double_t a=par[4] ;
  Double_t dx=(x[0]-m)/s ;
  if(dx>-a)
    return par[0]*exp(-dx*dx/2.)+par[5]+par[6]*(x[0]-kMean)+par[7]*(x[0]-kMean)*(x[0]-kMean) ;
  else{
    Double_t A=TMath::Power((n/TMath::Abs(a)),n)*TMath::Exp(-a*a/2) ;
    Double_t B=n/TMath::Abs(a)-TMath::Abs(a) ;
    return par[0]*A*TMath::Power((B-dx),-n)+par[5]+par[6]*(x[0]-kMean)+par[7]*(x[0]-kMean)*(x[0]-kMean) ;
  }

}
//------------------------------------------------------------------------
TH1D * BinWidthCorrection(TH1D * h){
  //We apply bin width a-la PHENIX 
  //Use Tsalis fit to calculate shift in y direction

  // It is not Tsallis fit below - break
  //  TF1 * fit = new TF1("hag","[0]*(([2]*[1]+sqrt(x*x+0.135*0.135))/([2]*[1]+0.135))^-[2]",0.5,25.) ;
  //  fit->SetParameters(10.,0.2,8.) ;


  TF1 * fit = new TF1("Tsalis","[0]/2./3.1415*([2]-1.)*([2]-2.)/([2]*[1]*([2]*[1]+0.135*([2]-2.)))*(1.+(sqrt(x*x+0.135*0.135)-0.135)/([2]*[1]))^-[2]",0.5,25.) ;
  fit->SetParameters(1.6e+11,0.2,6.7) ;


  TCanvas * corr = new TCanvas("BWcorr","Bin-width-correction") ;
  Int_t col[6]={kRed,kOrange,kMagenta,kGreen,kCyan,kBlue} ;
  TH1D * hcorr[20] ;
  char key[55] ;
  Double_t rMax=10 ;
  Int_t iteration=0 ;
  TH1D * htmp = (TH1D*)h->Clone("tmp") ;

  while(iteration<6){
    //    printf(" Iteration %d: rMax=%f \n",iteration, rMax) ;
    htmp->Fit(fit,"N") ;
    //    printf(" 2=- IteratioN %d: rMax=%f \n",iteration, rMax) ;

    sprintf(key,"Iteration%d",iteration) ;
    hcorr[iteration]=(TH1D*)h->Clone(key);
    rMax= 0; 

    //    printf(" 3=- IteratioN %d: rMax=%f \n",iteration, rMax) ;
    for(Int_t i=1;i<=h->GetNbinsX();i++){
      Double_t a=h->GetXaxis()->GetBinLowEdge(i) ;
      Double_t b=h->GetXaxis()->GetBinUpEdge(i) ;
      Double_t r=fit->Integral(a,b)/(b-a)/fit->Eval(0.5*(a+b)) ;
      hcorr[iteration]->SetBinContent(i,r) ;
      hcorr[iteration]->SetBinError(i,0.) ;
      if(rMax<r)rMax=r ;
      //      printf(" rMax = %f \n", rMax);
    }
    //    printf(" 4=- IteratioN \n") ;  

    delete htmp ;
    htmp = (TH1D*)h->Clone("tmp") ;
    htmp->Divide(hcorr[iteration]) ;
    corr->cd() ;
    hcorr[iteration]->SetLineColor(col[iteration]);
    if(iteration==0) {
      hcorr[iteration]->Draw() ;

      Double_t hval=0;
      for(Int_t i=1; i<=16; i++){
	hval = hcorr[iteration]->GetBinContent(i) ;
	//	hMass->GetBinContent(iM)
	printf(" hv %f i %d \n", hval, i ); 
      }
    

    }
    //    else
    //      hcorr[iteration]->Draw("same") ;
    corr->Update() ;
    iteration++ ;
  } 
  return hcorr[5] ;

  //  Double_t hval=0;
  //  for(Int_t i=1;i<=h->GetNbinsX();i++){
  //  hval = hcorr->GetBinContent(i) ;
  //  printf(" hv %f i %d \n"); }
  
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
//-----------------------------------------------------------------------------
void ALICEPreliminary(TPad *c){

  TPad *myPadLogo = new TPad("myPadLogo", "Pad for ALICE Logo",0.42,0.7,0.69,0.95);
  myPadLogo->SetFillColor(0); 
  myPadLogo->SetBorderMode(0);
  myPadLogo->SetBorderSize(2);
  myPadLogo->SetFrameBorderMode(0);
  myPadLogo->SetLeftMargin(0.0);
  myPadLogo->SetTopMargin(0.0);
  myPadLogo->SetBottomMargin(0.0);
  myPadLogo->SetRightMargin(0.0);
  myPadLogo->SetFillStyle(0);
  myPadLogo->Draw();
  myPadLogo->cd();

  TASImage *myAliceLogo = new TASImage("./alice_logo.png");
  myAliceLogo->Draw();

  c->cd() ;
  TPaveText* t1=new TPaveText(0.42,0.55,0.62,0.69,"NDC");
  t1->SetFillStyle(0);
  t1->SetBorderSize(0);
  t1->SetTextSize(0.04) ;
  t1->AddText(0.,0.,"ALICE performance");
  t1->AddText(0.,0.,"pp @ #sqrt{s}=7 TeV");
  t1->AddText(0.,0.,"15 May 2011");

  t1->SetTextColor(kRed);
  t1->SetTextFont(42);
  t1->Draw();
}


void myPadSetUp(TPad *currentPad, float currentLeft, float currentTop, float currentRight, float currentBottom){
  currentPad->SetLeftMargin(currentLeft);
  currentPad->SetTopMargin(currentTop);
  currentPad->SetRightMargin(currentRight);
  currentPad->SetBottomMargin(currentBottom);
  return;
}


void SetStyle(Bool_t graypalette) {
  cout << "Setting style!" << endl;
  
  gStyle->Reset("Plain");
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  if(graypalette) gStyle->SetPalette(8,0);
  else gStyle->SetPalette(1);
  gStyle->SetCanvasColor(10);
  gStyle->SetCanvasBorderMode(0);
  gStyle->SetFrameLineWidth(1);
  gStyle->SetFrameLineColor(kBlack);

  gStyle->SetFrameFillColor(kWhite);
  gStyle->SetPadColor(10);
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
  gStyle->SetPadBottomMargin(0.15);
  gStyle->SetPadLeftMargin(0.15);
  gStyle->SetHistLineWidth(1);
  gStyle->SetHistLineColor(kRed);
  gStyle->SetFuncWidth(2);
  gStyle->SetFuncColor(kGreen);
  gStyle->SetLineWidth(2);
  gStyle->SetLabelSize(0.045,"xyz");
  gStyle->SetLabelOffset(0.015,"y");
  gStyle->SetLabelOffset(0.01,"x");
  gStyle->SetLabelColor(kBlack,"xyz");
  gStyle->SetTitleSize(0.05,"xyz");
  gStyle->SetTitleOffset(1.25,"y");
  gStyle->SetTitleOffset(1.2,"x");
  gStyle->SetTitleFillColor(kWhite);
  gStyle->SetTextSizePixels(26);
  gStyle->SetTextFont(42);
  //  gStyle->SetTickLength(0.04,"X");  gStyle->SetTickLength(0.04,"Y"); 

  gStyle->SetLegendBorderSize(0);
  gStyle->SetLegendFillColor(kWhite);
  //  gStyle->SetFillColor(kWhite);
  gStyle->SetLegendFont(42);


}
