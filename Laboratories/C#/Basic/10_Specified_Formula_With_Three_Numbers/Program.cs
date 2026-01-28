public class SpecifiedFormulaThreeNumbers {
	public static void Main() {

		int x, y, z;
		string? line;

		System.Console.Write("Type the first number: ");
		line = System.Console.ReadLine();
		if (!int.TryParse(line, out x))
			return ;
		System.Console.Write("\nType the second number: ");
		y = Convert.ToInt32(System.Console.ReadLine());
		System.Console.Write("\nType the third number: ");
		line = System.Console.ReadLine();
		if (!int.TryParse(line, out z))
			return ;
		int firstResult = (x + y) * z;
		int secondResult = x * y + y * z;

		System.Console.WriteLine("First Result: {0}", firstResult);
		System.Console.WriteLine("Second Result: {0}", secondResult);
	}
}
