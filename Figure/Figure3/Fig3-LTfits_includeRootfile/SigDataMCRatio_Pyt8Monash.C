void SetStyle(Bool_t graypalette=kFALSE);
void myPadSetUp(TPad *currentPad, float currentLeft=0.11, float currentTop=0.04, float currentRight=0.04, float currentBottom=0.15);
void DrawLogo (Int_t logo=0, Double_t xmin =  0.28, Double_t ymin= 0.68, Double_t size = 0.15) ;
void FakeHistosOnlyForExample(TH1*&hstat, TH1*&hsyst, TH1*&hsystCorr);
// void LoadLibs();

void SigDataMCRatio_Pyt8Monash(){

  SetStyle();


 //  TFile *f0= new TFile("Lambda-pp7TeV-Preliminary.root"); // Lambda yields for comparison

 //  PYTHIA-6 offi 
  TFile *f1 = TFile::Open("./mc10bcdefp4-sum-v45-12aug16.root"); Double_t nevt=525*1.e6;
  TObjArray *histESD1 = (TObjArray*) f1->Get("PWGGA_CaloConv/CaloConv");
  TDirectoryFile *td1 = (TDirectoryFile*) f1->Get("PWGGA_CaloConv");
  TList *list1 = (TList*)td1->Get("CaloConv");
  TH1F *h_Lam1 = (TH1F*)list1->FindObject("hMCPLamPtGen4");
  TH1F *LamYield1 = (TH1F*)list1->FindObject("hMCgenSig0");
  TH1F *h_Sig1 = (TH1F*)list1->FindObject("hMCPSig0PtGen4");



  // Pyt8-Monash 
	TFile *f0 = TFile::Open("./mc_pythia8_sum.root"); Double_t nevt=9.0*1.e6 ;
  TObjArray *histESD = (TObjArray*) f0->Get("PWGGA_CaloConv/CaloConv");
  TDirectoryFile *td = (TDirectoryFile*) f0->Get("PWGGA_CaloConv");
  TList *list = (TList*)td->Get("CaloConv");
  TH1F *h_Lam = (TH1F*)list->FindObject("hMCPLamPtGen4");
  TH1F *LamYield = (TH1F*)list->FindObject("hMCgenSig0");
  TH1F *h_Sig = (TH1F*)list->FindObject("hMCPSig0PtGen4");

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
 

   //====================================================================== 
const int ptbin = 8; 
double ptedges[ptbin+1] = { 1.1, 1.6, 2.0, 2.4, 2.8, 3.4, 4., 5.0, 8.0 };

 
  // LamYield->Draw();
 //  h_Sig->Draw("same");
 Double_t xPtd,yPtd, exPtd,eyPtd;

  Double_t ycont,xwidth,xlow, xup, ex, ey, xmean, xuphi;

  /* Double_t xa[]={1.1, 1.6, 2.0, 2.4, 2.8, 3.4, 4.0, 5.0, 8.0} ;
  Double_t xma[]={1.1, 1.6, 2.0, 2.4, 2.8, 3.4, 4.0, 5.0, 8.0} ;
  Double_t exa[]={1.1, 1.6, 2.0, 2.4, 2.8, 3.4, 4.0, 5.0, 8.0} ;
  Double_t ya[]={1.1, 1.6, 2.0, 2.4, 2.8, 3.4, 4.0, 5.0, 8.0} ;
  Double_t ny[]={1.1, 1.6, 2.0, 2.4, 2.8, 3.4, 4.0, 5.0, 8.0} ;
  Double_t eya[]={1.1, 1.6, 2.0, 2.4, 2.8, 3.4, 4.0, 5.0, 8.0} ;
  */
  Double_t xas[]={1.1, 1.6, 2.0, 2.4, 2.8, 3.4, 4.0, 5.0, 8.0} ;
  Double_t xmas[]={1.1, 1.6, 2.0, 2.4, 2.8, 3.4, 4.0, 5.0, 8.0} ;
  Double_t exas[]={1.1, 1.6, 2.0, 2.4, 2.8, 3.4, 4.0, 5.0, 8.0} ;
  Double_t yas[]={1.1, 1.6, 2.0, 2.4, 2.8, 3.4, 4.0, 5.0, 8.0} ;
  Double_t nys[]={1.1, 1.6, 2.0, 2.4, 2.8, 3.4, 4.0, 5.0, 8.0} ;
  Double_t eyas[]={1.1, 1.6, 2.0, 2.4, 2.8, 3.4, 4.0, 5.0, 8.0} ;


  Double_t rsiglam[]={1.1, 1.6, 2.0, 2.4, 2.8, 3.4, 4.0, 5.0, 8.0} ;
  Double_t rsiglam_e[]={1.1, 1.6, 2.0, 2.4, 2.8, 3.4, 4.0, 5.0, 8.0} ;



  Int_t nbin=8;
  Int_t npt=600;
  const Int_t n = npt ;
  Double_t x[n];
  Double_t y[n];
  Double_t u[n];

  const int ptbinALL = 17; 
  //  double ptedges_SigmaALL[ptbinALL+1] = {0.00001, 0.1, 0.3, 0.5, 0.7, 0.9, 1.1, 1.6, 2.0, 2.4, 2.8, 3.4, 4., 5.0, 8.0, 11. };
  /*  double xa[ptbinALL+1] = {0.00001, 0.1, 0.3, 0.5, 0.7, 0.9, 1.1, 1.6, 2.0, 2.4, 2.8, 3.4, 4., 5.0, 8.0, 11. };
 double xma[ptbinALL+1] = {0.00001, 0.1, 0.3, 0.5, 0.7, 0.9, 1.1, 1.6, 2.0, 2.4, 2.8, 3.4, 4., 5.0, 8.0, 11. };
 double exa[ptbinALL+1] = {0.00001, 0.1, 0.3, 0.5, 0.7, 0.9, 1.1, 1.6, 2.0, 2.4, 2.8, 3.4, 4., 5.0, 8.0, 11. };
 double ya[ptbinALL+1] = {0.00001, 0.1, 0.3, 0.5, 0.7, 0.9, 1.1, 1.6, 2.0, 2.4, 2.8, 3.4, 4., 5.0, 8.0, 11. };
 double ny[ptbinALL+1] = {0.00001, 0.1, 0.3, 0.5, 0.7, 0.9, 1.1, 1.6, 2.0, 2.4, 2.8, 3.4, 4., 5.0, 8.0, 11. };
 double eya[ptbinALL+1] = {0.00001, 0.1, 0.3, 0.5, 0.7, 0.9, 1.1, 1.6, 2.0, 2.4, 2.8, 3.4, 4., 5.0, 8.0, 11. };
  */

  double xa[ptbinALL+1] = {1.0, 1.05,  1.1, 1.35, 1.6, 1.8,  2.0, 2.4, 2.8, 3.4, 3.7, 4.0, 4.5,  5.0, 6.,  7., 8.0, 8.1 };
  double xma[ptbinALL+1] = {1.0, 1.05,  1.1, 1.35, 1.6, 1.8,  2.0, 2.4, 2.8, 3.4, 3.7, 4.0, 4.5,  5.0, 6., 7., 8.0, 8.1 };
  double exa[ptbinALL+1] = {1.0, 1.05,  1.1, 1.35, 1.6, 1.8,  2.0, 2.4, 2.8, 3.4, 3.7, 4.0, 4.5,  5.0, 6., 7., 8.0, 8.1 };
  double ya[ptbinALL+1] = {1.0, 1.05,  1.1, 1.35, 1.6, 1.8,  2.0, 2.4, 2.8, 3.4, 3.7, 4.0, 4.5,  5.0,  6., 7., 8.0, 8.1 };
  double ny[ptbinALL+1] = {1.0, 1.05,  1.1, 1.35, 1.6, 1.8,  2.0, 2.4, 2.8, 3.4, 3.7, 4.0, 4.5,  5.0,  6., 7., 8.0, 8.1 };
  double eya[ptbinALL+1] = {1.0, 1.05,  1.1, 1.35, 1.6, 1.8,  2.0, 2.4, 2.8, 3.4, 3.7, 4.0, 4.5,  5.0, 6., 7., 8.0, 8.1 };

  const Int_t n1 = ptbinALL;
  Double_t x1[n1];
  Double_t y1[n1];
  Double_t u1[n1];


  TGraph* g1=new TGraph(n);
  TGraphErrors* g2=new TGraphErrors(n);
  // double x1,y1,u1;

 //  for (Int_t i=0; i< nbin ; i++) {
 for (Int_t i=0; i< ptbinALL ; i++) {
    ya[i] = 0; 
    ny[i] = 0 ;
    eya[i] = 0;
    exa[i] = (xa[i+1] - xa[i])/2 ;
    xma[i] = (xa[i+1] + xa[i])/2 ;

    for (Int_t iPt=0; iPt< npt ; iPt++) {
      ycont =   LamYield->GetBinContent(iPt);
      xwidth=  LamYield->GetBinWidth(iPt);
      //  LamYield->GetBinWithContent(iPt);
      xlow=  LamYield->GetBinLowEdge(iPt);
      //      xuphi=  LamYield->GetBinUpEdge(iPt);
      // ex = LamYield->GetErrorX(iPt) ;
      ey = LamYield->GetBinError(iPt) ;    
      xup = xlow+xwidth;        
      xmean = xlow+xwidth*0.5 ;

      x[iPt] = xmean  ;
      // old normalization  
      y[iPt] = ycont * 5.5e-9 ;
      if(  xlow >= xa[i] && xup <= xa[i+1] ) {
	ya[i] += ycont;
	eya[i] += ey ;
	ny[i] += 1  ;
      } 
    }
    //    ya[i] = 2.*	ya[i] / ny[i]; upto 17jan17
    ya[i] = 	ya[i] / ny[i];
    eya[i] =    eya[i] / ny[i];
    printf("Lam NEW ipt-ibin = %d  y %f ey %f n %f \n", i, ya[i], eya[i], ny[i] );
    x1[i]=  (xa[i+1] + xa[i] )/2   ;   
    y1[i] = ya[i] * 5.5e-9  * 58.3 ;
    
    //    y1[i] = ya[i]  / nevt *100 ;   // those points are plotted
    u1[i] =  (xa[i+1] + xa[i] )/2 ;
 }
 TGraph *gr = new TGraph(n,x,y);
 TGraph *g1 = new TGraph(n1,x1,y1);
 TCanvas *c100 = new TCanvas("c100","gerrors2",200,10,700,500);
 TGraph *gr = new TGraph(n,x,y);
 gr->SetMarkerStyle(21);
 TSpline3 *s3 = new TSpline3("s3",gr->GetX(),gr->GetY(),gr->GetN());
 s3->SetLineColor(kMagenta);
 
 TSpline3 *s4 = new TSpline3("s4",g1->GetX(),g1->GetY(),g1->GetN());
 s4->SetLineColor(kMagenta);
 
 g1->Draw("alp");
 s3->Draw("lsame");   
 s4->Draw("lsame");

 // LamYield->Scale(1./nevt); LamYield->SetMarkerSize(2); LamYield->SetMarkerStyle(24);
 //     LamYield->Draw("P"); LamYield->Draw("Psame");
 TCanvas *c101 = new TCanvas("c101","Input",200,10,700,500);       

 // for Pyt6 Perugia
 for (Int_t i=0; i< ptbinALL ; i++) {
    ya[i] = 0; 
    ny[i] = 0 ;
    eya[i] = 0;
    exa[i] = (xa[i+1] - xa[i])/2 ;
    xma[i] = (xa[i+1] + xa[i])/2 ;

    for (Int_t iPt=0; iPt< npt ; iPt++) {
      ycont =   LamYield1->GetBinContent(iPt);
      xwidth=  LamYield1->GetBinWidth(iPt);
      //  LamYield->GetBinWithContent(iPt);
      xlow=  LamYield1->GetBinLowEdge(iPt);
      //      xuphi=  LamYield->GetBinUpEdge(iPt);
      // ex = LamYield->GetErrorX(iPt) ;
      ey = LamYield1->GetBinError(iPt) ;    
      xup = xlow+xwidth;        
      xmean = xlow+xwidth*0.5 ;

      x[iPt] = xmean  ;
      // old normalization  
      y[iPt] = ycont * 5.5e-9 ;
      if(  xlow >= xa[i] && xup <= xa[i+1] ) {
	ya[i] += ycont;
	eya[i] += ey ;
	ny[i] += 1  ;
      } 
    }
    //    ya[i] = 2.*	ya[i] / ny[i]; upto 17jan17
    ya[i] = 	ya[i] / ny[i];
    eya[i] =    eya[i] / ny[i];
    printf("Lam NEW ipt-ibin = %d  y %f ey %f n %f \n", i, ya[i], eya[i], ny[i] );
    x1[i]=  (xa[i+1] + xa[i] )/2   ;
   
    y1[i] = ya[i] * 5.5e-9  ;
    
    //    y1[i] = ya[i]  / nevt *100 ;   // those points are plotted

    u1[i] =  (xa[i+1] + xa[i] )/2 ;
 }
 TGraph *gr1 = new TGraph(n,x,y);
 TGraph *g11 = new TGraph(n1,x1,y1);
 TCanvas *c1100 = new TCanvas("c1100","gerrors2",200,10,700,500);
 TGraph *gr1 = new TGraph(n,x,y);
 gr1->SetMarkerStyle(21);
 TSpline3 *s31 = new TSpline3("s31",gr1->GetX(),gr1->GetY(),gr1->GetN());
 s31->SetLineColor(kBlue);
 
 TSpline3 *s41 = new TSpline3("s41",g11->GetX(),g11->GetY(),g11->GetN());
 s41->SetLineColor(kBlue);
 
 g11->Draw("alp");
 s31->Draw("lsame");   
 s41->Draw("lsame");

 // LamYield->Scale(1./nevt); LamYield->SetMarkerSize(2); LamYield->SetMarkerStyle(24);
 //     LamYield->Draw("P"); LamYield->Draw("Psame");
 //TCanvas *c1011 = new TCanvas("c1011","Input",200,10,700,500);





//======================================================================
/* TH1F *h = (TH1F*)list->FindObject("hMCgenSig0");

  int n=h->GetNbinsX();
  TGraph* g1=new TGraph(n);
  TGraphErrors* g2=new TGraphErrors(n);
  double x,y,u;

  for(int i=0;i<n;i++){
    x=h->GetXaxis()->GetBinCenter(i+1);
    y=h->GetBinContent(i+1);
    u=h->GetBinError(i+1);
    g1->SetPoint(i,x,y);
    g2->SetPoint(i,x,y);
    g2->SetPointError(i,0,u);
  }

  g1->SetLineColor(2);
  g1->SetLineWidth(2);

// g2->SetFillColor(TColor::GetColor("#ffc0cb");
 TCanvas *c100 = new TCanvas("c100","gerrors2",200,10,700,500);

//First draw your “frame” histogram: the empty one that has the axis labels.
g2->Draw("3same");
g1->Draw("lsame");
*/
//		 if (1>0 ) return;

		 //======================================

     //jan17       TFile *fpol1 = TFile::Open("SigMac.root-STANDART-SHOWN-31jan17.root");
     // TFile *fpol1 = TFile::Open("SigMac.root-STANDART-16mar17.root");

 TFile *fpol1 = TFile::Open("./SigMac.root-6feb18-Data-LTfit-Pyt6-Pyt8.root");
  TH1D *h_spectrum = (TH1D*)fpol1->Get("stat")->Clone("h_spectrum");
  TH1D *data_syst = (TH1D*) fpol1->Get("syst")->Clone("data_syst");
  TH1D *h_spectrum_mc = (TH1D*)fpol1->Get("h_spectrum_mc"); 

  TH1D *h_spectrum_pyt8 = (TH1D*)fpol1->Get("hratio68dtmc"); 



  TFile *ffit = TFile::Open("./FitRes.root");

  gStyle->SetOptStat(0);
  gStyle->SetOptFit(0);

  //  data_stat->SetOptStat(0);
  data_stat->SetLineColor(kRed);
  data_stat->Draw("PE1");

  result->Draw("same");


  gStyle->SetOptStat(0);

 TH1D *ratiototal = (TH1D*)fpol1->Get("ratiototal"); 
 TH1D *ratioStatDtMC = (TH1D*)fpol1->Get("ratioStatDtMC"); 

 // ratioStatDtMC->Draw() ; if(1) return;


  TH1F *boxL = new TH1F("box","#pi^{0} production spectrum",8,0.,9.);
  TH1F *box = new TH1F("box","#pi^{0} production spectrum",8,0.,9.);

  boxL->SetAxisRange(0.0,4.,"Y");
  boxL->SetXTitle("#it{p}_{T} (GeV/#it{c})");
  //  boxL->SetYTitle("1/N_{inel}d^{3}N/dyd^{2}p_{t} (GeV^{-2}c^{2})");
  boxL->SetYTitle("1/#it{N}_{INEL} d^{2}#it{N}/(d#it{y}d#it{p}_{T}) [(GeV/#it{c})^{-1}]");
  boxL->SetTitleSize(0.05,"Y");
  boxL->SetTitleOffset(0.750,"Y");
  boxL->SetLabelOffset(0.0,"Y");
    boxL->SetLabelSize(0.05,"Y");
  boxL->SetMinimum(0.200001e-5) ;
  boxL->SetMaximum(0.20) ;


  /*  box->SetAxisRange(0.0,4.,"Y");
  box->SetXTitle("#it{p}_{T} (GeV/#it{c})");
  box->SetYTitle("Data/Perugia-2011"); 
  box->SetTitleSize(0.01,"Y");
  //  box->SetTitleOffset(1.0,"Y");
  box->SetTitleOffset(0.45,"Y");
  box->SetTitleSize(0.12,"Y");
  box->SetLabelSize(0.09,"Y");

  box->SetTitleOffset(1.02,"X");
  box->SetLabelSize(0.0,"X");
  box->SetTitleSize(0.09,"X"); */

  box->SetAxisRange(0.0,4.,"Y");
  box->SetXTitle("#it{p}_{T} (GeV/#it{c})");
  box->SetYTitle("Data/PYTHIA"); 
   //  box->SetTitleOffset(1.0,"Y");
  box->SetTitleOffset(0.4,"Y");
  box->SetTitleSize(0.10,"Y");
  box->SetLabelSize(0.09,"Y");

  box->SetTitleOffset(0.9,"X");
  box->SetLabelSize(0.09,"X");
  box->SetTitleSize(0.12,"X");


  box->SetMaximum(4.2) ;
  box->SetMinimum(0.500001e-5) ;

  gStyle->SetOptStat(0);

  h_spectrum->SetMarkerSize(1.1);
  h_spectrum_mc->SetMarkerSize(1.1);

  h_spectrum->SetMarkerColor(kRed);
  h_spectrum_mc->SetMarkerColor(kRed);

  ratiototal-> SetMarkerStyle(21);
 ratiototal-> SetMarkerColor(kRed);
 ratiototal->  SetLineColor(kRed);

 ratioStatDtMC->  SetLineColor(kRed);

 TCanvas * cM = new TCanvas("cM","Data-MC-ratio",10,10,800,800) ;
  cM->SetFillColor(0) ;
  cM->SetFillStyle(0) ;
  cM->Range(0,0,1.1,1.1);
  cM->SetBorderSize(0);
  gStyle->SetOptStat(0);
  
  //   spectrum_1 = new TPad("spectrum_1", "spectrum_1",0.001,0.32,0.99,0.99);
  spectrum_1 = new TPad("spectrum_1", "spectrum_1",0.001,0.32,0.99,0.99);

   spectrum_1->Draw();
   spectrum_1->cd();
   spectrum_1->Range(0,0,1,1);
   spectrum_1->SetFillColor(0);
   spectrum_1->SetFillStyle(0);
   spectrum_1->SetBorderSize(1);
   spectrum_1->SetBottomMargin(0.0);
   spectrum_1->SetTopMargin(0.03);
   spectrum_1->SetLeftMargin(0.10);
   spectrum_1->SetRightMargin(0.05);
   spectrum_1->SetLogy();
   spectrum_1->cd() ;



const Int_t fillColors[] = {kGray+1,  kRed-10, kBlue-9, kGreen-8, kMagenta-9, kOrange-9,kCyan-8,kYellow-7}; // for syst bands
const Int_t colors[]     = {kBlack, kRed , kBlue+1, kGreen+3, kMagenta+1, kOrange-1,kCyan+2,kYellow+2};
const Int_t markers[]    = {kFullCircle, kFullSquare,kOpenCircle,kOpenSquare,kOpenDiamond,kOpenCross,kFullCross,
 kFullDiamond,kFullStar,kOpenStar};

 Int_t icolor=1;
 data_syst ->SetMarkerColor(colors[icolor]);
 data_syst->SetFillColor(fillColors[icolor]);
 data_syst ->SetFillStyle(0);
 data_syst ->SetLineColor(colors[icolor]);
 data_syst ->SetLineWidth(0.1);

gStyle->SetOptStat(0);

 boxL->Draw();

 gStyle->SetOptStat(0);

   h_spectrum->Draw("E1same") ;

  gStyle->SetOptStat(0);

   data_syst ->Draw("PE2same");

   data_stat->SetLineColor(kRed);
   data_stat->SetMarkerColor(kRed);

   data_stat->Draw("same");


 //  h_spectrum_mc->Draw("E1,same") ;

   //  gr->Draw("lsame");

   // s4->SetLineColor(kBlue);

   s4->SetLineWidth(2.);

   s4->Draw("lsame");

  s41->SetLineWidth(2.);
 s41->Draw("lsame");

  TLatex * text = new TLatex (0.65,0.05,"ALICE, pp #sqrt{#it{s}} = 7 TeV (INEL)");
  text->SetTextSize(0.065);
  //  text.SetNDC();
  text->SetTextFont(42);
  text->Draw();

   TLatex * text3 = new TLatex (0.75,0.10,"#Sigma^{0} #rightarrow #Lambda #gamma,  #bar{#Sigma^{0}} #rightarrow #bar{#Lambda} #gamma");
   //  text3.SetNDC();
  text3->SetTextSize(0.07);
  text3->SetTextFont(42);
  //  text3->Draw();

   TLatex * text2 = new TLatex (0.20,0.1,"Uncertainties: stat. (bars), sys. (boxes)");
 // text2.SetNDC();
  text2->SetTextSize(0.04);
  text2->SetTextFont(42);
  text2->Draw();
 
   spectrum_1->cd() ;


   gStyle->SetOptStat(0);
 
   h_spectrum_mc->SetLineWidth(3.);
   h_spectrum_mc->SetLineColor(kRed);

   TLegend * l = new TLegend(0.45,0.45,0.9,0.75) ;
   l->SetFillColor(0) ;
   l->AddEntry(h_spectrum,"Data (#Sigma^{0} + #bar{#Sigma}^{0}) / 2","pl") ;
   l->AddEntry(h_spectrum,"Levy-Tsallis fit","l") ; 
   l->AddEntry(s4," PYTHIA6 Perugia-2011","l") ;
   l->AddEntry(s41," PYTHIA8 Monash-2013","l") ;

   //   l->AddEntry(fit,"Tsalis fit 5<p_{t}<25.","l") ;
   // l->SetFrameColor(1) ;
   l->Draw() ;

      cM->cd() ;
   TPad *spectrum_2 = new TPad("spectrum_2", "spectrum_2",0.001,0.01,0.99,0.32);
   spectrum_2->SetFillColor(0) ;
   spectrum_2->SetFillStyle(0) ;
   spectrum_2->SetLogy(0) ;
   spectrum_2->SetGridy(0) ;
   spectrum_2->Draw();
   spectrum_2->Range(0,0,1,1);
   spectrum_2->SetFillColor(0);
   spectrum_2->SetBorderSize(1);
   spectrum_2->SetTopMargin(0.0);
   spectrum_2->SetBottomMargin(0.25);
   spectrum_2->SetLeftMargin(0.10);
   spectrum_2->SetRightMargin(0.05);
   spectrum_2->cd() ;

   icolor=2;
ratiototal ->SetMarkerColor(colors[icolor]);
ratiototal ->SetFillColor(fillColors[icolor]);
ratiototal ->SetFillStyle(0);
 ratiototal ->SetLineColor(colors[icolor]);
ratiototal ->SetLineWidth(0.1);


h_spectrum_pyt8 ->SetMarkerColor(kMagenta);

h_spectrum_pyt8->SetFillColor(kMagenta);

h_spectrum_pyt8->SetFillStyle(0);

h_spectrum_pyt8->SetLineColor(kMagenta);

h_spectrum_pyt8->SetLineWidth(0.1);

h_spectrum_pyt8->SetMarkerStyle(21);


   box->Draw() ;
   //   ratiototal->Draw("E2same");
   ratiototal->Draw("E1same");
   h_spectrum_pyt8->Draw("E1same");

Int_t icolor=2;


ratioStatDtMC ->SetMarkerColor(colors[icolor]);
ratioStatDtMC->SetFillColor(fillColors[icolor]);
ratioStatDtMC->SetFillStyle(0);
 ratioStatDtMC->SetLineColor(colors[icolor]);
ratioStatDtMC->SetLineWidth(0.1);

  TLine* l1 = new TLine;
  //  l1->DrawLine(hx->GetXaxis()->GetXmin(),1., hx->GetXaxis()->GetXmax(), 1.0);
  l1->DrawLine(0., 1., 9., 1. );
    // (xx,0.02,xx,0.0228);

  ratioStatDtMC->Draw("PE1same");

  /*   
   TCanvas * cR2 = new TCanvas("cR2","Fits of Data-MC-ratios",10,10,800,800) ;
   cR2->Divide(2,2);

  TH1F *box2 = new TH1F("box2","#pi^{0} production spectrum",8,0.,9.);
  box2->SetAxisRange(0.0,4.,"Y");
  box2->SetXTitle("#it{p}_{T} (GeV/#it{c})");
  box2->SetYTitle("Data/PYTHIA"); 
   //  box->SetTitleOffset(1.0,"Y");
  box2->SetTitleOffset(0.4,"Y");
  box2->SetTitleSize(0.030,"Y");
  box2->SetLabelSize(0.09,"Y");

  box2->SetTitleOffset(0.9,"X");
  box2->SetLabelSize(0.09,"X");
  box2->SetTitleSize(0.032,"X");

  box2->SetMaximum(4.2) ;
  box2->SetMinimum(0.500001e-5) ;

   cR2->cd(1);
 gStyle->SetOptFit(1111);
 //      ratiototal->Draw("AP");
      // box2->Draw("") ; 
  ratiototal->Draw("Esame");
 gStyle->SetOptFit(1111);
   ratiototal->Fit("pol0","","",1.1,8.);

   cR2->cd(2);
gStyle->SetOptFit(11111);
// box2->Draw("") ; 
 ratiototal->Draw("Esame");
 gStyle->SetOptFit(11111);
 ratiototal->Fit("pol1","","",1.1,8.);


 // TCanvas * cR3 = new TCanvas("cR3","Fits of Data-MC-ratios",10,10,800,800) ;   cR3->Divide(1,2);



 cR2->cd(3);
gStyle->SetOptFit(1111);
// box2->Draw("") ;
  h_spectrum_pyt8 ->Draw("Esame");
 gStyle->SetOptFit(1111);
   h_spectrum_pyt8->Fit("pol0","","",1.1,8.);

 cR2->cd(4);
gStyle->SetOptFit(11111);
// box2->Draw("") ;
  h_spectrum_pyt8 ->Draw("Esame");
 gStyle->SetOptFit(11111);
   h_spectrum_pyt8->Fit("pol1","","",1.1,8.);
  */



   //   hSysRatio->Draw("sameE2") ;
   // hStatRatio->Draw("same") ;
   //   hSysRatio2->SetFillStyle(0) ;
   //   hSysRatio2->SetLineColor(1) ;
   //   hSysRatio2->Draw("sameE2") ;
   //   hStatRatio2->SetMarkerColor(1) ;
   //   hStatRatio2->SetMarkerStyle(24) ;
   //   hStatRatio2->Draw("same") ;

   /* TCanvas * cM1 = new TCanvas("cM1","Data-MC",10,10,800,800) ;
   data_stat->Draw("E1");
   //   s4->Draw("lsame");
   cM1->Draw("lsame");
   */

  TFile *fout = TFile::Open("MCResRes.root","RECREATE");

  //cM1->Write("");
  //   s4->SetLineWidth(3.);   s4->Draw("lsame");
 

 s4->Write("l");
  fout->Close();


}
//-----------------------------------------------------------------------------
void ALICEPreliminary(TPad *c){

  TPad *myPadLogo = new TPad("myPadLogo", "Pad for ALICE Logo",0.42,0.7,0.69,0.95);
  myPadLogo->SetFillColor(0); 
  myPadLogo->SetBorderMode(0);
  myPadLogo->SetBorderSize(2);
  myPadLogo->SetFrameBorderMode(0);
  myPadLogo->SetLeftMargin(0.15);
  myPadLogo->SetTopMargin(0.0);
  myPadLogo->SetBottomMargin(0.15);
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
  gStyle->SetLabelOffset(0.01,"y");
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
