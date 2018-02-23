#pragma once

//tolua_begin
namespace ItemEventType
{
    enum ItemEventType
    {
		None = 0,
		DoMeleeAttack = 1,
		DoMissileAttack = 2,
		DoMeleeDamage = 4,
		DoMissileDamage = 8,
		Kill = 0x10,
		DamagedInMelee = 0x20,
		DamagedByMissile = 0x40,
		Death = 0x80,
		LevelUp = 0x100,
    };
};

namespace StorePage
{
    enum StorePage
    {
        NotApplicable = -1,
        None = 0,
        Armor = 1,
        Weapon = 2,
        Misc = 3
    };
};

namespace ItemVersion
{
	enum ItemVersion
    {
        Classic = 0,
        Classic110 = 2,
        LoD = 100,
        LoD110 = 101,
    };
};

namespace ItemClass
{
    enum ItemClass
    {
        NotApplicable = 0,
        Normal = 1,
        Exceptional = 2,
        Elite = 3,
    };
};

namespace ItemQuality
{
    enum ItemQuality
    {
        NotApplicable = 0,
        Inferior = 1,
        Normal = 2,
        Superior = 3,
        Magic = 4,
        Set = 5,
        Rare = 6,
        Unique = 7,
        Crafted = 8,
    };
};

namespace EquipmentLocation
{
    enum EquipmentLocation
    {
        NotApplicable    = 0,
        Helm             = 1,
        Amulet           = 2,
        Armor            = 3,
        RightHand        = 4,
        LeftHand         = 5,
        RightHandRing    = 6,
        LeftHandRing     = 7,
        Belt             = 8,
        Boots            = 9,
        Gloves           = 10,
        RightHandSwitch  = 11,
        LeftHandSwitch   = 12,
    };
};

namespace ItemCategory
{
    /// <summary>
    /// This is used by GS Packet 0x9C - 0x9D, and is pretty weird...
    /// </summary>
    enum ItemCategory
    {
        Helm      = 0,
        Armor     = 1,
        /// <summary>
        /// Most weapons, including Crossbows
        /// </summary>
        Weapon    = 5,
        /// <summary>
        /// Bows (not crossbows), sometimes shield (if equipped in LeftHand?)
        /// </summary>
        Weapon2   = 6,
        /// <summary>
        /// Shields can some sometimes be Weapon2...
        /// </summary>
        Shield    = 7,
        /// <summary>
        /// Class specific items !?
        /// </summary>
        Special   = 10,
        /// <summary>
        /// BaseMiscItems and gloves, boots...
        /// </summary>
        Misc      = 16,
    };
};

namespace ItemContainer
{
    enum ItemContainer
    {
        Unspecified      = 0,

        Inventory        = 2,
        TraderOffer      = 4,
        ForTrade         = 6,
        Cube             = 8,
        Stash            = 0x0A,

        // Not a buffer... flagged with 0x20 if (action == PutInBelt || RemoveFromBelt)
        Belt             = 0x20,
        // Not a buffer... if (buffer == Equipement && destination == Item)
        Item             = 0x40,
        
        //NPC buffers are flagged with 0x80 so they are different
        ArmorTab         = 0x82,
        WeaponTab1       = 0x84,
        WeaponTab2       = 0x86,
        MiscTab          = 0x88,
        //ArmorTabBottom   = 0x83, // Buffer merged with ArmorTab
        //WeaponTab1Bottom = 0x85, // Buffer merged with WeaponTab1
        //MiscTabBottom    = 0x89, // Buffer merged with WeaponTab2
    };
};

namespace ItemContainerGC
{
	enum ItemContainerGC
	{
		Inventory		= 0,
		Trade			= 2,
		Cube			= 3,
		Stash			= 4,
    };
};

namespace ItemDestination
{
    enum ItemDestination
    {
        Unspecified  = 0,
        Equipment    = 1,
        Belt         = 2,
        Ground       = 3,
        Cursor       = 4,
        Item         = 6,
    };
};

namespace ItemActionType
{
    //TODO: 2 unknowns left... are there imbue and craft / transmute action types ?
    enum ItemActionType
    {
        AddToGround = 0,
        /// <summary>
        /// Only sent if item goes to cursor (packet 0x0A removes items from ground...)
        /// </summary>
        GroundToCursor = 1,
        DropToGround = 2,
        OnGround = 3,
        PutInContainer = 4,
        RemoveFromContainer = 5,
        Equip = 6,
        /// <summary>
        /// Sent for the equipped item when changing from a two handed weapon to a single handed weapon or vice versa.
        /// <para>The item must be equipped on the "empty" hand or a regular SwapBodyItem will be sent instead. 
        /// If currently wearing a two handed weapon, the empty hand means the left hand. 
        /// The result will be the new item being equipped and the old going to cursor.</para>
        /// </summary>
        IndirectlySwapBodyItem = 7,
        Unequip = 8,
        SwapBodyItem = 9,
        AddQuantity = 0x0A,
        AddToShop = 0x0B,
        RemoveFromShop = 0x0C,
        SwapInContainer = 0x0D,
        PutInBelt = 0x0E,
        RemoveFromBelt = 0x0F,
        SwapInBelt = 0x10,
        /// <summary>
        /// Sent for the secondary hand's item going to inventory when changing from a dual item setup to a two handed weapon.
        /// </summary>
        AutoUnequip = 0x11,
        /// <summary>
        /// Item on cursor when entering game.
        /// <para>Also sent along with a 0x9d type 0x08 packet when unequipping merc item.</para>
        /// </summary>
        ToCursor = 0x12,
        ItemInSocket = 0x13,
        UNKNOWNx14 = 0x14,
        /// <summary>
        /// When inserting item in socket, for each potion that drops in belt when lower one is removed, etc.
        /// </summary>
        UpdateStats = 0x15,
        UNKNOWNx16 = 0x16,
        WeaponSwitch = 0x17,
    };
};

struct Flags
{
	bool None;
	bool Equipped;
	bool InSocket;
	bool Identified;
	bool x20;
	bool SwitchedIn;
	bool SwitchedOut;
	bool Broken;
	bool Duplicate;
	bool Socketed;
	bool OnPet;
	bool x2000;
	bool NotInSocket;
	bool Ear;
	bool StartItem;
	bool Compact;
	bool Ethereal;
	bool Any;
	bool Personalized;
	bool Gamble;
	bool Runeword;
	bool x8000000;

	Flags()
	{
		None = false;
		Equipped = false;
		InSocket = false;
		Identified = false;
		x20 = false;
		SwitchedIn = false;
		SwitchedOut = false;
		Broken = false;
		Duplicate = false;
		Socketed = false;
		OnPet = false;
		x2000 = false;
		NotInSocket = false;
		Ear = false;
		StartItem = false;
		Compact = false;
		Ethereal = false;
		Any = false;
		Personalized = false;
		Gamble = false;
		Runeword = false;
		x8000000 = false;
	}
};

namespace ItemFlags
{
    enum ItemFlags
    {
        None              = 0,
        Equipped          = 1,
        // UNKNOWN        = 2,
        // UNKNOWN        = 4,
        InSocket          = 8,
        /// <summary>
        /// Not undentified, really... also set for items that cannot be identified.
        /// </summary>
        Identified        = 0x10,
        /// <summary>
        /// Has to do with aura / state change !?
        /// </summary>
        x20               = 0x20,
        SwitchedIn        = 0x40,
        SwitchedOut       = 0x80,
        Broken            = 0x100,
        // UNKNOWN        = 0x200,
        /// <summary>
        /// Sometimes on Mana, Healing and Rejuvenation potions and runes... use is unknown.
        /// </summary>
        Duplicate         = 0x400,
        Socketed          = 0x800,
        /// <summary>
        /// Set on items equipped by Valkyrie...
        /// </summary>
        OnPet             = 0x1000,
        /// <summary>
        /// Set on AddToShop (but not for items I sold), on items equipped by Valkyrie.
        /// Also set on AddToGround and sometimes(?) on quest items... Special Interact ? Is New ?
        /// </summary>
        x2000             = 0x2000,
        NotInSocket       = 0x4000, // Illegal Equip ?
        // UNKNOWN        = 0x8000,
        /// <summary>
        /// Is a player's ear. Ear packets have a different structure...
        /// </summary>
        Ear               = 0x10000,
        /// <summary>
        /// Item a character started with (meaning the item worthless to resell.)
        /// </summary>
        StartItem         = 0x20000,
        //UNKNOWN         = 0x40000,
        //UNKNOWN         = 0x80000,
        //UNKNOWN         = 0x100000,
        /// <summary>
        /// Item that doesn't have an ILevel or stats.
        /// </summary>
        Compact           = 0x200000,
        Ethereal          = 0x400000,
        /// <summary>
        /// Meaning is unknown...
        /// </summary>
        Any               = 0x800000,
        Personalized      = 0x1000000,
        /// <summary>
        /// Item a town folk is offering for gambling (same purpose as Compact: no ILevel + extra info.)
        /// </summary>
        Gamble            = 0x2000000,
        Runeword          = 0x4000000,
        /// <summary>
        /// Induce State Change !?
        /// </summary>
        x8000000          = 0x8000000,
        //UNKNOWN         = 0x10000000,
        //UNKNOWN         = 0x20000000,
        //UNKNOWN         = 0x40000000,
        //UNKNOWN         = 0x80000000
    };
};

namespace SuperiorItemType
{
    enum SuperiorItemType
    {
        NotApplicable = -1,
        AttackRating = 0,
        Damage = 1,
        Defense = 2,
        DamageAttackRating = 3,
        Durability = 4,
        AttackRatingDurability = 5,
        DamageDurability = 6,
        DefenseDurability = 7
    };
};
// tolua_end
