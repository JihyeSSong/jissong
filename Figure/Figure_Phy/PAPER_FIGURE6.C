void PAPER_FIGURE6()
{
//=========Macro generated from canvas: c/
//=========  (Wed Feb  3 14:05:05 2016) by ROOT version6.06/00
   TCanvas *c = new TCanvas("c", "",455,45,800,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
    gStyle->SetLineWidth(2);

   c->Range(0,0,1,1);
   c->SetFillColor(0);
   c->SetBorderMode(0);
   c->SetBorderSize(2);
   c->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: p2
   TPad *p2 = new TPad("p2", "",0,0,1,1);
   p2->Draw();
   p2->cd();
   p2->Range(-0.7519231,-0.5023256,3.671154,3.683721);
   p2->SetFillColor(0);
   p2->SetBorderMode(0);
   p2->SetBorderSize(2);
   p2->SetTickx(1);
   p2->SetTicky(1);
   p2->SetLeftMargin(0.17);
   p2->SetRightMargin(0.05);
   p2->SetTopMargin(0.02);
   p2->SetBottomMargin(0.12);
   p2->SetFrameBorderMode(0);
   p2->SetFrameBorderMode(0);
   
   TH1F *frame__1__1 = new TH1F("frame__1__1","",1,0,3.45);
   frame__1__1->SetMinimum(0);
   frame__1__1->SetMaximum(3.6);
   frame__1__1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000000");
   frame__1__1->SetLineColor(ci);
   frame__1__1->GetXaxis()->SetTitle("#it{m} (GeV/#it{c}^{2})");
   frame__1__1->GetXaxis()->SetLabelFont(42);
   frame__1__1->GetXaxis()->SetLabelOffset(0.01);
   frame__1__1->GetXaxis()->SetLabelSize(0.045);
   frame__1__1->GetXaxis()->SetTitleSize(0.06);
   frame__1__1->GetXaxis()->SetTitleOffset(0.92);
   frame__1__1->GetXaxis()->SetTitleFont(42);
   frame__1__1->GetYaxis()->SetTitle("#LT#it{p}_{T}#GT (GeV/#it{c})");
   frame__1__1->GetYaxis()->SetNdivisions(509);
   frame__1__1->GetYaxis()->SetLabelFont(42);
   frame__1__1->GetYaxis()->SetLabelOffset(0.01);
   frame__1__1->GetYaxis()->SetLabelSize(0.045);
   frame__1__1->GetYaxis()->SetTitleSize(0.06);
   frame__1__1->GetYaxis()->SetTickLength(0.02);
   frame__1__1->GetYaxis()->SetTitleOffset(0.92);
   frame__1__1->GetYaxis()->SetTitleFont(42);
   frame__1__1->GetZaxis()->SetLabelFont(42);
   frame__1__1->GetZaxis()->SetLabelOffset(0.01);
   frame__1__1->GetZaxis()->SetLabelSize(0.05);
   frame__1__1->GetZaxis()->SetTitleSize(0.06);
   frame__1__1->GetZaxis()->SetTitleFont(42);
   frame__1__1->Draw("");
   
   Double_t GraphStat_fx1001[11] = {
   0.1395702,
   0.493677,
   0.527614,
   0.938272,
   0.89594,
   1.019455,
   1.115683,
   1.32171,
   1.3872,
   1.5318,
   1.67845};
   Double_t GraphStat_fy1001[11] = {
   0.538368,
   0.920836,
   0.935784,
   1.222741,
   1.3789,
   1.4344,
   1.355523,
   1.543919,
   -10,
   -10,
   1.810031};
   Double_t GraphStat_fex1001[11] = {
   0.03,
   0.03,
   0.03,
   0.03,
   0.03,
   0.03,
   0.03,
   0.03,
   0.03,
   0.03,
   0.03};
   Double_t GraphStat_fey1001[11] = {
   0.000414,
   0.004328,
   0.001865,
   0.003868,
   0.011,
   0.0088,
   0.004851,
   0.009166,
   0,
   0,
   0.057617};
   TGraphErrors *gre = new TGraphErrors(11,GraphStat_fx1001,GraphStat_fy1001,GraphStat_fex1001,GraphStat_fey1001);
   gre->SetName("GraphStat");
   gre->SetTitle("GraphStat");
   gre->SetFillColor(1);
   gre->SetLineColor(1);
   gre->SetLineWidth(2);
   gre->SetMarkerColor(1);
   gre->SetMarkerStyle(25);
   gre->SetMarkerSize(1.5);
   
   TH1F *Graph_Graph_GraphStat10011001 = new TH1F("Graph_Graph_GraphStat10011001","GraphStat",100,0,1.868338);
   Graph_Graph_GraphStat10011001->SetMinimum(-11.18676);
   Graph_Graph_GraphStat10011001->SetMaximum(3.054413);
   Graph_Graph_GraphStat10011001->SetDirectory(0);
   Graph_Graph_GraphStat10011001->SetStats(0);

   ci = TColor::GetColor("#000000");
   Graph_Graph_GraphStat10011001->SetLineColor(ci);
   Graph_Graph_GraphStat10011001->GetXaxis()->SetLabelFont(42);
   Graph_Graph_GraphStat10011001->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_GraphStat10011001->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_GraphStat10011001->GetXaxis()->SetTitleFont(42);
   Graph_Graph_GraphStat10011001->GetYaxis()->SetLabelFont(42);
   Graph_Graph_GraphStat10011001->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_GraphStat10011001->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_GraphStat10011001->GetYaxis()->SetTitleFont(42);
   Graph_Graph_GraphStat10011001->GetZaxis()->SetLabelFont(42);
   Graph_Graph_GraphStat10011001->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_GraphStat10011001->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_GraphStat10011001->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_GraphStat10011001);
   
   gre->Draw("pz");
   
   Double_t GraphSyst_fx1002[11] = {
   0.1395702,
   0.493677,
   0.527614,
   0.938272,
   0.89594,
   1.019455,
   1.115683,
   1.32171,
   1.3872,
   1.5318,
   1.67845};
   Double_t GraphSyst_fy1002[11] = {
   0.538368,
   0.920836,
   0.935784,
   1.222741,
   1.3789,
   1.4344,
   1.355523,
   1.543919,
   -10,
   -10,
   1.810031};
   Double_t GraphSyst_fex1002[11] = {
   0.03,
   0.03,
   0.03,
   0.03,
   0.03,
   0.03,
   0.03,
   0.03,
   0.03,
   0.03,
   0.03};
   Double_t GraphSyst_fey1002[11] = {
   0.014927,
   0.084655,
   0.01367,
   0.047728,
   0.0181,
   0.0261,
   0.039111,
   0.052525,
   0,
   0,
   0.157296};
   gre = new TGraphErrors(11,GraphSyst_fx1002,GraphSyst_fy1002,GraphSyst_fex1002,GraphSyst_fey1002);
   gre->SetName("GraphSyst");
   gre->SetTitle("GraphSyst");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(1);
   gre->SetLineWidth(2);
   gre->SetMarkerColor(1);
   gre->SetMarkerStyle(25);
   gre->SetMarkerSize(1.5);
   
   TH1F *Graph_Graph_GraphSyst10021002 = new TH1F("Graph_Graph_GraphSyst10021002","GraphSyst",100,0,1.868338);
   Graph_Graph_GraphSyst10021002->SetMinimum(-11.19673);
   Graph_Graph_GraphSyst10021002->SetMaximum(3.16406);
   Graph_Graph_GraphSyst10021002->SetDirectory(0);
   Graph_Graph_GraphSyst10021002->SetStats(0);

   ci = TColor::GetColor("#000000");
   Graph_Graph_GraphSyst10021002->SetLineColor(ci);
   Graph_Graph_GraphSyst10021002->GetXaxis()->SetLabelFont(42);
   Graph_Graph_GraphSyst10021002->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_GraphSyst10021002->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_GraphSyst10021002->GetXaxis()->SetTitleFont(42);
   Graph_Graph_GraphSyst10021002->GetYaxis()->SetLabelFont(42);
   Graph_Graph_GraphSyst10021002->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_GraphSyst10021002->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_GraphSyst10021002->GetYaxis()->SetTitleFont(42);
   Graph_Graph_GraphSyst10021002->GetZaxis()->SetLabelFont(42);
   Graph_Graph_GraphSyst10021002->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_GraphSyst10021002->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_GraphSyst10021002->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_GraphSyst10021002);
   
   gre->Draw("[]");
   
   Double_t GraphSigmaStarStat_fx1003[1] = {
   1.3872};
   Double_t GraphSigmaStarStat_fy1003[1] = {
   1.495};
   Double_t GraphSigmaStarStat_fex1003[1] = {
   0.03};
   Double_t GraphSigmaStarStat_fey1003[1] = {
   0.012};
   gre = new TGraphErrors(1,GraphSigmaStarStat_fx1003,GraphSigmaStarStat_fy1003,GraphSigmaStarStat_fex1003,GraphSigmaStarStat_fey1003);
   gre->SetName("GraphSigmaStarStat");
   gre->SetTitle("GraphSigmaStarStat");
   gre->SetFillColor(1);
   gre->SetLineColor(2);
   gre->SetLineWidth(2);
   gre->SetMarkerColor(2);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(1.5);
   
   TH1F *Graph_Graph_GraphSigmaStarStat10031003 = new TH1F("Graph_Graph_GraphSigmaStarStat10031003","GraphSigmaStarStat",100,1.3512,1.4232);
   Graph_Graph_GraphSigmaStarStat10031003->SetMinimum(1.4918);
   Graph_Graph_GraphSigmaStarStat10031003->SetMaximum(1.5182);
   Graph_Graph_GraphSigmaStarStat10031003->SetDirectory(0);
   Graph_Graph_GraphSigmaStarStat10031003->SetStats(0);

   ci = TColor::GetColor("#000000");
   Graph_Graph_GraphSigmaStarStat10031003->SetLineColor(ci);
   Graph_Graph_GraphSigmaStarStat10031003->GetXaxis()->SetLabelFont(42);
   Graph_Graph_GraphSigmaStarStat10031003->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_GraphSigmaStarStat10031003->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_GraphSigmaStarStat10031003->GetXaxis()->SetTitleFont(42);
   Graph_Graph_GraphSigmaStarStat10031003->GetYaxis()->SetLabelFont(42);
   Graph_Graph_GraphSigmaStarStat10031003->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_GraphSigmaStarStat10031003->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_GraphSigmaStarStat10031003->GetYaxis()->SetTitleFont(42);
   Graph_Graph_GraphSigmaStarStat10031003->GetZaxis()->SetLabelFont(42);
   Graph_Graph_GraphSigmaStarStat10031003->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_GraphSigmaStarStat10031003->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_GraphSigmaStarStat10031003->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_GraphSigmaStarStat10031003);
   
   gre->Draw("pz");
   
   Double_t GraphSigmaStarSyst_fx1004[1] = {
   1.3872};
   Double_t GraphSigmaStarSyst_fy1004[1] = {
   1.495};
   Double_t GraphSigmaStarSyst_fex1004[1] = {
   0.03};
   //   Double_t GraphSigmaStarSyst_fey1004[1] = {
   //0.027};
   Double_t GraphSigmaStarSyst_fey1004[1] = {
   0.046};
   gre = new TGraphErrors(1,GraphSigmaStarSyst_fx1004,GraphSigmaStarSyst_fy1004,GraphSigmaStarSyst_fex1004,GraphSigmaStarSyst_fey1004);
   gre->SetName("GraphSigmaStarSyst");
   gre->SetTitle("GraphSigmaStarSyst");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(2);
   gre->SetLineWidth(2);
   gre->SetMarkerColor(2);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(1.5);
   
   TH1F *Graph_Graph_GraphSigmaStarSyst10041004 = new TH1F("Graph_Graph_GraphSigmaStarSyst10041004","GraphSigmaStarSyst",100,1.3512,1.4232);
   Graph_Graph_GraphSigmaStarSyst10041004->SetMinimum(1.4402);
   Graph_Graph_GraphSigmaStarSyst10041004->SetMaximum(1.5698);
   Graph_Graph_GraphSigmaStarSyst10041004->SetDirectory(0);
   Graph_Graph_GraphSigmaStarSyst10041004->SetStats(0);

   ci = TColor::GetColor("#000000");
   Graph_Graph_GraphSigmaStarSyst10041004->SetLineColor(ci);
   Graph_Graph_GraphSigmaStarSyst10041004->GetXaxis()->SetLabelFont(42);
   Graph_Graph_GraphSigmaStarSyst10041004->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_GraphSigmaStarSyst10041004->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_GraphSigmaStarSyst10041004->GetXaxis()->SetTitleFont(42);
   Graph_Graph_GraphSigmaStarSyst10041004->GetYaxis()->SetLabelFont(42);
   Graph_Graph_GraphSigmaStarSyst10041004->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_GraphSigmaStarSyst10041004->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_GraphSigmaStarSyst10041004->GetYaxis()->SetTitleFont(42);
   Graph_Graph_GraphSigmaStarSyst10041004->GetZaxis()->SetLabelFont(42);
   Graph_Graph_GraphSigmaStarSyst10041004->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_GraphSigmaStarSyst10041004->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_GraphSigmaStarSyst10041004->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_GraphSigmaStarSyst10041004);
   
   gre->Draw("[]");
   
   Double_t GraphXiStarStat_fx1005[1] = {
   1.5318};
   Double_t GraphXiStarStat_fy1005[1] = {
   1.626};
   Double_t GraphXiStarStat_fex1005[1] = {
   0.03};
   Double_t GraphXiStarStat_fey1005[1] = {
   0.016};
   gre = new TGraphErrors(1,GraphXiStarStat_fx1005,GraphXiStarStat_fy1005,GraphXiStarStat_fex1005,GraphXiStarStat_fey1005);
   gre->SetName("GraphXiStarStat");
   gre->SetTitle("GraphXiStarStat");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(4);
   gre->SetLineWidth(2);
   gre->SetMarkerColor(4);
   gre->SetMarkerStyle(21);
   gre->SetMarkerSize(1.5);
   
   TH1F *Graph_Graph_GraphXiStarStat10051005 = new TH1F("Graph_Graph_GraphXiStarStat10051005","GraphXiStarStat",100,1.4958,1.5678);
   Graph_Graph_GraphXiStarStat10051005->SetMinimum(1.6258);
   Graph_Graph_GraphXiStarStat10051005->SetMaximum(1.6642);
   Graph_Graph_GraphXiStarStat10051005->SetDirectory(0);
   Graph_Graph_GraphXiStarStat10051005->SetStats(0);

   ci = TColor::GetColor("#000000");
   Graph_Graph_GraphXiStarStat10051005->SetLineColor(ci);
   Graph_Graph_GraphXiStarStat10051005->GetXaxis()->SetLabelFont(42);
   Graph_Graph_GraphXiStarStat10051005->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_GraphXiStarStat10051005->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_GraphXiStarStat10051005->GetXaxis()->SetTitleFont(42);
   Graph_Graph_GraphXiStarStat10051005->GetYaxis()->SetLabelFont(42);
   Graph_Graph_GraphXiStarStat10051005->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_GraphXiStarStat10051005->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_GraphXiStarStat10051005->GetYaxis()->SetTitleFont(42);
   Graph_Graph_GraphXiStarStat10051005->GetZaxis()->SetLabelFont(42);
   Graph_Graph_GraphXiStarStat10051005->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_GraphXiStarStat10051005->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_GraphXiStarStat10051005->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_GraphXiStarStat10051005);
   
   gre->Draw("pz");
   
   Double_t GraphXiStarSyst_fx1006[1] = {
   1.5318};
   Double_t GraphXiStarSyst_fy1006[1] = {
   1.626};
   Double_t GraphXiStarSyst_fex1006[1] = {
   0.03};
   Double_t GraphXiStarSyst_fey1006[1] = {
   0.068};
   gre = new TGraphErrors(1,GraphXiStarSyst_fx1006,GraphXiStarSyst_fy1006,GraphXiStarSyst_fex1006,GraphXiStarSyst_fey1006);
   gre->SetName("GraphXiStarSyst");
   gre->SetTitle("GraphXiStarSyst");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(4);
   gre->SetLineWidth(2);
   gre->SetMarkerColor(4);
   gre->SetMarkerStyle(21);
   gre->SetMarkerSize(1.5);
   
   TH1F *Graph_Graph_GraphXiStarSyst10061006 = new TH1F("Graph_Graph_GraphXiStarSyst10061006","GraphXiStarSyst",100,1.4958,1.5678);
   Graph_Graph_GraphXiStarSyst10061006->SetMinimum(1.5862);
   Graph_Graph_GraphXiStarSyst10061006->SetMaximum(1.7038);
   Graph_Graph_GraphXiStarSyst10061006->SetDirectory(0);
   Graph_Graph_GraphXiStarSyst10061006->SetStats(0);

   ci = TColor::GetColor("#000000");
   Graph_Graph_GraphXiStarSyst10061006->SetLineColor(ci);
   Graph_Graph_GraphXiStarSyst10061006->GetXaxis()->SetLabelFont(42);
   Graph_Graph_GraphXiStarSyst10061006->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_GraphXiStarSyst10061006->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_GraphXiStarSyst10061006->GetXaxis()->SetTitleFont(42);
   Graph_Graph_GraphXiStarSyst10061006->GetYaxis()->SetLabelFont(42);
   Graph_Graph_GraphXiStarSyst10061006->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_GraphXiStarSyst10061006->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_GraphXiStarSyst10061006->GetYaxis()->SetTitleFont(42);
   Graph_Graph_GraphXiStarSyst10061006->GetZaxis()->SetLabelFont(42);
   Graph_Graph_GraphXiStarSyst10061006->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_GraphXiStarSyst10061006->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_GraphXiStarSyst10061006->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_GraphXiStarSyst10061006);
   
   gre->Draw("[]");
    
    Double_t GraphD0Stat_fx1005[1] = {
        1.859024};
    Double_t GraphD0Stat_fy1005[1] = {
        2.13};
    Double_t GraphD0Stat_fex1005[1] = {
        0.03};
    Double_t GraphD0Stat_fey1005[1] = {
        0.05};
    gre = new TGraphErrors(1,GraphD0Stat_fx1005,GraphD0Stat_fy1005,GraphD0Stat_fex1005,GraphD0Stat_fey1005);
    gre->SetName("GraphD0Stat");
    gre->SetTitle("GraphD0Stat");
    gre->SetFillColor(1);
    gre->SetFillStyle(0);
    gre->SetLineColor(1);
    gre->SetLineWidth(2);
    gre->SetMarkerColor(1);
    gre->SetMarkerStyle(27);
    gre->SetMarkerSize(2.3);
    
    TH1F *GraphD0Stat = new TH1F("GraphD0Stat","GraphD0Stat",100,1.4958,1.5678);
    GraphD0Stat->SetMinimum(1.6258);
    GraphD0Stat->SetMaximum(1.6642);
    GraphD0Stat->SetDirectory(0);
    GraphD0Stat->SetStats(0);
    
    GraphD0Stat->SetLineColor(ci);
    GraphD0Stat->GetXaxis()->SetLabelFont(42);
    GraphD0Stat->GetXaxis()->SetLabelSize(0.035);
    GraphD0Stat->GetXaxis()->SetTitleSize(0.035);
    GraphD0Stat->GetXaxis()->SetTitleFont(42);
    GraphD0Stat->GetYaxis()->SetLabelFont(42);
    GraphD0Stat->GetYaxis()->SetLabelSize(0.035);
    GraphD0Stat->GetYaxis()->SetTitleSize(0.035);
    GraphD0Stat->GetYaxis()->SetTitleFont(42);
    GraphD0Stat->GetZaxis()->SetLabelFont(42);
    GraphD0Stat->GetZaxis()->SetLabelSize(0.035);
    GraphD0Stat->GetZaxis()->SetTitleSize(0.035);
    GraphD0Stat->GetZaxis()->SetTitleFont(42);
    gre->SetHistogram(GraphD0Stat);
    
    gre->Draw("pz");
    
    Double_t GraphD0Syst_fx1006[1] = {
        1.859024};
    Double_t GraphD0Syst_fy1006[1] = {
        2.13};
    Double_t GraphD0Syst_fex1006[1] = {
        0.03};
    Double_t GraphD0Syst_fey1006[1] = {
        0.10};
    gre = new TGraphErrors(1,GraphD0Syst_fx1006,GraphD0Syst_fy1006,GraphD0Syst_fex1006,GraphD0Syst_fey1006);
    gre->SetName("GraphD0Syst");
    gre->SetTitle("GraphD0Syst");
    gre->SetFillColor(1);
    gre->SetFillStyle(0);
    gre->SetLineColor(1);
    gre->SetLineWidth(2);
    gre->SetMarkerColor(1);
    gre->SetMarkerStyle(27);
    gre->SetMarkerSize(2.3);
    
    TH1F *GraphD0Syst = new TH1F("GraphD0Syst","GraphD0Syst",100,1.4958,1.5678);
    GraphD0Syst->SetMinimum(1.5862);
    GraphD0Syst->SetMaximum(1.7038);
    GraphD0Syst->SetDirectory(0);
    GraphD0Syst->SetStats(0);
    
    ci = TColor::GetColor("#000000");
    GraphD0Syst->SetLineColor(ci);
    GraphD0Syst->GetXaxis()->SetLabelFont(42);
    GraphD0Syst->GetXaxis()->SetLabelSize(0.035);
    GraphD0Syst->GetXaxis()->SetTitleSize(0.035);
    GraphD0Syst->GetXaxis()->SetTitleFont(42);
    GraphD0Syst->GetYaxis()->SetLabelFont(42);
    GraphD0Syst->GetYaxis()->SetLabelSize(0.035);
    GraphD0Syst->GetYaxis()->SetTitleSize(0.035);
    GraphD0Syst->GetYaxis()->SetTitleFont(42);
    GraphD0Syst->GetZaxis()->SetLabelFont(42);
    GraphD0Syst->GetZaxis()->SetLabelSize(0.035);
    GraphD0Syst->GetZaxis()->SetTitleSize(0.035);
    GraphD0Syst->GetZaxis()->SetTitleFont(42);
    gre->SetHistogram(GraphD0Syst);
    
    gre->Draw("[]");

   
   Double_t GraphJpsiSyst_fx1007[1] = {
   3.0969};
   Double_t GraphJpsiSyst_fy1007[1] = {
   2.86};
   Double_t GraphJpsiSyst_fex1007[1] = {
   0.03};
   Double_t GraphJpsiSyst_fey1007[1] = {
   0.15};
   gre = new TGraphErrors(1,GraphJpsiSyst_fx1007,GraphJpsiSyst_fy1007,GraphJpsiSyst_fex1007,GraphJpsiSyst_fey1007);
   gre->SetName("GraphJpsiSyst");
   gre->SetTitle("GraphJpsiSyst");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(1);
   gre->SetLineWidth(2);
   gre->SetMarkerColor(1);
   gre->SetMarkerStyle(27);
   gre->SetMarkerSize(2.3);
   
   TH1F *Graph_Graph_GraphJpsiSyst10071007 = new TH1F("Graph_Graph_GraphJpsiSyst10071007","GraphJpsiSyst",100,3.0609,3.1329);
   Graph_Graph_GraphJpsiSyst10071007->SetMinimum(2.74);
   Graph_Graph_GraphJpsiSyst10071007->SetMaximum(2.98);
   Graph_Graph_GraphJpsiSyst10071007->SetDirectory(0);
   Graph_Graph_GraphJpsiSyst10071007->SetStats(0);

   ci = TColor::GetColor("#000000");
   Graph_Graph_GraphJpsiSyst10071007->SetLineColor(ci);
   Graph_Graph_GraphJpsiSyst10071007->GetXaxis()->SetLabelFont(42);
   Graph_Graph_GraphJpsiSyst10071007->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_GraphJpsiSyst10071007->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_GraphJpsiSyst10071007->GetXaxis()->SetTitleFont(42);
   Graph_Graph_GraphJpsiSyst10071007->GetYaxis()->SetLabelFont(42);
   Graph_Graph_GraphJpsiSyst10071007->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_GraphJpsiSyst10071007->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_GraphJpsiSyst10071007->GetYaxis()->SetTitleFont(42);
   Graph_Graph_GraphJpsiSyst10071007->GetZaxis()->SetLabelFont(42);
   Graph_Graph_GraphJpsiSyst10071007->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_GraphJpsiSyst10071007->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_GraphJpsiSyst10071007->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_GraphJpsiSyst10071007);
   
   gre->Draw("pz");
   
   Double_t GraphJpsiSyst_fx1008[1] = {
   3.0969};
   Double_t GraphJpsiSyst_fy1008[1] = {
   2.86};
   Double_t GraphJpsiSyst_fex1008[1] = {
   0.03};
   Double_t GraphJpsiSyst_fey1008[1] = {
   0.1};
   gre = new TGraphErrors(1,GraphJpsiSyst_fx1008,GraphJpsiSyst_fy1008,GraphJpsiSyst_fex1008,GraphJpsiSyst_fey1008);
   gre->SetName("GraphJpsiSyst");
   gre->SetTitle("GraphJpsiSyst");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(1);
   gre->SetLineWidth(2);
   gre->SetMarkerColor(1);
   gre->SetMarkerStyle(27);
   gre->SetMarkerSize(2.3);
   
   TH1F *Graph_Graph_Graph_GraphJpsiSyst100710081008 = new TH1F("Graph_Graph_Graph_GraphJpsiSyst100710081008","GraphJpsiSyst",100,3.0609,3.1329);
   Graph_Graph_Graph_GraphJpsiSyst100710081008->SetMinimum(2.74);
   Graph_Graph_Graph_GraphJpsiSyst100710081008->SetMaximum(2.98);
   Graph_Graph_Graph_GraphJpsiSyst100710081008->SetDirectory(0);
   Graph_Graph_Graph_GraphJpsiSyst100710081008->SetStats(0);

   ci = TColor::GetColor("#000000");
   Graph_Graph_Graph_GraphJpsiSyst100710081008->SetLineColor(ci);
   Graph_Graph_Graph_GraphJpsiSyst100710081008->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph_GraphJpsiSyst100710081008->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph_GraphJpsiSyst100710081008->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph_GraphJpsiSyst100710081008->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph_GraphJpsiSyst100710081008->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph_GraphJpsiSyst100710081008->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph_GraphJpsiSyst100710081008->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph_GraphJpsiSyst100710081008->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph_GraphJpsiSyst100710081008->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph_GraphJpsiSyst100710081008->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph_GraphJpsiSyst100710081008->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph_GraphJpsiSyst100710081008->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_Graph_GraphJpsiSyst100710081008);
   
   gre->Draw("[]");
   
   Double_t GraphppStat_fx1009[13] = {
   0.1395702,
   0.493677,
   0.527614,
   0.938272,
   0.89594,
   1.019455,
   1.115683,
   1.32171,
   1.3872,
   1.5318,
   1.67845,
       1.859024,
   3.0969};
   Double_t GraphppStat_fy1009[13] = {
   0.466,
   0.773,
   0.7728,
   0.9,
   1.01,
   1.07,
   1.0323,
   1.21,
   1.17,
   1.33,
   1.47,
       2.18,
   2.72};
   Double_t GraphppStat_fex1009[13] = {
   0.03,
   0.03,
   0.03,
   0.03,
   0.03,
   0.03,
   0.03,
   0.03,
   0.03,
   0.03,
   0.03,
       0.03,
   0.03};
   Double_t GraphppStat_fey1009[13] = {
   9e-05,
   0.0006,
   0.0006,
   0.0006,
   0.003,
   0.005,
   0.001,
   0.01,
   0.02,
   0.02,
   0.03,
       0.08,
   0.14};
   gre = new TGraphErrors(13,GraphppStat_fx1009,GraphppStat_fy1009,GraphppStat_fex1009,GraphppStat_fey1009);
   gre->SetName("GraphppStat");
   gre->SetTitle("GraphppStat");
   gre->SetFillColor(1);
   gre->SetLineColor(1);
   gre->SetLineWidth(2);
   gre->SetMarkerColor(1);
   gre->SetMarkerStyle(34);
   gre->SetMarkerSize(1.7);
   
   TH1F *Graph_Graph_GraphppStat10091009 = new TH1F("Graph_Graph_GraphppStat10091009","GraphppStat",100,0,3.428633);
   Graph_Graph_GraphppStat10091009->SetMinimum(0.226501);
   Graph_Graph_GraphppStat10091009->SetMaximum(3.099409);
   Graph_Graph_GraphppStat10091009->SetDirectory(0);
   Graph_Graph_GraphppStat10091009->SetStats(0);

   ci = TColor::GetColor("#000000");
   Graph_Graph_GraphppStat10091009->SetLineColor(ci);
   Graph_Graph_GraphppStat10091009->GetXaxis()->SetLabelFont(42);
   Graph_Graph_GraphppStat10091009->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_GraphppStat10091009->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_GraphppStat10091009->GetXaxis()->SetTitleFont(42);
   Graph_Graph_GraphppStat10091009->GetYaxis()->SetLabelFont(42);
   Graph_Graph_GraphppStat10091009->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_GraphppStat10091009->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_GraphppStat10091009->GetYaxis()->SetTitleFont(42);
   Graph_Graph_GraphppStat10091009->GetZaxis()->SetLabelFont(42);
   Graph_Graph_GraphppStat10091009->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_GraphppStat10091009->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_GraphppStat10091009->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_GraphppStat10091009);
   
   gre->Draw("pz");
   
   Double_t GraphppSyst_fx1010[13] = {
   0.1395702,
   0.493677,
   0.527614,
   0.938272,
   0.89594,
   1.019455,
   1.115683,
   1.32171,
   1.3872,
   1.5318,
   1.67845,
       1.859024,
   3.0969};
   Double_t GraphppSyst_fy1010[13] = {
   0.466,
   0.773,
   0.7728,
   0.9,
   1.01,
   1.07,
   1.0323,
   1.21,
   1.17,
   1.33,
   1.47,
       2.18,
   2.72};
   Double_t GraphppSyst_fex1010[13] = {
   0.03,
   0.03,
   0.03,
   0.03,
   0.03,
   0.03,
   0.03,
   0.03,
   0.03,
   0.03,
   0.03,
       0.03,
   0.02};
   Double_t GraphppSyst_fey1010[13] = {
   0.01,
   0.016,
   0.01,
   0.029,
   0.02,
   0.03,
   0.02,
   0.06,
   0.03,
   0.05,
   0.09,
       0.07,
   0.11};
   gre = new TGraphErrors(13,GraphppSyst_fx1010,GraphppSyst_fy1010,GraphppSyst_fex1010,GraphppSyst_fey1010);
   gre->SetName("GraphppSyst");
   gre->SetTitle("GraphppSyst");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(1);
   gre->SetLineWidth(2);
   gre->SetMarkerColor(1);
   gre->SetMarkerStyle(34);
   gre->SetMarkerSize(1.7);
   
   TH1F *Graph_Graph_GraphppSyst10101010 = new TH1F("Graph_Graph_GraphppSyst10101010","GraphppSyst",100,0,3.417633);
   Graph_Graph_GraphppSyst10101010->SetMinimum(0.2186);
   Graph_Graph_GraphppSyst10101010->SetMaximum(3.0674);
   Graph_Graph_GraphppSyst10101010->SetDirectory(0);
   Graph_Graph_GraphppSyst10101010->SetStats(0);

   ci = TColor::GetColor("#000000");
   Graph_Graph_GraphppSyst10101010->SetLineColor(ci);
   Graph_Graph_GraphppSyst10101010->GetXaxis()->SetLabelFont(42);
   Graph_Graph_GraphppSyst10101010->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_GraphppSyst10101010->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_GraphppSyst10101010->GetXaxis()->SetTitleFont(42);
   Graph_Graph_GraphppSyst10101010->GetYaxis()->SetLabelFont(42);
   Graph_Graph_GraphppSyst10101010->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_GraphppSyst10101010->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_GraphppSyst10101010->GetYaxis()->SetTitleFont(42);
   Graph_Graph_GraphppSyst10101010->GetZaxis()->SetLabelFont(42);
   Graph_Graph_GraphppSyst10101010->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_GraphppSyst10101010->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_GraphppSyst10101010->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_GraphppSyst10101010);
   
   gre->Draw("[]");
   
   //TLegend *leg = new TLegend(0.2,0.69,0.46,0.94,NULL,"brNDC");
   TLegend *leg = new TLegend(0.2,0.63,0.46,0.88,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.04);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(2);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("GraphStat","p-Pb 5.02 TeV (0-20%)","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(25);
   entry->SetMarkerSize(1.5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","p-Pb 5.02 TeV (0-100%)","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(27);
   entry->SetMarkerSize(2.3);
   entry->SetTextFont(42);
   entry=leg->AddEntry("GraphppStat","pp 7 TeV (INEL)","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(34);
   entry->SetMarkerSize(1.7);
   entry->SetTextFont(42);
   leg->Draw();
   TLatex *   tex = new TLatex(0.09,0.2,"#pi^{#pm}");
   tex->SetTextFont(42);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   //tex->SetTextColor(kGray+2);
   tex->Draw();
      tex = new TLatex(0.3427515,0.2,"K^{#pm}");
   tex->SetTextFont(42);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
    //tex->SetTextColor(kGray+2);
   tex->Draw();
      tex = new TLatex(0.527614,0.2,"K^{0}_{S}");
   tex->SetTextFont(42);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
    //tex->SetTextColor(kGray+2);
   tex->Draw();
      tex = new TLatex(0.79,0.2,"K*^{0}");
   tex->SetTextFont(42);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
    //tex->SetTextColor(kGray+2);
   tex->Draw();
      tex = new TLatex(0.91,0.5,"p");
   tex->SetTextFont(42);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
    //tex->SetTextColor(kGray+2);
   tex->Draw();
      tex = new TLatex(1.08,0.5,"#Lambda");
   tex->SetTextFont(42);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
    //tex->SetTextColor(kGray+2);
   tex->Draw();
      tex = new TLatex(1.01,0.2,"#phi");
   tex->SetTextFont(42);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
    //tex->SetTextColor(kGray+2);
   tex->Draw();
      tex = new TLatex(1.27,0.5,"#Xi^{-}");
   tex->SetTextFont(42);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
    //tex->SetTextColor(kGray+2);
   tex->Draw();
      tex = new TLatex(1.31,0.2,"#Sigma*^{#pm}");
   tex->SetTextFont(42);
   tex->SetTextSize(0.04);
   //tex->SetTextColor(kRed);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(1.54,0.2,"#Xi*^{0}");
   tex->SetTextFont(42);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   //tex->SetTextColor(kBlue);
   tex->Draw();
      tex = new TLatex(1.69,0.5,"#Omega^{-}");
   tex->SetTextFont(42);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
    //tex->SetTextColor(kGray+2);
   tex->Draw();
    
    tex = new TLatex(1.9,0.5,"D^{0}");
    tex->SetTextFont(42);
    tex->SetTextSize(0.04);
    tex->SetLineWidth(2);
    //tex->SetTextColor(kGray+2);
    tex->Draw();
    
      tex = new TLatex(2.97,0.5,"J/#psi");
   tex->SetTextFont(42);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
    //tex->SetTextColor(kGray+2);
   tex->Draw();
    
    
   
   //TPaveText *pt = new TPaveText(0.15,0.64,0.41,0.67,"brNDC");
   TPaveText *pt = new TPaveText(0.15,0.59,0.41,0.61,"brNDC");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetLineWidth(2);
   pt->SetTextFont(42);
   pt->SetTextSize(0.045);
   Text = pt->AddText("ALICE");
   pt->Draw();

   //legend
   Double_t GraphSigmaStarxLegend[1] = {0.27};
   Double_t GraphSigmaStaryLegend[1] = {3.32};
   Double_t GraphSigmaStarexLegend[1] = {0.03};
   Double_t GraphSigmaStareyLegend[1] = {0.012};
   gre = new TGraphErrors(1,GraphSigmaStarxLegend,GraphSigmaStaryLegend,GraphSigmaStarexLegend,GraphSigmaStareyLegend);
   gre->SetName("GraphSigmaStarLegend");
   gre->SetTitle("GraphSigmaStarLegend");
   gre->SetFillColor(1);
   gre->SetLineColor(2);
   gre->SetLineWidth(2);
   gre->SetMarkerColor(2);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(1.5);
   gre->Draw("pz");
   Double_t GraphXiStarxLegend[1] = {0.61};
   Double_t GraphXiStaryLegend[1] = {3.32};
   Double_t GraphXiStarexLegend[1] = {0.03};
   Double_t GraphXiStareyLegend[1] = {0.012};
   gre = new TGraphErrors(1,GraphXiStarxLegend,GraphXiStaryLegend,GraphXiStarexLegend,GraphXiStareyLegend);
   gre->SetName("GraphXiStarLegend");
   gre->SetTitle("GraphXiStarLegend");
   gre->SetFillColor(1);
   gre->SetLineColor(4);
   gre->SetLineWidth(2);
   gre->SetMarkerColor(4);
   gre->SetMarkerStyle(21);
   gre->SetMarkerSize(1.5);
   gre->Draw("pz");
   //TPaveText *pt = new TPaveText(0.15,0.64,0.41,0.67,"brNDC");
   TPaveText *pt = new TPaveText(0.33,0.88,0.60,0.94,"brNDC");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetLineWidth(2);
   pt->SetTextFont(42);
   pt->SetTextSize(0.045);
   Text = pt->AddText("#Sigma*^{#pm}    #Xi*^{0} p-Pb 5.02 TeV (0-20%)");
//    Text = pt->AddText("results in this analysis");

   pt->Draw();
   //


   p2->Modified();
   c->cd();
   c->Modified();
   c->cd();
   c->SetSelected(c);
   c->ToggleToolBar();
    c->SaveAs("PAPER_FIGURE6.gif");
    c->SaveAs("PAPER_FIGURE6.eps");
}
