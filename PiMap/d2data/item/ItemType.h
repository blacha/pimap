#pragma once

//tolua_begin
namespace ItemType
{
	enum ItemType
	{
		
		// Misc Items
		Elixir,
		PotionOfHealing,		// hp0, unused...
		PotionOfMana,			// mp0, unused...
		FullHealingPotion,		// unused...
		FullManaPotion,			// unused...
		StaminaPotion,
		AntidotePotion,
		RejuvenationPotion,
		FullRejuvenationPotion,
		ThawingPotion,
		TomeOfTownPortal,
		TomeOfIdentify,
		Amulet,
		ViperAmulet,
		Ring,
		Gold,
		BarkScroll,
		DecipheredBarkScroll,
		Arrows,
		Torch,
		Bolts,
		ScrollOfTownPortal,
		ScrollOfIdentify,
		Heart,
		Brain,
		Jawbone,
		Eye,
		Horn,
		Tail,
		Flag,
		Fang,
		Quill,
		Soul,
		Scalp,
		Spleen,
		Key,
		MephistoKey,
		ScrollOfSelfResurrect,
		JadeFigurine,
		GoldBird,
		LamEsensTome,
		HoradricCube,
		HoradricScroll,
		MephistoSoulStone,
		BookOfSkill,
		KhalimsEye,
		KhalimsHeart,
		KhalimsBrain,
		Ear,
		ChippedAmethyst,
		FlawedAmethyst,
		Amethyst,
		FlawlessAmethyst,
		PerfectAmethyst,
		ChippedTopaz,
		FlawedTopaz,
		Topaz,
		FlawlessTopaz,
		PerfectTopaz,
		ChippedSapphire,
		FlawedSapphire,
		Sapphire,
		FlawlessSapphire,
		PerfectSapphire,
		ChippedEmerald,
		FlawedEmerald,
		Emerald,
		FlawlessEmerald,
		PerfectEmerald,
		ChippedRuby,
		FlawedRuby,
		Ruby,
		FlawlessRuby,
		PerfectRuby,
		ChippedDiamond,
		FlawedDiamond,
		Diamond,
		FlawlessDiamond,
		PerfectDiamond,
		MinorHealingPotion,
		LightHealingPotion,
		HealingPotion,
		GreaterHealingPotion,
		SuperHealingPotion,
		MinorManaPotion,
		LightManaPotion,
		ManaPotion,
		GreaterManaPotion,
		SuperManaPotion,
		ChippedSkull,
		FlawedSkull,
		Skull,
		FlawlessSkull,
		PerfectSkull,
		Herb,
		SmallCharm,
		LargeCharm,
		GrandCharm,
		SmallRedPotion,
		LargeRedPotion,
		SmallBluePotion,
		LargeBluePotion,
		ElRune,
		EldRune,
		TirRune,
		NefRune,
		EthRune,
		IthRune,
		TalRune,
		RalRune,
		OrtRune,
		ThulRune,
		AmnRune,
		SolRune,
		ShaelRune,
		DolRune,
		HelRune,
		IoRune,
		LumRune,
		KoRune,
		FalRune,
		LemRune,
		PulRune,
		UmRune,
		MalRune,
		IstRune,
		GulRune,
		VexRune,
		OhmRune,
		LoRune,
		SurRune,
		BerRune,
		JahRune,
		ChamRune,
		ZodRune,
		Jewel,
		Maguffin,
		Scroll,
		ScrollOfMalah,
		KeyOfTerror,
		KeyOfHate,
		KeyOfDestruction,
		DiablosHorn,
		BaalsEye,
		MephistosBrain,
		TokenOfAbsolution,
		EssenseOfSuffering,
		EssenseOfHatred,
		EssenseOfTerror,
		EssenseOfDestruction,
		StandardOfHeroes,
			
		// Armors
		Cap,
		SkullCap,
		Helm,
		FullHelm,
		GreatHelm,
		Crown,
		Mask,
		QuiltedArmor,
		LeatherArmor,
		HardLeatherArmor,
		StuddedLeather,
		RingMail,
		ScaleMail,
		ChainMail,
		BreastPlate,
		SplintMail,
		PlateMail,
		FieldPlate,
		GothicPlate,
		FullPlateMail,
		AncientArmor,
		LightPlate,
		Buckler,
		SmallShield,
		LargeShield,
		KiteShield,
		TowerShield,
		GothicShield,
		Gloves,
		HeavyGloves,
		ChainGloves,
		LightGauntlets,
		Gaunlets,
		LeatherBoots,
		HeavyBoots,
		ChainBoots,
		LightPlateBoots,
		PlateBoots,
		Sash,
		LightBelt,
		Belt,
		HeavyBelt,
		PlatedBelt,
		BoneHelm,
		BoneShield,
		SpikedShield,
		WarHat,
		Sallet,
		Casque,
		Basinet,
		WingedHelm,
		GrandCrown,
		DeathMask,
		GhostArmor,
		SerpentskinArmor,
		DemonhideArmor,
		TrellisedArmor,
		LinkedMail,
		TigulatedMail,
		MeshArmor,
		Cuirass,
		RussetArmor,
		TemplarCoat,
		SharktoothArmor,
		EmbossedPlate,
		ChaosArmor,
		OrnateArmor,
		MagePlate,
		Defender,
		RoundShield,
		Scutum,
		DragonShield,
		Pavise,
		AncientShield,
		DemonhideGloves,
		SharkskinGloves,
		HeavyBracers,
		BattleGauntlets,
		WarGauntlets,
		DemonhideBoots,
		SharkskinBoots,
		MeshBoots,
		BattleBoots,
		WarBoots,
		DemonhideSash,
		SharkskinBelt,
		MeshBelt,
		BattleBelt,
		WarBelt,
		GrimHelm,
		GrimShield,
		BarbedShield,
		WolfHead,
		HawkHelm,
		Antlers,
		FalconMask,
		SpiritMask,
		JawboneCap,
		FangedHelm,
		HornedHelm,
		AssaultHelmet,
		AvengerGuard,
		Targe,
		Rondache,
		HeraldicShield,
		AerinShield,
		CrownShield,
		PreservedHead,
		ZombieHead,
		UnravellerHead,
		GargoyleHead,
		DemonHead,
		Circlet,
		Coronet,
		Tiara,
		Diadem,
		Shako,
		Hydraskull,
		Armet,
		GiantConch,
		SpiredHelm,
		Corona,
		Demonhead,
		DuskShroud,
		Wyrmhide,
		ScarabHusk,
		WireFleece,
		DiamondMail,
		LoricatedMail,
		Boneweave,
		GreatHauberk,
		BalrogSkin,
		HellforgedPlate,
		KrakenShell,
		LacqueredPlate,
		ShadowPlate,
		SacredArmor,
		ArchonPlate,
		Heater,
		Luna,
		Hyperion,
		Monarch,
		Aegis,
		Ward,
		BrambleMitts,
		VampireboneGloves,
		Vambraces,
		CrusaderGauntlets,
		OgreGauntlets,
		WyrmhideBoots,
		ScarabshellBoots,
		BoneweaveBoots,
		MirroredBoots,
		MyrmidonGreaves,
		SpiderwebSash,
		VampirefangBelt,
		MithrilCoil,
		TrollBelt,
		ColossusGirdle,
		BoneVisage,
		TrollNest,
		BladeBarrier,
		AlphaHelm,
		GriffonHeadress,
		HuntersGuise,
		SacredFeathers,
		TotemicMask,
		JawboneVisor,
		LionHelm,
		RageMask,
		SavageHelmet,
		SlayerGuard,
		AkaranTarge,
		AkaranRondache,
		ProtectorShield,
		GuildedShield,
		RoyalShield,
		MummifiedTrophy,
		FetishTrophy,
		SextonTrophy,
		CantorTrophy,
		HeirophantTrophy,
		BloodSpirt,
		SunSpirit,
		EarthSpirit,
		SkySpirit,
		DreamSpirit,
		CarnageHelm,
		FuryVisor,
		DestroyerHelm,
		ConquererCrown,
		GuardianCrown,
		SacredTarge,
		SacredRondache,
		KurastShield,
		ZakarumShield,
		VortexShield,
		MinionSkull,
		HellspawnSkull,
		OverseerSkull,
		SuccubaeSkull,
		BloodlordSkull,
		
		// Weapons
		HandAxe,
		Axe,
		DoubleAxe,
		MilitaryPick,
		WarAxe,
		LargeAxe,
		BroadAxe,
		BattleAxe,
		GreatAxe,
		GiantAxe,
		Wand,
		YewWand,
		BoneWand,
		GrimWand,
		Club,
		Scepter,
		GrandScepter,
		WarScepter,
		SpikedClub,
		Mace,
		MorningStar,
		Flail,
		WarHammer,
		Maul,
		GreatMaul,
		ShortSword,
		Scimitar,
		Saber,
		Falchion,
		CrystalSword,
		BroadSword,
		LongSword,
		WarSword,
		TwoHandedSword,
		Claymore,
		GiantSword,
		BastardSword,
		Flamberge,
		GreatSword,
		Dagger,
		Dirk,
		Kriss,
		Blade,
		ThrowingKnife,
		ThrowingAxe,
		BalancedKnife,
		BalancedAxe,
		Javelin,
		Pilum,
		ShortSpear,
		Glaive,
		ThrowingSpear,
		Spear,
		Trident,
		Brandistock,
		Spetum,
		Pike,
		Bardiche,
		Voulge,
		Scythe,
		Poleaxe,
		Halberd,
		WarScythe,
		ShortStaff,
		LongStaff,
		GnarledStaff,
		BattleStaff,
		WarStaff,
		ShortBow,
		HuntersBow,
		LongBow,
		CompositeBow,
		ShortBattleBow,
		LongBattleBow,
		ShortWarBow,
		LongWarBow,
		LightCrossbow,
		Crossbow,
		HeavyCrossbow,
		RepeatingCrossbow,
		RancidGasPotion,
		OilPotion,
		ChokingGasPotion,
		ExplodingPotion,
		StranglingGasPotion,
		FulminatingPotion,
		DecoyDagger,
		Gidbinn,
		WirtsLeg,
		HoradricMalus,
		HellforgeHammer,
		HoradricStaff,
		StaffOfKings,
		Hatchet,
		Cleaver,
		TwinAxe,
		Crowbill,
		Naga,
		MilitaryAxe,
		BeardedAxe,
		Tabar,
		GothicAxe,
		AncientAxe,
		BurntWand,
		PetrifiedWand,
		TombWand,
		GraveWand,
		Cudgel,
		RuneScepter,
		HolyWaterSprinkler,
		DivineScepter,
		BarbedClub,
		FlangedMace,
		JaggedStar,
		Knout,
		BattleHammer,
		WarClub,
		MartelDeFer,
		Gladius,
		Cutlass,
		Shamshir,
		Tulwar,
		DimensionalBlade,
		BattleSword,
		RuneSword,
		AncientSword,
		Espadon,
		DacianFalx,
		TuskSword,
		GothicSword,
		Zweihander,
		ExecutionerSword,
		Poignard,
		Rondel,
		Cinquedeas,
		Stilleto,
		BattleDart,
		Francisca,
		WarDart,
		Hurlbat,
		WarJavelin,
		GreatPilum,
		Simbilan,
		Spiculum,
		Harpoon,
		WarSpear,
		Fuscina,
		WarFork,
		Yari,
		Lance,
		LochaberAxe,
		Bill,
		BattleScythe,
		Partizan,
		BecDeCorbin,
		GrimScythe,
		JoStaff,
		Quarterstaff,
		CedarStaff,
		GothicStaff,
		RuneStaff,
		EdgeBow,
		RazorBow,
		CedarBow,
		DoubleBow,
		ShortSiegeBow,
		LongSiegeBow,
		RuneBow,
		GothicBow,
		Arbalest,
		SiegeCrossbow,
		Balista,
		ChuKoNu,
		KhalimFlail,
		SuperKhalimFlail,
		Katar,
		WristBlade,
		HatchetHands,
		Cestus,
		Claws,
		BladeTalons,
		ScissorsKatar,
		Quhab,
		WristSpike,
		Fascia,
		HandScythe,
		GreaterClaws,
		GreaterTalons,
		ScissorsQuhab,
		Suwayyah,
		WristSword,
		WarFist,
		BattleCestus,
		FeralClaws,
		RunicTalons,
		ScissorsSuwayyah,
		Tomahawk,
		SmallCrescent,
		EttinAxe,
		WarSpike,
		BerserkerAxe,
		FeralAxe,
		SilverEdgedAxe,
		Decapitator,
		ChampionAxe,
		GloriousAxe,
		PolishedWand,
		GhostWand,
		LichWand,
		UnearthedWand,
		Truncheon,
		MightyScepter,
		SeraphRod,
		Caduceus,
		TyrantClub,
		ReinforcedMace,
		DevilStar,
		Scourge,
		LegendaryMallet,
		OgreMaul,
		ThunderMaul,
		Falcata,
		Ataghan,
		ElegantBlade,
		HydraEdge,
		PhaseBlade,
		ConquestSword,
		CrypticSword,
		MythicalSword,
		LegendSword,
		HighlandBlade,
		BalrogBlade,
		ChampionSword,
		ColossalSword,
		ColossusBlade,
		BoneKnife,
		MithralPoint,
		FangedKnife,
		LegendSpike,
		FlyingKnife,
		FlyingAxe,
		WingedKnife,
		WingedAxe,
		HyperionJavelin,
		StygianPilum,
		BalrogSpear,
		GhostGlaive,
		WingedHarpoon,
		HyperionSpear,
		StygianPike,
		Mancatcher,
		GhostSpear,
		WarPike,
		OgreAxe,
		ColossusVoulge,
		Thresher,
		CrypticAxe,
		GreatPoleaxe,
		GiantThresher,
		WalkingStick,
		Stalagmite,
		ElderStaff,
		Shillelah,
		ArchonStaff,
		SpiderBow,
		BladeBow,
		ShadowBow,
		GreatBow,
		DiamondBow,
		CrusaderBow,
		WardBow,
		HydraBow,
		PelletBow,
		GorgonCrossbow,
		ColossusCrossbow,
		DemonCrossbow,
		EagleOrb,
		SacredGlobe,
		SmokedSphere,
		ClaspedOrb,
		DragonStone,
		StagBow,
		ReflexBow,
		MaidenSpear,
		MaidenPike,
		MaidenJavelin,
		GlowingOrb,
		CrystallineGlobe,
		CloudySphere,
		SparklingBall,
		SwirlingCrystal,
		AshwoodBow,
		CeremonialBow,
		CeremonialSpear,
		CeremonialPike,
		CeremonialJavelin,
		HeavenlyStone,
		EldritchOrb,
		DemonHeart,
		VortexOrb,
		DimensionalShard,
		MatriarchalBow,
		GrandMatronBow,
		MatriarchalSpear,
		MatriarchalPike,
		MatriarchalJavelin,

		Invalid,
        None = -1
	};
};
// tolua_end
