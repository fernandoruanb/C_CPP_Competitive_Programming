//using System;

public class multiplicationTable {
	public static void Main() {
		int a;
		string? line;

		System.Console.Write("Type a number to see its table: ");
		line = System.Console.ReadLine();
		if (!int.TryParse(line, out a))
			return ;
		for (int i = 1; i < 11; ++i) {
			System.Console.WriteLine("\n{0} * {1} = {2}", a, i, a * i);
		}
		return ;
	}
}
