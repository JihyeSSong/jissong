void olddt(int w=5) {

  gROOT->Reset();
  
  // type
  // plab
  // sqrts
  // ratio
  // error
  const int maxoftype = 32;
  const int maxtypes = 10;
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
  TString lbl[10];
  
  TNtuple* rat = new TNtuple("rat","Sig/Lam ratio","type:plab:s:ratio:err");
  rat->ReadFile("data-orig.txt");
  
  lbl[0] = "e^{+} e^{-}";
  lbl[1] = "#bar{p} p";
  lbl[2] = "p p";
  lbl[3] = "p Be";
  lbl[4] = "p Ne";
  lbl[9] = "K N";
  //lbl[9] = "K^{-} p";
  
  
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
  }
  for (int i=0;i<maxtypes;i++) {
    if (noft[i] > 0) {
      int j = i*maxoftype;
      gr[i] = new TGraphErrors(noft[i],&(s[j]),&(ratio[j]),xe,&(err[j]));
    }
  }
  
  gStyle->SetOptStat(0);
  //TH2F* hh = new TH2F("hh","#Sigma^{0}/#Lambda ratio",1,1.0,500.,1,0.03,1.5);
  TH2F* hh = new TH2F("hh","#Sigma^{0}/#Lambda ratio",1,1.3,150.,1,0.025,1.3);
  //TH2F* hh = new TH2F("hh","#Sigma^{0}/#Lambda ratio",1,0.6,6,1,0.025,1.3);
  TH2F* h2 = new TH2F("h2","#Sigma^{0}/#Lambda ratio",1,1.5,4.0,1,0.025,1.0);
  TH2F* h3 = new TH2F("h3","#Sigma^{0}/#Lambda ratio",1,1.8765,1.8775,1,0.02,0.2);
  TH2F* h4 = new TH2F("h4","#Sigma^{0}/#Lambda ratio",1,1.8775,150.,1,0.02,1.3);
  TH2F* h5 = new TH2F("h5","#Sigma^{0}/#Lambda ratio",10000,1.8765,1.8776,1,0.02,1.3);
  TCanvas* c1 = new TCanvas("c1","plots",900,500);
  TPad* p1 = new TPad("p1","pad1",0.401,0.02,1.0,0.98);
  TPad* p2 = new TPad("p2","pad1",0.02,0.02,0.40,0.98);
  p1->SetLogy(1);
  p1->SetLogx(1);
  p1->Draw();
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
    hx->GetXaxis()->SetNdivisions(999999,0);
    hx->SetLabelSize(0.065,"y");
    hx->SetLabelSize(0.065,"x");
    hl->SetLabelSize(0.05,"x");
    hl->SetTitle("");
    hl->SetTitleSize(0.05,"x");
    hl->SetTitleOffset(1.05,"x");
    p1->SetLeftMargin(0.000);
    p2->SetRightMargin(0.002);
    p2->SetLeftMargin(0.15);
    p2->SetBottomMargin(0.11);
    p1->SetBottomMargin(0.11);
    p2->SetTopMargin(0.02);
    p1->SetTopMargin(0.02);
  }
    
  TLatex* lt = new TLatex();
//  TLegend* ll = new TLegend(0.55,0.14,0.8,0.65,"System:");
  TLegend* ll = new TLegend(0.6,0.15,0.8,0.5);
  
  hl->SetXTitle("#sqrt{s} [GeV]");
  
  p1->cd();
  hl->Draw();
  //gStyle->SetPalette(1);
  
  int clrs[10] = {4,1,2,2,2,0,0,0,4,4};
  int stys[10] = {25,23,26,20,21,0,0,0,0,28};
  
  for (int i=0;i<maxtypes;i++) {
    if (gr[i]) {
      cout << "siz= " << gr[i]->GetN() << endl;
      gr[i]->SetMarkerColor(clrs[i]);
      gr[i]->SetMarkerStyle(stys[i]);
      gr[i]->Draw("p");
      ll->AddEntry(gr[i],lbl[i].Data(),"p");
    }
  }
  ll->Draw();
  l1->SetLineStyle(2);
  l1->DrawLine(hl->GetXaxis()->GetXmin(),0.333,hl->GetXaxis()->GetXmax(),0.333);
  
  if (w>=4) {
    p2->cd();
    hx->SetTitle("");
    hx->Draw();
    for (int i=0;i<maxtypes;i++) {
      if (gr[i]) {
	gr[i]->SetMarkerColor(clrs[i]);
	gr[i]->SetMarkerStyle(stys[i]);
	gr[i]->SetMarkerSize(1.5);
	gr[i]->Draw("p");
      }
    }
    l1->DrawLine(hx->GetXaxis()->GetXmin(),0.333,hx->GetXaxis()->GetXmax(),0.333);
    lt->SetTextSize(0.15);
    lt->DrawLatex(1.87665,0.7,"#Sigma^{0}/#Lambda");
    lt->SetTextSize(0.065);
    lt->DrawLatex(1.87632,0.0155,"1.8765");
    lt->DrawLatex(1.87728,0.0155,"1.8775");
    for (float xx=1.8766;xx<1.8775;xx+=0.0001) l1->DrawLine(xx,0.02,xx,0.0212);
    l1->DrawLine(xx,0.02,xx,0.0228);
  }
  
  c1->Update();
  
}
