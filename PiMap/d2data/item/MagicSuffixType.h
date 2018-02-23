#pragma once

//tolua_begin
namespace MagicSuffixType
{
    enum MagicSuffixType
    {
        None = 0,
        Health,
        Protection,
        Absorption,
        Life,
        Unused5,
        Warding,
        TheSentinel,
        Guarding,
        Negation,
        Unused10,
        Piercing,
        Bashing,
        Puncturing,
        Thorns,
        Spikes,
        Readiness,
        Alacrity,
        Swiftness,
        Quickness,
        Blocking,
        Deflecting,
        TheApprentice,
        TheMagus,
        Frost,
        TheGlacier,
        Frost2,
        Warmth3,
        Flame,
        Fire,
        Burning,
        Flame2,
        Shock,
        Lightning,
        Thunder,
        Shock2,
        Craftsmanship,
        Quality,
        Maiming,
        Slaying,
        Gore,
        Carnage,
        Slaughter,
        Maiming2,
        Worth,
        Measure,
        Excellence,
        Performance,
        Measure2,
        Blight,
        Venom,
        Pestilence,
        Blight2,
        Dexterity,
        Dexterity2,
        Skill,
        Skill2,
        Accuracy,
        Precision,
        Precision2,
        Perfection,
        Balance,
        Stability,
        Unused63,
        Regeneration,
        Regeneration2,
        Regeneration3,
        Regrowth,
        Regrowth2,
        Vileness,
        Unused70,
        Greed,
        Wealth,
        Chance,
        Fortune,
        Energy,
        Energy2,
        TheMind,
        Brilliance,
        Sorcery,
        Wizardry,
        TheBear,
        Light,
        Radiance,
        TheSun,
        Life2,
        TheJackal,
        TheFox,
        TheWolf,
        TheWolf2,
        TheTiger,
        TheMammoth,
        TheMammoth2,
        TheColosuss,
        TheLeech,
        TheLocust,
        TheBat,
        TheVampire,
        Defiance,
        Amelioration,
        Remedy,
        Unused101,
        Simplicity,
        Ease,
        Unused104,
        Strength,
        Might,
        TheOx,
        TheOx2,
        TheGiant,
        TheGiant2,
        TheTitan4,
        Pacing,
        Haste,
        Speed,
        Health2,
        Protection2,
        Absorption2,
        Life3,
        LifeEverlasting,
        Protection3,
        Absorption3,
        Life4,
        Anima,
        Warding2,
        TheSentinel2,
        Guarding2,
        Negation2,
        TheSentinel3,
        Guarding3,
        Negation3,
        Unused131,
        Unused132,
        Unused133,
        Unused134,
        Unused135,
        Unused136,
        Unused137,
        Unused138,
        Unused139,
        Unused140,
        Unused141,
        Unused142,
        Unused143,
        Unused144,
        Unused145,
        Unused146,
        Unused147,
        Unused148,
        Unused149,
        Unused150,
        Unused151,
        Unused152,
        Unused153,
        Unused154,
        Unused155,
        Unused156,
        Unused157,
        Piercing2,
        Unused158,
        Unused159,
        Thorns2,
        Spikes2,
        Razors,
        Swords,
        Malice,
        Readiness2,
        Alacrity2,
        Swiftness2,
        Quickness2,
        Alacrity3,
        Fervor,
        Blocking2,
        Deflecting2,
        TheApprentice2,
        TheMagus2,
        Frost3,
        TheIcicle,
        TheGlacier2,
        Winter,
        Frost4,
        Frigidity,
        Warmth2,
        Flame3,
        Fire2,
        Burning2,
        Incineration,
        Flame4,
        Passion,
        Shock3,
        Lightning2,
        Thunder2,
        Storms,
        Shock4,
        Ennui,
        Craftsmanship2,
        Quality2,
        Maiming3,
        Slaying2,
        Gore2,
        Carnage2,
        Slaughter2,
        Butchery,
        Evisceration,
        Maiming4,
        Craftsmanship3,
        Craftsmanship4,
        Craftsmanship5,
        Quality3,
        Quality4,
        Maiming5,
        Maiming6,
        Unused212,
        Unused213,
        Unused214,
        Unused215,
        Unused216,
        Unused217,
        Unused218,
        Unused219,
        Ire,
        Wrath,
        Carnage3,
        Worth2,
        Measure3,
        Excellence2,
        Performance2,
        Transcendence,
        Worth3,
        Measure4,
        Excellence3,
        Performance3,
        Joyfulness,
        Bliss,
        Blight3,
        Venom2,
        Pestilence2,
        Anthrax,
        Blight4,
        Envy,
        Dexterity3,
        Skill3,
        Accuracy2,
        Precision3,
        Perfection2,
        Nirvana,
        Dexterity4,
        Skill4,
        Accuracy3,
        Precision4,
        Perfection3,
        Dexterity5,
        Skill5,
        Accuracy4,
        Precision5,
        Dexterity6,
        Dexterity7,
        Dexterity8,
        Dexterity9,
        Dexterity10,
        Dexterity11,
        Daring,
        Balance2,
        Equilibrium,
        Stability2,
        Balance3,
        Balance4,
        Balance5,
        Truth,
        Regeneration4,
        Regeneration5,
        Regeneration6,
        Regrowth3,
        Regrowth4,
        Revivification,
        Honor,
        Vileness2,
        Greed2,
        Wealth2,
        Greed3,
        Greed4,
        Greed5,
        Greed6,
        Greed7,
        Greed8,
        Avarice,
        Chance2,
        Fortune3,
        Fortune4,
        Luck,
        Fortune5,
        GoodLuck,
        Prosperity,
        Energy3,
        TheMind2,
        Brilliance2,
        Sorcery2,
        Wizardry2,
        Enlightenment,
        Energy4,
        TheMind3,
        Brilliance3,
        Sorcery3,
        Wizardry3,
        Energy5,
        TheMind4,
        Brilliance4,
        Sorcery4,
        Knowledge,
        TheBear2,
        Light2,
        Radiance2,
        TheSun2,
        TheJackal2,
        TheFox2,
        TheWolf3,
        TheTiger2,
        TheMammoth3,
        TheColosuss2,
        TheSquid,
        TheWhale,
        TheJackal3,
        TheFox3,
        TheWolf4,
        TheTiger3,
        TheMammoth4,
        TheColosuss3,
        TheJackal4,
        TheFox4,
        TheWolf5,
        TheTiger4,
        TheMammoth5,
        Life5,
        Life6,
        Life7,
        Substinence,
        Substinence2,
        Substinence3,
        Vita,
        Vita2,
        Vita3,
        Life8,
        Life9,
        Substinence4,
        Substinence5,
        Vita4,
        Vita5,
        Life10,
        Substinence6,
        Vita6,
        Spirit,
        Hope,
        TheLeech2,
        TheLocust2,
        TheLamprey,
        TheLeech3,
        TheLocust3,
        TheLamprey2,
        TheLeech4,
        TheBat2,
        TheWraith,
        TheVampire2,
        TheBat3,
        TheWraith2,
        TheVampire3,
        TheBat4,
        Defiance2,
        Amelioration2,
        Remedy2,
        Simplicity2,
        Ease2,
        Freedom,
        Strength2,
        Might2,
        TheOx3,
        TheGiant3,
        TheTitan2,
        Atlus,
        Strength3,
        Might3,
        TheOx4,
        TheGiant4,
        TheTitan3,
        Strength4,
        Might4,
        TheOx5,
        TheGiant5,
        Strength5,
        Strength6,
        Strength7,
        Strength8,
        Strength9,
        Strength10,
        Virility,
        Pacing2,
        Haste2,
        Speed2,
        Traveling,
        Acceleration,
        Inertia,
        Inertia2,
        Inertia3,
        Self,
        FastRepair,
        Ages,
        Replenishing,
        Propogation,
        TheKraken,
        Memory,
        TheElephant,
        Unused410,
        Unused411,
        Unused412,
        Unused413,
        Unused414,
        Unused415,
        Unused416,
        Unused417,
        Firebolts,
        Firebolts2,
        Firebolts3,
        ChargedShield,
        ChargedShield2,
        ChargedShield3,
        Icebolt,
        Unused425,
        Unused426,
        Unused427,
        FrostShield,
        Unused429,
        Unused430,
        Unused431,
        Nova,
        Nova2,
        NovaShield,
        NovaShield2,
        NovaShield3,
        Lightning3,
        Unused438,
        Unused439,
        Unused440,
        Unused441,
        ChainLightning,
        ChainLightning2,
        ChainLightning3,
        Unused445,
        Unused446,
        Unused447,
        Unused448,
        Unused449,
        Unused450,
        Unused451,
        Unused452,
        Unused453,
        HydraShield,
        Unused455,
        Unused456,
        Unused457,
        MagicArrows,
        Unused459,
        Unused460,
        FireArrows,
        InnerSight,
        InnerSight2,
        Unused464,
        Unused465,
        ColdArrows,
        ColdArrows2,
        MultipleShot,
        MultipleShot2,
        PowerStrike,
        PowerStrike2,
        Unused472,
        Unused473,
        ExplodingArrows,
        ExplodingArrows2,
        Unused476,
        Unused477,
        Unused478,
        Unused479,
        Unused480,
        Unused481,
        IceArrows,
        IceArrows2,
        Unused484,
        Unused485,
        ChargedStrike,
        ChargedStrike2,
        Unused488,
        Unused489,
        Unused490,
        Unused491,
        Unused492,
        Unused493,
        FreezingArrows,
        FreezingArrows2,
        LightningStrike,
        LightningStrike2,
        Unused498,
        Unused499,
        FireBolts,
        FireBolts2,
        ChargedBolts,
        ChargedBolts2,
        IceBolts,
        IceBolts2,
        Unused506,
        Unused507,
        Unused508,
        Unused509,
        Telekinesis,
        Telekinesis2,
        FrostNovas,
        FrostNovas2,
        IceBlasts,
        IceBlasts2,
        Unused516,
        Unused517,
        FireBalls,
        FireBalls2,
        Novas,
        Novas2,
        Lightning4,
        Lightning5,
        Unused524,
        Unused525,
        Unused526,
        Unused527,
        Enchantment,
        Enchantment2,
        ChainLightning4,
        ChainLightning5,
        Teleportation,
        Teleportation2,
        GlacialSpikes,
        GlacialSpikes2,
        Meteors,
        Meteors2,
        Unused538,
        Unused539,
        Unused540,
        Unused541,
        Blizzards,
        Blizzards2,
        Unused544,
        Unused545,
        Unused546,
        Unused547,
        FrozenOrbs,
        FrozenOrbs2,
        Unused550,
        Unused551,
        Teeth,
        Teeth2,
        Unused554,
        Unused555,
        Unused556,
        Unused557,
        DimVision,
        DimVision2,
        Weaken,
        Weaken2,
        PoisonDagger,
        PoisonDagger2,
        Unused564,
        Unused565,
        Unused566,
        Unused567,
        Unused568,
        Unused569,
        Terror,
        Terror2,
        Unused572,
        Unused573,
        Unused574,
        Unused575,
        Confusion,
        Confusion2,
        LifeTap,
        LifeTap2,
        Unused580,
        Unused581,
        BoneSpears,
        BoneSpears2,
        Unused584,
        Unused585,
        Attraction,
        Attraction2,
        Unused588,
        Unused589,
        Unused590,
        Unused591,
        Unused592,
        Unused593,
        LowerResistance,
        LowerResistance2,
        PoisonNovas,
        PoisonNovas2,
        BoneSpirits,
        BoneSpirits2,
        Unused600,
        Unused601,
        Unused602,
        Unused603,
        Sacrifice,
        Sacrifice2,
        HolyBolts,
        HolyBolts2,
        Zeal,
        Zeal2,
        Vengeance,
        Vengeance2,
        BlessedHammers,
        BlessedHammers2,
        Unused614,
        Unused615,
        Unused616,
        Unused617,
        Bashing2,
        Bashing3,
        Unused620,
        Unused621,
        Unused622,
        Unused623,
        Unused624,
        Unused625,
        Unused626,
        Unused627,
        Stunning,
        Stunning2,
        Unused630,
        Unused631,
        Concentration,
        Concentration2,
        Unused634,
        Unused635,
        Unused636,
        Unused637,
        GrimWard,
        GrimWard2,
        Unused640,
        Unused641,
        Unused642,
        Unused643,
        Firestorms,
        Firestorms2,
        Unused644,
        Unused645,
        Eruption,
        Eruption2,
        Unused650,
        Unused651,
        Twister,
        Twister2,
        Volcano,
        Volcano2,
        Tornado,
        Tornado2,
        Unused658,
        Unused659,
        Unused660,
        Unused661,
        DamageAmplification,
        TheIcicle2,
        TheGlacier3,
        Fire3,
        Burning3,
        Lightning6,
        Thunder3,
        Daring2,
        Daring3,
        Knowledge2,
        Knowledge3,
        Virility2,
        Virility3,
        Readiness3,
        Craftsmanship6,
        Quality5,
        Maiming7,
        Craftsmanship7,
        Quality6,
        Craftsmanship8,
        Blight5,
        Venom3,
        Pestilence3,
        Anthrax2,
        Blight6,
        Venom4,
        Pestilence4,
        Anthrax3,
        Blight7,
        Venom5,
        Pestilence5,
        Anthrax4,
        Frost5,
        TheIcicle3,
        TheGlacier4,
        Winter2,
        Frost6,
        TheIcicle4,
        TheGlacier5,
        Winter3,
        Frost7,
        TheIcicle5,
        TheGlacier6,
        Winter4,
        Flame5,
        Fire4,
        Burning4,
        Incineration2,
        Flame6,
        Fire5,
        Burning5,
        Incineration3,
        Flame7,
        Fire6,
        Burning6,
        Incineration4,
        Shock5,
        Lightning7,
        Thunder4,
        Storms2,
        Shock6,
        Lightning8,
        Thunder5,
        Storms3,
        Shock7,
        Lightning9,
        Thunder6,
        Storms4,
        Dexterity12,
        Dexterity13,
        Strength11,
        Strength12,
        Thorns3,
        Frost8,
        Flame8,
        Blight8,
        Shock8,
        Regeneration7,
        Energy6,
        Light3,
        TheLeech5,
        TheLocust4,
        TheLamprey3,
        TheBat5,
        TheWraith3,
        TheVampire4,
    };

	static std::string toString(MagicSuffixType input)
	{
		switch (input)
		{
			case None: return "None";
			case Health: return "Health";
			case Protection: return "Protection";
			case Absorption: return "Absorption";
			case Life: return "Life";
			case Unused5: return "Unused5";
			case Warding: return "Warding";
			case TheSentinel: return "TheSentinel";
			case Guarding: return "Guarding";
			case Negation: return "Negation";
			case Unused10: return "Unused10";
			case Piercing: return "Piercing";
			case Bashing: return "Bashing";
			case Puncturing: return "Puncturing";
			case Thorns: return "Thorns";
			case Spikes: return "Spikes";
			case Readiness: return "Readiness";
			case Alacrity: return "Alacrity";
			case Swiftness: return "Swiftness";
			case Quickness: return "Quickness";
			case Blocking: return "Blocking";
			case Deflecting: return "Deflecting";
			case TheApprentice: return "TheApprentice";
			case TheMagus: return "TheMagus";
			case Frost: return "Frost";
			case TheGlacier: return "TheGlacier";
			case Frost2: return "Frost2";
			case Warmth3: return "Warmth3";
			case Flame: return "Flame";
			case Fire: return "Fire";
			case Burning: return "Burning";
			case Flame2: return "Flame2";
			case Shock: return "Shock";
			case Lightning: return "Lightning";
			case Thunder: return "Thunder";
			case Shock2: return "Shock2";
			case Craftsmanship: return "Craftsmanship";
			case Quality: return "Quality";
			case Maiming: return "Maiming";
			case Slaying: return "Slaying";
			case Gore: return "Gore";
			case Carnage: return "Carnage";
			case Slaughter: return "Slaughter";
			case Maiming2: return "Maiming2";
			case Worth: return "Worth";
			case Measure: return "Measure";
			case Excellence: return "Excellence";
			case Performance: return "Performance";
			case Measure2: return "Measure2";
			case Blight: return "Blight";
			case Venom: return "Venom";
			case Pestilence: return "Pestilence";
			case Blight2: return "Blight2";
			case Dexterity: return "Dexterity";
			case Dexterity2: return "Dexterity2";
			case Skill: return "Skill";
			case Skill2: return "Skill2";
			case Accuracy: return "Accuracy";
			case Precision: return "Precision";
			case Precision2: return "Precision2";
			case Perfection: return "Perfection";
			case Balance: return "Balance";
			case Stability: return "Stability";
			case Unused63: return "Unused63";
			case Regeneration: return "Regeneration";
			case Regeneration2: return "Regeneration2";
			case Regeneration3: return "Regeneration3";
			case Regrowth: return "Regrowth";
			case Regrowth2: return "Regrowth2";
			case Vileness: return "Vileness";
			case Unused70: return "Unused70";
			case Greed: return "Greed";
			case Wealth: return "Wealth";
			case Chance: return "Chance";
			case Fortune: return "Fortune";
			case Energy: return "Energy";
			case Energy2: return "Energy2";
			case TheMind: return "TheMind";
			case Brilliance: return "Brilliance";
			case Sorcery: return "Sorcery";
			case Wizardry: return "Wizardry";
			case TheBear: return "TheBear";
			case Light: return "Light";
			case Radiance: return "Radiance";
			case TheSun: return "TheSun";
			case Life2: return "Life2";
			case TheJackal: return "TheJackal";
			case TheFox: return "TheFox";
			case TheWolf: return "TheWolf";
			case TheWolf2: return "TheWolf2";
			case TheTiger: return "TheTiger";
			case TheMammoth: return "TheMammoth";
			case TheMammoth2: return "TheMammoth2";
			case TheColosuss: return "TheColosuss";
			case TheLeech: return "TheLeech";
			case TheLocust: return "TheLocust";
			case TheBat: return "TheBat";
			case TheVampire: return "TheVampire";
			case Defiance: return "Defiance";
			case Amelioration: return "Amelioration";
			case Remedy: return "Remedy";
			case Unused101: return "Unused101";
			case Simplicity: return "Simplicity";
			case Ease: return "Ease";
			case Unused104: return "Unused104";
			case Strength: return "Strength";
			case Might: return "Might";
			case TheOx: return "TheOx";
			case TheOx2: return "TheOx2";
			case TheGiant: return "TheGiant";
			case TheGiant2: return "TheGiant2";
			case TheTitan4: return "TheTitan4";
			case Pacing: return "Pacing";
			case Haste: return "Haste";
			case Speed: return "Speed";
			case Health2: return "Health2";
			case Protection2: return "Protection2";
			case Absorption2: return "Absorption2";
			case Life3: return "Life3";
			case LifeEverlasting: return "LifeEverlasting";
			case Protection3: return "Protection3";
			case Absorption3: return "Absorption3";
			case Life4: return "Life4";
			case Anima: return "Anima";
			case Warding2: return "Warding2";
			case TheSentinel2: return "TheSentinel2";
			case Guarding2: return "Guarding2";
			case Negation2: return "Negation2";
			case TheSentinel3: return "TheSentinel3";
			case Guarding3: return "Guarding3";
			case Negation3: return "Negation3";
			case Unused131: return "Unused131";
			case Unused132: return "Unused132";
			case Unused133: return "Unused133";
			case Unused134: return "Unused134";
			case Unused135: return "Unused135";
			case Unused136: return "Unused136";
			case Unused137: return "Unused137";
			case Unused138: return "Unused138";
			case Unused139: return "Unused139";
			case Unused140: return "Unused140";
			case Unused141: return "Unused141";
			case Unused142: return "Unused142";
			case Unused143: return "Unused143";
			case Unused144: return "Unused144";
			case Unused145: return "Unused145";
			case Unused146: return "Unused146";
			case Unused147: return "Unused147";
			case Unused148: return "Unused148";
			case Unused149: return "Unused149";
			case Unused150: return "Unused150";
			case Unused151: return "Unused151";
			case Unused152: return "Unused152";
			case Unused153: return "Unused153";
			case Unused154: return "Unused154";
			case Unused155: return "Unused155";
			case Unused156: return "Unused156";
			case Unused157: return "Unused157";
			case Piercing2: return "Piercing2";
			case Unused158: return "Unused158";
			case Unused159: return "Unused159";
			case Thorns2: return "Thorns2";
			case Spikes2: return "Spikes2";
			case Razors: return "Razors";
			case Swords: return "Swords";
			case Malice: return "Malice";
			case Readiness2: return "Readiness2";
			case Alacrity2: return "Alacrity2";
			case Swiftness2: return "Swiftness2";
			case Quickness2: return "Quickness2";
			case Alacrity3: return "Alacrity3";
			case Fervor: return "Fervor";
			case Blocking2: return "Blocking2";
			case Deflecting2: return "Deflecting2";
			case TheApprentice2: return "TheApprentice2";
			case TheMagus2: return "TheMagus2";
			case Frost3: return "Frost3";
			case TheIcicle: return "TheIcicle";
			case TheGlacier2: return "TheGlacier2";
			case Winter: return "Winter";
			case Frost4: return "Frost4";
			case Frigidity: return "Frigidity";
			case Warmth2: return "Warmth2";
			case Flame3: return "Flame3";
			case Fire2: return "Fire2";
			case Burning2: return "Burning2";
			case Incineration: return "Incineration";
			case Flame4: return "Flame4";
			case Passion: return "Passion";
			case Shock3: return "Shock3";
			case Lightning2: return "Lightning2";
			case Thunder2: return "Thunder2";
			case Storms: return "Storms";
			case Shock4: return "Shock4";
			case Ennui: return "Ennui";
			case Craftsmanship2: return "Craftsmanship2";
			case Quality2: return "Quality2";
			case Maiming3: return "Maiming3";
			case Slaying2: return "Slaying2";
			case Gore2: return "Gore2";
			case Carnage2: return "Carnage2";
			case Slaughter2: return "Slaughter2";
			case Butchery: return "Butchery";
			case Evisceration: return "Evisceration";
			case Maiming4: return "Maiming4";
			case Craftsmanship3: return "Craftsmanship3";
			case Craftsmanship4: return "Craftsmanship4";
			case Craftsmanship5: return "Craftsmanship5";
			case Quality3: return "Quality3";
			case Quality4: return "Quality4";
			case Maiming5: return "Maiming5";
			case Maiming6: return "Maiming6";
			case Unused212: return "Unused212";
			case Unused213: return "Unused213";
			case Unused214: return "Unused214";
			case Unused215: return "Unused215";
			case Unused216: return "Unused216";
			case Unused217: return "Unused217";
			case Unused218: return "Unused218";
			case Unused219: return "Unused219";
			case Ire: return "Ire";
			case Wrath: return "Wrath";
			case Carnage3: return "Carnage3";
			case Worth2: return "Worth2";
			case Measure3: return "Measure3";
			case Excellence2: return "Excellence2";
			case Performance2: return "Performance2";
			case Transcendence: return "Transcendence";
			case Worth3: return "Worth3";
			case Measure4: return "Measure4";
			case Excellence3: return "Excellence3";
			case Performance3: return "Performance3";
			case Joyfulness: return "Joyfulness";
			case Bliss: return "Bliss";
			case Blight3: return "Blight3";
			case Venom2: return "Venom2";
			case Pestilence2: return "Pestilence2";
			case Anthrax: return "Anthrax";
			case Blight4: return "Blight4";
			case Envy: return "Envy";
			case Dexterity3: return "Dexterity3";
			case Skill3: return "Skill3";
			case Accuracy2: return "Accuracy2";
			case Precision3: return "Precision3";
			case Perfection2: return "Perfection2";
			case Nirvana: return "Nirvana";
			case Dexterity4: return "Dexterity4";
			case Skill4: return "Skill4";
			case Accuracy3: return "Accuracy3";
			case Precision4: return "Precision4";
			case Perfection3: return "Perfection3";
			case Dexterity5: return "Dexterity5";
			case Skill5: return "Skill5";
			case Accuracy4: return "Accuracy4";
			case Precision5: return "Precision5";
			case Dexterity6: return "Dexterity6";
			case Dexterity7: return "Dexterity7";
			case Dexterity8: return "Dexterity8";
			case Dexterity9: return "Dexterity9";
			case Dexterity10: return "Dexterity10";
			case Dexterity11: return "Dexterity11";
			case Daring: return "Daring";
			case Balance2: return "Balance2";
			case Equilibrium: return "Equilibrium";
			case Stability2: return "Stability2";
			case Balance3: return "Balance3";
			case Balance4: return "Balance4";
			case Balance5: return "Balance5";
			case Truth: return "Truth";
			case Regeneration4: return "Regeneration4";
			case Regeneration5: return "Regeneration5";
			case Regeneration6: return "Regeneration6";
			case Regrowth3: return "Regrowth3";
			case Regrowth4: return "Regrowth4";
			case Revivification: return "Revivification";
			case Honor: return "Honor";
			case Vileness2: return "Vileness2";
			case Greed2: return "Greed2";
			case Wealth2: return "Wealth2";
			case Greed3: return "Greed3";
			case Greed4: return "Greed4";
			case Greed5: return "Greed5";
			case Greed6: return "Greed6";
			case Greed7: return "Greed7";
			case Greed8: return "Greed8";
			case Avarice: return "Avarice";
			case Chance2: return "Chance2";
			case Fortune3: return "Fortune3";
			case Fortune4: return "Fortune4";
			case Luck: return "Luck";
			case Fortune5: return "Fortune5";
			case GoodLuck: return "GoodLuck";
			case Prosperity: return "Prosperity";
			case Energy3: return "Energy3";
			case TheMind2: return "TheMind2";
			case Brilliance2: return "Brilliance2";
			case Sorcery2: return "Sorcery2";
			case Wizardry2: return "Wizardry2";
			case Enlightenment: return "Enlightenment";
			case Energy4: return "Energy4";
			case TheMind3: return "TheMind3";
			case Brilliance3: return "Brilliance3";
			case Sorcery3: return "Sorcery3";
			case Wizardry3: return "Wizardry3";
			case Energy5: return "Energy5";
			case TheMind4: return "TheMind4";
			case Brilliance4: return "Brilliance4";
			case Sorcery4: return "Sorcery4";
			case Knowledge: return "Knowledge";
			case TheBear2: return "TheBear2";
			case Light2: return "Light2";
			case Radiance2: return "Radiance2";
			case TheSun2: return "TheSun2";
			case TheJackal2: return "TheJackal2";
			case TheFox2: return "TheFox2";
			case TheWolf3: return "TheWolf3";
			case TheTiger2: return "TheTiger2";
			case TheMammoth3: return "TheMammoth3";
			case TheColosuss2: return "TheColosuss2";
			case TheSquid: return "TheSquid";
			case TheWhale: return "TheWhale";
			case TheJackal3: return "TheJackal3";
			case TheFox3: return "TheFox3";
			case TheWolf4: return "TheWolf4";
			case TheTiger3: return "TheTiger3";
			case TheMammoth4: return "TheMammoth4";
			case TheColosuss3: return "TheColosuss3";
			case TheJackal4: return "TheJackal4";
			case TheFox4: return "TheFox4";
			case TheWolf5: return "TheWolf5";
			case TheTiger4: return "TheTiger4";
			case TheMammoth5: return "TheMammoth5";
			case Life5: return "Life5";
			case Life6: return "Life6";
			case Life7: return "Life7";
			case Substinence: return "Substinence";
			case Substinence2: return "Substinence2";
			case Substinence3: return "Substinence3";
			case Vita: return "Vita";
			case Vita2: return "Vita2";
			case Vita3: return "Vita3";
			case Life8: return "Life8";
			case Life9: return "Life9";
			case Substinence4: return "Substinence4";
			case Substinence5: return "Substinence5";
			case Vita4: return "Vita4";
			case Vita5: return "Vita5";
			case Life10: return "Life10";
			case Substinence6: return "Substinence6";
			case Vita6: return "Vita6";
			case Spirit: return "Spirit";
			case Hope: return "Hope";
			case TheLeech2: return "TheLeech2";
			case TheLocust2: return "TheLocust2";
			case TheLamprey: return "TheLamprey";
			case TheLeech3: return "TheLeech3";
			case TheLocust3: return "TheLocust3";
			case TheLamprey2: return "TheLamprey2";
			case TheLeech4: return "TheLeech4";
			case TheBat2: return "TheBat2";
			case TheWraith: return "TheWraith";
			case TheVampire2: return "TheVampire2";
			case TheBat3: return "TheBat3";
			case TheWraith2: return "TheWraith2";
			case TheVampire3: return "TheVampire3";
			case TheBat4: return "TheBat4";
			case Defiance2: return "Defiance2";
			case Amelioration2: return "Amelioration2";
			case Remedy2: return "Remedy2";
			case Simplicity2: return "Simplicity2";
			case Ease2: return "Ease2";
			case Freedom: return "Freedom";
			case Strength2: return "Strength2";
			case Might2: return "Might2";
			case TheOx3: return "TheOx3";
			case TheGiant3: return "TheGiant3";
			case TheTitan2: return "TheTitan2";
			case Atlus: return "Atlus";
			case Strength3: return "Strength3";
			case Might3: return "Might3";
			case TheOx4: return "TheOx4";
			case TheGiant4: return "TheGiant4";
			case TheTitan3: return "TheTitan3";
			case Strength4: return "Strength4";
			case Might4: return "Might4";
			case TheOx5: return "TheOx5";
			case TheGiant5: return "TheGiant5";
			case Strength5: return "Strength5";
			case Strength6: return "Strength6";
			case Strength7: return "Strength7";
			case Strength8: return "Strength8";
			case Strength9: return "Strength9";
			case Strength10: return "Strength10";
			case Virility: return "Virility";
			case Pacing2: return "Pacing2";
			case Haste2: return "Haste2";
			case Speed2: return "Speed2";
			case Traveling: return "Traveling";
			case Acceleration: return "Acceleration";
			case Inertia: return "Inertia";
			case Inertia2: return "Inertia2";
			case Inertia3: return "Inertia3";
			case Self: return "Self";
			case FastRepair: return "FastRepair";
			case Ages: return "Ages";
			case Replenishing: return "Replenishing";
			case Propogation: return "Propogation";
			case TheKraken: return "TheKraken";
			case Memory: return "Memory";
			case TheElephant: return "TheElephant";
			case Unused410: return "Unused410";
			case Unused411: return "Unused411";
			case Unused412: return "Unused412";
			case Unused413: return "Unused413";
			case Unused414: return "Unused414";
			case Unused415: return "Unused415";
			case Unused416: return "Unused416";
			case Unused417: return "Unused417";
			case Firebolts: return "Firebolts";
			case Firebolts2: return "Firebolts2";
			case Firebolts3: return "Firebolts3";
			case ChargedShield: return "ChargedShield";
			case ChargedShield2: return "ChargedShield2";
			case ChargedShield3: return "ChargedShield3";
			case Icebolt: return "Icebolt";
			case Unused425: return "Unused425";
			case Unused426: return "Unused426";
			case Unused427: return "Unused427";
			case FrostShield: return "FrostShield";
			case Unused429: return "Unused429";
			case Unused430: return "Unused430";
			case Unused431: return "Unused431";
			case Nova: return "Nova";
			case Nova2: return "Nova2";
			case NovaShield: return "NovaShield";
			case NovaShield2: return "NovaShield2";
			case NovaShield3: return "NovaShield3";
			case Lightning3: return "Lightning3";
			case Unused438: return "Unused438";
			case Unused439: return "Unused439";
			case Unused440: return "Unused440";
			case Unused441: return "Unused441";
			case ChainLightning: return "ChainLightning";
			case ChainLightning2: return "ChainLightning2";
			case ChainLightning3: return "ChainLightning3";
			case Unused445: return "Unused445";
			case Unused446: return "Unused446";
			case Unused447: return "Unused447";
			case Unused448: return "Unused448";
			case Unused449: return "Unused449";
			case Unused450: return "Unused450";
			case Unused451: return "Unused451";
			case Unused452: return "Unused452";
			case Unused453: return "Unused453";
			case HydraShield: return "HydraShield";
			case Unused455: return "Unused455";
			case Unused456: return "Unused456";
			case Unused457: return "Unused457";
			case MagicArrows: return "MagicArrows";
			case Unused459: return "Unused459";
			case Unused460: return "Unused460";
			case FireArrows: return "FireArrows";
			case InnerSight: return "InnerSight";
			case InnerSight2: return "InnerSight2";
			case Unused464: return "Unused464";
			case Unused465: return "Unused465";
			case ColdArrows: return "ColdArrows";
			case ColdArrows2: return "ColdArrows2";
			case MultipleShot: return "MultipleShot";
			case MultipleShot2: return "MultipleShot2";
			case PowerStrike: return "PowerStrike";
			case PowerStrike2: return "PowerStrike2";
			case Unused472: return "Unused472";
			case Unused473: return "Unused473";
			case ExplodingArrows: return "ExplodingArrows";
			case ExplodingArrows2: return "ExplodingArrows2";
			case Unused476: return "Unused476";
			case Unused477: return "Unused477";
			case Unused478: return "Unused478";
			case Unused479: return "Unused479";
			case Unused480: return "Unused480";
			case Unused481: return "Unused481";
			case IceArrows: return "IceArrows";
			case IceArrows2: return "IceArrows2";
			case Unused484: return "Unused484";
			case Unused485: return "Unused485";
			case ChargedStrike: return "ChargedStrike";
			case ChargedStrike2: return "ChargedStrike2";
			case Unused488: return "Unused488";
			case Unused489: return "Unused489";
			case Unused490: return "Unused490";
			case Unused491: return "Unused491";
			case Unused492: return "Unused492";
			case Unused493: return "Unused493";
			case FreezingArrows: return "FreezingArrows";
			case FreezingArrows2: return "FreezingArrows2";
			case LightningStrike: return "LightningStrike";
			case LightningStrike2: return "LightningStrike2";
			case Unused498: return "Unused498";
			case Unused499: return "Unused499";
			case FireBolts: return "FireBolts";
			case FireBolts2: return "FireBolts2";
			case ChargedBolts: return "ChargedBolts";
			case ChargedBolts2: return "ChargedBolts2";
			case IceBolts: return "IceBolts";
			case IceBolts2: return "IceBolts2";
			case Unused506: return "Unused506";
			case Unused507: return "Unused507";
			case Unused508: return "Unused508";
			case Unused509: return "Unused509";
			case Telekinesis: return "Telekinesis";
			case Telekinesis2: return "Telekinesis2";
			case FrostNovas: return "FrostNovas";
			case FrostNovas2: return "FrostNovas2";
			case IceBlasts: return "IceBlasts";
			case IceBlasts2: return "IceBlasts2";
			case Unused516: return "Unused516";
			case Unused517: return "Unused517";
			case FireBalls: return "FireBalls";
			case FireBalls2: return "FireBalls2";
			case Novas: return "Novas";
			case Novas2: return "Novas2";
			case Lightning4: return "Lightning4";
			case Lightning5: return "Lightning5";
			case Unused524: return "Unused524";
			case Unused525: return "Unused525";
			case Unused526: return "Unused526";
			case Unused527: return "Unused527";
			case Enchantment: return "Enchantment";
			case Enchantment2: return "Enchantment2";
			case ChainLightning4: return "ChainLightning4";
			case ChainLightning5: return "ChainLightning5";
			case Teleportation: return "Teleportation";
			case Teleportation2: return "Teleportation2";
			case GlacialSpikes: return "GlacialSpikes";
			case GlacialSpikes2: return "GlacialSpikes2";
			case Meteors: return "Meteors";
			case Meteors2: return "Meteors2";
			case Unused538: return "Unused538";
			case Unused539: return "Unused539";
			case Unused540: return "Unused540";
			case Unused541: return "Unused541";
			case Blizzards: return "Blizzards";
			case Blizzards2: return "Blizzards2";
			case Unused544: return "Unused544";
			case Unused545: return "Unused545";
			case Unused546: return "Unused546";
			case Unused547: return "Unused547";
			case FrozenOrbs: return "FrozenOrbs";
			case FrozenOrbs2: return "FrozenOrbs2";
			case Unused550: return "Unused550";
			case Unused551: return "Unused551";
			case Teeth: return "Teeth";
			case Teeth2: return "Teeth2";
			case Unused554: return "Unused554";
			case Unused555: return "Unused555";
			case Unused556: return "Unused556";
			case Unused557: return "Unused557";
			case DimVision: return "DimVision";
			case DimVision2: return "DimVision2";
			case Weaken: return "Weaken";
			case Weaken2: return "Weaken2";
			case PoisonDagger: return "PoisonDagger";
			case PoisonDagger2: return "PoisonDagger2";
			case Unused564: return "Unused564";
			case Unused565: return "Unused565";
			case Unused566: return "Unused566";
			case Unused567: return "Unused567";
			case Unused568: return "Unused568";
			case Unused569: return "Unused569";
			case Terror: return "Terror";
			case Terror2: return "Terror2";
			case Unused572: return "Unused572";
			case Unused573: return "Unused573";
			case Unused574: return "Unused574";
			case Unused575: return "Unused575";
			case Confusion: return "Confusion";
			case Confusion2: return "Confusion2";
			case LifeTap: return "LifeTap";
			case LifeTap2: return "LifeTap2";
			case Unused580: return "Unused580";
			case Unused581: return "Unused581";
			case BoneSpears: return "BoneSpears";
			case BoneSpears2: return "BoneSpears2";
			case Unused584: return "Unused584";
			case Unused585: return "Unused585";
			case Attraction: return "Attraction";
			case Attraction2: return "Attraction2";
			case Unused588: return "Unused588";
			case Unused589: return "Unused589";
			case Unused590: return "Unused590";
			case Unused591: return "Unused591";
			case Unused592: return "Unused592";
			case Unused593: return "Unused593";
			case LowerResistance: return "LowerResistance";
			case LowerResistance2: return "LowerResistance2";
			case PoisonNovas: return "PoisonNovas";
			case PoisonNovas2: return "PoisonNovas2";
			case BoneSpirits: return "BoneSpirits";
			case BoneSpirits2: return "BoneSpirits2";
			case Unused600: return "Unused600";
			case Unused601: return "Unused601";
			case Unused602: return "Unused602";
			case Unused603: return "Unused603";
			case Sacrifice: return "Sacrifice";
			case Sacrifice2: return "Sacrifice2";
			case HolyBolts: return "HolyBolts";
			case HolyBolts2: return "HolyBolts2";
			case Zeal: return "Zeal";
			case Zeal2: return "Zeal2";
			case Vengeance: return "Vengeance";
			case Vengeance2: return "Vengeance2";
			case BlessedHammers: return "BlessedHammers";
			case BlessedHammers2: return "BlessedHammers2";
			case Unused614: return "Unused614";
			case Unused615: return "Unused615";
			case Unused616: return "Unused616";
			case Unused617: return "Unused617";
			case Bashing2: return "Bashing2";
			case Bashing3: return "Bashing3";
			case Unused620: return "Unused620";
			case Unused621: return "Unused621";
			case Unused622: return "Unused622";
			case Unused623: return "Unused623";
			case Unused624: return "Unused624";
			case Unused625: return "Unused625";
			case Unused626: return "Unused626";
			case Unused627: return "Unused627";
			case Stunning: return "Stunning";
			case Stunning2: return "Stunning2";
			case Unused630: return "Unused630";
			case Unused631: return "Unused631";
			case Concentration: return "Concentration";
			case Concentration2: return "Concentration2";
			case Unused634: return "Unused634";
			case Unused635: return "Unused635";
			case Unused636: return "Unused636";
			case Unused637: return "Unused637";
			case GrimWard: return "GrimWard";
			case GrimWard2: return "GrimWard2";
			case Unused640: return "Unused640";
			case Unused641: return "Unused641";
			case Unused642: return "Unused642";
			case Unused643: return "Unused643";
			case Firestorms: return "Firestorms";
			case Firestorms2: return "Firestorms2";
			case Unused644: return "Unused644";
			case Unused645: return "Unused645";
			case Eruption: return "Eruption";
			case Eruption2: return "Eruption2";
			case Unused650: return "Unused650";
			case Unused651: return "Unused651";
			case Twister: return "Twister";
			case Twister2: return "Twister2";
			case Volcano: return "Volcano";
			case Volcano2: return "Volcano2";
			case Tornado: return "Tornado";
			case Tornado2: return "Tornado2";
			case Unused658: return "Unused658";
			case Unused659: return "Unused659";
			case Unused660: return "Unused660";
			case Unused661: return "Unused661";
			case DamageAmplification: return "DamageAmplification";
			case TheIcicle2: return "TheIcicle2";
			case TheGlacier3: return "TheGlacier3";
			case Fire3: return "Fire3";
			case Burning3: return "Burning3";
			case Lightning6: return "Lightning6";
			case Thunder3: return "Thunder3";
			case Daring2: return "Daring2";
			case Daring3: return "Daring3";
			case Knowledge2: return "Knowledge2";
			case Knowledge3: return "Knowledge3";
			case Virility2: return "Virility2";
			case Virility3: return "Virility3";
			case Readiness3: return "Readiness3";
			case Craftsmanship6: return "Craftsmanship6";
			case Quality5: return "Quality5";
			case Maiming7: return "Maiming7";
			case Craftsmanship7: return "Craftsmanship7";
			case Quality6: return "Quality6";
			case Craftsmanship8: return "Craftsmanship8";
			case Blight5: return "Blight5";
			case Venom3: return "Venom3";
			case Pestilence3: return "Pestilence3";
			case Anthrax2: return "Anthrax2";
			case Blight6: return "Blight6";
			case Venom4: return "Venom4";
			case Pestilence4: return "Pestilence4";
			case Anthrax3: return "Anthrax3";
			case Blight7: return "Blight7";
			case Venom5: return "Venom5";
			case Pestilence5: return "Pestilence5";
			case Anthrax4: return "Anthrax4";
			case Frost5: return "Frost5";
			case TheIcicle3: return "TheIcicle3";
			case TheGlacier4: return "TheGlacier4";
			case Winter2: return "Winter2";
			case Frost6: return "Frost6";
			case TheIcicle4: return "TheIcicle4";
			case TheGlacier5: return "TheGlacier5";
			case Winter3: return "Winter3";
			case Frost7: return "Frost7";
			case TheIcicle5: return "TheIcicle5";
			case TheGlacier6: return "TheGlacier6";
			case Winter4: return "Winter4";
			case Flame5: return "Flame5";
			case Fire4: return "Fire4";
			case Burning4: return "Burning4";
			case Incineration2: return "Incineration2";
			case Flame6: return "Flame6";
			case Fire5: return "Fire5";
			case Burning5: return "Burning5";
			case Incineration3: return "Incineration3";
			case Flame7: return "Flame7";
			case Fire6: return "Fire6";
			case Burning6: return "Burning6";
			case Incineration4: return "Incineration4";
			case Shock5: return "Shock5";
			case Lightning7: return "Lightning7";
			case Thunder4: return "Thunder4";
			case Storms2: return "Storms2";
			case Shock6: return "Shock6";
			case Lightning8: return "Lightning8";
			case Thunder5: return "Thunder5";
			case Storms3: return "Storms3";
			case Shock7: return "Shock7";
			case Lightning9: return "Lightning9";
			case Thunder6: return "Thunder6";
			case Storms4: return "Storms4";
			case Dexterity12: return "Dexterity12";
			case Dexterity13: return "Dexterity13";
			case Strength11: return "Strength11";
			case Strength12: return "Strength12";
			case Thorns3: return "Thorns3";
			case Frost8: return "Frost8";
			case Flame8: return "Flame8";
			case Blight8: return "Blight8";
			case Shock8: return "Shock8";
			case Regeneration7: return "Regeneration7";
			case Energy6: return "Energy6";
			case Light3: return "Light3";
			case TheLeech5: return "TheLeech5";
			case TheLocust4: return "TheLocust4";
			case TheLamprey3: return "TheLamprey3";
			case TheBat5: return "TheBat5";
			case TheWraith3: return "TheWraith3";
			case TheVampire4: return "TheVampire4";
		}
		return "N/A";
	}
};
// tolua_end
