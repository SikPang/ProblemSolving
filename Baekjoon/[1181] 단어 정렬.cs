using System.Text;

class Test
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
        StringBuilder sb = new StringBuilder();
        
        int num = Convert.ToInt32(sr.ReadLine());
        Coordinate[] coordi = new Coordinate[num];

        for (int i=0; i< num; i++)
        {
            string input = sr.ReadLine();

            coordi[i] = new Coordinate(input);
        }

        coordi = coordi.OrderBy(a => a.length).ThenBy(a => a.word).ToArray();

        for(int i=0; i<num; i++)
        {
            if (i > 0 && coordi[i].word.Equals(coordi[i - 1].word)) continue;
            sb.AppendLine(coordi[i].word);
        }

        sw.Write(sb.ToString());
        sw.Close();
    }
}

class Coordinate
{
    public string word;
    public int length;

    public Coordinate(string word)
    {
        this.word = word;
        length = word.Length;
    }
}