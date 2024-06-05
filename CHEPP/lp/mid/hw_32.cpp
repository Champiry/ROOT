//hw_32.cpp
//HomeWork 3	-Finding pi number using the Montcarlo method.
//		-Drawing the error ratio per number of events.
// version 3.2
  
void hw_32(){

//-------------------------------------------------------------------
//simulation parameters: number of events and resolution (step)
//-------------------------------------------------------------------	
	int res = 1000; 	//number of events
	int step= 10;
//-------------------------------------------------------------------
		
	double u[step]; 		//calculated ration array
	double v[step]; 		//events array
	
	for(int kk=0; kk<step; kk++){
	u[kk]=0;
	v[kk]=0;
	}
	
	TRandom3 rand(0);
	
	double circle_point = 0;
	double square_point = 0;
	double ratio;

	int k=1;	
	
	//x
	//y
	//distance
	//pi_estimate
//-------------------------------------------------------------------
	
	for(int j=1; j<res; j=j+step){ 
	
		circle_point = 0;
		square_point = 0;
		ratio = 0;
		
			for(int i=0; i<j; i++){
		
				double x = rand.Rndm();
				double y = rand.Rndm();
			
				double distance = (x*x + y*y);
			
				if(distance <= 1.){
					circle_point++;
				}
				square_point++;
			}
		
		double pi_estimate = (4*circle_point) / square_point;
		ratio = 3.14159 / pi_estimate;
		
		u[k]=ratio;
		v[k]=j;
		k++;

//---------------------- output log ----------------------		
		cout<<"k="<<k<<" j="<<j<<"   	v["<<k<<"]="<<v[k]<<"	 u[k]="<<u[k]<<"        	ratio= "<<ratio<<endl;
		}
	
	cout<<"==============================="<<endl;
	cout<<"Res="<<res<<" events"<<"   Step="<<step<<endl;
	cout<<"==============================="<<endl;			
	cout<<" u[]="<<u<<endl;
	cout<<" v[]="<<v<<endl;
	cout<<"============================"<<endl;
//--------------------------------------------------------
//--------------------- output graph ---------------------		
	TCanvas *c1 = new TCanvas("c1","Graph");
	TGraph *gr = new TGraph(k,v,u);
	gr->SetTitle("Accuracy (%);Number of Events;3.14159 / pi_estimate");
	gr->Draw("Ac.");
	
 }
 
 
 
 
