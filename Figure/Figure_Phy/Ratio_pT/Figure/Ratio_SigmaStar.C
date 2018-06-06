{
//=========Macro generated from canvas: c1_n2/c1_n2
//=========  (Thu Apr 19 12:35:08 2018) by ROOT version5.34/30
   TCanvas *c1_n2 = new TCanvas("c1_n2", "c1_n2",332,634,700,502);
   c1_n2->Range(-1,-0.1,9,0.9);
   c1_n2->SetFillColor(0);
   c1_n2->SetBorderMode(0);
   c1_n2->SetBorderSize(2);
   c1_n2->SetFrameBorderMode(0);
   c1_n2->SetFrameBorderMode(0);
   Double_t xAxis1[10] = {0, 1.1, 1.6, 2, 2.4, 2.8, 3.4, 4, 5, 8}; 
   
   TH1D *Spectrum_stat = new TH1D("Spectrum_stat","",9, xAxis1);
   Spectrum_stat->SetBinContent(2,0.41073);
   Spectrum_stat->SetBinContent(3,0.4149452);
   Spectrum_stat->SetBinContent(4,0.455086);
   Spectrum_stat->SetBinContent(5,0.4055917);
   Spectrum_stat->SetBinContent(6,0.3447339);
   Spectrum_stat->SetBinContent(7,0.332046);
   Spectrum_stat->SetBinContent(8,0.2442244);
   Spectrum_stat->SetBinContent(9,0.1171813);
   Spectrum_stat->SetBinError(2,0.06431802);
   Spectrum_stat->SetBinError(3,0.04549414);
   Spectrum_stat->SetBinError(4,0.0561047);
   Spectrum_stat->SetBinError(5,0.04125349);
   Spectrum_stat->SetBinError(6,0.02767039);
   Spectrum_stat->SetBinError(7,0.03170513);
   Spectrum_stat->SetBinError(8,0.02383521);
   Spectrum_stat->SetBinError(9,0.01381502);
   Spectrum_stat->SetMinimum(0);
   Spectrum_stat->SetMaximum(0.8);
   Spectrum_stat->SetEntries(546.3814);
   
   TPaveStats *ptstats = new TPaveStats(0.6666667,0.6976744,0.8678161,0.858351,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetLineColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextColor(0);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("Spectrum_stat");
   text->SetTextSize(0.0369556);
   text = ptstats->AddText("Entries = 546    ");
   text = ptstats->AddText("Mean  =  2.758");
   text = ptstats->AddText("RMS   =  1.221");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   Spectrum_stat->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(Spectrum_stat);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#990099");
   Spectrum_stat->SetLineColor(ci);

   ci = TColor::GetColor("#cc00ff");
   Spectrum_stat->SetMarkerColor(ci);
   Spectrum_stat->SetMarkerStyle(20);
   Spectrum_stat->GetXaxis()->SetTitle("#it{p}_{T}");
   Spectrum_stat->GetXaxis()->SetLabelFont(42);
   Spectrum_stat->GetXaxis()->SetLabelSize(0.035);
   Spectrum_stat->GetXaxis()->SetTitleSize(0.05);
   Spectrum_stat->GetXaxis()->SetTitleOffset(0.87);
   Spectrum_stat->GetXaxis()->SetTitleFont(42);
   Spectrum_stat->GetYaxis()->SetTitle("#Sigma(1385)^{#pm} / #Sigma^{0}");
   Spectrum_stat->GetYaxis()->SetRange(1,1);
   Spectrum_stat->GetYaxis()->SetLabelFont(42);
   Spectrum_stat->GetYaxis()->SetLabelSize(0.035);
   Spectrum_stat->GetYaxis()->SetTitleSize(0.05);
   Spectrum_stat->GetYaxis()->SetTitleOffset(0.94);
   Spectrum_stat->GetYaxis()->SetTitleFont(42);
   Spectrum_stat->GetZaxis()->SetLabelFont(42);
   Spectrum_stat->GetZaxis()->SetLabelSize(0.035);
   Spectrum_stat->GetZaxis()->SetTitleSize(0.035);
   Spectrum_stat->GetZaxis()->SetTitleFont(42);
   Spectrum_stat->Draw("");
   c1_n2->Modified();
   c1_n2->cd();
   c1_n2->SetSelected(c1_n2);
}
