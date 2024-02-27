import { MathFormula } from "./MathFomula"


test('MathFormula radian', () => {
	expect(MathFormula.radian(90)).toBe(Math.PI / 2);
});

test('MathFormula degrees', () => {
	expect(MathFormula.degrees(Math.PI / 2)).toBe(90);
});

test('MathFormula convertCartesianCoordinates', () => {
	const {x, y} = MathFormula.convertCartesianCoordinates(MathFormula.radian(45), 2);
	expect(Math.abs(x - Math.sqrt(2))).toBeLessThan(0.000000001);
	expect(Math.abs(y - Math.sqrt(2))).toBeLessThan(0.000000001);
});
