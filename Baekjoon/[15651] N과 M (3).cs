using System.Text;

namespace Program
{
    class Program
    {
        static int max;
        static int dep;
        static List<int> list = new List<int>();
        static StringBuilder sb = new StringBuilder();

        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split();
            max = int.Parse(input[0]);
            dep = int.Parse(input[1]);

            NnM(0);
            
            Console.Write(sb.ToString());
        }

        static void NnM(int depth)
        {
            if (depth == dep)
            {
                foreach(int i in list)
                    sb.Append(i + " ");
                sb.AppendLine();
                return;
            }

            for(int i= 0; i < max; i++)
            {
                list.Add(i+1);

                NnM(depth+1);

                list.RemoveAt(list.Count-1);
            }
        }
    }
}