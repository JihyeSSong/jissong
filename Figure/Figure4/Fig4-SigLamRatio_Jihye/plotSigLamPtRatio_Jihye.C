void SetStyle(Bool_t graypalette=kFALSE);
void myPadSetUp(TPad *currentPad, float currentLeft=0.11, float currentTop=0.04, float currentRight=0.04, float currentBottom=0.15);
void DrawLogo (Int_t logo=0, Double_t xmin =  0.28, Double_t ymin= 0.68, Double_t size = 0.15) ;
void FakeHistosOnlyForExample(TH1*&hstat, TH1*&hsyst, TH1*&hsystCorr);
// void LoadLibs();


void plotSigLamPtRatio_v2(){
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

  //  TFile *fPyt6 = TFile::Open("RSigLamGen-Pyt6Per-23feb18.root");
  TFile *fPyt6 = TFile::Open("RSigLamGen-v2-pyt6.root");
  TGraphErrors *hRSigLamPyt6 = (TGraphErrors*) fPyt6->Get("h_RSigLam"); 


  //  hRSigLamPyt6 ->Draw("E");  if(1) return; 

  //  TFile *fPyt8 = TFile::Open("RSigLamGen-Pyt8Mon-23feb18.root");
  TFile *fPyt8 = TFile::Open("RSigLamGen-v2-pyt8.root");
  TGraphErrors *hRSigLamPyt8 = (TGraphErrors*) fPyt8->Get("h_RSigLam"); 

   

 
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
  box->SetTitleOffset(1.0,"Y");
  box->SetTitleSize(0.05,"Y");
  box->SetLabelSize(0.03,"Y");

  box->SetTitleOffset(0.8,"X");
  box->SetLabelSize(0.03,"X");
  box->SetTitleSize(0.05,"X");

  box->SetMaximum(1.5) ;
  box->SetMinimum(0.0001) ;

  h_RatioSigLam-> SetMarkerStyle(21);
  h_RatioSigLam-> SetMarkerColor(kBlue+2);
  h_RatioSigLam->  SetLineColor(kBlue+2);
 

  TCanvas * cLam = new TCanvas("cLam","Data-MC-ratio",10,10,800,800) ;
  cLam->SetFillColor(0) ;
  cLam->SetFillStyle(0) ;
  cLam->Range(0,0,1,1);
  cLam->SetBorderSize(0);
 
const Int_t fillColors[] = {kGray+1,  kRed-10, kBlue-9, kGreen-8, kMagenta-9, kOrange-9,kCyan-8,kYellow-7}; // for syst bands
const Int_t colors[]     = {kBlack, kRed+1 , kBlue+1, kGreen+3, kMagenta+1, kOrange-1,kCyan+2,kYellow+2};
const Int_t markers[]    = {kFullCircle, kFullSquare,kOpenCircle,kOpenSquare,kOpenDiamond,kOpenCross,kFullCross,kFullDiamond,kFullStar,kOpenStar};



 /*   boxL->Draw();
   h_SigSpec->Draw("E1same") ;
    h_LamSpec->Draw("PE2same") ;
   h_LamSpecStat->Draw("E1same") ;
  data_syst ->Draw("PE2same");
 */

  // TLatex *   text = new TLatex(xmin,ymin, logo ? "ALICE Preliminary" : "ALICE");
  //  text->SetTextSizePixels(12);
 /*  TLatex * text = new TLatex (0.155,0.87,"ALICE, pp #sqrt{#it{s}} = 7 TeV (INEL)");
  text->SetTextSize(0.065);
  text.SetNDC();
  text->SetTextFont(42);
  text->Draw();

   TLatex * text3 = new TLatex (0.20,0.78,"#Sigma^{0} #rightarrow #Lambda #gamma,  #bar{#Sigma^{0}} #rightarrow #bar{#Lambda} #gamma");
  text3.SetNDC();
  text3->SetTextSize(0.07);
  text3->SetTextFont(42);
  // text3->Draw();

   TLatex * text2 = new TLatex (0.45,0.55,"Uncertainties: stat. (bars), sys. (boxes)");
  text2.SetNDC();
  text2->SetTextSize(0.04);
  text2->SetTextFont(42);
  text2->Draw();
 */

   /*
   hSys2->SetFillStyle(0) ;
   hSys2->SetLineColor(1) ;
   hSys2->Draw("E2same") ;
   hStat2->SetMarkerColor(13) ;
   hStat2->SetMarkerStyle(24) ;
   hStat2->Draw("same") ;
   */
   //   fit->Draw("same") ;
   //  ALICEPreliminary(spectrum_1) ;
 /* spectrum_1->cd() ;
   //  fitText->Draw() ;
   //   TLegend * l = new TLegend(0.55,0.65,0.9,0.85) ;
   TLegend * l = new TLegend(0.45,0.65,0.65, 0.75) ;
   l->SetFillColor(0) ;
   l->AddEntry(h_SigSpec,"(#Sigma^{0} + #bar{#Sigma}^{0}) / 2","pl") ;
   l->AddEntry(h_LamSpec,"#Lambda","pl") ;
   //   l->AddEntry(fit,"Tsalis fit 5<p_{t}<25.","l") ;
   // l->SetFrameColor(1) ;
   l->Draw() ;
 */

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
   spectrum_2->SetTopMargin(0.0);
   spectrum_2->SetBottomMargin(0.10);
   spectrum_2->SetLeftMargin(0.12);
   spectrum_2->SetRightMargin(0.01);
   spectrum_2->cd() ;

   SetStyle();

Int_t icolor=2;
h_RatioStatSigLam ->SetMarkerColor(colors[icolor]);
h_RatioStatSigLam->SetFillColor(fillColors[icolor]);
h_RatioStatSigLam->SetFillStyle(0);
h_RatioStatSigLam->SetLineColor(colors[icolor]);
h_RatioStatSigLam->SetLineWidth(1.);

h_RatioSigLam ->SetMarkerColor(colors[icolor]);
h_RatioSigLam->SetFillColor(fillColors[icolor]);
h_RatioSigLam->SetFillStyle(0);
h_RatioSigLam->SetLineColor(colors[icolor]);
h_RatioSigLam->SetLineWidth(1.);

   box->Draw() ;
   h_RatioSigLam->Draw("E2,same");
   h_RatioStatSigLam->Draw("E1,same");

   hRSigLamPyt6->Draw("Esame");
   hRSigLamPyt8->Draw("Esame");

  TLatex * text = new TLatex (0.25,0.90,"ALICE, pp #sqrt{#it{s}} = 7 TeV (INEL)");
  Double_t xmin =  0.18 ; Double_t ymin= 0.68 ;
  Int_t logo=0 ;
  text->SetTextSize(0.05);
 // text.SetNDC();
  text->SetTextFont(42);
  text->Draw("same");

  TLegend * l = new TLegend(0.15,0.63,0.55,0.83) ;
   l->SetFillColor(0) ;
   l->AddEntry(h_RatioSigLam,"Data","pl") ;
   l->AddEntry(hRSigLamPyt6,"PYTHIA-6 Perugia-2011","pl") ; 
   l->AddEntry(hRSigLamPyt8,"PYTHIA-8 Monash-2013","pl") ;
   //   l->AddEntry(fit,"Tsalis fit 5<p_{t}<25.","l") ;
   // l->SetFrameColor(1) ;
   l->Draw() ;




   //   hSysRatio->Draw("sameE2") ;
   // hStatRatio->Draw("same") ;
   //   hSysRatio2->SetFillStyle(0) ;
   //   hSysRatio2->SetLineColor(1) ;
   //   hSysRatio2->Draw("sameE2") ;
   //   hStatRatio2->SetMarkerColor(1) ;
   //   hStatRatio2->SetMarkerStyle(24) ;
   //   hStatRatio2->Draw("same") ;

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
