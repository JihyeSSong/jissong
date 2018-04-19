//
void RunRebin(){
    
    int Cent = 2; //0:010 , 1:1040, 2:4080
    
    TFile* f=TFile::Open("PbPb276.fullpT.INEL.20140329.root");
    
    if(Cent==0){
    TH1D* hpion_stat0 = (TH1D*)f->Get("hstat_PbPb276_0005_pion_sum");
    TH1D* hpion_stat1 = (TH1D*)f->Get("hstat_PbPb276_0510_pion_sum");
    hpion_stat0->Add(hpion_stat1);
    hpion_stat0->Scale(0.25);
    
    TH1D* hpion_sys0 = (TH1D*)f->Get("hsys_PbPb276_0005_pion_sum");
    TH1D* hpion_sys1 = (TH1D*)f->Get("hsys_PbPb276_0510_pion_sum");
    hpion_sys0->Add(hpion_sys1);
    hpion_sys0->Scale(0.25);
    }
    else if(Cent==1){
        TH1D* hpion_stat0 = (TH1D*)f->Get("hstat_PbPb276_1020_pion_sum");
        TH1D* hpion_stat1 = (TH1D*)f->Get("hstat_PbPb276_2040_pion_sum");
        hpion_stat1->Scale(2.);
        hpion_stat0->Add(hpion_stat1);
        hpion_stat0->Scale(1./6.);
        
        TH1D* hpion_sys0 = (TH1D*)f->Get("hsys_PbPb276_1020_pion_sum");
        TH1D* hpion_sys1 = (TH1D*)f->Get("hsys_PbPb276_2040_pion_sum");
        hpion_sys1->Scale(2.);
        hpion_sys0->Add(hpion_sys1);
        hpion_sys0->Scale(1./6.);
        
    }
    else if(Cent==2){
        TH1D* hpion_stat0 = (TH1D*)f->Get("hstat_PbPb276_4060_pion_sum");
        TH1D* hpion_stat1 = (TH1D*)f->Get("hstat_PbPb276_6080_pion_sum");
        hpion_stat0->Add(hpion_stat1);
        hpion_stat0->Scale(0.25);
        
        TH1D* hpion_sys0 = (TH1D*)f->Get("hsys_PbPb276_4060_pion_sum");
        TH1D* hpion_sys1 = (TH1D*)f->Get("hsys_PbPb276_6080_pion_sum");
        hpion_sys0->Add(hpion_sys1);
        hpion_sys0->Scale(0.25);
    }
    
    TH1F* hi[1];
    hi[0] = (TH1F*)hpion_stat0->Clone("hi[0]");
    hi[1] = (TH1F*)hpion_sys0->Clone("hi[1]");

    int n=2;
    int dofit=1;
//    int bin=7;
//    double bins[8]={1.2,2.0,2.5,3.0,3.5,4.0,5.0,6.0};

    int bin=10;
    double bins[11]={1.2,1.9,2.5,3.0,3.5,4.0,4.4, 4.9, 5.4, 6.0};


    TH1F* ht=(TH1F*) hi[0]->Clone("ht");
    for(int j=1;j<=ht->GetNbinsX();j++) ht->SetBinError(j,sqrt(pow(hi[0]->GetBinError(j),2)+pow(hi[1]->GetBinError(j),2)));
        
    TH1F* hf[1];
    hf[0] = new TH1F("rebinned_stat","",bin,bins);
    hf[1] = new TH1F("rebinned_sys","",bin,bins);

    TF1* g=new TF1("fit","[0]*exp([1]*x)",0.,10.);
    g->SetParameters(1.,-1.);
    gROOT->LoadMacro("RebinSpectrum.C");
    RebinSpectrum(hi,hf,g,n,dofit,ht);
    
    Double_t xAxis1[11] = {0,1.2,1.9,2.5,3.0,3.5,4.0,4.4, 4.9, 5.4, 6.0};
    TH1D *Pion_stat = new TH1D("Pion_stat","",10, xAxis1);
    TH1D *Pion_sys = new TH1D("Pion_sys","",10, xAxis1);

    for(int k=2; k<12; k++){
        Pion_stat->SetBinContent(k,hf[0]->GetBinContent(k-1));
        Pion_stat->SetBinError(k,hf[0]->GetBinError(k-1));
        
        Pion_sys->SetBinContent(k,hf[1]->GetBinContent(k-1));
        Pion_sys->SetBinError(k,hf[1]->GetBinError(k-1));


    }

    TFile *fileout = TFile::Open(Form("Pion_rebin%d.root",Cent),"RECREATE");
    hi[0]->Write("stat");
    hi[1]->Write("sys");
    hf[0]->Write("rebinned_stat");
    hf[1]->Write("rebinned_sys");
    Pion_stat->Write("Pion_stat");
    Pion_sys->Write("Pion_sys");
    fileout->Close();


    
    
}


