class ShapeBase {
  constructor() {}
  area() {
    return 0;
  }
}

class Square extends ShapeBase {
  side = 0;

  constructor(side) {
    super();
    this.side = side;
  }

  area() {
    return this.side * this.side;
  }
}

class Rectangle extends ShapeBase {
  width = 0;
  height = 0;

  constructor(width, height) {
    super();
    this.width = width;
    this.height = height;
  }

  area() {
    return this.width * this.height;
  }
}

class Triangle extends ShapeBase {
  base = 0;
  height = 0;

  constructor(base, height) {
    super();
    this.base = base;
    this.height = height;
  }

  area() {
    return 0.5 * this.base * this.height;
  }
}

class Circle extends ShapeBase {
  radius = 0;

  constructor(radius) {
    super();
    this.radius = radius;
  }

  area() {
    return Math.PI * this.radius * this.radius;
  }
}

function areaClean() {
  const shapes = new Array();
  for (let i = 0; i < 1000000; i++) {
    shapes.push(new Square(Math.random()));
    shapes.push(new Rectangle(Math.random(), Math.random()));
    shapes.push(new Triangle(Math.random(), Math.random()));
    shapes.push(new Circle(Math.random()));
  }

  let totalArea = 0;
  const start = new Date().valueOf();
  for (let i = 0; i < shapes.length; i++) {
    totalArea += shapes[i].area();
  }
  const end = new Date().valueOf();

  console.log("Processing time in ms =", end - start, " ms");
}

areaClean();

