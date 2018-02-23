#pragma once

//tolua_begin
namespace PlayerRelationshipType
{
	enum PlayerRelationshipType
	{
		None = 0,
		Loot = 1,
		Mute = 2,
		Squelch = 4,
		Hostile = 8,
	};
};

namespace PartyRelationshipType
{
	enum PartyRelationshipType
	{
		/// <summary>
		/// Player is not in any party or wanting to party
		/// </summary>
		None		= 0,
		/// <summary>
		/// Player is in a party
		/// </summary>
		InAParty	= 1,
		/// <summary>
		/// Player is waiting for you to accept invitation
		/// </summary>
		InvitedYou	= 2,
		/// <summary>
		/// Waiting for player to accept invitation
		/// </summary>
		Invited		= 4,
	};
};

namespace PlayerInformationActionType
{
	enum PlayerInformationActionType
	{
		Neutral		= 0,
		Party		= 2,
		Friendly	= 4,
		UnFriendly	= 8,
		Remove		= 1,

		None		= 0x80,
	};
};

namespace PlayerRelationActionType
{
	enum PlayerRelationActionType
	{
		// Neutral
		/// <summary>
		/// Player has removed Hostile
		/// </summary>
		Unhostile		= 4,

		// Party
		/// <summary>
		/// Player Is Asking To Party With You
		/// </summary>
		InvitedYou		= 5,
		/// <summary>
		/// New Player Has Joined Party
		/// </summary>
		JoinedParty		= 7,
		/// <summary>
		/// Your Now In This Players party ?
		/// </summary>
		JoinedYourParty	= 8,

		// Friendly
		/// <summary>
		/// Player has given you permission to loot his body
		/// </summary>
		AllowLoot		= 2,

		// UnFriendly
		/// <summary>
		/// Player has gone hostile
		/// </summary>
		Hostile			= 3,

		// Remove
		/// <summary>
		/// Player has left your party
		/// </summary>
		LeftParty		= 9,
		/// <summary>
		/// Player has canlceled the party invitation
		/// </summary>
		CanceledInvite	= 6,
		/// <summary>
		/// Player has canceled permission to loot his body
		/// </summary>
		CanceledLootPermission	= 0x0B,

		NotApplicable	= 0xFF,
	};
};
// tolua_end
