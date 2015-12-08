#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <math.h>

using namespace std;
#define PROCESS_LEN 2
#define VECTOR_LEN 100

vector<int> BigIntSum(vector<int> OP1, vector<int> OP2);

vector<int> BigIntMul(vector<int> OP1, int OPMUL2);

void printOP(vector<int> OP);

int main() {
	string str;
	cin >> str;
	string str2 = "";
	int control = PROCESS_LEN;
	int i;
	for(i = 0; i < PROCESS_LEN-str.size()%PROCESS_LEN; i++) {
		str2 = str2 + "0";
	}
	str = str2 + str;
	vector<int> OP1;
	for(i = str.size(); i > 0; i-= PROCESS_LEN) {
		int aux = str.size()-control-1;
		string t;
		t = str.substr(str.size()-control, PROCESS_LEN);
		
		//n1[VECTOR_LEN-(control/PROCESS_LEN)] = atoi(t.c_str());
		OP1.insert(OP1.begin(),atoi(t.c_str()));
		control += PROCESS_LEN;
	}

    //OP2
    control = PROCESS_LEN;
    cin >> str;
    str2 = "";
	for(i = 0; i < PROCESS_LEN-str.size()%PROCESS_LEN; i++) {
		str2 = str2 + "0";
	}
	str = str2 + str;
	vector<int> OP2;
	for(i = str.size(); i > 0; i-= PROCESS_LEN) {
		int aux = str.size()-control-1;
		string t;
		t = str.substr(str.size()-control, PROCESS_LEN);
		
		//n1[VECTOR_LEN-(control/PROCESS_LEN)] = atoi(t.c_str());
		OP2.insert(OP2.begin(),atoi(t.c_str()));
		control += PROCESS_LEN;
	}
	if(OP1.size() < OP2.size()) {
		vector<int> OPAUX = OP1;
		OP1 = OP2;
		OP2 = OPAUX;
	}
	vector<int> result;
	//INÍCIO SOMA
	
	//result = BigIntSum(OP1, OP2);
	vector<vector<int>> vResult;
	for(i = 0;OP2.size() > 0; i++) {
		cout << "OP..\n";
		vector <int> pre = BigIntMul(OP1,OP2.back());
		for(int j = 0; j < i; j++) {
			cout << "pre\n";
			pre.push_back(0);
			printOP(pre);
		}
		
		vResult.push_back(pre);
		OP2.pop_back();
	}
	vector<int> ACUM;
	for(;vResult.size() > 0;) {
		cout << "ACUM\n";
		ACUM = BigIntSum(vResult.back(),ACUM);
		cout << "ACUM.size() " << ACUM.size() << "\n";
		vResult.pop_back();
	}
	


	
	//FIM SOMA
	
	//result = BigIntMul(OP1,OP2.back());

	printOP(ACUM);
	return 0;
}

void printOP(vector<int> OP) {
	cout << "\nANS\n";
	for (vector<int>::iterator it=OP.begin(); it<OP.end(); it++)
    	cout << *it <<"|"; //Outputs the values of MyVector in order */
    cout <<"\n\n";
}
//   7771111111122222222333333

/*
 19748x19748

	 1 97 48
		 x48
	94 79 04
		 x97
  1 91 55 56 00
		  x1
  	 1 97 48 00 00

 3 89 98 35 04



*/

vector<int> BigIntMul(vector<int> OP1, int OP2MUL) {
	vector<int> result;

	/*/
		7 797 468
			2 0

	*/
	int i;
	for(;OP1.size() > 0 ;) {
		int MUL = OP1.back();
		OP1.pop_back();
		MUL *= OP2MUL;
		result.insert(result.begin(), MUL);
	}
	vector<int> result2 = result;
	result.clear();
	int carry = 0;
	for(; ;) {
			if(result2.size() > 0) {
				int toSum = result2.back()+carry;
				result2.pop_back();
				result.insert(result.begin(), (toSum) % (int)pow(10, PROCESS_LEN));
				carry = toSum / pow(10, PROCESS_LEN);
			}
			else {
				if(carry > 0) {
					result.insert(result.begin(), carry);
					carry = 0;
				}
				else
					break;
			}
	}
	return result;
}

vector<int> BigIntSum(vector<int> OP1, vector<int> OP2) {
	vector<int> result;
	int i;
	for(;OP1.size() > 0 ;) {
		int SUM = OP1.back();
		OP1.pop_back();
		if(OP2.size() > 0) {
			SUM += OP2.back();
			OP2.pop_back();
		}
		result.insert(result.begin(), SUM);
	}
	vector<int> result2 = result;
	result.clear();
	int carry = 0;
	for(; ;) {
		if(result2.size() > 0) {
			int toSum = result2.back()+carry;
			result2.pop_back();
			result.insert(result.begin(), (toSum) % (int)pow(10, PROCESS_LEN));
			carry = toSum / pow(10, PROCESS_LEN);
		}
		else {
			if(carry > 0) {
				result.insert(result.begin(), carry);
				carry = 0;
			}
			else
				break;
		}
	}
	return result;
}



/*
4937
   2
-----



*/
