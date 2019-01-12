#ifndef _GameObject_h__
#define _GameObject_h__

enum GameObject
{
    TestData1 = 0,
    Casket5 = 1,
    Shrine = 2,
    Casket6 = 3,
    LargeUrn1 = 4,
    LargeChestRight = 5,
    LargeChestLeft = 6,
    Barrel = 7,
    TowerTome = 8,
    Urn2 = 9,
    Bench = 10,
    BarrelExploding = 11,
    RogueFountain = 12,
    DoorGateLeft = 13,
    DoorGateRight = 14,
    DoorWoodenLeft = 15,
    DoorWoodenRight = 16,
    CairnStoneAlpha = 17,
    CairnStoneBeta = 18,
    CairnStoneGamma = 19,
    CairnStoneDelta = 20,
    CairnStoneLambda = 21,
    CairnStoneTheta = 22,
    DoorCourtyardLeft = 23,
    DoorCourtyardRight = 24,
    DoorCathedralDouble = 25,
    CainGibbet = 26,
    DoorMonasteryDoubleRight = 27,
    HoleAnim = 28,
    Brazier = 29,
    InifussTree = 30,
    Fountain = 31,
    Crucifix = 32,
    Candles1 = 33,
    Candles2 = 34,
    Standard1 = 35,
    Standard2 = 36,
    Torch1Tiki = 37,
    Torch2Wall = 38,
    RogueBonfire = 39,
    River1 = 40,
    River2 = 41,
    River3 = 42,
    River4 = 43,
    River5 = 44,
    AmbientSoundGenerator = 45,
    Crate = 46,
    AndarielDoor = 47,
    RogueTorch1 = 48,
    RogueTorch2 = 49,
    CasketR = 50,
    CasketL = 51,
    Urn3 = 52,
    Casket = 53,
    RogueCorpse1 = 54,
    RogueCorpse2 = 55,
    RogueCorpseRolling = 56,
    CorpseOnStick1 = 57,
    CorpseOnStick2 = 58,
    TownPortal = 59,
    PermanentTownPortal = 60,
    InvisibleObject = 61,
    DoorCathedralLeft = 62,
    DoorCathedralRight = 63,
    DoorWoodenLeft2 = 64,
    InvisibleRiverSound1 = 65,
    InvisibleRiverSound2 = 66,
    Ripple1 = 67,
    Ripple2 = 68,
    Ripple3 = 69,
    Ripple4 = 70,
    ForestNightSound1 = 71,
    ForestNightSound2 = 72,
    YetiDung = 73,
    TrappDoor = 74,
    DoorByAct2Dock = 75,
    SewerDrip = 76,
    HealthOrama = 77,
    InvisibleTownSound = 78,
    Casket3 = 79,
    Obelisk = 80,
    ForestAltar = 81,
    BubblingPoolOfBlood = 82,
    HornShrine = 83,
    HealingWell = 84,
    BullHealthShrine = 85,
    SteleDesertMagicShrine = 86,
    TombLargeChestL = 87,
    TombLargeChestR = 88,
    Sarcophagus = 89,
    DesertObelisk = 90,
    TombDoorLeft = 91,
    TombDoorRight = 92,
    InnerHellManaShrine = 93,
    LargeUrn4 = 94,
    LargeUrn5 = 95,
    InnerHellHealthShrine = 96,
    InnerHellShrine = 97,
    TombDoorLeft2 = 98,
    TombDoorRight2 = 99,
    DurielsLairPortal = 100,
    Brazier3 = 101,
    FloorBrazier = 102,
    Flies = 103,
    ArmorStandRight = 104,
    ArmorStandLeft = 105,
    WeaponRackRight = 106,
    WeaponRackLeft = 107,
    Malus = 108,
    PalaceHealthShrine = 109,
    Drinker = 110,
    Fountain1 = 111,
    Gesturer = 112,
    DesertFountain = 113,
    Turner = 114,
    Fountain3 = 115,
    SnakeWomanShrine = 116,
    JungleTorch = 117,
    Fountain4 = 118,
    WaypointPortal = 119,
    DungeonHealthShrine = 120,
    JerhynPlaceHolder1 = 121,
    JerhynPlaceHolder2 = 122,
    InnerHellShrine2 = 123,
    InnerHellShrine3 = 124,
    InnerHellHiddenStash = 125,
    InnerHellSkullPile = 126,
    InnerHellHiddenStash2 = 127,
    InnerHellHiddenStash3 = 128,
    SecretDoor1 = 129,
    Act1WildernessWell = 130,
    VileDogAfterglow = 131,
    CathedralWell = 132,
    ArcaneSanctuaryShrine = 133,
    DesertShrine2 = 134,
    DesertShrine3 = 135,
    DesertShrine1 = 136,
    DesertWell = 137,
    CaveWell = 138,
    Act1LargeChestRight = 139,
    Act1TallChestRight = 140,
    Act1MediumChestRight = 141,
    DesertJug1 = 142,
    DesertJug2 = 143,
    Act1LargeChest1 = 144,
    InnerHellWaypoint = 145,
    Act2MediumChestRight = 146,
    Act2LargeChestRight = 147,
    Act2LargeChestLeft = 148,
    TaintedSunAltar = 149,
    DesertShrine5 = 150,
    DesertShrine4 = 151,
    HoradricOrifice = 152,
    TyraelsDoor = 153,
    GuardCorpse = 154,
    HiddenStashRock = 155,
    Act2Waypoint = 156,
    Act1WildernessWaypoint = 157,
    SkeletonCorpseIsAnOxymoron = 158,
    HiddenStashRockB = 159,
    SmallFire = 160,
    MediumFire = 161,
    LargeFire = 162,
    Act1CliffHidingSpot = 163,
    ManaWell1 = 164,
    ManaWell2 = 165,
    ManaWell3 = 166,
    ManaWell4 = 167,
    ManaWell5 = 168,
    HollowLog = 169,
    JungleHealWell = 170,
    SkeletonCorpseIsStillAnOxymoron = 171,
    DesertHealthShrine = 172,
    ManaWell7 = 173,
    LooseRock = 174,
    LooseBoulder = 175,
    MediumChestLeft = 176,
    LargeChestLeft2 = 177,
    GuardCorpseOnAStick = 178,
    Bookshelf1 = 179,
    Bookshelf2 = 180,
    JungleChest = 181,
    TombCoffin = 182,
    JungleMediumChestLeft = 183,
    JungleShrine2 = 184,
    JungleStashObject1 = 185,
    JungleStashObject2 = 186,
    JungleStashObject3 = 187,
    JungleStashObject4 = 188,
    DummyCainPortal = 189,
    JungleShrine3 = 190,
    JungleShrine4 = 191,
    TeleportationPad1 = 192,
    LamEsensTome = 193,
    StairsL = 194,
    StairsR = 195,
    FloorTrap = 196,
    JungleShrine5 = 197,
    TallChestLeft = 198,
    MafistoShrine1 = 199,
    MafistoShrine2 = 200,
    MafistoShrine3 = 201,
    MafistoManaShrine = 202,
    MafistoLair = 203,
    StashBox = 204,
    StashAltar = 205,
    MafistoHealthShrine = 206,
    Act3WaterRocks = 207,
    Basket1 = 208,
    Basket2 = 209,
    Act3WaterLogs = 210,
    Act3WaterRocksGirl = 211,
    Act3WaterBubbles = 212,
    Act3WaterLogsX = 213,
    Act3WaterRocksB = 214,
    Act3WaterRocksGirlC = 215,
    Act3WaterRocksY = 216,
    Act3WaterLogsZ = 217,
    WebCoveredTree1 = 218,
    WebCoveredTree2 = 219,
    WebCoveredTree3 = 220,
    WebCoveredTree4 = 221,
    Pillar = 222,
    Cocoon = 223,
    Cocoon2 = 224,
    SkullPileH1 = 225,
    OuterHellShrine = 226,
    Act3WaterRocksGirlW = 227,
    Act3BigLog = 228,
    SlimeDoor1 = 229,
    SlimeDoor2 = 230,
    OuterHellShrine2 = 231,
    OuterHellShrine3 = 232,
    PillarH2 = 233,
    Act3BigLogC = 234,
    Act3BigLogD = 235,
    HellHealthShrine = 236,
    Act3TownWaypoint = 237,
    WaypointH = 238,
    BurningBodyTown = 239,
    Gchest1L = 240,
    Gchest2R = 241,
    Gchest3R = 242,
    GLchest3L = 243,
    SewersRatNest = 244,
    BurningBodyTown2 = 245,
    SewersRatNest2 = 246,
    Act1BedBed1 = 247,
    Act1BedBed2 = 248,
    HellManaShrine = 249,
    ExplodingCow = 250,
    GidbinnAltar = 251,
    GidbinnAltarDecoy = 252,
    DiabloRightLight = 253,
    DiabloLeftLight = 254,
    DiabloStartPoint = 255,
    Act1CabinStool = 256,
    Act1CabinWood = 257,
    Act1CabinWood2 = 258,
    HellSkeletonSpawnNW = 259,
    Act1HolyShrine = 260,
    TombsFloorTrapSpikes = 261,
    Act1CathedralShrine = 262,
    Act1JailShrine1 = 263,
    Act1JailShrine2 = 264,
    Act1JailShrine3 = 265,
    MaggotLairGooPile = 266,
    Bank = 267,
    WirtCorpse = 268,
    GoldPlaceHolder = 269,
    GuardCorpse2 = 270,
    DeadVillager1 = 271,
    DeadVillager2 = 272,
    DummyFlameNoDamage = 273,
    TinyPixelShapedThingie = 274,
    CavesHealthShrine = 275,
    CavesManaShrine = 276,
    CaveMagicShrine = 277,
    Act3DungeonManaShrine = 278,
    Act3SewersMagicShrine1 = 279,
    Act3SewersHealthWell = 280,
    Act3SewersManaWell = 281,
    Act3SewersMagicShrine2 = 282,
    Act2BrazierCeller = 283,
    Act2TombAnubisCoffin = 284,
    Act2Brazier = 285,
    Act2BrazierTall = 286,
    Act2BrazierSmall = 287,
    Act2CellerWaypoint = 288,
    HarumBedBed = 289,
    IronGrateDoorLeft = 290,
    IronGrateDoorRight = 291,
    WoodenGrateDoorLeft = 292,
    WoodenGrateDoorRight = 293,
    WoodenDoorLeft = 294,
    WoodenDoorRight = 295,
    TombsWallTorchLeft = 296,
    TombsWallTorchRight = 297,
    ArcaneSanctuaryPortal = 298,
    Act2HaramMagicShrine1 = 299,
    Act2HaramMagicShrine2 = 300,
    MaggotHealthWell = 301,
    MaggotManaWell = 302,
    ArcaneSanctuaryMagicShrine = 303,
    TeleportationPad2 = 304,
    TeleportationPad3 = 305,
    TeleportationPad4 = 306,
    DummyArcaneThing1 = 307,
    DummyArcaneThing2 = 308,
    DummyArcaneThing3 = 309,
    DummyArcaneThing4 = 310,
    DummyArcaneThing5 = 311,
    DummyArcaneThing6 = 312,
    DummyArcaneThing7 = 313,
    HaremDeadGuard1 = 314,
    HaremDeadGuard2 = 315,
    HaremDeadGuard3 = 316,
    HaremDeadGuard4 = 317,
    HaremEunuchBlocker = 318,
    ArcaneHealthWell = 319,
    ArcaneManaWell = 320,
    TestData2 = 321,
    Act2TombWell = 322,
    Act2SewerWaypoint = 323,
    Act3TravincalWaypoint = 324,
    Act3SewerMagicShrine = 325,
    Act3SewerDeadBody = 326,
    Act3SewerTorch = 327,
    Act3KurastTorch = 328,
    MafistoLargeChestLeft = 329,
    MafistoLargeChestRight = 330,
    MafistoMediumChestLeft = 331,
    MafistoMediumChestRight = 332,
    SpiderLairLargeChestLeft = 333,
    SpiderLairTallChestLeft = 334,
    SpiderLairMediumChestRight = 335,
    SpiderLairTallChestRight = 336,
    SteegStone = 337,
    GuildVault = 338,
    TrophyCase = 339,
    MessageBoard = 340,
    MephistoBridge = 341,
    HellGate = 342,
    Act3KurastManaWell = 343,
    Act3KurastHealthWell = 344,
    HellFire1 = 345,
    HellFire2 = 346,
    HellFire3 = 347,
    HellLava1 = 348,
    HellLava2 = 349,
    HellLava3 = 350,
    HellLightSource1 = 351,
    HellLightSource2 = 352,
    HellLightSource3 = 353,
    HoradricCubeChest = 354,
    HoradricScrollChest = 355,
    StaffOfKingsChest = 356,
    YetAnotherTome = 357,
    HellBrazier1 = 358,
    HellBrazier2 = 359,
    DungeonRockPile = 360,
    Act3DungeonMagicShrine = 361,
    Act3DungeonBasket = 362,
    OuterHellHungSkeleton = 363,
    GuyForDungeon = 364,
    Act3DungeonCasket = 365,
    Act3SewerStairs = 366,
    Act3SewerStairsToLevel3 = 367,
    DarkWandererStartPosition = 368,
    TrappedSoulPlaceHolder = 369,
    Act3TownTorch = 370,
    LargeChestR = 371,
    InnerHellBoneChest = 372,
    HellSkeletonSpawnNE = 373,
    Act3WaterFog = 374,
    DummyNotUsed = 375,
    HellForge = 376,
    GuildPortal = 377,
    HratliStartPosition = 378,
    HratliEndPosition = 379,
    BurningTrappedSoul1 = 380,
    BurningTrappedSoul2 = 381,
    NatalyaStartPosition = 382,
    StuckedTrappedSoul1 = 383,
    StuckedTrappedSoul2 = 384,
    CainStartPosition = 385,
    StairSR = 386,
    ArcaneLargeChestLeft = 387,
    ArcaneCasket = 388,
    ArcaneLargeChestRight = 389,
    ArcaneSmallChestLeft = 390,
    ArcaneSmallChestRight = 391,
    DiabloSeal1 = 392,
    DiabloSeal2 = 393,
    DiabloSeal3 = 394,
    DiabloSeal4 = 395,
    DiabloSeal5 = 396,
    SparklyChest = 397,
    PandamoniumFortressWaypoint = 398,
    InnerHellFissure = 399,
    HellMesaBrazier = 400,
    Smoke = 401,
    ValleyWaypoint = 402,
    HellBrazier3 = 403,
    CompellingOrb = 404,
    KhalimChest1 = 405,
    KhalimChest2 = 406,
    KhalimChest3 = 407,
    FortressBrazier1 = 408,
    FortressBrazier2 = 409,

    // LoD
    SiegeMachineControl = 573,
    PotOTorch = 574,
    PyoxFirePit = 410,
    ExpansionChestRight = 413,
    ExpansionWildernessShrine1 = 414,
    ExpansionWildernessShrine2 = 415,
    ExpansionHiddenStash = 416,
    ExpansionWildernessFlag = 417,
    ExpansionWildernessBarrel = 418,
    ExpansionSiegeBarrel = 419,
    ExpansionWoodChestLeft = 420,
    ExpansionWildernessShrine3 = 421,
    ExpansionManaShrine = 422,
    ExpansionHealthShrine = 423,
    BurialChestLeft = 424,
    BurialChestRight = 425,
    ExpansionWell = 426,
    ExpansionWildernessShrine4 = 427,
    ExpansionWildernessShrine5 = 428,
    ExpansionWaypoint = 429,
    ExpansionChestLeft = 430,
    ExpansionWoodChestRight = 431,
    ExpansionSmallChestLeft = 432,
    ExpansionSmallChestRight = 433,
    ExpansionTorch1 = 434,
    ExpansionCampFire = 435,
    ExpansionTownTorch = 436,
    ExpansionTorch2 = 437,
    ExpansionBurningBodies = 438,
    ExpansionBurningPit = 439,
    ExpansionTribalFlag = 440,
    ExpansionTownFlag = 441,
    ExpansionChandelier = 442,
    ExpansionJar1 = 443,
    ExpansionJar2 = 444,
    ExpansionJar3 = 445,
    ExpansionSwingingHeads = 446,
    ExpansionWildernessPole = 447,
    AnimatedSkullAndRockPile = 448,
    ExpansionTownGate = 449,
    SkullAndRockPile = 450,
    SiegeHellGate = 451,
    EnemyCampBanner1 = 452,
    EnemyCampBanner2 = 453,
    ExpansionExplodingChest = 454,
    ExpansionSpecialChest = 455,
    ExpansionDeathPole = 456,
    ExpansionDeathPoleLeft = 457,
    TempleAltar = 458,
    DrehyaTownStartPosition = 459,
    DrehyaWildernessStartPosition = 460,
    NihlathakTownStartPosition = 461,
    NihlathakWildernessStartPosition = 462,
    IceCaveHiddenStash = 463,
    IceCaveHealthShrine = 464,
    IceCaveManaShrine = 465,
    IceCaveEvilUrn = 466,
    IceCaveJar1 = 467,
    IceCaveJar2 = 468,
    IceCaveJar3 = 469,
    IceCaveJar4 = 470,
    IceCaveJar5 = 471,
    IceCaveMagicShrine = 472,
    CagedWussie = 473,
    AncientStatue3 = 474,
    AncientStatue1 = 475,
    AncientStatue2 = 476,
    DeadBarbarian = 477,
    ClientSmoke = 478,
    IceCaveMagicShrine2 = 479,
    IceCaveTorch1 = 480,
    IceCaveTorch2 = 481,
    ExpansionTikiTorch = 482,
    WorldstoneManaShrine = 483,
    WorldstoneHealthShrine = 484,
    WorldstoneTomb1 = 485,
    WorldstoneTomb2 = 486,
    WorldstoneTomb3 = 487,
    WorldstoneMagicShrine = 488,
    WorldstoneTorch1 = 489,
    WorldstoneTorch2 = 490,
    ExpansionSnowyManaShrine1 = 491,
    ExpansionSnowyHealthShrine = 492,
    ExpansionSnowyWell = 493,
    WorldstoneWaypoint = 494,
    ExpansionSnowyMagicShrine2 = 495,
    ExpansionWildernessWaypoint = 496,
    ExpansionSnowyMagicShrine3 = 497,
    WorldstoneWell = 498,
    WorldstoneMagicShrine2 = 499,
    ExpansionSnowyObject1 = 500,
    ExpansionSnowyWoodChestLeft = 501,
    ExpansionSnowyWoodChestRight = 502,
    WorldstoneMagicShrine3 = 503,
    ExpansionSnowyWoodChest2Left = 504,
    ExpansionSnowyWoodChest2Right = 505,
    SnowySwingingHeads = 506,
    SnowyDebris = 507,
    PenBreakableDoor = 508,
    ExpansionTempleMagicShrine1 = 509,
    ExpansionSnowyPoleMR = 510,
    IceCaveWaypoint = 511,
    ExpansionTempleMagicShrine2 = 512,
    ExpansionTempleWell = 513,
    ExpansionTempleTorch1 = 514,
    ExpansionTempleTorch2 = 515,
    ExpansionTempleObject1 = 516,
    ExpansionTempleObject2 = 517,
    WorldstoneMrBox = 518,
    IceCaveWell = 519,
    ExpansionTempleMagicShrine = 520,
    ExpansionTempleHealthShrine = 521,
    ExpansionTempleManaShrine = 522,
    BlacksmithForge = 523,
    WorldstoneTomb1Left = 524,
    WorldstoneTomb2Left = 525,
    WorldstoneTomb3Left = 526,
    IceCaveBubblesU = 527,
    IceCaveBubblesS = 528,
    RedBaalsLairTomb1 = 529,
    RedBaalsLairTomb1Left = 530,
    RedBaalsLairTomb2 = 531,
    RedBaalsLairTomb2Left = 532,
    RedBaalsLairTomb3 = 533,
    RedBaalsLairTomb3Left = 534,
    RedBaalsLairMrBox = 535,
    RedBaalsLairTorch1 = 536,
    RedBaalsLairTorch2 = 537,
    CandlesTemple = 538,
    TempleWaypoint = 539,
    ExpansionDeadPerson1 = 540,
    TempleGroundTomb = 541,
    LarzukGreeting = 542,
    LarzukStandard = 543,
    TempleGroundTombLeft = 544,
    ExpansionDeadPerson2 = 545,
    AncientsAltar = 546,
    ArreatSummitDoorToWorldstone = 547,
    ExpansionWeaponRackRight = 548,
    ExpansionWeaponRackLeft = 549,
    ExpansionArmorStandRight = 550,
    ExpansionArmorStandLeft = 551,
    ArreatsSummitTorch2 = 552,
    ExpansionFuneralSpire = 553,
    ExpansionBurningLogs = 554,
    IceCaveSteam = 555,
    ExpansionDeadPerson3 = 556,
    BaalsLair = 557,
    FrozenAnya = 558,
    BBQBunny = 559,
    BaalTorchBig = 560,
    InvisibleAncient = 561,
    InvisibleBase = 562,
    BaalsPortal = 563,
    ArreatSummitDoor = 564,
    LastPortal = 565,
    LastLastPortal = 566,
    ZooTestData = 567,
    KeeperTestData = 568,
    BaalsPortal2 = 569,
    FirePlaceGuy = 570,
    DoorBlocker1 = 571,
    DoorBlocker2 = 572,
    CountessChest = 580,

    NotApplicable
};

static bool object_is_useless(int id)
{
    switch (id)
    {
    case GameObject::AmbientSoundGenerator:
    case GameObject::InvisibleRiverSound1:
    case GameObject::InvisibleRiverSound2:
    case GameObject::ForestNightSound1:
    case GameObject::ForestNightSound2:
    case GameObject::InvisibleTownSound:
        return true;
    default:
        return false;
    }
}
static bool object_is_waypoint(int id)

{
    switch (id)
    {
    case GameObject::Act1WildernessWaypoint:
    case GameObject::TempleWaypoint:
    case GameObject::IceCaveWaypoint:
    case GameObject::ExpansionWildernessWaypoint:
    case GameObject::WorldstoneWaypoint:
    case GameObject::ExpansionWaypoint:
    case GameObject::ValleyWaypoint:
    case GameObject::PandamoniumFortressWaypoint:
    case GameObject::Act2SewerWaypoint:
    case GameObject::Act3TravincalWaypoint:
    case GameObject::Act2CellerWaypoint:
    case GameObject::Act3TownWaypoint:
    case GameObject::WaypointH:
    case GameObject::InnerHellWaypoint:
    case GameObject::WaypointPortal:
    case GameObject::Act2Waypoint:
        return true;
    default:
        return false;
    }
}

static bool object_is_shrine(int id)
{
    switch (id)
    {
    case GameObject::Shrine:
        return true;
    default:
        return false;
    }
}
static bool object_is_door(int id)
{
    switch (id)
    {
    case GameObject::DoorGateLeft:
    case GameObject::DoorGateRight:
    case GameObject::DoorWoodenLeft:
    case GameObject::DoorWoodenRight:
    case GameObject::DoorCourtyardLeft:
    case GameObject::DoorCourtyardRight:
    case GameObject::DoorCathedralDouble:
    case GameObject::DoorMonasteryDoubleRight:
    case GameObject::AndarielDoor:
    case GameObject::DoorCathedralLeft:
    case GameObject::DoorCathedralRight:
    case GameObject::DoorWoodenLeft2:
    case GameObject::TrappDoor:
    case GameObject::DoorByAct2Dock:
    case GameObject::TombDoorLeft:
    case GameObject::TombDoorRight:
    case GameObject::TombDoorLeft2:
    case GameObject::TombDoorRight2:
    case GameObject::SecretDoor1:
    case GameObject::TyraelsDoor:
    case GameObject::SlimeDoor1:
    case GameObject::SlimeDoor2:
    case GameObject::IronGrateDoorLeft:
    case GameObject::IronGrateDoorRight:
    case GameObject::WoodenGrateDoorLeft:
    case GameObject::WoodenGrateDoorRight:
    case GameObject::WoodenDoorLeft:
    case GameObject::WoodenDoorRight:
    case GameObject::TeleportationPad1:
    case GameObject::TeleportationPad2:
    case GameObject::TeleportationPad3:
    case GameObject::TeleportationPad4:
    case GameObject::DummyArcaneThing1:
    case GameObject::DummyArcaneThing2:
    case GameObject::DummyArcaneThing3:
    case GameObject::DummyArcaneThing4:
    case GameObject::DummyArcaneThing5:
    case GameObject::DummyArcaneThing6:
    case GameObject::DummyArcaneThing7:
    case GameObject::Act3SewerStairs:
    case GameObject::Act3SewerStairsToLevel3:
    case GameObject::ExpansionTownGate:
    case GameObject::SiegeHellGate:
    case GameObject::PenBreakableDoor:
    case GameObject::ArreatSummitDoorToWorldstone:
        return true;
    default:
        return false;
    }
}
static bool object_is_chest(int id)
{
    switch (id)
    {
    case GameObject::Act1LargeChest1:
    case GameObject::Act1MediumChestRight:
    case GameObject::Act1TallChestRight:
    case GameObject::Act2LargeChestLeft:
    case GameObject::Act2LargeChestRight:
    case GameObject::Act2MediumChestRight:
    case GameObject::ArcaneLargeChestLeft:
    case GameObject::ArcaneLargeChestRight:
    case GameObject::ArcaneSmallChestLeft:
    case GameObject::ArcaneSmallChestRight:
    case GameObject::BurialChestLeft:
    case GameObject::BurialChestRight:
    case GameObject::ExpansionChestLeft:
    case GameObject::ExpansionChestRight:
    case GameObject::ExpansionExplodingChest:
    case GameObject::ExpansionSmallChestLeft:
    case GameObject::ExpansionSmallChestRight:
    case GameObject::ExpansionSnowyWoodChest2Left:
    case GameObject::ExpansionSnowyWoodChest2Right:
    case GameObject::ExpansionSnowyWoodChestLeft:
    case GameObject::ExpansionSnowyWoodChestRight:
    case GameObject::ExpansionSpecialChest:
    case GameObject::ExpansionWoodChestLeft:
    case GameObject::ExpansionWoodChestRight:
    case GameObject::Gchest1L:
    case GameObject::Gchest2R:
    case GameObject::Gchest3R:
    case GameObject::GLchest3L:
    case GameObject::HoradricCubeChest:
    case GameObject::HoradricScrollChest:
    case GameObject::InnerHellBoneChest:
    case GameObject::JungleChest:
    case GameObject::JungleMediumChestLeft:
    case GameObject::KhalimChest1:
    case GameObject::KhalimChest2:
    case GameObject::KhalimChest3:
    case GameObject::LargeChestLeft2:
    case GameObject::LargeChestR:
    case GameObject::LargeChestRight:
    case GameObject::LargeChestLeft:
    case GameObject::MafistoLargeChestLeft:
    case GameObject::MafistoLargeChestRight:
    case GameObject::MafistoMediumChestLeft:
    case GameObject::MafistoMediumChestRight:
    case GameObject::MediumChestLeft:
    case GameObject::SparklyChest:
    case GameObject::SpiderLairLargeChestLeft:
    case GameObject::SpiderLairMediumChestRight:
    case GameObject::SpiderLairTallChestLeft:
    case GameObject::SpiderLairTallChestRight:
    case GameObject::StaffOfKingsChest:
    case GameObject::TallChestLeft:
    case GameObject::TombLargeChestL:
    case GameObject::TombLargeChestR:
        return true;
    default:
        return false;
    }
}
#endif
