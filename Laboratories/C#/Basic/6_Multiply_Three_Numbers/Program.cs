// using System;

public class MultiplyThreeNumbers {
	public static void Main() {
		int a, b, c, d;
		string? line;

		System.Console.Write("Type the first Number: ");
		line = System.Console.ReadLine();
		if (!int.TryParse(line, out a))
			return ;
		System.Console.Write("\nType the second Number: ");
		line = System.Console.ReadLine();
		if (!int.TryParse(line, out b))
			return ;
		System.Console.Write("\nType the third Number: ");
		line = System.Console.ReadLine();
		if (!int.TryParse(line, out c))
			return ;

		System.Console.Write("\nType the fourth Number: ");
		// This is another method to get the number
		d = Convert.ToInt32(System.Console.ReadLine());

		//if (!a || !b || !c)
		//	return ;

		int result = a * b * c * d;

		//WriteLine has more functionalities than Write
		System.Console.WriteLine("\n{0} * {1} * {2} * {3} = {4}", a, b, c, d, result);
	}
}
