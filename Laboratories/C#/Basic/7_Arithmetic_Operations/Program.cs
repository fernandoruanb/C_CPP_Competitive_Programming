public class ArithMeticOperations {
	public static void Main() {

		int a, b;
		string? line;

		System.Console.Write("Type the first number: ");
		line = System.Console.ReadLine();
		if (!int.TryParse(line, out a))
			return ;
		System.Console.Write("\nType the second number: ");
		b = Convert.ToInt32(System.Console.ReadLine());
		System.Console.WriteLine("{0} + {1} = {2}", a, b, a + b);
		System.Console.WriteLine("{0} - {1} = {2}", a, b, a - b);
		System.Console.WriteLine("{0} * {1} = {2}", a, b, a * b);
		if (b != 0) {
			System.Console.WriteLine("{0} / {1} = {2}", a, b, a / b);
			System.Console.WriteLine("{0} % {1} = {2}", a, b, a % b);
		}
		else 
			System.Console.Write("Zero Division Error!");
	}
}
