#include <iostream>
#include <vector>

using namespace std;

enum PlayerClassEnum
{
	Mele,
	Range
};

struct PlayerInfo
{
	int PlayerID;
	PlayerClassEnum PlayerClass ;
	float MeleDamage;
	float RangeDamage;
};

int MostPowerPlayerID(const vector<PlayerInfo>& PlayerInfoInput);
int MostPowerPlayerIDInClass(const vector <PlayerInfo>& PlayerInfoInput, PlayerClassEnum PlayerClass);

int main()
{
	vector <PlayerInfo> PlayerInfoVector = 
	{	
		{1, Mele, 25,20},
		{2, Range, 99,35},
		{3, Mele, 18, 5},
		{4, Mele, 45,75},
		{5, Range,13,12},
		{6, Range, 10,8}	
	};
	
	cout << "Max damage Player have ID: " << MostPowerPlayerID(PlayerInfoVector) << endl;

	int MostPowerfulMelePlayerID = (MostPowerPlayerIDInClass(PlayerInfoVector, Mele));
	int MostPowerfulRangePlayerID = (MostPowerPlayerIDInClass(PlayerInfoVector, Range));

	cout << "Most power mele: " << MostPowerfulMelePlayerID << endl;

	cout << "Most power ranger: " << MostPowerfulRangePlayerID << endl;

	return 0;
}

int MostPowerPlayerID(const vector<PlayerInfo>& PlayerInfoInput)
{
	
	float ComparebleDamage = 0;
	int MaxDamagePlayerID = -1;

	for (const PlayerInfo& info : PlayerInfoInput)
	{
		float TotalDamage = info.MeleDamage + info.RangeDamage;
		if (TotalDamage > ComparebleDamage)
		{
			ComparebleDamage = TotalDamage;
			MaxDamagePlayerID = info.PlayerID;
		}

	}
	return MaxDamagePlayerID;
}

int MostPowerPlayerIDInClass(const vector <PlayerInfo>& PlayerInfoInput, PlayerClassEnum PlayerClass)
{
	float ComparebleDamage = 0;
	int MaxDamagePlayerID = -1;

	for (const PlayerInfo& info : PlayerInfoInput)
	{
		float TotalDamage = info.MeleDamage + info.RangeDamage;

		if (info.PlayerClass == PlayerClass)
		{
			if (TotalDamage > ComparebleDamage)
			{
				ComparebleDamage = TotalDamage;
				MaxDamagePlayerID = info.PlayerID;
			}
		}
	}
	return MaxDamagePlayerID;
}
