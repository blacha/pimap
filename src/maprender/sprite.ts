declare type Image = any;

export class SpriteSheet {
    sizeHalf: number;
    image: Image;
    size = 32;

    constructor(image: Image) {
        this.image = image;
        this.sizeHalf = this.size / 2;
    }
}


const TWO_PI = Math.PI * 2;
export class Sprite {
    name: string;
    x: number;
    y: number;
    constructor(name: string, x: number, y: number) {
        this.name = name;
        this.x = x;
        this.y = y;
    }

    draw(ctx: CanvasRenderingContext2D, sheet: SpriteSheet, x: number, y: number, drawSize?: number): null {
        const baseSize = sheet.size;
        const sourceX = this.x * baseSize;
        const sourceY = this.y * baseSize;
        if (drawSize == null) {
            drawSize = baseSize;
        }
        const drawX = x - drawSize / 2;
        const drawY = y - drawSize / 2;

        // console.log('draw', this.name, '@', `${drawX},${drawY}`);
        ctx.drawImage(sheet.image, sourceX, sourceY, baseSize, baseSize, drawX, drawY, drawSize, drawSize);
        // ctx.beginPath();
        // ctx.arc(drawX, drawY, drawSize / 4, 0, 2 * Math.PI, false);
        // ctx.fillStyle = 'green';
        // ctx.fill();
        // ctx.lineWidth = 2;
        // ctx.strokeStyle = 'black';
        // ctx.stroke();
        return null;
    }
}

export const Sprites = {
    Cross: new Sprite('Cross', 2, 2),
    Player: new Sprite('Player', 0, 2),
    PlayerHydra: new Sprite('Hydra', 1, 0),
    Merc: new Sprite('Merc', 0, 2),

    Waypoint: new Sprite('Star', 2, 1),
    Shrine: new Sprite('Shrine', 5, 0),
    Chest: new Sprite('Chest', 8, 0),
    Quest: new Sprite('Chest', 10, 0),

    Exit: new Sprite('Map', 1, 2),
    ExitGood: new Sprite('Map', 3, 2),

    MonsterEvil: new Sprite('Skull', 0, 4),
    MonsterLightning: new Sprite('Bolt', 1, 4),
    MonsterBoss: new Sprite('Boss', 0, 1),

    MonsterArcher: new Sprite('BlueCircle', 1, 1),

    MonsterNormal: new Sprite('GreyCircle', 13, 0),
    MonsterMinion: new Sprite('YelloCircle', 3, 0),
    MonsterChampion: new Sprite('OrangeCircle', 2, 0),
    MonsterUnique: new Sprite('RedCircle', 1, 0),
    MonsterSuperUnique: new Sprite('PurpleCircle', 10, 0),

    Unkown: new Sprite('QuestionMark', 6, 5)
};
