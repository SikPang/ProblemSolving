class Test
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
        Stack<int> stack = new Stack<int>();
        long answer = 0;

        int num = Convert.ToInt32(sr.ReadLine());

        for(int i=0; i<num; i++)
        {
            int heights = Convert.ToInt32(sr.ReadLine());

            // 현재 들어온 heights 보다 stack에 작은 값들이 있다면 pop
            while (stack.Count > 0 && stack.Peek() <= heights)
                stack.Pop();

            // 현재 들어온 heights를 볼 수 있는 빌딩의 수 : stack.Count
            answer += stack.Count;

            stack.Push(heights);
        }

        sw.Write(answer.ToString());
        sw.Close();
    }
}