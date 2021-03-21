declare type Image = any;

export interface MapObject {
  draw(ctx: CanvasRenderingContext2D, x: number, y: number, size: number);
}

export class SpriteSheet {
  sizeHalf: number;
  image: Image;
  size = 32;

  constructor(image: Image) {
    this.image = image;
    this.sizeHalf = this.size / 2;
  }
}

const TextDefaults = {
  size: 18,
  font: 'Roboto Condensed',
  stroke: 1,
  color: 'magenta',
};

export class CanvasText {
  static draw(
    ctx: CanvasRenderingContext2D,
    x: number,
    y: number,
    text: string,
    config: Partial<typeof TextDefaults> = {},
  ): void {
    const obj = { ...TextDefaults, ...config };
    ctx.font = `${obj.size}px "${obj.font}`;

    ctx.fillStyle = obj.color;
    ctx.textBaseline = 'middle';
    ctx.textAlign = 'center';
    if (obj.stroke > 0) {
      ctx.lineWidth = obj.stroke;
      ctx.strokeStyle = 'black';
      ctx.strokeText(text, x, y);
    }
    ctx.fillText(text, x, y);
  }
}

export class SpriteSquare {
  name: string;
  color: string;
  constructor(name: string, color: string) {
    this.name = name;
    this.color = color;
  }

  draw(ctx: CanvasRenderingContext2D, x: number, y: number, drawSize = 32): void {
    const drawX = x - drawSize / 2;
    const drawY = y - drawSize / 2;

    ctx.lineWidth = 1;
    ctx.fillStyle = this.color;
    ctx.strokeStyle = 'black';
    ctx.strokeRect(drawX, drawY, drawSize, drawSize);
    ctx.fillRect(drawX, drawY, drawSize, drawSize);
    return null;
  }
}

export class SpriteCircle {
  name: string;
  color: string;
  constructor(name: string, color: string) {
    this.name = name;
    this.color = color;
  }

  draw(ctx: CanvasRenderingContext2D, x: number, y: number, drawSize = 32): void {
    ctx.beginPath();
    ctx.arc(x, y, drawSize / 2, 0, 2 * Math.PI, false);
    ctx.fillStyle = this.color;
    ctx.fill();
    ctx.lineWidth = 1;
    ctx.strokeStyle = 'black';
    ctx.stroke();
    return null;
  }
}

export class Sprite {
  name: string;
  x: number;
  y: number;
  constructor(name: string, x: number, y: number) {
    this.name = name;
    this.x = x;
    this.y = y;
  }

  draw(ctx: CanvasRenderingContext2D, sheet: SpriteSheet, x: number, y: number, drawSize?: number): void {
    const baseSize = sheet.size;
    const sourceX = this.x * baseSize;
    const sourceY = this.y * baseSize;
    if (drawSize == null) drawSize = baseSize;
    const drawX = x - drawSize / 2;
    const drawY = y - drawSize / 2;

    ctx.drawImage(sheet.image, sourceX, sourceY, baseSize, baseSize, drawX, drawY, drawSize, drawSize);
    return null;
  }
}

export const Sprites = {
  Cross: new Sprite('Cross', 2, 2),
  Player: new SpriteCircle('Player', 'rgba(255,0,255,0.87)'),
  PlayerHydra: new Sprite('Hydra', 1, 0),
  TownsFolk: new SpriteCircle('TownFolk', 'rgba(200,200,250,0.87)'),
  Item: new Sprite('Hydra', 2, 2),

  Merc: new Sprite('Merc', 0, 2),

  Waypoint: new Sprite('Star', 2, 1),
  Shrine: new SpriteCircle('Shrine', 'rgba(0,250,0,0.37)'),
  Well: new SpriteCircle('Well', 'rgba(0,0,250,0.37)'), // new Sprite('Shrine', 5, 0), //new SpriteCircle('Well', 'rgba(0,0,250,0.87)'),

  Chest: new Sprite('Chest', 8, 0),
  Quest: new Sprite('Chest', 10, 0),

  Exit: new Sprite('Map', 1, 2),
  ExitGood: new Sprite('Map', 3, 2),

  MonsterEvil: new Sprite('Skull', 0, 4),
  MonsterLightning: new Sprite('Bolt', 1, 4),
  MonsterBoss: new Sprite('Boss', 3, 1),

  MonsterArcher: new Sprite('BlueCircle', 1, 1),

  MonsterNormal: new Sprite('GreyCircle', 13, 0),
  MonsterMinion: new Sprite('YelloCircle', 3, 0),
  MonsterChampion: new Sprite('OrangeCircle', 2, 0),
  MonsterUnique: new Sprite('RedCircle', 1, 0),
  MonsterSuperUnique: new Sprite('PurpleCircle', 10, 0),

  Unknown: new SpriteCircle('QuestionMark', '#dcdcdcdc'),
};
