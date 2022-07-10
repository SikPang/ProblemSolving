using System.Text;

class Test
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
        StringBuilder sb = new StringBuilder();
        
        int num = Convert.ToInt32(sr.ReadLine());
        Coordinate[] coord = new Coordinate[num];

        for (int i=0; i< num; i++)
        {
            int[] input = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);

            Coordinate temp = new Coordinate();

            temp.x = input[0];
            temp.y = input[1];

            coord[i] = temp;
        }

        coord = coord.OrderBy(x => x.x).ThenBy(x => x.y).ToArray();

        for(int i=0; i<num; i++)
        {
            sb.AppendLine(coord[i].x.ToString() + " " + coord[i].y.ToString());
        }

        sw.Write(sb.ToString());
        sw.Close();
    }
}

class Coordinate
{
    public int x;
    public int y;
}