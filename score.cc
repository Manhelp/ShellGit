#include<iostream>
using namespace std;


int main()
{
		int flag=0;
		int arr[10];

		for(int i=0; i<10; i++){
				cin >> arr[i];
				if(arr[i]<0 || arr[i]>100){
						cout << "ERROR" << endl;
						break;
				}
		}

		for(int i=9; i>=0; i--){
				if(arr[i]>=60)
						flag++;
		}

		if(flag != 10){
		for(int i=0; i<10; i++)
				for(int j=i; j<10; j++){
						if(arr[i]>arr[j]){
								int temp = arr[i];
								arr[i] = arr[j];
								arr[j] = temp;
						}
				}
		cout << "The score:" << arr[5] / 10 * 10 << endl;
		}
		else{
				cout << "The score: " << 60 << endl;
		}
		return 0;
}
