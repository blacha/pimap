import { GameObject } from './object';

export const enum GameObjectClass {
  DOOR = 'door',
  SOUND = 'sound',
  SHRINE = 'shrine',
  CHEST = 'chest',
  USELESS = 'useless',
  PORTAL = 'portal',
  WAYPOINT = 'waypoint',
  QUEST = 'quest',
}

export const GameObjectClasses = {
  [GameObject.TestData1]: GameObjectClass.USELESS,
  [GameObject.Casket5]: GameObjectClass.CHEST,
  [GameObject.Shrine]: GameObjectClass.SHRINE,
  [GameObject.Casket6]: GameObjectClass.CHEST,
  [GameObject.LargeUrn1]: GameObjectClass.USELESS,
  [GameObject.LargeChestRight]: GameObjectClass.CHEST,
  [GameObject.LargeChestLeft]: GameObjectClass.CHEST,
  [GameObject.Barrel]: GameObjectClass.USELESS,
  [GameObject.TowerTome]: GameObjectClass.USELESS,
  [GameObject.Urn2]: GameObjectClass.USELESS,
  [GameObject.Bench]: GameObjectClass.USELESS,
  [GameObject.BarrelExploding]: GameObjectClass.USELESS,
  [GameObject.RogueFountain]: GameObjectClass.USELESS,
  [GameObject.DoorGateLeft]: GameObjectClass.DOOR,
  [GameObject.DoorGateRight]: GameObjectClass.DOOR,
  [GameObject.DoorWoodenLeft]: GameObjectClass.DOOR,
  [GameObject.DoorWoodenRight]: GameObjectClass.DOOR,
  [GameObject.CairnStoneAlpha]: GameObjectClass.QUEST,
  [GameObject.CairnStoneBeta]: GameObjectClass.QUEST,
  [GameObject.CairnStoneGamma]: GameObjectClass.QUEST,
  [GameObject.CairnStoneDelta]: GameObjectClass.QUEST,
  [GameObject.CairnStoneLambda]: GameObjectClass.QUEST,
  [GameObject.CairnStoneTheta]: GameObjectClass.QUEST,
  [GameObject.DoorCourtyardLeft]: GameObjectClass.DOOR,
  [GameObject.DoorCourtyardRight]: GameObjectClass.DOOR,
  [GameObject.DoorCathedralDouble]: GameObjectClass.DOOR,
  [GameObject.CainGibbet]: GameObjectClass.USELESS,
  [GameObject.DoorMonasteryDoubleRight]: GameObjectClass.DOOR,
  [GameObject.HoleAnim]: GameObjectClass.USELESS,
  [GameObject.Brazier]: GameObjectClass.USELESS,
  [GameObject.InifussTree]: GameObjectClass.QUEST,
  [GameObject.Fountain]: GameObjectClass.USELESS,
  [GameObject.Crucifix]: GameObjectClass.USELESS,
  [GameObject.Candles1]: GameObjectClass.USELESS,
  [GameObject.Candles2]: GameObjectClass.USELESS,
  [GameObject.Standard1]: GameObjectClass.USELESS,
  [GameObject.Standard2]: GameObjectClass.USELESS,
  [GameObject.Torch1Tiki]: GameObjectClass.USELESS,
  [GameObject.Torch2Wall]: GameObjectClass.USELESS,
  [GameObject.RogueBonfire]: GameObjectClass.USELESS,
  [GameObject.River1]: GameObjectClass.USELESS,
  [GameObject.River2]: GameObjectClass.USELESS,
  [GameObject.River3]: GameObjectClass.USELESS,
  [GameObject.River4]: GameObjectClass.USELESS,
  [GameObject.River5]: GameObjectClass.USELESS,
  [GameObject.AmbientSoundGenerator]: GameObjectClass.SOUND,
  [GameObject.Crate]: GameObjectClass.USELESS,
  [GameObject.AndarielDoor]: GameObjectClass.DOOR,
  [GameObject.RogueTorch1]: GameObjectClass.USELESS,
  [GameObject.RogueTorch2]: GameObjectClass.USELESS,
  [GameObject.CasketR]: GameObjectClass.CHEST,
  [GameObject.CasketL]: GameObjectClass.CHEST,
  [GameObject.Urn3]: GameObjectClass.USELESS,
  [GameObject.Casket]: GameObjectClass.CHEST,
  [GameObject.RogueCorpse1]: GameObjectClass.CHEST,
  [GameObject.RogueCorpse2]: GameObjectClass.CHEST,
  [GameObject.RogueCorpseRolling]: GameObjectClass.USELESS,
  [GameObject.CorpseOnStick1]: GameObjectClass.USELESS,
  [GameObject.CorpseOnStick2]: GameObjectClass.USELESS,
  [GameObject.TownPortal]: GameObjectClass.PORTAL,
  [GameObject.PermanentTownPortal]: 60,
  [GameObject.InvisibleObject]: GameObjectClass.USELESS,
  [GameObject.DoorCathedralLeft]: GameObjectClass.DOOR,
  [GameObject.DoorCathedralRight]: GameObjectClass.DOOR,
  [GameObject.DoorWoodenLeft2]: GameObjectClass.DOOR,
  [GameObject.InvisibleRiverSound1]: GameObjectClass.SOUND,
  [GameObject.InvisibleRiverSound2]: GameObjectClass.SOUND,
  [GameObject.Ripple1]: GameObjectClass.USELESS,
  [GameObject.Ripple2]: GameObjectClass.USELESS,
  [GameObject.Ripple3]: GameObjectClass.USELESS,
  [GameObject.Ripple4]: GameObjectClass.USELESS,
  [GameObject.ForestNightSound1]: GameObjectClass.SOUND,
  [GameObject.ForestNightSound2]: GameObjectClass.SOUND,
  [GameObject.YetiDung]: GameObjectClass.USELESS,
  [GameObject.TrappDoor]: GameObjectClass.DOOR,
  [GameObject.DoorByAct2Dock]: GameObjectClass.DOOR,
  [GameObject.SewerDrip]: GameObjectClass.USELESS,
  [GameObject.HealthOrama]: GameObjectClass.USELESS,
  [GameObject.InvisibleTownSound]: GameObjectClass.SOUND,
  [GameObject.Casket3]: GameObjectClass.CHEST,
  [GameObject.Obelisk]: GameObjectClass.USELESS,
  [GameObject.ForestAltar]: GameObjectClass.CHEST,
  [GameObject.BubblingPoolOfBlood]: GameObjectClass.USELESS,
  [GameObject.HornShrine]: GameObjectClass.SHRINE,
  [GameObject.HealingWell]: GameObjectClass.SHRINE,
  [GameObject.BullHealthShrine]: GameObjectClass.SHRINE,
  [GameObject.SteleDesertMagicShrine]: GameObjectClass.SHRINE,
  [GameObject.TombLargeChestL]: GameObjectClass.CHEST,
  [GameObject.TombLargeChestR]: GameObjectClass.CHEST,
  [GameObject.Sarcophagus]: 89,
  [GameObject.DesertObelisk]: 90,
  [GameObject.TombDoorLeft]: GameObjectClass.DOOR,
  [GameObject.TombDoorRight]: GameObjectClass.DOOR,
  [GameObject.InnerHellManaShrine]: GameObjectClass.SHRINE,
  [GameObject.LargeUrn4]: GameObjectClass.USELESS,
  [GameObject.LargeUrn5]: GameObjectClass.USELESS,
  [GameObject.InnerHellHealthShrine]: GameObjectClass.SHRINE,
  [GameObject.InnerHellShrine]: GameObjectClass.SHRINE,
  [GameObject.TombDoorLeft2]: GameObjectClass.DOOR,
  [GameObject.TombDoorRight2]: GameObjectClass.DOOR,
  [GameObject.DurielsLairPortal]: GameObjectClass.QUEST,
  [GameObject.Brazier3]: GameObjectClass.USELESS,
  [GameObject.FloorBrazier]: GameObjectClass.USELESS,
  [GameObject.Flies]: GameObjectClass.USELESS,
  [GameObject.ArmorStandRight]: GameObjectClass.CHEST,
  [GameObject.ArmorStandLeft]: GameObjectClass.CHEST,
  [GameObject.WeaponRackRight]: GameObjectClass.CHEST,
  [GameObject.WeaponRackLeft]: GameObjectClass.CHEST,
  [GameObject.Malus]: GameObjectClass.USELESS,
  [GameObject.PalaceHealthShrine]: GameObjectClass.SHRINE,
  [GameObject.Drinker]: GameObjectClass.USELESS,
  [GameObject.Fountain1]: GameObjectClass.SHRINE,
  [GameObject.Gesturer]: GameObjectClass.USELESS,
  [GameObject.DesertFountain]: GameObjectClass.SHRINE,
  [GameObject.Turner]: 114,
  [GameObject.Fountain3]: GameObjectClass.SHRINE,
  [GameObject.SnakeWomanShrine]: GameObjectClass.SHRINE,
  [GameObject.JungleTorch]: GameObjectClass.USELESS,
  [GameObject.Fountain4]: GameObjectClass.SHRINE,
  [GameObject.WaypointPortal]: GameObjectClass.WAYPOINT,
  [GameObject.DungeonHealthShrine]: GameObjectClass.SHRINE,
  [GameObject.JerhynPlaceHolder1]: GameObjectClass.USELESS,
  [GameObject.JerhynPlaceHolder2]: GameObjectClass.USELESS,
  [GameObject.InnerHellShrine2]: GameObjectClass.SHRINE,
  [GameObject.InnerHellShrine3]: GameObjectClass.SHRINE,
  [GameObject.InnerHellHiddenStash]: GameObjectClass.CHEST,
  [GameObject.InnerHellSkullPile]: GameObjectClass.CHEST,
  [GameObject.InnerHellHiddenStash2]: GameObjectClass.CHEST,
  [GameObject.InnerHellHiddenStash3]: GameObjectClass.CHEST,
  [GameObject.SecretDoor1]: GameObjectClass.DOOR,
  [GameObject.Act1WildernessWell]: GameObjectClass.SHRINE,
  [GameObject.VileDogAfterglow]: GameObjectClass.USELESS,
  [GameObject.CathedralWell]: GameObjectClass.SHRINE,
  [GameObject.ArcaneSanctuaryShrine]: GameObjectClass.SHRINE,
  [GameObject.DesertShrine2]: GameObjectClass.SHRINE,
  [GameObject.DesertShrine3]: GameObjectClass.SHRINE,
  [GameObject.DesertShrine1]: GameObjectClass.SHRINE,
  [GameObject.DesertWell]: GameObjectClass.SHRINE,
  [GameObject.CaveWell]: GameObjectClass.SHRINE,
  [GameObject.Act1LargeChestRight]: GameObjectClass.CHEST,
  [GameObject.Act1TallChestRight]: GameObjectClass.CHEST,
  [GameObject.Act1MediumChestRight]: GameObjectClass.CHEST,
  [GameObject.DesertJug1]: GameObjectClass.USELESS,
  [GameObject.DesertJug2]: GameObjectClass.USELESS,
  [GameObject.Act1LargeChest1]: GameObjectClass.CHEST,
  [GameObject.InnerHellWaypoint]: GameObjectClass.WAYPOINT,
  [GameObject.Act2MediumChestRight]: GameObjectClass.CHEST,
  [GameObject.Act2LargeChestRight]: GameObjectClass.CHEST,
  [GameObject.Act2LargeChestLeft]: GameObjectClass.CHEST,
  [GameObject.TaintedSunAltar]: GameObjectClass.QUEST,
  [GameObject.DesertShrine5]: GameObjectClass.SHRINE,
  [GameObject.DesertShrine4]: GameObjectClass.SHRINE,
  [GameObject.HoradricOrifice]: GameObjectClass.QUEST,
  [GameObject.TyraelsDoor]: GameObjectClass.DOOR,
  [GameObject.GuardCorpse]: GameObjectClass.USELESS,
  [GameObject.HiddenStashRock]: GameObjectClass.USELESS,
  [GameObject.Act2Waypoint]: GameObjectClass.WAYPOINT,
  [GameObject.Act1WildernessWaypoint]: GameObjectClass.WAYPOINT,
  [GameObject.SkeletonCorpseIsAnOxymoron]: GameObjectClass.USELESS,
  [GameObject.HiddenStashRockB]: GameObjectClass.USELESS,
  [GameObject.SmallFire]: GameObjectClass.USELESS,
  [GameObject.MediumFire]: GameObjectClass.USELESS,
  [GameObject.LargeFire]: GameObjectClass.USELESS,
  [GameObject.Act1CliffHidingSpot]: GameObjectClass.USELESS,
  [GameObject.ManaWell1]: GameObjectClass.SHRINE,
  [GameObject.ManaWell2]: GameObjectClass.SHRINE,
  [GameObject.ManaWell3]: GameObjectClass.SHRINE,
  [GameObject.ManaWell4]: GameObjectClass.SHRINE,
  [GameObject.ManaWell5]: GameObjectClass.SHRINE,
  [GameObject.HollowLog]: GameObjectClass.USELESS,
  [GameObject.JungleHealWell]: GameObjectClass.SHRINE,
  [GameObject.SkeletonCorpseIsStillAnOxymoron]: GameObjectClass.USELESS,
  [GameObject.DesertHealthShrine]: GameObjectClass.SHRINE,
  [GameObject.ManaWell7]: GameObjectClass.SHRINE,
  [GameObject.LooseRock]: GameObjectClass.USELESS,
  [GameObject.LooseBoulder]: GameObjectClass.USELESS,
  [GameObject.MediumChestLeft]: GameObjectClass.CHEST,
  [GameObject.LargeChestLeft2]: GameObjectClass.CHEST,
  [GameObject.GuardCorpseOnAStick]: GameObjectClass.USELESS,
  [GameObject.Bookshelf1]: GameObjectClass.USELESS,
  [GameObject.Bookshelf2]: GameObjectClass.USELESS,
  [GameObject.JungleChest]: GameObjectClass.CHEST,
  [GameObject.TombCoffin]: GameObjectClass.USELESS,
  [GameObject.JungleMediumChestLeft]: GameObjectClass.CHEST,
  [GameObject.JungleShrine2]: GameObjectClass.SHRINE,
  [GameObject.JungleStashObject1]: GameObjectClass.USELESS,
  [GameObject.JungleStashObject2]: GameObjectClass.USELESS,
  [GameObject.JungleStashObject3]: GameObjectClass.USELESS,
  [GameObject.JungleStashObject4]: GameObjectClass.USELESS,
  [GameObject.DummyCainPortal]: GameObjectClass.USELESS,
  [GameObject.JungleShrine3]: GameObjectClass.SHRINE,
  [GameObject.JungleShrine4]: GameObjectClass.SHRINE,
  [GameObject.TeleportationPad1]: GameObjectClass.USELESS,
  [GameObject.LamEsensTome]: GameObjectClass.QUEST,
  [GameObject.StairsL]: GameObjectClass.USELESS,
  [GameObject.StairsR]: GameObjectClass.USELESS,
  [GameObject.FloorTrap]: GameObjectClass.USELESS,
  [GameObject.JungleShrine5]: GameObjectClass.SHRINE,
  [GameObject.TallChestLeft]: GameObjectClass.CHEST,
  [GameObject.MafistoShrine1]: GameObjectClass.SHRINE,
  [GameObject.MafistoShrine2]: GameObjectClass.SHRINE,
  [GameObject.MafistoShrine3]: GameObjectClass.SHRINE,
  [GameObject.MafistoManaShrine]: GameObjectClass.SHRINE,
  [GameObject.MafistoLair]: 203,
  [GameObject.StashBox]: GameObjectClass.USELESS,
  [GameObject.StashAltar]: GameObjectClass.USELESS,
  [GameObject.MafistoHealthShrine]: GameObjectClass.SHRINE,
  [GameObject.Act3WaterRocks]: GameObjectClass.USELESS,
  [GameObject.Basket1]: GameObjectClass.USELESS,
  [GameObject.Basket2]: GameObjectClass.USELESS,
  [GameObject.Act3WaterLogs]: GameObjectClass.USELESS,
  [GameObject.Act3WaterRocksGirl]: GameObjectClass.USELESS,
  [GameObject.Act3WaterBubbles]: GameObjectClass.USELESS,
  [GameObject.Act3WaterLogsX]: GameObjectClass.USELESS,
  [GameObject.Act3WaterRocksB]: GameObjectClass.USELESS,
  [GameObject.Act3WaterRocksGirlC]: GameObjectClass.USELESS,
  [GameObject.Act3WaterRocksY]: GameObjectClass.USELESS,
  [GameObject.Act3WaterLogsZ]: GameObjectClass.USELESS,
  [GameObject.WebCoveredTree1]: GameObjectClass.USELESS,
  [GameObject.WebCoveredTree2]: GameObjectClass.USELESS,
  [GameObject.WebCoveredTree3]: GameObjectClass.USELESS,
  [GameObject.WebCoveredTree4]: GameObjectClass.USELESS,
  [GameObject.Pillar]: GameObjectClass.USELESS,
  [GameObject.Cocoon]: GameObjectClass.USELESS,
  [GameObject.Cocoon2]: GameObjectClass.USELESS,
  [GameObject.SkullPileH1]: GameObjectClass.USELESS,
  [GameObject.OuterHellShrine]: GameObjectClass.SHRINE,
  [GameObject.Act3WaterRocksGirlW]: GameObjectClass.USELESS,
  [GameObject.Act3BigLog]: GameObjectClass.USELESS,
  [GameObject.SlimeDoor1]: GameObjectClass.DOOR,
  [GameObject.SlimeDoor2]: GameObjectClass.DOOR,
  [GameObject.OuterHellShrine2]: GameObjectClass.SHRINE,
  [GameObject.OuterHellShrine3]: GameObjectClass.SHRINE,
  [GameObject.PillarH2]: GameObjectClass.USELESS,
  [GameObject.Act3BigLogC]: GameObjectClass.USELESS,
  [GameObject.Act3BigLogD]: GameObjectClass.USELESS,
  [GameObject.HellHealthShrine]: GameObjectClass.SHRINE,
  [GameObject.Act3TownWaypoint]: GameObjectClass.WAYPOINT,
  [GameObject.WaypointH]: GameObjectClass.WAYPOINT,
  [GameObject.BurningBodyTown]: GameObjectClass.USELESS,
  [GameObject.Gchest1L]: GameObjectClass.CHEST,
  [GameObject.Gchest2R]: GameObjectClass.CHEST,
  [GameObject.Gchest3R]: GameObjectClass.CHEST,
  [GameObject.GLchest3L]: GameObjectClass.CHEST,
  [GameObject.SewersRatNest]: GameObjectClass.USELESS,
  [GameObject.BurningBodyTown2]: GameObjectClass.USELESS,
  [GameObject.SewersRatNest2]: GameObjectClass.USELESS,
  [GameObject.Act1BedBed1]: GameObjectClass.USELESS,
  [GameObject.Act1BedBed2]: GameObjectClass.USELESS,
  [GameObject.HellManaShrine]: GameObjectClass.SHRINE,
  [GameObject.ExplodingCow]: GameObjectClass.USELESS,
  [GameObject.GidbinnAltar]: GameObjectClass.QUEST,
  [GameObject.GidbinnAltarDecoy]: GameObjectClass.USELESS,
  [GameObject.DiabloRightLight]: GameObjectClass.USELESS,
  [GameObject.DiabloLeftLight]: GameObjectClass.USELESS,
  [GameObject.DiabloStartPoint]: GameObjectClass.USELESS,
  [GameObject.Act1CabinStool]: GameObjectClass.USELESS,
  [GameObject.Act1CabinWood]: GameObjectClass.USELESS,
  [GameObject.Act1CabinWood2]: GameObjectClass.USELESS,
  [GameObject.HellSkeletonSpawnNW]: GameObjectClass.USELESS,
  [GameObject.Act1HolyShrine]: GameObjectClass.SHRINE,
  [GameObject.TombsFloorTrapSpikes]: GameObjectClass.USELESS,
  [GameObject.Act1CathedralShrine]: GameObjectClass.SHRINE,
  [GameObject.Act1JailShrine1]: GameObjectClass.SHRINE,
  [GameObject.Act1JailShrine2]: GameObjectClass.SHRINE,
  [GameObject.Act1JailShrine3]: GameObjectClass.SHRINE,
  [GameObject.MaggotLairGooPile]: GameObjectClass.USELESS,
  [GameObject.Bank]: GameObjectClass.USELESS,
  [GameObject.WirtCorpse]: GameObjectClass.QUEST,
  [GameObject.GoldPlaceHolder]: GameObjectClass.USELESS,
  [GameObject.GuardCorpse2]: GameObjectClass.USELESS,
  [GameObject.DeadVillager1]: 271,
  [GameObject.DeadVillager2]: 272,
  [GameObject.DummyFlameNoDamage]: 273,
  [GameObject.TinyPixelShapedThingie]: 274,
  [GameObject.CavesHealthShrine]: GameObjectClass.SHRINE,
  [GameObject.CavesManaShrine]: GameObjectClass.SHRINE,
  [GameObject.CaveMagicShrine]: GameObjectClass.SHRINE,
  [GameObject.Act3DungeonManaShrine]: GameObjectClass.SHRINE,
  [GameObject.Act3SewersMagicShrine1]: GameObjectClass.SHRINE,
  [GameObject.Act3SewersHealthWell]: GameObjectClass.SHRINE,
  [GameObject.Act3SewersManaWell]: GameObjectClass.SHRINE,
  [GameObject.Act3SewersMagicShrine2]: GameObjectClass.SHRINE,
  [GameObject.Act2BrazierCeller]: 283,
  [GameObject.Act2TombAnubisCoffin]: 284,
  [GameObject.Act2Brazier]: 285,
  [GameObject.Act2BrazierTall]: 286,
  [GameObject.Act2BrazierSmall]: 287,
  [GameObject.Act2CellerWaypoint]: GameObjectClass.WAYPOINT,
  [GameObject.HarumBedBed]: 289,
  [GameObject.IronGrateDoorLeft]: GameObjectClass.DOOR,
  [GameObject.IronGrateDoorRight]: GameObjectClass.DOOR,
  [GameObject.WoodenGrateDoorLeft]: GameObjectClass.DOOR,
  [GameObject.WoodenGrateDoorRight]: GameObjectClass.DOOR,
  [GameObject.WoodenDoorLeft]: GameObjectClass.DOOR,
  [GameObject.WoodenDoorRight]: GameObjectClass.DOOR,
  [GameObject.TombsWallTorchLeft]: GameObjectClass.USELESS,
  [GameObject.TombsWallTorchRight]: GameObjectClass.USELESS,
  [GameObject.ArcaneSanctuaryPortal]: 298,
  [GameObject.Act2HaramMagicShrine1]: GameObjectClass.SHRINE,
  [GameObject.Act2HaramMagicShrine2]: GameObjectClass.SHRINE,
  [GameObject.MaggotHealthWell]: GameObjectClass.SHRINE,
  [GameObject.MaggotManaWell]: GameObjectClass.SHRINE,
  [GameObject.ArcaneSanctuaryMagicShrine]: GameObjectClass.SHRINE,
  [GameObject.TeleportationPad2]: GameObjectClass.DOOR,
  [GameObject.TeleportationPad3]: GameObjectClass.DOOR,
  [GameObject.TeleportationPad4]: GameObjectClass.DOOR,
  [GameObject.DummyArcaneThing1]: GameObjectClass.DOOR,
  [GameObject.DummyArcaneThing2]: GameObjectClass.DOOR,
  [GameObject.DummyArcaneThing3]: GameObjectClass.DOOR,
  [GameObject.DummyArcaneThing4]: GameObjectClass.DOOR,
  [GameObject.DummyArcaneThing5]: GameObjectClass.DOOR,
  [GameObject.DummyArcaneThing6]: GameObjectClass.DOOR,
  [GameObject.DummyArcaneThing7]: GameObjectClass.DOOR,
  [GameObject.HaremDeadGuard1]: 314,
  [GameObject.HaremDeadGuard2]: 315,
  [GameObject.HaremDeadGuard3]: 316,
  [GameObject.HaremDeadGuard4]: 317,
  [GameObject.HaremEunuchBlocker]: 318,
  [GameObject.ArcaneHealthWell]: GameObjectClass.SHRINE,
  [GameObject.ArcaneManaWell]: GameObjectClass.SHRINE,
  [GameObject.TestData2]: 321,
  [GameObject.Act2TombWell]: GameObjectClass.SHRINE,
  [GameObject.Act2SewerWaypoint]: GameObjectClass.WAYPOINT,
  [GameObject.Act3TravincalWaypoint]: GameObjectClass.WAYPOINT,
  [GameObject.Act3SewerMagicShrine]: GameObjectClass.SHRINE,
  [GameObject.Act3SewerDeadBody]: 326,
  [GameObject.Act3SewerTorch]: GameObjectClass.USELESS,
  [GameObject.Act3KurastTorch]: GameObjectClass.USELESS,
  [GameObject.MafistoLargeChestLeft]: GameObjectClass.CHEST,
  [GameObject.MafistoLargeChestRight]: GameObjectClass.CHEST,
  [GameObject.MafistoMediumChestLeft]: GameObjectClass.CHEST,
  [GameObject.MafistoMediumChestRight]: GameObjectClass.CHEST,
  [GameObject.SpiderLairLargeChestLeft]: GameObjectClass.CHEST,
  [GameObject.SpiderLairTallChestLeft]: GameObjectClass.CHEST,
  [GameObject.SpiderLairMediumChestRight]: GameObjectClass.CHEST,
  [GameObject.SpiderLairTallChestRight]: GameObjectClass.CHEST,
  [GameObject.SteegStone]: 337,
  [GameObject.GuildVault]: 338,
  [GameObject.TrophyCase]: 339,
  [GameObject.MessageBoard]: 340,
  [GameObject.MephistoBridge]: 341,
  [GameObject.HellGate]: 342,
  [GameObject.Act3KurastManaWell]: GameObjectClass.SHRINE,
  [GameObject.Act3KurastHealthWell]: GameObjectClass.SHRINE,
  [GameObject.HellFire1]: GameObjectClass.USELESS,
  [GameObject.HellFire2]: GameObjectClass.USELESS,
  [GameObject.HellFire3]: GameObjectClass.USELESS,
  [GameObject.HellLava1]: 348,
  [GameObject.HellLava2]: 349,
  [GameObject.HellLava3]: 350,
  [GameObject.HellLightSource1]: 351,
  [GameObject.HellLightSource2]: 352,
  [GameObject.HellLightSource3]: 353,
  [GameObject.HoradricCubeChest]: GameObjectClass.CHEST,
  [GameObject.HoradricScrollChest]: GameObjectClass.CHEST,
  [GameObject.StaffOfKingsChest]: GameObjectClass.CHEST,
  [GameObject.YetAnotherTome]: 357,
  [GameObject.HellBrazier1]: 358,
  [GameObject.HellBrazier2]: 359,
  [GameObject.DungeonRockPile]: 360,
  [GameObject.Act3DungeonMagicShrine]: GameObjectClass.SHRINE,
  [GameObject.Act3DungeonBasket]: 362,
  [GameObject.OuterHellHungSkeleton]: 363,
  [GameObject.GuyForDungeon]: 364,
  [GameObject.Act3DungeonCasket]: 365,
  [GameObject.Act3SewerStairs]: GameObjectClass.DOOR,
  [GameObject.Act3SewerStairsToLevel3]: GameObjectClass.DOOR,
  [GameObject.DarkWandererStartPosition]: 368,
  [GameObject.TrappedSoulPlaceHolder]: 369,
  [GameObject.Act3TownTorch]: GameObjectClass.USELESS,
  [GameObject.LargeChestR]: GameObjectClass.CHEST,
  [GameObject.InnerHellBoneChest]: GameObjectClass.CHEST,
  [GameObject.HellSkeletonSpawnNE]: 373,
  [GameObject.Act3WaterFog]: 374,
  [GameObject.DummyNotUsed]: 375,
  [GameObject.HellForge]: GameObjectClass.QUEST,
  [GameObject.GuildPortal]: 377,
  [GameObject.HratliStartPosition]: 378,
  [GameObject.HratliEndPosition]: 379,
  [GameObject.BurningTrappedSoul1]: 380,
  [GameObject.BurningTrappedSoul2]: 381,
  [GameObject.NatalyaStartPosition]: 382,
  [GameObject.StuckedTrappedSoul1]: 383,
  [GameObject.StuckedTrappedSoul2]: 384,
  [GameObject.CainStartPosition]: 385,
  [GameObject.StairSR]: 386,
  [GameObject.ArcaneLargeChestLeft]: GameObjectClass.CHEST,
  [GameObject.ArcaneCasket]: 388,
  [GameObject.ArcaneLargeChestRight]: GameObjectClass.CHEST,
  [GameObject.ArcaneSmallChestLeft]: GameObjectClass.CHEST,
  [GameObject.ArcaneSmallChestRight]: GameObjectClass.CHEST,
  [GameObject.DiabloSeal1]: 392,
  [GameObject.DiabloSeal2]: 393,
  [GameObject.DiabloSeal3]: 394,
  [GameObject.DiabloSeal4]: 395,
  [GameObject.DiabloSeal5]: 396,
  [GameObject.SparklyChest]: GameObjectClass.CHEST,
  [GameObject.PandamoniumFortressWaypoint]: GameObjectClass.WAYPOINT,
  [GameObject.InnerHellFissure]: 399,
  [GameObject.HellMesaBrazier]: 400,
  [GameObject.Smoke]: 401,
  [GameObject.ValleyWaypoint]: GameObjectClass.WAYPOINT,
  [GameObject.HellBrazier3]: 403,
  [GameObject.CompellingOrb]: 404,
  [GameObject.KhalimChest1]: GameObjectClass.CHEST,
  [GameObject.KhalimChest2]: GameObjectClass.CHEST,
  [GameObject.KhalimChest3]: GameObjectClass.CHEST,
  [GameObject.FortressBrazier1]: 408,
  [GameObject.FortressBrazier2]: 409,
  [GameObject.SiegeMachineControl]: 408,
  [GameObject.PotOTorch]: GameObjectClass.USELESS,
  [GameObject.PyoxFirePit]: GameObjectClass.USELESS,
  [GameObject.ExpansionChestRight]: GameObjectClass.CHEST,
  [GameObject.ExpansionWildernessShrine1]: GameObjectClass.SHRINE,
  [GameObject.ExpansionWildernessShrine2]: GameObjectClass.SHRINE,
  [GameObject.ExpansionHiddenStash]: 416,
  [GameObject.ExpansionWildernessFlag]: 417,
  [GameObject.ExpansionWildernessBarrel]: GameObjectClass.USELESS,
  [GameObject.ExpansionSiegeBarrel]: GameObjectClass.USELESS,
  [GameObject.ExpansionWoodChestLeft]: GameObjectClass.CHEST,
  [GameObject.ExpansionWildernessShrine3]: GameObjectClass.SHRINE,
  [GameObject.ExpansionManaShrine]: GameObjectClass.SHRINE,
  [GameObject.ExpansionHealthShrine]: GameObjectClass.SHRINE,
  [GameObject.BurialChestLeft]: GameObjectClass.CHEST,
  [GameObject.BurialChestRight]: GameObjectClass.CHEST,
  [GameObject.ExpansionWell]: GameObjectClass.SHRINE,
  [GameObject.ExpansionWildernessShrine4]: GameObjectClass.SHRINE,
  [GameObject.ExpansionWildernessShrine5]: GameObjectClass.SHRINE,
  [GameObject.ExpansionWaypoint]: GameObjectClass.WAYPOINT,
  [GameObject.ExpansionChestLeft]: GameObjectClass.CHEST,
  [GameObject.ExpansionWoodChestRight]: GameObjectClass.CHEST,
  [GameObject.ExpansionSmallChestLeft]: GameObjectClass.CHEST,
  [GameObject.ExpansionSmallChestRight]: GameObjectClass.CHEST,
  [GameObject.ExpansionTorch1]: GameObjectClass.USELESS,
  [GameObject.ExpansionCampFire]: GameObjectClass.USELESS,
  [GameObject.ExpansionTownTorch]: GameObjectClass.USELESS,
  [GameObject.ExpansionTorch2]: GameObjectClass.USELESS,
  [GameObject.ExpansionBurningBodies]: 438,
  [GameObject.ExpansionBurningPit]: 439,
  [GameObject.ExpansionTribalFlag]: 440,
  [GameObject.ExpansionTownFlag]: 441,
  [GameObject.ExpansionChandelier]: 442,
  [GameObject.ExpansionJar1]: 443,
  [GameObject.ExpansionJar2]: 444,
  [GameObject.ExpansionJar3]: 445,
  [GameObject.ExpansionSwingingHeads]: 446,
  [GameObject.ExpansionWildernessPole]: 447,
  [GameObject.AnimatedSkullAndRockPile]: 448,
  [GameObject.ExpansionTownGate]: GameObjectClass.DOOR,
  [GameObject.SkullAndRockPile]: 450,
  [GameObject.SiegeHellGate]: GameObjectClass.DOOR,
  [GameObject.EnemyCampBanner1]: 452,
  [GameObject.EnemyCampBanner2]: 453,
  [GameObject.ExpansionExplodingChest]: GameObjectClass.CHEST,
  [GameObject.ExpansionSpecialChest]: GameObjectClass.CHEST,
  [GameObject.ExpansionDeathPole]: 456,
  [GameObject.ExpansionDeathPoleLeft]: 457,
  [GameObject.TempleAltar]: 458,
  [GameObject.DrehyaTownStartPosition]: 459,
  [GameObject.DrehyaWildernessStartPosition]: 460,
  [GameObject.NihlathakTownStartPosition]: 461,
  [GameObject.NihlathakWildernessStartPosition]: 462,
  [GameObject.IceCaveHiddenStash]: 463,
  [GameObject.IceCaveHealthShrine]: GameObjectClass.SHRINE,
  [GameObject.IceCaveManaShrine]: GameObjectClass.SHRINE,
  [GameObject.IceCaveEvilUrn]: GameObjectClass.SHRINE,
  [GameObject.IceCaveJar1]: 467,
  [GameObject.IceCaveJar2]: 468,
  [GameObject.IceCaveJar3]: 469,
  [GameObject.IceCaveJar4]: 470,
  [GameObject.IceCaveJar5]: 471,
  [GameObject.IceCaveMagicShrine]: GameObjectClass.SHRINE,
  [GameObject.CagedWussie]: GameObjectClass.QUEST,
  [GameObject.AncientStatue3]: 474,
  [GameObject.AncientStatue1]: 475,
  [GameObject.AncientStatue2]: 476,
  [GameObject.DeadBarbarian]: 477,
  [GameObject.ClientSmoke]: 478,
  [GameObject.IceCaveMagicShrine2]: GameObjectClass.SHRINE,
  [GameObject.IceCaveTorch1]: GameObjectClass.USELESS,
  [GameObject.IceCaveTorch2]: GameObjectClass.USELESS,
  [GameObject.ExpansionTikiTorch]: GameObjectClass.USELESS,
  [GameObject.WorldstoneManaShrine]: GameObjectClass.SHRINE,
  [GameObject.WorldstoneHealthShrine]: GameObjectClass.SHRINE,
  [GameObject.WorldstoneTomb1]: 485,
  [GameObject.WorldstoneTomb2]: 486,
  [GameObject.WorldstoneTomb3]: 487,
  [GameObject.WorldstoneMagicShrine]: GameObjectClass.SHRINE,
  [GameObject.WorldstoneTorch1]: GameObjectClass.USELESS,
  [GameObject.WorldstoneTorch2]: GameObjectClass.USELESS,
  [GameObject.ExpansionSnowyManaShrine1]: GameObjectClass.SHRINE,
  [GameObject.ExpansionSnowyHealthShrine]: GameObjectClass.SHRINE,
  [GameObject.ExpansionSnowyWell]: GameObjectClass.SHRINE,
  [GameObject.WorldstoneWaypoint]: GameObjectClass.WAYPOINT,
  [GameObject.ExpansionSnowyMagicShrine2]: GameObjectClass.SHRINE,
  [GameObject.ExpansionWildernessWaypoint]: GameObjectClass.WAYPOINT,
  [GameObject.ExpansionSnowyMagicShrine3]: GameObjectClass.SHRINE,
  [GameObject.WorldstoneWell]: GameObjectClass.SHRINE,
  [GameObject.WorldstoneMagicShrine2]: GameObjectClass.SHRINE,
  [GameObject.ExpansionSnowyObject1]: 500,
  [GameObject.ExpansionSnowyWoodChestLeft]: GameObjectClass.CHEST,
  [GameObject.ExpansionSnowyWoodChestRight]: GameObjectClass.CHEST,
  [GameObject.WorldstoneMagicShrine3]: GameObjectClass.SHRINE,
  [GameObject.ExpansionSnowyWoodChest2Left]: GameObjectClass.CHEST,
  [GameObject.ExpansionSnowyWoodChest2Right]: GameObjectClass.CHEST,
  [GameObject.SnowySwingingHeads]: 506,
  [GameObject.SnowyDebris]: 507,
  [GameObject.PenBreakableDoor]: GameObjectClass.DOOR,
  [GameObject.ExpansionTempleMagicShrine1]: GameObjectClass.SHRINE,
  [GameObject.ExpansionSnowyPoleMR]: 510,
  [GameObject.IceCaveWaypoint]: GameObjectClass.WAYPOINT,
  [GameObject.ExpansionTempleMagicShrine2]: GameObjectClass.SHRINE,
  [GameObject.ExpansionTempleWell]: GameObjectClass.SHRINE,
  [GameObject.ExpansionTempleTorch1]: GameObjectClass.USELESS,
  [GameObject.ExpansionTempleTorch2]: GameObjectClass.USELESS,
  [GameObject.ExpansionTempleObject1]: 516,
  [GameObject.ExpansionTempleObject2]: 517,
  [GameObject.WorldstoneMrBox]: 518,
  [GameObject.IceCaveWell]: GameObjectClass.SHRINE,
  [GameObject.ExpansionTempleMagicShrine]: GameObjectClass.SHRINE,
  [GameObject.ExpansionTempleHealthShrine]: GameObjectClass.SHRINE,
  [GameObject.ExpansionTempleManaShrine]: GameObjectClass.SHRINE,
  [GameObject.BlacksmithForge]: GameObjectClass.USELESS,
  [GameObject.WorldstoneTomb1Left]: 524,
  [GameObject.WorldstoneTomb2Left]: 525,
  [GameObject.WorldstoneTomb3Left]: 526,
  [GameObject.IceCaveBubblesU]: 527,
  [GameObject.IceCaveBubblesS]: 528,
  [GameObject.RedBaalsLairTomb1]: 529,
  [GameObject.RedBaalsLairTomb1Left]: 530,
  [GameObject.RedBaalsLairTomb2]: 531,
  [GameObject.RedBaalsLairTomb2Left]: 532,
  [GameObject.RedBaalsLairTomb3]: 533,
  [GameObject.RedBaalsLairTomb3Left]: 534,
  [GameObject.RedBaalsLairMrBox]: 535,
  [GameObject.RedBaalsLairTorch1]: GameObjectClass.USELESS,
  [GameObject.RedBaalsLairTorch2]: GameObjectClass.USELESS,
  [GameObject.CandlesTemple]: GameObjectClass.USELESS,
  [GameObject.TempleWaypoint]: GameObjectClass.WAYPOINT,
  [GameObject.ExpansionDeadPerson1]: 540,
  [GameObject.TempleGroundTomb]: 541,
  [GameObject.LarzukGreeting]: 542,
  [GameObject.LarzukStandard]: 543,
  [GameObject.TempleGroundTombLeft]: 544,
  [GameObject.ExpansionDeadPerson2]: 545,
  [GameObject.AncientsAltar]: 546,
  [GameObject.ArreatSummitDoorToWorldstone]: GameObjectClass.DOOR,
  [GameObject.ExpansionWeaponRackRight]: 548,
  [GameObject.ExpansionWeaponRackLeft]: 549,
  [GameObject.ExpansionArmorStandRight]: 550,
  [GameObject.ExpansionArmorStandLeft]: 551,
  [GameObject.ArreatsSummitTorch2]: GameObjectClass.USELESS,
  [GameObject.ExpansionFuneralSpire]: 553,
  [GameObject.ExpansionBurningLogs]: 554,
  [GameObject.IceCaveSteam]: 555,
  [GameObject.ExpansionDeadPerson3]: 556,
  [GameObject.BaalsLair]: 557,
  [GameObject.FrozenAnya]: 558,
  [GameObject.BBQBunny]: 559,
  [GameObject.BaalTorchBig]: GameObjectClass.USELESS,
  [GameObject.InvisibleAncient]: 561,
  [GameObject.InvisibleBase]: 562,
  [GameObject.BaalsPortal]: 563,
  [GameObject.ArreatSummitDoor]: GameObjectClass.DOOR,
  [GameObject.LastPortal]: 565,
  [GameObject.LastLastPortal]: 566,
  [GameObject.ZooTestData]: 567,
  [GameObject.KeeperTestData]: 568,
  [GameObject.BaalsPortal2]: 569,
  [GameObject.FirePlaceGuy]: GameObjectClass.USELESS,
  [GameObject.DoorBlocker1]: GameObjectClass.DOOR,
  [GameObject.DoorBlocker2]: GameObjectClass.DOOR,
  [GameObject.NotApplicable]: -1,
};
