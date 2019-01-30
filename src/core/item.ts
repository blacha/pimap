export enum ItemClass {
    NotApplicable,
    Normal,
    Exceptional,
    Elite
}

export enum ItemQuality {
    NotApplicable = 0,
    Inferior,
    Normal,
    Superior,
    Magic,
    Set,
    Rare,
    Unique,
    Crafted
}

export enum EquipmentLocation {
    NotApplicable = 0,
    Helm = 1,
    Amulet = 2,
    Armor = 3,
    RightHand = 4,
    LeftHand = 5,
    RightHandRing = 6,
    LeftHandRing = 7,
    Belt = 8,
    Boots = 9,
    Gloves = 10,
    RightHandSwitch = 11,
    LeftHandSwitch = 12
}

/// <summary>
/// This is used by GS Packet 0x9C - 0x9D, and is pretty weird...
/// </summary>
export enum ItemCategory {
    Helm = 0,
    Armor = 1,
    /// <summary>
    /// Most weapons, including Crossbows
    /// </summary>
    Weapon = 5,
    /// <summary>
    /// Bows (not crossbows), sometimes shield (if equiped in LeftHand?)
    /// </summary>
    Weapon2 = 6,
    /// <summary>
    /// Shields can some somtimes be Weapon2...
    /// </summary>
    Shield = 7,
    /// <summary>
    /// Class specific items !?
    /// </summary>
    Special = 10,
    /// <summary>
    /// BaseMiscItems and gloves, boots...
    /// </summary>
    Misc = 16
}

export enum ItemContainer {
    Equipment = 0x00,	// Player or Merc Equipment
    Ground = 0x01,
    Inventory = 0x02,
    TraderOffer = 0x04,
    ForTrade = 0x06,
    Cube = 0x08,
    Stash = 0x0A,
    // Not a buffer... if (buffer == Equipement && Location == EquipmentLocation.NotApplicable)
    Belt = 0x0C,
    // Not a buffer... if (buffer == Equipement && destination == ItemDestination.Item)
    Item = 0x0E,
    //NPC buffers are flagged with 0x80 so they are different
    ArmorTab = 0x82,
    WeaponTab1 = 0x84,
    WeaponTab2 = 0x86,
    MiscTab = 0x88
    //ArmorTabBottom	= 0x83, // Buffer merged with ArmorTab
    //WeaponTab1Bottom	= 0x85, // Buffer merged with WeaponTab1
    //MiscTabBottom		= 0x89, // Buffer merged with WeaponTab2
}

export enum ItemDestination {
    /// <summary>
    /// The item is going in the specified container
    /// </summary>
    Unspecified = 0,
    Equipment = 1,
    Belt = 2,
    Ground = 3,
    Cursor = 4,
    Item = 6,
    // Container = 0,
    // Equipment = 4,
    // Belt = 8,
    // Cursor = 0x10,
    // Item = 0x18
}

//TODO: 2 unknowns left... are there imbue and craft / transmute action types ?
export enum ItemActionType {
    AddToGround = 0,
    GroundToCursor = 1,			// only sent if item goes to cursor (GS packet 0x0A removes item from ground)
    DropToGround = 2,
    OnGround = 3,
    PutInContainer = 4,
    RemoveFromContainer = 5,
    Equip = 6,
    /// <summary>
    /// Sent for the equipped item when changing from a two handed weapon to a single handed weapon or vice versa.
    /// The item must be equiped on the "empty" hand or a regular SwapBodyItem will be sent instead.
    /// Empty hand meaning left hand if currently wearing a two handed weapon or the empty hand if wearing a single hand item.
    /// The result will be the new item being equipped and the old going to cursor.
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
    RemoveFromHireling = 0x12,	// sent along with a 9d 08 packet... Also Item on cursor when entering game ?? MiscToCursor??
    ItemInSocket = 0x13,
    UNKNOWN1 = 0x14,
    UpdateStats = 0x15,			// put item in socket; for each potion that drops in belt when lower one is removed...
    UNKNOWN2 = 0x16,
    WeaponSwitch = 0x17
}

export enum ItemFlag {
    None = 0,
    Equipped = 1,
    // UNKNOWN		= 2,
    // UNKNOWN		= 4,
    InSocket = 8,
    Identified = 0x10,		 // Not undentified, really...
    x20 = 0x20,		 // Has to do with aura / state change !?
    SwitchedIn = 0x40,
    SwitchedOut = 0x80,
    Broken = 0x100,
    // UNKNOWN		= 0x200,
    Potion = 0x400,	 // Set for Mana, Healing and Rejuvenation potions, but not always !?!
    Socketed = 0x800,
    // UNKNOWN		= 0x1000,	 // WasPickedUp ? NOT !
    InStore = 0x2000,	 // Not always set when in store !?
    NotInSocket = 0x4000,	 // Illegal Equip ?
    // UNKNOWN		= 0x8000,
    Ear = 0x10000,	 // Has different packet structure
    StartItem = 0x20000,	 // Item character started with (meaning it's worthless)
    //UNKNOWN		= 0x40000,
    //UNKNOWN		= 0x80000,
    //UNKNOWN		= 0x100000,
    SimpleItem = 0x200000,	 // No ILevel
    Ethereal = 0x400000,
    Any = 0x800000,	 // Which means ??
    Personalized = 0x1000000,
    Gamble = 0x2000000, // Item a town folk is offering for gambling (same purpose as SimpleItem: no ILevel+ info)
    Runeword = 0x4000000,
    x8000000 = 0x8000000, // InducesTempStatusChange ??
    MASK = 0xFE36DF9 // Known / used values
}
