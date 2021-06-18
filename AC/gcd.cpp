#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}


int main(){
    int N;
	cin>>N;
	int A[N];
	for(int i = 0; i < N; i++){
		cin>>A[i];
	}
	int gcdLeft[N];
	int gcdRight[N];

	gcdLeft[0] = A[0];
	gcdRight[N-1] = A[N-1];	

	for(int i = 1; i < N; i++){
		gcdLeft[i] = gcd(gcdLeft[i-1],A[i]);
		gcdRight[N-1-i] = gcd(gcdRight[N-i],A[N-1-i]);
	}
	int maxGcd = gcdRight[0];
	for(int i = 0; i < N; i++){
		if(i == 0)
			maxGcd = max(maxGcd,gcdRight[1]);
		else if(i == N)
			maxGcd = max(maxGcd,gcdLeft[N-1]);
		else
			maxGcd = max(maxGcd,gcd(gcdLeft[i-1],gcdRight[i+1]));
	}
	cout<<maxGcd;
}

