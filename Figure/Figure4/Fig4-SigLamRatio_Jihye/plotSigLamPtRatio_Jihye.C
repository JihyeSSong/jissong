void SetStyle(Bool_t graypalette=kFALSE);
void myPadSetUp(TPad *currentPad, float currentLeft=0.11, float currentTop=0.04, float currentRight=0.04, float currentBottom=0.15);
void DrawLogo (Int_t logo=0, Double_t xmin =  0.28, Double_t ymin= 0.68, Double_t size = 0.15) ;
void FakeHistosOnlyForExample(TH1*&hstat, TH1*&hsyst, TH1*&hsystCorr);
// void LoadLibs();


void plotSigLamPtRatio_Jihye(){
  // Load necessary libraries
  // LoadLibs();
  // Set the default style
  SetStyle();

  TFile *fpol1 = TFile::Open("SigMac-715--Tree-Pol3-Gauss-STANDARD2-29oct17.root");

  TH1D *h_SigSpec = (TH1D*) fpol1->Get("stat")->Clone("h_SigSpec");   // syst unc.
  TH1D *data_syst = (TH1D*) fpol1->Get("syst")->Clone("data_syst");

  TH1D *h_LamSpec = (TH1D*)     fpol1->Get("h_LamSpec"); 
  TH1D *h_LamSpecStat = (TH1D*)     fpol1->Get("h_LamSpecStat"); 

  TH1D *h_RatioSigLam = (TH1D*) fpol1->Get("h_RatioSigLam"); 
  TH1D *h_RatioStatSigLam = (TH1D*) fpol1->Get("h_RatioStatSigLam"); 

//  TFile *fPyt6 = TFile::Open("RSigLamGen-v2-pyt6.root");
//  TGraphErrors *hRSigLamPyt6 = (TGraphErrors*) fPyt6->Get("h_RSigLam");
//    hRSigLamPyt6->SetLineColor(2);
    
    TGraphErrors *hRSigLamPyt6 = new TGraphErrors(9);
    hRSigLamPyt6->SetName("hRSigLamPyt6");
    hRSigLamPyt6->SetTitle("hRSigLamPyt6");
    hRSigLamPyt6->SetFillColor(1);
    
    Int_t ci;      // for color index setting
    TColor *color; // for color definition with alpha
    hRSigLamPyt6->SetLineColor(2);
    hRSigLamPyt6->SetLineWidth(2);
  //  hRSigLamPyt6->SetPoint(0,0.25,0.4389356);
  //  hRSigLamPyt6->SetPointError(0,0.05,6.992606e-05);
    hRSigLamPyt6->SetPoint(1,0.7,0.2662726);
    hRSigLamPyt6->SetPointError(1,0.4,6.296073e-05);
    hRSigLamPyt6->SetPoint(2,1.35,0.285063);
    hRSigLamPyt6->SetPointError(2,0.25,0.0001377947);
    hRSigLamPyt6->SetPoint(3,1.8,0.3001202);
    hRSigLamPyt6->SetPointError(3,0.2,0.0002127028);
    hRSigLamPyt6->SetPoint(4,2.2,0.3075513);
    hRSigLamPyt6->SetPointError(4,0.2,0.00030191);
    hRSigLamPyt6->SetPoint(5,2.6,0.3131504);
    hRSigLamPyt6->SetPointError(5,0.2,0.0004166539);
    hRSigLamPyt6->SetPoint(6,3.1,0.316265);
    hRSigLamPyt6->SetPointError(6,0.3,0.0006037659);
    hRSigLamPyt6->SetPoint(7,3.7,0.3145022);
    hRSigLamPyt6->SetPointError(7,0.3,0.0008954056);
    hRSigLamPyt6->SetPoint(8,4.5,0.3197625);
    hRSigLamPyt6->SetPointError(8,0.5,0.001393487);
    hRSigLamPyt6->SetPoint(9,6.5,0.3085886);
    hRSigLamPyt6->SetPointError(9,1.5,0.00287543);
    
    TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","Graph",100,0,8.78);
    hRSigLamPyt6->SetHistogram(Graph_Graph1);


    
  //  TFile *fPyt8 = TFile::Open("RSigLamGen-v2-pyt8.root");
  //TGraphErrors *hRSigLamPyt8 = (TGraphErrors*) fPyt8->Get("h_RSigLam");
   // hRSigLamPyt8->SetLineColor(4);
   
    TGraphErrors *hRSigLamPyt8 = new TGraphErrors(9);
    hRSigLamPyt8->SetName("hRSigLamPyt8");
    hRSigLamPyt8->SetTitle("hRSigLamPyt8");
    hRSigLamPyt8->SetFillColor(1);
    
    hRSigLamPyt8->SetLineColor(4);
    hRSigLamPyt8->SetLineWidth(2);
 //   hRSigLamPyt8->SetPoint(0,0.25,0.4904651);
 //   hRSigLamPyt8->SetPointError(0,0.05,0.0005121884);
    hRSigLamPyt8->SetPoint(1,0.7,0.3007051);
    hRSigLamPyt8->SetPointError(1,0.4,0.0004952473);
    hRSigLamPyt8->SetPoint(2,1.35,0.3203976);
    hRSigLamPyt8->SetPointError(2,0.25,0.001151183);
    hRSigLamPyt8->SetPoint(3,1.8,0.3437061);
    hRSigLamPyt8->SetPointError(3,0.2,0.001692323);
    hRSigLamPyt8->SetPoint(4,2.2,0.3485103);
    hRSigLamPyt8->SetPointError(4,0.2,0.002285309);
    hRSigLamPyt8->SetPoint(5,2.6,0.343408);
    hRSigLamPyt8->SetPointError(5,0.2,0.002992146);
    hRSigLamPyt8->SetPoint(6,3.1,0.3655896);
    hRSigLamPyt8->SetPointError(6,0.3,0.004385994);
    hRSigLamPyt8->SetPoint(7,3.7,0.3391241);
    hRSigLamPyt8->SetPointError(7,0.3,0.006220357);
    hRSigLamPyt8->SetPoint(8,4.5,0.3144913);
    hRSigLamPyt8->SetPointError(8,0.5,0.008859374);
    hRSigLamPyt8->SetPoint(9,6.5,0.334275);
    hRSigLamPyt8->SetPointError(9,1.5,0.01854652);
    
    TH1F *Graph_Graph2 = new TH1F("Graph_Graph2","Graph",100,0,8.78);
    hRSigLamPyt8->SetHistogram(Graph_Graph2);

 
//  gStyle->SetOptDate(0);
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(1);
//  gStyle->SetFillColor(kWhite);
  gStyle->SetTitleFillColor(kWhite);
  gStyle->SetPalette(1);
  gStyle->SetCanvasBorderMode(-1);
  gStyle->SetCanvasBorderSize(1);
  gStyle->SetFrameFillColor(0);
  gStyle->SetFrameBorderSize(1);
  gStyle->SetStatColor(0);
  gStyle->SetFitFormat("5.3g") ;

  gStyle->SetOptStat(0);
    
    gStyle->SetPadTickX(1);
    gStyle->SetPadTickY(1);
    gStyle->SetFuncWidth(2);
    gStyle->SetLineWidth(2);
  //  hSys->Draw();
  //  hStat->Draw();
  
  // if(1>0 ) return;

  /*
  TH1F *boxL = new TH1F("box","#pi^{0} production spectrum",8,0.,9.);
  boxL->SetAxisRange(0.0,4.,"Y");
  boxL->SetXTitle("#it{p}_{T} (GeV/#it{c})");
  boxL->SetYTitle("d^{2}#it{N}_{INEL}/(d#it{y}d#it{p}_{T}) [(GeV/#it{c})^{-1}]");
  boxL->SetTitleSize(0.059,"Y");
  boxL->SetTitleOffset(0.750,"Y");
  boxL->SetLabelOffset(0.0,"Y");
  boxL->SetMinimum(1.00001e-5) ;
  boxL->SetMaximum(0.70) ;
  */

  TH1F *box = new TH1F("box","#pi^{0} production spectrum",8,0.,9.);
  box->SetAxisRange(0.0,4.,"Y");
  box->SetXTitle("#it{p}_{T} (GeV/#it{c})");
  box->SetYTitle("(#Sigma^{0} + #bar{#Sigma^{0}}) / 2#Lambda");
  box->SetTitleSize(0.01,"Y");
  box->SetTitleOffset(1.1,"Y");
  box->SetTitleSize(0.05,"Y");
  box->SetLabelSize(0.05,"Y");

  box->SetTitleOffset(1.1,"X");
  box->SetLabelSize(0.05,"X");
  box->SetTitleSize(0.05,"X");

  box->SetMaximum(1.5) ;
  box->SetMinimum(0.0001) ;

  h_RatioSigLam-> SetMarkerStyle(20);
  h_RatioSigLam-> SetMarkerColor(1);
  h_RatioSigLam->  SetLineColor(1);
 

  TCanvas * cLam = new TCanvas("cLam","Data-MC-ratio",10,10,800,600) ;
  cLam->SetFillColor(0) ;
  cLam->SetFillStyle(0) ;
  cLam->Range(0,0,1,1);
  cLam->SetBorderSize(0);
 
//const Int_t fillColors[] = {kGray+1,  kRed-10, kBlue-9, khRSigLamPyt6en-8, kMagenta-9, kOrange-9,kCyan-8,kYellow-7}; // for syst bands
//const Int_t colors[]     = {kBlack, kRed+1 , kBlue+1, khRSigLamPyt6en+3, kMagenta+1, kOrange-1,kCyan+2,kYellow+2};
//const Int_t markers[]    = {kFullCircle, kFullSquare,kOpenCircle,kOpenSquare,kOpenDiamond,kOpenCross,kFullCross,kFullDiamond,kFullStar,kOpenStar};




   cLam->cd() ;
   TPad *spectrum_2 = new TPad("spectrum_2", "spectrum_2",0.001,0.01,0.99,0.99);
   spectrum_2->SetFillColor(0) ;
   spectrum_2->SetFillStyle(0) ;
   spectrum_2->SetLogy(0) ;
   spectrum_2->SetGridy(0) ;
   spectrum_2->Draw();
   spectrum_2->Range(0,0,1,1);
   spectrum_2->SetFillColor(0);
   spectrum_2->SetBorderSize(1);
   spectrum_2->SetTopMargin(0.05);
   spectrum_2->SetBottomMargin(0.12);
   spectrum_2->SetLeftMargin(0.12);
   spectrum_2->SetRightMargin(0.05);
   spectrum_2->cd() ;

   SetStyle();

//Int_t icolor=2;
h_RatioStatSigLam ->SetMarkerColor(1);
h_RatioStatSigLam->SetFillColor(1);
h_RatioStatSigLam->SetFillStyle(0);
h_RatioStatSigLam->SetLineColor(1);
h_RatioStatSigLam->SetMarkerSize(1.);
    h_RatioStatSigLam->SetMarkerStyle(20);
h_RatioStatSigLam->SetLineWidth(1.);

h_RatioSigLam ->SetMarkerColor(1);
h_RatioSigLam->SetFillColor(1);
h_RatioSigLam->SetFillStyle(0);
h_RatioSigLam->SetLineColor(1);
h_RatioSigLam->SetLineWidth(1.);

   box->Draw() ;
   h_RatioSigLam->Draw("E2,same");
   h_RatioStatSigLam->Draw("E1,same");

   hRSigLamPyt6->Draw("Esame");
   hRSigLamPyt8->Draw("Esame");

  TLatex * text = new TLatex (0.5,1.35,"ALICE, pp, #sqrt{#it{s}} = 7 TeV (INEL)");
  Double_t xmin =  0.18 ; Double_t ymin= 0.68 ;
  Int_t logo=0 ;
  text->SetTextSize(0.05);
  text->SetTextFont(42);
  text->Draw("same");

  TLegend * l = new TLegend(0.15,0.6,0.4,0.83) ;
    l->SetTextSize(0.045);
   l->SetFillColor(0) ;
    TLegendEntry *entry = l->AddEntry("NULL","Data","lp") ;
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1.0);
    
   entry = l->AddEntry(hRSigLamPyt6,"PYTHIA-6 Perugia-2011","pl") ;
   entry = l->AddEntry(hRSigLamPyt8,"PYTHIA-8 Monash-2013","pl") ;
   //   l->AddEntry(fit,"Tsalis fit 5<p_{t}<25.","l") ;
   // l->SetFrameColor(1) ;
   l->Draw() ;


    cLam->SaveAs("Figure4.pdf");
    cLam->SaveAs("Figure4.C");
    

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
 // gStyle->SetFuncColor(khRSigLamPyt6en);
  gStyle->SetLineWidth(2);
  gStyle->SetLabelSize(0.045,"xyz");
  gStyle->SetLabelOffset(0.015,"y");
  gStyle->SetLabelOffset(0.01,"x");
  gStyle->SetLabelColor(kBlack,"xyz");
  gStyle->SetTitleSize(0.05,"xyz");
  gStyle->SetTitleOffset(1.25,"y");
  gStyle->SetTitleOffset(1.25,"x");
  gStyle->SetTitleFillColor(kWhite);
  gStyle->SetTextSizePixels(26);
  gStyle->SetTextFont(42);
  //  gStyle->SetTickLength(0.04,"X");  gStyle->SetTickLength(0.04,"Y"); 

  gStyle->SetLegendBorderSize(0);
  gStyle->SetLegendFillColor(kWhite);
  //  gStyle->SetFillColor(kWhite);
  gStyle->SetLegendFont(42);


}
