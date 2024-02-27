

export class Stack {

	stack: Array<number>;

	constructor(initValues: Array<number>) {
		this.stack = initValues;
	}

	push(value: number): void {
		this.stack.push(value);
	}

	pop(): number | undefined {
		return this.stack.pop();
	}

	swap(): void {
		const first = this.stack.pop();
		const secound = this.stack.pop();

		if (first != undefined)
			this.stack.push(first);
		if (secound != undefined)
			this.stack.push(secound);
	}

	rotate(): void {
		const value = this.stack.shift();

		if (value != undefined)
			this.stack.push(value);
	}

	reverseRotate(): void {
		const value = this.stack.pop();

		if (value != undefined)
			this.stack.unshift(value);
	}
}

