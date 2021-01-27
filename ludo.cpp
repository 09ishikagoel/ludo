#include<iostream>
#include<vector>
#include<ios>
#include<string>
#include<queue>
using namespace std;
string arr[61][61];
vector<string> name;
int turn=0;
queue<int> moves;
queue<int> number_of_dice;
vector<bool>player_finished;
int number;
int Afinished=0;
int Bfinished=0;
int Cfinished=0;
int Dfinished=0;
int last=0;
int number_of_players_finished=0;
pair<int,int> coordinatesofA[4]={make_pair(6,6),make_pair(6,6+12),make_pair(6+12,6+12),make_pair(6+12,6)};
pair<int,int> coordinatesofB[4]={make_pair(60-6,60-6),make_pair(60-6,60-6-12),make_pair(60-6-12,60-6-12),make_pair(60-6-12,60-6)};
pair<int,int> coordinatesofC[4]={make_pair(6,60-6),make_pair(6,60-6-12),make_pair(6+12,60-6-12),make_pair(6+12,60-6)};
pair<int,int> coordinatesofD[4]={make_pair(60-6,6),make_pair(60-6,6+12),make_pair(60-6-12,6+12),make_pair(60-6-12,6)};
pair<int,int> coordinatesforA[]={make_pair(26,6),make_pair(26,10),make_pair(26,14),make_pair(26,18),make_pair(26,22),make_pair(22,26),make_pair(18,26),make_pair(14,26),make_pair(10,26),make_pair(6,26),make_pair(2,26),make_pair(2,30),make_pair(2,34),make_pair(6,34),make_pair(10,34),make_pair(14,34),make_pair(18,34),make_pair(22,34),make_pair(26,38),make_pair(26,42),make_pair(26,46),make_pair(26,50),make_pair(26,54),make_pair(26,58),make_pair(30,58),make_pair(34,58),make_pair(34,54),make_pair(34,50),make_pair(34,46),make_pair(34,42),make_pair(34,38),make_pair(38,34),make_pair(42,34),make_pair(46,34),make_pair(50,34),make_pair(54,34),make_pair(58,34),make_pair(58,30),make_pair(58,26),make_pair(54,26),make_pair(50,26),make_pair(46,26),make_pair(42,26),make_pair(38,26),make_pair(34,22),make_pair(34,18),make_pair(34,14),make_pair(34,10),make_pair(34,6),make_pair(34,2),make_pair(30,2),make_pair(30,6),make_pair(30,10),make_pair(30,14),make_pair(30,18),make_pair(30,22),make_pair(25+Afinished,26)};
pair<int,int> coordinatesforB[]={make_pair(34,54),make_pair(34,50),make_pair(34,46),make_pair(34,42),make_pair(34,38),make_pair(38,34),make_pair(42,34),make_pair(46,34),make_pair(50,34),make_pair(54,34),make_pair(58,34),make_pair(58,30),make_pair(58,26),make_pair(54,26),make_pair(50,26),make_pair(46,26),make_pair(42,26),make_pair(38,26),make_pair(34,22),make_pair(34,18),make_pair(34,14),make_pair(34,10),make_pair(34,6),make_pair(34,2),make_pair(30,2),make_pair(26,2),make_pair(26,6),make_pair(26,10),make_pair(26,14),make_pair(26,18),make_pair(26,22),make_pair(22,26),make_pair(18,26),make_pair(14,26),make_pair(10,26),make_pair(6,26),make_pair(2,26),make_pair(2,30),make_pair(2,34),make_pair(6,34),make_pair(10,34),make_pair(14,34),make_pair(18,34),make_pair(22,34),make_pair(26,38),make_pair(26,42),make_pair(26,46),make_pair(26,50),make_pair(26,54),make_pair(26,58),make_pair(30,58),make_pair(30,54),make_pair(30,50),make_pair(30,46),make_pair(30,42),make_pair(30,38),make_pair(32+Bfinished,34)};
pair<int,int> coordinatesforC[]={make_pair(6,34),make_pair(10,34),make_pair(14,34),make_pair(18,34),make_pair(22,34),make_pair(26,38),make_pair(26,42),make_pair(26,46),make_pair(26,50),make_pair(26,54),make_pair(26,58),make_pair(30,58),make_pair(34,58),make_pair(34,54),make_pair(34,50),make_pair(34,46),make_pair(34,42),make_pair(34,38),make_pair(38,34),make_pair(42,34),make_pair(46,34),make_pair(50,34),make_pair(54,34),make_pair(58,34),make_pair(58,30),make_pair(58,26),make_pair(54,26),make_pair(50,26),make_pair(46,26),make_pair(42,26),make_pair(38,26),make_pair(34,22),make_pair(34,18),make_pair(34,14),make_pair(34,10),make_pair(34,6),make_pair(34,2),make_pair(30,2),make_pair(26,2),make_pair(26,6),make_pair(26,10),make_pair(26,14),make_pair(26,18),make_pair(26,22),make_pair(22,26),make_pair(18,26),make_pair(14,26),make_pair(10,26),make_pair(6,26),make_pair(2,26),make_pair(2,30),make_pair(6,30),make_pair(10,30),make_pair(14,30),make_pair(18,30),make_pair(22,30),make_pair(25+Cfinished,34)};
pair<int,int> coordinatesforD[]={make_pair(54,26),make_pair(50,26),make_pair(46,26),make_pair(42,26),make_pair(38,26),make_pair(34,22),make_pair(34,18),make_pair(34,14),make_pair(34,10),make_pair(34,6),make_pair(34,2),make_pair(30,2),make_pair(26,2),make_pair(26,6),make_pair(26,10),make_pair(26,14),make_pair(26,18),make_pair(26,22),make_pair(22,26),make_pair(18,26),make_pair(14,26),make_pair(10,26),make_pair(6,26),make_pair(2,26),make_pair(2,30),make_pair(2,34),make_pair(6,34),make_pair(10,34),make_pair(14,34),make_pair(18,34),make_pair(22,34),make_pair(26,38),make_pair(26,42),make_pair(26,46),make_pair(26,50),make_pair(26,54),make_pair(26,58),make_pair(30,58),make_pair(34,58),make_pair(34,54),make_pair(34,50),make_pair(34,46),make_pair(34,42),make_pair(34,38),make_pair(38,34),make_pair(42,34),make_pair(46,34),make_pair(50,34),make_pair(54,34),make_pair(58,34),make_pair(58,30),make_pair(54,30),make_pair(50,30),make_pair(46,30),make_pair(42,30),make_pair(38,30),make_pair(32+Dfinished,26)};
pair<int,int> immune_cells[]={make_pair(26,6),make_pair(10,26),make_pair(6,34),make_pair(26,50),make_pair(34,54),make_pair(50,34),make_pair(54,26),make_pair(34,10)};
vector<string> immune[8];
int isimmune(int x,int y)
{
	for(int i=0;i<8;i++)
	{
		if(immune_cells[i].first==x && immune_cells[i].second==y)
		{
			return i;
		}
	}
	return -1;
}
void roll_dice(void);
int findforA(int x,int y)
{
	int i;
	for(i=0;i<=56;i++)
	{
		if(coordinatesforA[i].first==x && coordinatesforA[i].second==y)
			return i;
	}
	return -1;
}
int findforB(int x,int y)
{
	int i;
	for(i=0;i<=56;i++)
	{
		if(coordinatesforB[i].first==x && coordinatesforB[i].second==y)
			return i;
	}
	return -1;
}
int findforD(int x,int y)
{
	int i;
	for(i=0;i<=56;i++)
	{
		if(coordinatesforD[i].first==x && coordinatesforD[i].second==y)
			return i;
	}
	return -1;
}
int findforC(int x,int y)
{
	int i;
	for(i=0;i<=56;i++)
	{
		if(coordinatesforC[i].first==x && coordinatesforC[i].second==y)
			return i;
	}
	return -1;
}
// converts "A1B2" to " A1B2 "
// converts "A1" to "  A1  "
string convertToDisplayString(string s){
	if(s.size()%2 == 1) {
		cout<<"cell content cannot be odd in length";
		return s;
	}
	if(s.size() >= 6) {
		return s.substr(0, 6);
	}
	while(s.size()<6){
		s = " " + s + " ";
	}
	return s;
}
string getUpdatedDisplayString(string initStr, string token, bool addToken) {
	// remove spaces
	string::iterator end_pos = std::remove(initStr.begin(), initStr.end(), ' ');
	initStr.erase(end_pos, initStr.end());
	if(addToken) {
		if(initStr.size()>4){
			cout<<"Cannot add more tokens at same place\n"<<endl;
			return initStr;
		} else {
			initStr += token;	
		}
	} else {
		size_t found = initStr.find(token);
		if (found != string::npos) {
			initStr.erase(found, token.size());
		}
	}
	return convertToDisplayString(initStr);
}
void cutbyA(string present)
{
	int count=0;
	for(int i=0;i<present.size();i++)
	{
		if(present[i]==' ')
			count++;
	}
	if(count==4)
		{}
	else if(count==2)
		{
			cutbyA("  " + present.substr(1,2) + "  ");
			cutbyA("  " + present.substr(3,2) + "  ");
		}
	else if(count==0)
		{
			cutbyA("  " + present.substr(0,2) + "  ");
			cutbyA("  " + present.substr(2,2) + "  ");
			cutbyA("  " + present.substr(4,2) + "  ");
		}
	char nameofplayercut=present[2];
	int numberoftokencut=present[3]-'0';
	if(nameofplayercut=='B')
	{
		if(numberoftokencut==1)
		{
			coordinatesofB[0].first=60-6;
			coordinatesofB[0].second=60-6;
			arr[60-6][60-6]=present;	
		}
		else if(numberoftokencut==2)
		{
			coordinatesofB[1].first=60-6;
			coordinatesofB[1].second=60-6-12;
			arr[60-6][60-6-12]=present;
		}
		else if(numberoftokencut==3)
		{
			coordinatesofB[2].first=60-6-12;
			coordinatesofB[2].second=60-6-12;
			arr[60-6-12][60-6-12]=present;
		}
		else if(numberoftokencut==4)
		{
			coordinatesofB[3].first=60-6-12;
			coordinatesofB[3].second=60-6;
			arr[60-6-12][60-6]=present;
		}
	}
	else if(nameofplayercut=='C')
	{
		if(numberoftokencut==1)
		{
			coordinatesofC[0].first=6;
			coordinatesofC[0].second=60-6;
			arr[6][60-6]=present;	
		}
		else if(numberoftokencut==2)
		{
			coordinatesofC[1].first=6;
			coordinatesofC[1].second=60-6-12;
			arr[6][60-6-12]=present;
		}
		else if(numberoftokencut==3)
		{
			coordinatesofC[2].first=6+12;
			coordinatesofC[2].second=60-6-12;
			arr[6+12][60-6-12]=present;
		}
		else if(numberoftokencut==4)
		{
			coordinatesofC[3].first=6+12;
			coordinatesofC[3].second=60-6;
			arr[6+12][60-6]=present;
		}
	}
	else if(nameofplayercut=='D')
	{
		if(numberoftokencut==1)
		{
			coordinatesofD[0].first=60-6;
			coordinatesofD[0].second=6;
			arr[60-6][6]=present;	
		}
		else if(numberoftokencut==2)
		{
			coordinatesofD[1].first=60-6;
			coordinatesofD[1].second=6+12;
			arr[60-6][6+12]=present;
		}
		else if(numberoftokencut==3)
		{
			coordinatesofD[2].first=60-6-12;
			coordinatesofD[2].second=6+12;
			arr[60-6-12][6+12]=present;
		}
		else if(numberoftokencut==4)
		{
			coordinatesofD[3].first=60-6-12;
			coordinatesofD[3].second=6;
			arr[60-6-12][6]=present;
		}
	}
}
void cutbyB(string present)
{
	int count=0;
	for(int i=0;i<present.size();i++)
	{
		if(present[i]==' ')
			count++;
	}
	if(count==4)
		{}
	else if(count==2)
		{
			cutbyB("  " + present.substr(1,2) + "  ");
			cutbyB("  " + present.substr(3,2) + "  ");
		}
	else if(count==0)
		{
			cutbyB("  " + present.substr(0,2) + "  ");
			cutbyB("  " + present.substr(2,2) + "  ");
			cutbyB("  " + present.substr(4,2) + "  ");
		}
	char nameofplayercut=present[2];
	int numberoftokencut=present[3]-'0';
	if(nameofplayercut=='A')
	{
		if(numberoftokencut==1)
		{
			coordinatesofA[0].first=6;
			coordinatesofA[0].second=6;
			arr[6][6]=present;	
		}
		else if(numberoftokencut==2)
		{
			coordinatesofA[1].first=6;
			coordinatesofA[1].second=6+12;
			arr[6][6+12]=present;
		}
		else if(numberoftokencut==3)
		{
			coordinatesofA[2].first=6+12;
			coordinatesofA[2].second=6+12;
			arr[6+12][6+12]=present;
		}
		else if(numberoftokencut==4)
		{
			coordinatesofA[3].first=6+12;
			coordinatesofA[3].second=6;
			arr[6+12][6]=present;
		}
	}
	else if(nameofplayercut=='C')
	{
		if(numberoftokencut==1)
		{
			coordinatesofC[0].first=6;
			coordinatesofC[0].second=60-6;
			arr[6][60-6]=present;	
		}
		else if(numberoftokencut==2)
		{
			coordinatesofC[1].first=6;
			coordinatesofC[1].second=60-6-12;
			arr[6][60-6-12]=present;
		}
		else if(numberoftokencut==3)
		{
			coordinatesofC[2].first=6+12;
			coordinatesofC[2].second=60-6-12;
			arr[6+12][60-6-12]=present;
		}
		else if(numberoftokencut==4)
		{
			coordinatesofC[3].first=6+12;
			coordinatesofC[3].second=60-6;
			arr[6+12][60-6]=present;
		}
	}
	else if(nameofplayercut=='D')
	{
		if(numberoftokencut==1)
		{
			coordinatesofD[0].first=60-6;
			coordinatesofD[0].second=6;
			arr[60-6][6]=present;	
		}
		else if(numberoftokencut==2)
		{
			coordinatesofD[1].first=60-6;
			coordinatesofD[1].second=6+12;
			arr[60-6][6+12]=present;
		}
		else if(numberoftokencut==3)
		{
			coordinatesofD[2].first=60-6-12;
			coordinatesofD[2].second=6+12;
			arr[60-6-12][6+12]=present;
		}
		else if(numberoftokencut==4)
		{
			coordinatesofD[3].first=60-6-12;
			coordinatesofD[3].second=6;
			arr[60-6-12][6]=present;
		}
	}
}
void cutbyC(string present)
{
	int count=0;
	for(int i=0;i<present.size();i++)
	{
		if(present[i]==' ')
			count++;
	}
	if(count==4)
		{}
	else if(count==2)
		{
			cutbyC("  " + present.substr(1,2) + "  ");
			cutbyC("  " + present.substr(3,2) + "  ");
		}
	else if(count==0)
		{
			cutbyC("  " + present.substr(0,2) + "  ");
			cutbyC("  " + present.substr(2,2) + "  ");
			cutbyC("  " + present.substr(4,2) + "  ");
		}
	char nameofplayercut=present[2];
	int numberoftokencut=present[3]-'0';
	if(nameofplayercut=='B')
	{
		if(numberoftokencut==1)
		{
			coordinatesofB[0].first=60-6;
			coordinatesofB[0].second=60-6;
			arr[60-6][60-6]=present;	
		}
		else if(numberoftokencut==2)
		{
			coordinatesofB[1].first=60-6;
			coordinatesofB[1].second=60-6-12;
			arr[60-6][60-6-12]=present;
		}
		else if(numberoftokencut==3)
		{
			coordinatesofB[2].first=60-6-12;
			coordinatesofB[2].second=60-6-12;
			arr[60-6-12][60-6-12]=present;
		}
		else if(numberoftokencut==4)
		{
			coordinatesofB[3].first=60-6-12;
			coordinatesofB[3].second=60-6;
			arr[60-6-12][60-6]=present;
		}
	}
	else if(nameofplayercut=='A')
	{
		if(numberoftokencut==1)
		{
			coordinatesofA[0].first=6;
			coordinatesofA[0].second=6;
			arr[6][6]=present;	
		}
		else if(numberoftokencut==2)
		{
			coordinatesofA[1].first=6;
			coordinatesofA[1].second=6+12;
			arr[6][6+12]=present;
		}
		else if(numberoftokencut==3)
		{
			coordinatesofA[2].first=6+12;
			coordinatesofA[2].second=6+12;
			arr[6+12][6+12]=present;
		}
		else if(numberoftokencut==4)
		{
			coordinatesofA[3].first=6+12;
			coordinatesofA[3].second=6;
			arr[6+12][6]=present;
		}
	}
	else if(nameofplayercut=='D')
	{
		if(numberoftokencut==1)
		{
			coordinatesofD[0].first=60-6;
			coordinatesofD[0].second=6;
			arr[60-6][6]=present;	
		}
		else if(numberoftokencut==2)
		{
			coordinatesofD[1].first=60-6;
			coordinatesofD[1].second=6+12;
			arr[60-6][6+12]=present;
		}
		else if(numberoftokencut==3)
		{
			coordinatesofD[2].first=60-6-12;
			coordinatesofD[2].second=6+12;
			arr[60-6-12][6+12]=present;
		}
		else if(numberoftokencut==4)
		{
			coordinatesofD[3].first=60-6-12;
			coordinatesofD[3].second=6;
			arr[60-6-12][6]=present;
		}
	}
}
void cutbyD(string present)
{
	int count=0;
	for(int i=0;i<present.size();i++)
	{
		if(present[i]==' ')
			count++;
	}
	if(count==4)
		{}
	else if(count==2)
		{
			cutbyD("  " + present.substr(1,2) + "  ");
			cutbyD("  " + present.substr(3,2) + "  ");
		}
	else if(count==0)
		{
			cutbyD("  " + present.substr(0,2) + "  ");
			cutbyD("  " + present.substr(2,2) + "  ");
			cutbyD("  " + present.substr(4,2) + "  ");
		}
	char nameofplayercut=present[2];
	int numberoftokencut=present[3]-'0';
	if(nameofplayercut=='B')
	{
		if(numberoftokencut==1)
		{
			coordinatesofB[0].first=60-6;
			coordinatesofB[0].second=60-6;
			arr[60-6][60-6]=present;	
		}
		else if(numberoftokencut==2)
		{
			coordinatesofB[1].first=60-6;
			coordinatesofB[1].second=60-6-12;
			arr[60-6][60-6-12]=present;
		}
		else if(numberoftokencut==3)
		{
			coordinatesofB[2].first=60-6-12;
			coordinatesofB[2].second=60-6-12;
			arr[60-6-12][60-6-12]=present;
		}
		else if(numberoftokencut==4)
		{
			coordinatesofB[3].first=60-6-12;
			coordinatesofB[3].second=60-6;
			arr[60-6-12][60-6]=present;
		}
	}
	else if(nameofplayercut=='C')
	{
		if(numberoftokencut==1)
		{
			coordinatesofC[0].first=6;
			coordinatesofC[0].second=60-6;
			arr[6][60-6]=present;	
		}
		else if(numberoftokencut==2)
		{
			coordinatesofC[1].first=6;
			coordinatesofC[1].second=60-6-12;
			arr[6][60-6-12]=present;
		}
		else if(numberoftokencut==3)
		{
			coordinatesofC[2].first=6+12;
			coordinatesofC[2].second=60-6-12;
			arr[6+12][60-6-12]=present;
		}
		else if(numberoftokencut==4)
		{
			coordinatesofC[3].first=6+12;
			coordinatesofC[3].second=60-6;
			arr[6+12][60-6]=present;
		}
	}
	else if(nameofplayercut=='A')
	{
		if(numberoftokencut==1)
		{
			coordinatesofA[0].first=6;
			coordinatesofA[0].second=6;
			arr[6][6]=present;	
		}
		else if(numberoftokencut==2)
		{
			coordinatesofA[1].first=6;
			coordinatesofA[1].second=6+12;
			arr[6][6+12]=present;
		}
		else if(numberoftokencut==3)
		{
			coordinatesofA[2].first=6+12;
			coordinatesofA[2].second=6+12;
			arr[6+12][6+12]=present;
		}
		else if(numberoftokencut==4)
		{
			coordinatesofA[3].first=6+12;
			coordinatesofA[3].second=6;
			arr[6+12][6]=present;
		}
	}
}
void create_ludo()
{
	int i,j;
	for(i=0;i<61;i++)
	{
		for(j=0;j<61;j++)
		{
			if(i==0||j==0||i==60||j==60||i==24||i==36||j==24||j==36||i==12||j==12||i==48||j==48)
				{
					arr[i][j]= "*";
					if((j+2)%4==0)
					arr[i][j]+="*****";
				}
			else
			{
				if((j+2)%4==0)
					arr[i][j]="      ";
				else arr[i][j]=" ";
			}
			if(i<24||i>36)
			{
				if((i==4||i==8||i==16||i==20||i==40||i==44||i==52||i==56)&&(j>24&&j<36))
				{
					arr[i][j]="*";
					if((j+2)%4==0)
				    arr[i][j]+="*****";
			    }
				if(j==28||j==32)
				{
					arr[i][j]="*";
					if((j+2)%4==0)
					arr[i][j]+="*****";
				}
			}
			if(j<24||j>36)
			{
				if((j==4||j==8||j==16||j==20||j==40||j==44||j==52||j==56)&&(i>24&&i<36))
				{
					arr[i][j]="*";
					if((j+2)%4==0)
					arr[i][j]+="*****";
				}
				if(i==28||i==32)
				{
					arr[i][j]="*";
					if((j+2)%4==0)
					arr[i][j]+="*****";
			    }
			}
		}
		
	}
}
void display_ludo()
{
	int i,j;
	for(i=0;i<61;i++)
	{
		for(j=0;j<61;j++)
		{
			cout<<arr[i][j];
		}
		cout<<endl;
	}
}
void create_ludo_of_n()
{
	if(number==2)
	{
		arr[6][6]="  A1  ";
		arr[6][6+12]="  A2  ";
		arr[6+12][6]="  A4  ";
		arr[6+12][6+12]="  A3  ";
		arr[60-6][60-6]="  B1  ";
		arr[60-6][60-6-12]="  B2  ";
		arr[60-6-12][60-6]="  B4  ";
		arr[60-6-12][60-6-12]="  B3  ";
		player_finished.push_back(false);
		player_finished.push_back(false);
	}
	else if(number==3)
	{
		arr[6][6]="  A1  ";
		arr[6][6+12]="  A2  ";
		arr[6+12][6]="  A4  ";
		arr[6+12][6+12]="  A3  ";
		arr[60-6][60-6]="  B1  ";
		arr[60-6][60-6-12]="  B2  ";
		arr[60-6-12][60-6]="  B4  ";
		arr[60-6-12][60-6-12]="  B3  ";
		arr[6][60-6]="  C1  ";
		arr[6][60-6-12]="  C2  ";
		arr[6+12][60-6]="  C4  ";
		arr[6+12][60-6-12]="  C3  ";
		player_finished.push_back(false);
		player_finished.push_back(false);
		player_finished.push_back(false);
	}
	else if(number==4)
	{
		arr[6][6]="  A1  ";
		arr[6][6+12]="  A2  ";
		arr[6+12][6]="  A4  ";
		arr[6+12][6+12]="  A3  ";
		arr[60-6][60-6]="  B1  ";
		arr[60-6][60-6-12]="  B2  ";
		arr[60-6-12][60-6]="  B4  ";
		arr[60-6-12][60-6-12]="  B3  ";
		arr[6][60-6]="  C1  ";
		arr[6][60-6-12]="  C2  ";
		arr[6+12][60-6]="  C4  ";
		arr[6+12][60-6-12]="  C3  ";
		arr[60-6][6]="  D1  ";
		arr[60-6][6+12]="  D2  ";
		arr[60-6-12][6]="  D4  ";
		arr[60-6-12][6+12]="  D3  ";
		player_finished.push_back(false);
		player_finished.push_back(false);
		player_finished.push_back(false);
		player_finished.push_back(false);
	}
}
void move_token(int token_number, int places)
{
	char a;
	if(turn==0)
	{
		int initialx=coordinatesofA[token_number-1].first;
		int initialy=coordinatesofA[token_number-1].second;
		string tokenStr = "A"+to_string(token_number); //******
			if((initialx==6||initialx==6+12)&&(initialy==6||initialy==6+12))
			{
				if(places==6||places==1)
		        {
					arr[initialx][initialy]="      ";
					arr[26][6] = getUpdatedDisplayString(arr[26][6], tokenStr, true); //******
					coordinatesofA[token_number-1].first=26;
					coordinatesofA[token_number-1].second=6;
		        }
		        else 
		        {
		        	cout<<"Can't move the token\n";
		        }
		    }
		    else
		    {
				int index=findforA(initialx,initialy);
				// string temp1=arr[initialx][initialy];  //******
				if(index+places<=56)
				{
					int finalx=coordinatesforA[index+places].first;
				    int finaly=coordinatesforA[index+places].second;
				    string temp2=arr[finalx][finaly];
				    arr[initialx][initialy] = getUpdatedDisplayString(arr[initialx][initialy], tokenStr, false); //******
				    if((temp2=="      ")|| (temp2.find('B')==-1 && temp2.find('C')==-1 && temp2.find('D')==-1 ))
				    {
				        // arr[initialx][initialy]=temp2; //******
				        // arr[finalx][finaly]=temp1;  //******
				        arr[finalx][finaly] = getUpdatedDisplayString(arr[finalx][finaly], tokenStr, true);
				        coordinatesofA[token_number-1].first=finalx;
				        coordinatesofA[token_number-1].second=finaly;	
				    }
				    else
				    {
				    	string present = temp2;
				    	if(isimmune(finalx, finaly) == -1) { //******
				    		cutbyA(present); //check for multiple tokens for B, C and D on a single place
				    		arr[finalx][finaly] = "  " + tokenStr + "  ";
					    	//arr[finalx][finaly] = getUpdatedDisplayString(arr[finalx][finaly], temp2, false); //******
					    	//arr[finalx][finaly] = getUpdatedDisplayString(arr[finalx][finaly], tokenStr, true); //******
					    	display_ludo();
					    	vector<int>tempmoves;
					    	cout<<name[turn]<<" got another chance\nRoll dice again(Enter $) ";
					    	cin>>a;
					    	if(a=='$')
					    	{
					    		int ch;
								char temp;
								srand(time(0));
								ch=(rand()%6)+1;
								while(ch==6)
								{
									tempmoves.push_back(ch);
									cout<<name[turn]<<" scored "<<ch<<"\n";
									cout<<"Roll dice again(Enter $)\n";
									cin>>temp;
									if(temp=='$')
									{
										srand(time(0));
								        ch=(rand()%6)+1;
									}
									else {
										exit(1);
									}
								}
								cout<<name[turn]<<" scored "<<ch<<"\n";
								tempmoves.push_back(ch);
								int temptoken;
								int size=tempmoves.size();
								for(int i=0;i<size;i++)
								{
									cout<<"Enter the token you want to move for "<<tempmoves[i]<<"\n";
									cin>>temptoken;
									moves.push(tempmoves[i]);
									number_of_dice.push(temptoken);
								}
					    	}
					    	else exit(1);
				    	} else { //****** 
				    		arr[finalx][finaly] = getUpdatedDisplayString(arr[finalx][finaly], tokenStr, true); //****** 
				    		coordinatesofB[token_number-1].first=finalx;
				        	coordinatesofB[token_number-1].second=finaly;
				    	}
				    }
				    if(index+places==56)
				    {
						Afinished++;
						if(Afinished==4)
						{
							cout<<name[turn]<<" secured "<<number_of_players_finished+1<<" position";
							player_finished[0]=true;
							number_of_players_finished++;
						}
					}
				}
				else
				{
					cout<<"Can't move this token";
			    }    
		    }
	}
	else if(turn==1)
	{

		int initialx=coordinatesofB[token_number-1].first;
		int initialy=coordinatesofB[token_number-1].second;
		string tokenStr = "B"+to_string(token_number); //******
			if((initialx==60-6||initialx==60-6-12)&&(initialy==60-6||initialy==60-6-12))
			{
				if(places==6||places==1)
		        {
					arr[initialx][initialy]="      ";
					arr[34][54]=getUpdatedDisplayString(arr[34][54], tokenStr, true); //******
					coordinatesofB[token_number-1].first=34;
					coordinatesofB[token_number-1].second=54;
		        }
		        else 
		        {
		        	cout<<"Can't move the token\n";
		        }
	        }
		    else
		    {
				int index=findforB(initialx,initialy);
				// string temp1=arr[initialx][initialy];
				if(index+places<=56)
				{
					int finalx=coordinatesforB[index+places].first;
				    int finaly=coordinatesforB[index+places].second;
				    string temp2=arr[finalx][finaly];
				    arr[initialx][initialy] = getUpdatedDisplayString(arr[initialx][initialy], tokenStr, false); //******
				    if((temp2=="      ")|| (temp2.find('A')==-1 && temp2.find('C')==-1 && temp2.find('D')==-1 ))
				    {
				        arr[finalx][finaly] = getUpdatedDisplayString(arr[finalx][finaly], tokenStr, true);
				        coordinatesofB[token_number-1].first=finalx;
				        coordinatesofB[token_number-1].second=finaly;		
				    }
				    else
				    {
				    	string present = temp2;
				    	if(isimmune(finalx, finaly) == -1) { //******
				    		cutbyB(present); //check for multiple tokens for B, C and D on a single place
				    		arr[finalx][finaly] = "  " + tokenStr + "  ";
					    	// arr[finalx][finaly] = getUpdatedDisplayString(arr[finalx][finaly], temp2, false); //******
					    	// arr[finalx][finaly] = getUpdatedDisplayString(arr[finalx][finaly], tokenStr, true); //******
					    	display_ludo();
					    	vector<int>tempmoves;
					    	cout<<name[turn]<<" got another chance\nRoll dice again(Enter $) ";
					    	cin>>a;
					    	if(a=='$')
					    	{
					    		int ch;
								char temp;
								srand(time(0));
								ch=(rand()%6)+1;
								while(ch==6)
								{
									tempmoves.push_back(ch);
									cout<<name[turn]<<" scored "<<ch<<"\n";
									cout<<"Roll dice again(Enter $)\n";
									cin>>temp;
									if(temp=='$')
									{
										srand(time(0));
								        ch=(rand()%6)+1;
									}
									else {
										exit(1);
									}
								}
								cout<<name[turn]<<" scored "<<ch<<"\n";
								tempmoves.push_back(ch);
								int temptoken;
								int size=tempmoves.size();
								for(int i=0;i<size;i++)
								{
									cout<<"Enter the token you want to move for "<<tempmoves[i]<<"\n";
									cin>>temptoken;
									moves.push(tempmoves[i]);
									number_of_dice.push(temptoken);
								}
					    	}
					    	else exit(1);
				    	} else { //****** 
				    		arr[finalx][finaly] = getUpdatedDisplayString(arr[finalx][finaly], tokenStr, true); //******
				    		coordinatesofB[token_number-1].first=finalx;
				        	coordinatesofB[token_number-1].second=finaly;
				    	}
				    }
				    if(index+places==56)
				    {
					    Bfinished++;
						if(Bfinished==4)
						{
							cout<<name[turn]<<" secured "<<number_of_players_finished+1<<" position";
							player_finished[0]=true;
							number_of_players_finished++;
						}
				    }
				}
				else
				{
					cout<<"Can't move this token";
				}    
		    }
	}
	else if (turn==2)
	{

		int initialx=coordinatesofC[token_number-1].first;
		int initialy=coordinatesofC[token_number-1].second;
		string tokenStr = "C"+to_string(token_number); //******
			if((initialx==6||initialx==6+12)&&(initialy==60-6||initialy==60-6-12))
			{
					if(places==6||places==1)
			        {
						arr[initialx][initialy]="      ";
						arr[6][34]=getUpdatedDisplayString(arr[6][34], tokenStr, true); //******;
						coordinatesofC[token_number-1].first=6;
						coordinatesofC[token_number-1].second=34;
			        }
			        else 
			        {
			        	cout<<"Can't move the token\n";
			        }
		    }
			else
			{
				int index=findforC(initialx,initialy);
				// string temp1=arr[initialx][initialy];
				if(index+places<=56)
				{
					int finalx=coordinatesforC[index+places].first;
				    int finaly=coordinatesforC[index+places].second;
				    string temp2=arr[finalx][finaly];
				    arr[initialx][initialy] = getUpdatedDisplayString(arr[initialx][initialy], tokenStr, false); //******
				    if((temp2=="      ")||(temp2.find('A')==-1 && temp2.find('B')==-1 && temp2.find('D')==-1 ))
				    {
				        arr[finalx][finaly] = getUpdatedDisplayString(arr[finalx][finaly], tokenStr, true);
				        coordinatesofC[token_number-1].first=finalx;
				        coordinatesofC[token_number-1].second=finaly;	
				    }
				    else
				    {
				    	string present = temp2;
				    	if(isimmune(finalx, finaly) == -1) { //******
				    		display_ludo();
				    		cutbyC(present); //check for multiple tokens for B, C and D on a single place
				    		arr[finalx][finaly] = "  " + tokenStr + "  ";
					    	// arr[finalx][finaly] = getUpdatedDisplayString(arr[finalx][finaly], temp2, false); //******
					    	// arr[finalx][finaly] = getUpdatedDisplayString(arr[finalx][finaly], tokenStr, true); //******
					    	vector<int>tempmoves;
					    	cout<<name[turn]<<" got another chance\nRoll dice again(Enter $) ";
					    	cin>>a;
					    	if(a=='$')
					    	{
					    		int ch;
								char temp;
								srand(time(0));
								ch=(rand()%6)+1;
								while(ch==6)
								{
									tempmoves.push_back(ch);
									cout<<name[turn]<<" scored "<<ch<<"\n";
									cout<<"Roll dice again(Enter $)\n";
									cin>>temp;
									if(temp=='$')
									{
										srand(time(0));
								        ch=(rand()%6)+1;
									}
									else {
										exit(1);
									}
								}
								cout<<name[turn]<<" scored "<<ch<<"\n";
								tempmoves.push_back(ch);
								int temptoken;
								int size=tempmoves.size();
								for(int i=0;i<size;i++)
								{
									cout<<"Enter the token you want to move for "<<tempmoves[i]<<"\n";
									cin>>temptoken;
									moves.push(tempmoves[i]);
									number_of_dice.push(temptoken);
								}
					    	}
					    	else exit(1);
				    	} else { //****** 
				    		arr[finalx][finaly] = getUpdatedDisplayString(arr[finalx][finaly], tokenStr, true); //****** 
				    		coordinatesofB[token_number-1].first=finalx;
				         	coordinatesofB[token_number-1].second=finaly;
				    	}
				    }
				    if(index+places==56)
				    {
					    Cfinished++;
						if(Cfinished==4)
						{
							cout<<name[turn]<<" secured "<<number_of_players_finished+1<<" position";
							player_finished[0]=true;
							number_of_players_finished++;
						}
				    }
				}
				else
				{
					cout<<"Can't move this token";
				}    
		    }
	}
	else if(turn==3)
	{

		int initialx=coordinatesofD[token_number-1].first;
		int initialy=coordinatesofD[token_number-1].second;
		string tokenStr = "D"+to_string(token_number); //******
		arr[initialx][initialy] = getUpdatedDisplayString(arr[initialx][initialy], tokenStr, false); //******
			if((initialx==60-6||initialx==60-6-12)&&(initialy==6||initialy==6+12))
			{
				if(places==6||places==1)
		        {
					arr[initialx][initialy]="      ";
					arr[54][26]=getUpdatedDisplayString(arr[54][26], tokenStr, true); //******;;
					coordinatesofD[token_number-1].first=54;
					coordinatesofD[token_number-1].second=26;
			    }
			    else 
			    {
			   		cout<<"Can't move the token\n";
			   	}
		    }
			else
			{
				int index=findforD(initialx,initialy);
				// string temp1=arr[initialx][initialy];
				if(index+places<=56)
				{
					int finalx=coordinatesforD[index+places].first;
				    int finaly=coordinatesforD[index+places].second;
				    string temp2=arr[finalx][finaly];
				    arr[initialx][initialy] = getUpdatedDisplayString(arr[initialx][initialy], tokenStr, false); //******
				    if((temp2=="      ")||(temp2.find('A')==-1 && temp2.find('B')==-1 && temp2.find('C')==-1 ))
				    {
				        arr[finalx][finaly] = getUpdatedDisplayString(arr[finalx][finaly], tokenStr, true);
				        coordinatesofD[token_number-1].first=finalx;
				        coordinatesofD[token_number-1].second=finaly;	
				    }
				    else
				    {
				    	string present = temp2;
				    	if(isimmune(finalx, finaly) == -1) { //******
				    		cutbyD(present); //check for multiple tokens for B, C and D on a single place
				    		arr[finalx][finaly] = "  " + tokenStr + "  ";
					    	// arr[finalx][finaly] = getUpdatedDisplayString(arr[finalx][finaly], temp2, false); //******
					    	// arr[finalx][finaly] = getUpdatedDisplayString(arr[finalx][finaly], tokenStr, true); //******
					    	display_ludo();
					    	vector<int>tempmoves;
					    	cout<<name[turn]<<" got another chance\nRoll dice again(Enter $) ";
					    	cin>>a;
					    	if(a=='$')
					    	{
					    		int ch;
								char temp;
								srand(time(0));
								ch=(rand()%6)+1;
								while(ch==6)
								{
									tempmoves.push_back(ch);
									cout<<name[turn]<<" scored "<<ch<<"\n";
									cout<<"Roll dice again(Enter $)\n";
									cin>>temp;
									if(temp=='$')
									{
										srand(time(0));
								        ch=(rand()%6)+1;
									}
									else {
										exit(1);
									}
								}
								cout<<name[turn]<<" scored "<<ch<<"\n";
								tempmoves.push_back(ch);
								int temptoken;
								int size=tempmoves.size();
								for(int i=0;i<size;i++)
								{
									cout<<"Enter the token you want to move for "<<tempmoves[i]<<"\n";
									cin>>temptoken;
									moves.push(tempmoves[i]);
									number_of_dice.push(temptoken);
								}
					    	}
					    	else exit(1);
				    	} else { //****** 
				    		arr[finalx][finaly] = getUpdatedDisplayString(arr[finalx][finaly], tokenStr, true); //****** 
				    		coordinatesofB[token_number-1].first=finalx;
				        	coordinatesofB[token_number-1].second=finaly;
				    	}
				    }
				    if(index+places==56)
				    {
					    Dfinished++;
						if(Dfinished==4)
						{
							cout<<name[turn]<<" secured "<<number_of_players_finished+1<<" position";
							player_finished[0]=true;
							number_of_players_finished++;
						}
				    }
				}
				else
				{
					cout<<"Can't move this token";
				}    
		    }
	}
}
void do_moves()
{
	queue<int> moves_copy;
	moves_copy=moves;
	while(!moves_copy.empty())
	{
		int token_number;
		cout<<"Enter the token number you want to move for "<<moves_copy.front()<<'\n';
		cin>>token_number;
		number_of_dice.push(token_number);
		moves_copy.pop();
	}
	while(!moves.empty())
	{
		move_token(number_of_dice.front(),moves.front());
		number_of_dice.pop();
		moves.pop();
	}
}
void roll_dice()
{
	int ch;
	char temp;
	srand(time(0));
	ch=(rand()%6)+1;
	cout<<name[turn]<<" scored "<<ch<<"\n";
	while(ch==6)
	{
		moves.push(ch);
		cout<<"Roll dice again(Enter $)\n";
		cin>>temp;
		if(temp=='$')
		{
			srand(time(0));
	        ch=(rand()%6)+1;
	        cout<<name[turn]<<" scored "<<ch<<"\n";
		}
		else {
			exit(1);
		}
	}
	moves.push(ch);
	do_moves();
}

int main()
{
	char choice;
	int temp_num;
	string temp_name;
	int temp;
	cout<<"Enter the number of players(2-4)\n";
	cin>>temp;
	number=temp;
	temp_num=0;
	create_ludo();
	create_ludo_of_n();
	display_ludo();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
    while(temp_num<number)
    {
    	cout<<"Enter "<<temp_num+1<<" player's name\n";
    	getline(cin,temp_name);
    	name.push_back(temp_name);
    	temp_num++;
    }
    display_ludo();
    while(number_of_players_finished<number)
    {
    	cout<<name[turn]<<"'s turn\n";
    	cout<<"press $ to roll a dice";
    	cin>>choice;
    	if(choice!='$')
    		exit(1);
    	else roll_dice();
    	display_ludo();
    	while(player_finished[(turn+1)%number]!=false)
			{turn=(turn+1)%(number);}
		turn=(turn+1)%(number);
		if(number_of_players_finished==number-1)
		{
			last=turn;
			number_of_players_finished++;
		}
    }
    cout<<name[turn]<<" finished at last position";
    return 0;
}