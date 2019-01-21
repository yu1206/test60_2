
#include "MSRCR.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream> 
#include <io.h>
#include <Windows.h>
#include "opencv\cv.h"
#include "opencv\highgui.h"
#include <direct.h>

using namespace cv;
using namespace std;


extern void SplitString(const string& s, vector<string>& v, const string& c);
extern int readDir(char *dirName, vector<string> &filesName);




int test60_1(int argc, char *argv[])
{

	string imgpath = "E:\\LISA-Traffic-Light\\dayTrainingall\\dayClip";

	fstream finRead;
	string inputPathtxt = imgpath + "\\" + "trainval-bigall.txt";
	finRead.open(inputPathtxt, ios::in);
	if (!finRead.is_open())
	{
		cout << "finRead1 文件数据打开错误！" << endl;
		system("pause");
		return false;
	}

	int classnum[7] = {0};
	string line;

	while (getline(finRead, line))
	{
		string str1, str2;
		stringstream str_s(line);
		str_s >> str1 >> str2;

		/*int npos = str2.find_last_of('\\');
		int npos2 = vs[0].find_last_of('.');
		string name1 = vs[0].substr(npos + 1, npos2 - npos - 1);*/

		string outputtxt = imgpath + "\\" + str2;
		fstream fin1;
		fin1.open(outputtxt, ios::in);

		if (!fin1.is_open())
		{
			cout << "fin12 文件数据打开错误！" << endl;
			system("pause");
			return false;
		}


		string line1;
		
		while (getline(fin1, line1))
		{
			int x1, y1, x2, y2, label;
			stringstream str_s(line1);
			str_s >> label >> x1>>y1>>x2>>y2;
			classnum[label]++;
		}
		
		fin1.close();

	}

	finRead.close();


	for (int i = 1; i < 7; i++)
	{
		printf("%d,classnum:%d\n", i, classnum[i]);
	}

	return 0;
}

int test60_2(int argc, char *argv[])
{

	string imgpath = "E:\\LISA-Traffic-Light\\dayTrainingall\\dayClip";

	fstream finRead;
	string inputPathtxt = imgpath + "\\" + "trainval-bigallone.txt";
	finRead.open(inputPathtxt, ios::in);
	if (!finRead.is_open())
	{
		cout << "finRead1 文件数据打开错误！" << endl;
		system("pause");
		return false;
	}

	int classnum[7] = { 0 };
	string line;
	while (getline(finRead, line))
	{
		string str1, str2;
		stringstream str_s(line);
		str_s >> str1 >> str2;

		/*int npos = str2.find_last_of('\\');
		int npos2 = vs[0].find_last_of('.');
		string name1 = vs[0].substr(npos + 1, npos2 - npos - 1);*/

		string outputtxt = imgpath + "\\" + str2;
		fstream fin1;
		fin1.open(outputtxt, ios::in);

		if (!fin1.is_open())
		{
			cout << "fin12 文件数据打开错误！" << endl;
			system("pause");
			return false;
		}


		string line1;
		
		while (getline(fin1, line1))
		{
			int x1, y1, x2, y2, label;
			stringstream str_s(line1);
			str_s >> label >> x1 >> y1 >> x2 >> y2;
			classnum[label]++;
		}

		fin1.close();

	}

	finRead.close();


	for (int i = 1; i < 7; i++)
	{
		printf("%d,classnum:%d\n", i, classnum[i]);
	}

	return 0;
}
int test60(int argc, char *argv[])
{

	test60_1(argc, argv);
	test60_2(argc, argv);

	return 0;
}










