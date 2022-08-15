class Test
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
        int count = 0;
        bool isBreaked;
        bool[] alphabet;

        int num = Convert.ToInt32(sr.ReadLine());

        for (int i = 0; i < num; i++)
        {
            string input = sr.ReadLine();
            isBreaked = false;
            alphabet = new bool[26];
            for (int j = 1; j < input.Length; j++)
            {
                if (input[j - 1] != input[j])
                {
                    if (alphabet[Convert.ToInt32(input[j] - 97)])
                    {
                        isBreaked = true;
                        break;
                    }
                    alphabet[Convert.ToInt32(input[j - 1] - 97)] = true;
                }
            }
            if (!isBreaked)
                count++;
        }

        sw.Write(count);
        sw.Close();
    }
}