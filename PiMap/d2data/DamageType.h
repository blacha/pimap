#pragma once

//tolua_begin
namespace DamageType
{
    enum DamageType
    {
        None = 0,
        Fire = 1,
        Lightning = 2,
        Cold = 3,
        Physical = 4,
        Magic = 5,
        Poison = 6,
        Undead = 7,
    };
};

namespace DamageTypes
{
    enum DamageTypes
    {
        None = 0,
        Fire = 1,
        Lightning = 2,
        Cold = 4,
        Physical = 8,
        Magic = 16,
        Poison = 32,
        Undead = 64,
    };
};
// tolua_end
