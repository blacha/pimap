#ifndef _AreaLevel_h__
#define _AreaLevel_h__
//tolua_begin
namespace ActLocation
{
	enum ActLocation
	{
		Act1		= 0,
		Act2		= 1,
		Act3		= 2,
		Act4		= 3,
		Act5		= 4,
	};
};

namespace WaypointDestination
{
	enum WaypointDestination
	{
		CloseWaypoint = 0x00,
		RogueEncampment = 0x01,
		ColdPlains = 0x03,
		StonyField = 0x04,
		DarkWood = 0x05,
		BlackMarsh = 0x06,
		OuterCloister = 0x1B,
		JailLevel1 = 0x1D,
		InnerCloister = 0x20,
		CatacombsLevel2 = 0x23,
		LutGholein = 0x28,
		LutGholeinSewersLevel2 = 0x30,
		DryHills = 0x2A,
		HallsOfTheDeadLevel2 = 0x39,
		FarOasis = 0x2B,
		LostCity = 0x2C,
		PalaceCellarLevel1 = 0x34,
		ArcaneSanctuary = 0x4A,
		CanyonOfTheMagi = 0x2E,
		KurastDocks = 0x4B,
		SpiderForest = 0x4C,
		GreatMarsh = 0x4D,
		FlayerJungle = 0x4E,
		LowerKurast = 0x4F,
		KurastBazaar = 0x50,
		UpperKurast = 0x51,
		Travincial = 0x53,
		DuranceOfHateLevel2 = 0x65,
		ThePandemoniumFortress = 0x67,
		CityOfTheDamned = 0x6A,
		RiverOfFlame = 0x6B,
		Harrogath = 0x6D,
		FrigidHighlands = 0x6F,
		ArreatPlateau = 0x70,
		CrystallinePassage = 0x71,
		GlacialTrail = 0x73,
		HallsOfPain = 0x7B,
		FrozenTundra = 0x75,
		TheAncientsWay = 0x76,
		WorldstoneKeepLevel2 = 0x81,
	};
};

namespace AreaLevel
{
	enum AreaLevel
	{
		Abaddon = 0x7d,
		AncientTunnels = 0x41,
		ArcaneSanctuary = 0x4a,
		ArreatPlateau = 0x70,
		ArreatSummit = 120,
		Barracks = 0x1c,
		BlackMarsh = 6,
		BloodMoor = 2,
		BloodyFoothills = 110,
		BurialGrounds = 0x11,
		CanyonOfTheMagi = 0x2e,
		CatacombsLevel1 = 0x22,
		CatacombsLevel2 = 0x23,
		CatacombsLevel3 = 0x24,
		CatacombsLevel4 = 0x25,
		Cathedral = 0x21,
		CaveLevel1 = 9,
		CaveLevel2 = 13,
		ChaosSanctuary = 0x6c,
		CityOfTheDamned = 0x6a,
		ClawViperTempleLevel1 = 0x3a,
		ClawViperTempleLevel2 = 0x3d,
		ColdPlains = 3,
		Crypt = 0x12,
		CrystallinePassage = 0x71,
		DarkWood = 5,
		DenOfEvil = 8,
		DisusedFane = 0x5f,
		DisusedReliquary = 0x63,
		DrifterCavern = 0x74,
		DryHills = 0x2a,
		DuranceOfHateLevel1 = 100,
		DuranceOfHateLevel2 = 0x65,
		DuranceOfHateLevel3 = 0x66,
		DurielsLair = 0x49,
		FarOasis = 0x2b,
		FlayerDungeonLevel1 = 0x58,
		FlayerDungeonLevel2 = 0x59,
		FlayerDungeonLevel3 = 0x5b,
		FlayerJungle = 0x4e,
		ForgottenReliquary = 0x60,
		ForgottenSands = 0x86,
		ForgottenTemple = 0x61,
		ForgottenTower = 20,
		FrigidHighlands = 0x6f,
		FrozenRiver = 0x72,
		FrozenTundra = 0x75,
		FurnaceOfPain = 0x87,
		GlacialTrail = 0x73,
		GreatMarsh = 0x4d,
		HallsOfAnguish = 0x7a,
		HallsOfPain = 0x7b,
		HallsOfTheDeadLevel1 = 0x38,
		HallsOfTheDeadLevel2 = 0x39,
		HallsOfTheDeadLevel3 = 0x3c,
		HallsOfVaught = 0x7c,
		HaremLevel1 = 50,
		HaremLevel2 = 0x33,
		Harrogath = 0x6d,
		HoleLevel1 = 11,
		HoleLevel2 = 15,
		IcyCellar = 0x77,
		InfernalPit = 0x7f,
		InnerCloister = 0x20,
		JailLevel1 = 0x1d,
		JailLevel2 = 30,
		JailLevel3 = 0x1f,
		KurastBazaar = 80,
		KurastCauseway = 0x52,
		KurastDocks = 0x4b,
		LostCity = 0x2c,
		LowerKurast = 0x4f,
		LutGholein = 40,
		MaggotLairLevel1 = 0x3e,
		MaggotLairLevel2 = 0x3f,
		MaggotLairLevel3 = 0x40,
		MatronsDen = 0x85,
		Mausoleum = 0x13,
		MonasteryGate = 0x1a,
		MooMooFarm = 0x27,
		NihlathaksTemple = 0x79,
		None = 0,
		OuterCloister = 0x1b,
		OuterSteppes = 0x68,
		PalaceCellarLevel1 = 0x34,
		PalaceCellarLevel2 = 0x35,
		PalaceCellarLevel3 = 0x36,
		PitLevel1 = 12,
		PitLevel2 = 0x10,
		PitOfAcheron = 0x7e,
		PlainsOfDespair = 0x69,
		RiverOfFlame = 0x6b,
		RockyWaste = 0x29,
		RogueEncampment = 1,
		RuinedFane = 0x62,
		RuinedTemple = 0x5e,
		SewersLevel1Act2 = 0x2f,
		SewersLevel1Act3 = 0x5c,
		SewersLevel2Act2 = 0x30,
		SewersLevel2Act3 = 0x5d,
		SewersLevel3Act2 = 0x31,
		SpiderCave = 0x54,
		SpiderCavern = 0x55,
		SpiderForest = 0x4c,
		StonyField = 4,
		StonyTombLevel1 = 0x37,
		StonyTombLevel2 = 0x3b,
		SwampyPitLevel1 = 0x56,
		SwampyPitLevel2 = 0x57,
		SwampyPitLevel3 = 90,
		TalRashasTomb1 = 0x42,
		TalRashasTomb2 = 0x43,
		TalRashasTomb3 = 0x44,
		TalRashasTomb4 = 0x45,
		TalRashasTomb5 = 70,
		TalRashasTomb6 = 0x47,
		TalRashasTomb7 = 0x48,
		TamoeHighland = 7,
		TheAncientsWay = 0x76,
		ThePandemoniumFortress = 0x67,
		TheWorldstoneChamber = 0x84,
		TheWorldStoneKeepLevel1 = 0x80,
		TheWorldStoneKeepLevel2 = 0x81,
		TheWorldStoneKeepLevel3 = 130,
		ThroneOfDestruction = 0x83,
		TowerCellarLevel1 = 0x15,
		TowerCellarLevel2 = 0x16,
		TowerCellarLevel3 = 0x17,
		TowerCellarLevel4 = 0x18,
		TowerCellarLevel5 = 0x19,
		Travincal = 0x53,
		Tristram = 0x26,
		UberTristram = 0x88,
		UndergroundPassageLevel1 = 10,
		UndergroundPassageLevel2 = 14,
		UpperKurast = 0x51,
		ValleyOfSnakes = 0x2d,
		Map1 = 137,
		Map2 = 138,
		Map3 = 139,
		Map4 = 140,
		Map5 = 141
	};

	static std::string toString(AreaLevel input)
	{
		switch (input)
		{
			case Abaddon: return "Abaddon";
			case AncientTunnels: return "AncientTunnels";
			case ArcaneSanctuary: return "ArcaneSanctuary";
			case ArreatPlateau: return "ArreatPlateau";
			case ArreatSummit: return "ArreatSummit";
			case Barracks: return "Barracks";
			case BlackMarsh: return "BlackMarsh";
			case BloodMoor: return "BloodMoor";
			case BloodyFoothills: return "BloodyFoothills";
			case BurialGrounds: return "BurialGrounds";
			case CanyonOfTheMagi: return "CanyonOfTheMagi";
			case CatacombsLevel1: return "CatacombsLevel1";
			case CatacombsLevel2: return "CatacombsLevel2";
			case CatacombsLevel3: return "CatacombsLevel3";
			case CatacombsLevel4: return "CatacombsLevel4";
			case Cathedral: return "Cathedral";
			case CaveLevel1: return "CaveLevel1";
			case CaveLevel2: return "CaveLevel2";
			case ChaosSanctuary: return "ChaosSanctuary";
			case CityOfTheDamned: return "CityOfTheDamned";
			case ClawViperTempleLevel1: return "ClawViperTempleLevel1";
			case ClawViperTempleLevel2: return "ClawViperTempleLevel2";
			case ColdPlains: return "ColdPlains";
			case Crypt: return "Crypt";
			case CrystallinePassage: return "CrystallinePassage";
			case DarkWood: return "DarkWood";
			case DenOfEvil: return "DenOfEvil";
			case DisusedFane: return "DisusedFane";
			case DisusedReliquary: return "DisusedReliquary";
			case DrifterCavern: return "DrifterCavern";
			case DryHills: return "DryHills";
			case DuranceOfHateLevel1: return "DuranceOfHateLevel1";
			case DuranceOfHateLevel2: return "DuranceOfHateLevel2";
			case DuranceOfHateLevel3: return "DuranceOfHateLevel3";
			case DurielsLair: return "DurielsLair";
			case FarOasis: return "FarOasis";
			case FlayerDungeonLevel1: return "FlayerDungeonLevel1";
			case FlayerDungeonLevel2: return "FlayerDungeonLevel2";
			case FlayerDungeonLevel3: return "FlayerDungeonLevel3";
			case FlayerJungle: return "FlayerJungle";
			case ForgottenReliquary: return "ForgottenReliquary";
			case ForgottenSands: return "ForgottenSands";
			case ForgottenTemple: return "ForgottenTemple";
			case ForgottenTower: return "ForgottenTower";
			case FrigidHighlands: return "FrigidHighlands";
			case FrozenRiver: return "FrozenRiver";
			case FrozenTundra: return "FrozenTundra";
			case FurnaceOfPain: return "FurnaceOfPain";
			case GlacialTrail: return "GlacialTrail";
			case GreatMarsh: return "GreatMarsh";
			case HallsOfAnguish: return "HallsOfAnguish";
			case HallsOfPain: return "HallsOfPain";
			case HallsOfTheDeadLevel1: return "HallsOfTheDeadLevel1";
			case HallsOfTheDeadLevel2: return "HallsOfTheDeadLevel2";
			case HallsOfTheDeadLevel3: return "HallsOfTheDeadLevel3";
			case HallsOfVaught: return "HallsOfVaught";
			case HaremLevel1: return "HaremLevel1";
			case HaremLevel2: return "HaremLevel2";
			case Harrogath: return "Harrogath";
			case HoleLevel1: return "HoleLevel1";
			case HoleLevel2: return "HoleLevel2";
			case IcyCellar: return "IcyCellar";
			case InfernalPit: return "InfernalPit";
			case InnerCloister: return "InnerCloister";
			case JailLevel1: return "JailLevel1";
			case JailLevel2: return "JailLevel2";
			case JailLevel3: return "JailLevel3";
			case KurastBazaar: return "KurastBazaar";
			case KurastCauseway: return "KurastCauseway";
			case KurastDocks: return "KurastDocks";
			case LostCity: return "LostCity";
			case LowerKurast: return "LowerKurast";
			case LutGholein: return "LutGholein";
			case MaggotLairLevel1: return "MaggotLairLevel1";
			case MaggotLairLevel2: return "MaggotLairLevel2";
			case MaggotLairLevel3: return "MaggotLairLevel3";
			case MatronsDen: return "MatronsDen";
			case Mausoleum: return "Mausoleum";
			case MonasteryGate: return "MonasteryGate";
			case MooMooFarm: return "MooMooFarm";
			case NihlathaksTemple: return "NihlathaksTemple";
			case None: return "None";
			case OuterCloister: return "OuterCloister";
			case OuterSteppes: return "OuterSteppes";
			case PalaceCellarLevel1: return "PalaceCellarLevel1";
			case PalaceCellarLevel2: return "PalaceCellarLevel2";
			case PalaceCellarLevel3: return "PalaceCellarLevel3";
			case PitLevel1: return "PitLevel1";
			case PitLevel2: return "PitLevel2";
			case PitOfAcheron: return "PitOfAcheron";
			case PlainsOfDespair: return "PlainsOfDespair";
			case RiverOfFlame: return "RiverOfFlame";
			case RockyWaste: return "RockyWaste";
			case RogueEncampment: return "RogueEncampment";
			case RuinedFane: return "RuinedFane";
			case RuinedTemple: return "RuinedTemple";
			case SewersLevel1Act2: return "SewersLevel1Act2";
			case SewersLevel1Act3: return "SewersLevel1Act3";
			case SewersLevel2Act2: return "SewersLevel2Act2";
			case SewersLevel2Act3: return "SewersLevel2Act3";
			case SewersLevel3Act2: return "SewersLevel3Act2";
			case SpiderCave: return "SpiderCave";
			case SpiderCavern: return "SpiderCavern";
			case SpiderForest: return "SpiderForest";
			case StonyField: return "StonyField";
			case StonyTombLevel1: return "StonyTombLevel1";
			case StonyTombLevel2: return "StonyTombLevel2";
			case SwampyPitLevel1: return "SwampyPitLevel1";
			case SwampyPitLevel2: return "SwampyPitLevel2";
			case SwampyPitLevel3: return "SwampyPitLevel3";
			case TalRashasTomb1: return "TalRashasTomb1";
			case TalRashasTomb2: return "TalRashasTomb2";
			case TalRashasTomb3: return "TalRashasTomb3";
			case TalRashasTomb4: return "TalRashasTomb4";
			case TalRashasTomb5: return "TalRashasTomb5";
			case TalRashasTomb6: return "TalRashasTomb6";
			case TalRashasTomb7: return "TalRashasTomb7";
			case TamoeHighland: return "TamoeHighland";
			case TheAncientsWay: return "TheAncientsWay";
			case ThePandemoniumFortress: return "ThePandemoniumFortress";
			case TheWorldstoneChamber: return "TheWorldstoneChamber";
			case TheWorldStoneKeepLevel1: return "TheWorldStoneKeepLevel1";
			case TheWorldStoneKeepLevel2: return "TheWorldStoneKeepLevel2";
			case TheWorldStoneKeepLevel3: return "TheWorldStoneKeepLevel3";
			case ThroneOfDestruction: return "ThroneOfDestruction";
			case TowerCellarLevel1: return "TowerCellarLevel1";
			case TowerCellarLevel2: return "TowerCellarLevel2";
			case TowerCellarLevel3: return "TowerCellarLevel3";
			case TowerCellarLevel4: return "TowerCellarLevel4";
			case TowerCellarLevel5: return "TowerCellarLevel5";
			case Travincal: return "Travincal";
			case Tristram: return "Tristram";
			case UberTristram: return "UberTristram";
			case UndergroundPassageLevel1: return "UndergroundPassageLevel1";
			case UndergroundPassageLevel2: return "UndergroundPassageLevel2";
			case UpperKurast: return "UpperKurast";
			case ValleyOfSnakes: return "ValleyOfSnakes";
			case Map1: return "Ancient Temple";
			case Map2: return "Desecrated Temple";
			case Map3: return "Map Frigid Plateau";
			case Map4: return "Infernal Trial";
			case Map5: return "Ruined Citadel";
		}
		return "N/A";
	}
	static AreaLevel getWpIndex(int a)
	{
		switch(a)
		{
			case 0: return RogueEncampment;
			case 1: return ColdPlains;
			case 2: return StonyField;
			case 3: return DarkWood;
			case 4: return BlackMarsh;
			case 5: return OuterCloister;
			case 6: return JailLevel1;
			case 7: return InnerCloister;
			case 8: return CatacombsLevel2;
			case 9: return LutGholein;
			case 10: return SewersLevel2Act2;
			case 11: return DryHills;
			case 12: return HallsOfTheDeadLevel2;
			case 13: return FarOasis;
			case 14: return LostCity;
			case 15: return PalaceCellarLevel1;
			case 16: return ArcaneSanctuary;
			case 17: return CanyonOfTheMagi;
			case 18: return KurastDocks;
			case 19: return SpiderForest;
			case 20: return GreatMarsh;
			case 21: return FlayerJungle;
			case 22: return LowerKurast;
			case 23: return KurastBazaar;
			case 24: return UpperKurast;
			case 25: return Travincal;
			case 26: return DuranceOfHateLevel2;
			case 27: return ThePandemoniumFortress;
			case 28: return CityOfTheDamned;
			case 29: return RiverOfFlame;
			case 30: return Harrogath;
			case 31: return FrigidHighlands;
			case 32: return ArreatPlateau;
			case 33: return CrystallinePassage;
			case 34: return GlacialTrail;
			case 35: return HallsOfPain;
			case 36: return FrozenTundra;
			case 37: return TheAncientsWay;
			case 38: return TheWorldStoneKeepLevel2;
		}
	}
};


class Waypoints
{
public:
    bool Available;
	AreaLevel::AreaLevel Location;
};
#endif
// tolua_end
