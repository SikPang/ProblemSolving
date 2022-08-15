class Test
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
        int[] alphabet = new int[26];
        int max = 0;
        int maxNum = 0;
        bool isDuplicate = false;

        string input = sr.ReadLine();

        for (int i = 0; i < input.Length; i++)
        {
            int ascii = Convert.ToInt32(input[i]);

            if (ascii >= 97)
                alphabet[ascii - 97]++;
            else
                alphabet[ascii - 65]++;
        }

        for (int i = 0; i < alphabet.Length; i++)
        {
            if (maxNum < alphabet[i])
            {
                maxNum = alphabet[i];
                max = i;
                isDuplicate = false;
            }
            else if (maxNum == alphabet[i])
                isDuplicate = true;
        }

        if (isDuplicate)
            sw.Write("?");
        else
            sw.Write(Convert.ToChar(max + 65));

        sw.Close();
    }
}