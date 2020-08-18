import { GameObject } from '../core/object';
import { GameObjectClass, GameObjectClasses } from '../core/object.type';
import { writeFileSync } from 'fs';

function isNumber(str) {
  return !isNaN(str) && !isNaN(parseFloat(str));
}

function dumpEnum(vals, enumName: string) {
  let enumBuffer = `enum ${enumName}\n{`;

  let numbers = [];
  for (const key of Object.keys(vals)) {
    if (isNumber(key)) {
      numbers.push(parseInt(key));
    }
  }
  numbers = numbers.sort((a, b) => a - b);

  for (const value of numbers) {
    const key = vals[value];
    enumBuffer += `\n    ${key} = ${value},`;
  }

  enumBuffer = enumBuffer.substr(0, enumBuffer.length - 1);
  enumBuffer += '\n};';

  return enumBuffer;
}

function dumpFunction(fnName: string, trues) {
  let fnBuffer = `static bool ${fnName}(int id)\n{\n`;
  fnBuffer += `    switch (id)\n`;
  fnBuffer += `    {\n`;
  for (const value of trues) {
    fnBuffer += `    case ${value}:\n`;
  }

  fnBuffer += `        return true;\n    default:\n        return false;\n    }\n}`;
  return fnBuffer;
}

const doors = [];
const useless = [];
for (const key of Object.keys(GameObjectClasses)) {
  const value = GameObjectClasses[key];
  const gameObject = GameObject[key];
  if (value === GameObjectClass.USELESS || value === GameObjectClass.SOUND) {
    useless.push(`GameObject::${gameObject}`);
  }
  if (value === GameObjectClass.DOOR) {
    doors.push(`GameObject::${gameObject}`);
  }
}

const gameObjectEnum = dumpEnum(GameObject, 'GameObject');
// console.log(gameObjectEnum);

const isDoor = dumpFunction('object_is_door', doors);
const isUseless = dumpFunction('object_is_useless', useless);
console.log(isDoor);

const gameObjectH = `#ifndef _GameObject_h__
#define _GameObject_h__

${gameObjectEnum}

${isDoor}

${isUseless}

#endif
`;

writeFileSync('src/mapgen/d2data/d2_game_object.h', gameObjectH);
