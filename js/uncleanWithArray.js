
const SQUARE = 0;
const RECTANGLE = 1;
const TRIANGLE = 2;
const CIRCLE = 3;



function area(shape) {
  switch (shape[0]) {
    case SQUARE:
      return shape[1] * shape[1];
    case RECTANGLE:
      return shape[1]* shape[2];
    case TRIANGLE:
      return 0.5 * shape[1] * shape[2];
    case CIRCLE:
      return Math.PI * shape[1] * shape[2];
  }
}

function areaNotClean() {

  const shapes = [];
  for (let i = 0; i < 1000000; i++) {
    shapes.push([SQUARE, Math.random(),0]);
    shapes.push([RECTANGLE, Math.random(),Math.random()]);
    shapes.push([TRIANGLE, Math.random(),Math.random()]);
    shapes.push([CIRCLE, Math.random(),Math.random()]);
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
