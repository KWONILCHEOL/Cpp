/*
	[G5]15961 회전 초밥2
	https://www.acmicpc.net/problem/15961
*/
#include<iostream>
#define MAX(A,B) A > B ? A : B
using namespace std;

int sushi[3003000];
int curSushi[3001];	//먹은 초밥 현황
int answer;
int cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, d, k, c;
	cin >> n >> d >> k >> c;

	for (int i = 0; i < n; i++) 
		cin >> sushi[i];
  
  for(int i=n; i < n + k; i++)
    sushi[i] = sushi[i-n];

  for(int i=0; i < k; i++){
    int x = sushi[i];
    curSushi[x]++;
    if(curSushi[x] == 1)
      cnt++;
  }
  if(curSushi[c] == 0)
    cnt++;
  
  answer = cnt;
  if ((answer == k + 1) || (answer == d)) {
		cout << answer;
		return 0;	
	}

  for(int i=k; i < n + k; i++){
    int add = sushi[i];
    int del = sushi[i-k];

    curSushi[del]--;
    if (curSushi[del] == 0 && del != c)
			cnt--;

    curSushi[add]++;
		if (curSushi[add] == 1 && add != c)
			cnt++;

		answer = MAX(answer, cnt);

    if ((answer == k + 1) || (answer == d)) {
		  cout << answer;
		  return 0;	
	  }
  }

	cout << answer;
  return 0;
}