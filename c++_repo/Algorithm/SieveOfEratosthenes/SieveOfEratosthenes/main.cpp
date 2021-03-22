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
			cout << "�����佺�׳׽� ü�� �̹� �ʱ�ȭ�� �Ǿ����ϴ�."; 

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


	cout << "############  �����佺�׳׽� ü  ############" << endl << endl;
	cout << "�����佺�׳׽��� ü�� ����� ���߸� ã�� ������� 2���� �����Ͽ� \n�� ���� ����� �������� ������ ���� ���� �Ҽ����� �̿��� ����̴�." << endl;
	cout << endl << "-------------------------------------------------------------------------" << endl;

	int n, select;
	cout << "�ִ� �Ҽ��� ������ �Է�(0�Է½� Default) : ";
	cin >> n;
	SieveOfEratosthenes sieveOfEratosthenes = SieveOfEratosthenes(n);
	
	cout << "1. �����佺�׳׽��� ü ���" << endl;
	cout << "2. �Ҽ� ���� Ȯ��" << endl;

	
	while (true) {
		cout << "������ �۾��� �������ֽÿ�(����:0) : ";
		cin >> select;

		if (select == 1) {
			sieveOfEratosthenes.printSieveOfEratosthenes();
		}
		else if (select == 2) {
			int prime;
			cout << "Ȯ���ϰ��� �ϴ� �Ҽ���? ";
			cin >> prime;

			if (sieveOfEratosthenes.isPrime(prime)) {
				cout << prime << "�� �Ҽ��Դϴ�." << endl;
			}
			else {
				cout << prime << "�� �Ҽ��� �ƴմϴ�." << endl;
			}
		}
		else {
			break;
		}
	}
	

	return 0;
}