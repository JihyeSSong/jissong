{
//=========Macro generated from canvas: c1_n4/c1_n4
//=========  (Mon Apr 16 16:41:14 2018) by ROOT version5.34/30
   TCanvas *c1_n4 = new TCanvas("c1_n4", "c1_n4",448,92,700,500);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c1_n4->Range(-1.756,0.2353489,9.950667,0.5405769);
   c1_n4->SetFillColor(10);
   c1_n4->SetBorderMode(0);
   c1_n4->SetBorderSize(2);
   c1_n4->SetTickx(1);
   c1_n4->SetTicky(1);
   c1_n4->SetLeftMargin(0.15);
   c1_n4->SetBottomMargin(0.15);
   c1_n4->SetFrameFillColor(0);
   c1_n4->SetFrameBorderMode(0);
   c1_n4->SetFrameBorderMode(0);
   
   TGraphErrors *gre = new TGraphErrors(10);
   gre->SetName("Graph0");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);
   gre->SetPoint(0,0.25,0.4904651);
   gre->SetPointError(0,0.05,0.0005121884);
   gre->SetPoint(1,0.7,0.3007051);
   gre->SetPointError(1,0.4,0.0004952473);
   gre->SetPoint(2,1.35,0.3203976);
   gre->SetPointError(2,0.25,0.001151183);
   gre->SetPoint(3,1.8,0.3437061);
   gre->SetPointError(3,0.2,0.001692323);
   gre->SetPoint(4,2.2,0.3485103);
   gre->SetPointError(4,0.2,0.002285309);
   gre->SetPoint(5,2.6,0.343408);
   gre->SetPointError(5,0.2,0.002992146);
   gre->SetPoint(6,3.1,0.3655896);
   gre->SetPointError(6,0.3,0.004385994);
   gre->SetPoint(7,3.7,0.3391241);
   gre->SetPointError(7,0.3,0.006220357);
   gre->SetPoint(8,4.5,0.3144913);
   gre->SetPointError(8,0.5,0.008859374);
   gre->SetPoint(9,6.5,0.334275);
   gre->SetPointError(9,1.5,0.01854652);
   
   TH1F *Graph_Graph2 = new TH1F("Graph_Graph2","Graph",100,0,8.78);
   Graph_Graph2->SetMinimum(0.2811331);
   Graph_Graph2->SetMaximum(0.5100541);
   Graph_Graph2->SetDirectory(0);
   Graph_Graph2->SetStats(0);

   ci = TColor::GetColor("#ff0000");
   Graph_Graph2->SetLineColor(ci);
   Graph_Graph2->GetXaxis()->SetLabelFont(42);
   Graph_Graph2->GetXaxis()->SetLabelOffset(0.01);
   Graph_Graph2->GetXaxis()->SetLabelSize(0.045);
   Graph_Graph2->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph2->GetXaxis()->SetTitleOffset(1.2);
   Graph_Graph2->GetXaxis()->SetTitleFont(42);
   Graph_Graph2->GetYaxis()->SetLabelFont(42);
   Graph_Graph2->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph2->GetYaxis()->SetLabelSize(0.045);
   Graph_Graph2->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph2->GetYaxis()->SetTitleOffset(1.25);
   Graph_Graph2->GetYaxis()->SetTitleFont(42);
   Graph_Graph2->GetZaxis()->SetLabelFont(42);
   Graph_Graph2->GetZaxis()->SetLabelSize(0.045);
   Graph_Graph2->GetZaxis()->SetTitleSize(0.05);
   Graph_Graph2->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph2);
   
   gre->Draw("alp");
   c1_n4->Modified();
   c1_n4->cd();
   c1_n4->SetSelected(c1_n4);
}
