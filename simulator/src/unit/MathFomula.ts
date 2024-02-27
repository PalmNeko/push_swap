

export class MathFormula {

	static radian(degrees: number) {
		return degrees * (Math.PI / 180);
	}

	static degrees(radian: number) {
		return radian * 180 / Math.PI;
	}

	static convertCartesianCoordinates(radian: number, radius: number) {
		const x = radius * Math.cos(radian);
		const y = radius * Math.sin(radian);

		return {'x': x, 'y': y};
	}
}