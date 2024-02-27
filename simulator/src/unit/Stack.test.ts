import { Stack } from "./Stack";


test('stack pop', () => {
	const stack = new Stack([1, 2, 3]);
    expect(stack.pop()).toBe(3);
    expect(stack.pop()).toBe(2);
    expect(stack.pop()).toBe(1);
    expect(stack.pop()).toBe(undefined);
});

test('stack value:stack', () => {
	const stack = new Stack([1, 2, 3]);

	expect(stack.stack.toString() == [1, 2, 3].toString()).toBeTruthy();
});

test('stack push', () => {
	const stack = new Stack([]);

	stack.push(1);
	stack.push(2);
	stack.push(3);
	expect(stack.stack.toString() == [1, 2, 3].toString()).toBeTruthy();
});

test('stack swap', () => {
	const stack = new Stack([1, 2, 3, 4]);

	stack.swap();
    expect(stack.pop()).toBe(3);
});

test('stack rotate', () => {
	const stack = new Stack([1, 2, 3]);

	stack.rotate();
	expect(stack.pop()).toBe(1);
});

test('stack reverseRotate', () => {
	const stack = new Stack([1, 2, 3]);

	stack.reverseRotate();
	expect(stack.pop()).toBe(2);
});

