void Light_Spectra(){
    
    
    double pTbins_pion[42] = {0.10,    0.12 ,    0.14 ,    0.16 ,    0.18 ,    0.20 ,    0.25 ,    0.30 ,    0.35 ,    0.40 ,    0.45 ,    0.50 ,    0.55 ,    0.60 ,    0.65 ,    0.70 ,    0.75 ,    0.80  , 0.85 , 0.90 ,0.95 ,1.00 ,1.10 ,1.20 ,1.30 ,1.40 ,1.50 ,1.60 ,1.70 ,1.80 ,1.90 ,2.00 ,2.10 ,2.20 ,2.30 ,2.40 ,2.50 ,2.60 ,2.70 ,2.80 ,    2.90 ,3.00};
    
    double pTbins_proton[47] = {0.30 ,    0.35 ,    0.40 ,    0.45 ,    0.50 ,    0.55 ,    0.60 ,    0.65 ,    0.70 ,    0.75 ,    0.80   ,
        0.85 , 0.90 ,0.95 ,1.00 ,1.10 ,1.20 ,1.30 ,1.40 ,1.50 ,1.60 ,1.70 ,1.80 ,1.90 ,2.00 ,2.10 ,2.20 ,2.30 ,2.40 ,2.50 ,2.60 ,2.70 ,2.80 ,    2.90 ,3.00 ,3.20 ,3.40 ,3.60 ,3.80 ,4.00 ,4.20 ,4.40 ,    4.60 ,4.80 ,5.00,5.50,6.00};
    
    
    TH1D *Pion_AantiPion_stat = new TH1D("Pion_AantiPion_stat","Pion_AantiPion_stat", 41, pTbins_pion);
    
    
    Pion_AantiPion_stat->SetBinContent(1, 8.0414);
    Pion_AantiPion_stat->SetBinContent(2, 8.4742);
    Pion_AantiPion_stat->SetBinContent(3, 8.8227);
    Pion_AantiPion_stat->SetBinContent(4, 8.7642);
    Pion_AantiPion_stat->SetBinContent(5, 8.7028);
    Pion_AantiPion_stat->SetBinContent(6, 8.1833);
    Pion_AantiPion_stat->SetBinContent(7, 7.3833);
    Pion_AantiPion_stat->SetBinContent(8, 6.4552);
    Pion_AantiPion_stat->SetBinContent(9, 5.5804);
    Pion_AantiPion_stat->SetBinContent(10, 4.7945);
    Pion_AantiPion_stat->SetBinContent(11, 4.0869);
    Pion_AantiPion_stat->SetBinContent(12, 3.4942);
    Pion_AantiPion_stat->SetBinContent(13, 2.9838);
    Pion_AantiPion_stat->SetBinContent(14, 2.6681);
    Pion_AantiPion_stat->SetBinContent(15, 2.2817);
    Pion_AantiPion_stat->SetBinContent(16, 1.9632);
    Pion_AantiPion_stat->SetBinContent(17, 1.6974);
    Pion_AantiPion_stat->SetBinContent(18, 1.4669);
    Pion_AantiPion_stat->SetBinContent(19, 1.2771);
    Pion_AantiPion_stat->SetBinContent(20, 1.1125);
    Pion_AantiPion_stat->SetBinContent(21, 0.9742);
    Pion_AantiPion_stat->SetBinContent(22, 0.7969);
    Pion_AantiPion_stat->SetBinContent(23, 0.619);
    Pion_AantiPion_stat->SetBinContent(24, 0.4859);
    Pion_AantiPion_stat->SetBinContent(25, 0.38487);
    Pion_AantiPion_stat->SetBinContent(26, 0.30772);
    Pion_AantiPion_stat->SetBinContent(27, 0.24648);
    Pion_AantiPion_stat->SetBinContent(28, 0.19993);
    Pion_AantiPion_stat->SetBinContent(29, 0.16261);
    Pion_AantiPion_stat->SetBinContent(30, 0.13309);
    Pion_AantiPion_stat->SetBinContent(31, 0.10937);
    Pion_AantiPion_stat->SetBinContent(32, 0.09054);
    Pion_AantiPion_stat->SetBinContent(33, 0.07512);
    Pion_AantiPion_stat->SetBinContent(34, 0.06281);
    Pion_AantiPion_stat->SetBinContent(35, 0.05299);
    Pion_AantiPion_stat->SetBinContent(36, 0.04512);
    Pion_AantiPion_stat->SetBinContent(37, 0.03758);
    Pion_AantiPion_stat->SetBinContent(38, 0.0318);
    Pion_AantiPion_stat->SetBinContent(39, 0.02706);
    Pion_AantiPion_stat->SetBinContent(40, 0.024);
    Pion_AantiPion_stat->SetBinContent(41, 0.02025);
    
    Pion_AantiPion_stat->SetBinError(1, 0.0062);
    Pion_AantiPion_stat->SetBinError(2, 0.0049);
    Pion_AantiPion_stat->SetBinError(3, 0.0047);
    Pion_AantiPion_stat->SetBinError(4, 0.0045);
    Pion_AantiPion_stat->SetBinError(5, 0.0043);
    Pion_AantiPion_stat->SetBinError(6, 0.0025);
    Pion_AantiPion_stat->SetBinError(7, 0.0025);
    Pion_AantiPion_stat->SetBinError(8, 0.0022);
    Pion_AantiPion_stat->SetBinError(9, 0.0020);
    Pion_AantiPion_stat->SetBinError(10, 0.0018);
    Pion_AantiPion_stat->SetBinError(11, 0.0017);
    Pion_AantiPion_stat->SetBinError(12, 0.0016);
    Pion_AantiPion_stat->SetBinError(13, 0.0015);
    Pion_AantiPion_stat->SetBinError(14, 0.0031);
    Pion_AantiPion_stat->SetBinError(15, 0.0030);
    Pion_AantiPion_stat->SetBinError(16, 0.0028);
    Pion_AantiPion_stat->SetBinError(17, 0.0024);
    Pion_AantiPion_stat->SetBinError(18, 0.0025);
    Pion_AantiPion_stat->SetBinError(19, 0.0023);
    Pion_AantiPion_stat->SetBinError(20, 0.0022);
    Pion_AantiPion_stat->SetBinError(21, 0.0021);
    Pion_AantiPion_stat->SetBinError(22, 0.0013);
    Pion_AantiPion_stat->SetBinError(23, 0.0011);
    Pion_AantiPion_stat->SetBinError(24, 0.0010);
    Pion_AantiPion_stat->SetBinError(25, 0.00091);
    Pion_AantiPion_stat->SetBinError(26, 0.00081);
    Pion_AantiPion_stat->SetBinError(27, 0.00066);
    Pion_AantiPion_stat->SetBinError(28, 0.00058);
    Pion_AantiPion_stat->SetBinError(29, 0.00051);
    Pion_AantiPion_stat->SetBinError(30, 0.00045);
    Pion_AantiPion_stat->SetBinError(31, 0.00040);
    Pion_AantiPion_stat->SetBinError(32, 0.00035);
    Pion_AantiPion_stat->SetBinError(33, 0.00032);
    Pion_AantiPion_stat->SetBinError(34, 0.00028);
    Pion_AantiPion_stat->SetBinError(35, 0.00026);
    Pion_AantiPion_stat->SetBinError(36, 0.00023);
    Pion_AantiPion_stat->SetBinError(37, 0.00034);
    Pion_AantiPion_stat->SetBinError(38, 0.00031);
    Pion_AantiPion_stat->SetBinError(39, 0.00029);
    Pion_AantiPion_stat->SetBinError(40, 0.00027);
    Pion_AantiPion_stat->SetBinError(41, 0.00025);
    
    
    TH1D *Pion_AantiPion_sys = new TH1D("Pion_AantiPion_sys","Pion_AantiPion_sys", 41, pTbins_pion);
    
    
    Pion_AantiPion_sys->SetBinContent(1, 8.0414);
    Pion_AantiPion_sys->SetBinContent(2, 8.4742);
    Pion_AantiPion_sys->SetBinContent(3, 8.8227);
    Pion_AantiPion_sys->SetBinContent(4, 8.7642);
    Pion_AantiPion_sys->SetBinContent(5, 8.7028);
    Pion_AantiPion_sys->SetBinContent(6, 8.1833);
    Pion_AantiPion_sys->SetBinContent(7, 7.3833);
    Pion_AantiPion_sys->SetBinContent(8, 6.4552);
    Pion_AantiPion_sys->SetBinContent(9, 5.5804);
    Pion_AantiPion_sys->SetBinContent(10, 4.7945);
    Pion_AantiPion_sys->SetBinContent(11, 4.0869);
    Pion_AantiPion_sys->SetBinContent(12, 3.4942);
    Pion_AantiPion_sys->SetBinContent(13, 2.9838);
    Pion_AantiPion_sys->SetBinContent(14, 2.6681);
    Pion_AantiPion_sys->SetBinContent(15, 2.2817);
    Pion_AantiPion_sys->SetBinContent(16, 1.9632);
    Pion_AantiPion_sys->SetBinContent(17, 1.6974);
    Pion_AantiPion_sys->SetBinContent(18, 1.4669);
    Pion_AantiPion_sys->SetBinContent(19, 1.2771);
    Pion_AantiPion_sys->SetBinContent(20, 1.1125);
    Pion_AantiPion_sys->SetBinContent(21, 0.9742);
    Pion_AantiPion_sys->SetBinContent(22, 0.7969);
    Pion_AantiPion_sys->SetBinContent(23, 0.619);
    Pion_AantiPion_sys->SetBinContent(24, 0.4859);
    Pion_AantiPion_sys->SetBinContent(25, 0.38487);
    Pion_AantiPion_sys->SetBinContent(26, 0.30772);
    Pion_AantiPion_sys->SetBinContent(27, 0.24648);
    Pion_AantiPion_sys->SetBinContent(28, 0.19993);
    Pion_AantiPion_sys->SetBinContent(29, 0.16261);
    Pion_AantiPion_sys->SetBinContent(30, 0.13309);
    Pion_AantiPion_sys->SetBinContent(31, 0.10937);
    Pion_AantiPion_sys->SetBinContent(32, 0.09054);
    Pion_AantiPion_sys->SetBinContent(33, 0.07512);
    Pion_AantiPion_sys->SetBinContent(34, 0.06281);
    Pion_AantiPion_sys->SetBinContent(35, 0.05299);
    Pion_AantiPion_sys->SetBinContent(36, 0.04512);
    Pion_AantiPion_sys->SetBinContent(37, 0.03758);
    Pion_AantiPion_sys->SetBinContent(38, 0.0318);
    Pion_AantiPion_sys->SetBinContent(39, 0.02706);
    Pion_AantiPion_sys->SetBinContent(40, 0.024);
    Pion_AantiPion_sys->SetBinContent(41, 0.02025);
    
    Pion_AantiPion_sys->SetBinError(1, 0.5399);
    Pion_AantiPion_sys->SetBinError(2, 0.4077);
    Pion_AantiPion_sys->SetBinError(3, 0.4126);
    Pion_AantiPion_sys->SetBinError(4, 0.4118);
    Pion_AantiPion_sys->SetBinError(5, 0.4074);
    Pion_AantiPion_sys->SetBinError(6, 0.3822);
    Pion_AantiPion_sys->SetBinError(7, 0.2292);
    Pion_AantiPion_sys->SetBinError(8, 0.1953);
    Pion_AantiPion_sys->SetBinError(9, 0.1669);
    Pion_AantiPion_sys->SetBinError(10, 0.1424);
    Pion_AantiPion_sys->SetBinError(11, 0.1209);
    Pion_AantiPion_sys->SetBinError(12, 0.1033);
    Pion_AantiPion_sys->SetBinError(13, 0.0888);
    Pion_AantiPion_sys->SetBinError(14, 0.1296);
    Pion_AantiPion_sys->SetBinError(15, 0.1109);
    Pion_AantiPion_sys->SetBinError(16, 0.0956);
    Pion_AantiPion_sys->SetBinError(17, 0.0828);
    Pion_AantiPion_sys->SetBinError(18, 0.0715);
    Pion_AantiPion_sys->SetBinError(19, 0.0622);
    Pion_AantiPion_sys->SetBinError(20, 0.0543);
    Pion_AantiPion_sys->SetBinError(21, 0.0474);
    Pion_AantiPion_sys->SetBinError(22, 0.0389);
    Pion_AantiPion_sys->SetBinError(23, 0.0302);
    Pion_AantiPion_sys->SetBinError(24, 0.0238);
    Pion_AantiPion_sys->SetBinError(25, 0.01890);
    Pion_AantiPion_sys->SetBinError(26, 0.01519);
    Pion_AantiPion_sys->SetBinError(27, 0.01210);
    Pion_AantiPion_sys->SetBinError(28, 0.00994);
    Pion_AantiPion_sys->SetBinError(29, 0.00824);
    Pion_AantiPion_sys->SetBinError(30, 0.00692);
    Pion_AantiPion_sys->SetBinError(31, 0.00583);
    Pion_AantiPion_sys->SetBinError(32, 0.00495);
    Pion_AantiPion_sys->SetBinError(33, 0.00411);
    Pion_AantiPion_sys->SetBinError(34, 0.00354);
    Pion_AantiPion_sys->SetBinError(35, 0.00311);
    Pion_AantiPion_sys->SetBinError(36, 0.00279);
    Pion_AantiPion_sys->SetBinError(37, 0.00368);
    Pion_AantiPion_sys->SetBinError(38, 0.00308);
    Pion_AantiPion_sys->SetBinError(39, 0.00260);
    Pion_AantiPion_sys->SetBinError(40, 0.00232);
    Pion_AantiPion_sys->SetBinError(41, 0.00207);
    
    
    
    // PROTON
    
    
    TH1D *Proton_AntiProton_stat = new TH1D("Proton_AntiProton_stat","Proton_AntiProton_stat", 46, pTbins_proton);
    
    
    Proton_AntiProton_stat->SetBinContent(1, 0.19549);
    Proton_AntiProton_stat->SetBinContent(2, 0.21035);
    Proton_AntiProton_stat->SetBinContent(3, 0.21865);
    Proton_AntiProton_stat->SetBinContent(4, 0.22589);
    Proton_AntiProton_stat->SetBinContent(5, 0.22439);
    Proton_AntiProton_stat->SetBinContent(6, 0.21939);
    Proton_AntiProton_stat->SetBinContent(7, 0.21279);
    Proton_AntiProton_stat->SetBinContent(8, 0.20354);
    Proton_AntiProton_stat->SetBinContent(9, 0.19431);
    Proton_AntiProton_stat->SetBinContent(10, 0.18658);
    Proton_AntiProton_stat->SetBinContent(11, 0.17499);
    Proton_AntiProton_stat->SetBinContent(12, 0.16482);
    Proton_AntiProton_stat->SetBinContent(13, 0.15406);
    Proton_AntiProton_stat->SetBinContent(14, 0.14187);
    Proton_AntiProton_stat->SetBinContent(15, 0.12676);
    Proton_AntiProton_stat->SetBinContent(16, 0.10727);
    Proton_AntiProton_stat->SetBinContent(17, 0.09121);
    Proton_AntiProton_stat->SetBinContent(18, 0.07655);
    Proton_AntiProton_stat->SetBinContent(19, 0.0649);
    Proton_AntiProton_stat->SetBinContent(20, 0.05438);
    Proton_AntiProton_stat->SetBinContent(21, 0.04557);
    Proton_AntiProton_stat->SetBinContent(22, 0.03836);
    Proton_AntiProton_stat->SetBinContent(23, 0.0319);
    Proton_AntiProton_stat->SetBinContent(24, 0.02677);
    Proton_AntiProton_stat->SetBinContent(25, 0.0226);
    Proton_AntiProton_stat->SetBinContent(26, 0.01861);
    Proton_AntiProton_stat->SetBinContent(27, 0.01567);
    Proton_AntiProton_stat->SetBinContent(28, 0.01337);
    Proton_AntiProton_stat->SetBinContent(29, 0.01103);
    Proton_AntiProton_stat->SetBinContent(30, 0.00962);
    Proton_AntiProton_stat->SetBinContent(31, 0.00819);
    Proton_AntiProton_stat->SetBinContent(32, 0.007);
    Proton_AntiProton_stat->SetBinContent(33, 0.0061);
    Proton_AntiProton_stat->SetBinContent(34, 0.0052);
    Proton_AntiProton_stat->SetBinContent(35, 0.00414);
    Proton_AntiProton_stat->SetBinContent(36, 0.00298);
    Proton_AntiProton_stat->SetBinContent(37, 0.0022);
    Proton_AntiProton_stat->SetBinContent(38, 0.00165);
    Proton_AntiProton_stat->SetBinContent(39, 0.00118);
    Proton_AntiProton_stat->SetBinContent(40, 9.2E-4);
    Proton_AntiProton_stat->SetBinContent(41, 6.8E-4);
    Proton_AntiProton_stat->SetBinContent(42, 5.5E-4);
    Proton_AntiProton_stat->SetBinContent(43, 4.1E-4);
    Proton_AntiProton_stat->SetBinContent(44, 3.3E-4);
    Proton_AntiProton_stat->SetBinContent(45, 2.1E-4);
    Proton_AntiProton_stat->SetBinContent(46, 1.3E-4);
    
    
    
    
    Proton_AntiProton_stat->SetBinError(1,0.00091);
    Proton_AntiProton_stat->SetBinError(2,0.00079);
    Proton_AntiProton_stat->SetBinError(3,0.00070);
    Proton_AntiProton_stat->SetBinError(4, 0.00074);
    Proton_AntiProton_stat->SetBinError(5,   0.00068);
    Proton_AntiProton_stat->SetBinError(6,   0.00063);
    Proton_AntiProton_stat->SetBinError(7,    0.00097);
    Proton_AntiProton_stat->SetBinError(8,   0.00090);
    Proton_AntiProton_stat->SetBinError(9,   0.00083);
    Proton_AntiProton_stat->SetBinError(10,   0.00082);
    Proton_AntiProton_stat->SetBinError(11,   0.00086);
    Proton_AntiProton_stat->SetBinError(12,   0.00084);
    Proton_AntiProton_stat->SetBinError(13,   0.00083);
    Proton_AntiProton_stat->SetBinError(14,   0.00079);
    Proton_AntiProton_stat->SetBinError(15,   0.00050);
    Proton_AntiProton_stat->SetBinError(16,   0.00049);
    Proton_AntiProton_stat->SetBinError(17,   0.00045);
    Proton_AntiProton_stat->SetBinError(18,   0.00042);
    Proton_AntiProton_stat->SetBinError(19,   0.00034);
    Proton_AntiProton_stat->SetBinError(20,   0.00032);
    Proton_AntiProton_stat->SetBinError(21,  0.00027);
    Proton_AntiProton_stat->SetBinError(22,  0.00024);
    Proton_AntiProton_stat->SetBinError(23,  0.00022);
    Proton_AntiProton_stat->SetBinError(24,   0.00019);
    Proton_AntiProton_stat->SetBinError(25,   0.00020);
    Proton_AntiProton_stat->SetBinError(26,   0.00018);
    Proton_AntiProton_stat->SetBinError(27,   0.00016);
    Proton_AntiProton_stat->SetBinError(28,   0.00015);
    Proton_AntiProton_stat->SetBinError(29,   0.00013);
    Proton_AntiProton_stat->SetBinError(30,   0.00012);
    Proton_AntiProton_stat->SetBinError(31,   0.00011);
    Proton_AntiProton_stat->SetBinError(32,   0.00010);
    Proton_AntiProton_stat->SetBinError(33,   0.00010);
    Proton_AntiProton_stat->SetBinError(34,   0.00009);
    Proton_AntiProton_stat->SetBinError(35,   0.00006);
    Proton_AntiProton_stat->SetBinError(36,   0.00006);
    Proton_AntiProton_stat->SetBinError(37,   0.00005);
    Proton_AntiProton_stat->SetBinError(38,   0.00005);
    Proton_AntiProton_stat->SetBinError(39,   0.00004);
    Proton_AntiProton_stat->SetBinError(40,   0.00005);
    Proton_AntiProton_stat->SetBinError(41,   0.00004);
    Proton_AntiProton_stat->SetBinError(42,   0.00004);
    Proton_AntiProton_stat->SetBinError(43,   0.00003);
    Proton_AntiProton_stat->SetBinError(44,   0.00003);
    Proton_AntiProton_stat->SetBinError(45,   0.00002);
    Proton_AntiProton_stat->SetBinError(46,   0.00002);
    
    
    TH1D *Proton_AntiProton_sys = new TH1D("Proton_AntiProton_sys","Proton_AntiProton_sys", 46, pTbins_proton);
    
    
    Proton_AntiProton_sys->SetBinContent(1, 0.19549);
    Proton_AntiProton_sys->SetBinContent(2, 0.21035);
    Proton_AntiProton_sys->SetBinContent(3, 0.21865);
    Proton_AntiProton_sys->SetBinContent(4, 0.22589);
    Proton_AntiProton_sys->SetBinContent(5, 0.22439);
    Proton_AntiProton_sys->SetBinContent(6, 0.21939);
    Proton_AntiProton_sys->SetBinContent(7, 0.21279);
    Proton_AntiProton_sys->SetBinContent(8, 0.20354);
    Proton_AntiProton_sys->SetBinContent(9, 0.19431);
    Proton_AntiProton_sys->SetBinContent(10, 0.18658);
    Proton_AntiProton_sys->SetBinContent(11, 0.17499);
    Proton_AntiProton_sys->SetBinContent(12, 0.16482);
    Proton_AntiProton_sys->SetBinContent(13, 0.15406);
    Proton_AntiProton_sys->SetBinContent(14, 0.14187);
    Proton_AntiProton_sys->SetBinContent(15, 0.12676);
    Proton_AntiProton_sys->SetBinContent(16, 0.10727);
    Proton_AntiProton_sys->SetBinContent(17, 0.09121);
    Proton_AntiProton_sys->SetBinContent(18, 0.07655);
    Proton_AntiProton_sys->SetBinContent(19, 0.0649);
    Proton_AntiProton_sys->SetBinContent(20, 0.05438);
    Proton_AntiProton_sys->SetBinContent(21, 0.04557);
    Proton_AntiProton_sys->SetBinContent(22, 0.03836);
    Proton_AntiProton_sys->SetBinContent(23, 0.0319);
    Proton_AntiProton_sys->SetBinContent(24, 0.02677);
    Proton_AntiProton_sys->SetBinContent(25, 0.0226);
    Proton_AntiProton_sys->SetBinContent(26, 0.01861);
    Proton_AntiProton_sys->SetBinContent(27, 0.01567);
    Proton_AntiProton_sys->SetBinContent(28, 0.01337);
    Proton_AntiProton_sys->SetBinContent(29, 0.01103);
    Proton_AntiProton_sys->SetBinContent(30, 0.00962);
    Proton_AntiProton_sys->SetBinContent(31, 0.00819);
    Proton_AntiProton_sys->SetBinContent(32, 0.007);
    Proton_AntiProton_sys->SetBinContent(33, 0.0061);
    Proton_AntiProton_sys->SetBinContent(34, 0.0052);
    Proton_AntiProton_sys->SetBinContent(35, 0.00414);
    Proton_AntiProton_sys->SetBinContent(36, 0.00298);
    Proton_AntiProton_sys->SetBinContent(37, 0.0022);
    Proton_AntiProton_sys->SetBinContent(38, 0.00165);
    Proton_AntiProton_sys->SetBinContent(39, 0.00118);
    Proton_AntiProton_sys->SetBinContent(40, 9.2E-4);
    Proton_AntiProton_sys->SetBinContent(41, 6.8E-4);
    Proton_AntiProton_sys->SetBinContent(42, 5.5E-4);
    Proton_AntiProton_sys->SetBinContent(43, 4.1E-4);
    Proton_AntiProton_sys->SetBinContent(44, 3.3E-4);
    Proton_AntiProton_sys->SetBinContent(45, 2.1E-4);
    Proton_AntiProton_sys->SetBinContent(46, 1.3E-4);
    
    
    
    
    Proton_AntiProton_sys->SetBinError(1,  0.01829 );
    Proton_AntiProton_sys->SetBinError(2,	0.01813 );
    Proton_AntiProton_sys->SetBinError(3,	0.01804 );
    Proton_AntiProton_sys->SetBinError(4,	0.01089 );
    Proton_AntiProton_sys->SetBinError(5,	0.01039 );
    Proton_AntiProton_sys->SetBinError(6,	0.00962 );
    Proton_AntiProton_sys->SetBinError(7,	0.01425 );
    Proton_AntiProton_sys->SetBinError(8,	0.01352 );
    Proton_AntiProton_sys->SetBinError(9,	0.01264 );
    Proton_AntiProton_sys->SetBinError(10,	0.01188 );
    Proton_AntiProton_sys->SetBinError(11,	0.01087 );
    Proton_AntiProton_sys->SetBinError(12,	0.01021 );
    Proton_AntiProton_sys->SetBinError(13,	0.00948 );
    Proton_AntiProton_sys->SetBinError(14,	0.00873 );
    Proton_AntiProton_sys->SetBinError(15,	0.00784 );
    Proton_AntiProton_sys->SetBinError(16,	0.00658 );
    Proton_AntiProton_sys->SetBinError(17,	0.00560 );
    Proton_AntiProton_sys->SetBinError(18,	0.00468 );
    Proton_AntiProton_sys->SetBinError(19,	0.00406 );
    Proton_AntiProton_sys->SetBinError(20,	0.00321 );
    Proton_AntiProton_sys->SetBinError(21,	0.00271 );
    Proton_AntiProton_sys->SetBinError(22,	0.00227 );
    Proton_AntiProton_sys->SetBinError(23,	0.00189 );
    Proton_AntiProton_sys->SetBinError(24,	0.00160 );
    Proton_AntiProton_sys->SetBinError(25,	0.00142 );
    Proton_AntiProton_sys->SetBinError(26,	0.00113 );
    Proton_AntiProton_sys->SetBinError(27,	0.00094 );
    Proton_AntiProton_sys->SetBinError(28,	0.00082 );
    Proton_AntiProton_sys->SetBinError(29,	0.00071 );
    Proton_AntiProton_sys->SetBinError(30,	0.00062 );
    Proton_AntiProton_sys->SetBinError(31,	0.00051 );
    Proton_AntiProton_sys->SetBinError(32,	0.00046 );
    Proton_AntiProton_sys->SetBinError(33,	0.00039 );
    Proton_AntiProton_sys->SetBinError(34,	0.00034 );
    Proton_AntiProton_sys->SetBinError(35,	0.00028 );
    Proton_AntiProton_sys->SetBinError(36,	0.00021 );
    Proton_AntiProton_sys->SetBinError(37,	0.00017 );
    Proton_AntiProton_sys->SetBinError(38,	0.00014 );
    Proton_AntiProton_sys->SetBinError(39,	0.00012 );
    Proton_AntiProton_sys->SetBinError(40,	0.00010 );
    Proton_AntiProton_sys->SetBinError(41,	0.00007 );
    Proton_AntiProton_sys->SetBinError(42,	0.00006 );
    Proton_AntiProton_sys->SetBinError(43,	0.00005 );
    Proton_AntiProton_sys->SetBinError(44,	0.00004 );
    Proton_AntiProton_sys->SetBinError(45,	0.00002 );
    Proton_AntiProton_sys->SetBinError(46,	0.00002 );
    
    
    
    TFile *outputfile = new TFile("Light_Spectra.root", "RECREATE");
    
    Pion_AantiPion_stat->Write("Pion_AantiPion_stat");
    Pion_AantiPion_sys->Write("Pion_AantiPion_sys");
    Proton_AntiProton_stat->Write("Proton_AntiProton_stat");
    Proton_AntiProton_sys->Write("Proton_AntiProton_sys");
    
    
    
}
