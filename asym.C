#include<iostream>
#include<fstream>
#include<TFile.h>
#include<TTree.h>
#include<TRoot.h>
#include<TCanvas.h>

int asym(){
  TFile * f1=new TFile("moller16700.root");
  // TFile * f1=new TFile("../raw-ntup/commisioning/moller_data_16354.root");
 TTree *tr1=(TTree*)f1->Get("h1");
 Int_t nentries=tr1->GetEntries();
 Int_t event[nentries];
 Int_t tick[nentries];
 // Declaration of leaf types
 UShort_t        irun;
 UChar_t         idtyp;
 UChar_t         ievtyp;
 Int_t           iret;
 UChar_t         itrig[8];
 Int_t           itick;
 Int_t           nadc;
 UShort_t        iadc[36];   //[nadc]
 Int_t           ntdc;
 UShort_t        itch[4096];   //[ntdc]
 UShort_t        itim[4096];   //[ntdc]
 UChar_t         ited[4096];   //[ntdc]
 Int_t           nhcha;
 UShort_t        ihit[10];   //[nhcha]
 Int_t           nsca;
 Int_t           isca[33];   //[nsca]

 // List of branches
 TBranch        *b_irun;   //!
 TBranch        *b_idtyp;   //!
 TBranch        *b_ievtyp;   //!
 TBranch        *b_iret;   //!
 TBranch        *b_itrig;   //!
 TBranch        *b_itick;   //!
 TBranch        *b_nadc;   //!
 TBranch        *b_iadc;   //!
 TBranch        *b_ntdc;   //!
 TBranch        *b_itch;   //!
 TBranch        *b_itim;   //!
 TBranch        *b_ited;   //!
 TBranch        *b_nhcha;   //!
 TBranch        *b_ihit;   //!
 TBranch        *b_nsca;   //!
 TBranch        *b_isca;   //!

    tr1->SetBranchAddress("irun", &irun, &b_irun);
   tr1->SetBranchAddress("idtyp", &idtyp, &b_idtyp);
   tr1->SetBranchAddress("ievtyp", &ievtyp, &b_ievtyp);
   tr1->SetBranchAddress("iret", &iret, &b_iret);
   tr1->SetBranchAddress("itrig", itrig, &b_itrig);
   tr1->SetBranchAddress("itick", &itick, &b_itick);
   tr1->SetBranchAddress("nadc", &nadc, &b_nadc);
   tr1->SetBranchAddress("iadc", iadc, &b_iadc);
   tr1->SetBranchAddress("ntdc", &ntdc, &b_ntdc);
   tr1->SetBranchAddress("itch", itch, &b_itch);
   tr1->SetBranchAddress("itim", itim, &b_itim);
   tr1->SetBranchAddress("ited", ited, &b_ited);
   tr1->SetBranchAddress("nhcha", &nhcha, &b_nhcha);
   tr1->SetBranchAddress("ihit", ihit, &b_ihit);
   tr1->SetBranchAddress("nsca", &nsca, &b_nsca);
   tr1->SetBranchAddress("isca", isca, &b_isca);


   TH1I *diff=new TH1I("diff","Difference in scalars",20000,0,20000);
   TH1I *hel1=new TH1I("hel1","Helicity = 1",20000,0,20000);
   TH1I *hel2=new TH1I("hel2","Helicity = 2",20000,0,20000);      
   TH1I *hel=new TH1I("hel","adc[12]",500,0,500);
   TH1F *a1=new TH1F("a1","Asymmetry",2000,-2,2);      
   Int_t jcdif;
   Int_t accdif;
   Int_t bcmdif;      
   Int_t ncyc=0;
   Int_t jsca=0;
   Int_t acc=0;
   Int_t bcm=0;   
   Int_t jhel=0;
   Int_t cntr=0;
   Float_t num=0;
   Float_t denom=0;
   Float_t asym=0;
   Int_t trig0=0;
   Int_t trig7=0;   
   for(Int_t i=0;i<nentries;i++){

     tr1->GetEntry(i);
     trig0=itrig[0];
     trig7=itrig[7];
     jcdif=isca[2]-jsca;
     jsca=isca[2];
     accdif=isca[3]-acc;
     acc=isca[3];
     bcmdif=isca[4]-bcm;
     bcm=isca[4];     

     //     cout<<jcdif<<endl;

     if(jcdif!=0 && i!=0){
       cntr++;
       if (trig7==0){cntr=1;}
       diff->Fill(jcdif);
       hel->Fill(iadc[11]);

       if(iadc[11]>150){
       jhel=1;
       hel2->Fill(jcdif);}
       else{
       jhel=-1;
       hel1->Fill(jcdif);}
       cout <<jhel<<" "<<i<<"trig[0]:"<<trig0<<"\t trig[7]"<<trig7<<    endl;
       num+= ((Float_t)jhel*((Float_t)jcdif-(Float_t)accdif)/(Float_t)bcmdif);
       denom+=(((Float_t)jcdif-(Float_t)accdif)/(Float_t)bcmdif);
       cout <<accdif<<"\t"<<bcmdif<<endl;
       //       cout << "num:"<<num<<"\tdenom:"<<denom<<"\tjcdif"<<jcdif<<endl;
         if(cntr==4){
	 asym=(Float_t)num/denom;
	 //	 cout <<"cntr"<<cntr<<"\t"<< asym <<endl;
	 cout<<endl;
	 a1->Fill(asym);
	 num=0;
	 denom=0;
	 cntr=0;
       }
     }
     
       event[i]=i+1;

   tick[i]=itick;
   //   cout<<event[i]<<"\t"<<tick[i]<<endl;
   if(itrig[0]!=0)ncyc++;

   }
   //	 asym=(Float_t)num/denom;
   //	 cout <<num<<"   "<<denom<< "   The asymmetry is:"<<asym<<endl;
   cout<<"number of cycles"<<ncyc<<endl;
   cout << "Last tick minus first tick is "<<tick[nentries-1]-tick[0]<<endl;
  TCanvas *c1=new TCanvas("c1","Ticks vs Event#",0,0,600,800);
  TGraph *gr1=new TGraph(nentries,event,tick);
  c1->Divide(3,2);
  c1->cd(1);
  gr1->Draw("ap");
  c1->cd(2);
   diff->Draw("cp");

  c1->cd(3);
   hel->Draw();
  c1->cd(4);
   hel1->Draw();
  c1->cd(5);
   hel2->Draw();
  c1->cd(6);
   a1->Draw();      
   

  
  return 0;
}
