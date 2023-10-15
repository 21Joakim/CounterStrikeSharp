/*
 *  This file is part of CounterStrikeSharp.
 *  CounterStrikeSharp is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  CounterStrikeSharp is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with CounterStrikeSharp.  If not, see <https://www.gnu.org/licenses/>. *
 */

#include <ios>
#include <sstream>

#include "scripting/autonative.h"
#include "scripting/script_engine.h"
#include "core/memory.h"
#include <public/entity2/entitysystem.h>

namespace counterstrikesharp {

CBaseEntity* GetEntityFromIndex(ScriptContext& script_context) {
    auto entityIndex = script_context.GetArgument<int>(0);

    return globals::entitySystem->GetBaseEntity(CEntityIndex(entityIndex));
}

REGISTER_NATIVES(entities, {
    ScriptEngine::RegisterNativeHandler("GET_ENTITY_FROM_INDEX", GetEntityFromIndex);
})
}  // namespace counterstrikesharp