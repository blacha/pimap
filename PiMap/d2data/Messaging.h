#pragma once

//tolua_begin
namespace GameSound
{	
	enum GameSound
	{
		/// <summary>
		/// Item specific sound triggered when an item is swap or picked up.
		/// </summary>
		Pickup				= 1,
		/// <summary>
		/// Masochistic Baal has a good laugh because he's one step closer to getting his ass kicked.
		/// </summary>
		BaalLaugh			= 16,
		/// <summary>
		/// Cannot perform action (pick up item with telekinesis or when there's not enough space in inventory).
		/// </summary>
		Impossible			= 19,
		HelpMe				= 25,
		FollowMe			= 26,
		ThisIsForYou		= 27,
		ThankYou			= 28,
		ForgiveMe			= 29,
		GoodBye				= 30,
		TimeToDie			= 31,
		RunAway				= 32,
		IllPutThatToGoodUse	= 87,
	};
};

namespace GameMessageType
{	
	enum GameMessageType
	{
		GameMessage = 1,
		GameWhisper = 2,
		OverheadMessage = 5,
		GameWhisperReceipt = 6,
	};
};
// tolua_end
