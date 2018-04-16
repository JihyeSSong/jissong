{
//=========Macro generated from canvas: c1/c1
//=========  (Mon Apr 16 16:40:35 2018) by ROOT version5.34/30
   TCanvas *c1 = new TCanvas("c1", "c1",492,45,700,500);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c1->Range(-1.756,0.2074591,9.950667,0.4839324);
   c1->SetFillColor(10);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetTickx(1);
   c1->SetTicky(1);
   c1->SetLeftMargin(0.15);
   c1->SetBottomMargin(0.15);
   c1->SetFrameFillColor(0);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TGraphErrors *gre = new TGraphErrors(10);
   gre->SetName("Graph0");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);
   gre->SetPoint(0,0.25,0.4389356);
   gre->SetPointError(0,0.05,6.992606e-05);
   gre->SetPoint(1,0.7,0.2662726);
   gre->SetPointError(1,0.4,6.296073e-05);
   gre->SetPoint(2,1.35,0.285063);
   gre->SetPointError(2,0.25,0.0001377947);
   gre->SetPoint(3,1.8,0.3001202);
   gre->SetPointError(3,0.2,0.0002127028);
   gre->SetPoint(4,2.2,0.3075513);
   gre->SetPointError(4,0.2,0.00030191);
   gre->SetPoint(5,2.6,0.3131504);
   gre->SetPointError(5,0.2,0.0004166539);
   gre->SetPoint(6,3.1,0.316265);
   gre->SetPointError(6,0.3,0.0006037659);
   gre->SetPoint(7,3.7,0.3145022);
   gre->SetPointError(7,0.3,0.0008954056);
   gre->SetPoint(8,4.5,0.3197625);
   gre->SetPointError(8,0.5,0.001393487);
   gre->SetPoint(9,6.5,0.3085886);
   gre->SetPointError(9,1.5,0.00287543);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","Graph",100,0,8.78);
   Graph_Graph1->SetMinimum(0.2489301);
   Graph_Graph1->SetMaximum(0.4562851);
   Graph_Graph1->SetDirectory(0);
   Graph_Graph1->SetStats(0);

   ci = TColor::GetColor("#ff0000");
   Graph_Graph1->SetLineColor(ci);
   Graph_Graph1->GetXaxis()->SetLabelFont(42);
   Graph_Graph1->GetXaxis()->SetLabelOffset(0.01);
   Graph_Graph1->GetXaxis()->SetLabelSize(0.045);
   Graph_Graph1->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph1->GetXaxis()->SetTitleOffset(1.2);
   Graph_Graph1->GetXaxis()->SetTitleFont(42);
   Graph_Graph1->GetYaxis()->SetLabelFont(42);
   Graph_Graph1->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph1->GetYaxis()->SetLabelSize(0.045);
   Graph_Graph1->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph1->GetYaxis()->SetTitleOffset(1.25);
   Graph_Graph1->GetYaxis()->SetTitleFont(42);
   Graph_Graph1->GetZaxis()->SetLabelFont(42);
   Graph_Graph1->GetZaxis()->SetLabelSize(0.045);
   Graph_Graph1->GetZaxis()->SetTitleSize(0.05);
   Graph_Graph1->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1);
   
   gre->Draw("ACP");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
