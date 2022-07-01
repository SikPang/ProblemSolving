using System.Text;

class Test
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
        StringBuilder sb = new StringBuilder();
        Stack<char> leftStack = new Stack<char>();
        Stack<char> rightStack = new Stack<char>();

        string input = sr.ReadLine();
        int num = Convert.ToInt32(sr.ReadLine());

        for(int i = 0; i < input.Length; i++)
            leftStack.Push(input[i]);

        for(int i=0; i<num; i++)
        {
            string[] str = sr.ReadLine().Split();
            char temp;

            switch (str[0])
            {
                case "L":
                    if (leftStack.Count > 0)
                    {
                        temp = leftStack.Peek();
                        leftStack.Pop();
                        rightStack.Push(temp);
                    }
                    break;
                case "D":
                    if (rightStack.Count > 0)
                    {
                        temp = rightStack.Peek();
                        rightStack.Pop();
                        leftStack.Push(temp);
                    }
                    break;
                case "P":
                    leftStack.Push(str[1][0]);
                    break;
                case "B":
                    if (leftStack.Count > 0)
                        leftStack.Pop();
                    break;
            }
        }

        while(leftStack.Count > 0)
        {
            char temp = leftStack.Peek();
            leftStack.Pop();
            rightStack.Push(temp);
        }

        while (rightStack.Count > 0)
        {
            sb.Append(rightStack.Peek());
            rightStack.Pop();
        }

        sw.Write(sb.ToString());
        sw.Close();
    }
}