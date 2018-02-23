#pragma once

//tolua_begin
namespace GameDifficulty
{
	enum GameDifficulty
	{
		Normal		= 0,
		Nightmare	= 1,
		Hell		= 2
	};
};

namespace TownFolkMenuItem
{
	enum TownFolkMenuItem
	{
		Travel		= 0,
		Trade		= 1,
		Gamble		= 2,
		Hire		= 3,
		Invalid		= -1
	};
};

namespace GameButton
{
	enum GameButton
	{
		CloseTrade			= 2,
		EnterTrade			= 3,
		AcceptTrade			= 4,
		CancelAcceptTrade	= 7,
		UpdateGoldOffer		= 8,
		CloseStash			= 0x12,
		WithdrawGold		= 0x13,
		StashGold			= 0x14,
		CloseCube			= 0x17,
		Transmute			= 0x18,
	};
};

namespace ItemUIAction
{
	/// <summary>
	/// Notifies of an update to item related interface. Used by GS packet 0x77
	/// </summary>
	enum ItemUIAction
	{
		/// <summary>
		/// Requesting to trade with someone (result of interacting with a player who isn't "busy").
		/// </summary>
		RequestTrade		= 0x00,
		/// <summary>
		/// Another player is requesting to trade with you.
		/// </summary>
		TradeRequest		= 0x01,
		/// <summary>
		/// Trade partner has accepted your trade offer (Acceot button goes green.)
		/// </summary>
		TradeAccepted		= 0x05,
		/// <summary>
		/// Unchecks all Accept buttons - sent whenever a trader changes anything in trade offer.
		/// Or might do so soon... e.g. picks up an item from inventory, clicks the offer gold button...
		/// </summary>
		UnacceptAllTrades	= 0x06,
		/// <summary>
		/// You don't have enough room to trade, sent instead of TradeCompleted when both accept but trade can't be performed.
		/// </summary>
		NoRoomForTrade		= 0x09,
		/// <summary>
		/// Trade partner doesn't have enough room to trade, sent instead of TradeCompleted when both accept but trade can't be performed.
		/// </summary>
		TraderHasNoRoom		= 0x0A,
		/// <summary>
		/// A player refuses trade request or cancels trade before it is completed.
		/// In the later case, this resets inventory / equipment to what they were before trade and closes the trade window.
		/// </summary>
		RefuseTrade			= 0x0C,
		/// <summary>
		/// Both player have accepted trade and completion is successful. Trade window closes and each player get the other player's trade buffer.
		/// </summary>
		TradeCompleted		= 0x0D,
		/// <summary>
		/// This turns the Accept button red, making it unclickable for a certain duration (until EnableAcceptTrade is sent.)
		/// </summary>
		DisableAcceptTrade	= 0x0E,
		/// <summary>
		/// Enables the Accept trade button.
		/// </summary>
		EnableAcceptTrade	= 0x0F,
		/// <summary>
		/// Open the stash panel.
		/// </summary>
		OpenStash			= 0x10,
		/// <summary>
		/// Hide the stash panel with another panel, e.g. the Horadric cube panel.
		/// The stash remains open and should (but doesn't always) get redisplayed when the hiding UI is closed...
		/// </summary>
		HideStash   		= 0x11,
		/// <summary>
		/// Open the Horadric cube panel.
		/// </summary>
		OpenCube			= 0x15,
	};
};

namespace PlayerRelationType
{
    enum PlayerRelationType
    {
        Loot = 1,
        Mute = 2,
        Squelch = 3,
        Hostile = 4,
    };
};

namespace PartyAction
{
    enum PartyAction
    {
        Invite = 0x06,
        CancelInvite = 0x07,
        AcceptInvite = 0x08,
    };
};

namespace MovementType
{
	enum MovementType
	{
		Walk = 0x01,
		Run = 0x17,
		KnockBack = 0x20,
	};
};

namespace SpecialItemType
{
	enum SpecialItemType
	{
		TomeOrScroll	= 4,
    };
};

namespace ItemStateType
{
    enum ItemStateType
    {
        Broken = 1,
        Full = 2,
    };
};

namespace NPCMode
{
    enum NPCMode
	{
        Alive = 0x06,
        /// <summary>
        /// Null X and Y means the monster displays a 'in air' dying animation..
        /// </summary>
        Dying = 0x08,
	    /// <summary>
        /// Dead monsters coming into view as well.
	    /// </summary>
		Dead  = 0x09,
    };
};
// tolua_end
