#include<iostream>
#include<fstream>
#include<TFile.h>
#include<TTree.h>
#include<TRoot.h>
#include<TCanvas.h>

int tdc(){
 
 TFile * f1=new TFile("../raw-ntup/moller_data_16018.root");
 TTree *tr1=(TTree*)f1->Get("h1");
 Int_t nentries=tr1->GetEntries();
 Int_t event[nentries];

 for(Int_t i=0;i<nentries;i++)event[i]=i+1;
  TCanvas *c1=new TCanvas("c1","TDC 1-12",0,0,450,250);
  c1->Divide(3,4);
  TCanvas *c2=new TCanvas("c2","TDC 13-24",450,0,700,250);
  c2->Divide(3,4);

  char *name=new char[10];
  for(Int_t i=0;i<12;i++){
    sprintf(name,"itim[%d]",i);
    c1->cd(i+1);
    tr1->Draw(name);
  }

  for(Int_t i=12;i<24;i++){
    sprintf(name,"itim[%d]",i);
    c2->cd(i-11);
    tr1->Draw(name);
  }  
  

  
  return 0;
}
