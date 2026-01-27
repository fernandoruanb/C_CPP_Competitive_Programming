public class SumAndDivideTwoNumbers {
	public static void Main () {

		// Sum two values in C#, printing the result - Exercise 2

		System.Console.WriteLine(25 + 25);

		// Dividing values - Exercise 3, bonus multiplication and subtraction

		System.Console.WriteLine(45 / 5);
		System.Console.WriteLine(5 * 5);
		System.Console.WriteLine(10 - 10);

		// testing specif operations - Exercise 4

		System.Console.WriteLine(-1 + 4 * 6);
		System.Console.WriteLine((35 + 5) % 7);
		System.Console.WriteLine(14 + -4 * 6 / 11);
		System.Console.WriteLine(2 + 15 / 6 * 1 - 7 % 2);

		// Swap two numbers - Exercise 5

		int a, b, temp;
		string? line; // line can be NULL if you put the '?' character in the side

		System.Console.Write("\nInput the First Number: ");

		line = System.Console.ReadLine(); // get the line
		// we can also create with out int a (yes, the declaration in the attempt)
		if (!int.TryParse(line, out a)) // try to parse to int, if it is possible store in output a
			return ;
		System.Console.Write("\nInput the Second Number: ");
		line = System.Console.ReadLine();
		if (!int.TryParse(line, out b))
			return ;

		temp = a;
		a = b;
		b = temp;

		System.Console.Write("\nAfter Swaping");
		System.Console.Write("\nFirst number: " + a);
		System.Console.Write("\nSecond number: " + b + "\n");
	}
}
