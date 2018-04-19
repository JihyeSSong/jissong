{
//=========Macro generated from canvas: Canvas_1/Canvas_1
//=========  (Thu Apr 19 11:27:33 2018) by ROOT version5.34/30
   TCanvas *Canvas_1 = new TCanvas("Canvas_1", "Canvas_1",1515,94,536,324);
   Canvas_1->Range(-1,-0.001624609,9,0.01462148);
   Canvas_1->SetFillColor(0);
   Canvas_1->SetBorderMode(0);
   Canvas_1->SetBorderSize(2);
   Canvas_1->SetFrameBorderMode(0);
   Canvas_1->SetFrameBorderMode(0);
   Double_t xAxis1[10] = {0, 1.1, 1.6, 2, 2.4, 2.8, 3.4, 4, 5, 8}; 
   
   TH1D *h_spectrum = new TH1D("h_spectrum","pp #sqrt{s}= 7 TeV",9, xAxis1);
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
   h_spectrum->SetEntries(16);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.655,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("h_spectrum");
   text->SetTextSize(0.06439999);
   text = ptstats->AddText("Entries = 16     ");
   text = ptstats->AddText("Mean  =  1.827");
   text = ptstats->AddText("RMS   = 0.6363");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(1111);
   ptstats->Draw();
   h_spectrum->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(h_spectrum);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
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
   h_spectrum->Draw("");
   
   TPaveText *pt = new TPaveText(0.4016541,0.93125,0.5983459,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("pp #sqrt{s}= 7 TeV");
   pt->Draw();
   Canvas_1->Modified();
   Canvas_1->cd();
   Canvas_1->SetSelected(Canvas_1);
}
