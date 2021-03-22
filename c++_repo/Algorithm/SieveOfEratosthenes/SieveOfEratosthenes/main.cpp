#include<iostream>
#include<cmath>

using namespace std;

class SieveOfEratosthenes {
private:
	int const DEFAULT_MAX_SIZE = 100;
	int size;
	bool *primeArr = NULL;

	void setSieveOfEratosthenes(int n) {
		size = n;
		if (primeArr != NULL) {
			cout << "에라토스테네스 체가 이미 초기화가 되었습니다."; 

			return;
		}

		primeArr = new bool[size + 1];
		memset(primeArr, true, (size+1) * sizeof(bool));
		primeArr[0] = false;
		primeArr[1] = false;
		primeArr[size] = false;

		for (int i = 2; i < sqrt(size); i++) {
			if (!primeArr[i]) continue;

			for (int idx = i * 2; idx <= size; idx += i) {
				primeArr[idx] = false;
			}
		}
	}

public:
	//Default Size
	SieveOfEratosthenes() {
		setSieveOfEratosthenes(DEFAULT_MAX_SIZE);
	}

	SieveOfEratosthenes(int n) {
		if (n == 0) {
			SieveOfEratosthenes();
			return;
		}
		setSieveOfEratosthenes(n);
	}

	bool isPrime(int num) {
		
		return primeArr[num];
	}

	void printSieveOfEratosthenes() {
		for (int i = 1;i <= size;i++) {
			cout << primeArr[i] << " ";
			if(!(i%10)) cout<<endl;
		}
	}

};


int main() {


	cout << "############  에라토스테네스 체  ############" << endl << endl;
	cout << "에라토스테네스의 체가 고안한 소추를 찾는 방법으로 2부터 시작하여 \n각 수의 배수를 지워나가 마지막 남은 수가 소수임을 이용한 방법이다." << endl;
	cout << endl << "-------------------------------------------------------------------------" << endl;

	int n, select;
	cout << "최대 소수의 사이즈 입력(0입력시 Default) : ";
	cin >> n;
	SieveOfEratosthenes sieveOfEratosthenes = SieveOfEratosthenes(n);
	
	cout << "1. 에라토스테네스의 체 출력" << endl;
	cout << "2. 소수 여부 확인" << endl;

	
	while (true) {
		cout << "수행할 작업을 선택해주시오(종료:0) : ";
		cin >> select;

		if (select == 1) {
			sieveOfEratosthenes.printSieveOfEratosthenes();
		}
		else if (select == 2) {
			int prime;
			cout << "확인하고자 하는 소수는? ";
			cin >> prime;

			if (sieveOfEratosthenes.isPrime(prime)) {
				cout << prime << "은 소수입니다." << endl;
			}
			else {
				cout << prime << "은 소수가 아닙니다." << endl;
			}
		}
		else {
			break;
		}
	}
	

	return 0;
}