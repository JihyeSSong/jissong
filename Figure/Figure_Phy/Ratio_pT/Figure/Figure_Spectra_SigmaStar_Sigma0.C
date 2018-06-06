{
//=========Macro generated from canvas: c1/c1
//=========  (Thu Apr 19 12:37:03 2018) by ROOT version5.34/30
   TCanvas *c1 = new TCanvas("c1", "c1",483,199,700,500);
   c1->Range(-1,-6.646256,9,-0.8635528);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetLogy();
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   Double_t xAxis1[10] = {0, 1.1, 1.6, 2, 2.4, 2.8, 3.4, 4, 5, 8}; 
   
   TH1D *Spectrum_stat = new TH1D("Spectrum_stat","",9, xAxis1);
   Spectrum_stat->SetBinContent(2,0.004398036);
   Spectrum_stat->SetBinContent(3,0.002475);
   Spectrum_stat->SetBinContent(4,0.0013);
   Spectrum_stat->SetBinContent(5,0.0007226646);
   Spectrum_stat->SetBinContent(6,0.0003469246);
   Spectrum_stat->SetBinContent(7,0.0001504656);
   Spectrum_stat->SetBinContent(8,4.773436e-05);
   Spectrum_stat->SetBinContent(9,4.255215e-06);
   Spectrum_stat->SetBinError(2,6.136128e-05);
   Spectrum_stat->SetBinError(3,4.063942e-05);
   Spectrum_stat->SetBinError(4,2.136001e-05);
   Spectrum_stat->SetBinError(5,1.133592e-05);
   Spectrum_stat->SetBinError(6,4.030219e-06);
   Spectrum_stat->SetBinError(7,2.522634e-06);
   Spectrum_stat->SetBinError(8,1.422386e-06);
   Spectrum_stat->SetBinError(9,1.267967e-07);
   Spectrum_stat->SetMinimum(8.550955e-07);
   Spectrum_stat->SetMaximum(0.03615571);
   Spectrum_stat->SetEntries(9);
   
   TPaveStats *ptstats = new TPaveStats(0.637931,0.6490486,0.8390805,0.8097252,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetLineColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextColor(0);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("Spectrum_stat");
   text->SetTextSize(0.0369556);
   text = ptstats->AddText("Entries = 9      ");
   text = ptstats->AddText("Mean  =  1.801");
   text = ptstats->AddText("RMS   = 0.5759");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   Spectrum_stat->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(Spectrum_stat);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#cc00ff");
   Spectrum_stat->SetLineColor(ci);

   ci = TColor::GetColor("#cc00ff");
   Spectrum_stat->SetMarkerColor(ci);
   Spectrum_stat->SetMarkerStyle(22);
   Spectrum_stat->GetXaxis()->SetLabelFont(42);
   Spectrum_stat->GetXaxis()->SetLabelSize(0.035);
   Spectrum_stat->GetXaxis()->SetTitleSize(0.035);
   Spectrum_stat->GetXaxis()->SetTitleFont(42);
   Spectrum_stat->GetYaxis()->SetLabelFont(42);
   Spectrum_stat->GetYaxis()->SetLabelSize(0.035);
   Spectrum_stat->GetYaxis()->SetTitleSize(0.035);
   Spectrum_stat->GetYaxis()->SetTitleFont(42);
   Spectrum_stat->GetZaxis()->SetLabelFont(42);
   Spectrum_stat->GetZaxis()->SetLabelSize(0.035);
   Spectrum_stat->GetZaxis()->SetTitleSize(0.035);
   Spectrum_stat->GetZaxis()->SetTitleFont(42);
   Spectrum_stat->Draw("");
   Double_t xAxis2[10] = {0, 1.1, 1.6, 2, 2.4, 2.8, 3.4, 4, 5, 8}; 
   
   TH1D *h_spectrum = new TH1D("h_spectrum","pp #sqrt{s}= 7 TeV",9, xAxis2);
   h_spectrum->SetBinContent(2,0.01070785);
   h_spectrum->SetBinContent(3,0.005964643);
   h_spectrum->SetBinContent(4,0.002856603);
   h_spectrum->SetBinContent(5,0.001781754);
   h_spectrum->SetBinContent(6,0.001006355);
   h_spectrum->SetBinContent(7,0.0004531467);
   h_spectrum->SetBinContent(8,0.0001954529);
   h_spectrum->SetBinContent(9,3.631308e-05);
   h_spectrum->SetBinError(2,0.001670121);
   h_spectrum->SetBinError(3,0.0006465814);
   h_spectrum->SetBinError(4,0.0003490309);
   h_spectrum->SetBinError(5,0.0001790574);
   h_spectrum->SetBinError(6,7.99255e-05);
   h_spectrum->SetBinError(7,4.259613e-05);
   h_spectrum->SetBinError(8,1.816447e-05);
   h_spectrum->SetBinError(9,4.142105e-06);
   h_spectrum->SetMinimum(8.550955e-07);
   h_spectrum->SetMaximum(0.03615571);
   h_spectrum->SetEntries(16);
   
   ptstats = new TPaveStats(0.6350575,0.5687104,0.8362069,0.8498943,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetLineColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextColor(0);
   ptstats->SetTextFont(42);
   text = ptstats->AddText("h_spectrum");
   text->SetTextSize(0.06467231);
   text = ptstats->AddText("Entries = 16     ");
   text = ptstats->AddText("Mean  =  1.827");
   text = ptstats->AddText("RMS   = 0.6363");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(1111);
   ptstats->Draw();
   h_spectrum->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(h_spectrum);

   ci = TColor::GetColor("#ff0000");
   h_spectrum->SetLineColor(ci);

   ci = TColor::GetColor("#ff0000");
   h_spectrum->SetMarkerColor(ci);
   h_spectrum->SetMarkerStyle(21);
   h_spectrum->SetMarkerSize(0.5);
   h_spectrum->GetXaxis()->SetTitle("p_{T} (GeV/c)");
   h_spectrum->GetXaxis()->SetLabelFont(42);
   h_spectrum->GetXaxis()->SetLabelSize(0.035);
   h_spectrum->GetXaxis()->SetTitleSize(0.035);
   h_spectrum->GetXaxis()->SetTitleFont(42);
   h_spectrum->GetYaxis()->SetTitle("1/N_{E}d^{2}N/dydp_{T} (GeV/c)^{-1}");
   h_spectrum->GetYaxis()->SetLabelFont(42);
   h_spectrum->GetYaxis()->SetLabelSize(0.035);
   h_spectrum->GetYaxis()->SetTitleSize(0.035);
   h_spectrum->GetYaxis()->SetTitleFont(42);
   h_spectrum->GetZaxis()->SetLabelFont(42);
   h_spectrum->GetZaxis()->SetLabelSize(0.035);
   h_spectrum->GetZaxis()->SetTitleSize(0.035);
   h_spectrum->GetZaxis()->SetTitleFont(42);
   h_spectrum->Draw("same");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
