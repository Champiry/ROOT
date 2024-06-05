//--------------------------------
// CHEP Project
//--------------------------------
// Afshin Mahmoudieh Champiry 
// 2333105008
// 2023-2024
//--------------------------------
// Read a Tree @ Root
// 04 June 2024
//--------------------------------
// data.txt :
//************************************************************
//*    Row   * nScinPhot * nCerenPho * nAbsPhot_ * TotEdep_x *
//************************************************************

void rtree()
{
	TCanvas *c1 = new TCanvas();
	TFile *inpout = new TFile("data.root", "read");
	TTree *mytree = (TTree*)input->Get("mytree");
	
	double nScinPhot, nCerenPho, nAbsPhot_, TotEdep_x;
	
	tree->SetBranch("nScinPhot", &nScinPhot); //, "nScinPhot/D");
	tree->SetBranch("nCerenPho", &nCerenPho); //, "nCerenPho/D");
	tree->SetBranch("nAbsPhot_", &nAbsPhot_); //, "nAbsPhot_/D");
	tree->SetBranch("TotEdep_x", &TotEdep_x); //, "TotEdep_x/D");
	
	int entries = tree->GetEntries();
	
	cout << entries << endl;
	
	TH1F *hit = new TH1F("hist", "Histogram", 20, 0, 20);
	
	for(int i = 0 <entries; i++)
	{
		tree->GetEntry(i);
		
		cout << nScinPhot << "	" << nCerenPho << "	"  << nAbsPhot_  << "	" << TotEdep_x << endl;
		
		hist->Fill(x);
		
	}
	hist->Draw();
	