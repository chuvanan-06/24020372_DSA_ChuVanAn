#include<iostream>
using namespace std;
int main() {
	int N;
	cout<<"Nhap so luong phan tu N" ;
	cin>>N;
	int a[1000] ;
	cout<<"Nhap"<<N<<"phan tu cua day.";
	for(int i=0;i<N;i++) {
		cin>>a[i];
	}
	int sum=0;
	for(int i=0;i<N;i++) {
		sum+=a[i];
	}
	cout<<"Tong cac phan tu cua day la"<<sum<<endl;
	return 0;
}
