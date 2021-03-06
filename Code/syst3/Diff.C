{
//=========Macro generated from canvas: Diff_tot/Sigma0 diff
//=========  (Fri Oct  3 11:58:10 2014) by ROOT version5.34/18
   TCanvas *Diff_tot = new TCanvas("Diff_tot", "Sigma0 diff",0,44,800,674);
   Diff_tot->Range(-1.25,-0.0625,11.25,0.5625);
   Diff_tot->SetFillColor(0);
   Diff_tot->SetBorderMode(0);
   Diff_tot->SetBorderSize(2);
   Diff_tot->SetFrameBorderMode(0);
   Diff_tot->SetFrameBorderMode(0);
   Double_t xAxis1[10] = {0, 1, 1.5, 2, 2.4, 2.8, 3.2, 4, 6, 10}; 
   
   TH1D *hdiff = new TH1D("hdiff","Uncertainty",9, xAxis1);
   hdiff->SetBinContent(2,0.1259505);
   hdiff->SetBinContent(3,0.1415134);
   hdiff->SetBinContent(4,0.009678377);
   hdiff->SetBinContent(5,0.05851749);
   hdiff->SetBinContent(6,0.1044407);
   hdiff->SetBinContent(8,0.06637384);
   hdiff->SetBinContent(9,0.2690315);
   hdiff->SetBinError(2,0.02326498);
   hdiff->SetBinError(3,0.01475514);
   hdiff->SetBinError(4,0.002932228);
   hdiff->SetBinError(5,0.007145054);
   hdiff->SetBinError(6,0.01066076);
   hdiff->SetBinError(8,0.00825139);
   hdiff->SetBinError(9,0.04243793);
   hdiff->SetMinimum(0);
   hdiff->SetMaximum(0.5);
   hdiff->SetEntries(8);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("hdiff");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 8      ");
   text = ptstats->AddText("Mean  =  4.353");
   text = ptstats->AddText("RMS   =  2.826");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   hdiff->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(hdiff);
   hdiff->SetLineColor(2);
   hdiff->SetLineWidth(2);
   hdiff->GetXaxis()->SetLabelFont(42);
   hdiff->GetXaxis()->SetLabelSize(0.035);
   hdiff->GetXaxis()->SetTitleSize(0.035);
   hdiff->GetXaxis()->SetTitleFont(42);
   hdiff->GetYaxis()->SetLabelFont(42);
   hdiff->GetYaxis()->SetLabelSize(0.035);
   hdiff->GetYaxis()->SetTitleSize(0.035);
   hdiff->GetYaxis()->SetTitleFont(42);
   hdiff->GetZaxis()->SetLabelFont(42);
   hdiff->GetZaxis()->SetLabelSize(0.035);
   hdiff->GetZaxis()->SetTitleSize(0.035);
   hdiff->GetZaxis()->SetTitleFont(42);
   hdiff->Draw("E");
   Double_t xAxis2[10] = {0, 1, 1.5, 2, 2.4, 2.8, 3.2, 4, 6, 10}; 
   
   TH1D *hdiff1 = new TH1D("hdiff1","Pol3 - mix",9, xAxis2);
   hdiff1->SetBinContent(2,0.1297672);
   hdiff1->SetBinContent(3,0.3126772);
   hdiff1->SetBinContent(4,0.09942332);
   hdiff1->SetBinContent(5,0.05934168);
   hdiff1->SetBinContent(6,0.1044407);
   hdiff1->SetBinContent(8,0.06733578);
   hdiff1->SetBinContent(9,0.07912691);
   hdiff1->SetBinError(2,0.02365484);
   hdiff1->SetBinError(3,0.02351967);
   hdiff1->SetBinError(4,0.009806895);
   hdiff1->SetBinError(5,0.007197996);
   hdiff1->SetBinError(6,0.01066076);
   hdiff1->SetBinError(8,0.008314716);
   hdiff1->SetBinError(9,0.02122339);
   hdiff1->SetMinimum(0);
   hdiff1->SetMaximum(0.5);
   hdiff1->SetEntries(8);
   hdiff1->SetLineColor(3);
   hdiff1->SetLineWidth(2);
   hdiff1->GetXaxis()->SetLabelFont(42);
   hdiff1->GetXaxis()->SetLabelSize(0.035);
   hdiff1->GetXaxis()->SetTitleSize(0.035);
   hdiff1->GetXaxis()->SetTitleFont(42);
   hdiff1->GetYaxis()->SetLabelFont(42);
   hdiff1->GetYaxis()->SetLabelSize(0.035);
   hdiff1->GetYaxis()->SetTitleSize(0.035);
   hdiff1->GetYaxis()->SetTitleFont(42);
   hdiff1->GetZaxis()->SetLabelFont(42);
   hdiff1->GetZaxis()->SetLabelSize(0.035);
   hdiff1->GetZaxis()->SetTitleSize(0.035);
   hdiff1->GetZaxis()->SetTitleFont(42);
   hdiff1->Draw("Esame");
   Double_t xAxis3[10] = {0, 1, 1.5, 2, 2.4, 2.8, 3.2, 4, 6, 10}; 
   
   TH1D *hdiff2 = new TH1D("hdiff2","Pol4 - mix",9, xAxis3);
   hdiff2->SetBinContent(2,0.2213676);
   hdiff2->SetBinContent(3,0.3194159);
   hdiff2->SetBinContent(4,0.09854347);
   hdiff2->SetBinContent(5,0.06181425);
   hdiff2->SetBinContent(6,0.1064113);
   hdiff2->SetBinContent(7,0.00174507);
   hdiff2->SetBinContent(8,0.06348802);
   hdiff2->SetBinContent(9,0.07385178);
   hdiff2->SetBinError(2,0.03212353);
   hdiff2->SetBinError(3,0.0238327);
   hdiff2->SetBinError(4,0.009759498);
   hdiff2->SetBinError(5,0.007354992);
   hdiff2->SetBinError(6,0.01077046);
   hdiff2->SetBinError(7,0.001235027);
   hdiff2->SetBinError(8,0.008059092);
   hdiff2->SetBinError(9,0.02045357);
   hdiff2->SetMinimum(0);
   hdiff2->SetMaximum(0.5);
   hdiff2->SetEntries(8);
   hdiff2->SetLineColor(4);
   hdiff2->SetLineWidth(2);
   hdiff2->GetXaxis()->SetLabelFont(42);
   hdiff2->GetXaxis()->SetLabelSize(0.035);
   hdiff2->GetXaxis()->SetTitleSize(0.035);
   hdiff2->GetXaxis()->SetTitleFont(42);
   hdiff2->GetYaxis()->SetLabelFont(42);
   hdiff2->GetYaxis()->SetLabelSize(0.035);
   hdiff2->GetYaxis()->SetTitleSize(0.035);
   hdiff2->GetYaxis()->SetTitleFont(42);
   hdiff2->GetZaxis()->SetLabelFont(42);
   hdiff2->GetZaxis()->SetLabelSize(0.035);
   hdiff2->GetZaxis()->SetTitleSize(0.035);
   hdiff2->GetZaxis()->SetTitleFont(42);
   hdiff2->Draw("Esame");
   
   TLegend *leg = new TLegend(0.78,0.6,0.98,0.75,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(19);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("hdiff","Pol2 - mix","lpf");
   entry->SetFillStyle(1001);
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("hdiff1","Pol3 - mix","lpf");
   entry->SetFillStyle(1001);
   entry->SetLineColor(3);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("hdiff2","Pol4 - mix","lpf");
   entry->SetFillStyle(1001);
   entry->SetLineColor(4);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TPaveText *pt = new TPaveText(0.3863568,0.9282303,0.6136432,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("Pol2 - mix");
   pt->Draw();
   Diff_tot->Modified();
   Diff_tot->cd();
   Diff_tot->SetSelected(Diff_tot);
}
