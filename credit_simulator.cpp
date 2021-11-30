#include <iostream>
#include <string>
#include <stdio.h>
#include <ctime>   
#include <string.h>
#include<bits/stdc++.h>
#include <iomanip>

using namespace std;

int main(){
	cout << "Welcome to Simple Credit Simulator by Maybank" << endl;
	cout << "created by Jeremy Matthew Mandei" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	
	int year, loan, tenor, dp, cicil;
	time_t curr_time = time(NULL);
	char type[4], condition[5], recalc[3];
	
	
	do{
		do{
			cout << "Input vehicle Type [motor | mobil]: " ;
			cin >> type;
			for(int i=0;i<strlen(type);i++){
				type[i]=tolower(type[i]);
			}
		}while(strcmp(type, "mobil") != 0 && strcmp(type, "motor") != 0);
		
		
		cout << endl;
		cout << "============================================" << endl;
		cout << endl;
	
	
		do{
			cout << "Input vehicle Condition [baru | bekas]: " ;
			cin >> condition;
			for(int i=0;i<strlen(condition);i++){
				condition[i]=tolower(condition[i]);
			}
		}while(strcmp(condition, "baru") != 0 && strcmp(condition, "bekas") != 0);
		
	
		cout << endl;
		cout << "============================================" << endl;
		cout << endl;
		
		
		if(strcmp(condition, "baru") == 0){
			do{
				cout << "Input vehicle production Year [!< CurrentYear - 1]: " ;
				cin >> year;
			}while(year <= (curr_time/31537970 + 1970)-2);	
		}else{
			cout << "Input vehicle production Year: " ;
			cin >> year;
		}

		cout << endl;
		cout << "============================================" << endl;
		cout << endl;
		
	
		do{
			cout << "Input Loan [<1 Bil]: " ;
			cin >> loan;
		}while(loan > 1000000000);
		
		
		cout << endl;
		cout << "============================================" << endl;
		cout << endl;
		
	
		do{
			cout << "Input Tenor [1 - 6] tahun: " ;
			cin >> tenor;
		}while(tenor < 1 || tenor > 6);
		
		
		cout << endl;
		cout << "============================================" << endl;
		cout << endl;
		
		
		if(strcmp(condition, "baru") == 0){
			do{
				cout << "Input Down Payment (DP) [Min 35%]: " ;
				cin >> dp;
			}while(dp < (0.35*loan));
		}else{
			do{
				cout << "Input Down Payment (DP) [Min 25%]: " ;
				cin >> dp;
			}while(dp < (0.25*loan));
		}
		
		double pokok_pinjam[6], total_pinjam[6], cicilan_perbulan[6], cicilan_pertahun[6];
		float rate[6];
		
		if(strcmp(type, "mobil") == 0){
			rate[1] = 0.08;
		}else if(strcmp(type, "motor") == 0){
			rate[1] = 0.09;
		}
		
		cout << endl;
		cout << endl;
		cout << "============================================" << endl;
		cout << endl;
		cout << "Payment Estimation: " << endl;
		cout << endl;
		cout << endl;
		
		cout << left << setw(7) << "Tahun" << left << setw(27) << "Cicilan per Bulan (Rp.)" << left << setw(25) << "Bunga per Tahun (Rp.)" << left << setw(12) << "Bunga (%)" << endl;
		
		for(int i=1;i<=tenor;i++){
			if(i > 1){
				pokok_pinjam[i] = total_pinjam[i-1] - cicilan_pertahun[i-1];
			}else{
				pokok_pinjam[i] = loan-dp;
			}
			if(i > 1){
				if(i%2 == 0){
					rate[i] = rate[i-1]+0.001;
				}
				else if(i%2 == 1){
					rate[i] = rate[i-1]+0.005;
				}
			}
			total_pinjam[i] = (pokok_pinjam[i] * rate[i]) + pokok_pinjam[i];
			if(i > 1){
				cicilan_perbulan[i] = total_pinjam[i]/((12*tenor)-(12*(i-1)));	
			}else{
				cicilan_perbulan[i] = total_pinjam[i]/(12*tenor);
			}
			
			cicilan_pertahun[i] = cicilan_perbulan[i]*12;

			cout << left << setw(7) << i << left << setw(27) << fixed << setprecision(2) << cicilan_perbulan[i] << left << setw(25) << pokok_pinjam[i] * rate[i] << left << setw(12) << rate[i]*100 << endl;

		}

		cout << endl;
		cout << "============================================" << endl;
		cout << endl;
		
		cout << "Calculate another loan [yes | no]: ";
		cin >> recalc;
		for(int i=0;i<strlen(recalc);i++){
				recalc[i]=tolower(recalc[i]);
			}
	}while(strcmp(recalc, "yes") == 0);
	

	
	
	
	return 0;
}
