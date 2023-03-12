
const SQUARE = 0;
const RECTANGLE = 1;
const TRIANGLE = 2;
const CIRCLE = 3;

class Shape {
  constructor(type, width, height) {
    this.type = type;
    this.width = width;
    this.height = height;
  }
  width = 0;
  height = 0;
  type = SQUARE;
}

function area(shape) {
  switch (shape.type) {
    case SQUARE:
      return shape.width * shape.width;
    case RECTANGLE:
      return shape.width * shape.height;
    case TRIANGLE:
      return 0.5 * shape.width * shape.height;
    case CIRCLE:
      return Math.PI * shape.width * shape.width;
  }
}

function areaNotClean() {

  const shapes = new Array();
  for (let i = 0; i < 1000000; i++) {
    shapes.push(new Shape(SQUARE, Math.random(), 0));
    shapes.push(new Shape(RECTANGLE, Math.random(), Math.random()));
    shapes.push(new Shape(TRIANGLE, Math.random(), Math.random()));
    shapes.push(new Shape(CIRCLE, Math.random(), 0));
  }
  let totalArea = 0;
  const start = new Date().valueOf();
  for (let i = 0; i < shapes.length; i++) {
    totalArea += area(shapes[i]);
  }
  const end = new Date().valueOf();

  console.log("Processing time in ms =", end - start, " ms");
}
areaNotClean();
