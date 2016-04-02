#include <string>
#include <iostream>
using namespace std;

	
int main()
{
	string flag = "ReverseThisAlgorithmWithTheGivenStringToGetTheFlag";
	string shorterFlag="";
	for (int i = 0; i < flag.length()/2; i++) {
		shorterFlag += to_string((int)(flag[2*i+1]+flag[2*i])) + ",";
	}
	for (int i = 0; i < shorterFlag.length(); i++) {
		shorterFlag[i] = shorterFlag[i]^'a';
	}
	cout << shorterFlag << endl;
	return 0;
}