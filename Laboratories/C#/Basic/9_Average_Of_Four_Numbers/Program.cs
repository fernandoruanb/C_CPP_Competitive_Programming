// using System;

public class AverageFourNumbers {
	public static void Main() {
		double a, b, c, d;
		string? line;

		System.Console.Write("Type the first number: ");
		line = System.Console.ReadLine();
		if (!double.TryParse(line, out a))
			return ;
		System.Console.Write("\nType the second number: ");
		b = Convert.ToDouble(System.Console.ReadLine());
		System.Console.Write("\nType the third number: ");
		line = System.Console.ReadLine();
		if (!double.TryParse(line, out c))
			return ;
		System.Console.Write("\nType the fourth number: ");
		d = Convert.ToDouble(System.Console.ReadLine());
		double average = (a + b + c + d) / 4;
		System.Console.WriteLine("The average is: {0}", average);
	}
}
